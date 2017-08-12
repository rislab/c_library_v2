/** @file
 *  @brief MAVLink comm protocol generated from cmu_mavlink.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_CMU_MAVLINK_H
#define MAVLINK_CMU_MAVLINK_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_CMU_MAVLINK.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{207, 183, 61, 0, 0, 0}, {208, 208, 70, 0, 0, 0}, {209, 177, 48, 0, 0, 0}, {210, 101, 76, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_CMU_MAVLINK

// ENUM DEFINITIONS



// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_image_triggered_imu.h"
#include "./mavlink_msg_l1_adaptive_debug.h"
#include "./mavlink_msg_odom_mocap.h"
#include "./mavlink_msg_rpm_output.h"

// base include
#include "../standard/standard.h"

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_IMAGE_TRIGGERED_IMU, MAVLINK_MESSAGE_INFO_L1_ADAPTIVE_DEBUG, MAVLINK_MESSAGE_INFO_ODOM_MOCAP, MAVLINK_MESSAGE_INFO_RPM_OUTPUT}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_CMU_MAVLINK_H
