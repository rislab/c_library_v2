#pragma once
// MESSAGE CHARGER_GPIO PACKING

#define MAVLINK_MSG_ID_CHARGER_GPIO 221

MAVPACKED(
typedef struct __mavlink_charger_gpio_t {
 uint64_t time_usec; /*< Timestamp (micros since boot or Unix epoch)*/
 uint8_t target_system; /*< Target system*/
 uint8_t on; /*< toggle GPIO on or off*/
}) mavlink_charger_gpio_t;

#define MAVLINK_MSG_ID_CHARGER_GPIO_LEN 10
#define MAVLINK_MSG_ID_CHARGER_GPIO_MIN_LEN 10
#define MAVLINK_MSG_ID_221_LEN 10
#define MAVLINK_MSG_ID_221_MIN_LEN 10

#define MAVLINK_MSG_ID_CHARGER_GPIO_CRC 54
#define MAVLINK_MSG_ID_221_CRC 54



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CHARGER_GPIO { \
    221, \
    "CHARGER_GPIO", \
    3, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_charger_gpio_t, time_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_charger_gpio_t, target_system) }, \
         { "on", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_charger_gpio_t, on) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CHARGER_GPIO { \
    "CHARGER_GPIO", \
    3, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_charger_gpio_t, time_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_charger_gpio_t, target_system) }, \
         { "on", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_charger_gpio_t, on) }, \
         } \
}
#endif

/**
 * @brief Pack a charger_gpio message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param target_system Target system
 * @param on toggle GPIO on or off
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_charger_gpio_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t target_system, uint8_t on)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHARGER_GPIO_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, on);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHARGER_GPIO_LEN);
#else
    mavlink_charger_gpio_t packet;
    packet.time_usec = time_usec;
    packet.target_system = target_system;
    packet.on = on;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CHARGER_GPIO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CHARGER_GPIO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CHARGER_GPIO_MIN_LEN, MAVLINK_MSG_ID_CHARGER_GPIO_LEN, MAVLINK_MSG_ID_CHARGER_GPIO_CRC);
}

/**
 * @brief Pack a charger_gpio message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param target_system Target system
 * @param on toggle GPIO on or off
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_charger_gpio_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t target_system,uint8_t on)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHARGER_GPIO_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, on);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CHARGER_GPIO_LEN);
#else
    mavlink_charger_gpio_t packet;
    packet.time_usec = time_usec;
    packet.target_system = target_system;
    packet.on = on;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CHARGER_GPIO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CHARGER_GPIO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CHARGER_GPIO_MIN_LEN, MAVLINK_MSG_ID_CHARGER_GPIO_LEN, MAVLINK_MSG_ID_CHARGER_GPIO_CRC);
}

/**
 * @brief Encode a charger_gpio struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param charger_gpio C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_charger_gpio_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_charger_gpio_t* charger_gpio)
{
    return mavlink_msg_charger_gpio_pack(system_id, component_id, msg, charger_gpio->time_usec, charger_gpio->target_system, charger_gpio->on);
}

/**
 * @brief Encode a charger_gpio struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param charger_gpio C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_charger_gpio_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_charger_gpio_t* charger_gpio)
{
    return mavlink_msg_charger_gpio_pack_chan(system_id, component_id, chan, msg, charger_gpio->time_usec, charger_gpio->target_system, charger_gpio->on);
}

/**
 * @brief Send a charger_gpio message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param target_system Target system
 * @param on toggle GPIO on or off
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_charger_gpio_send(mavlink_channel_t chan, uint64_t time_usec, uint8_t target_system, uint8_t on)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CHARGER_GPIO_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, on);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHARGER_GPIO, buf, MAVLINK_MSG_ID_CHARGER_GPIO_MIN_LEN, MAVLINK_MSG_ID_CHARGER_GPIO_LEN, MAVLINK_MSG_ID_CHARGER_GPIO_CRC);
#else
    mavlink_charger_gpio_t packet;
    packet.time_usec = time_usec;
    packet.target_system = target_system;
    packet.on = on;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHARGER_GPIO, (const char *)&packet, MAVLINK_MSG_ID_CHARGER_GPIO_MIN_LEN, MAVLINK_MSG_ID_CHARGER_GPIO_LEN, MAVLINK_MSG_ID_CHARGER_GPIO_CRC);
#endif
}

/**
 * @brief Send a charger_gpio message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_charger_gpio_send_struct(mavlink_channel_t chan, const mavlink_charger_gpio_t* charger_gpio)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_charger_gpio_send(chan, charger_gpio->time_usec, charger_gpio->target_system, charger_gpio->on);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHARGER_GPIO, (const char *)charger_gpio, MAVLINK_MSG_ID_CHARGER_GPIO_MIN_LEN, MAVLINK_MSG_ID_CHARGER_GPIO_LEN, MAVLINK_MSG_ID_CHARGER_GPIO_CRC);
#endif
}

#if MAVLINK_MSG_ID_CHARGER_GPIO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_charger_gpio_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint8_t target_system, uint8_t on)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, on);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHARGER_GPIO, buf, MAVLINK_MSG_ID_CHARGER_GPIO_MIN_LEN, MAVLINK_MSG_ID_CHARGER_GPIO_LEN, MAVLINK_MSG_ID_CHARGER_GPIO_CRC);
#else
    mavlink_charger_gpio_t *packet = (mavlink_charger_gpio_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->target_system = target_system;
    packet->on = on;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CHARGER_GPIO, (const char *)packet, MAVLINK_MSG_ID_CHARGER_GPIO_MIN_LEN, MAVLINK_MSG_ID_CHARGER_GPIO_LEN, MAVLINK_MSG_ID_CHARGER_GPIO_CRC);
#endif
}
#endif

#endif

// MESSAGE CHARGER_GPIO UNPACKING


/**
 * @brief Get field time_usec from charger_gpio message
 *
 * @return Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_charger_gpio_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field target_system from charger_gpio message
 *
 * @return Target system
 */
static inline uint8_t mavlink_msg_charger_gpio_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field on from charger_gpio message
 *
 * @return toggle GPIO on or off
 */
static inline uint8_t mavlink_msg_charger_gpio_get_on(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Decode a charger_gpio message into a struct
 *
 * @param msg The message to decode
 * @param charger_gpio C-struct to decode the message contents into
 */
static inline void mavlink_msg_charger_gpio_decode(const mavlink_message_t* msg, mavlink_charger_gpio_t* charger_gpio)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    charger_gpio->time_usec = mavlink_msg_charger_gpio_get_time_usec(msg);
    charger_gpio->target_system = mavlink_msg_charger_gpio_get_target_system(msg);
    charger_gpio->on = mavlink_msg_charger_gpio_get_on(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CHARGER_GPIO_LEN? msg->len : MAVLINK_MSG_ID_CHARGER_GPIO_LEN;
        memset(charger_gpio, 0, MAVLINK_MSG_ID_CHARGER_GPIO_LEN);
    memcpy(charger_gpio, _MAV_PAYLOAD(msg), len);
#endif
}
