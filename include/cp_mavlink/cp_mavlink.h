/** @file
 *  @brief MAVLink comm protocol generated from cp_mavlink.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_CP_MAVLINK_H
#define MAVLINK_CP_MAVLINK_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_CP_MAVLINK.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{0, 225, 156, 156, 0, 0, 0}, {1, 13, 120, 120, 0, 0, 0}, {2, 76, 84, 84, 0, 0, 0}, {3, 48, 193, 193, 0, 0, 0}, {4, 101, 170, 170, 0, 0, 0}, {5, 123, 84, 84, 0, 0, 0}, {6, 47, 92, 92, 0, 0, 0}, {7, 93, 85, 85, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_CP_MAVLINK

// ENUM DEFINITIONS


/** @brief CoPlayer Operation ACK. */
#ifndef HAVE_ENUM_CP_OP_ACK_TYPE
#define HAVE_ENUM_CP_OP_ACK_TYPE
typedef enum CP_OP_ACK_TYPE
{
   CP_OP_ACK_TYPE_FAIL=0, /* fail | */
   CP_OP_ACK_TYPE_SUCCESS=1, /* success | */
   CP_OP_ACK_TYPE_ENUM_END=2, /*  | */
} CP_OP_ACK_TYPE;
#endif

/** @brief CoPlayer Instance Operation. */
#ifndef HAVE_ENUM_CP_INSTANCE_CMD_STAGE
#define HAVE_ENUM_CP_INSTANCE_CMD_STAGE
typedef enum CP_INSTANCE_CMD_STAGE
{
   CP_INSTANCE_CMD_STAGE_0=0, /* Close CoPlayer Instance. | */
   CP_INSTANCE_CMD_STAGE_1=1, /* Open CoPlayer Instance. | */
   CP_INSTANCE_CMD_STAGE_2=2, /* Query CoPlayer Instance Status. | */
   CP_INSTANCE_CMD_STAGE_3=3, /* Pair CoPlayer Instance. | */
   CP_INSTANCE_CMD_STAGE_ENUM_END=4, /*  | */
} CP_INSTANCE_CMD_STAGE;
#endif

/** @brief CoPlayer Instance Operation. */
#ifndef HAVE_ENUM_CP_INSTANCE_OP_TYPE
#define HAVE_ENUM_CP_INSTANCE_OP_TYPE
typedef enum CP_INSTANCE_OP_TYPE
{
   CP_INSTANCE_OP_TYPE_CLOSE=0, /* Close CoPlayer Instance. | */
   CP_INSTANCE_OP_TYPE_OPEN=1, /* Open CoPlayer Instance. | */
   CP_INSTANCE_OP_TYPE_QUERY=2, /* Query CoPlayer Instance Status. | */
   CP_INSTANCE_OP_TYPE_ENUM_END=3, /*  | */
} CP_INSTANCE_OP_TYPE;
#endif

/** @brief CoPlayer Video Operation. */
#ifndef HAVE_ENUM_CP_VIDEO_OP_TYPE
#define HAVE_ENUM_CP_VIDEO_OP_TYPE
typedef enum CP_VIDEO_OP_TYPE
{
   CP_VIDEO_OP_TYPE_PAUSE=0, /* Pause Video Instance. | */
   CP_VIDEO_OP_TYPE_PLAY=1, /* Play Video Instance. | */
   CP_VIDEO_OP_TYPE_ENUM_END=2, /*  | */
} CP_VIDEO_OP_TYPE;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_heartbeat.h"
#include "./mavlink_msg_cp_instance_op.h"
#include "./mavlink_msg_cp_instance_op_ack.h"
#include "./mavlink_msg_cp_instance_status.h"
#include "./mavlink_msg_cp_instance_pair.h"
#include "./mavlink_msg_cp_instance_pair_ack.h"
#include "./mavlink_msg_cp_video_op.h"
#include "./mavlink_msg_cp_video_op_ack.h"

// base include


#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_HEARTBEAT, MAVLINK_MESSAGE_INFO_CP_INSTANCE_OP, MAVLINK_MESSAGE_INFO_CP_INSTANCE_OP_ACK, MAVLINK_MESSAGE_INFO_CP_INSTANCE_STATUS, MAVLINK_MESSAGE_INFO_CP_INSTANCE_PAIR, MAVLINK_MESSAGE_INFO_CP_INSTANCE_PAIR_ACK, MAVLINK_MESSAGE_INFO_CP_VIDEO_OP, MAVLINK_MESSAGE_INFO_CP_VIDEO_OP_ACK}
# define MAVLINK_MESSAGE_NAMES {{ "CP_INSTANCE_OP", 1 }, { "CP_INSTANCE_OP_ACK", 2 }, { "CP_INSTANCE_PAIR", 4 }, { "CP_INSTANCE_PAIR_ACK", 5 }, { "CP_INSTANCE_STATUS", 3 }, { "CP_VIDEO_OP", 6 }, { "CP_VIDEO_OP_ACK", 7 }, { "HEARTBEAT", 0 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_CP_MAVLINK_H
