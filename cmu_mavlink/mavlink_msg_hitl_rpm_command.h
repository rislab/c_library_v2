#pragma once
// MESSAGE HITL_RPM_COMMAND PACKING

#define MAVLINK_MSG_ID_HITL_RPM_COMMAND 440


typedef struct __mavlink_hitl_rpm_command_t {
 uint64_t timestamp; /*<  Timestamp (micros since boot or Unix epoch)*/
 uint16_t rpm[4]; /*<  Commanded RPM values*/
} mavlink_hitl_rpm_command_t;

#define MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN 16
#define MAVLINK_MSG_ID_HITL_RPM_COMMAND_MIN_LEN 16
#define MAVLINK_MSG_ID_440_LEN 16
#define MAVLINK_MSG_ID_440_MIN_LEN 16

#define MAVLINK_MSG_ID_HITL_RPM_COMMAND_CRC 196
#define MAVLINK_MSG_ID_440_CRC 196

#define MAVLINK_MSG_HITL_RPM_COMMAND_FIELD_RPM_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_HITL_RPM_COMMAND { \
    440, \
    "HITL_RPM_COMMAND", \
    2, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_hitl_rpm_command_t, timestamp) }, \
         { "rpm", NULL, MAVLINK_TYPE_UINT16_T, 4, 8, offsetof(mavlink_hitl_rpm_command_t, rpm) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_HITL_RPM_COMMAND { \
    "HITL_RPM_COMMAND", \
    2, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_hitl_rpm_command_t, timestamp) }, \
         { "rpm", NULL, MAVLINK_TYPE_UINT16_T, 4, 8, offsetof(mavlink_hitl_rpm_command_t, rpm) }, \
         } \
}
#endif

/**
 * @brief Pack a hitl_rpm_command message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  Timestamp (micros since boot or Unix epoch)
 * @param rpm  Commanded RPM values
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hitl_rpm_command_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, const uint16_t *rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint16_t_array(buf, 8, rpm, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN);
#else
    mavlink_hitl_rpm_command_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.rpm, rpm, sizeof(uint16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HITL_RPM_COMMAND;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_HITL_RPM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN, MAVLINK_MSG_ID_HITL_RPM_COMMAND_CRC);
}

/**
 * @brief Pack a hitl_rpm_command message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  Timestamp (micros since boot or Unix epoch)
 * @param rpm  Commanded RPM values
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_hitl_rpm_command_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,const uint16_t *rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint16_t_array(buf, 8, rpm, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN);
#else
    mavlink_hitl_rpm_command_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.rpm, rpm, sizeof(uint16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_HITL_RPM_COMMAND;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_HITL_RPM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN, MAVLINK_MSG_ID_HITL_RPM_COMMAND_CRC);
}

/**
 * @brief Encode a hitl_rpm_command struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param hitl_rpm_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hitl_rpm_command_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_hitl_rpm_command_t* hitl_rpm_command)
{
    return mavlink_msg_hitl_rpm_command_pack(system_id, component_id, msg, hitl_rpm_command->timestamp, hitl_rpm_command->rpm);
}

/**
 * @brief Encode a hitl_rpm_command struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param hitl_rpm_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_hitl_rpm_command_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_hitl_rpm_command_t* hitl_rpm_command)
{
    return mavlink_msg_hitl_rpm_command_pack_chan(system_id, component_id, chan, msg, hitl_rpm_command->timestamp, hitl_rpm_command->rpm);
}

/**
 * @brief Send a hitl_rpm_command message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  Timestamp (micros since boot or Unix epoch)
 * @param rpm  Commanded RPM values
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_hitl_rpm_command_send(mavlink_channel_t chan, uint64_t timestamp, const uint16_t *rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint16_t_array(buf, 8, rpm, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HITL_RPM_COMMAND, buf, MAVLINK_MSG_ID_HITL_RPM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN, MAVLINK_MSG_ID_HITL_RPM_COMMAND_CRC);
#else
    mavlink_hitl_rpm_command_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.rpm, rpm, sizeof(uint16_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HITL_RPM_COMMAND, (const char *)&packet, MAVLINK_MSG_ID_HITL_RPM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN, MAVLINK_MSG_ID_HITL_RPM_COMMAND_CRC);
#endif
}

/**
 * @brief Send a hitl_rpm_command message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_hitl_rpm_command_send_struct(mavlink_channel_t chan, const mavlink_hitl_rpm_command_t* hitl_rpm_command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_hitl_rpm_command_send(chan, hitl_rpm_command->timestamp, hitl_rpm_command->rpm);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HITL_RPM_COMMAND, (const char *)hitl_rpm_command, MAVLINK_MSG_ID_HITL_RPM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN, MAVLINK_MSG_ID_HITL_RPM_COMMAND_CRC);
#endif
}

#if MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_hitl_rpm_command_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, const uint16_t *rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint16_t_array(buf, 8, rpm, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HITL_RPM_COMMAND, buf, MAVLINK_MSG_ID_HITL_RPM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN, MAVLINK_MSG_ID_HITL_RPM_COMMAND_CRC);
#else
    mavlink_hitl_rpm_command_t *packet = (mavlink_hitl_rpm_command_t *)msgbuf;
    packet->timestamp = timestamp;
    mav_array_memcpy(packet->rpm, rpm, sizeof(uint16_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_HITL_RPM_COMMAND, (const char *)packet, MAVLINK_MSG_ID_HITL_RPM_COMMAND_MIN_LEN, MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN, MAVLINK_MSG_ID_HITL_RPM_COMMAND_CRC);
#endif
}
#endif

#endif

// MESSAGE HITL_RPM_COMMAND UNPACKING


/**
 * @brief Get field timestamp from hitl_rpm_command message
 *
 * @return  Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_hitl_rpm_command_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field rpm from hitl_rpm_command message
 *
 * @return  Commanded RPM values
 */
static inline uint16_t mavlink_msg_hitl_rpm_command_get_rpm(const mavlink_message_t* msg, uint16_t *rpm)
{
    return _MAV_RETURN_uint16_t_array(msg, rpm, 4,  8);
}

/**
 * @brief Decode a hitl_rpm_command message into a struct
 *
 * @param msg The message to decode
 * @param hitl_rpm_command C-struct to decode the message contents into
 */
static inline void mavlink_msg_hitl_rpm_command_decode(const mavlink_message_t* msg, mavlink_hitl_rpm_command_t* hitl_rpm_command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    hitl_rpm_command->timestamp = mavlink_msg_hitl_rpm_command_get_timestamp(msg);
    mavlink_msg_hitl_rpm_command_get_rpm(msg, hitl_rpm_command->rpm);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN? msg->len : MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN;
        memset(hitl_rpm_command, 0, MAVLINK_MSG_ID_HITL_RPM_COMMAND_LEN);
    memcpy(hitl_rpm_command, _MAV_PAYLOAD(msg), len);
#endif
}
