#pragma once
// MESSAGE ATT_CTRL_DEBUG PACKING

#define MAVLINK_MSG_ID_ATT_CTRL_DEBUG 223

MAVPACKED(
typedef struct __mavlink_att_ctrl_debug_t {
 uint64_t time_usec; /*< Timestamp (micros since boot or Unix epoch)*/
 float rpm[6]; /*< RPM values calculated from MocapAttitudeController for quadrotor*/
 float eOm[3]; /*< Angular velocity error*/
 float Omd[3]; /*< Desired angular velocity*/
 float eR[3]; /*< Orientation error*/
 float Rd[9]; /*< Desired orientation (populated in row-major order)*/
 float R[9]; /*< Actual orientation (populated in row-major order)*/
 float casc_cmd_dt; /*< Time difference between current and previously received cascaded commands*/
 float eRint[3]; /*< New orientation error*/
 float body_cmd_fbz; /*< Thrust component of cascaded command*/
}) mavlink_att_ctrl_debug_t;

#define MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN 160
#define MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN 160
#define MAVLINK_MSG_ID_223_LEN 160
#define MAVLINK_MSG_ID_223_MIN_LEN 160

#define MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC 106
#define MAVLINK_MSG_ID_223_CRC 106

#define MAVLINK_MSG_ATT_CTRL_DEBUG_FIELD_RPM_LEN 6
#define MAVLINK_MSG_ATT_CTRL_DEBUG_FIELD_EOM_LEN 3
#define MAVLINK_MSG_ATT_CTRL_DEBUG_FIELD_OMD_LEN 3
#define MAVLINK_MSG_ATT_CTRL_DEBUG_FIELD_ER_LEN 3
#define MAVLINK_MSG_ATT_CTRL_DEBUG_FIELD_RD_LEN 9
#define MAVLINK_MSG_ATT_CTRL_DEBUG_FIELD_R_LEN 9
#define MAVLINK_MSG_ATT_CTRL_DEBUG_FIELD_ERINT_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ATT_CTRL_DEBUG { \
    223, \
    "ATT_CTRL_DEBUG", \
    10, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_att_ctrl_debug_t, time_usec) }, \
         { "rpm", NULL, MAVLINK_TYPE_FLOAT, 6, 8, offsetof(mavlink_att_ctrl_debug_t, rpm) }, \
         { "eOm", NULL, MAVLINK_TYPE_FLOAT, 3, 32, offsetof(mavlink_att_ctrl_debug_t, eOm) }, \
         { "Omd", NULL, MAVLINK_TYPE_FLOAT, 3, 44, offsetof(mavlink_att_ctrl_debug_t, Omd) }, \
         { "eR", NULL, MAVLINK_TYPE_FLOAT, 3, 56, offsetof(mavlink_att_ctrl_debug_t, eR) }, \
         { "Rd", NULL, MAVLINK_TYPE_FLOAT, 9, 68, offsetof(mavlink_att_ctrl_debug_t, Rd) }, \
         { "R", NULL, MAVLINK_TYPE_FLOAT, 9, 104, offsetof(mavlink_att_ctrl_debug_t, R) }, \
         { "casc_cmd_dt", NULL, MAVLINK_TYPE_FLOAT, 0, 140, offsetof(mavlink_att_ctrl_debug_t, casc_cmd_dt) }, \
         { "eRint", NULL, MAVLINK_TYPE_FLOAT, 3, 144, offsetof(mavlink_att_ctrl_debug_t, eRint) }, \
         { "body_cmd_fbz", NULL, MAVLINK_TYPE_FLOAT, 0, 156, offsetof(mavlink_att_ctrl_debug_t, body_cmd_fbz) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ATT_CTRL_DEBUG { \
    "ATT_CTRL_DEBUG", \
    10, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_att_ctrl_debug_t, time_usec) }, \
         { "rpm", NULL, MAVLINK_TYPE_FLOAT, 6, 8, offsetof(mavlink_att_ctrl_debug_t, rpm) }, \
         { "eOm", NULL, MAVLINK_TYPE_FLOAT, 3, 32, offsetof(mavlink_att_ctrl_debug_t, eOm) }, \
         { "Omd", NULL, MAVLINK_TYPE_FLOAT, 3, 44, offsetof(mavlink_att_ctrl_debug_t, Omd) }, \
         { "eR", NULL, MAVLINK_TYPE_FLOAT, 3, 56, offsetof(mavlink_att_ctrl_debug_t, eR) }, \
         { "Rd", NULL, MAVLINK_TYPE_FLOAT, 9, 68, offsetof(mavlink_att_ctrl_debug_t, Rd) }, \
         { "R", NULL, MAVLINK_TYPE_FLOAT, 9, 104, offsetof(mavlink_att_ctrl_debug_t, R) }, \
         { "casc_cmd_dt", NULL, MAVLINK_TYPE_FLOAT, 0, 140, offsetof(mavlink_att_ctrl_debug_t, casc_cmd_dt) }, \
         { "eRint", NULL, MAVLINK_TYPE_FLOAT, 3, 144, offsetof(mavlink_att_ctrl_debug_t, eRint) }, \
         { "body_cmd_fbz", NULL, MAVLINK_TYPE_FLOAT, 0, 156, offsetof(mavlink_att_ctrl_debug_t, body_cmd_fbz) }, \
         } \
}
#endif

