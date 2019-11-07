#pragma once
// MESSAGE MOCAP_POSE PACKING

#define MAVLINK_MSG_ID_MOCAP_POSE 222

MAVPACKED(
typedef struct __mavlink_mocap_pose_t {
 uint64_t time_usec; /*< Timestamp (micros since boot or Unix epoch)*/
 int16_t pose[4]; /*< Robot pose (x, y, z, heading) in m/10^3 or rad/10^4*/
}) mavlink_mocap_pose_t;

#define MAVLINK_MSG_ID_MOCAP_POSE_LEN 16
#define MAVLINK_MSG_ID_MOCAP_POSE_MIN_LEN 16
#define MAVLINK_MSG_ID_222_LEN 16
#define MAVLINK_MSG_ID_222_MIN_LEN 16

#define MAVLINK_MSG_ID_MOCAP_POSE_CRC 228
#define MAVLINK_MSG_ID_222_CRC 228

#define MAVLINK_MSG_MOCAP_POSE_FIELD_POSE_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MOCAP_POSE { \
    222, \
    "MOCAP_POSE", \
    2, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_mocap_pose_t, time_usec) }, \
         { "pose", NULL, MAVLINK_TYPE_INT16_T, 4, 8, offsetof(mavlink_mocap_pose_t, pose) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MOCAP_POSE { \
    "MOCAP_POSE", \
    2, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_mocap_pose_t, time_usec) }, \
         { "pose", NULL, MAVLINK_TYPE_INT16_T, 4, 8, offsetof(mavlink_mocap_pose_t, pose) }, \
         } \
}
#endif

/**
 * @brief Pack a mocap_pose message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param pose Robot pose (x, y, z, heading) in m/10^3 or rad/10^4
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mocap_pose_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const int16_t *pose)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOCAP_POSE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int16_t_array(buf, 8, pose, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOCAP_POSE_LEN);
#else
    mavlink_mocap_pose_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.pose, pose, sizeof(int16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOCAP_POSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOCAP_POSE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOCAP_POSE_MIN_LEN, MAVLINK_MSG_ID_MOCAP_POSE_LEN, MAVLINK_MSG_ID_MOCAP_POSE_CRC);
}

/**
 * @brief Pack a mocap_pose message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param pose Robot pose (x, y, z, heading) in m/10^3 or rad/10^4
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mocap_pose_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const int16_t *pose)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOCAP_POSE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int16_t_array(buf, 8, pose, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOCAP_POSE_LEN);
#else
    mavlink_mocap_pose_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.pose, pose, sizeof(int16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOCAP_POSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOCAP_POSE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOCAP_POSE_MIN_LEN, MAVLINK_MSG_ID_MOCAP_POSE_LEN, MAVLINK_MSG_ID_MOCAP_POSE_CRC);
}

/**
 * @brief Encode a mocap_pose struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mocap_pose C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mocap_pose_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mocap_pose_t* mocap_pose)
{
    return mavlink_msg_mocap_pose_pack(system_id, component_id, msg, mocap_pose->time_usec, mocap_pose->pose);
}

/**
 * @brief Encode a mocap_pose struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mocap_pose C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mocap_pose_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mocap_pose_t* mocap_pose)
{
    return mavlink_msg_mocap_pose_pack_chan(system_id, component_id, chan, msg, mocap_pose->time_usec, mocap_pose->pose);
}

/**
 * @brief Send a mocap_pose message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param pose Robot pose (x, y, z, heading) in m/10^3 or rad/10^4
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mocap_pose_send(mavlink_channel_t chan, uint64_t time_usec, const int16_t *pose)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOCAP_POSE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int16_t_array(buf, 8, pose, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_POSE, buf, MAVLINK_MSG_ID_MOCAP_POSE_MIN_LEN, MAVLINK_MSG_ID_MOCAP_POSE_LEN, MAVLINK_MSG_ID_MOCAP_POSE_CRC);
#else
    mavlink_mocap_pose_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.pose, pose, sizeof(int16_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_POSE, (const char *)&packet, MAVLINK_MSG_ID_MOCAP_POSE_MIN_LEN, MAVLINK_MSG_ID_MOCAP_POSE_LEN, MAVLINK_MSG_ID_MOCAP_POSE_CRC);
#endif
}

/**
 * @brief Send a mocap_pose message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mocap_pose_send_struct(mavlink_channel_t chan, const mavlink_mocap_pose_t* mocap_pose)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mocap_pose_send(chan, mocap_pose->time_usec, mocap_pose->pose);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_POSE, (const char *)mocap_pose, MAVLINK_MSG_ID_MOCAP_POSE_MIN_LEN, MAVLINK_MSG_ID_MOCAP_POSE_LEN, MAVLINK_MSG_ID_MOCAP_POSE_CRC);
#endif
}

#if MAVLINK_MSG_ID_MOCAP_POSE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mocap_pose_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const int16_t *pose)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int16_t_array(buf, 8, pose, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_POSE, buf, MAVLINK_MSG_ID_MOCAP_POSE_MIN_LEN, MAVLINK_MSG_ID_MOCAP_POSE_LEN, MAVLINK_MSG_ID_MOCAP_POSE_CRC);
#else
    mavlink_mocap_pose_t *packet = (mavlink_mocap_pose_t *)msgbuf;
    packet->time_usec = time_usec;
    mav_array_memcpy(packet->pose, pose, sizeof(int16_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_POSE, (const char *)packet, MAVLINK_MSG_ID_MOCAP_POSE_MIN_LEN, MAVLINK_MSG_ID_MOCAP_POSE_LEN, MAVLINK_MSG_ID_MOCAP_POSE_CRC);
#endif
}
#endif

#endif

// MESSAGE MOCAP_POSE UNPACKING


/**
 * @brief Get field time_usec from mocap_pose message
 *
 * @return Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_mocap_pose_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field pose from mocap_pose message
 *
 * @return Robot pose (x, y, z, heading) in m/10^3 or rad/10^4
 */
static inline uint16_t mavlink_msg_mocap_pose_get_pose(const mavlink_message_t* msg, int16_t *pose)
{
    return _MAV_RETURN_int16_t_array(msg, pose, 4,  8);
}

/**
 * @brief Decode a mocap_pose message into a struct
 *
 * @param msg The message to decode
 * @param mocap_pose C-struct to decode the message contents into
 */
static inline void mavlink_msg_mocap_pose_decode(const mavlink_message_t* msg, mavlink_mocap_pose_t* mocap_pose)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mocap_pose->time_usec = mavlink_msg_mocap_pose_get_time_usec(msg);
    mavlink_msg_mocap_pose_get_pose(msg, mocap_pose->pose);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MOCAP_POSE_LEN? msg->len : MAVLINK_MSG_ID_MOCAP_POSE_LEN;
        memset(mocap_pose, 0, MAVLINK_MSG_ID_MOCAP_POSE_LEN);
    memcpy(mocap_pose, _MAV_PAYLOAD(msg), len);
#endif
}
