#pragma once
// MESSAGE ATT_CTRL_DEBUG PACKING

#define MAVLINK_MSG_ID_ATT_CTRL_DEBUG 437


typedef struct __mavlink_att_ctrl_debug_t {
 uint64_t time_usec; /*<  Timestamp (micros since boot or Unix epoch)*/
 float rpm[4]; /*<  RPM*/
 float ang_vel_err[3]; /*<  Angular velocity error*/
 float ang_vel_des[3]; /*<  Desired angular velocity*/
 float orientation_err[3]; /*<  Orientation error*/
 float orientation_des[9]; /*<  Desired orientation*/
 float orientation_act[9]; /*<  Actual orientation*/
 float body_cmd_fbz; /*<  Thrust component of cascaded command*/
 float mb[3]; /*<  Torque*/
} mavlink_att_ctrl_debug_t;

#define MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN 148
#define MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN 148
#define MAVLINK_MSG_ID_437_LEN 148
#define MAVLINK_MSG_ID_437_MIN_LEN 148

#define MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC 85
#define MAVLINK_MSG_ID_437_CRC 85

#define MAVLINK_MSG_ATT_CTRL_DEBUG_FIELD_RPM_LEN 4
#define MAVLINK_MSG_ATT_CTRL_DEBUG_FIELD_ANG_VEL_ERR_LEN 3
#define MAVLINK_MSG_ATT_CTRL_DEBUG_FIELD_ANG_VEL_DES_LEN 3
#define MAVLINK_MSG_ATT_CTRL_DEBUG_FIELD_ORIENTATION_ERR_LEN 3
#define MAVLINK_MSG_ATT_CTRL_DEBUG_FIELD_ORIENTATION_DES_LEN 9
#define MAVLINK_MSG_ATT_CTRL_DEBUG_FIELD_ORIENTATION_ACT_LEN 9
#define MAVLINK_MSG_ATT_CTRL_DEBUG_FIELD_MB_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ATT_CTRL_DEBUG { \
    437, \
    "ATT_CTRL_DEBUG", \
    9, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_att_ctrl_debug_t, time_usec) }, \
         { "rpm", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_att_ctrl_debug_t, rpm) }, \
         { "ang_vel_err", NULL, MAVLINK_TYPE_FLOAT, 3, 24, offsetof(mavlink_att_ctrl_debug_t, ang_vel_err) }, \
         { "ang_vel_des", NULL, MAVLINK_TYPE_FLOAT, 3, 36, offsetof(mavlink_att_ctrl_debug_t, ang_vel_des) }, \
         { "orientation_err", NULL, MAVLINK_TYPE_FLOAT, 3, 48, offsetof(mavlink_att_ctrl_debug_t, orientation_err) }, \
         { "orientation_des", NULL, MAVLINK_TYPE_FLOAT, 9, 60, offsetof(mavlink_att_ctrl_debug_t, orientation_des) }, \
         { "orientation_act", NULL, MAVLINK_TYPE_FLOAT, 9, 96, offsetof(mavlink_att_ctrl_debug_t, orientation_act) }, \
         { "body_cmd_fbz", NULL, MAVLINK_TYPE_FLOAT, 0, 132, offsetof(mavlink_att_ctrl_debug_t, body_cmd_fbz) }, \
         { "mb", NULL, MAVLINK_TYPE_FLOAT, 3, 136, offsetof(mavlink_att_ctrl_debug_t, mb) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ATT_CTRL_DEBUG { \
    "ATT_CTRL_DEBUG", \
    9, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_att_ctrl_debug_t, time_usec) }, \
         { "rpm", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_att_ctrl_debug_t, rpm) }, \
         { "ang_vel_err", NULL, MAVLINK_TYPE_FLOAT, 3, 24, offsetof(mavlink_att_ctrl_debug_t, ang_vel_err) }, \
         { "ang_vel_des", NULL, MAVLINK_TYPE_FLOAT, 3, 36, offsetof(mavlink_att_ctrl_debug_t, ang_vel_des) }, \
         { "orientation_err", NULL, MAVLINK_TYPE_FLOAT, 3, 48, offsetof(mavlink_att_ctrl_debug_t, orientation_err) }, \
         { "orientation_des", NULL, MAVLINK_TYPE_FLOAT, 9, 60, offsetof(mavlink_att_ctrl_debug_t, orientation_des) }, \
         { "orientation_act", NULL, MAVLINK_TYPE_FLOAT, 9, 96, offsetof(mavlink_att_ctrl_debug_t, orientation_act) }, \
         { "body_cmd_fbz", NULL, MAVLINK_TYPE_FLOAT, 0, 132, offsetof(mavlink_att_ctrl_debug_t, body_cmd_fbz) }, \
         { "mb", NULL, MAVLINK_TYPE_FLOAT, 3, 136, offsetof(mavlink_att_ctrl_debug_t, mb) }, \
         } \
}
#endif

