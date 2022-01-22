#pragma once
// MESSAGE CASCADED_CMD PACKING

#define MAVLINK_MSG_ID_CASCADED_CMD 424


typedef struct __mavlink_cascaded_cmd_t {
 uint64_t time_usec; /*<  Timestamp (micros since boot or Unix epoch)*/
 float thrust; /*<  Thrust (N)*/
 float current_yaw; /*<  Current system heading in world (yaw)*/
 float q[4]; /*<  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)*/
 float ang_vel[3]; /*<  Angular velocity about body axes (x, y, z)*/
 float ang_acc[3]; /*<  Angular velocity about body axes (x, y, z)*/
 uint8_t target_system; /*<  Target system*/
} mavlink_cascaded_cmd_t;

#define MAVLINK_MSG_ID_CASCADED_CMD_LEN 57
#define MAVLINK_MSG_ID_CASCADED_CMD_MIN_LEN 57
#define MAVLINK_MSG_ID_424_LEN 57
#define MAVLINK_MSG_ID_424_MIN_LEN 57

#define MAVLINK_MSG_ID_CASCADED_CMD_CRC 109
#define MAVLINK_MSG_ID_424_CRC 109

#define MAVLINK_MSG_CASCADED_CMD_FIELD_Q_LEN 4
#define MAVLINK_MSG_CASCADED_CMD_FIELD_ANG_VEL_LEN 3
#define MAVLINK_MSG_CASCADED_CMD_FIELD_ANG_ACC_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CASCADED_CMD { \
    424, \
    "CASCADED_CMD", \
    7, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_cascaded_cmd_t, time_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_cascaded_cmd_t, target_system) }, \
         { "thrust", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_cascaded_cmd_t, thrust) }, \
         { "current_yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_cascaded_cmd_t, current_yaw) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 16, offsetof(mavlink_cascaded_cmd_t, q) }, \
         { "ang_vel", NULL, MAVLINK_TYPE_FLOAT, 3, 32, offsetof(mavlink_cascaded_cmd_t, ang_vel) }, \
         { "ang_acc", NULL, MAVLINK_TYPE_FLOAT, 3, 44, offsetof(mavlink_cascaded_cmd_t, ang_acc) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CASCADED_CMD { \
    "CASCADED_CMD", \
    7, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_cascaded_cmd_t, time_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_cascaded_cmd_t, target_system) }, \
         { "thrust", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_cascaded_cmd_t, thrust) }, \
         { "current_yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_cascaded_cmd_t, current_yaw) }, \
         { "q", NULL, MAVLINK_TYPE_FLOAT, 4, 16, offsetof(mavlink_cascaded_cmd_t, q) }, \
         { "ang_vel", NULL, MAVLINK_TYPE_FLOAT, 3, 32, offsetof(mavlink_cascaded_cmd_t, ang_vel) }, \
         { "ang_acc", NULL, MAVLINK_TYPE_FLOAT, 3, 44, offsetof(mavlink_cascaded_cmd_t, ang_acc) }, \
         } \
}
#endif

