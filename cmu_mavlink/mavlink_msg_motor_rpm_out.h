#pragma once
// MESSAGE MOTOR_RPM_OUT PACKING

#define MAVLINK_MSG_ID_MOTOR_RPM_OUT 223

MAVPACKED(
typedef struct __mavlink_motor_rpm_out_t {
 uint64_t time_usec; /*< Timestamp (micros since boot or Unix epoch)*/
 float rpm[4]; /*< RPM values calculated from MocapAttitudeController for quadrotor*/
}) mavlink_motor_rpm_out_t;

#define MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN 24
#define MAVLINK_MSG_ID_MOTOR_RPM_OUT_MIN_LEN 24
#define MAVLINK_MSG_ID_223_LEN 24
#define MAVLINK_MSG_ID_223_MIN_LEN 24

#define MAVLINK_MSG_ID_MOTOR_RPM_OUT_CRC 9
#define MAVLINK_MSG_ID_223_CRC 9

#define MAVLINK_MSG_MOTOR_RPM_OUT_FIELD_RPM_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MOTOR_RPM_OUT { \
    223, \
    "MOTOR_RPM_OUT", \
    2, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_motor_rpm_out_t, time_usec) }, \
         { "rpm", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_motor_rpm_out_t, rpm) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MOTOR_RPM_OUT { \
    "MOTOR_RPM_OUT", \
    2, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_motor_rpm_out_t, time_usec) }, \
         { "rpm", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_motor_rpm_out_t, rpm) }, \
         } \
}
#endif

/**
 * @brief Pack a motor_rpm_out message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param rpm RPM values calculated from MocapAttitudeController for quadrotor
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_rpm_out_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const float *rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, rpm, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN);
#else
    mavlink_motor_rpm_out_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.rpm, rpm, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOTOR_RPM_OUT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOTOR_RPM_OUT_MIN_LEN, MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN, MAVLINK_MSG_ID_MOTOR_RPM_OUT_CRC);
}

/**
 * @brief Pack a motor_rpm_out message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param rpm RPM values calculated from MocapAttitudeController for quadrotor
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motor_rpm_out_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const float *rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, rpm, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN);
#else
    mavlink_motor_rpm_out_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.rpm, rpm, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOTOR_RPM_OUT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOTOR_RPM_OUT_MIN_LEN, MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN, MAVLINK_MSG_ID_MOTOR_RPM_OUT_CRC);
}

/**
 * @brief Encode a motor_rpm_out struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param motor_rpm_out C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_rpm_out_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_motor_rpm_out_t* motor_rpm_out)
{
    return mavlink_msg_motor_rpm_out_pack(system_id, component_id, msg, motor_rpm_out->time_usec, motor_rpm_out->rpm);
}

/**
 * @brief Encode a motor_rpm_out struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motor_rpm_out C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motor_rpm_out_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_motor_rpm_out_t* motor_rpm_out)
{
    return mavlink_msg_motor_rpm_out_pack_chan(system_id, component_id, chan, msg, motor_rpm_out->time_usec, motor_rpm_out->rpm);
}

/**
 * @brief Send a motor_rpm_out message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param rpm RPM values calculated from MocapAttitudeController for quadrotor
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_motor_rpm_out_send(mavlink_channel_t chan, uint64_t time_usec, const float *rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, rpm, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_RPM_OUT, buf, MAVLINK_MSG_ID_MOTOR_RPM_OUT_MIN_LEN, MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN, MAVLINK_MSG_ID_MOTOR_RPM_OUT_CRC);
#else
    mavlink_motor_rpm_out_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.rpm, rpm, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_RPM_OUT, (const char *)&packet, MAVLINK_MSG_ID_MOTOR_RPM_OUT_MIN_LEN, MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN, MAVLINK_MSG_ID_MOTOR_RPM_OUT_CRC);
#endif
}

/**
 * @brief Send a motor_rpm_out message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_motor_rpm_out_send_struct(mavlink_channel_t chan, const mavlink_motor_rpm_out_t* motor_rpm_out)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_motor_rpm_out_send(chan, motor_rpm_out->time_usec, motor_rpm_out->rpm);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_RPM_OUT, (const char *)motor_rpm_out, MAVLINK_MSG_ID_MOTOR_RPM_OUT_MIN_LEN, MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN, MAVLINK_MSG_ID_MOTOR_RPM_OUT_CRC);
#endif
}

#if MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_motor_rpm_out_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const float *rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, rpm, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_RPM_OUT, buf, MAVLINK_MSG_ID_MOTOR_RPM_OUT_MIN_LEN, MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN, MAVLINK_MSG_ID_MOTOR_RPM_OUT_CRC);
#else
    mavlink_motor_rpm_out_t *packet = (mavlink_motor_rpm_out_t *)msgbuf;
    packet->time_usec = time_usec;
    mav_array_memcpy(packet->rpm, rpm, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_RPM_OUT, (const char *)packet, MAVLINK_MSG_ID_MOTOR_RPM_OUT_MIN_LEN, MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN, MAVLINK_MSG_ID_MOTOR_RPM_OUT_CRC);
#endif
}
#endif

#endif

// MESSAGE MOTOR_RPM_OUT UNPACKING


/**
 * @brief Get field time_usec from motor_rpm_out message
 *
 * @return Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_motor_rpm_out_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field rpm from motor_rpm_out message
 *
 * @return RPM values calculated from MocapAttitudeController for quadrotor
 */
static inline uint16_t mavlink_msg_motor_rpm_out_get_rpm(const mavlink_message_t* msg, float *rpm)
{
    return _MAV_RETURN_float_array(msg, rpm, 4,  8);
}

/**
 * @brief Decode a motor_rpm_out message into a struct
 *
 * @param msg The message to decode
 * @param motor_rpm_out C-struct to decode the message contents into
 */
static inline void mavlink_msg_motor_rpm_out_decode(const mavlink_message_t* msg, mavlink_motor_rpm_out_t* motor_rpm_out)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    motor_rpm_out->time_usec = mavlink_msg_motor_rpm_out_get_time_usec(msg);
    mavlink_msg_motor_rpm_out_get_rpm(msg, motor_rpm_out->rpm);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN? msg->len : MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN;
        memset(motor_rpm_out, 0, MAVLINK_MSG_ID_MOTOR_RPM_OUT_LEN);
    memcpy(motor_rpm_out, _MAV_PAYLOAD(msg), len);
#endif
}
