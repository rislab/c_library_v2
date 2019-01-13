#pragma once
// MESSAGE PWM_FINAL_INPUT PACKING

#define MAVLINK_MSG_ID_PWM_FINAL_INPUT 223

MAVPACKED(
typedef struct __mavlink_pwm_final_input_t {
 uint64_t timestamp; /*< Timestamp of the message in used*/     
 float pwm_final[8]; /*< Final PWM input passed to IOCTL */                          
 uint16_t seq_id; /*< Sequence id of data*/                                       // 2
}) mavlink_pwm_final_input_t;                                                        

#define MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN 42
#define MAVLINK_MSG_ID_PWM_FINAL_INPUT_MIN_LEN 42
#define MAVLINK_MSG_ID_223_LEN 42
#define MAVLINK_MSG_ID_223_MIN_LEN 42

#define MAVLINK_MSG_ID_PWM_FINAL_INPUT_CRC 224
#define MAVLINK_MSG_ID_223_CRC 224

#define MAVLINK_MSG_PWM_FINAL_INPUT_FIELD_PWM_FINAL_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PWM_FINAL_INPUT { \
    223, \
    "PWM_FINAL_INPUT", \
    3, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_pwm_final_input_t, timestamp) }, \
         { "pwm_final", NULL, MAVLINK_TYPE_FLOAT, 8, 8, offsetof(mavlink_pwm_final_input_t, pwm_final) }, \
         { "seq_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_pwm_final_input_t, seq_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PWM_FINAL_INPUT { \
    "PWM_FINAL_INPUT", \
    3, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_pwm_final_input_t, timestamp) }, \
         { "pwm_final", NULL, MAVLINK_TYPE_FLOAT, 8, 8, offsetof(mavlink_pwm_final_input_t, pwm_final) }, \
         { "seq_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_pwm_final_input_t, seq_id) }, \
         } \
}
#endif

