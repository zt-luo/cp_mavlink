#pragma once
// MESSAGE HEARTBEAT PACKING

#define MAVLINK_MSG_ID_HEARTBEAT 0

MAVPACKED(
typedef struct __mavlink_heartbeat_t {
 uint64_t timestamp; /*<  timestamp*/
 char uuid[37]; /*<  my uuid*/
 char pass_uuid[37]; /*<  pass uuid*/
 char to_uuid[37]; /*<  to uuid*/
 char pair_uuid[37]; /*<  pair uuid*/
}) mavlink_heartbeat_t;

#define MAVLINK_MSG_ID_HEARTBEAT_LEN 156
#define MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN 156
#define MAVLINK_MSG_ID_0_LEN 156
#define MAVLINK_MSG_ID_0_MIN_LEN 156

#define MAVLINK_MSG_ID_HEARTBEAT_CRC 225
#define MAVLINK_MSG_ID_0_CRC 225

#define MAVLINK_MSG_HEARTBEAT_FIELD_UUID_LEN 37
#define MAVLINK_MSG_HEARTBEAT_FIELD_PASS_UUID_LEN 37
#define MAVLINK_MSG_HEARTBEAT_FIELD_TO_UUID_LEN 37
#define MAVLINK_MSG_HEARTBEAT_FIELD_PAIR_UUID_LEN 37

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HEARTBEAT { \
    0, \
    "HEARTBEAT", \
    5, \
    {  { "uuid", NULL, MAVLINK_TYPE_CHAR, 37, 8, offsetof(mavlink_heartbeat_t, uuid) }, \
         { "pass_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 45, offsetof(mavlink_heartbeat_t, pass_uuid) }, \
         { "to_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 82, offsetof(mavlink_heartbeat_t, to_uuid) }, \
         { "pair_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 119, offsetof(mavlink_heartbeat_t, pair_uuid) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_heartbeat_t, timestamp) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HEARTBEAT { \
    "HEARTBEAT", \
    5, \
    {  { "uuid", NULL, MAVLINK_TYPE_CHAR, 37, 8, offsetof(mavlink_heartbeat_t, uuid) }, \
         { "pass_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 45, offsetof(mavlink_heartbeat_t, pass_uuid) }, \
         { "to_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 82, offsetof(mavlink_heartbeat_t, to_uuid) }, \
         { "pair_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 119, offsetof(mavlink_heartbeat_t, pair_uuid) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_heartbeat_t, timestamp) }, \
         } \
}
#endif

