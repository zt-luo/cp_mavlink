#pragma once
// MESSAGE CP_INSTANCE_PAIR PACKING

#define MAVLINK_MSG_ID_CP_INSTANCE_PAIR 4

MAVPACKED(
typedef struct __mavlink_cp_instance_pair_t {
 uint64_t timestamp; /*<  timestamp*/
 char uuid[37]; /*<  my uuid*/
 char pass_uuid[37]; /*<  pass uuid*/
 char pair_uuid[37]; /*<  pair uuid*/
 char pair_name[50]; /*<  pair name*/
 uint8_t pair_stage; /*<  Pair Stage*/
}) mavlink_cp_instance_pair_t;

#define MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN 170
#define MAVLINK_MSG_ID_CP_INSTANCE_PAIR_MIN_LEN 170
#define MAVLINK_MSG_ID_4_LEN 170
#define MAVLINK_MSG_ID_4_MIN_LEN 170

#define MAVLINK_MSG_ID_CP_INSTANCE_PAIR_CRC 101
#define MAVLINK_MSG_ID_4_CRC 101

#define MAVLINK_MSG_CP_INSTANCE_PAIR_FIELD_UUID_LEN 37
#define MAVLINK_MSG_CP_INSTANCE_PAIR_FIELD_PASS_UUID_LEN 37
#define MAVLINK_MSG_CP_INSTANCE_PAIR_FIELD_PAIR_UUID_LEN 37
#define MAVLINK_MSG_CP_INSTANCE_PAIR_FIELD_PAIR_NAME_LEN 50

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CP_INSTANCE_PAIR { \
    4, \
    "CP_INSTANCE_PAIR", \
    6, \
    {  { "uuid", NULL, MAVLINK_TYPE_CHAR, 37, 8, offsetof(mavlink_cp_instance_pair_t, uuid) }, \
         { "pass_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 45, offsetof(mavlink_cp_instance_pair_t, pass_uuid) }, \
         { "pair_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 82, offsetof(mavlink_cp_instance_pair_t, pair_uuid) }, \
         { "pair_name", NULL, MAVLINK_TYPE_CHAR, 50, 119, offsetof(mavlink_cp_instance_pair_t, pair_name) }, \
         { "pair_stage", NULL, MAVLINK_TYPE_UINT8_T, 0, 169, offsetof(mavlink_cp_instance_pair_t, pair_stage) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_cp_instance_pair_t, timestamp) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CP_INSTANCE_PAIR { \
    "CP_INSTANCE_PAIR", \
    6, \
    {  { "uuid", NULL, MAVLINK_TYPE_CHAR, 37, 8, offsetof(mavlink_cp_instance_pair_t, uuid) }, \
         { "pass_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 45, offsetof(mavlink_cp_instance_pair_t, pass_uuid) }, \
         { "pair_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 82, offsetof(mavlink_cp_instance_pair_t, pair_uuid) }, \
         { "pair_name", NULL, MAVLINK_TYPE_CHAR, 50, 119, offsetof(mavlink_cp_instance_pair_t, pair_name) }, \
         { "pair_stage", NULL, MAVLINK_TYPE_UINT8_T, 0, 169, offsetof(mavlink_cp_instance_pair_t, pair_stage) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_cp_instance_pair_t, timestamp) }, \
         } \
}
#endif

/**
 * @brief Pack a cp_instance_pair message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uuid  my uuid
 * @param pass_uuid  pass uuid
 * @param pair_uuid  pair uuid
 * @param pair_name  pair name
 * @param pair_stage  Pair Stage
 * @param timestamp  timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cp_instance_pair_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *uuid, const char *pass_uuid, const char *pair_uuid, const char *pair_name, uint8_t pair_stage, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 169, pair_stage);
    _mav_put_char_array(buf, 8, uuid, 37);
    _mav_put_char_array(buf, 45, pass_uuid, 37);
    _mav_put_char_array(buf, 82, pair_uuid, 37);
    _mav_put_char_array(buf, 119, pair_name, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN);
#else
    mavlink_cp_instance_pair_t packet;
    packet.timestamp = timestamp;
    packet.pair_stage = pair_stage;
    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pass_uuid, pass_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pair_uuid, pair_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pair_name, pair_name, sizeof(char)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CP_INSTANCE_PAIR;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_CRC);
}

/**
 * @brief Pack a cp_instance_pair message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uuid  my uuid
 * @param pass_uuid  pass uuid
 * @param pair_uuid  pair uuid
 * @param pair_name  pair name
 * @param pair_stage  Pair Stage
 * @param timestamp  timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cp_instance_pair_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *uuid,const char *pass_uuid,const char *pair_uuid,const char *pair_name,uint8_t pair_stage,uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 169, pair_stage);
    _mav_put_char_array(buf, 8, uuid, 37);
    _mav_put_char_array(buf, 45, pass_uuid, 37);
    _mav_put_char_array(buf, 82, pair_uuid, 37);
    _mav_put_char_array(buf, 119, pair_name, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN);
#else
    mavlink_cp_instance_pair_t packet;
    packet.timestamp = timestamp;
    packet.pair_stage = pair_stage;
    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pass_uuid, pass_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pair_uuid, pair_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pair_name, pair_name, sizeof(char)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CP_INSTANCE_PAIR;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_CRC);
}

/**
 * @brief Encode a cp_instance_pair struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cp_instance_pair C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cp_instance_pair_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cp_instance_pair_t* cp_instance_pair)
{
    return mavlink_msg_cp_instance_pair_pack(system_id, component_id, msg, cp_instance_pair->uuid, cp_instance_pair->pass_uuid, cp_instance_pair->pair_uuid, cp_instance_pair->pair_name, cp_instance_pair->pair_stage, cp_instance_pair->timestamp);
}

/**
 * @brief Encode a cp_instance_pair struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cp_instance_pair C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cp_instance_pair_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cp_instance_pair_t* cp_instance_pair)
{
    return mavlink_msg_cp_instance_pair_pack_chan(system_id, component_id, chan, msg, cp_instance_pair->uuid, cp_instance_pair->pass_uuid, cp_instance_pair->pair_uuid, cp_instance_pair->pair_name, cp_instance_pair->pair_stage, cp_instance_pair->timestamp);
}

/**
 * @brief Send a cp_instance_pair message
 * @param chan MAVLink channel to send the message
 *
 * @param uuid  my uuid
 * @param pass_uuid  pass uuid
 * @param pair_uuid  pair uuid
 * @param pair_name  pair name
 * @param pair_stage  Pair Stage
 * @param timestamp  timestamp
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cp_instance_pair_send(mavlink_channel_t chan, const char *uuid, const char *pass_uuid, const char *pair_uuid, const char *pair_name, uint8_t pair_stage, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 169, pair_stage);
    _mav_put_char_array(buf, 8, uuid, 37);
    _mav_put_char_array(buf, 45, pass_uuid, 37);
    _mav_put_char_array(buf, 82, pair_uuid, 37);
    _mav_put_char_array(buf, 119, pair_name, 50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_PAIR, buf, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_CRC);
#else
    mavlink_cp_instance_pair_t packet;
    packet.timestamp = timestamp;
    packet.pair_stage = pair_stage;
    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pass_uuid, pass_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pair_uuid, pair_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pair_name, pair_name, sizeof(char)*50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_PAIR, (const char *)&packet, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_CRC);
#endif
}

/**
 * @brief Send a cp_instance_pair message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cp_instance_pair_send_struct(mavlink_channel_t chan, const mavlink_cp_instance_pair_t* cp_instance_pair)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cp_instance_pair_send(chan, cp_instance_pair->uuid, cp_instance_pair->pass_uuid, cp_instance_pair->pair_uuid, cp_instance_pair->pair_name, cp_instance_pair->pair_stage, cp_instance_pair->timestamp);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_PAIR, (const char *)cp_instance_pair, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_CRC);
#endif
}

#if MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cp_instance_pair_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *uuid, const char *pass_uuid, const char *pair_uuid, const char *pair_name, uint8_t pair_stage, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 169, pair_stage);
    _mav_put_char_array(buf, 8, uuid, 37);
    _mav_put_char_array(buf, 45, pass_uuid, 37);
    _mav_put_char_array(buf, 82, pair_uuid, 37);
    _mav_put_char_array(buf, 119, pair_name, 50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_PAIR, buf, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_CRC);
#else
    mavlink_cp_instance_pair_t *packet = (mavlink_cp_instance_pair_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->pair_stage = pair_stage;
    mav_array_memcpy(packet->uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet->pass_uuid, pass_uuid, sizeof(char)*37);
    mav_array_memcpy(packet->pair_uuid, pair_uuid, sizeof(char)*37);
    mav_array_memcpy(packet->pair_name, pair_name, sizeof(char)*50);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_PAIR, (const char *)packet, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_CRC);
#endif
}
#endif

#endif

// MESSAGE CP_INSTANCE_PAIR UNPACKING


/**
 * @brief Get field uuid from cp_instance_pair message
 *
 * @return  my uuid
 */
static inline uint16_t mavlink_msg_cp_instance_pair_get_uuid(const mavlink_message_t* msg, char *uuid)
{
    return _MAV_RETURN_char_array(msg, uuid, 37,  8);
}

/**
 * @brief Get field pass_uuid from cp_instance_pair message
 *
 * @return  pass uuid
 */
static inline uint16_t mavlink_msg_cp_instance_pair_get_pass_uuid(const mavlink_message_t* msg, char *pass_uuid)
{
    return _MAV_RETURN_char_array(msg, pass_uuid, 37,  45);
}

/**
 * @brief Get field pair_uuid from cp_instance_pair message
 *
 * @return  pair uuid
 */
static inline uint16_t mavlink_msg_cp_instance_pair_get_pair_uuid(const mavlink_message_t* msg, char *pair_uuid)
{
    return _MAV_RETURN_char_array(msg, pair_uuid, 37,  82);
}

/**
 * @brief Get field pair_name from cp_instance_pair message
 *
 * @return  pair name
 */
static inline uint16_t mavlink_msg_cp_instance_pair_get_pair_name(const mavlink_message_t* msg, char *pair_name)
{
    return _MAV_RETURN_char_array(msg, pair_name, 50,  119);
}

/**
 * @brief Get field pair_stage from cp_instance_pair message
 *
 * @return  Pair Stage
 */
static inline uint8_t mavlink_msg_cp_instance_pair_get_pair_stage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  169);
}

/**
 * @brief Get field timestamp from cp_instance_pair message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_cp_instance_pair_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Decode a cp_instance_pair message into a struct
 *
 * @param msg The message to decode
 * @param cp_instance_pair C-struct to decode the message contents into
 */
static inline void mavlink_msg_cp_instance_pair_decode(const mavlink_message_t* msg, mavlink_cp_instance_pair_t* cp_instance_pair)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cp_instance_pair->timestamp = mavlink_msg_cp_instance_pair_get_timestamp(msg);
    mavlink_msg_cp_instance_pair_get_uuid(msg, cp_instance_pair->uuid);
    mavlink_msg_cp_instance_pair_get_pass_uuid(msg, cp_instance_pair->pass_uuid);
    mavlink_msg_cp_instance_pair_get_pair_uuid(msg, cp_instance_pair->pair_uuid);
    mavlink_msg_cp_instance_pair_get_pair_name(msg, cp_instance_pair->pair_name);
    cp_instance_pair->pair_stage = mavlink_msg_cp_instance_pair_get_pair_stage(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN? msg->len : MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN;
        memset(cp_instance_pair, 0, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_LEN);
    memcpy(cp_instance_pair, _MAV_PAYLOAD(msg), len);
#endif
}
