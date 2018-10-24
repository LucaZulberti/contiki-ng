/*
 * Copyright (c) 2012, Texas Instruments Incorporated - http://www.ti.com/
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/**
 * \addtogroup wi502
 * @{
 *
 * \defgroup wi502-peripherals WI502 Peripherals
 *
 * Defines related to the WI502 on board peripherlas
 *
 * This file provides connectivity information on LEDs, Buttons, UART and
 * other WI502 peripherals
 *
 * @{
 *
 * \file
 * Header file with definitions related to the I/O connections on the HCE
 * WI502
 *
 * \note   Do not include this file directly. It gets included by contiki-conf
 *         after all relevant directives have been set.
 */
#ifndef BOARD_H_
#define BOARD_H_

#include "dev/gpio.h"
#include "dev/nvic.h"
/*---------------------------------------------------------------------------*/
/** \name LED configuration
 *
 * There is no LEDs on WI502 board
 * @{
 */

/* Notify various examples that we don't have LEDs */
#define PLATFORM_HAS_LEDS       0
/** @} */
/*---------------------------------------------------------------------------*/
/** \name USB configuration
 *
 * The USB pullup is driven by PC0 and is shared with LED1
 * @{
 */
#define USB_PULLUP_PORT         GPIO_C_NUM
#define USB_PULLUP_PIN          0
/** @} */
/*---------------------------------------------------------------------------*/
/** \name UART configuration
 *
 * On the WI502, the UART (XDS back channel) is connected to the
 * following ports/pins
 * - RX:  PA0
 * - TX:  PA1
 * - CTS: PB0 (Can only be used with UART1)
 * - RTS: PD3 (Can only be used with UART1)
 *
 * We configure the port to use UART0. To use UART1, replace UART0_* with
 * UART1_* below.
 * @{
 */
#define UART0_RX_PORT           GPIO_A_NUM
#define UART0_RX_PIN            0

#define UART0_TX_PORT           GPIO_A_NUM
#define UART0_TX_PIN            1

#define UART1_RX_PORT           GPIO_A_NUM
#define UART1_RX_PIN            2

#define UART1_TX_PORT           GPIO_A_NUM
#define UART1_TX_PIN            3

#define UART1_CTS_PORT          GPIO_B_NUM
#define UART1_CTS_PIN           0

#define UART1_RTS_PORT          GPIO_D_NUM
#define UART1_RTS_PIN           3
/** @} */
/*---------------------------------------------------------------------------*/
/** \name WI502 Button configuration
 *
 * Buttons on the WI502 are connected as follows:
 * - BUTTON_USER -> PA3
 * @{
 */
/** BUTTON_SELECT -> PA3 */
#define BUTTON_SELECT_PORT      GPIO_A_NUM
#define BUTTON_SELECT_PIN       7
#define BUTTON_SELECT_VECTOR    GPIO_A_IRQn

/* Notify various examples that we have Buttons - Temporarily disabled */
#define PLATFORM_HAS_BUTTON     0
#define PLATFORM_SUPPORTS_BUTTON_HAL 0
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name ADC configuration
 *
 * These values configure which CC2538 pins and ADC channels to use for the ADC
 * inputs.
 *
 * ADC inputs can only be on port A.
 * @{
 */
#define ADC_BAT_PORT            GPIO_A_NUM /**< ALS power GPIO control port */
#define ADC_BAT_PIN             6 /**< battery voltage ANA pin */

/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name SPI configuration
 *
 * These values configure which CC2538 pins to use for the SPI lines. Both
 * SPI instances can be used independently by providing the corresponding
 * port / pin macros.
 * @{
 */
#define SPI0_IN_USE             1
#define SPI1_IN_USE             0
#if SPI0_IN_USE
/** Clock port SPI0 */
#define SPI0_CLK_PORT           GPIO_D_NUM
/** Clock pin SPI0 */
#define SPI0_CLK_PIN            4
/** TX port SPI0 (master mode: MOSI) */
#define SPI0_TX_PORT            GPIO_D_NUM
/** TX pin SPI0 */
#define SPI0_TX_PIN             2
/** RX port SPI0 (master mode: MISO */
#define SPI0_RX_PORT            GPIO_D_NUM
/** RX pin SPI0 */
#define SPI0_RX_PIN             3
#endif  /* #if SPI0_IN_USE */
#if SPI1_IN_USE
/** Clock port SPI1 */
#define SPI1_CLK_PORT           GPIO_A_NUM
/** Clock pin SPI1 */
#define SPI1_CLK_PIN            2
/** TX port SPI1 (master mode: MOSI) */
#define SPI1_TX_PORT            GPIO_A_NUM
/** TX pin SPI1 */
#define SPI1_TX_PIN             4
/** RX port SPI1 (master mode: MISO) */
#define SPI1_RX_PORT            GPIO_A_NUM
/** RX pin SPI1 */
#define SPI1_RX_PIN             5
#endif  /* #if SPI1_IN_USE */
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name I2C configuration
 *
 * These values configure which CC2538 pins to use for the I2C lines.
 * @{
 */
#define I2C_IN_USE             1
#if I2C_IN_USE
/** Data port I2C */
#define I2C_SDA_PORT           GPIO_B_NUM
/** Data pin I2C */
#define I2C_SDA_PIN            1
/** Clock port I2C */
#define I2C_SCL_PORT           GPIO_B_NUM
/** Clock pin I2C */
#define I2C_SCL_PIN            2
#endif /* #if I2C_IN_USE */
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name Device string used on startup
 * @{
 */
#define BOARD_STRING "HCE WI502 IoT Module, cc2538-powered board"
/** @} */

#endif /* BOARD_H_ */

/**
 * @}
 * @}
 */