/**
 * @brief Pack a att_ctrl_debug message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param rpm  RPM
 * @param ang_vel_err  Angular velocity error
 * @param ang_vel_des  Desired angular velocity
 * @param orientation_err  Orientation error
 * @param orientation_des  Desired orientation
 * @param orientation_act  Actual orientation
 * @param body_cmd_fbz  Thrust component of cascaded command
 * @param mb  Torque
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const float *rpm, const float *ang_vel_err, const float *ang_vel_des, const float *orientation_err, const float *orientation_des, const float *orientation_act, float body_cmd_fbz, const float *mb)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 132, body_cmd_fbz);
    _mav_put_float_array(buf, 8, rpm, 4);
    _mav_put_float_array(buf, 24, ang_vel_err, 3);
    _mav_put_float_array(buf, 36, ang_vel_des, 3);
    _mav_put_float_array(buf, 48, orientation_err, 3);
    _mav_put_float_array(buf, 60, orientation_des, 9);
    _mav_put_float_array(buf, 96, orientation_act, 9);
    _mav_put_float_array(buf, 136, mb, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN);
#else
    mavlink_att_ctrl_debug_t packet;
    packet.time_usec = time_usec;
    packet.body_cmd_fbz = body_cmd_fbz;
    mav_array_memcpy(packet.rpm, rpm, sizeof(float)*4);
    mav_array_memcpy(packet.ang_vel_err, ang_vel_err, sizeof(float)*3);
    mav_array_memcpy(packet.ang_vel_des, ang_vel_des, sizeof(float)*3);
    mav_array_memcpy(packet.orientation_err, orientation_err, sizeof(float)*3);
    mav_array_memcpy(packet.orientation_des, orientation_des, sizeof(float)*9);
    mav_array_memcpy(packet.orientation_act, orientation_act, sizeof(float)*9);
    mav_array_memcpy(packet.mb, mb, sizeof(float)*3);
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
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param rpm  RPM
 * @param ang_vel_err  Angular velocity error
 * @param ang_vel_des  Desired angular velocity
 * @param orientation_err  Orientation error
 * @param orientation_des  Desired orientation
 * @param orientation_act  Actual orientation
 * @param body_cmd_fbz  Thrust component of cascaded command
 * @param mb  Torque
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const float *rpm,const float *ang_vel_err,const float *ang_vel_des,const float *orientation_err,const float *orientation_des,const float *orientation_act,float body_cmd_fbz,const float *mb)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 132, body_cmd_fbz);
    _mav_put_float_array(buf, 8, rpm, 4);
    _mav_put_float_array(buf, 24, ang_vel_err, 3);
    _mav_put_float_array(buf, 36, ang_vel_des, 3);
    _mav_put_float_array(buf, 48, orientation_err, 3);
    _mav_put_float_array(buf, 60, orientation_des, 9);
    _mav_put_float_array(buf, 96, orientation_act, 9);
    _mav_put_float_array(buf, 136, mb, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN);
#else
    mavlink_att_ctrl_debug_t packet;
    packet.time_usec = time_usec;
    packet.body_cmd_fbz = body_cmd_fbz;
    mav_array_memcpy(packet.rpm, rpm, sizeof(float)*4);
    mav_array_memcpy(packet.ang_vel_err, ang_vel_err, sizeof(float)*3);
    mav_array_memcpy(packet.ang_vel_des, ang_vel_des, sizeof(float)*3);
    mav_array_memcpy(packet.orientation_err, orientation_err, sizeof(float)*3);
    mav_array_memcpy(packet.orientation_des, orientation_des, sizeof(float)*9);
    mav_array_memcpy(packet.orientation_act, orientation_act, sizeof(float)*9);
    mav_array_memcpy(packet.mb, mb, sizeof(float)*3);
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
    return mavlink_msg_att_ctrl_debug_pack(system_id, component_id, msg, att_ctrl_debug->time_usec, att_ctrl_debug->rpm, att_ctrl_debug->ang_vel_err, att_ctrl_debug->ang_vel_des, att_ctrl_debug->orientation_err, att_ctrl_debug->orientation_des, att_ctrl_debug->orientation_act, att_ctrl_debug->body_cmd_fbz, att_ctrl_debug->mb);
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
    return mavlink_msg_att_ctrl_debug_pack_chan(system_id, component_id, chan, msg, att_ctrl_debug->time_usec, att_ctrl_debug->rpm, att_ctrl_debug->ang_vel_err, att_ctrl_debug->ang_vel_des, att_ctrl_debug->orientation_err, att_ctrl_debug->orientation_des, att_ctrl_debug->orientation_act, att_ctrl_debug->body_cmd_fbz, att_ctrl_debug->mb);
}

/**
 * @brief Send a att_ctrl_debug message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param rpm  RPM
 * @param ang_vel_err  Angular velocity error
 * @param ang_vel_des  Desired angular velocity
 * @param orientation_err  Orientation error
 * @param orientation_des  Desired orientation
 * @param orientation_act  Actual orientation
 * @param body_cmd_fbz  Thrust component of cascaded command
 * @param mb  Torque
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_att_ctrl_debug_send(mavlink_channel_t chan, uint64_t time_usec, const float *rpm, const float *ang_vel_err, const float *ang_vel_des, const float *orientation_err, const float *orientation_des, const float *orientation_act, float body_cmd_fbz, const float *mb)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 132, body_cmd_fbz);
    _mav_put_float_array(buf, 8, rpm, 4);
    _mav_put_float_array(buf, 24, ang_vel_err, 3);
    _mav_put_float_array(buf, 36, ang_vel_des, 3);
    _mav_put_float_array(buf, 48, orientation_err, 3);
    _mav_put_float_array(buf, 60, orientation_des, 9);
    _mav_put_float_array(buf, 96, orientation_act, 9);
    _mav_put_float_array(buf, 136, mb, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATT_CTRL_DEBUG, buf, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
#else
    mavlink_att_ctrl_debug_t packet;
    packet.time_usec = time_usec;
    packet.body_cmd_fbz = body_cmd_fbz;
    mav_array_memcpy(packet.rpm, rpm, sizeof(float)*4);
    mav_array_memcpy(packet.ang_vel_err, ang_vel_err, sizeof(float)*3);
    mav_array_memcpy(packet.ang_vel_des, ang_vel_des, sizeof(float)*3);
    mav_array_memcpy(packet.orientation_err, orientation_err, sizeof(float)*3);
    mav_array_memcpy(packet.orientation_des, orientation_des, sizeof(float)*9);
    mav_array_memcpy(packet.orientation_act, orientation_act, sizeof(float)*9);
    mav_array_memcpy(packet.mb, mb, sizeof(float)*3);
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
    mavlink_msg_att_ctrl_debug_send(chan, att_ctrl_debug->time_usec, att_ctrl_debug->rpm, att_ctrl_debug->ang_vel_err, att_ctrl_debug->ang_vel_des, att_ctrl_debug->orientation_err, att_ctrl_debug->orientation_des, att_ctrl_debug->orientation_act, att_ctrl_debug->body_cmd_fbz, att_ctrl_debug->mb);
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
static inline void mavlink_msg_att_ctrl_debug_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const float *rpm, const float *ang_vel_err, const float *ang_vel_des, const float *orientation_err, const float *orientation_des, const float *orientation_act, float body_cmd_fbz, const float *mb)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 132, body_cmd_fbz);
    _mav_put_float_array(buf, 8, rpm, 4);
    _mav_put_float_array(buf, 24, ang_vel_err, 3);
    _mav_put_float_array(buf, 36, ang_vel_des, 3);
    _mav_put_float_array(buf, 48, orientation_err, 3);
    _mav_put_float_array(buf, 60, orientation_des, 9);
    _mav_put_float_array(buf, 96, orientation_act, 9);
    _mav_put_float_array(buf, 136, mb, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATT_CTRL_DEBUG, buf, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
#else
    mavlink_att_ctrl_debug_t *packet = (mavlink_att_ctrl_debug_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->body_cmd_fbz = body_cmd_fbz;
    mav_array_memcpy(packet->rpm, rpm, sizeof(float)*4);
    mav_array_memcpy(packet->ang_vel_err, ang_vel_err, sizeof(float)*3);
    mav_array_memcpy(packet->ang_vel_des, ang_vel_des, sizeof(float)*3);
    mav_array_memcpy(packet->orientation_err, orientation_err, sizeof(float)*3);
    mav_array_memcpy(packet->orientation_des, orientation_des, sizeof(float)*9);
    mav_array_memcpy(packet->orientation_act, orientation_act, sizeof(float)*9);
    mav_array_memcpy(packet->mb, mb, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATT_CTRL_DEBUG, (const char *)packet, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
#endif
}
#endif

#endif

// MESSAGE ATT_CTRL_DEBUG UNPACKING


/**
 * @brief Get field time_usec from att_ctrl_debug message
 *
 * @return  Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_att_ctrl_debug_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field rpm from att_ctrl_debug message
 *
 * @return  RPM
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_get_rpm(const mavlink_message_t* msg, float *rpm)
{
    return _MAV_RETURN_float_array(msg, rpm, 4,  8);
}

/**
 * @brief Get field ang_vel_err from att_ctrl_debug message
 *
 * @return  Angular velocity error
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_get_ang_vel_err(const mavlink_message_t* msg, float *ang_vel_err)
{
    return _MAV_RETURN_float_array(msg, ang_vel_err, 3,  24);
}

/**
 * @brief Get field ang_vel_des from att_ctrl_debug message
 *
 * @return  Desired angular velocity
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_get_ang_vel_des(const mavlink_message_t* msg, float *ang_vel_des)
{
    return _MAV_RETURN_float_array(msg, ang_vel_des, 3,  36);
}

/**
 * @brief Get field orientation_err from att_ctrl_debug message
 *
 * @return  Orientation error
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_get_orientation_err(const mavlink_message_t* msg, float *orientation_err)
{
    return _MAV_RETURN_float_array(msg, orientation_err, 3,  48);
}

/**
 * @brief Get field orientation_des from att_ctrl_debug message
 *
 * @return  Desired orientation
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_get_orientation_des(const mavlink_message_t* msg, float *orientation_des)
{
    return _MAV_RETURN_float_array(msg, orientation_des, 9,  60);
}

/**
 * @brief Get field orientation_act from att_ctrl_debug message
 *
 * @return  Actual orientation
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_get_orientation_act(const mavlink_message_t* msg, float *orientation_act)
{
    return _MAV_RETURN_float_array(msg, orientation_act, 9,  96);
}

/**
 * @brief Get field body_cmd_fbz from att_ctrl_debug message
 *
 * @return  Thrust component of cascaded command
 */
