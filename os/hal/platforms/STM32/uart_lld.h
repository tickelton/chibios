/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010 Giovanni Di Sirio.

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
 * @file    STM32/uart_lld.h
 * @brief   STM32 low level UART driver header.
 *
 * @addtogroup STM32_UART
 * @{
 */

#ifndef _UART_LLD_H_
#define _UART_LLD_H_

#if CH_HAL_USE_UART || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @brief   UART driver on USART1 enable switch.
 * @details If set to @p TRUE the support for USART1 is included.
 * @note    The default is @p FALSE.
 */
#if !defined(STM32_UART_USE_USART1) || defined(__DOXYGEN__)
#define STM32_UART_USE_USART1               TRUE
#endif

/**
 * @brief   USART1 interrupt priority level setting.
 */
#if !defined(STM32_UART_USART1_IRQ_PRIO) || defined(__DOXYGEN__)
#define STM32_UART_USART1_IRQ_PRIORITY      12
#endif

/**
 * @brief   USART1 DMA priority (0..3|lowest..highest).
 * @note    The priority level is used for both the TX and RX DMA channels but
 *          because of the channels ordering the RX channel has always priority
 *          over the TX channel.
 */
#if !defined(STM32_UART_USART1_DMA_PRIO) || defined(__DOXYGEN__)
#define STM32_UART_USART1_DMA_PRIORITY      1
#endif

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   UART driver condition flags type.
 */
typedef uint32_t uartflags_t;

/**
 * @brief   Generic UART notification callback type.
 */
typedef void (*uartcb_t)(void);

/**
 * @brief   Character received UART notification callback type.
 *
 * @param[in] c         received character
 */
typedef void (*uartccb_t)(uint16_t c);

/**
 * @brief   Receive error UART notification callback type.
 *
 * @param[in] e         receive error mask
 */
typedef void (*uartecb_t)(uartflags_t e);

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  /** @brief End of transmission buffer callback.*/
  uartcb_t                  uc_txend1;
  /** @brief Physical end of transmission callback.*/
  uartcb_t                  uc_txend2;
  /** @brief Receive buffer filled callback.*/
  uartcb_t                  uc_rxend;
  /** @brief Character received while out if the @p UART_RECEIVE state.*/
  uartccb_t                 uc_rxchar;
  /** @brief Receive error callback.*/  
  uartecb_t                 uc_rxerr;
  /* End of the mandatory fields.*/
  /** @brief Bit rate.*/
  uint32_t                  uc_speed;
  /** @brief Initialization value for the CR1 register.*/
  uint16_t                  uc_cr1;
  /** @brief Initialization value for the CR2 register.*/
  uint16_t                  uc_cr2;
  /** @brief Initialization value for the CR3 register.*/
  uint16_t                  uc_cr3;
} UARTConfig;

/**
 * @brief   Structure representing an UART driver.
 */
typedef struct {
  /** @brief Driver state.*/
  uartstate_t               ud_state;
  /** @brief Current configuration data.*/
  const UARTConfig          *ud_config;
  /** @brief Transmitter state.*/
  uarttxstate_t             ud_txstate;
  /** @brief Receiver state.*/
  uartrxstate_t             ud_rxstate;
  /** @brief UART driver status flags.*/
  uartflags_t               ud_flags;
  /* End of the mandatory fields.*/
  /** @brief Pointer to the USART registers block.*/
  USART_TypeDef             *ud_usart;
  /** @brief Pointer to the DMA registers block.*/
  stm32_dma_t               *ud_dmap;
  /** @brief DMA priority bit mask.*/
  uint32_t                  ud_dmaccr;
  /** @brief Receive DMA channel.*/
  uint8_t                   ud_dmarx;
  /** @brief Transmit DMA channel.*/
  uint8_t                   ud_dmatx;
  /** @brief Default receive buffer while into @p UART_RX_IDLE state.*/
  uint16_t                  ud_rxbuf;
} UARTDriver;

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void uart_lld_init(void);
  void uart_lld_start(UARTDriver *uartp);
  void uart_lld_stop(UARTDriver *uartp);
  void uart_lld_start_send(UARTDriver *uartp, size_t n, const void *txbuf);
  void uart_lld_stop_send(UARTDriver *uartp);
  void uart_lld_start_receive(UARTDriver *uartp, size_t n, void *rxbuf);
  void uart_lld_stop_receive(UARTDriver *uartp);
#ifdef __cplusplus
}
#endif

#endif /* CH_HAL_USE_UART */

#endif /* _UART_LLD_H_ */

/** @} */
