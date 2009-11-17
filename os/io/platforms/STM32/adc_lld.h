/*
    ChibiOS/RT - Copyright (C) 2006-2007 Giovanni Di Sirio.

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
 * @file STM32/adc_lld.h
 * @brief STM32 ADC subsystem low level driver header
 * @addtogroup STM32_ADC
 * @{
 */

#ifndef _ADC_LLD_H_
#define _ADC_LLD_H_

#undef FALSE
#undef TRUE
#include <stm32f10x.h>
#define FALSE 0
#define TRUE (!FALSE)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief ADC1 driver enable switch.
 * @details If set to @p TRUE the support for ADC1 is included.
 * @note The default is @p TRUE.
 */
#if !defined(USE_STM32_ADC1) || defined(__DOXYGEN__)
#define USE_STM32_ADC1              TRUE
#endif

/**
 * @brief ADC1 DMA priority (0..3|lowest..highest).
 */
#if !defined(STM32_ADC1_DMA_PRIORITY) || defined(__DOXYGEN__)
#define STM32_ADC1_DMA_PRIORITY     1
#endif

/**
 * @brief ADC1 interrupt priority level setting.
 * @note @p BASEPRI_KERNEL >= @p STM32_ADC1_IRQ_PRIORITY > @p PRIORITY_PENDSV.
 */
#if !defined(STM32_ADC1_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define STM32_ADC1_IRQ_PRIORITY     0x70
#endif

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief ADC sample data type.
 */
typedef uint16_t adcsample_t;

/**
 * @brief Channels number in a conversion group.
 */
typedef uint16_t adc_channels_num_t;

/**
 * @brief ADC notification callback type.
 * @param[in] buffer pointer to the most recent samples data
 * @param[in] n number of buffer rows available starting from @p buffer
 */
typedef void (*adccallback_t)(adcsample_t *buffer, size_t n);

/**
 * @brief Conversion group configuration structure.
 * @details This implementation-dependent structure describes a conversion
 *          operation.
 */
typedef struct {
  /**
   * @brief Number of the analog channels belonging to the conversion group.
   */
  adc_channels_num_t    acg_num_channels;
  /**
   * @brief ADC CR1 register initialization data.
   * @note All the required bits must be defined into this field except
   *       @p ADC_CR1_SCAN that is enforced inside the driver.
   */
  uint32_t              acg_cr1;
  /**
   * @brief ADC CR2 register initialization data.
   * @note All the required bits must be defined into this field except
   *       @p ADC_CR2_DMA and @p ADC_CR2_ADON that are enforced inside the
   *       driver.
   */
  uint32_t              acg_cr2;
  /**
   * @brief ADC SMPR1 register initialization data.
   */
  uint32_t              acg_smpr1;
  /**
   * @brief ADC SMPR2 register initialization data.
   */
  uint32_t              acg_smpr2;
  /**
   * @brief ADC SQR1 register initialization data.
   */
  uint32_t              acg_sqr1;
  /**
   * @brief ADC SQR2 register initialization data.
   */
  uint32_t              acg_sqr2;
  /**
   * @brief ADC SQR3 register initialization data.
   */
  uint32_t              acg_sqr3;
} ADCConversionGroup;

/**
 * @brief Driver configuration structure.
 */
typedef struct {
  /* * <----------
   * @brief ADC prescaler setting.
   * @note This field can assume one of the following values:
   *       @p RCC_CFGR_ADCPRE_DIV2, @p RCC_CFGR_ADCPRE_DIV4,
   *       @p RCC_CFGR_ADCPRE_DIV6, @p RCC_CFGR_ADCPRE_DIV8.
   */
/*  uint32_t              ac_prescaler;*/
} ADCConfig;

/**
 * @brief Structure representing an ADC driver.
 */
typedef struct {
  /**
   * @brief Driver state.
   */
  adcstate_t            ad_state;
  /**
   * @brief Current configuration data.
   */
  const ADCConfig       *ad_config;
  /**
   * @brief Semaphore for completion synchronization.
   */
  Semaphore             ad_sem;
  /**
   * @brief Current callback function or @p NULL.
   */
  adccallback_t         ad_callback;
  /* End of the mandatory fields.*/
  /**
   * @brief Pointer to the ADCx registers block.
   */
  ADC_TypeDef           *ad_adc;
  /**
   * @brief Pointer to the DMA channel registers block.
   */
  DMA_Channel_TypeDef   *ad_dma;
  /**
   * @brief DMA priority bit mask.
   */
  uint32_t              ad_dmaprio;
  /**
   * @brief DMA error event.
   */
  EventSource           ad_dmaerror;
} ADCDriver;

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void adc_lld_init(void);
  void adc_lld_start(ADCDriver *adcp);
  void adc_lld_stop(ADCDriver *adcp);
  void adc_lld_start_conversion(ADCDriver *adcp,
                                ADCConversionGroup *grpp,
                                void *samples,
                                size_t depth);
  void adc_lld_stop_conversion(ADCDriver *adcp);
#ifdef __cplusplus
}
#endif

#endif /* _ADC_LLD_H_ */

/** @} */
