#pragma once
// MESSAGE MOCAP_MOTOR_STATE PACKING

#define MAVLINK_MSG_ID_MOCAP_MOTOR_STATE 426


typedef struct __mavlink_mocap_motor_state_t {
 uint64_t time_usec; /*<  Timestamp (micros since boot or Unix epoch)*/
 uint8_t target_system; /*<  Target system*/
 uint8_t state; /*<  Motor status (1 = on, 0 = off)*/
} mavlink_mocap_motor_state_t;

#define MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN 10
#define MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_MIN_LEN 10
#define MAVLINK_MSG_ID_426_LEN 10
#define MAVLINK_MSG_ID_426_MIN_LEN 10

#define MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_CRC 163
#define MAVLINK_MSG_ID_426_CRC 163



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MOCAP_MOTOR_STATE { \
    426, \
    "MOCAP_MOTOR_STATE", \
    3, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_mocap_motor_state_t, time_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_mocap_motor_state_t, target_system) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_mocap_motor_state_t, state) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MOCAP_MOTOR_STATE { \
    "MOCAP_MOTOR_STATE", \
    3, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_mocap_motor_state_t, time_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_mocap_motor_state_t, target_system) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_mocap_motor_state_t, state) }, \
         } \
}
#endif

/**
 * @brief Pack a mocap_motor_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param target_system  Target system
 * @param state  Motor status (1 = on, 0 = off)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mocap_motor_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t target_system, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN);
#else
    mavlink_mocap_motor_state_t packet;
    packet.time_usec = time_usec;
    packet.target_system = target_system;
    packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOCAP_MOTOR_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_MIN_LEN, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_CRC);
}

/**
 * @brief Pack a mocap_motor_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param target_system  Target system
 * @param state  Motor status (1 = on, 0 = off)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mocap_motor_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t target_system,uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN);
#else
    mavlink_mocap_motor_state_t packet;
    packet.time_usec = time_usec;
    packet.target_system = target_system;
    packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOCAP_MOTOR_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_MIN_LEN, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_CRC);
}

/**
 * @brief Encode a mocap_motor_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mocap_motor_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mocap_motor_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mocap_motor_state_t* mocap_motor_state)
{
    return mavlink_msg_mocap_motor_state_pack(system_id, component_id, msg, mocap_motor_state->time_usec, mocap_motor_state->target_system, mocap_motor_state->state);
}

/**
 * @brief Encode a mocap_motor_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mocap_motor_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mocap_motor_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mocap_motor_state_t* mocap_motor_state)
{
    return mavlink_msg_mocap_motor_state_pack_chan(system_id, component_id, chan, msg, mocap_motor_state->time_usec, mocap_motor_state->target_system, mocap_motor_state->state);
}

/**
 * @brief Send a mocap_motor_state message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param target_system  Target system
 * @param state  Motor status (1 = on, 0 = off)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mocap_motor_state_send(mavlink_channel_t chan, uint64_t time_usec, uint8_t target_system, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE, buf, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_MIN_LEN, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_CRC);
#else
    mavlink_mocap_motor_state_t packet;
    packet.time_usec = time_usec;
    packet.target_system = target_system;
    packet.state = state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE, (const char *)&packet, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_MIN_LEN, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_CRC);
#endif
}

/**
 * @brief Send a mocap_motor_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mocap_motor_state_send_struct(mavlink_channel_t chan, const mavlink_mocap_motor_state_t* mocap_motor_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mocap_motor_state_send(chan, mocap_motor_state->time_usec, mocap_motor_state->target_system, mocap_motor_state->state);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE, (const char *)mocap_motor_state, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_MIN_LEN, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mocap_motor_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint8_t target_system, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE, buf, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_MIN_LEN, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_CRC);
#else
    mavlink_mocap_motor_state_t *packet = (mavlink_mocap_motor_state_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->target_system = target_system;
    packet->state = state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE, (const char *)packet, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_MIN_LEN, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE MOCAP_MOTOR_STATE UNPACKING


/**
 * @brief Get field time_usec from mocap_motor_state message
 *
 * @return  Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_mocap_motor_state_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field target_system from mocap_motor_state message
 *
 * @return  Target system
 */
static inline uint8_t mavlink_msg_mocap_motor_state_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field state from mocap_motor_state message
 *
 * @return  Motor status (1 = on, 0 = off)
 */
static inline uint8_t mavlink_msg_mocap_motor_state_get_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Decode a mocap_motor_state message into a struct
 *
 * @param msg The message to decode
 * @param mocap_motor_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_mocap_motor_state_decode(const mavlink_message_t* msg, mavlink_mocap_motor_state_t* mocap_motor_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mocap_motor_state->time_usec = mavlink_msg_mocap_motor_state_get_time_usec(msg);
    mocap_motor_state->target_system = mavlink_msg_mocap_motor_state_get_target_system(msg);
    mocap_motor_state->state = mavlink_msg_mocap_motor_state_get_state(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN? msg->len : MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN;
        memset(mocap_motor_state, 0, MAVLINK_MSG_ID_MOCAP_MOTOR_STATE_LEN);
    memcpy(mocap_motor_state, _MAV_PAYLOAD(msg), len);
#endif
}