/**
 * @brief Pack a pwm_final_input message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp Timestamp of the message in used
 * @param seq_id Sequence id of data
 * @param pwm_final Final PWM inputs passed to the ESCs 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pwm_final_input_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint16_t seq_id, const float *pwm_final)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint16_t(buf, 40, seq_id);
    _mav_put_float_array(buf, 8, pwm_final, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN);
#else
    mavlink_pwm_final_input_t packet;
    packet.timestamp = timestamp;
    packet.seq_id = seq_id;
    mav_array_memcpy(packet.pwm_final, pwm_final, sizeof(float)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PWM_FINAL_INPUT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PWM_FINAL_INPUT_MIN_LEN, 
        MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN, MAVLINK_MSG_ID_PWM_FINAL_INPUT_CRC);
}

/**
 * @brief Pack a pwm_final_input message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp Timestamp of the message in used
 * @param seq_id Sequence id of data
 * @param pwm_final Final PWM inputs passed to the ESCs 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pwm_final_input_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp, uint16_t seq_id, const float *pwm_final)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint16_t(buf, 40, seq_id);
    _mav_put_float_array(buf, 8, pwm_final, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN);
#else
    mavlink_pwm_final_input_t packet;
    packet.timestamp = timestamp;
    packet.seq_id = seq_id;
    mav_array_memcpy(packet.pwm_final, pwm_final, sizeof(float)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PWM_FINAL_INPUT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PWM_FINAL_INPUT_MIN_LEN, 
        MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN, MAVLINK_MSG_ID_PWM_FINAL_INPUT_CRC);
}

/**
 * @brief Encode a pwm_final_input struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pwm_final_input C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pwm_final_input_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, 
    const mavlink_pwm_final_input_t* pwm_final_input) {
    return mavlink_msg_pwm_final_input_pack(system_id, component_id, msg, pwm_final_input->timestamp, 
        pwm_final_input->seq_id, pwm_final_input->pwm_final);
}

/**
 * @brief Encode a pwm_final_input struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pwm_final_input C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pwm_final_input_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, 
    mavlink_message_t* msg, const mavlink_pwm_final_input_t* pwm_final_input) {
    return mavlink_msg_pwm_final_input_pack_chan(system_id, component_id, chan, msg, 
        pwm_final_input->timestamp, pwm_final_input->seq_id, pwm_final_input->pwm_final);
}

/**
 * @brief Send a pwm_final_input message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp Timestamp of the message in used
 * @param seq_id Sequence id of data
 * @param pwm_final Final PWM inputs passed to the ESCs
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pwm_final_input_send(mavlink_channel_t chan, uint64_t timestamp, 
    uint16_t seq_id, const float *pwm_final)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint16_t(buf, 40, seq_id);
    _mav_put_float_array(buf, 8, pwm_final, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWM_FINAL_INPUT, buf, MAVLINK_MSG_ID_PWM_FINAL_INPUT_MIN_LEN, 
        MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN, MAVLINK_MSG_ID_PWM_FINAL_INPUT_CRC);
#else
    mavlink_pwm_final_input_t packet;
    packet.timestamp = timestamp;
    packet.seq_id = seq_id;
    mav_array_memcpy(packet.pwm_final, pwm_final, sizeof(float)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWM_FINAL_INPUT, (const char *)&packet, 
        MAVLINK_MSG_ID_PWM_FINAL_INPUT_MIN_LEN, MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN, 
        MAVLINK_MSG_ID_PWM_FINAL_INPUT_CRC);
#endif
}

/**
 * @brief Send a pwm_final_input message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pwm_final_input_send_struct(mavlink_channel_t chan, const mavlink_pwm_final_input_t* pwm_final_input)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pwm_final_input_send(chan, pwm_final_input->timestamp, pwm_final_input->seq_id, pwm_final_input->pwm_final);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWM_FINAL_INPUT, (const char *)pwm_final_input, 
        MAVLINK_MSG_ID_PWM_FINAL_INPUT_MIN_LEN, MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN, 
        MAVLINK_MSG_ID_PWM_FINAL_INPUT_CRC);
#endif
}

#if MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pwm_final_input_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  
    uint64_t timestamp, uint16_t seq_id, const float *pwm_final)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint16_t(buf, 40, seq_id);
    _mav_put_float_array(buf, 8, pwm_final, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWM_FINAL_INPUT, buf, 
        MAVLINK_MSG_ID_PWM_FINAL_INPUT_MIN_LEN, MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN, 
        MAVLINK_MSG_ID_PWM_FINAL_INPUT_CRC);
#else
    mavlink_pwm_final_input_t *packet = (mavlink_pwm_final_input_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->seq_id = seq_id;
    mav_array_memcpy(packet->pwm_final, pwm_final, sizeof(float)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PWM_FINAL_INPUT, (const char *)packet, 
        MAVLINK_MSG_ID_PWM_FINAL_INPUT_MIN_LEN, MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN, 
        MAVLINK_MSG_ID_PWM_FINAL_INPUT_CRC);
#endif
}
#endif

#endif

// MESSAGE PWM_FINAL_INPUT UNPACKING


/**
 * @brief Get field timestamp from pwm_final_input message
 *
 * @return Timestamp of the message in used
 */
static inline uint64_t mavlink_msg_pwm_final_input_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field seq_id from pwm_final_input message
 *
 * @return Sequence id of data
 */
static inline uint16_t mavlink_msg_pwm_final_input_get_seq_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  40);
}

/**
 * @brief Get field pwm_final from pwm_final_input message
 *
 * @return Final PWM inputs passed to the ESCs 
 */
static inline uint16_t mavlink_msg_pwm_final_input_get_pwm_final(const mavlink_message_t* msg, float *pwm_final)
{
    return _MAV_RETURN_float_array(msg, pwm_final, 8,  8);
}

/**
 * @brief Decode a pwm_final_input message into a struct
 *
 * @param msg The message to decode
 * @param pwm_final_input C-struct to decode the message contents into
 */
static inline void mavlink_msg_pwm_final_input_decode(const mavlink_message_t* msg, mavlink_pwm_final_input_t* pwm_final_input)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    pwm_final_input->timestamp = mavlink_msg_pwm_final_input_get_timestamp(msg);
    mavlink_msg_pwm_final_input_get_pwm_final(msg, pwm_final_input->pwm_final);
    pwm_final_input->seq_id = mavlink_msg_pwm_final_input_get_seq_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN? msg->len : MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN;
        memset(pwm_final_input, 0, MAVLINK_MSG_ID_PWM_FINAL_INPUT_LEN);
    memcpy(pwm_final_input, _MAV_PAYLOAD(msg), len);
#endif
}
