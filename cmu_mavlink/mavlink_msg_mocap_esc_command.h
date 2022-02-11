#pragma once
// MESSAGE MOCAP_ESC_COMMAND PACKING

#define MAVLINK_MSG_ID_MOCAP_ESC_COMMAND 436


typedef struct __mavlink_mocap_esc_command_t {
 uint64_t time_usec; /*<  Timestamp (micros since boot or Unix epoch)*/
 uint16_t cmds[8]; /*<  CMD*/
} mavlink_mocap_esc_command_t;

#define MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN 24
#define MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_MIN_LEN 24
#define MAVLINK_MSG_ID_436_LEN 24
#define MAVLINK_MSG_ID_436_MIN_LEN 24

#define MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_CRC 169
#define MAVLINK_MSG_ID_436_CRC 169

#define MAVLINK_MSG_MOCAP_ESC_COMMAND_FIELD_CMDS_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MOCAP_ESC_COMMAND { \
    436, \
    "MOCAP_ESC_COMMAND", \
    2, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_mocap_esc_command_t, time_usec) }, \
         { "cmds", NULL, MAVLINK_TYPE_UINT16_T, 8, 8, offsetof(mavlink_mocap_esc_command_t, cmds) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MOCAP_ESC_COMMAND { \
    "MOCAP_ESC_COMMAND", \
    2, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_mocap_esc_command_t, time_usec) }, \
         { "cmds", NULL, MAVLINK_TYPE_UINT16_T, 8, 8, offsetof(mavlink_mocap_esc_command_t, cmds) }, \
         } \
}
#endif

/**
 * @brief Pack a mocap_esc_command message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param cmds  CMD
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mocap_esc_command_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const uint16_t *cmds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t_array(buf, 8, cmds, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN);
#else
    mavlink_mocap_esc_command_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.cmds, cmds, sizeof(uint16_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOCAP_ESC_COMMAND;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_CRC);
}

/**
 * @brief Pack a mocap_esc_command message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param cmds  CMD
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mocap_esc_command_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const uint16_t *cmds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t_array(buf, 8, cmds, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN);
#else
    mavlink_mocap_esc_command_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.cmds, cmds, sizeof(uint16_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOCAP_ESC_COMMAND;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_CRC);
}

/**
 * @brief Encode a mocap_esc_command struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mocap_esc_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mocap_esc_command_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mocap_esc_command_t* mocap_esc_command)
{
    return mavlink_msg_mocap_esc_command_pack(system_id, component_id, msg, mocap_esc_command->time_usec, mocap_esc_command->cmds);
}

/**
 * @brief Encode a mocap_esc_command struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mocap_esc_command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mocap_esc_command_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mocap_esc_command_t* mocap_esc_command)
{
    return mavlink_msg_mocap_esc_command_pack_chan(system_id, component_id, chan, msg, mocap_esc_command->time_usec, mocap_esc_command->cmds);
}

/**
 * @brief Send a mocap_esc_command message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param cmds  CMD
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mocap_esc_command_send(mavlink_channel_t chan, uint64_t time_usec, const uint16_t *cmds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t_array(buf, 8, cmds, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND, buf, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_CRC);
#else
    mavlink_mocap_esc_command_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.cmds, cmds, sizeof(uint16_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND, (const char *)&packet, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_CRC);
#endif
}

/**
 * @brief Send a mocap_esc_command message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mocap_esc_command_send_struct(mavlink_channel_t chan, const mavlink_mocap_esc_command_t* mocap_esc_command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mocap_esc_command_send(chan, mocap_esc_command->time_usec, mocap_esc_command->cmds);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND, (const char *)mocap_esc_command, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_CRC);
#endif
}

#if MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mocap_esc_command_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const uint16_t *cmds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t_array(buf, 8, cmds, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND, buf, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_CRC);
#else
    mavlink_mocap_esc_command_t *packet = (mavlink_mocap_esc_command_t *)msgbuf;
    packet->time_usec = time_usec;
    mav_array_memcpy(packet->cmds, cmds, sizeof(uint16_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND, (const char *)packet, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_MIN_LEN, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_CRC);
#endif
}
#endif

#endif

// MESSAGE MOCAP_ESC_COMMAND UNPACKING


/**
 * @brief Get field time_usec from mocap_esc_command message
 *
 * @return  Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_mocap_esc_command_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field cmds from mocap_esc_command message
 *
 * @return  CMD
 */
static inline uint16_t mavlink_msg_mocap_esc_command_get_cmds(const mavlink_message_t* msg, uint16_t *cmds)
{
    return _MAV_RETURN_uint16_t_array(msg, cmds, 8,  8);
}

/**
 * @brief Decode a mocap_esc_command message into a struct
 *
 * @param msg The message to decode
 * @param mocap_esc_command C-struct to decode the message contents into
 */
static inline void mavlink_msg_mocap_esc_command_decode(const mavlink_message_t* msg, mavlink_mocap_esc_command_t* mocap_esc_command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mocap_esc_command->time_usec = mavlink_msg_mocap_esc_command_get_time_usec(msg);
    mavlink_msg_mocap_esc_command_get_cmds(msg, mocap_esc_command->cmds);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN? msg->len : MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN;
        memset(mocap_esc_command, 0, MAVLINK_MSG_ID_MOCAP_ESC_COMMAND_LEN);
    memcpy(mocap_esc_command, _MAV_PAYLOAD(msg), len);
#endif
}
