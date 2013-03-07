/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,
                 2011,2012,2013 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file    LPC8xx/gpt_lld.h
 * @brief   LPC8xx GPT subsystem low level driver header.
 *
 * @addtogroup GPT
 * @{
 */

#ifndef _GPT_LLD_H_
#define _GPT_LLD_H_

#if HAL_USE_GPT || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   GPT1 driver enable switch.
 * @details If set to @p TRUE the support for GPT1 is included.
 * @note    The default is @p TRUE.
 */
#if !defined(LPC8xx_GPT_USE_MRT0) || defined(__DOXYGEN__)
#define LPC8xx_GPT_USE_MRT0              TRUE
#endif

/**
 * @brief   GPT2 driver enable switch.
 * @details If set to @p TRUE the support for GPT2 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(LPC8xx_GPT_USE_MRT1) || defined(__DOXYGEN__)
#define LPC8xx_GPT_USE_MRT1              FALSE
#endif

/**
 * @brief   GPT3 driver enable switch.
 * @details If set to @p TRUE the support for GPT3 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(LPC8xx_GPT_USE_MRT2) || defined(__DOXYGEN__)
#define LPC8xx_GPT_USE_MRT2              FALSE
#endif

/**
 * @brief   GPT4 driver enable switch.
 * @details If set to @p TRUE the support for GPT4 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(LPC8xx_GPT_USE_MRT3) || defined(__DOXYGEN__)
#define LPC8xx_GPT_USE_MRT3              FALSE
#endif

/**
 * @brief   GPT interrupt priority level setting.
 */
#if !defined(LPC8xx_GPT_MRT_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define LPC8xx_GPT_MRT_IRQ_PRIORITY     2
#endif


/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if !LPC8xx_GPT_USE_MRT0 && !LPC8xx_GPT_USE_MRT1 &&                   \
    !LPC8xx_GPT_USE_MRT2 && !LPC8xx_GPT_USE_MRT3
#error "GPT driver activated but no CT peripheral assigned"
#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   GPT frequency type.
 */
typedef uint32_t gptfreq_t;

/**
 * @brief   GPT counter type.
 */
typedef uint32_t gptcnt_t;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  /**
   * @brief   Timer clock in Hz.
   * @note    The low level can use assertions in order to catch invalid
   *          frequency specifications.
   */
  gptfreq_t                 frequency;
  /**
   * @brief   Timer callback pointer.
   * @note    This callback is invoked on GPT counter events.
   */
  gptcallback_t             callback;
  /* End of the mandatory fields.*/
} GPTConfig;

/**
 * @brief   Structure representing a GPT driver.
 */
struct GPTDriver {
  /**
   * @brief Driver state.
   */
  gptstate_t                state;
  /**
   * @brief Current configuration data.
   */
  const GPTConfig           *config;
  /* End of the mandatory fields.*/
  /**
   * @brief Pointer to the MRT Channelx registers block.
   */
  MRT_Channel_cfg_Type           *tmr;
  /**
   * @brief Prescaler.
   */
  uint32_t                  pr;
  /**
   * @brief channel bitmask.
   */
  uint32_t                  mask;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if LPC8xx_GPT_USE_MRT0 && !defined(__DOXYGEN__)
extern GPTDriver GPTD1;
#endif

#if LPC8xx_GPT_USE_MRT1 && !defined(__DOXYGEN__)
extern GPTDriver GPTD2;
#endif

#if LPC8xx_GPT_USE_MRT2 && !defined(__DOXYGEN__)
extern GPTDriver GPTD3;
#endif

#if LPC8xx_GPT_USE_MRT3 && !defined(__DOXYGEN__)
extern GPTDriver GPTD4;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  void gpt_lld_init(void);
  void gpt_lld_start(GPTDriver *gptp);
  void gpt_lld_stop(GPTDriver *gptp);
  void gpt_lld_start_timer(GPTDriver *gptp, gptcnt_t period);
  void gpt_lld_stop_timer(GPTDriver *gptp);
  void gpt_lld_polled_delay(GPTDriver *gptp, gptcnt_t interval);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_GPT */

#endif /* _GPT_LLD_H_ */

/** @} */
