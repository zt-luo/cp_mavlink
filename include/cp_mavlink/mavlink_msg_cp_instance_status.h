#pragma once
// MESSAGE CP_INSTANCE_STATUS PACKING

#define MAVLINK_MSG_ID_CP_INSTANCE_STATUS 3

MAVPACKED(
typedef struct __mavlink_cp_instance_status_t {
 uint64_t video_duration; /*<  video duration*/
 uint64_t video_size; /*<  video size*/
 uint64_t video_time; /*<  video time*/
 uint64_t timestamp; /*<  timestamp*/
 char uuid[37]; /*<  uuid*/
 char to_uuid[37]; /*<  to uuid*/
 char pair_uuid[37]; /*<  pair uuid*/
 char pair_name[50]; /*<  pair name*/
}) mavlink_cp_instance_status_t;

#define MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN 193
#define MAVLINK_MSG_ID_CP_INSTANCE_STATUS_MIN_LEN 193
#define MAVLINK_MSG_ID_3_LEN 193
#define MAVLINK_MSG_ID_3_MIN_LEN 193

#define MAVLINK_MSG_ID_CP_INSTANCE_STATUS_CRC 48
#define MAVLINK_MSG_ID_3_CRC 48

#define MAVLINK_MSG_CP_INSTANCE_STATUS_FIELD_UUID_LEN 37
#define MAVLINK_MSG_CP_INSTANCE_STATUS_FIELD_TO_UUID_LEN 37
#define MAVLINK_MSG_CP_INSTANCE_STATUS_FIELD_PAIR_UUID_LEN 37
#define MAVLINK_MSG_CP_INSTANCE_STATUS_FIELD_PAIR_NAME_LEN 50

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CP_INSTANCE_STATUS { \
    3, \
    "CP_INSTANCE_STATUS", \
    8, \
    {  { "uuid", NULL, MAVLINK_TYPE_CHAR, 37, 32, offsetof(mavlink_cp_instance_status_t, uuid) }, \
         { "to_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 69, offsetof(mavlink_cp_instance_status_t, to_uuid) }, \
         { "pair_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 106, offsetof(mavlink_cp_instance_status_t, pair_uuid) }, \
         { "pair_name", NULL, MAVLINK_TYPE_CHAR, 50, 143, offsetof(mavlink_cp_instance_status_t, pair_name) }, \
         { "video_duration", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_cp_instance_status_t, video_duration) }, \
         { "video_size", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_cp_instance_status_t, video_size) }, \
         { "video_time", NULL, MAVLINK_TYPE_UINT64_T, 0, 16, offsetof(mavlink_cp_instance_status_t, video_time) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 24, offsetof(mavlink_cp_instance_status_t, timestamp) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CP_INSTANCE_STATUS { \
    "CP_INSTANCE_STATUS", \
    8, \
    {  { "uuid", NULL, MAVLINK_TYPE_CHAR, 37, 32, offsetof(mavlink_cp_instance_status_t, uuid) }, \
         { "to_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 69, offsetof(mavlink_cp_instance_status_t, to_uuid) }, \
         { "pair_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 106, offsetof(mavlink_cp_instance_status_t, pair_uuid) }, \
         { "pair_name", NULL, MAVLINK_TYPE_CHAR, 50, 143, offsetof(mavlink_cp_instance_status_t, pair_name) }, \
         { "video_duration", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_cp_instance_status_t, video_duration) }, \
         { "video_size", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_cp_instance_status_t, video_size) }, \
         { "video_time", NULL, MAVLINK_TYPE_UINT64_T, 0, 16, offsetof(mavlink_cp_instance_status_t, video_time) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 24, offsetof(mavlink_cp_instance_status_t, timestamp) }, \
         } \
}
#endif

