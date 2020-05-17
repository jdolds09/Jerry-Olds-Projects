#ifndef INCLUDE_DDSHELPER_H_
#define INCLUDE_DDSHELPER_H_

#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <vector>

#include <boost/signals2/signal.hpp>

#include "include/DDSEntityManager.h"
#include "standalone/ccpp_TSN.h"

// Adapted from example on BudDavis GitHub

template <typename READER, typename SEQ, typename MSG>
class DDSListener : public virtual DDS::DataReaderListener {
    private:
        std::mutex mtx; // We use a mutex so we don't
                        // interfere with the data between threads

        std::vector<MSG> incoming_list;

    public:
        boost::signals2::signal<void(MSG)> signal_data_ready;

        READER reader;
        DDSListener() {}
        std::vector<MSG> receive() {
            mtx.lock();

            std::vector<MSG> out;
            out = incoming_list;
            incoming_list.clear();

            mtx.unlock();
            return out;
        }

        virtual void on_data_available(DDS::DataReader_ptr r) {
            DDS::ReturnCode_t status;
            SEQ msg_list;

            SampleInfoSeq info_seq;
            status = reader -> take(msg_list, info_seq, LENGTH_UNLIMITED,
                    ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
            checkStatus(status, "DataReader::read");

            for (DDS::ULong i = 0; i < msg_list.length(); i++) {
                if (msg_list.length() > 0) {
                    mtx.lock();
                    incoming_list.push_back(msg_list[i]);
                    signal_data_ready(msg_list[i]);
                    mtx.unlock();
                }
            }

            status = reader -> return_loan(msg_list, info_seq);
            checkStatus(status, "DataReader::return_load");
        }

        /* Unused function overrides */
        virtual void on_requested_deadline_missed(DDS::DataReader_ptr reader,
            const DDS::RequestedDeadlineMissedStatus &status) {}
        virtual void on_requested_incompatible_qos(DDS::DataReader_ptr reader,
            const DDS::RequestedIncompatibleQosStatus &status) {}
        virtual void on_sample_rejected(DDS::DataReader_ptr reader,
            const DDS::SampleRejectedStatus &status) {}
        virtual void on_liveliness_changed(DDS::DataReader_ptr reader,
            const DDS::LivelinessChangedStatus &status) {}
        virtual void on_subscription_matched(DDS::DataReader_ptr reader,
            const DDS::SubscriptionMatchedStatus &status) {}
        virtual void on_sample_lost(DDS::DataReader_ptr reader,
            const DDS::SampleLostStatus &status) {}
};

template <typename MSG, typename SEQ, typename SUPPORT, class TYPE_SUPPORT,
         typename WRITER, class DATA_WRITER, typename READER, class DATA_READER>
class DDSHelper {
    typedef void (*cb_func_type)( MSG );

    private:
        DDSEntityManager mgr;
        SUPPORT mt;
        DataWriter_var writer;
        WRITER l_writer;
        DataReader_var reader;

    public:
        DDSListener<READER, SEQ, MSG> *listener;

        DDSHelper() {}

        explicit DDSHelper(char* topic, bool is_publishing = false, bool is_subscribing = false) {
            // Create a domain participant
            mgr.createParticipant("");

            // Create a type
            mt = new TYPE_SUPPORT();
            mgr.registerType(mt.in());

            // Setup our topic based on the struct
            mgr.createTopic(topic);

            // We want to publish data to others
            if (is_publishing) {
                // Create a publisher
                mgr.createPublisher();

                // Create a DataWriter
                mgr.createWriter();

                writer = mgr.getWriter();
                l_writer = DATA_WRITER::_narrow(writer.in());
            }

            // We want to subscribe data from others
            if (is_subscribing) {
                // Create a subscriber
                mgr.createSubscriber();

                // Create a DataReader
                mgr.createReader();

                DataReader_var tmp_reader = mgr.getReader();
                listener = new DDSListener<READER, SEQ, MSG>();

                listener -> reader = DATA_READER::_narrow(tmp_reader.in());
                checkHandle(listener -> reader.in(), "DataReader::_narrow");

                DDS::StatusMask s_mask = DDS::DATA_AVAILABLE_STATUS;
                listener -> reader -> set_listener(listener, s_mask);
            }
        }

        std::vector<MSG> receive() {
            return listener -> receive();
        }

        void publish(MSG msg) {
            ReturnCode_t status = l_writer -> write(msg, DDS::HANDLE_NIL);
            checkStatus(status, "DataWriter::write");
        }

        void dispose() {
            mgr.deleteWriter();
            mgr.deletePublisher();
            mgr.deleteReader();
            mgr.deleteSubscriber();
            mgr.deleteTopic();
            mgr.deleteParticipant();
        }
};

#endif // INCLUDE_DDSHELPER_H_