/**
 * @brief Pack a heartbeat message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uuid  my uuid
 * @param pass_uuid  pass uuid
 * @param to_uuid  to uuid
 * @param pair_uuid  pair uuid
 * @param timestamp  timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heartbeat_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *uuid, const char *pass_uuid, const char *to_uuid, const char *pair_uuid, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEARTBEAT_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_char_array(buf, 8, uuid, 37);
    _mav_put_char_array(buf, 45, pass_uuid, 37);
    _mav_put_char_array(buf, 82, to_uuid, 37);
    _mav_put_char_array(buf, 119, pair_uuid, 37);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#else
    mavlink_heartbeat_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pass_uuid, pass_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.to_uuid, to_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pair_uuid, pair_uuid, sizeof(char)*37);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HEARTBEAT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
}

/**
 * @brief Pack a heartbeat message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uuid  my uuid
 * @param pass_uuid  pass uuid
 * @param to_uuid  to uuid
 * @param pair_uuid  pair uuid
 * @param timestamp  timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_heartbeat_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *uuid,const char *pass_uuid,const char *to_uuid,const char *pair_uuid,uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEARTBEAT_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_char_array(buf, 8, uuid, 37);
    _mav_put_char_array(buf, 45, pass_uuid, 37);
    _mav_put_char_array(buf, 82, to_uuid, 37);
    _mav_put_char_array(buf, 119, pair_uuid, 37);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#else
    mavlink_heartbeat_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pass_uuid, pass_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.to_uuid, to_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pair_uuid, pair_uuid, sizeof(char)*37);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HEARTBEAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HEARTBEAT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
}

/**
 * @brief Encode a heartbeat struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_heartbeat_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_heartbeat_t* heartbeat)
{
    return mavlink_msg_heartbeat_pack(system_id, component_id, msg, heartbeat->uuid, heartbeat->pass_uuid, heartbeat->to_uuid, heartbeat->pair_uuid, heartbeat->timestamp);
}

/**
 * @brief Encode a heartbeat struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param heartbeat C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_heartbeat_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_heartbeat_t* heartbeat)
{
    return mavlink_msg_heartbeat_pack_chan(system_id, component_id, chan, msg, heartbeat->uuid, heartbeat->pass_uuid, heartbeat->to_uuid, heartbeat->pair_uuid, heartbeat->timestamp);
}

/**
 * @brief Send a heartbeat message
 * @param chan MAVLink channel to send the message
 *
 * @param uuid  my uuid
 * @param pass_uuid  pass uuid
 * @param to_uuid  to uuid
 * @param pair_uuid  pair uuid
 * @param timestamp  timestamp
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_heartbeat_send(mavlink_channel_t chan, const char *uuid, const char *pass_uuid, const char *to_uuid, const char *pair_uuid, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HEARTBEAT_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_char_array(buf, 8, uuid, 37);
    _mav_put_char_array(buf, 45, pass_uuid, 37);
    _mav_put_char_array(buf, 82, to_uuid, 37);
    _mav_put_char_array(buf, 119, pair_uuid, 37);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, buf, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#else
    mavlink_heartbeat_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pass_uuid, pass_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.to_uuid, to_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pair_uuid, pair_uuid, sizeof(char)*37);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, (const char *)&packet, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#endif
}

/**
 * @brief Send a heartbeat message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_heartbeat_send_struct(mavlink_channel_t chan, const mavlink_heartbeat_t* heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_heartbeat_send(chan, heartbeat->uuid, heartbeat->pass_uuid, heartbeat->to_uuid, heartbeat->pair_uuid, heartbeat->timestamp);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, (const char *)heartbeat, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#endif
}

#if MAVLINK_MSG_ID_HEARTBEAT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_heartbeat_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *uuid, const char *pass_uuid, const char *to_uuid, const char *pair_uuid, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_char_array(buf, 8, uuid, 37);
    _mav_put_char_array(buf, 45, pass_uuid, 37);
    _mav_put_char_array(buf, 82, to_uuid, 37);
    _mav_put_char_array(buf, 119, pair_uuid, 37);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, buf, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#else
    mavlink_heartbeat_t *packet = (mavlink_heartbeat_t *)msgbuf;
    packet->timestamp = timestamp;
    mav_array_memcpy(packet->uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet->pass_uuid, pass_uuid, sizeof(char)*37);
    mav_array_memcpy(packet->to_uuid, to_uuid, sizeof(char)*37);
    mav_array_memcpy(packet->pair_uuid, pair_uuid, sizeof(char)*37);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HEARTBEAT, (const char *)packet, MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN, MAVLINK_MSG_ID_HEARTBEAT_LEN, MAVLINK_MSG_ID_HEARTBEAT_CRC);
#endif
}
#endif

#endif

// MESSAGE HEARTBEAT UNPACKING


/**
 * @brief Get field uuid from heartbeat message
 *
 * @return  my uuid
 */
static inline uint16_t mavlink_msg_heartbeat_get_uuid(const mavlink_message_t* msg, char *uuid)
{
    return _MAV_RETURN_char_array(msg, uuid, 37,  8);
}

/**
 * @brief Get field pass_uuid from heartbeat message
 *
 * @return  pass uuid
 */
static inline uint16_t mavlink_msg_heartbeat_get_pass_uuid(const mavlink_message_t* msg, char *pass_uuid)
{
    return _MAV_RETURN_char_array(msg, pass_uuid, 37,  45);
}

/**
 * @brief Get field to_uuid from heartbeat message
 *
 * @return  to uuid
 */
static inline uint16_t mavlink_msg_heartbeat_get_to_uuid(const mavlink_message_t* msg, char *to_uuid)
{
    return _MAV_RETURN_char_array(msg, to_uuid, 37,  82);
}

/**
 * @brief Get field pair_uuid from heartbeat message
 *
 * @return  pair uuid
 */
static inline uint16_t mavlink_msg_heartbeat_get_pair_uuid(const mavlink_message_t* msg, char *pair_uuid)
{
    return _MAV_RETURN_char_array(msg, pair_uuid, 37,  119);
}

/**
 * @brief Get field timestamp from heartbeat message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_heartbeat_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Decode a heartbeat message into a struct
 *
 * @param msg The message to decode
 * @param heartbeat C-struct to decode the message contents into
 */
static inline void mavlink_msg_heartbeat_decode(const mavlink_message_t* msg, mavlink_heartbeat_t* heartbeat)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    heartbeat->timestamp = mavlink_msg_heartbeat_get_timestamp(msg);
    mavlink_msg_heartbeat_get_uuid(msg, heartbeat->uuid);
    mavlink_msg_heartbeat_get_pass_uuid(msg, heartbeat->pass_uuid);
    mavlink_msg_heartbeat_get_to_uuid(msg, heartbeat->to_uuid);
    mavlink_msg_heartbeat_get_pair_uuid(msg, heartbeat->pair_uuid);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_HEARTBEAT_LEN? msg->len : MAVLINK_MSG_ID_HEARTBEAT_LEN;
        memset(heartbeat, 0, MAVLINK_MSG_ID_HEARTBEAT_LEN);
    memcpy(heartbeat, _MAV_PAYLOAD(msg), len);
#endif
}
