#pragma once
// MESSAGE CP_INSTANCE_PAIR_ACK PACKING

#define MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK 5

MAVPACKED(
typedef struct __mavlink_cp_instance_pair_ack_t {
 uint64_t timestamp; /*<  timestamp*/
 char uuid[37]; /*<  uuid*/
 char to_uuid[37]; /*<  to uuid*/
 uint8_t pair_stage; /*<  Pair Stage*/
 uint8_t ack; /*<  Pair ACK*/
}) mavlink_cp_instance_pair_ack_t;

#define MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN 84
#define MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_MIN_LEN 84
#define MAVLINK_MSG_ID_5_LEN 84
#define MAVLINK_MSG_ID_5_MIN_LEN 84

#define MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_CRC 123
#define MAVLINK_MSG_ID_5_CRC 123

#define MAVLINK_MSG_CP_INSTANCE_PAIR_ACK_FIELD_UUID_LEN 37
#define MAVLINK_MSG_CP_INSTANCE_PAIR_ACK_FIELD_TO_UUID_LEN 37

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CP_INSTANCE_PAIR_ACK { \
    5, \
    "CP_INSTANCE_PAIR_ACK", \
    5, \
    {  { "uuid", NULL, MAVLINK_TYPE_CHAR, 37, 8, offsetof(mavlink_cp_instance_pair_ack_t, uuid) }, \
         { "to_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 45, offsetof(mavlink_cp_instance_pair_ack_t, to_uuid) }, \
         { "pair_stage", NULL, MAVLINK_TYPE_UINT8_T, 0, 82, offsetof(mavlink_cp_instance_pair_ack_t, pair_stage) }, \
         { "ack", NULL, MAVLINK_TYPE_UINT8_T, 0, 83, offsetof(mavlink_cp_instance_pair_ack_t, ack) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_cp_instance_pair_ack_t, timestamp) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CP_INSTANCE_PAIR_ACK { \
    "CP_INSTANCE_PAIR_ACK", \
    5, \
    {  { "uuid", NULL, MAVLINK_TYPE_CHAR, 37, 8, offsetof(mavlink_cp_instance_pair_ack_t, uuid) }, \
         { "to_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 45, offsetof(mavlink_cp_instance_pair_ack_t, to_uuid) }, \
         { "pair_stage", NULL, MAVLINK_TYPE_UINT8_T, 0, 82, offsetof(mavlink_cp_instance_pair_ack_t, pair_stage) }, \
         { "ack", NULL, MAVLINK_TYPE_UINT8_T, 0, 83, offsetof(mavlink_cp_instance_pair_ack_t, ack) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_cp_instance_pair_ack_t, timestamp) }, \
         } \
}
#endif

