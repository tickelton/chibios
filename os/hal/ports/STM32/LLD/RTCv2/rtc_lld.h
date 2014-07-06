/*
    ChibiOS/RT - Copyright (C) 2006-2013 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
/*
   Concepts and parts of this file have been contributed by Uladzimir Pylinsky
   aka barthess.
 */

/**
 * @file    STM32/RTCv2/rtc_lld.h
 * @brief   STM32L1xx/STM32F2xx/STM32F4xx RTC low level driver header.
 *
 * @addtogroup RTC
 * @{
 */

#ifndef _RTC_LLD_H_
#define _RTC_LLD_H_

#if HAL_USE_RTC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Callback support int the driver.
 */
#define RTC_SUPPORTS_CALLBACKS              STM32_RTC_HAS_INTERRUPTS

/**
 * @brief   RTC PRER register initializer.
 */
#define RTC_PRER(a, s)                      ((((a) - 1) << 16) | ((s) - 1))

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */
/**
 * @brief   RTC PRES register initialization.
 * @note    The default is calculated for a 32768Hz clock.
 */
#if !defined(STM32_RTC_PRESA_VALUE) || defined(__DOXYGEN__)
#define STM32_RTC_PRESA_VALUE               32
#endif

/**
 * @brief   RTC PRESS divider initialization.
 * @note    The default is calculated for a 32768Hz clock.
 */
#if !defined(STM32_RTC_PRESS_VALUE) || defined(__DOXYGEN__)
#define STM32_RTC_PRESS_VALUE               1024
#endif
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if HAL_USE_RTC && !STM32_HAS_RTC
#error "RTC not present in the selected device"
#endif

#if !(STM32_RTCSEL == STM32_RTCSEL_LSE) &&                                  \
    !(STM32_RTCSEL == STM32_RTCSEL_LSI) &&                                  \
    !(STM32_RTCSEL == STM32_RTCSEL_HSEDIV)
#error "invalid source selected for RTC clock"
#endif

#if STM32_PCLK1 < (STM32_RTCCLK * 7)
#error "STM32_PCLK1 frequency is too low"
#endif

/**
 * @brief   Initialization for the RTC_PRER register.
 */
#define STM32_RTC_PRER_BITS                 RTC_PRER(STM32_RTC_PRESA_VALUE, \
                                                     STM32_RTC_PRESS_VALUE)

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Structure representing an RTC driver.
 */
struct RTCDriver {
  /**
   * @brief Pointer to the RTC registers block.
   */
  RTC_TypeDef               *rtc;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(__DOXYGEN__)
extern RTCDriver RTCD1;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void rtc_lld_init(void);
  void rtc_lld_set_time(RTCDriver *rtcp, const RTCDateTime *timespec);
  void rtc_lld_get_time(RTCDriver *rtcp, RTCDateTime *timespec);
#if STM32_RTC_NUM_ALARMS > 0
  void rtc_lld_set_alarm(RTCDriver *rtcp,
                         rtcalarm_t alarm,
                         const RTCAlarm *alarmspec);
  void rtc_lld_get_alarm(RTCDriver *rtcp,
                         rtcalarm_t alarm,
                         RTCAlarm *alarmspec);
#endif
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_RTC */

#endif /* _RTC_LLD_H_ */

/** @} */
