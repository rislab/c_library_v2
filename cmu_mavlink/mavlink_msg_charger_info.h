#pragma once
// MESSAGE CHARGER_INFO PACKING

#define MAVLINK_MSG_ID_CHARGER_INFO 220

MAVPACKED(
typedef struct __mavlink_charger_info_t {
 uint64_t time_usec; /*< Timestamp (micros since boot or Unix epoch)*/
 int32_t voltage; /*< Voltage from UPS sensor*/
 int32_t ups_current; /*< Current from UPS sensor*/
 int32_t hss_current; /*< Current from HSS sensor*/
 uint8_t target_system; /*< Target system*/
 uint8_t gpio_status; /*< status of GPIO on HSS*/
}) mavlink_charger_info_t;

#define MAVLINK_MSG_ID_CHARGER_INFO_LEN 22
#define MAVLINK_MSG_ID_CHARGER_INFO_MIN_LEN 22
#define MAVLINK_MSG_ID_220_LEN 22
#define MAVLINK_MSG_ID_220_MIN_LEN 22

#define MAVLINK_MSG_ID_CHARGER_INFO_CRC 50
#define MAVLINK_MSG_ID_220_CRC 50



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CHARGER_INFO { \
    220, \
    "CHARGER_INFO", \
    6, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_charger_info_t, time_usec) }, \
         { "voltage", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_charger_info_t, voltage) }, \
         { "ups_current", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_charger_info_t, ups_current) }, \
         { "hss_current", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_charger_info_t, hss_current) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_charger_info_t, target_system) }, \
         { "gpio_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_charger_info_t, gpio_status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CHARGER_INFO { \
    "CHARGER_INFO", \
    6, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_charger_info_t, time_usec) }, \
         { "voltage", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_charger_info_t, voltage) }, \
         { "ups_current", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_charger_info_t, ups_current) }, \
         { "hss_current", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_charger_info_t, hss_current) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_charger_info_t, target_system) }, \
         { "gpio_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_charger_info_t, gpio_status) }, \
         } \
}
#endif

