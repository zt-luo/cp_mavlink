#pragma once
// MESSAGE CP_INSTANCE_OP PACKING

#define MAVLINK_MSG_ID_CP_INSTANCE_OP 1

MAVPACKED(
typedef struct __mavlink_cp_instance_op_t {
 uint64_t timestamp; /*<  timestamp*/
 char uuid[37]; /*<  my uuid*/
 char pass_uuid[37]; /*<  pass uuid*/
 char prv_uuid[37]; /*<  previous uuid*/
 uint8_t op; /*<  Operation Type*/
}) mavlink_cp_instance_op_t;

#define MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN 120
#define MAVLINK_MSG_ID_CP_INSTANCE_OP_MIN_LEN 120
#define MAVLINK_MSG_ID_1_LEN 120
#define MAVLINK_MSG_ID_1_MIN_LEN 120

#define MAVLINK_MSG_ID_CP_INSTANCE_OP_CRC 13
#define MAVLINK_MSG_ID_1_CRC 13

#define MAVLINK_MSG_CP_INSTANCE_OP_FIELD_UUID_LEN 37
#define MAVLINK_MSG_CP_INSTANCE_OP_FIELD_PASS_UUID_LEN 37
#define MAVLINK_MSG_CP_INSTANCE_OP_FIELD_PRV_UUID_LEN 37

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CP_INSTANCE_OP { \
    1, \
    "CP_INSTANCE_OP", \
    5, \
    {  { "uuid", NULL, MAVLINK_TYPE_CHAR, 37, 8, offsetof(mavlink_cp_instance_op_t, uuid) }, \
         { "pass_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 45, offsetof(mavlink_cp_instance_op_t, pass_uuid) }, \
         { "prv_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 82, offsetof(mavlink_cp_instance_op_t, prv_uuid) }, \
         { "op", NULL, MAVLINK_TYPE_UINT8_T, 0, 119, offsetof(mavlink_cp_instance_op_t, op) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_cp_instance_op_t, timestamp) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CP_INSTANCE_OP { \
    "CP_INSTANCE_OP", \
    5, \
    {  { "uuid", NULL, MAVLINK_TYPE_CHAR, 37, 8, offsetof(mavlink_cp_instance_op_t, uuid) }, \
         { "pass_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 45, offsetof(mavlink_cp_instance_op_t, pass_uuid) }, \
         { "prv_uuid", NULL, MAVLINK_TYPE_CHAR, 37, 82, offsetof(mavlink_cp_instance_op_t, prv_uuid) }, \
         { "op", NULL, MAVLINK_TYPE_UINT8_T, 0, 119, offsetof(mavlink_cp_instance_op_t, op) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_cp_instance_op_t, timestamp) }, \
         } \
}
#endif

/**
 * @brief Pack a cp_instance_op message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uuid  my uuid
 * @param pass_uuid  pass uuid
 * @param prv_uuid  previous uuid
 * @param op  Operation Type
 * @param timestamp  timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cp_instance_op_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *uuid, const char *pass_uuid, const char *prv_uuid, uint8_t op, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 119, op);
    _mav_put_char_array(buf, 8, uuid, 37);
    _mav_put_char_array(buf, 45, pass_uuid, 37);
    _mav_put_char_array(buf, 82, prv_uuid, 37);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN);
#else
    mavlink_cp_instance_op_t packet;
    packet.timestamp = timestamp;
    packet.op = op;
    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pass_uuid, pass_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.prv_uuid, prv_uuid, sizeof(char)*37);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CP_INSTANCE_OP;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CP_INSTANCE_OP_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN, MAVLINK_MSG_ID_CP_INSTANCE_OP_CRC);
}

/**
 * @brief Pack a cp_instance_op message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uuid  my uuid
 * @param pass_uuid  pass uuid
 * @param prv_uuid  previous uuid
 * @param op  Operation Type
 * @param timestamp  timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cp_instance_op_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *uuid,const char *pass_uuid,const char *prv_uuid,uint8_t op,uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 119, op);
    _mav_put_char_array(buf, 8, uuid, 37);
    _mav_put_char_array(buf, 45, pass_uuid, 37);
    _mav_put_char_array(buf, 82, prv_uuid, 37);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN);
#else
    mavlink_cp_instance_op_t packet;
    packet.timestamp = timestamp;
    packet.op = op;
    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pass_uuid, pass_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.prv_uuid, prv_uuid, sizeof(char)*37);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CP_INSTANCE_OP;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CP_INSTANCE_OP_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN, MAVLINK_MSG_ID_CP_INSTANCE_OP_CRC);
}

/**
 * @brief Encode a cp_instance_op struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cp_instance_op C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cp_instance_op_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cp_instance_op_t* cp_instance_op)
{
    return mavlink_msg_cp_instance_op_pack(system_id, component_id, msg, cp_instance_op->uuid, cp_instance_op->pass_uuid, cp_instance_op->prv_uuid, cp_instance_op->op, cp_instance_op->timestamp);
}

/**
 * @brief Encode a cp_instance_op struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cp_instance_op C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cp_instance_op_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cp_instance_op_t* cp_instance_op)
{
    return mavlink_msg_cp_instance_op_pack_chan(system_id, component_id, chan, msg, cp_instance_op->uuid, cp_instance_op->pass_uuid, cp_instance_op->prv_uuid, cp_instance_op->op, cp_instance_op->timestamp);
}

/**
 * @brief Send a cp_instance_op message
 * @param chan MAVLink channel to send the message
 *
 * @param uuid  my uuid
 * @param pass_uuid  pass uuid
 * @param prv_uuid  previous uuid
 * @param op  Operation Type
 * @param timestamp  timestamp
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cp_instance_op_send(mavlink_channel_t chan, const char *uuid, const char *pass_uuid, const char *prv_uuid, uint8_t op, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 119, op);
    _mav_put_char_array(buf, 8, uuid, 37);
    _mav_put_char_array(buf, 45, pass_uuid, 37);
    _mav_put_char_array(buf, 82, prv_uuid, 37);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_OP, buf, MAVLINK_MSG_ID_CP_INSTANCE_OP_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN, MAVLINK_MSG_ID_CP_INSTANCE_OP_CRC);
#else
    mavlink_cp_instance_op_t packet;
    packet.timestamp = timestamp;
    packet.op = op;
    mav_array_memcpy(packet.uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet.pass_uuid, pass_uuid, sizeof(char)*37);
    mav_array_memcpy(packet.prv_uuid, prv_uuid, sizeof(char)*37);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_OP, (const char *)&packet, MAVLINK_MSG_ID_CP_INSTANCE_OP_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN, MAVLINK_MSG_ID_CP_INSTANCE_OP_CRC);
#endif
}

/**
 * @brief Send a cp_instance_op message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cp_instance_op_send_struct(mavlink_channel_t chan, const mavlink_cp_instance_op_t* cp_instance_op)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cp_instance_op_send(chan, cp_instance_op->uuid, cp_instance_op->pass_uuid, cp_instance_op->prv_uuid, cp_instance_op->op, cp_instance_op->timestamp);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_OP, (const char *)cp_instance_op, MAVLINK_MSG_ID_CP_INSTANCE_OP_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN, MAVLINK_MSG_ID_CP_INSTANCE_OP_CRC);
#endif
}

#if MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cp_instance_op_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *uuid, const char *pass_uuid, const char *prv_uuid, uint8_t op, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 119, op);
    _mav_put_char_array(buf, 8, uuid, 37);
    _mav_put_char_array(buf, 45, pass_uuid, 37);
    _mav_put_char_array(buf, 82, prv_uuid, 37);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_OP, buf, MAVLINK_MSG_ID_CP_INSTANCE_OP_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN, MAVLINK_MSG_ID_CP_INSTANCE_OP_CRC);
#else
    mavlink_cp_instance_op_t *packet = (mavlink_cp_instance_op_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->op = op;
    mav_array_memcpy(packet->uuid, uuid, sizeof(char)*37);
    mav_array_memcpy(packet->pass_uuid, pass_uuid, sizeof(char)*37);
    mav_array_memcpy(packet->prv_uuid, prv_uuid, sizeof(char)*37);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CP_INSTANCE_OP, (const char *)packet, MAVLINK_MSG_ID_CP_INSTANCE_OP_MIN_LEN, MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN, MAVLINK_MSG_ID_CP_INSTANCE_OP_CRC);
#endif
}
#endif

#endif

// MESSAGE CP_INSTANCE_OP UNPACKING


/**
 * @brief Get field uuid from cp_instance_op message
 *
 * @return  my uuid
 */
static inline uint16_t mavlink_msg_cp_instance_op_get_uuid(const mavlink_message_t* msg, char *uuid)
{
    return _MAV_RETURN_char_array(msg, uuid, 37,  8);
}

/**
 * @brief Get field pass_uuid from cp_instance_op message
 *
 * @return  pass uuid
 */
static inline uint16_t mavlink_msg_cp_instance_op_get_pass_uuid(const mavlink_message_t* msg, char *pass_uuid)
{
    return _MAV_RETURN_char_array(msg, pass_uuid, 37,  45);
}

/**
 * @brief Get field prv_uuid from cp_instance_op message
 *
 * @return  previous uuid
 */
static inline uint16_t mavlink_msg_cp_instance_op_get_prv_uuid(const mavlink_message_t* msg, char *prv_uuid)
{
    return _MAV_RETURN_char_array(msg, prv_uuid, 37,  82);
}

/**
 * @brief Get field op from cp_instance_op message
 *
 * @return  Operation Type
 */
static inline uint8_t mavlink_msg_cp_instance_op_get_op(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  119);
}

/**
 * @brief Get field timestamp from cp_instance_op message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_cp_instance_op_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Decode a cp_instance_op message into a struct
 *
 * @param msg The message to decode
 * @param cp_instance_op C-struct to decode the message contents into
 */
static inline void mavlink_msg_cp_instance_op_decode(const mavlink_message_t* msg, mavlink_cp_instance_op_t* cp_instance_op)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cp_instance_op->timestamp = mavlink_msg_cp_instance_op_get_timestamp(msg);
    mavlink_msg_cp_instance_op_get_uuid(msg, cp_instance_op->uuid);
    mavlink_msg_cp_instance_op_get_pass_uuid(msg, cp_instance_op->pass_uuid);
    mavlink_msg_cp_instance_op_get_prv_uuid(msg, cp_instance_op->prv_uuid);
    cp_instance_op->op = mavlink_msg_cp_instance_op_get_op(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN? msg->len : MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN;
        memset(cp_instance_op, 0, MAVLINK_MSG_ID_CP_INSTANCE_OP_LEN);
    memcpy(cp_instance_op, _MAV_PAYLOAD(msg), len);
#endif
}
