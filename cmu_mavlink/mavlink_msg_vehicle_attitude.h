#pragma once
// MESSAGE VEHICLE_ATTITUDE PACKING

#define MAVLINK_MSG_ID_VEHICLE_ATTITUDE 225

MAVPACKED(
typedef struct __mavlink_vehicle_attitude_t {
 uint64_t time_usec; /*<  Timestamp (micros since boot or Unix epoch)*/
 float q[4]; /*<  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)*/
}) mavlink_vehicle_attitude_t;

#define MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN 24
#define MAVLINK_MSG_ID_VEHICLE_ATTITUDE_MIN_LEN 24
#define MAVLINK_MSG_ID_225_LEN 24
#define MAVLINK_MSG_ID_225_MIN_LEN 24

#define MAVLINK_MSG_ID_VEHICLE_ATTITUDE_CRC 76
#define MAVLINK_MSG_ID_225_CRC 76

#define MAVLINK_MSG_VEHICLE_ATTITUDE_FIELD_Q_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VEHICLE_ATTITUDE { \
    225, \
    "VEHICLE_ATTITUDE", \
    2, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vehicle_attitude_t, time_usec) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_vehicle_attitude_t, q) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VEHICLE_ATTITUDE { \
    "VEHICLE_ATTITUDE", \
    2, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vehicle_attitude_t, time_usec) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_vehicle_attitude_t, q) }, \
         } \
}
#endif

/**
 * @brief Pack a vehicle_attitude message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param q  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vehicle_attitude_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const float *q)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN);
#else
    mavlink_vehicle_attitude_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VEHICLE_ATTITUDE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_CRC);
}

/**
 * @brief Pack a vehicle_attitude message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param q  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vehicle_attitude_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const float *q)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN);
#else
    mavlink_vehicle_attitude_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VEHICLE_ATTITUDE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_CRC);
}

/**
 * @brief Encode a vehicle_attitude struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vehicle_attitude C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vehicle_attitude_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vehicle_attitude_t* vehicle_attitude)
{
    return mavlink_msg_vehicle_attitude_pack(system_id, component_id, msg, vehicle_attitude->time_usec, vehicle_attitude->q);
}

/**
 * @brief Encode a vehicle_attitude struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vehicle_attitude C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vehicle_attitude_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vehicle_attitude_t* vehicle_attitude)
{
    return mavlink_msg_vehicle_attitude_pack_chan(system_id, component_id, chan, msg, vehicle_attitude->time_usec, vehicle_attitude->q);
}

/**
 * @brief Send a vehicle_attitude message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param q  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vehicle_attitude_send(mavlink_channel_t chan, uint64_t time_usec, const float *q)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, q, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_ATTITUDE, buf, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_CRC);
#else
    mavlink_vehicle_attitude_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_ATTITUDE, (const char *)&packet, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_CRC);
#endif
}

/**
 * @brief Send a vehicle_attitude message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_vehicle_attitude_send_struct(mavlink_channel_t chan, const mavlink_vehicle_attitude_t* vehicle_attitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_vehicle_attitude_send(chan, vehicle_attitude->time_usec, vehicle_attitude->q);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_ATTITUDE, (const char *)vehicle_attitude, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_CRC);
#endif
}

#if MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_vehicle_attitude_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const float *q)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, q, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_ATTITUDE, buf, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_CRC);
#else
    mavlink_vehicle_attitude_t *packet = (mavlink_vehicle_attitude_t *)msgbuf;
    packet->time_usec = time_usec;
    mav_array_memcpy(packet->q, q, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_ATTITUDE, (const char *)packet, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_CRC);
#endif
}
#endif

#endif

// MESSAGE VEHICLE_ATTITUDE UNPACKING


/**
 * @brief Get field time_usec from vehicle_attitude message
 *
 * @return  Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_vehicle_attitude_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field q from vehicle_attitude message
 *
 * @return  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 */
static inline uint16_t mavlink_msg_vehicle_attitude_get_q(const mavlink_message_t* msg, float *q)
{
    return _MAV_RETURN_float_array(msg, q, 4,  8);
}

/**
 * @brief Decode a vehicle_attitude message into a struct
 *
 * @param msg The message to decode
 * @param vehicle_attitude C-struct to decode the message contents into
 */
static inline void mavlink_msg_vehicle_attitude_decode(const mavlink_message_t* msg, mavlink_vehicle_attitude_t* vehicle_attitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    vehicle_attitude->time_usec = mavlink_msg_vehicle_attitude_get_time_usec(msg);
    mavlink_msg_vehicle_attitude_get_q(msg, vehicle_attitude->q);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN? msg->len : MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN;
        memset(vehicle_attitude, 0, MAVLINK_MSG_ID_VEHICLE_ATTITUDE_LEN);
    memcpy(vehicle_attitude, _MAV_PAYLOAD(msg), len);
#endif
}
