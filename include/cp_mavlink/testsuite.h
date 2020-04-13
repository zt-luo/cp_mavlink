/** @file
 *    @brief MAVLink comm protocol testsuite generated from cp_mavlink.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef CP_MAVLINK_TESTSUITE_H
#define CP_MAVLINK_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_cp_mavlink(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_cp_mavlink(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_heartbeat(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_HEARTBEAT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_heartbeat_t packet_in = {
        93372036854775807ULL,"IJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQR","TUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABC","EFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMN","PQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXY"
    };
    mavlink_heartbeat_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        
        mav_array_memcpy(packet1.uuid, packet_in.uuid, sizeof(char)*37);
        mav_array_memcpy(packet1.pass_uuid, packet_in.pass_uuid, sizeof(char)*37);
        mav_array_memcpy(packet1.to_uuid, packet_in.to_uuid, sizeof(char)*37);
        mav_array_memcpy(packet1.pair_uuid, packet_in.pair_uuid, sizeof(char)*37);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_HEARTBEAT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_pack(system_id, component_id, &msg , packet1.uuid , packet1.pass_uuid , packet1.to_uuid , packet1.pair_uuid , packet1.timestamp );
    mavlink_msg_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uuid , packet1.pass_uuid , packet1.to_uuid , packet1.pair_uuid , packet1.timestamp );
    mavlink_msg_heartbeat_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_heartbeat_send(MAVLINK_COMM_1 , packet1.uuid , packet1.pass_uuid , packet1.to_uuid , packet1.pair_uuid , packet1.timestamp );
    mavlink_msg_heartbeat_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cp_instance_op(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CP_INSTANCE_OP >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cp_instance_op_t packet_in = {
        93372036854775807ULL,"IJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQR","TUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABC","EFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMN",42
    };
    mavlink_cp_instance_op_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.op = packet_in.op;
        
        mav_array_memcpy(packet1.uuid, packet_in.uuid, sizeof(char)*37);
        mav_array_memcpy(packet1.pass_uuid, packet_in.pass_uuid, sizeof(char)*37);
        mav_array_memcpy(packet1.prv_uuid, packet_in.prv_uuid, sizeof(char)*37);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CP_INSTANCE_OP_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CP_INSTANCE_OP_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_op_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cp_instance_op_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_op_pack(system_id, component_id, &msg , packet1.uuid , packet1.pass_uuid , packet1.prv_uuid , packet1.op , packet1.timestamp );
    mavlink_msg_cp_instance_op_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_op_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uuid , packet1.pass_uuid , packet1.prv_uuid , packet1.op , packet1.timestamp );
    mavlink_msg_cp_instance_op_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cp_instance_op_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_op_send(MAVLINK_COMM_1 , packet1.uuid , packet1.pass_uuid , packet1.prv_uuid , packet1.op , packet1.timestamp );
    mavlink_msg_cp_instance_op_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cp_instance_op_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CP_INSTANCE_OP_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cp_instance_op_ack_t packet_in = {
        93372036854775807ULL,"IJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQR","TUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABC",123,190
    };
    mavlink_cp_instance_op_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.op = packet_in.op;
        packet1.ack = packet_in.ack;
        
        mav_array_memcpy(packet1.uuid, packet_in.uuid, sizeof(char)*37);
        mav_array_memcpy(packet1.to_uuid, packet_in.to_uuid, sizeof(char)*37);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CP_INSTANCE_OP_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CP_INSTANCE_OP_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_op_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cp_instance_op_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_op_ack_pack(system_id, component_id, &msg , packet1.uuid , packet1.to_uuid , packet1.op , packet1.ack , packet1.timestamp );
    mavlink_msg_cp_instance_op_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_op_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uuid , packet1.to_uuid , packet1.op , packet1.ack , packet1.timestamp );
    mavlink_msg_cp_instance_op_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cp_instance_op_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_op_ack_send(MAVLINK_COMM_1 , packet1.uuid , packet1.to_uuid , packet1.op , packet1.ack , packet1.timestamp );
    mavlink_msg_cp_instance_op_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cp_instance_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CP_INSTANCE_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cp_instance_status_t packet_in = {
        93372036854775807ULL,93372036854776311ULL,93372036854776815ULL,93372036854777319ULL,"GHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOP","RSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZA","CDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKL","NOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJ"
    };
    mavlink_cp_instance_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.video_duration = packet_in.video_duration;
        packet1.video_size = packet_in.video_size;
        packet1.video_time = packet_in.video_time;
        packet1.timestamp = packet_in.timestamp;
        
        mav_array_memcpy(packet1.uuid, packet_in.uuid, sizeof(char)*37);
        mav_array_memcpy(packet1.to_uuid, packet_in.to_uuid, sizeof(char)*37);
        mav_array_memcpy(packet1.pair_uuid, packet_in.pair_uuid, sizeof(char)*37);
        mav_array_memcpy(packet1.pair_name, packet_in.pair_name, sizeof(char)*50);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CP_INSTANCE_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CP_INSTANCE_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cp_instance_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_status_pack(system_id, component_id, &msg , packet1.uuid , packet1.to_uuid , packet1.pair_uuid , packet1.pair_name , packet1.video_duration , packet1.video_size , packet1.video_time , packet1.timestamp );
    mavlink_msg_cp_instance_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uuid , packet1.to_uuid , packet1.pair_uuid , packet1.pair_name , packet1.video_duration , packet1.video_size , packet1.video_time , packet1.timestamp );
    mavlink_msg_cp_instance_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cp_instance_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_status_send(MAVLINK_COMM_1 , packet1.uuid , packet1.to_uuid , packet1.pair_uuid , packet1.pair_name , packet1.video_duration , packet1.video_size , packet1.video_time , packet1.timestamp );
    mavlink_msg_cp_instance_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cp_instance_pair(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CP_INSTANCE_PAIR >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cp_instance_pair_t packet_in = {
        93372036854775807ULL,"IJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQR","TUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABC","EFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMN","PQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKL",64
    };
    mavlink_cp_instance_pair_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.pair_stage = packet_in.pair_stage;
        
        mav_array_memcpy(packet1.uuid, packet_in.uuid, sizeof(char)*37);
        mav_array_memcpy(packet1.pass_uuid, packet_in.pass_uuid, sizeof(char)*37);
        mav_array_memcpy(packet1.pair_uuid, packet_in.pair_uuid, sizeof(char)*37);
        mav_array_memcpy(packet1.pair_name, packet_in.pair_name, sizeof(char)*50);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CP_INSTANCE_PAIR_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CP_INSTANCE_PAIR_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_pair_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cp_instance_pair_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_pair_pack(system_id, component_id, &msg , packet1.uuid , packet1.pass_uuid , packet1.pair_uuid , packet1.pair_name , packet1.pair_stage , packet1.timestamp );
    mavlink_msg_cp_instance_pair_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_pair_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uuid , packet1.pass_uuid , packet1.pair_uuid , packet1.pair_name , packet1.pair_stage , packet1.timestamp );
    mavlink_msg_cp_instance_pair_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cp_instance_pair_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_pair_send(MAVLINK_COMM_1 , packet1.uuid , packet1.pass_uuid , packet1.pair_uuid , packet1.pair_name , packet1.pair_stage , packet1.timestamp );
    mavlink_msg_cp_instance_pair_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cp_instance_pair_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cp_instance_pair_ack_t packet_in = {
        93372036854775807ULL,"IJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQR","TUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABC",123,190
    };
    mavlink_cp_instance_pair_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.pair_stage = packet_in.pair_stage;
        packet1.ack = packet_in.ack;
        
        mav_array_memcpy(packet1.uuid, packet_in.uuid, sizeof(char)*37);
        mav_array_memcpy(packet1.to_uuid, packet_in.to_uuid, sizeof(char)*37);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CP_INSTANCE_PAIR_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_pair_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cp_instance_pair_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_pair_ack_pack(system_id, component_id, &msg , packet1.uuid , packet1.to_uuid , packet1.pair_stage , packet1.ack , packet1.timestamp );
    mavlink_msg_cp_instance_pair_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_pair_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uuid , packet1.to_uuid , packet1.pair_stage , packet1.ack , packet1.timestamp );
    mavlink_msg_cp_instance_pair_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cp_instance_pair_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_instance_pair_ack_send(MAVLINK_COMM_1 , packet1.uuid , packet1.to_uuid , packet1.pair_stage , packet1.ack , packet1.timestamp );
    mavlink_msg_cp_instance_pair_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cp_video_op(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CP_VIDEO_OP >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cp_video_op_t packet_in = {
        93372036854775807ULL,93372036854776311ULL,"QRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ","BCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJK",147,214
    };
    mavlink_cp_video_op_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.video_time = packet_in.video_time;
        packet1.timestamp = packet_in.timestamp;
        packet1.op = packet_in.op;
        packet1.op_stage = packet_in.op_stage;
        
        mav_array_memcpy(packet1.uuid, packet_in.uuid, sizeof(char)*37);
        mav_array_memcpy(packet1.pass_uuid, packet_in.pass_uuid, sizeof(char)*37);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CP_VIDEO_OP_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CP_VIDEO_OP_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_video_op_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cp_video_op_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_video_op_pack(system_id, component_id, &msg , packet1.uuid , packet1.pass_uuid , packet1.op , packet1.op_stage , packet1.video_time , packet1.timestamp );
    mavlink_msg_cp_video_op_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_video_op_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uuid , packet1.pass_uuid , packet1.op , packet1.op_stage , packet1.video_time , packet1.timestamp );
    mavlink_msg_cp_video_op_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cp_video_op_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_video_op_send(MAVLINK_COMM_1 , packet1.uuid , packet1.pass_uuid , packet1.op , packet1.op_stage , packet1.video_time , packet1.timestamp );
    mavlink_msg_cp_video_op_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cp_video_op_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CP_VIDEO_OP_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cp_video_op_ack_t packet_in = {
        93372036854775807ULL,"IJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQR","TUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABC",123,190,1
    };
    mavlink_cp_video_op_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp = packet_in.timestamp;
        packet1.op = packet_in.op;
        packet1.op_stage = packet_in.op_stage;
        packet1.ack = packet_in.ack;
        
        mav_array_memcpy(packet1.uuid, packet_in.uuid, sizeof(char)*37);
        mav_array_memcpy(packet1.to_uuid, packet_in.to_uuid, sizeof(char)*37);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CP_VIDEO_OP_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CP_VIDEO_OP_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_video_op_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cp_video_op_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_video_op_ack_pack(system_id, component_id, &msg , packet1.uuid , packet1.to_uuid , packet1.op , packet1.op_stage , packet1.ack , packet1.timestamp );
    mavlink_msg_cp_video_op_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_video_op_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uuid , packet1.to_uuid , packet1.op , packet1.op_stage , packet1.ack , packet1.timestamp );
    mavlink_msg_cp_video_op_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cp_video_op_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cp_video_op_ack_send(MAVLINK_COMM_1 , packet1.uuid , packet1.to_uuid , packet1.op , packet1.op_stage , packet1.ack , packet1.timestamp );
    mavlink_msg_cp_video_op_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cp_mavlink(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_heartbeat(system_id, component_id, last_msg);
    mavlink_test_cp_instance_op(system_id, component_id, last_msg);
    mavlink_test_cp_instance_op_ack(system_id, component_id, last_msg);
    mavlink_test_cp_instance_status(system_id, component_id, last_msg);
    mavlink_test_cp_instance_pair(system_id, component_id, last_msg);
    mavlink_test_cp_instance_pair_ack(system_id, component_id, last_msg);
    mavlink_test_cp_video_op(system_id, component_id, last_msg);
    mavlink_test_cp_video_op_ack(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // CP_MAVLINK_TESTSUITE_H