/**
 * @brief Pack a charger_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param target_system Target system
 * @param voltage Voltage from UPS sensor
 * @param ups_current Current from UPS sensor
 * @param hss_current Current from HSS sensor
 * @param gpio_status status of GPIO on HSS
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_charger_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t target_system, int32_t voltage, int32_t ups_current, int32_t hss_current, uint8_t gpio_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHARGER_INFO_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, voltage);
    _mav_put_int32_t(buf, 12, ups_current);
    _mav_put_int32_t(buf, 16, hss_current);
    _mav_put_uint8_t(buf, 20, target_system);
    _mav_put_uint8_t(buf, 21, gpio_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHARGER_INFO_LEN);
#else
    mavlink_charger_info_t packet;
    packet.time_usec = time_usec;
    packet.voltage = voltage;
    packet.ups_current = ups_current;
    packet.hss_current = hss_current;
    packet.target_system = target_system;
    packet.gpio_status = gpio_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CHARGER_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CHARGER_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CHARGER_INFO_MIN_LEN, MAVLINK_MSG_ID_CHARGER_INFO_LEN, MAVLINK_MSG_ID_CHARGER_INFO_CRC);
}

/**
 * @brief Pack a charger_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param target_system Target system
 * @param voltage Voltage from UPS sensor
 * @param ups_current Current from UPS sensor
 * @param hss_current Current from HSS sensor
 * @param gpio_status status of GPIO on HSS
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_charger_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t target_system,int32_t voltage,int32_t ups_current,int32_t hss_current,uint8_t gpio_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHARGER_INFO_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, voltage);
    _mav_put_int32_t(buf, 12, ups_current);
    _mav_put_int32_t(buf, 16, hss_current);
    _mav_put_uint8_t(buf, 20, target_system);
    _mav_put_uint8_t(buf, 21, gpio_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHARGER_INFO_LEN);
#else
    mavlink_charger_info_t packet;
    packet.time_usec = time_usec;
    packet.voltage = voltage;
    packet.ups_current = ups_current;
    packet.hss_current = hss_current;
    packet.target_system = target_system;
    packet.gpio_status = gpio_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CHARGER_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CHARGER_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CHARGER_INFO_MIN_LEN, MAVLINK_MSG_ID_CHARGER_INFO_LEN, MAVLINK_MSG_ID_CHARGER_INFO_CRC);
}

/**
 * @brief Encode a charger_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param charger_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_charger_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_charger_info_t* charger_info)
{
    return mavlink_msg_charger_info_pack(system_id, component_id, msg, charger_info->time_usec, charger_info->target_system, charger_info->voltage, charger_info->ups_current, charger_info->hss_current, charger_info->gpio_status);
}

/**
 * @brief Encode a charger_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param charger_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_charger_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_charger_info_t* charger_info)
{
    return mavlink_msg_charger_info_pack_chan(system_id, component_id, chan, msg, charger_info->time_usec, charger_info->target_system, charger_info->voltage, charger_info->ups_current, charger_info->hss_current, charger_info->gpio_status);
}

/**
 * @brief Send a charger_info message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param target_system Target system
 * @param voltage Voltage from UPS sensor
 * @param ups_current Current from UPS sensor
 * @param hss_current Current from HSS sensor
 * @param gpio_status status of GPIO on HSS
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_charger_info_send(mavlink_channel_t chan, uint64_t time_usec, uint8_t target_system, int32_t voltage, int32_t ups_current, int32_t hss_current, uint8_t gpio_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHARGER_INFO_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, voltage);
    _mav_put_int32_t(buf, 12, ups_current);
    _mav_put_int32_t(buf, 16, hss_current);
    _mav_put_uint8_t(buf, 20, target_system);
    _mav_put_uint8_t(buf, 21, gpio_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHARGER_INFO, buf, MAVLINK_MSG_ID_CHARGER_INFO_MIN_LEN, MAVLINK_MSG_ID_CHARGER_INFO_LEN, MAVLINK_MSG_ID_CHARGER_INFO_CRC);
#else
    mavlink_charger_info_t packet;
    packet.time_usec = time_usec;
    packet.voltage = voltage;
    packet.ups_current = ups_current;
    packet.hss_current = hss_current;
    packet.target_system = target_system;
    packet.gpio_status = gpio_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHARGER_INFO, (const char *)&packet, MAVLINK_MSG_ID_CHARGER_INFO_MIN_LEN, MAVLINK_MSG_ID_CHARGER_INFO_LEN, MAVLINK_MSG_ID_CHARGER_INFO_CRC);
#endif
}

/**
 * @brief Send a charger_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_charger_info_send_struct(mavlink_channel_t chan, const mavlink_charger_info_t* charger_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_charger_info_send(chan, charger_info->time_usec, charger_info->target_system, charger_info->voltage, charger_info->ups_current, charger_info->hss_current, charger_info->gpio_status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHARGER_INFO, (const char *)charger_info, MAVLINK_MSG_ID_CHARGER_INFO_MIN_LEN, MAVLINK_MSG_ID_CHARGER_INFO_LEN, MAVLINK_MSG_ID_CHARGER_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_CHARGER_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_charger_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint8_t target_system, int32_t voltage, int32_t ups_current, int32_t hss_current, uint8_t gpio_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, voltage);
    _mav_put_int32_t(buf, 12, ups_current);
    _mav_put_int32_t(buf, 16, hss_current);
    _mav_put_uint8_t(buf, 20, target_system);
    _mav_put_uint8_t(buf, 21, gpio_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHARGER_INFO, buf, MAVLINK_MSG_ID_CHARGER_INFO_MIN_LEN, MAVLINK_MSG_ID_CHARGER_INFO_LEN, MAVLINK_MSG_ID_CHARGER_INFO_CRC);
#else
    mavlink_charger_info_t *packet = (mavlink_charger_info_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->voltage = voltage;
    packet->ups_current = ups_current;
    packet->hss_current = hss_current;
    packet->target_system = target_system;
    packet->gpio_status = gpio_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHARGER_INFO, (const char *)packet, MAVLINK_MSG_ID_CHARGER_INFO_MIN_LEN, MAVLINK_MSG_ID_CHARGER_INFO_LEN, MAVLINK_MSG_ID_CHARGER_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE CHARGER_INFO UNPACKING


/**
 * @brief Get field time_usec from charger_info message
 *
 * @return Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_charger_info_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field target_system from charger_info message
 *
 * @return Target system
 */
static inline uint8_t mavlink_msg_charger_info_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field voltage from charger_info message
 *
 * @return Voltage from UPS sensor
 */
static inline int32_t mavlink_msg_charger_info_get_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field ups_current from charger_info message
 *
 * @return Current from UPS sensor
 */
static inline int32_t mavlink_msg_charger_info_get_ups_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field hss_current from charger_info message
 *
 * @return Current from HSS sensor
 */
static inline int32_t mavlink_msg_charger_info_get_hss_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field gpio_status from charger_info message
 *
 * @return status of GPIO on HSS
 */
static inline uint8_t mavlink_msg_charger_info_get_gpio_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  21);
}

/**
 * @brief Decode a charger_info message into a struct
 *
 * @param msg The message to decode
 * @param charger_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_charger_info_decode(const mavlink_message_t* msg, mavlink_charger_info_t* charger_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    charger_info->time_usec = mavlink_msg_charger_info_get_time_usec(msg);
    charger_info->voltage = mavlink_msg_charger_info_get_voltage(msg);
    charger_info->ups_current = mavlink_msg_charger_info_get_ups_current(msg);
    charger_info->hss_current = mavlink_msg_charger_info_get_hss_current(msg);
    charger_info->target_system = mavlink_msg_charger_info_get_target_system(msg);
    charger_info->gpio_status = mavlink_msg_charger_info_get_gpio_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CHARGER_INFO_LEN? msg->len : MAVLINK_MSG_ID_CHARGER_INFO_LEN;
        memset(charger_info, 0, MAVLINK_MSG_ID_CHARGER_INFO_LEN);
    memcpy(charger_info, _MAV_PAYLOAD(msg), len);
#endif
}
