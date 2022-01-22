#pragma once
// MESSAGE ODOM_MOCAP PACKING

#define MAVLINK_MSG_ID_ODOM_MOCAP 422


typedef struct __mavlink_odom_mocap_t {
 uint64_t time_usec; /*<  Timestamp (micros since boot or Unix epoch)*/
 float q[4]; /*<  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)*/
 float x; /*<  X position in meters (NED)*/
 float y; /*<  Y position in meters (NED)*/
 float z; /*<  Z position in meters (NED)*/
 float vx; /*<  X velocity in m/s (NED)*/
 float vy; /*<  Y velocity in m/s (NED)*/
 float vz; /*<  Z velocity in m/s (NED)*/
} mavlink_odom_mocap_t;

#define MAVLINK_MSG_ID_ODOM_MOCAP_LEN 48
#define MAVLINK_MSG_ID_ODOM_MOCAP_MIN_LEN 48
#define MAVLINK_MSG_ID_422_LEN 48
#define MAVLINK_MSG_ID_422_MIN_LEN 48

#define MAVLINK_MSG_ID_ODOM_MOCAP_CRC 177
#define MAVLINK_MSG_ID_422_CRC 177

#define MAVLINK_MSG_ODOM_MOCAP_FIELD_Q_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ODOM_MOCAP { \
    422, \
    "ODOM_MOCAP", \
    8, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_odom_mocap_t, time_usec) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_odom_mocap_t, q) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_odom_mocap_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_odom_mocap_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_odom_mocap_t, z) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_odom_mocap_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_odom_mocap_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_odom_mocap_t, vz) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ODOM_MOCAP { \
    "ODOM_MOCAP", \
    8, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_odom_mocap_t, time_usec) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_odom_mocap_t, q) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_odom_mocap_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_odom_mocap_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_odom_mocap_t, z) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_odom_mocap_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_odom_mocap_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_odom_mocap_t, vz) }, \
         } \
}
#endif

/**
 * @brief Pack a odom_mocap message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param q  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @param x  X position in meters (NED)
 * @param y  Y position in meters (NED)
 * @param z  Z position in meters (NED)
 * @param vx  X velocity in m/s (NED)
 * @param vy  Y velocity in m/s (NED)
 * @param vz  Z velocity in m/s (NED)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_odom_mocap_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const float *q, float x, float y, float z, float vx, float vy, float vz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ODOM_MOCAP_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 24, x);
    _mav_put_float(buf, 28, y);
    _mav_put_float(buf, 32, z);
    _mav_put_float(buf, 36, vx);
    _mav_put_float(buf, 40, vy);
    _mav_put_float(buf, 44, vz);
    _mav_put_float_array(buf, 8, q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ODOM_MOCAP_LEN);
#else
    mavlink_odom_mocap_t packet;
    packet.time_usec = time_usec;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ODOM_MOCAP_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ODOM_MOCAP;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ODOM_MOCAP_MIN_LEN, MAVLINK_MSG_ID_ODOM_MOCAP_LEN, MAVLINK_MSG_ID_ODOM_MOCAP_CRC);
}

/**
 * @brief Pack a odom_mocap message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param q  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @param x  X position in meters (NED)
 * @param y  Y position in meters (NED)
 * @param z  Z position in meters (NED)
 * @param vx  X velocity in m/s (NED)
 * @param vy  Y velocity in m/s (NED)
 * @param vz  Z velocity in m/s (NED)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_odom_mocap_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const float *q,float x,float y,float z,float vx,float vy,float vz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ODOM_MOCAP_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 24, x);
    _mav_put_float(buf, 28, y);
    _mav_put_float(buf, 32, z);
    _mav_put_float(buf, 36, vx);
    _mav_put_float(buf, 40, vy);
    _mav_put_float(buf, 44, vz);
    _mav_put_float_array(buf, 8, q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ODOM_MOCAP_LEN);
#else
    mavlink_odom_mocap_t packet;
    packet.time_usec = time_usec;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ODOM_MOCAP_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ODOM_MOCAP;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ODOM_MOCAP_MIN_LEN, MAVLINK_MSG_ID_ODOM_MOCAP_LEN, MAVLINK_MSG_ID_ODOM_MOCAP_CRC);
}

/**
 * @brief Encode a odom_mocap struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param odom_mocap C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_odom_mocap_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_odom_mocap_t* odom_mocap)
{
    return mavlink_msg_odom_mocap_pack(system_id, component_id, msg, odom_mocap->time_usec, odom_mocap->q, odom_mocap->x, odom_mocap->y, odom_mocap->z, odom_mocap->vx, odom_mocap->vy, odom_mocap->vz);
}

/**
 * @brief Encode a odom_mocap struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param odom_mocap C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_odom_mocap_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_odom_mocap_t* odom_mocap)
{
    return mavlink_msg_odom_mocap_pack_chan(system_id, component_id, chan, msg, odom_mocap->time_usec, odom_mocap->q, odom_mocap->x, odom_mocap->y, odom_mocap->z, odom_mocap->vx, odom_mocap->vy, odom_mocap->vz);
}

/**
 * @brief Send a odom_mocap message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param q  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @param x  X position in meters (NED)
 * @param y  Y position in meters (NED)
 * @param z  Z position in meters (NED)
 * @param vx  X velocity in m/s (NED)
 * @param vy  Y velocity in m/s (NED)
 * @param vz  Z velocity in m/s (NED)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_odom_mocap_send(mavlink_channel_t chan, uint64_t time_usec, const float *q, float x, float y, float z, float vx, float vy, float vz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ODOM_MOCAP_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 24, x);
    _mav_put_float(buf, 28, y);
    _mav_put_float(buf, 32, z);
    _mav_put_float(buf, 36, vx);
    _mav_put_float(buf, 40, vy);
    _mav_put_float(buf, 44, vz);
    _mav_put_float_array(buf, 8, q, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ODOM_MOCAP, buf, MAVLINK_MSG_ID_ODOM_MOCAP_MIN_LEN, MAVLINK_MSG_ID_ODOM_MOCAP_LEN, MAVLINK_MSG_ID_ODOM_MOCAP_CRC);
#else
    mavlink_odom_mocap_t packet;
    packet.time_usec = time_usec;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ODOM_MOCAP, (const char *)&packet, MAVLINK_MSG_ID_ODOM_MOCAP_MIN_LEN, MAVLINK_MSG_ID_ODOM_MOCAP_LEN, MAVLINK_MSG_ID_ODOM_MOCAP_CRC);
#endif
}

/**
 * @brief Send a odom_mocap message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_odom_mocap_send_struct(mavlink_channel_t chan, const mavlink_odom_mocap_t* odom_mocap)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_odom_mocap_send(chan, odom_mocap->time_usec, odom_mocap->q, odom_mocap->x, odom_mocap->y, odom_mocap->z, odom_mocap->vx, odom_mocap->vy, odom_mocap->vz);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ODOM_MOCAP, (const char *)odom_mocap, MAVLINK_MSG_ID_ODOM_MOCAP_MIN_LEN, MAVLINK_MSG_ID_ODOM_MOCAP_LEN, MAVLINK_MSG_ID_ODOM_MOCAP_CRC);
#endif
}

#if MAVLINK_MSG_ID_ODOM_MOCAP_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_odom_mocap_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const float *q, float x, float y, float z, float vx, float vy, float vz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 24, x);
    _mav_put_float(buf, 28, y);
    _mav_put_float(buf, 32, z);
    _mav_put_float(buf, 36, vx);
    _mav_put_float(buf, 40, vy);
    _mav_put_float(buf, 44, vz);
    _mav_put_float_array(buf, 8, q, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ODOM_MOCAP, buf, MAVLINK_MSG_ID_ODOM_MOCAP_MIN_LEN, MAVLINK_MSG_ID_ODOM_MOCAP_LEN, MAVLINK_MSG_ID_ODOM_MOCAP_CRC);
#else
    mavlink_odom_mocap_t *packet = (mavlink_odom_mocap_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->x = x;
    packet->y = y;
    packet->z = z;
    packet->vx = vx;
    packet->vy = vy;
    packet->vz = vz;
    mav_array_memcpy(packet->q, q, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ODOM_MOCAP, (const char *)packet, MAVLINK_MSG_ID_ODOM_MOCAP_MIN_LEN, MAVLINK_MSG_ID_ODOM_MOCAP_LEN, MAVLINK_MSG_ID_ODOM_MOCAP_CRC);
#endif
}
#endif

#endif

// MESSAGE ODOM_MOCAP UNPACKING


/**
 * @brief Get field time_usec from odom_mocap message
 *
 * @return  Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_odom_mocap_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field q from odom_mocap message
 *
 * @return  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 */
