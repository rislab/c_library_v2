#pragma once
// MESSAGE ESC_STATUS PACKING

#define MAVLINK_MSG_ID_ESC_STATUS 224

MAVPACKED(
typedef struct __mavlink_esc_status_t {
 uint64_t time_usec; /*<  Timestamp (micros since boot or Unix epoch)*/
 float voltage[4]; /*<  Voltage*/
 float current[4]; /*<  Current*/
 uint16_t error_count[4]; /*<  Error counts*/
 int16_t rpm[4]; /*<  RPMs (can be negative)*/
 int16_t rpm_setpoint[4]; /*<  RPMs (can be negative)*/
 uint8_t temp[4]; /*<  Temperature*/
}) mavlink_esc_status_t;

#define MAVLINK_MSG_ID_ESC_STATUS_LEN 68
#define MAVLINK_MSG_ID_ESC_STATUS_MIN_LEN 68
#define MAVLINK_MSG_ID_224_LEN 68
#define MAVLINK_MSG_ID_224_MIN_LEN 68

#define MAVLINK_MSG_ID_ESC_STATUS_CRC 118
#define MAVLINK_MSG_ID_224_CRC 118

#define MAVLINK_MSG_ESC_STATUS_FIELD_VOLTAGE_LEN 4
#define MAVLINK_MSG_ESC_STATUS_FIELD_CURRENT_LEN 4
#define MAVLINK_MSG_ESC_STATUS_FIELD_ERROR_COUNT_LEN 4
#define MAVLINK_MSG_ESC_STATUS_FIELD_RPM_LEN 4
#define MAVLINK_MSG_ESC_STATUS_FIELD_RPM_SETPOINT_LEN 4
#define MAVLINK_MSG_ESC_STATUS_FIELD_TEMP_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ESC_STATUS { \
    224, \
    "ESC_STATUS", \
    7, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_esc_status_t, time_usec) }, \
         { "error_count", NULL, MAVLINK_TYPE_UINT16_T, 4, 40, offsetof(mavlink_esc_status_t, error_count) }, \
         { "voltage", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_esc_status_t, voltage) }, \
         { "current", NULL, MAVLINK_TYPE_FLOAT, 4, 24, offsetof(mavlink_esc_status_t, current) }, \
         { "temp", NULL, MAVLINK_TYPE_UINT8_T, 4, 64, offsetof(mavlink_esc_status_t, temp) }, \
         { "rpm", NULL, MAVLINK_TYPE_INT16_T, 4, 48, offsetof(mavlink_esc_status_t, rpm) }, \
         { "rpm_setpoint", NULL, MAVLINK_TYPE_INT16_T, 4, 56, offsetof(mavlink_esc_status_t, rpm_setpoint) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ESC_STATUS { \
    "ESC_STATUS", \
    7, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_esc_status_t, time_usec) }, \
         { "error_count", NULL, MAVLINK_TYPE_UINT16_T, 4, 40, offsetof(mavlink_esc_status_t, error_count) }, \
         { "voltage", NULL, MAVLINK_TYPE_FLOAT, 4, 8, offsetof(mavlink_esc_status_t, voltage) }, \
         { "current", NULL, MAVLINK_TYPE_FLOAT, 4, 24, offsetof(mavlink_esc_status_t, current) }, \
         { "temp", NULL, MAVLINK_TYPE_UINT8_T, 4, 64, offsetof(mavlink_esc_status_t, temp) }, \
         { "rpm", NULL, MAVLINK_TYPE_INT16_T, 4, 48, offsetof(mavlink_esc_status_t, rpm) }, \
         { "rpm_setpoint", NULL, MAVLINK_TYPE_INT16_T, 4, 56, offsetof(mavlink_esc_status_t, rpm_setpoint) }, \
         } \
}
#endif

