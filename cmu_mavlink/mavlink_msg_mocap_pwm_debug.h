#pragma once
// MESSAGE MOCAP_PWM_DEBUG PACKING

#define MAVLINK_MSG_ID_MOCAP_PWM_DEBUG 436


typedef struct __mavlink_mocap_pwm_debug_t {
 uint64_t time_usec; /*<  Timestamp (micros since boot or Unix epoch)*/
 uint16_t pwms[8]; /*<  PWM*/
} mavlink_mocap_pwm_debug_t;

#define MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN 24
#define MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_MIN_LEN 24
#define MAVLINK_MSG_ID_436_LEN 24
#define MAVLINK_MSG_ID_436_MIN_LEN 24

#define MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_CRC 119
#define MAVLINK_MSG_ID_436_CRC 119

#define MAVLINK_MSG_MOCAP_PWM_DEBUG_FIELD_PWMS_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MOCAP_PWM_DEBUG { \
    436, \
    "MOCAP_PWM_DEBUG", \
    2, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_mocap_pwm_debug_t, time_usec) }, \
         { "pwms", NULL, MAVLINK_TYPE_UINT16_T, 8, 8, offsetof(mavlink_mocap_pwm_debug_t, pwms) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MOCAP_PWM_DEBUG { \
    "MOCAP_PWM_DEBUG", \
    2, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_mocap_pwm_debug_t, time_usec) }, \
         { "pwms", NULL, MAVLINK_TYPE_UINT16_T, 8, 8, offsetof(mavlink_mocap_pwm_debug_t, pwms) }, \
         } \
}
#endif

/**
 * @brief Pack a mocap_pwm_debug message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param pwms  PWM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mocap_pwm_debug_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const uint16_t *pwms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t_array(buf, 8, pwms, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN);
#else
    mavlink_mocap_pwm_debug_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.pwms, pwms, sizeof(uint16_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOCAP_PWM_DEBUG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_MIN_LEN, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_CRC);
}

/**
 * @brief Pack a mocap_pwm_debug message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param pwms  PWM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mocap_pwm_debug_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const uint16_t *pwms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t_array(buf, 8, pwms, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN);
#else
    mavlink_mocap_pwm_debug_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.pwms, pwms, sizeof(uint16_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MOCAP_PWM_DEBUG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_MIN_LEN, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_CRC);
}

/**
 * @brief Encode a mocap_pwm_debug struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mocap_pwm_debug C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mocap_pwm_debug_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mocap_pwm_debug_t* mocap_pwm_debug)
{
    return mavlink_msg_mocap_pwm_debug_pack(system_id, component_id, msg, mocap_pwm_debug->time_usec, mocap_pwm_debug->pwms);
}

/**
 * @brief Encode a mocap_pwm_debug struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mocap_pwm_debug C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mocap_pwm_debug_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mocap_pwm_debug_t* mocap_pwm_debug)
{
    return mavlink_msg_mocap_pwm_debug_pack_chan(system_id, component_id, chan, msg, mocap_pwm_debug->time_usec, mocap_pwm_debug->pwms);
}

/**
 * @brief Send a mocap_pwm_debug message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param pwms  PWM
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mocap_pwm_debug_send(mavlink_channel_t chan, uint64_t time_usec, const uint16_t *pwms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t_array(buf, 8, pwms, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG, buf, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_MIN_LEN, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_CRC);
#else
    mavlink_mocap_pwm_debug_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.pwms, pwms, sizeof(uint16_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG, (const char *)&packet, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_MIN_LEN, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_CRC);
#endif
}

/**
 * @brief Send a mocap_pwm_debug message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mocap_pwm_debug_send_struct(mavlink_channel_t chan, const mavlink_mocap_pwm_debug_t* mocap_pwm_debug)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mocap_pwm_debug_send(chan, mocap_pwm_debug->time_usec, mocap_pwm_debug->pwms);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG, (const char *)mocap_pwm_debug, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_MIN_LEN, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_CRC);
#endif
}

#if MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mocap_pwm_debug_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const uint16_t *pwms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint16_t_array(buf, 8, pwms, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG, buf, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_MIN_LEN, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_CRC);
#else
    mavlink_mocap_pwm_debug_t *packet = (mavlink_mocap_pwm_debug_t *)msgbuf;
    packet->time_usec = time_usec;
    mav_array_memcpy(packet->pwms, pwms, sizeof(uint16_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG, (const char *)packet, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_MIN_LEN, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_CRC);
#endif
}
#endif

#endif

// MESSAGE MOCAP_PWM_DEBUG UNPACKING


/**
 * @brief Get field time_usec from mocap_pwm_debug message
 *
 * @return  Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_mocap_pwm_debug_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field pwms from mocap_pwm_debug message
 *
 * @return  PWM
 */
static inline uint16_t mavlink_msg_mocap_pwm_debug_get_pwms(const mavlink_message_t* msg, uint16_t *pwms)
{
    return _MAV_RETURN_uint16_t_array(msg, pwms, 8,  8);
}

/**
 * @brief Decode a mocap_pwm_debug message into a struct
 *
 * @param msg The message to decode
 * @param mocap_pwm_debug C-struct to decode the message contents into
 */
static inline void mavlink_msg_mocap_pwm_debug_decode(const mavlink_message_t* msg, mavlink_mocap_pwm_debug_t* mocap_pwm_debug)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mocap_pwm_debug->time_usec = mavlink_msg_mocap_pwm_debug_get_time_usec(msg);
    mavlink_msg_mocap_pwm_debug_get_pwms(msg, mocap_pwm_debug->pwms);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN? msg->len : MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN;
        memset(mocap_pwm_debug, 0, MAVLINK_MSG_ID_MOCAP_PWM_DEBUG_LEN);
    memcpy(mocap_pwm_debug, _MAV_PAYLOAD(msg), len);
#endif
}
