#pragma once
// MESSAGE ATT_CTRL_DEBUG PACKING

#define MAVLINK_MSG_ID_ATT_CTRL_DEBUG 223

MAVPACKED(
typedef struct __mavlink_att_ctrl_debug_t {
 uint64_t time_usec; /*< Timestamp (micros since boot or Unix epoch)*/
 float rpm[6]; /*< RPM values calculated from MocapAttitudeController for quadrotor*/
 float eOm[3]; /*< Angular velocity error*/
}) mavlink_att_ctrl_debug_t;

#define MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN 44
#define MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN 44
#define MAVLINK_MSG_ID_223_LEN 44
#define MAVLINK_MSG_ID_223_MIN_LEN 44

#define MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC 184
#define MAVLINK_MSG_ID_223_CRC 184

#define MAVLINK_MSG_ATT_CTRL_DEBUG_FIELD_RPM_LEN 6
#define MAVLINK_MSG_ATT_CTRL_DEBUG_FIELD_EOM_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ATT_CTRL_DEBUG { \
    223, \
    "ATT_CTRL_DEBUG", \
    3, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_att_ctrl_debug_t, time_usec) }, \
         { "rpm", NULL, MAVLINK_TYPE_FLOAT, 6, 8, offsetof(mavlink_att_ctrl_debug_t, rpm) }, \
         { "eOm", NULL, MAVLINK_TYPE_FLOAT, 3, 32, offsetof(mavlink_att_ctrl_debug_t, eOm) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ATT_CTRL_DEBUG { \
    "ATT_CTRL_DEBUG", \
    3, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_att_ctrl_debug_t, time_usec) }, \
         { "rpm", NULL, MAVLINK_TYPE_FLOAT, 6, 8, offsetof(mavlink_att_ctrl_debug_t, rpm) }, \
         { "eOm", NULL, MAVLINK_TYPE_FLOAT, 3, 32, offsetof(mavlink_att_ctrl_debug_t, eOm) }, \
         } \
}
#endif

/**
 * @brief Pack a att_ctrl_debug message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param rpm RPM values calculated from MocapAttitudeController for quadrotor
 * @param eOm Angular velocity error
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const float *rpm, const float *eOm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, rpm, 6);
    _mav_put_float_array(buf, 32, eOm, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN);
#else
    mavlink_att_ctrl_debug_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.rpm, rpm, sizeof(float)*6);
    mav_array_memcpy(packet.eOm, eOm, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ATT_CTRL_DEBUG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
}

/**
 * @brief Pack a att_ctrl_debug message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param rpm RPM values calculated from MocapAttitudeController for quadrotor
 * @param eOm Angular velocity error
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const float *rpm,const float *eOm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, rpm, 6);
    _mav_put_float_array(buf, 32, eOm, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN);
#else
    mavlink_att_ctrl_debug_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.rpm, rpm, sizeof(float)*6);
    mav_array_memcpy(packet.eOm, eOm, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ATT_CTRL_DEBUG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
}

/**
 * @brief Encode a att_ctrl_debug struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param att_ctrl_debug C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_att_ctrl_debug_t* att_ctrl_debug)
{
    return mavlink_msg_att_ctrl_debug_pack(system_id, component_id, msg, att_ctrl_debug->time_usec, att_ctrl_debug->rpm, att_ctrl_debug->eOm);
}

/**
 * @brief Encode a att_ctrl_debug struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param att_ctrl_debug C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_att_ctrl_debug_t* att_ctrl_debug)
{
    return mavlink_msg_att_ctrl_debug_pack_chan(system_id, component_id, chan, msg, att_ctrl_debug->time_usec, att_ctrl_debug->rpm, att_ctrl_debug->eOm);
}

/**
 * @brief Send a att_ctrl_debug message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param rpm RPM values calculated from MocapAttitudeController for quadrotor
 * @param eOm Angular velocity error
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_att_ctrl_debug_send(mavlink_channel_t chan, uint64_t time_usec, const float *rpm, const float *eOm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, rpm, 6);
    _mav_put_float_array(buf, 32, eOm, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATT_CTRL_DEBUG, buf, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
#else
    mavlink_att_ctrl_debug_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.rpm, rpm, sizeof(float)*6);
    mav_array_memcpy(packet.eOm, eOm, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATT_CTRL_DEBUG, (const char *)&packet, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
#endif
}

/**
 * @brief Send a att_ctrl_debug message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_att_ctrl_debug_send_struct(mavlink_channel_t chan, const mavlink_att_ctrl_debug_t* att_ctrl_debug)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_att_ctrl_debug_send(chan, att_ctrl_debug->time_usec, att_ctrl_debug->rpm, att_ctrl_debug->eOm);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATT_CTRL_DEBUG, (const char *)att_ctrl_debug, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
#endif
}

#if MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_att_ctrl_debug_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const float *rpm, const float *eOm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, rpm, 6);
    _mav_put_float_array(buf, 32, eOm, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATT_CTRL_DEBUG, buf, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
#else
    mavlink_att_ctrl_debug_t *packet = (mavlink_att_ctrl_debug_t *)msgbuf;
    packet->time_usec = time_usec;
    mav_array_memcpy(packet->rpm, rpm, sizeof(float)*6);
    mav_array_memcpy(packet->eOm, eOm, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATT_CTRL_DEBUG, (const char *)packet, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
#endif
}
#endif

#endif

// MESSAGE ATT_CTRL_DEBUG UNPACKING


/**
 * @brief Get field time_usec from att_ctrl_debug message
 *
 * @return Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_att_ctrl_debug_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field rpm from att_ctrl_debug message
 *
 * @return RPM values calculated from MocapAttitudeController for quadrotor
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_get_rpm(const mavlink_message_t* msg, float *rpm)
{
    return _MAV_RETURN_float_array(msg, rpm, 6,  8);
}

/**
 * @brief Get field eOm from att_ctrl_debug message
 *
 * @return Angular velocity error
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_get_eOm(const mavlink_message_t* msg, float *eOm)
{
    return _MAV_RETURN_float_array(msg, eOm, 3,  32);
}

/**
 * @brief Decode a att_ctrl_debug message into a struct
 *
 * @param msg The message to decode
 * @param att_ctrl_debug C-struct to decode the message contents into
 */
static inline void mavlink_msg_att_ctrl_debug_decode(const mavlink_message_t* msg, mavlink_att_ctrl_debug_t* att_ctrl_debug)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    att_ctrl_debug->time_usec = mavlink_msg_att_ctrl_debug_get_time_usec(msg);
    mavlink_msg_att_ctrl_debug_get_rpm(msg, att_ctrl_debug->rpm);
    mavlink_msg_att_ctrl_debug_get_eOm(msg, att_ctrl_debug->eOm);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN? msg->len : MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN;
        memset(att_ctrl_debug, 0, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN);
    memcpy(att_ctrl_debug, _MAV_PAYLOAD(msg), len);
#endif
}