/**
 * @brief Pack a att_ctrl_debug message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param rpm RPM values calculated from MocapAttitudeController for quadrotor
 * @param eOm Angular velocity error
 * @param Omd Desired angular velocity
 * @param eR Orientation error
 * @param Rd Desired orientation (populated in row-major order)
 * @param R Actual orientation (populated in row-major order)
 * @param casc_cmd_dt Time difference between current and previously received cascaded commands
 * @param eRint New orientation error
 * @param body_cmd_fbz Thrust component of cascaded command
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, const float *rpm, const float *eOm, const float *Omd, const float *eR, const float *Rd, const float *R, float casc_cmd_dt, const float *eRint, float body_cmd_fbz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 140, casc_cmd_dt);
    _mav_put_float(buf, 156, body_cmd_fbz);
    _mav_put_float_array(buf, 8, rpm, 6);
    _mav_put_float_array(buf, 32, eOm, 3);
    _mav_put_float_array(buf, 44, Omd, 3);
    _mav_put_float_array(buf, 56, eR, 3);
    _mav_put_float_array(buf, 68, Rd, 9);
    _mav_put_float_array(buf, 104, R, 9);
    _mav_put_float_array(buf, 144, eRint, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN);
#else
    mavlink_att_ctrl_debug_t packet;
    packet.time_usec = time_usec;
    packet.casc_cmd_dt = casc_cmd_dt;
    packet.body_cmd_fbz = body_cmd_fbz;
    mav_array_memcpy(packet.rpm, rpm, sizeof(float)*6);
    mav_array_memcpy(packet.eOm, eOm, sizeof(float)*3);
    mav_array_memcpy(packet.Omd, Omd, sizeof(float)*3);
    mav_array_memcpy(packet.eR, eR, sizeof(float)*3);
    mav_array_memcpy(packet.Rd, Rd, sizeof(float)*9);
    mav_array_memcpy(packet.R, R, sizeof(float)*9);
    mav_array_memcpy(packet.eRint, eRint, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ATT_CTRL_DEBUG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
}

/**
 * @brief Pack a att_ctrl_debug message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param rpm RPM values calculated from MocapAttitudeController for quadrotor
 * @param eOm Angular velocity error
 * @param Omd Desired angular velocity
 * @param eR Orientation error
 * @param Rd Desired orientation (populated in row-major order)
 * @param R Actual orientation (populated in row-major order)
 * @param casc_cmd_dt Time difference between current and previously received cascaded commands
 * @param eRint New orientation error
 * @param body_cmd_fbz Thrust component of cascaded command
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,const float *rpm,const float *eOm,const float *Omd,const float *eR,const float *Rd,const float *R,float casc_cmd_dt,const float *eRint,float body_cmd_fbz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 140, casc_cmd_dt);
    _mav_put_float(buf, 156, body_cmd_fbz);
    _mav_put_float_array(buf, 8, rpm, 6);
    _mav_put_float_array(buf, 32, eOm, 3);
    _mav_put_float_array(buf, 44, Omd, 3);
    _mav_put_float_array(buf, 56, eR, 3);
    _mav_put_float_array(buf, 68, Rd, 9);
    _mav_put_float_array(buf, 104, R, 9);
    _mav_put_float_array(buf, 144, eRint, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN);
#else
    mavlink_att_ctrl_debug_t packet;
    packet.time_usec = time_usec;
    packet.casc_cmd_dt = casc_cmd_dt;
    packet.body_cmd_fbz = body_cmd_fbz;
    mav_array_memcpy(packet.rpm, rpm, sizeof(float)*6);
    mav_array_memcpy(packet.eOm, eOm, sizeof(float)*3);
    mav_array_memcpy(packet.Omd, Omd, sizeof(float)*3);
    mav_array_memcpy(packet.eR, eR, sizeof(float)*3);
    mav_array_memcpy(packet.Rd, Rd, sizeof(float)*9);
    mav_array_memcpy(packet.R, R, sizeof(float)*9);
    mav_array_memcpy(packet.eRint, eRint, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ATT_CTRL_DEBUG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
}

/**
 * @brief Encode a att_ctrl_debug struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param att_ctrl_debug C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_att_ctrl_debug_t* att_ctrl_debug)
{
    return mavlink_msg_att_ctrl_debug_pack(system_id, component_id, msg, att_ctrl_debug->time_usec, att_ctrl_debug->rpm, att_ctrl_debug->eOm, att_ctrl_debug->Omd, att_ctrl_debug->eR, att_ctrl_debug->Rd, att_ctrl_debug->R, att_ctrl_debug->casc_cmd_dt, att_ctrl_debug->eRint, att_ctrl_debug->body_cmd_fbz);
}

/**
 * @brief Encode a att_ctrl_debug struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param att_ctrl_debug C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_att_ctrl_debug_t* att_ctrl_debug)
{
    return mavlink_msg_att_ctrl_debug_pack_chan(system_id, component_id, chan, msg, att_ctrl_debug->time_usec, att_ctrl_debug->rpm, att_ctrl_debug->eOm, att_ctrl_debug->Omd, att_ctrl_debug->eR, att_ctrl_debug->Rd, att_ctrl_debug->R, att_ctrl_debug->casc_cmd_dt, att_ctrl_debug->eRint, att_ctrl_debug->body_cmd_fbz);
}

/**
 * @brief Send a att_ctrl_debug message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (micros since boot or Unix epoch)
 * @param rpm RPM values calculated from MocapAttitudeController for quadrotor
 * @param eOm Angular velocity error
 * @param Omd Desired angular velocity
 * @param eR Orientation error
 * @param Rd Desired orientation (populated in row-major order)
 * @param R Actual orientation (populated in row-major order)
 * @param casc_cmd_dt Time difference between current and previously received cascaded commands
 * @param eRint New orientation error
 * @param body_cmd_fbz Thrust component of cascaded command
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_att_ctrl_debug_send(mavlink_channel_t chan, uint64_t time_usec, const float *rpm, const float *eOm, const float *Omd, const float *eR, const float *Rd, const float *R, float casc_cmd_dt, const float *eRint, float body_cmd_fbz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 140, casc_cmd_dt);
    _mav_put_float(buf, 156, body_cmd_fbz);
    _mav_put_float_array(buf, 8, rpm, 6);
    _mav_put_float_array(buf, 32, eOm, 3);
    _mav_put_float_array(buf, 44, Omd, 3);
    _mav_put_float_array(buf, 56, eR, 3);
    _mav_put_float_array(buf, 68, Rd, 9);
    _mav_put_float_array(buf, 104, R, 9);
    _mav_put_float_array(buf, 144, eRint, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATT_CTRL_DEBUG, buf, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
#else
    mavlink_att_ctrl_debug_t packet;
    packet.time_usec = time_usec;
    packet.casc_cmd_dt = casc_cmd_dt;
    packet.body_cmd_fbz = body_cmd_fbz;
    mav_array_memcpy(packet.rpm, rpm, sizeof(float)*6);
    mav_array_memcpy(packet.eOm, eOm, sizeof(float)*3);
    mav_array_memcpy(packet.Omd, Omd, sizeof(float)*3);
    mav_array_memcpy(packet.eR, eR, sizeof(float)*3);
    mav_array_memcpy(packet.Rd, Rd, sizeof(float)*9);
    mav_array_memcpy(packet.R, R, sizeof(float)*9);
    mav_array_memcpy(packet.eRint, eRint, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATT_CTRL_DEBUG, (const char *)&packet, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
#endif
}

/**
 * @brief Send a att_ctrl_debug message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_att_ctrl_debug_send_struct(mavlink_channel_t chan, const mavlink_att_ctrl_debug_t* att_ctrl_debug)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_att_ctrl_debug_send(chan, att_ctrl_debug->time_usec, att_ctrl_debug->rpm, att_ctrl_debug->eOm, att_ctrl_debug->Omd, att_ctrl_debug->eR, att_ctrl_debug->Rd, att_ctrl_debug->R, att_ctrl_debug->casc_cmd_dt, att_ctrl_debug->eRint, att_ctrl_debug->body_cmd_fbz);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATT_CTRL_DEBUG, (const char *)att_ctrl_debug, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
#endif
}

#if MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_att_ctrl_debug_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, const float *rpm, const float *eOm, const float *Omd, const float *eR, const float *Rd, const float *R, float casc_cmd_dt, const float *eRint, float body_cmd_fbz)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_float(buf, 140, casc_cmd_dt);
    _mav_put_float(buf, 156, body_cmd_fbz);
    _mav_put_float_array(buf, 8, rpm, 6);
    _mav_put_float_array(buf, 32, eOm, 3);
    _mav_put_float_array(buf, 44, Omd, 3);
    _mav_put_float_array(buf, 56, eR, 3);
    _mav_put_float_array(buf, 68, Rd, 9);
    _mav_put_float_array(buf, 104, R, 9);
    _mav_put_float_array(buf, 144, eRint, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATT_CTRL_DEBUG, buf, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
#else
    mavlink_att_ctrl_debug_t *packet = (mavlink_att_ctrl_debug_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->casc_cmd_dt = casc_cmd_dt;
    packet->body_cmd_fbz = body_cmd_fbz;
    mav_array_memcpy(packet->rpm, rpm, sizeof(float)*6);
    mav_array_memcpy(packet->eOm, eOm, sizeof(float)*3);
    mav_array_memcpy(packet->Omd, Omd, sizeof(float)*3);
    mav_array_memcpy(packet->eR, eR, sizeof(float)*3);
    mav_array_memcpy(packet->Rd, Rd, sizeof(float)*9);
    mav_array_memcpy(packet->R, R, sizeof(float)*9);
    mav_array_memcpy(packet->eRint, eRint, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ATT_CTRL_DEBUG, (const char *)packet, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_MIN_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_CRC);
#endif
}
#endif

#endif

// MESSAGE ATT_CTRL_DEBUG UNPACKING


/**
 * @brief Get field time_usec from att_ctrl_debug message
 *
 * @return Timestamp (micros since boot or Unix epoch)
 */