/**
 * @brief Pack a cp_instance_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uuid  uuid
 * @param to_uuid  to uuid
 * @param pair_uuid  pair uuid
 * @param pair_name  pair name
 * @param video_duration  video duration
 * @param video_size  video size
 * @param video_time  video time
 * @param timestamp  timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cp_instance_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *uuid, const char *to_uuid, const char *pair_uuid, const char *pair_name, uint64_t video_duration, uint64_t video_size, uint64_t video_time, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, video_duration);
    _mav_put_uint64_t(buf, 8, video_size);
    _mav_put_uint64_t(buf, 16, video_time);
    _mav_put_uint64_t(buf, 24, timestamp);
    _mav_put_char_array(buf, 32, uuid, 37);
    _mav_put_char_array(buf, 69, to_uuid, 37);
    _mav_put_char_array(buf, 106, pair_uuid, 37);
    _mav_put_char_array(buf, 143, pair_name, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN);
#else
    mavlink_cp_instance_status_t packet;
    packet.video_duration = video_duration;
    packet.video_size = video_size;
    packet.video_time = video_time;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet.to_uuid, to_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pair_uuid, pair_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pair_name, pair_name, sizeof(char)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CP_INSTANCE_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_CRC);
}

/**
 * @brief Pack a cp_instance_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uuid  uuid
 * @param to_uuid  to uuid
 * @param pair_uuid  pair uuid
 * @param pair_name  pair name
 * @param video_duration  video duration
 * @param video_size  video size
 * @param video_time  video time
 * @param timestamp  timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cp_instance_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *uuid,const char *to_uuid,const char *pair_uuid,const char *pair_name,uint64_t video_duration,uint64_t video_size,uint64_t video_time,uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, video_duration);
    _mav_put_uint64_t(buf, 8, video_size);
    _mav_put_uint64_t(buf, 16, video_time);
    _mav_put_uint64_t(buf, 24, timestamp);
    _mav_put_char_array(buf, 32, uuid, 37);
    _mav_put_char_array(buf, 69, to_uuid, 37);
    _mav_put_char_array(buf, 106, pair_uuid, 37);
    _mav_put_char_array(buf, 143, pair_name, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN);
#else
    mavlink_cp_instance_status_t packet;
    packet.video_duration = video_duration;
    packet.video_size = video_size;
    packet.video_time = video_time;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet.to_uuid, to_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pair_uuid, pair_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pair_name, pair_name, sizeof(char)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CP_INSTANCE_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_CRC);
}

/**
 * @brief Encode a cp_instance_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cp_instance_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cp_instance_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cp_instance_status_t* cp_instance_status)
{
    return mavlink_msg_cp_instance_status_pack(system_id, component_id, msg, cp_instance_status->uuid, cp_instance_status->to_uuid, cp_instance_status->pair_uuid, cp_instance_status->pair_name, cp_instance_status->video_duration, cp_instance_status->video_size, cp_instance_status->video_time, cp_instance_status->timestamp);
}

/**
 * @brief Encode a cp_instance_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cp_instance_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cp_instance_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cp_instance_status_t* cp_instance_status)
{
    return mavlink_msg_cp_instance_status_pack_chan(system_id, component_id, chan, msg, cp_instance_status->uuid, cp_instance_status->to_uuid, cp_instance_status->pair_uuid, cp_instance_status->pair_name, cp_instance_status->video_duration, cp_instance_status->video_size, cp_instance_status->video_time, cp_instance_status->timestamp);
}

/**
 * @brief Send a cp_instance_status message
 * @param chan MAVLink channel to send the message
 *
 * @param uuid  uuid
 * @param to_uuid  to uuid
 * @param pair_uuid  pair uuid
 * @param pair_name  pair name
 * @param video_duration  video duration
 * @param video_size  video size
 * @param video_time  video time
 * @param timestamp  timestamp
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cp_instance_status_send(mavlink_channel_t chan, const char *uuid, const char *to_uuid, const char *pair_uuid, const char *pair_name, uint64_t video_duration, uint64_t video_size, uint64_t video_time, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, video_duration);
    _mav_put_uint64_t(buf, 8, video_size);
    _mav_put_uint64_t(buf, 16, video_time);
    _mav_put_uint64_t(buf, 24, timestamp);
    _mav_put_char_array(buf, 32, uuid, 37);
    _mav_put_char_array(buf, 69, to_uuid, 37);
    _mav_put_char_array(buf, 106, pair_uuid, 37);
    _mav_put_char_array(buf, 143, pair_name, 50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_STATUS, buf, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_CRC);
#else
    mavlink_cp_instance_status_t packet;
    packet.video_duration = video_duration;
    packet.video_size = video_size;
    packet.video_time = video_time;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet.to_uuid, to_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pair_uuid, pair_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pair_name, pair_name, sizeof(char)*50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_STATUS, (const char *)&packet, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_CRC);
#endif
}

/**
 * @brief Send a cp_instance_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cp_instance_status_send_struct(mavlink_channel_t chan, const mavlink_cp_instance_status_t* cp_instance_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cp_instance_status_send(chan, cp_instance_status->uuid, cp_instance_status->to_uuid, cp_instance_status->pair_uuid, cp_instance_status->pair_name, cp_instance_status->video_duration, cp_instance_status->video_size, cp_instance_status->video_time, cp_instance_status->timestamp);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_STATUS, (const char *)cp_instance_status, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cp_instance_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *uuid, const char *to_uuid, const char *pair_uuid, const char *pair_name, uint64_t video_duration, uint64_t video_size, uint64_t video_time, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, video_duration);
    _mav_put_uint64_t(buf, 8, video_size);
    _mav_put_uint64_t(buf, 16, video_time);
    _mav_put_uint64_t(buf, 24, timestamp);
    _mav_put_char_array(buf, 32, uuid, 37);
    _mav_put_char_array(buf, 69, to_uuid, 37);
    _mav_put_char_array(buf, 106, pair_uuid, 37);
    _mav_put_char_array(buf, 143, pair_name, 50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_STATUS, buf, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_CRC);
#else
    mavlink_cp_instance_status_t *packet = (mavlink_cp_instance_status_t *)msgbuf;
    packet->video_duration = video_duration;
    packet->video_size = video_size;
    packet->video_time = video_time;
    packet->timestamp = timestamp;
    mav_array_memcpy(packet->uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet->to_uuid, to_uuid, sizeof(char)*37);
    mav_array_memcpy(packet->pair_uuid, pair_uuid, sizeof(char)*37);
    mav_array_memcpy(packet->pair_name, pair_name, sizeof(char)*50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_STATUS, (const char *)packet, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE CP_INSTANCE_STATUS UNPACKING


/**
 * @brief Get field uuid from cp_instance_status message
 *
 * @return  uuid
 */