/**
 * @brief Pack a cascaded_cmd message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param target_system  Target system
 * @param thrust  Thrust (N)
 * @param current_yaw  Current system heading in world (yaw)
 * @param q  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @param ang_vel  Angular velocity about body axes (x, y, z)
 * @param ang_acc  Angular velocity about body axes (x, y, z)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cascaded_cmd_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t target_system, float thrust, float current_yaw, const float *q, const float *ang_vel, const float *ang_acc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CASCADED_CMD_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, thrust);
    _mav_put_float(buf, 12, current_yaw);
    _mav_put_uint8_t(buf, 56, target_system);
    _mav_put_float_array(buf, 16, q, 4);
    _mav_put_float_array(buf, 32, ang_vel, 3);
    _mav_put_float_array(buf, 44, ang_acc, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CASCADED_CMD_LEN);
#else
    mavlink_cascaded_cmd_t packet;
    packet.time_usec = time_usec;
    packet.thrust = thrust;
    packet.current_yaw = current_yaw;
    packet.target_system = target_system;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
    mav_array_memcpy(packet.ang_vel, ang_vel, sizeof(float)*3);
    mav_array_memcpy(packet.ang_acc, ang_acc, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CASCADED_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CASCADED_CMD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CASCADED_CMD_MIN_LEN, MAVLINK_MSG_ID_CASCADED_CMD_LEN, MAVLINK_MSG_ID_CASCADED_CMD_CRC);
}

/**
 * @brief Pack a cascaded_cmd message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param target_system  Target system
 * @param thrust  Thrust (N)
 * @param current_yaw  Current system heading in world (yaw)
 * @param q  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @param ang_vel  Angular velocity about body axes (x, y, z)
 * @param ang_acc  Angular velocity about body axes (x, y, z)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cascaded_cmd_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t target_system,float thrust,float current_yaw,const float *q,const float *ang_vel,const float *ang_acc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CASCADED_CMD_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, thrust);
    _mav_put_float(buf, 12, current_yaw);
    _mav_put_uint8_t(buf, 56, target_system);
    _mav_put_float_array(buf, 16, q, 4);
    _mav_put_float_array(buf, 32, ang_vel, 3);
    _mav_put_float_array(buf, 44, ang_acc, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CASCADED_CMD_LEN);
#else
    mavlink_cascaded_cmd_t packet;
    packet.time_usec = time_usec;
    packet.thrust = thrust;
    packet.current_yaw = current_yaw;
    packet.target_system = target_system;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
    mav_array_memcpy(packet.ang_vel, ang_vel, sizeof(float)*3);
    mav_array_memcpy(packet.ang_acc, ang_acc, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CASCADED_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CASCADED_CMD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CASCADED_CMD_MIN_LEN, MAVLINK_MSG_ID_CASCADED_CMD_LEN, MAVLINK_MSG_ID_CASCADED_CMD_CRC);
}

/**
 * @brief Encode a cascaded_cmd struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cascaded_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cascaded_cmd_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cascaded_cmd_t* cascaded_cmd)
{
    return mavlink_msg_cascaded_cmd_pack(system_id, component_id, msg, cascaded_cmd->time_usec, cascaded_cmd->target_system, cascaded_cmd->thrust, cascaded_cmd->current_yaw, cascaded_cmd->q, cascaded_cmd->ang_vel, cascaded_cmd->ang_acc);
}

/**
 * @brief Encode a cascaded_cmd struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cascaded_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cascaded_cmd_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cascaded_cmd_t* cascaded_cmd)
{
    return mavlink_msg_cascaded_cmd_pack_chan(system_id, component_id, chan, msg, cascaded_cmd->time_usec, cascaded_cmd->target_system, cascaded_cmd->thrust, cascaded_cmd->current_yaw, cascaded_cmd->q, cascaded_cmd->ang_vel, cascaded_cmd->ang_acc);
}

/**
 * @brief Send a cascaded_cmd message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param target_system  Target system
 * @param thrust  Thrust (N)
 * @param current_yaw  Current system heading in world (yaw)
 * @param q  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 * @param ang_vel  Angular velocity about body axes (x, y, z)
 * @param ang_acc  Angular velocity about body axes (x, y, z)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cascaded_cmd_send(mavlink_channel_t chan, uint64_t time_usec, uint8_t target_system, float thrust, float current_yaw, const float *q, const float *ang_vel, const float *ang_acc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CASCADED_CMD_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, thrust);
    _mav_put_float(buf, 12, current_yaw);
    _mav_put_uint8_t(buf, 56, target_system);
    _mav_put_float_array(buf, 16, q, 4);
    _mav_put_float_array(buf, 32, ang_vel, 3);
    _mav_put_float_array(buf, 44, ang_acc, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CASCADED_CMD, buf, MAVLINK_MSG_ID_CASCADED_CMD_MIN_LEN, MAVLINK_MSG_ID_CASCADED_CMD_LEN, MAVLINK_MSG_ID_CASCADED_CMD_CRC);
#else
    mavlink_cascaded_cmd_t packet;
    packet.time_usec = time_usec;
    packet.thrust = thrust;
    packet.current_yaw = current_yaw;
    packet.target_system = target_system;
    mav_array_memcpy(packet.q, q, sizeof(float)*4);
    mav_array_memcpy(packet.ang_vel, ang_vel, sizeof(float)*3);
    mav_array_memcpy(packet.ang_acc, ang_acc, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CASCADED_CMD, (const char *)&packet, MAVLINK_MSG_ID_CASCADED_CMD_MIN_LEN, MAVLINK_MSG_ID_CASCADED_CMD_LEN, MAVLINK_MSG_ID_CASCADED_CMD_CRC);
#endif
}

/**
 * @brief Send a cascaded_cmd message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cascaded_cmd_send_struct(mavlink_channel_t chan, const mavlink_cascaded_cmd_t* cascaded_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cascaded_cmd_send(chan, cascaded_cmd->time_usec, cascaded_cmd->target_system, cascaded_cmd->thrust, cascaded_cmd->current_yaw, cascaded_cmd->q, cascaded_cmd->ang_vel, cascaded_cmd->ang_acc);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CASCADED_CMD, (const char *)cascaded_cmd, MAVLINK_MSG_ID_CASCADED_CMD_MIN_LEN, MAVLINK_MSG_ID_CASCADED_CMD_LEN, MAVLINK_MSG_ID_CASCADED_CMD_CRC);
#endif
}

#if MAVLINK_MSG_ID_CASCADED_CMD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cascaded_cmd_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint8_t target_system, float thrust, float current_yaw, const float *q, const float *ang_vel, const float *ang_acc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 8, thrust);
    _mav_put_float(buf, 12, current_yaw);
    _mav_put_uint8_t(buf, 56, target_system);
    _mav_put_float_array(buf, 16, q, 4);
    _mav_put_float_array(buf, 32, ang_vel, 3);
    _mav_put_float_array(buf, 44, ang_acc, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CASCADED_CMD, buf, MAVLINK_MSG_ID_CASCADED_CMD_MIN_LEN, MAVLINK_MSG_ID_CASCADED_CMD_LEN, MAVLINK_MSG_ID_CASCADED_CMD_CRC);
#else
    mavlink_cascaded_cmd_t *packet = (mavlink_cascaded_cmd_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->thrust = thrust;
    packet->current_yaw = current_yaw;
    packet->target_system = target_system;
    mav_array_memcpy(packet->q, q, sizeof(float)*4);
    mav_array_memcpy(packet->ang_vel, ang_vel, sizeof(float)*3);
    mav_array_memcpy(packet->ang_acc, ang_acc, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CASCADED_CMD, (const char *)packet, MAVLINK_MSG_ID_CASCADED_CMD_MIN_LEN, MAVLINK_MSG_ID_CASCADED_CMD_LEN, MAVLINK_MSG_ID_CASCADED_CMD_CRC);
#endif
}
#endif

#endif

// MESSAGE CASCADED_CMD UNPACKING


/**
 * @brief Get field time_usec from cascaded_cmd message
 *
 * @return  Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_cascaded_cmd_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field target_system from cascaded_cmd message
 *
 * @return  Target system
 */