static inline uint64_t mavlink_msg_att_ctrl_debug_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field rpm from att_ctrl_debug message
 *
 * @return RPM values calculated from MocapAttitudeController for quadrotor
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_get_rpm(const mavlink_message_t* msg, float *rpm)
{
    return _MAV_RETURN_float_array(msg, rpm, 6,  8);
}

/**
 * @brief Get field eOm from att_ctrl_debug message
 *
 * @return Angular velocity error
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_get_eOm(const mavlink_message_t* msg, float *eOm)
{
    return _MAV_RETURN_float_array(msg, eOm, 3,  32);
}

/**
 * @brief Get field Omd from att_ctrl_debug message
 *
 * @return Desired angular velocity
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_get_Omd(const mavlink_message_t* msg, float *Omd)
{
    return _MAV_RETURN_float_array(msg, Omd, 3,  44);
}

/**
 * @brief Get field eR from att_ctrl_debug message
 *
 * @return Orientation error
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_get_eR(const mavlink_message_t* msg, float *eR)
{
    return _MAV_RETURN_float_array(msg, eR, 3,  56);
}

/**
 * @brief Get field Rd from att_ctrl_debug message
 *
 * @return Desired orientation (populated in row-major order)
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_get_Rd(const mavlink_message_t* msg, float *Rd)
{
    return _MAV_RETURN_float_array(msg, Rd, 9,  68);
}

/**
 * @brief Get field R from att_ctrl_debug message
 *
 * @return Actual orientation (populated in row-major order)
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_get_R(const mavlink_message_t* msg, float *R)
{
    return _MAV_RETURN_float_array(msg, R, 9,  104);
}

/**
 * @brief Get field casc_cmd_dt from att_ctrl_debug message
 *
 * @return Time difference between current and previously received cascaded commands
 */