static inline uint16_t mavlink_msg_cp_instance_status_get_uuid(const mavlink_message_t* msg, char *uuid)
{
    return _MAV_RETURN_char_array(msg, uuid, 37,  32);
}

/**
 * @brief Get field to_uuid from cp_instance_status message
 *
 * @return  to uuid
 */
static inline uint16_t mavlink_msg_cp_instance_status_get_to_uuid(const mavlink_message_t* msg, char *to_uuid)
{
    return _MAV_RETURN_char_array(msg, to_uuid, 37,  69);
}

/**
 * @brief Get field pair_uuid from cp_instance_status message
 *
 * @return  pair uuid
 */
static inline uint16_t mavlink_msg_cp_instance_status_get_pair_uuid(const mavlink_message_t* msg, char *pair_uuid)
{
    return _MAV_RETURN_char_array(msg, pair_uuid, 37,  106);
}

/**
 * @brief Get field pair_name from cp_instance_status message
 *
 * @return  pair name
 */
static inline uint16_t mavlink_msg_cp_instance_status_get_pair_name(const mavlink_message_t* msg, char *pair_name)
{
    return _MAV_RETURN_char_array(msg, pair_name, 50,  143);
}

/**
 * @brief Get field video_duration from cp_instance_status message
 *
 * @return  video duration
 */
static inline uint64_t mavlink_msg_cp_instance_status_get_video_duration(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field video_size from cp_instance_status message
 *
 * @return  video size
 */
static inline uint64_t mavlink_msg_cp_instance_status_get_video_size(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Get field video_time from cp_instance_status message
 *
 * @return  video time
 */
static inline uint64_t mavlink_msg_cp_instance_status_get_video_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  16);
}

/**
 * @brief Get field timestamp from cp_instance_status message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_cp_instance_status_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  24);
}

/**
 * @brief Decode a cp_instance_status message into a struct
 *
 * @param msg The message to decode
 * @param cp_instance_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_cp_instance_status_decode(const mavlink_message_t* msg, mavlink_cp_instance_status_t* cp_instance_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cp_instance_status->video_duration = mavlink_msg_cp_instance_status_get_video_duration(msg);
    cp_instance_status->video_size = mavlink_msg_cp_instance_status_get_video_size(msg);
    cp_instance_status->video_time = mavlink_msg_cp_instance_status_get_video_time(msg);
    cp_instance_status->timestamp = mavlink_msg_cp_instance_status_get_timestamp(msg);
    mavlink_msg_cp_instance_status_get_uuid(msg, cp_instance_status->uuid);
    mavlink_msg_cp_instance_status_get_to_uuid(msg, cp_instance_status->to_uuid);
    mavlink_msg_cp_instance_status_get_pair_uuid(msg, cp_instance_status->pair_uuid);
    mavlink_msg_cp_instance_status_get_pair_name(msg, cp_instance_status->pair_name);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN? msg->len : MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN;
        memset(cp_instance_status, 0, MAVLINK_MSG_ID_CP_INSTANCE_STATUS_LEN);
    memcpy(cp_instance_status, _MAV_PAYLOAD(msg), len);
#endif
}