/**
 * @brief Pack a cp_instance_pair_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uuid  uuid
 * @param to_uuid  to uuid
 * @param pair_stage  Pair Stage
 * @param ack  Pair ACK
 * @param timestamp  timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cp_instance_pair_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *uuid, const char *to_uuid, uint8_t pair_stage, uint8_t ack, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 82, pair_stage);
    _mav_put_uint8_t(buf, 83, ack);
    _mav_put_char_array(buf, 8, uuid, 37);
    _mav_put_char_array(buf, 45, to_uuid, 37);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN);
#else
    mavlink_cp_instance_pair_ack_t packet;
    packet.timestamp = timestamp;
    packet.pair_stage = pair_stage;
    packet.ack = ack;
    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet.to_uuid, to_uuid, sizeof(char)*37);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_CRC);
}

/**
 * @brief Pack a cp_instance_pair_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uuid  uuid
 * @param to_uuid  to uuid
 * @param pair_stage  Pair Stage
 * @param ack  Pair ACK
 * @param timestamp  timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cp_instance_pair_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *uuid,const char *to_uuid,uint8_t pair_stage,uint8_t ack,uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 82, pair_stage);
    _mav_put_uint8_t(buf, 83, ack);
    _mav_put_char_array(buf, 8, uuid, 37);
    _mav_put_char_array(buf, 45, to_uuid, 37);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN);
#else
    mavlink_cp_instance_pair_ack_t packet;
    packet.timestamp = timestamp;
    packet.pair_stage = pair_stage;
    packet.ack = ack;
    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet.to_uuid, to_uuid, sizeof(char)*37);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_CRC);
}

/**
 * @brief Encode a cp_instance_pair_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cp_instance_pair_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cp_instance_pair_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cp_instance_pair_ack_t* cp_instance_pair_ack)
{
    return mavlink_msg_cp_instance_pair_ack_pack(system_id, component_id, msg, cp_instance_pair_ack->uuid, cp_instance_pair_ack->to_uuid, cp_instance_pair_ack->pair_stage, cp_instance_pair_ack->ack, cp_instance_pair_ack->timestamp);
}

/**
 * @brief Encode a cp_instance_pair_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cp_instance_pair_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cp_instance_pair_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cp_instance_pair_ack_t* cp_instance_pair_ack)
{
    return mavlink_msg_cp_instance_pair_ack_pack_chan(system_id, component_id, chan, msg, cp_instance_pair_ack->uuid, cp_instance_pair_ack->to_uuid, cp_instance_pair_ack->pair_stage, cp_instance_pair_ack->ack, cp_instance_pair_ack->timestamp);
}

/**
 * @brief Send a cp_instance_pair_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param uuid  uuid
 * @param to_uuid  to uuid
 * @param pair_stage  Pair Stage
 * @param ack  Pair ACK
 * @param timestamp  timestamp
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cp_instance_pair_ack_send(mavlink_channel_t chan, const char *uuid, const char *to_uuid, uint8_t pair_stage, uint8_t ack, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 82, pair_stage);
    _mav_put_uint8_t(buf, 83, ack);
    _mav_put_char_array(buf, 8, uuid, 37);
    _mav_put_char_array(buf, 45, to_uuid, 37);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK, buf, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_CRC);
#else
    mavlink_cp_instance_pair_ack_t packet;
    packet.timestamp = timestamp;
    packet.pair_stage = pair_stage;
    packet.ack = ack;
    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet.to_uuid, to_uuid, sizeof(char)*37);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK, (const char *)&packet, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_CRC);
#endif
}

/**
 * @brief Send a cp_instance_pair_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cp_instance_pair_ack_send_struct(mavlink_channel_t chan, const mavlink_cp_instance_pair_ack_t* cp_instance_pair_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cp_instance_pair_ack_send(chan, cp_instance_pair_ack->uuid, cp_instance_pair_ack->to_uuid, cp_instance_pair_ack->pair_stage, cp_instance_pair_ack->ack, cp_instance_pair_ack->timestamp);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK, (const char *)cp_instance_pair_ack, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cp_instance_pair_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *uuid, const char *to_uuid, uint8_t pair_stage, uint8_t ack, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 82, pair_stage);
    _mav_put_uint8_t(buf, 83, ack);
    _mav_put_char_array(buf, 8, uuid, 37);
    _mav_put_char_array(buf, 45, to_uuid, 37);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK, buf, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_CRC);
#else
    mavlink_cp_instance_pair_ack_t *packet = (mavlink_cp_instance_pair_ack_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->pair_stage = pair_stage;
    packet->ack = ack;
    mav_array_memcpy(packet->uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet->to_uuid, to_uuid, sizeof(char)*37);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK, (const char *)packet, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_CRC);
#endif
}
#endif

#endif

// MESSAGE CP_INSTANCE_PAIR_ACK UNPACKING


/**
 * @brief Get field uuid from cp_instance_pair_ack message
 *
 * @return  uuid
 */
static inline uint16_t mavlink_msg_cp_instance_pair_ack_get_uuid(const mavlink_message_t* msg, char *uuid)
{
    return _MAV_RETURN_char_array(msg, uuid, 37,  8);
}

/**
 * @brief Get field to_uuid from cp_instance_pair_ack message
 *
 * @return  to uuid
 */
static inline uint16_t mavlink_msg_cp_instance_pair_ack_get_to_uuid(const mavlink_message_t* msg, char *to_uuid)
{
    return _MAV_RETURN_char_array(msg, to_uuid, 37,  45);
}

/**
 * @brief Get field pair_stage from cp_instance_pair_ack message
 *
 * @return  Pair Stage
 */
static inline uint8_t mavlink_msg_cp_instance_pair_ack_get_pair_stage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  82);
}

/**
 * @brief Get field ack from cp_instance_pair_ack message
 *
 * @return  Pair ACK
 */
static inline uint8_t mavlink_msg_cp_instance_pair_ack_get_ack(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  83);
}

/**
 * @brief Get field timestamp from cp_instance_pair_ack message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_cp_instance_pair_ack_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Decode a cp_instance_pair_ack message into a struct
 *
 * @param msg The message to decode
 * @param cp_instance_pair_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_cp_instance_pair_ack_decode(const mavlink_message_t* msg, mavlink_cp_instance_pair_ack_t* cp_instance_pair_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cp_instance_pair_ack->timestamp = mavlink_msg_cp_instance_pair_ack_get_timestamp(msg);
    mavlink_msg_cp_instance_pair_ack_get_uuid(msg, cp_instance_pair_ack->uuid);
    mavlink_msg_cp_instance_pair_ack_get_to_uuid(msg, cp_instance_pair_ack->to_uuid);
    cp_instance_pair_ack->pair_stage = mavlink_msg_cp_instance_pair_ack_get_pair_stage(msg);
    cp_instance_pair_ack->ack = mavlink_msg_cp_instance_pair_ack_get_ack(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN? msg->len : MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN;
        memset(cp_instance_pair_ack, 0, MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_LEN);
    memcpy(cp_instance_pair_ack, _MAV_PAYLOAD(msg), len);
#endif
}