static inline float mavlink_msg_att_ctrl_debug_get_casc_cmd_dt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  140);
}

/**
 * @brief Get field eRint from att_ctrl_debug message
 *
 * @return New orientation error
 */
static inline uint16_t mavlink_msg_att_ctrl_debug_get_eRint(const mavlink_message_t* msg, float *eRint)
{
    return _MAV_RETURN_float_array(msg, eRint, 3,  144);
}

/**
 * @brief Get field body_cmd_fbz from att_ctrl_debug message
 *
 * @return Thrust component of cascaded command
 */
static inline float mavlink_msg_att_ctrl_debug_get_body_cmd_fbz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  156);
}

/**
 * @brief Decode a att_ctrl_debug message into a struct
 *
 * @param msg The message to decode
 * @param att_ctrl_debug C-struct to decode the message contents into
 */
static inline void mavlink_msg_att_ctrl_debug_decode(const mavlink_message_t* msg, mavlink_att_ctrl_debug_t* att_ctrl_debug)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    att_ctrl_debug->time_usec = mavlink_msg_att_ctrl_debug_get_time_usec(msg);
    mavlink_msg_att_ctrl_debug_get_rpm(msg, att_ctrl_debug->rpm);
    mavlink_msg_att_ctrl_debug_get_eOm(msg, att_ctrl_debug->eOm);
    mavlink_msg_att_ctrl_debug_get_Omd(msg, att_ctrl_debug->Omd);
    mavlink_msg_att_ctrl_debug_get_eR(msg, att_ctrl_debug->eR);
    mavlink_msg_att_ctrl_debug_get_Rd(msg, att_ctrl_debug->Rd);
    mavlink_msg_att_ctrl_debug_get_R(msg, att_ctrl_debug->R);
    att_ctrl_debug->casc_cmd_dt = mavlink_msg_att_ctrl_debug_get_casc_cmd_dt(msg);
    mavlink_msg_att_ctrl_debug_get_eRint(msg, att_ctrl_debug->eRint);
    att_ctrl_debug->body_cmd_fbz = mavlink_msg_att_ctrl_debug_get_body_cmd_fbz(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN? msg->len : MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN;
        memset(att_ctrl_debug, 0, MAVLINK_MSG_ID_ATT_CTRL_DEBUG_LEN);
    memcpy(att_ctrl_debug, _MAV_PAYLOAD(msg), len);
#endif
}
