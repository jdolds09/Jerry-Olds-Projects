#ifndef TSNSPLTYPES_H
#define TSNSPLTYPES_H

#include "ccpp_TSN.h"

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>

extern c_metaObject __TSN_TSN__load (c_base base);

extern c_metaObject __TSN_serial_number__load (c_base base);
typedef c_ulong _TSN_serial_number;

extern c_metaObject __TSN_user_information__load (c_base base);
extern const char * __TSN_user_information__keys (void);
extern const char * __TSN_user_information__name (void);
struct _TSN_user_information ;
extern  c_bool __TSN_user_information__copyIn(c_base base, struct TSN::user_information *from, struct _TSN_user_information *to);
extern  void __TSN_user_information__copyOut(void *_from, void *_to);
struct _TSN_user_information {
    c_string uuid;
    c_string first_name;
    c_string last_name;
    c_long date_of_birth;
    c_sequence interests;
    c_ulonglong number_of_highest_post;
};

extern c_metaObject __TSN_node_request__load (c_base base);
extern const char * __TSN_node_request__keys (void);
extern const char * __TSN_node_request__name (void);
struct _TSN_node_request ;
extern  c_bool __TSN_node_request__copyIn(c_base base, struct TSN::node_request *from, struct _TSN_node_request *to);
extern  void __TSN_node_request__copyOut(void *_from, void *_to);
struct _TSN_node_request {
    c_char fulfiller_uuid[37];
    c_sequence requested_posts;
};

extern c_metaObject __TSN_request__load (c_base base);
extern const char * __TSN_request__keys (void);
extern const char * __TSN_request__name (void);
struct _TSN_request ;
extern  c_bool __TSN_request__copyIn(c_base base, struct TSN::request *from, struct _TSN_request *to);
extern  void __TSN_request__copyOut(void *_from, void *_to);
struct _TSN_request {
    c_string uuid;
    c_sequence user_requests;
};

extern c_metaObject __TSN_post_data__load (c_base base);
extern const char * __TSN_post_data__keys (void);
extern const char * __TSN_post_data__name (void);
struct _TSN_post_data ;
extern  c_bool __TSN_post_data__copyIn(c_base base, struct TSN::post_data *from, struct _TSN_post_data *to);
extern  void __TSN_post_data__copyOut(void *_from, void *_to);
struct _TSN_post_data {
    c_char owner_uuid[37];
    _TSN_serial_number post_id;
};

extern c_metaObject __TSN_response__load (c_base base);
extern const char * __TSN_response__keys (void);
extern const char * __TSN_response__name (void);
struct _TSN_response ;
extern  c_bool __TSN_response__copyIn(c_base base, struct TSN::response *from, struct _TSN_response *to);
extern  void __TSN_response__copyOut(void *_from, void *_to);
struct _TSN_response {
    c_string uuid;
    _TSN_serial_number post_id;
    c_string post_body;
    c_long date_of_creation;
    struct _TSN_post_data parent_post;
    c_sequence child_posts;
};

extern c_metaObject __TSN_private_message__load (c_base base);
extern const char * __TSN_private_message__keys (void);
extern const char * __TSN_private_message__name (void);
struct _TSN_private_message ;
extern  c_bool __TSN_private_message__copyIn(c_base base, struct TSN::private_message *from, struct _TSN_private_message *to);
extern  void __TSN_private_message__copyOut(void *_from, void *_to);
struct _TSN_private_message {
    c_string receiver_uuid;
    c_char sender_uuid[37];
    c_string message_body;
    c_long date_of_creation;
};

#endif
