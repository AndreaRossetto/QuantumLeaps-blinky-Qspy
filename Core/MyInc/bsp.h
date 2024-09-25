//============================================================================
// Product: Board Support Package example
// Last Updated for Version: 7.3.0
// Date of the Last Update:  2023-08-12
//
//                   Q u a n t u m  L e a P s
//                   ------------------------
//                   Modern Embedded Software
//
// Copyright (C) 2005 Quantum Leaps, LLC. All rights reserved.
//
// SPDX-License-Identifier: GPL-3.0-or-later OR LicenseRef-QL-commercial
//
// This software is dual-licensed under the terms of the open source GNU
// General Public License version 3 (or any later version), or alternatively,
// under the terms of one of the closed source Quantum Leaps commercial
// licenses.
//
// The terms of the open source GNU General Public License version 3
// can be found at: <www.gnu.org/licenses/gpl-3.0>
//
// The terms of the closed source Quantum Leaps commercial licenses
// can be found at: <www.state-machine.com/licensing>
//
// Redistributions in source code must retain this top-level comment block.
// Plagiarizing this software to sidestep the license obligations is illegal.
//
// Contact information:
// <www.state-machine.com/licensing>
// <info@state-machine.com>
//============================================================================
#ifndef BSP_H_
#define BSP_H_

#include "qpc.h"                 // QP/C real-time embedded framework
#include "../MyInc/blinky.h"     // Blinky Application interface
#include "../MyInc/bsp.h"        // Board Support Package
#include "../MyInc/QSpy.h"

#include "stm32g4xx.h"  // CMSIS-compliant header file for the MCU used

#define BSP_TICKS_PER_SEC    100U

Q_NORETURN Q_onError(char const *module, int_t const id);

void BSP_init();
void BSP_start(void);
void BSP_displayPaused(uint8_t paused);
void BSP_displayPhilStat(uint8_t n, char const *stat);
void BSP_terminate(int16_t result);

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

void BSP_randomSeed(uint32_t seed); // random seed
uint32_t BSP_random(void);          // pseudo-random generator

void BSP_BtnEvt(void);
void BSP_blinkyStart(void);
void BSP_blinkyStop(void);
void BSP_ledOn(void);
void BSP_ledOff(void);
int BSP_isBlinking(void);

extern int isBlinking;

#endif // BSP_H_