static inline uint16_t mavlink_msg_odom_mocap_get_q(const mavlink_message_t* msg, float *q)
{
    return _MAV_RETURN_float_array(msg, q, 4,  8);
}

/**
 * @brief Get field x from odom_mocap message
 *
 * @return  X position in meters (NED)
 */
static inline float mavlink_msg_odom_mocap_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field y from odom_mocap message
 *
 * @return  Y position in meters (NED)
 */
static inline float mavlink_msg_odom_mocap_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field z from odom_mocap message
 *
 * @return  Z position in meters (NED)
 */
static inline float mavlink_msg_odom_mocap_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field vx from odom_mocap message
 *
 * @return  X velocity in m/s (NED)
 */
static inline float mavlink_msg_odom_mocap_get_vx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field vy from odom_mocap message
 *
 * @return  Y velocity in m/s (NED)
 */
static inline float mavlink_msg_odom_mocap_get_vy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field vz from odom_mocap message
 *
 * @return  Z velocity in m/s (NED)
 */
static inline float mavlink_msg_odom_mocap_get_vz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Decode a odom_mocap message into a struct
 *
 * @param msg The message to decode
 * @param odom_mocap C-struct to decode the message contents into
 */
static inline void mavlink_msg_odom_mocap_decode(const mavlink_message_t* msg, mavlink_odom_mocap_t* odom_mocap)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    odom_mocap->time_usec = mavlink_msg_odom_mocap_get_time_usec(msg);
    mavlink_msg_odom_mocap_get_q(msg, odom_mocap->q);
    odom_mocap->x = mavlink_msg_odom_mocap_get_x(msg);
    odom_mocap->y = mavlink_msg_odom_mocap_get_y(msg);
    odom_mocap->z = mavlink_msg_odom_mocap_get_z(msg);
    odom_mocap->vx = mavlink_msg_odom_mocap_get_vx(msg);
    odom_mocap->vy = mavlink_msg_odom_mocap_get_vy(msg);
    odom_mocap->vz = mavlink_msg_odom_mocap_get_vz(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ODOM_MOCAP_LEN? msg->len : MAVLINK_MSG_ID_ODOM_MOCAP_LEN;
        memset(odom_mocap, 0, MAVLINK_MSG_ID_ODOM_MOCAP_LEN);
    memcpy(odom_mocap, _MAV_PAYLOAD(msg), len);
#endif
}