static inline float mavlink_msg_att_ctrl_debug_get_body_cmd_fbz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  132);
}

/**
 * @brief Get field mb from att_ctrl_debug message
 *
 * @return  Torque
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_get_mb(const mavlink_message_t* msg, float *mb)
{
    return _MAV_RETURN_float_array(msg, mb, 3,  136);
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
    mavlink_msg_att_ctrl_debug_get_ang_vel_err(msg, att_ctrl_debug->ang_vel_err);
    mavlink_msg_att_ctrl_debug_get_ang_vel_des(msg, att_ctrl_debug->ang_vel_des);
    mavlink_msg_att_ctrl_debug_get_orientation_err(msg, att_ctrl_debug->orientation_err);
    mavlink_msg_att_ctrl_debug_get_orientation_des(msg, att_ctrl_debug->orientation_des);
    mavlink_msg_att_ctrl_debug_get_orientation_act(msg, att_ctrl_debug->orientation_act);
    att_ctrl_debug->body_cmd_fbz = mavlink_msg_att_ctrl_debug_get_body_cmd_fbz(msg);
    mavlink_msg_att_ctrl_debug_get_mb(msg, att_ctrl_debug->mb);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN? msg->len : MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN;
        memset(att_ctrl_debug, 0, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN);
    memcpy(att_ctrl_debug, _MAV_PAYLOAD(msg), len);
#endif
}