/**
 * @brief Pack a esc_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param error_count  Error counts
 * @param voltage  Voltage
 * @param current  Current
 * @param temp  Temperature
 * @param rpm  RPMs (can be negative)
 * @param rpm_setpoint  RPMs (can be negative)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const uint16_t *error_count, const float *voltage, const float *current, const uint8_t *temp, const int16_t *rpm, const int16_t *rpm_setpoint)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, voltage, 4);
    _mav_put_float_array(buf, 24, current, 4);
    _mav_put_uint16_t_array(buf, 40, error_count, 4);
    _mav_put_int16_t_array(buf, 48, rpm, 4);
    _mav_put_int16_t_array(buf, 56, rpm_setpoint, 4);
    _mav_put_uint8_t_array(buf, 64, temp, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_STATUS_LEN);
#else
    mavlink_esc_status_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.voltage, voltage, sizeof(float)*4);
    mav_array_memcpy(packet.current, current, sizeof(float)*4);
    mav_array_memcpy(packet.error_count, error_count, sizeof(uint16_t)*4);
    mav_array_memcpy(packet.rpm, rpm, sizeof(int16_t)*4);
    mav_array_memcpy(packet.rpm_setpoint, rpm_setpoint, sizeof(int16_t)*4);
    mav_array_memcpy(packet.temp, temp, sizeof(uint8_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESC_STATUS_LEN, MAVLINK_MSG_ID_ESC_STATUS_CRC);
}

/**
 * @brief Pack a esc_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param error_count  Error counts
 * @param voltage  Voltage
 * @param current  Current
 * @param temp  Temperature
 * @param rpm  RPMs (can be negative)
 * @param rpm_setpoint  RPMs (can be negative)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esc_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const uint16_t *error_count,const float *voltage,const float *current,const uint8_t *temp,const int16_t *rpm,const int16_t *rpm_setpoint)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, voltage, 4);
    _mav_put_float_array(buf, 24, current, 4);
    _mav_put_uint16_t_array(buf, 40, error_count, 4);
    _mav_put_int16_t_array(buf, 48, rpm, 4);
    _mav_put_int16_t_array(buf, 56, rpm_setpoint, 4);
    _mav_put_uint8_t_array(buf, 64, temp, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESC_STATUS_LEN);
#else
    mavlink_esc_status_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.voltage, voltage, sizeof(float)*4);
    mav_array_memcpy(packet.current, current, sizeof(float)*4);
    mav_array_memcpy(packet.error_count, error_count, sizeof(uint16_t)*4);
    mav_array_memcpy(packet.rpm, rpm, sizeof(int16_t)*4);
    mav_array_memcpy(packet.rpm_setpoint, rpm_setpoint, sizeof(int16_t)*4);
    mav_array_memcpy(packet.temp, temp, sizeof(uint8_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESC_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESC_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESC_STATUS_LEN, MAVLINK_MSG_ID_ESC_STATUS_CRC);
}

/**
 * @brief Encode a esc_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param esc_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_esc_status_t* esc_status)
{
    return mavlink_msg_esc_status_pack(system_id, component_id, msg, esc_status->time_usec, esc_status->error_count, esc_status->voltage, esc_status->current, esc_status->temp, esc_status->rpm, esc_status->rpm_setpoint);
}

/**
 * @brief Encode a esc_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param esc_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esc_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_esc_status_t* esc_status)
{
    return mavlink_msg_esc_status_pack_chan(system_id, component_id, chan, msg, esc_status->time_usec, esc_status->error_count, esc_status->voltage, esc_status->current, esc_status->temp, esc_status->rpm, esc_status->rpm_setpoint);
}

/**
 * @brief Send a esc_status message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec  Timestamp (micros since boot or Unix epoch)
 * @param error_count  Error counts
 * @param voltage  Voltage
 * @param current  Current
 * @param temp  Temperature
 * @param rpm  RPMs (can be negative)
 * @param rpm_setpoint  RPMs (can be negative)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_esc_status_send(mavlink_channel_t chan, uint64_t time_usec, const uint16_t *error_count, const float *voltage, const float *current, const uint8_t *temp, const int16_t *rpm, const int16_t *rpm_setpoint)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESC_STATUS_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, voltage, 4);
    _mav_put_float_array(buf, 24, current, 4);
    _mav_put_uint16_t_array(buf, 40, error_count, 4);
    _mav_put_int16_t_array(buf, 48, rpm, 4);
    _mav_put_int16_t_array(buf, 56, rpm_setpoint, 4);
    _mav_put_uint8_t_array(buf, 64, temp, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_STATUS, buf, MAVLINK_MSG_ID_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESC_STATUS_LEN, MAVLINK_MSG_ID_ESC_STATUS_CRC);
#else
    mavlink_esc_status_t packet;
    packet.time_usec = time_usec;
    mav_array_memcpy(packet.voltage, voltage, sizeof(float)*4);
    mav_array_memcpy(packet.current, current, sizeof(float)*4);
    mav_array_memcpy(packet.error_count, error_count, sizeof(uint16_t)*4);
    mav_array_memcpy(packet.rpm, rpm, sizeof(int16_t)*4);
    mav_array_memcpy(packet.rpm_setpoint, rpm_setpoint, sizeof(int16_t)*4);
    mav_array_memcpy(packet.temp, temp, sizeof(uint8_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_STATUS, (const char *)&packet, MAVLINK_MSG_ID_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESC_STATUS_LEN, MAVLINK_MSG_ID_ESC_STATUS_CRC);
#endif
}

/**
 * @brief Send a esc_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_esc_status_send_struct(mavlink_channel_t chan, const mavlink_esc_status_t* esc_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_esc_status_send(chan, esc_status->time_usec, esc_status->error_count, esc_status->voltage, esc_status->current, esc_status->temp, esc_status->rpm, esc_status->rpm_setpoint);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_STATUS, (const char *)esc_status, MAVLINK_MSG_ID_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESC_STATUS_LEN, MAVLINK_MSG_ID_ESC_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_ESC_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_esc_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const uint16_t *error_count, const float *voltage, const float *current, const uint8_t *temp, const int16_t *rpm, const int16_t *rpm_setpoint)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float_array(buf, 8, voltage, 4);
    _mav_put_float_array(buf, 24, current, 4);
    _mav_put_uint16_t_array(buf, 40, error_count, 4);
    _mav_put_int16_t_array(buf, 48, rpm, 4);
    _mav_put_int16_t_array(buf, 56, rpm_setpoint, 4);
    _mav_put_uint8_t_array(buf, 64, temp, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_STATUS, buf, MAVLINK_MSG_ID_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESC_STATUS_LEN, MAVLINK_MSG_ID_ESC_STATUS_CRC);
#else
    mavlink_esc_status_t *packet = (mavlink_esc_status_t *)msgbuf;
    packet->time_usec = time_usec;
    mav_array_memcpy(packet->voltage, voltage, sizeof(float)*4);
    mav_array_memcpy(packet->current, current, sizeof(float)*4);
    mav_array_memcpy(packet->error_count, error_count, sizeof(uint16_t)*4);
    mav_array_memcpy(packet->rpm, rpm, sizeof(int16_t)*4);
    mav_array_memcpy(packet->rpm_setpoint, rpm_setpoint, sizeof(int16_t)*4);
    mav_array_memcpy(packet->temp, temp, sizeof(uint8_t)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESC_STATUS, (const char *)packet, MAVLINK_MSG_ID_ESC_STATUS_MIN_LEN, MAVLINK_MSG_ID_ESC_STATUS_LEN, MAVLINK_MSG_ID_ESC_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE ESC_STATUS UNPACKING


/**
 * @brief Get field time_usec from esc_status message
 *
 * @return  Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_esc_status_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field error_count from esc_status message
 *
 * @return  Error counts
 */