static inline uint8_t mavlink_msg_cascaded_cmd_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  56);
}

/**
 * @brief Get field thrust from cascaded_cmd message
 *
 * @return  Thrust (N)
 */
static inline float mavlink_msg_cascaded_cmd_get_thrust(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field current_yaw from cascaded_cmd message
 *
 * @return  Current system heading in world (yaw)
 */
static inline float mavlink_msg_cascaded_cmd_get_current_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field q from cascaded_cmd message
 *
 * @return  Attitude quaternion (w, x, y, z order, zero-rotation is 1, 0, 0, 0)
 */
static inline uint16_t mavlink_msg_cascaded_cmd_get_q(const mavlink_message_t* msg, float *q)
{
    return _MAV_RETURN_float_array(msg, q, 4,  16);
}

/**
 * @brief Get field ang_vel from cascaded_cmd message
 *
 * @return  Angular velocity about body axes (x, y, z)
 */
static inline uint16_t mavlink_msg_cascaded_cmd_get_ang_vel(const mavlink_message_t* msg, float *ang_vel)
{
    return _MAV_RETURN_float_array(msg, ang_vel, 3,  32);
}

/**
 * @brief Get field ang_acc from cascaded_cmd message
 *
 * @return  Angular velocity about body axes (x, y, z)
 */
static inline uint16_t mavlink_msg_cascaded_cmd_get_ang_acc(const mavlink_message_t* msg, float *ang_acc)
{
    return _MAV_RETURN_float_array(msg, ang_acc, 3,  44);
}

/**
 * @brief Decode a cascaded_cmd message into a struct
 *
 * @param msg The message to decode
 * @param cascaded_cmd C-struct to decode the message contents into
 */
static inline void mavlink_msg_cascaded_cmd_decode(const mavlink_message_t* msg, mavlink_cascaded_cmd_t* cascaded_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cascaded_cmd->time_usec = mavlink_msg_cascaded_cmd_get_time_usec(msg);
    cascaded_cmd->thrust = mavlink_msg_cascaded_cmd_get_thrust(msg);
    cascaded_cmd->current_yaw = mavlink_msg_cascaded_cmd_get_current_yaw(msg);
    mavlink_msg_cascaded_cmd_get_q(msg, cascaded_cmd->q);
    mavlink_msg_cascaded_cmd_get_ang_vel(msg, cascaded_cmd->ang_vel);
    mavlink_msg_cascaded_cmd_get_ang_acc(msg, cascaded_cmd->ang_acc);
    cascaded_cmd->target_system = mavlink_msg_cascaded_cmd_get_target_system(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CASCADED_CMD_LEN? msg->len : MAVLINK_MSG_ID_CASCADED_CMD_LEN;
        memset(cascaded_cmd, 0, MAVLINK_MSG_ID_CASCADED_CMD_LEN);
    memcpy(cascaded_cmd, _MAV_PAYLOAD(msg), len);
#endif
}
