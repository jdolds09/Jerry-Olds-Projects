#include "TSNSplDcps.h"
#include "ccpp_TSN.h"
#include "dds_type_aliases.h"

const char *
__TSN_user_information__name(void)
{
    return (const char*)"TSN::user_information";
}

const char *
__TSN_user_information__keys(void)
{
    return (const char*)"uuid";
}

const char *
__TSN_node_request__name(void)
{
    return (const char*)"TSN::node_request";
}

const char *
__TSN_node_request__keys(void)
{
    return (const char*)"";
}

const char *
__TSN_request__name(void)
{
    return (const char*)"TSN::request";
}

const char *
__TSN_request__keys(void)
{
    return (const char*)"uuid";
}

const char *
__TSN_post_data__name(void)
{
    return (const char*)"TSN::post_data";
}

const char *
__TSN_post_data__keys(void)
{
    return (const char*)"";
}

const char *
__TSN_response__name(void)
{
    return (const char*)"TSN::response";
}

const char *
__TSN_response__keys(void)
{
    return (const char*)"uuid";
}

const char *
__TSN_private_message__name(void)
{
    return (const char*)"TSN::private_message";
}

const char *
__TSN_private_message__keys(void)
{
    return (const char*)"receiver_uuid";
}

#include <v_kernel.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