static inline uint16_t mavlink_msg_esc_status_get_error_count(const mavlink_message_t* msg, uint16_t *error_count)
{
    return _MAV_RETURN_uint16_t_array(msg, error_count, 4,  40);
}

/**
 * @brief Get field voltage from esc_status message
 *
 * @return  Voltage
 */
static inline uint16_t mavlink_msg_esc_status_get_voltage(const mavlink_message_t* msg, float *voltage)
{
    return _MAV_RETURN_float_array(msg, voltage, 4,  8);
}

/**
 * @brief Get field current from esc_status message
 *
 * @return  Current
 */
static inline uint16_t mavlink_msg_esc_status_get_current(const mavlink_message_t* msg, float *current)
{
    return _MAV_RETURN_float_array(msg, current, 4,  24);
}

/**
 * @brief Get field temp from esc_status message
 *
 * @return  Temperature
 */
static inline uint16_t mavlink_msg_esc_status_get_temp(const mavlink_message_t* msg, uint8_t *temp)
{
    return _MAV_RETURN_uint8_t_array(msg, temp, 4,  64);
}

/**
 * @brief Get field rpm from esc_status message
 *
 * @return  RPMs (can be negative)
 */
static inline uint16_t mavlink_msg_esc_status_get_rpm(const mavlink_message_t* msg, int16_t *rpm)
{
    return _MAV_RETURN_int16_t_array(msg, rpm, 4,  48);
}

/**
 * @brief Get field rpm_setpoint from esc_status message
 *
 * @return  RPMs (can be negative)
 */
static inline uint16_t mavlink_msg_esc_status_get_rpm_setpoint(const mavlink_message_t* msg, int16_t *rpm_setpoint)
{
    return _MAV_RETURN_int16_t_array(msg, rpm_setpoint, 4,  56);
}

/**
 * @brief Decode a esc_status message into a struct
 *
 * @param msg The message to decode
 * @param esc_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_esc_status_decode(const mavlink_message_t* msg, mavlink_esc_status_t* esc_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    esc_status->time_usec = mavlink_msg_esc_status_get_time_usec(msg);
    mavlink_msg_esc_status_get_voltage(msg, esc_status->voltage);
    mavlink_msg_esc_status_get_current(msg, esc_status->current);
    mavlink_msg_esc_status_get_error_count(msg, esc_status->error_count);
    mavlink_msg_esc_status_get_rpm(msg, esc_status->rpm);
    mavlink_msg_esc_status_get_rpm_setpoint(msg, esc_status->rpm_setpoint);
    mavlink_msg_esc_status_get_temp(msg, esc_status->temp);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ESC_STATUS_LEN? msg->len : MAVLINK_MSG_ID_ESC_STATUS_LEN;
        memset(esc_status, 0, MAVLINK_MSG_ID_ESC_STATUS_LEN);
    memcpy(esc_status, _MAV_PAYLOAD(msg), len);
#endif
}
