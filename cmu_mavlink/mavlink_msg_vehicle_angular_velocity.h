#pragma once
// MESSAGE VEHICLE_ANGULAR_VELOCITY PACKING

#define MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY 439


typedef struct __mavlink_vehicle_angular_velocity_t {
 uint64_t time_usec; /*<  Timestamp (micros since boot or Unix epoch)*/
 float xyz[3]; /*<  Angular velocity about body axes (x, y, z)*/
} mavlink_vehicle_angular_velocity_t;

#define MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN 20
#define MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_MIN_LEN 20
#define MAVLINK_MSG_ID_439_LEN 20
#define MAVLINK_MSG_ID_439_MIN_LEN 20

#define MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_CRC 234
#define MAVLINK_MSG_ID_439_CRC 234

#define MAVLINK_MSG_VEHICLE_ANGULAR_VELOCITY_FIELD_XYZ_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VEHICLE_ANGULAR_VELOCITY { \
    439, \
    "VEHICLE_ANGULAR_VELOCITY", \
    2, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vehicle_angular_velocity_t, time_usec) }, \
         { "xyz", NULL, MAVLINK_TYPE_FLOAT, 3, 8, offsetof(mavlink_vehicle_angular_velocity_t, xyz) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VEHICLE_ANGULAR_VELOCITY { \
    "VEHICLE_ANGULAR_VELOCITY", \
    2, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_vehicle_angular_velocity_t, time_usec) }, \
         { "xyz", NULL, MAVLINK_TYPE_FLOAT, 3, 8, offsetof(mavlink_vehicle_angular_velocity_t, xyz) }, \
         } \
}
#endif

/**
 * @brief Pack a vehicle_angular_velocity message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param xyz  Angular velocity about body axes (x, y, z)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vehicle_angular_velocity_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const float *xyz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, xyz, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN);
#else
    mavlink_vehicle_angular_velocity_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.xyz, xyz, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_CRC);
}

/**
 * @brief Pack a vehicle_angular_velocity message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param xyz  Angular velocity about body axes (x, y, z)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vehicle_angular_velocity_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const float *xyz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, xyz, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN);
#else
    mavlink_vehicle_angular_velocity_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.xyz, xyz, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_CRC);
}

/**
 * @brief Encode a vehicle_angular_velocity struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vehicle_angular_velocity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vehicle_angular_velocity_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vehicle_angular_velocity_t* vehicle_angular_velocity)
{
    return mavlink_msg_vehicle_angular_velocity_pack(system_id, component_id, msg, vehicle_angular_velocity->time_usec, vehicle_angular_velocity->xyz);
}

/**
 * @brief Encode a vehicle_angular_velocity struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vehicle_angular_velocity C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vehicle_angular_velocity_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_vehicle_angular_velocity_t* vehicle_angular_velocity)
{
    return mavlink_msg_vehicle_angular_velocity_pack_chan(system_id, component_id, chan, msg, vehicle_angular_velocity->time_usec, vehicle_angular_velocity->xyz);
}

/**
 * @brief Send a vehicle_angular_velocity message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param xyz  Angular velocity about body axes (x, y, z)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vehicle_angular_velocity_send(mavlink_channel_t chan, uint64_t time_usec, const float *xyz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, xyz, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY, buf, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_CRC);
#else
    mavlink_vehicle_angular_velocity_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.xyz, xyz, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY, (const char *)&packet, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_CRC);
#endif
}

/**
 * @brief Send a vehicle_angular_velocity message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_vehicle_angular_velocity_send_struct(mavlink_channel_t chan, const mavlink_vehicle_angular_velocity_t* vehicle_angular_velocity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_vehicle_angular_velocity_send(chan, vehicle_angular_velocity->time_usec, vehicle_angular_velocity->xyz);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY, (const char *)vehicle_angular_velocity, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_CRC);
#endif
}

#if MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_vehicle_angular_velocity_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const float *xyz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, xyz, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY, buf, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_CRC);
#else
    mavlink_vehicle_angular_velocity_t *packet = (mavlink_vehicle_angular_velocity_t *)msgbuf;
    packet->time_usec = time_usec;
    mav_array_memcpy(packet->xyz, xyz, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY, (const char *)packet, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_MIN_LEN, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_CRC);
#endif
}
#endif

#endif

// MESSAGE VEHICLE_ANGULAR_VELOCITY UNPACKING


/**
 * @brief Get field time_usec from vehicle_angular_velocity message
 *
 * @return  Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_vehicle_angular_velocity_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field xyz from vehicle_angular_velocity message
 *
 * @return  Angular velocity about body axes (x, y, z)
 */
static inline uint16_t mavlink_msg_vehicle_angular_velocity_get_xyz(const mavlink_message_t* msg, float *xyz)
{
    return _MAV_RETURN_float_array(msg, xyz, 3,  8);
}

/**
 * @brief Decode a vehicle_angular_velocity message into a struct
 *
 * @param msg The message to decode
 * @param vehicle_angular_velocity C-struct to decode the message contents into
 */
static inline void mavlink_msg_vehicle_angular_velocity_decode(const mavlink_message_t* msg, mavlink_vehicle_angular_velocity_t* vehicle_angular_velocity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    vehicle_angular_velocity->time_usec = mavlink_msg_vehicle_angular_velocity_get_time_usec(msg);
    mavlink_msg_vehicle_angular_velocity_get_xyz(msg, vehicle_angular_velocity->xyz);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN? msg->len : MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN;
        memset(vehicle_angular_velocity, 0, MAVLINK_MSG_ID_VEHICLE_ANGULAR_VELOCITY_LEN);
    memcpy(vehicle_angular_velocity, _MAV_PAYLOAD(msg), len);
#endif
}
