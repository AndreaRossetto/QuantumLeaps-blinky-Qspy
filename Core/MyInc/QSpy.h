/*
 * QSpy.h
 *
 *  Created on: Sep 12, 2024
 *      Author: pc-37c9l43
 */

#ifndef QSPY_H_
#define QSPY_H_

#include "qpc.h"
#include "stm32g4xx.h"

// USART pins PA.2 and PA.3
#define QSPY_UART				LPUART1
#define QSPY_IRQn				LPUART1_IRQn

#define QSPY_UART_TX_PIN 3U
#define QSPY_UART_RX_PIN 2U

#ifdef Q_SPY
    // QSpy source IDs
    static QSpyId const l_SysTick_Handler = { 0U };

    static QSTimeCtr QS_tickTime_;
    static QSTimeCtr QS_tickPeriod_;

    enum AppRecords { // application-specific trace records
        BLINKY_STAT = QS_USER,
        PAUSED_STAT,
		TIMEOUT_STAT,
        CONTEXT_SW,
    };

    void LPUSART_IRQHandler(void); // prototype

#endif


#endif /* QSPY_H_ */