c_bool
__TSN_user_information__copyIn(
    c_base base,
    struct ::TSN::user_information *from,
    struct _TSN_user_information *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    {
        /* Allocate the length of the array (and null terminator) as a database
        * string
        */
        to->uuid = c_stringMalloc(base, (37 + 1));
        if(to->uuid)
        {
            /* Copy the value of the array into the database string */
           strncpy(to->uuid, from->uuid, 37);
            to->uuid[37] = '\0';
        }
    }
#ifdef OSPL_BOUNDS_CHECK
    if(from->first_name){
        if(((unsigned int)strlen(from->first_name)) <= 70){
            to->first_name = c_stringNew(base, from->first_name);
        } else {
            OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'TSN::user_information.first_name' of type 'C_STRING<70>' is out of range.");
            result = OS_C_FALSE;
        }
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'TSN::user_information.first_name' of type 'C_STRING<70>' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->first_name = c_stringNew(base, from->first_name);
#endif
#ifdef OSPL_BOUNDS_CHECK
    if(from->last_name){
        if(((unsigned int)strlen(from->last_name)) <= 70){
            to->last_name = c_stringNew(base, from->last_name);
        } else {
            OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'TSN::user_information.last_name' of type 'C_STRING<70>' is out of range.");
            result = OS_C_FALSE;
        }
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'TSN::user_information.last_name' of type 'C_STRING<70>' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->last_name = c_stringNew(base, from->last_name);
#endif
    to->date_of_birth = (c_long)from->date_of_birth;
    {
/* Code generated by /home/dds/OvernightTests/tmp.EvVa0SFLQ3/build/src/tools/idlpp/code/idl_genCorbaCxxCopyin.c at line 774 */

        static c_type type0 = NULL;
        c_type subtype0;
        c_long length0;
        c_string *dest0;
        ::TSN::user_information::_interests_seq *src = &from->interests;

        if (type0 == NULL) {
            subtype0 = c_type(c_metaResolve (c_metaObject(base), "c_string"));
            type0 = c_metaSequenceTypeNew(c_metaObject(base),"C_SEQUENCE<c_string>",subtype0,0);
            c_free(subtype0);
        }
        length0 = (c_long)(*src).length();
#ifdef OSPL_BOUNDS_CHECK
         dest0 = (c_string *)c_newSequence(c_collectionType(type0),length0);
        {
        /* Code generated by /home/dds/OvernightTests/tmp.EvVa0SFLQ3/build/src/tools/idlpp/code/idl_genCorbaCxxCopyin.c at line 1928 */
            unsigned int i0;
            for (i0 = 0; (i0 < (unsigned int)length0) && result; i0++) {
#ifdef OSPL_BOUNDS_CHECK
                if((*src)[i0]){
                    dest0[i0] = c_stringNew(base, (*src)[i0]);
                } else {
                    OS_REPORT (OS_ERROR, "copyIn", 0,"Element of 'TSN::user_information.*src' of type 'c_string' is NULL.");
                    result = OS_C_FALSE;
                }
#else
                dest0[i0] = c_stringNew(base, (*src)[i0]);
#endif
            }
        }
        to->interests = (c_sequence)dest0;
#else
        dest0 = (c_string *)c_newSequence(c_collectionType(type0),length0);
        {
        /* Code generated by /home/dds/OvernightTests/tmp.EvVa0SFLQ3/build/src/tools/idlpp/code/idl_genCorbaCxxCopyin.c at line 1928 */
            unsigned int i0;
            for (i0 = 0; (i0 < (unsigned int)length0) && result; i0++) {
#ifdef OSPL_BOUNDS_CHECK
                if((*src)[i0]){
                    dest0[i0] = c_stringNew(base, (*src)[i0]);
                } else {
                    OS_REPORT (OS_ERROR, "copyIn", 0,"Element of 'TSN::user_information.*src' of type 'c_string' is NULL.");
                    result = OS_C_FALSE;
                }
#else
                dest0[i0] = c_stringNew(base, (*src)[i0]);
#endif
            }
        }
        to->interests = (c_sequence)dest0;
#endif
    }
    to->number_of_highest_post = (c_ulonglong)from->number_of_highest_post;
    return result;
}

c_bool
__TSN_node_request__copyIn(
    c_base base,
    struct ::TSN::node_request *from,
    struct _TSN_node_request *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    {
        typedef c_char _DestType[37];
        _DestType *dest = &to->fulfiller_uuid;
        memcpy (dest, from->fulfiller_uuid, sizeof (*dest));
    }
    {
/* Code generated by /home/dds/OvernightTests/tmp.EvVa0SFLQ3/build/src/tools/idlpp/code/idl_genCorbaCxxCopyin.c at line 774 */

        static c_type type0 = NULL;
        c_type subtype0;
        c_long length0;
        _TSN_serial_number *dest0;
        ::TSN::node_request::_requested_posts_seq *src = &from->requested_posts;

        if (type0 == NULL) {
            subtype0 = c_type(c_metaResolve (c_metaObject(base), "TSN::serial_number"));
            type0 = c_metaSequenceTypeNew(c_metaObject(base),"C_SEQUENCE<TSN::serial_number>",subtype0,0);
            c_free(subtype0);
        }
        length0 = (c_long)(*src).length();
#ifdef OSPL_BOUNDS_CHECK
         dest0 = (_TSN_serial_number *)c_newSequence(c_collectionType(type0),length0);
        {
        /* Code generated by /home/dds/OvernightTests/tmp.EvVa0SFLQ3/build/src/tools/idlpp/code/idl_genCorbaCxxCopyin.c at line 1873 */
                    _TSN_serial_number *buf0;
            buf0 = (_TSN_serial_number *)(*src).get_buffer();
            memcpy (dest0,buf0,length0* sizeof(*dest0));
        }
        to->requested_posts = (c_sequence)dest0;
#else
        dest0 = (_TSN_serial_number *)c_newSequence(c_collectionType(type0),length0);
        {
        /* Code generated by /home/dds/OvernightTests/tmp.EvVa0SFLQ3/build/src/tools/idlpp/code/idl_genCorbaCxxCopyin.c at line 1873 */
                    _TSN_serial_number *buf0;
            buf0 = (_TSN_serial_number *)(*src).get_buffer();
            memcpy (dest0,buf0,length0* sizeof(*dest0));
        }
        to->requested_posts = (c_sequence)dest0;
#endif
    }
    return result;
}

c_bool
__TSN_request__copyIn(
    c_base base,
    struct ::TSN::request *from,
    struct _TSN_request *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    {
        /* Allocate the length of the array (and null terminator) as a database
        * string
        */
        to->uuid = c_stringMalloc(base, (37 + 1));
        if(to->uuid)
        {
            /* Copy the value of the array into the database string */
           strncpy(to->uuid, from->uuid, 37);
            to->uuid[37] = '\0';
        }
    }
    {
/* Code generated by /home/dds/OvernightTests/tmp.EvVa0SFLQ3/build/src/tools/idlpp/code/idl_genCorbaCxxCopyin.c at line 774 */

        static c_type type0 = NULL;
        c_type subtype0;
        c_long length0;
        struct _TSN_node_request *dest0;
        ::TSN::request::_user_requests_seq *src = &from->user_requests;

        if (type0 == NULL) {
            subtype0 = c_type(c_metaResolve (c_metaObject(base), "TSN::node_request"));
            type0 = c_metaSequenceTypeNew(c_metaObject(base),"C_SEQUENCE<TSN::node_request>",subtype0,0);
            c_free(subtype0);
        }
        length0 = (c_long)(*src).length();
#ifdef OSPL_BOUNDS_CHECK
         dest0 = (struct _TSN_node_request *)c_newSequence(c_collectionType(type0),length0);
        {
        /* Code generated by /home/dds/OvernightTests/tmp.EvVa0SFLQ3/build/src/tools/idlpp/code/idl_genCorbaCxxCopyin.c at line 1928 */
            unsigned int i0;
            for (i0 = 0; (i0 < (unsigned int)length0) && result; i0++) {
                extern c_bool __TSN_node_request__copyIn(c_base base,
                    TSN::node_request *From,
                    struct _TSN_node_request *To);

                result = __TSN_node_request__copyIn(base, &(*src)[i0], (struct _TSN_node_request *)&dest0[i0]);
            }
        }
        to->user_requests = (c_sequence)dest0;
#else
        dest0 = (struct _TSN_node_request *)c_newSequence(c_collectionType(type0),length0);
        {
        /* Code generated by /home/dds/OvernightTests/tmp.EvVa0SFLQ3/build/src/tools/idlpp/code/idl_genCorbaCxxCopyin.c at line 1928 */
            unsigned int i0;
            for (i0 = 0; (i0 < (unsigned int)length0) && result; i0++) {
                extern c_bool __TSN_node_request__copyIn(c_base base,
                    TSN::node_request *From,
                    struct _TSN_node_request *To);

                result = __TSN_node_request__copyIn(base, &(*src)[i0], (struct _TSN_node_request *)&dest0[i0]);
            }
        }
        to->user_requests = (c_sequence)dest0;
#endif
    }
    return result;
}

c_bool
__TSN_post_data__copyIn(
    c_base base,
    struct ::TSN::post_data *from,
    struct _TSN_post_data *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    {
        typedef c_char _DestType[37];
        _DestType *dest = &to->owner_uuid;
        memcpy (dest, from->owner_uuid, sizeof (*dest));
    }
    to->post_id = (c_ulong)from->post_id;
    return result;
}

c_bool
__TSN_response__copyIn(
    c_base base,
    struct ::TSN::response *from,
    struct _TSN_response *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    {
        /* Allocate the length of the array (and null terminator) as a database
        * string
        */
        to->uuid = c_stringMalloc(base, (37 + 1));
        if(to->uuid)
        {
            /* Copy the value of the array into the database string */
           strncpy(to->uuid, from->uuid, 37);
            to->uuid[37] = '\0';
        }
    }
    to->post_id = (c_ulong)from->post_id;
#ifdef OSPL_BOUNDS_CHECK
    if(from->post_body){
        to->post_body = c_stringNew(base, from->post_body);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'TSN::response.post_body' of type 'c_string' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->post_body = c_stringNew(base, from->post_body);
#endif
    to->date_of_creation = (c_long)from->date_of_creation;
    if(result){
        extern c_bool __TSN_post_data__copyIn(c_base, ::TSN::post_data *, _TSN_post_data *);
        result = __TSN_post_data__copyIn(base, &from->parent_post, &to->parent_post);
    }
    {
/* Code generated by /home/dds/OvernightTests/tmp.EvVa0SFLQ3/build/src/tools/idlpp/code/idl_genCorbaCxxCopyin.c at line 774 */

        static c_type type0 = NULL;
        c_type subtype0;
        c_long length0;
        struct _TSN_post_data *dest0;
        ::TSN::response::_child_posts_seq *src = &from->child_posts;

        if (type0 == NULL) {
            subtype0 = c_type(c_metaResolve (c_metaObject(base), "TSN::post_data"));
            type0 = c_metaSequenceTypeNew(c_metaObject(base),"C_SEQUENCE<TSN::post_data>",subtype0,0);
            c_free(subtype0);
        }
        length0 = (c_long)(*src).length();
#ifdef OSPL_BOUNDS_CHECK
         dest0 = (struct _TSN_post_data *)c_newSequence(c_collectionType(type0),length0);
        {
        /* Code generated by /home/dds/OvernightTests/tmp.EvVa0SFLQ3/build/src/tools/idlpp/code/idl_genCorbaCxxCopyin.c at line 1928 */
            unsigned int i0;
            for (i0 = 0; (i0 < (unsigned int)length0) && result; i0++) {
                extern c_bool __TSN_post_data__copyIn(c_base base,
                    TSN::post_data *From,
                    struct _TSN_post_data *To);

                result = __TSN_post_data__copyIn(base, &(*src)[i0], (struct _TSN_post_data *)&dest0[i0]);
            }
        }
        to->child_posts = (c_sequence)dest0;
#else
        dest0 = (struct _TSN_post_data *)c_newSequence(c_collectionType(type0),length0);
        {
        /* Code generated by /home/dds/OvernightTests/tmp.EvVa0SFLQ3/build/src/tools/idlpp/code/idl_genCorbaCxxCopyin.c at line 1928 */
            unsigned int i0;
            for (i0 = 0; (i0 < (unsigned int)length0) && result; i0++) {
                extern c_bool __TSN_post_data__copyIn(c_base base,
                    TSN::post_data *From,
                    struct _TSN_post_data *To);

                result = __TSN_post_data__copyIn(base, &(*src)[i0], (struct _TSN_post_data *)&dest0[i0]);
            }
        }
        to->child_posts = (c_sequence)dest0;
#endif
    }
    return result;
}

c_bool
__TSN_private_message__copyIn(
    c_base base,
    struct ::TSN::private_message *from,
    struct _TSN_private_message *to)
{
    c_bool result = OS_C_TRUE;
    (void) base;

    {
        /* Allocate the length of the array (and null terminator) as a database
        * string
        */
        to->receiver_uuid = c_stringMalloc(base, (37 + 1));
        if(to->receiver_uuid)
        {
            /* Copy the value of the array into the database string */
           strncpy(to->receiver_uuid, from->receiver_uuid, 37);
            to->receiver_uuid[37] = '\0';
        }
    }
    {
        typedef c_char _DestType[37];
        _DestType *dest = &to->sender_uuid;
        memcpy (dest, from->sender_uuid, sizeof (*dest));
    }
#ifdef OSPL_BOUNDS_CHECK
    if(from->message_body){
        to->message_body = c_stringNew(base, from->message_body);
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'TSN::private_message.message_body' of type 'c_string' is NULL.");
        result = OS_C_FALSE;
    }
#else
    to->message_body = c_stringNew(base, from->message_body);
#endif
    to->date_of_creation = (c_long)from->date_of_creation;
    return result;
}

void
__TSN_user_information__copyOut(
    void *_from,
    void *_to)
{
    struct _TSN_user_information *from = (struct _TSN_user_information *)_from;
    struct ::TSN::user_information *to = (struct ::TSN::user_information *)_to;
    {
       strncpy(to->uuid, from->uuid, 37);
    }
    to->first_name = DDS::string_dup(from->first_name ? from->first_name : "");
    to->last_name = DDS::string_dup(from->last_name ? from->last_name : "");
    to->date_of_birth = (::DDS::Long)from->date_of_birth;
    {
        long size0;
        c_string *src0 = (c_string *)from->interests;
        ::TSN::user_information::_interests_seq *dst = &to->interests;

        size0 = c_arraySize(c_sequence(from->interests));
        to->interests.length(size0);
        {
            long i0;
            for (i0 = 0; i0 < size0; i0++) {
                (*dst)[i0] = DDS::string_dup(src0[i0]);
            }
        }
    }
    to->number_of_highest_post = (::DDS::ULongLong)from->number_of_highest_post;
}

void
__TSN_node_request__copyOut(
    void *_from,
    void *_to)
{
    struct _TSN_node_request *from = (struct _TSN_node_request *)_from;
    struct ::TSN::node_request *to = (struct ::TSN::node_request *)_to;
    {
        typedef c_char _DestType[37];
        _DestType *src = &from->fulfiller_uuid;

        memcpy (to->fulfiller_uuid, src, sizeof (*src));
    }
    {
        long size0;
        _TSN_serial_number *src0 = (_TSN_serial_number *)from->requested_posts;
        ::TSN::node_request::_requested_posts_seq *dst = &to->requested_posts;

        size0 = c_arraySize(c_sequence(from->requested_posts));
        to->requested_posts.length(size0);
        {
            _TSN_serial_number *buf0;
            buf0 = (_TSN_serial_number *)(*dst).get_buffer();
            memcpy (buf0,src0,size0* sizeof(*buf0));
        }
    }
}

void
__TSN_request__copyOut(
    void *_from,
    void *_to)
{
    struct _TSN_request *from = (struct _TSN_request *)_from;
    struct ::TSN::request *to = (struct ::TSN::request *)_to;
    {
       strncpy(to->uuid, from->uuid, 37);
    }
    {
        long size0;
        struct _TSN_node_request *src0 = (struct _TSN_node_request *)from->user_requests;
        ::TSN::request::_user_requests_seq *dst = &to->user_requests;

        size0 = c_arraySize(c_sequence(from->user_requests));
        to->user_requests.length(size0);
        {
            long i0;
            for (i0 = 0; i0 < size0; i0++) {
                extern void __TSN_node_request__copyOut(void *from, void *to);
                __TSN_node_request__copyOut((void *)&src0[i0], (void *)&(*dst)[i0]);
            }
        }
    }
}

void
__TSN_post_data__copyOut(
    void *_from,
    void *_to)
{
    struct _TSN_post_data *from = (struct _TSN_post_data *)_from;
    struct ::TSN::post_data *to = (struct ::TSN::post_data *)_to;
    {
        typedef c_char _DestType[37];
        _DestType *src = &from->owner_uuid;

        memcpy (to->owner_uuid, src, sizeof (*src));
    }
    to->post_id = (::DDS::ULong)from->post_id;
}

void
__TSN_response__copyOut(
    void *_from,
    void *_to)
{
    struct _TSN_response *from = (struct _TSN_response *)_from;
    struct ::TSN::response *to = (struct ::TSN::response *)_to;
    {
       strncpy(to->uuid, from->uuid, 37);
    }
    to->post_id = (::DDS::ULong)from->post_id;
    to->post_body = DDS::string_dup(from->post_body ? from->post_body : "");
    to->date_of_creation = (::DDS::Long)from->date_of_creation;
    {
        extern void __TSN_post_data__copyOut(void *, void *);
        __TSN_post_data__copyOut((void *)&from->parent_post, (void *)&to->parent_post);
    }
    {
        long size0;
        struct _TSN_post_data *src0 = (struct _TSN_post_data *)from->child_posts;
        ::TSN::response::_child_posts_seq *dst = &to->child_posts;

        size0 = c_arraySize(c_sequence(from->child_posts));
        to->child_posts.length(size0);
        {
            long i0;
            for (i0 = 0; i0 < size0; i0++) {
                extern void __TSN_post_data__copyOut(void *from, void *to);
                __TSN_post_data__copyOut((void *)&src0[i0], (void *)&(*dst)[i0]);
            }
        }
    }
}

void
__TSN_private_message__copyOut(
    void *_from,
    void *_to)
{
    struct _TSN_private_message *from = (struct _TSN_private_message *)_from;
    struct ::TSN::private_message *to = (struct ::TSN::private_message *)_to;
    {
       strncpy(to->receiver_uuid, from->receiver_uuid, 37);
    }
    {
        typedef c_char _DestType[37];
        _DestType *src = &from->sender_uuid;

        memcpy (to->sender_uuid, src, sizeof (*src));
    }
    to->message_body = DDS::string_dup(from->message_body ? from->message_body : "");
    to->date_of_creation = (::DDS::Long)from->date_of_creation;
}

