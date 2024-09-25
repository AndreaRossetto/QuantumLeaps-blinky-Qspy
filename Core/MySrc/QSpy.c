/*
 * QSpy.cpp
 *
 *  Created on: Sep 12, 2024
 *      Author: pc-37c9l43
 */

#include "../MyInc/QSpy.h"
#include "../MyInc/bsp.h"

#ifdef Q_SPY

//............................................................................
#define __DIV(__PCLK, __BAUD)       		(((__PCLK / 4) *25)/(__BAUD))
#define __DIVMANT(__PCLK, __BAUD)   		(__DIV(__PCLK, __BAUD)/100)
#define __DIVFRAQ(__PCLK, __BAUD)   		(((__DIV(__PCLK, __BAUD) - (__DIVMANT(__PCLK, __BAUD) * 100)) * 16 + 50) / 100)
#define __USART_BRR(__PCLK, __BAUD) 		((__DIVMANT(__PCLK, __BAUD) << 4)|(__DIVFRAQ(__PCLK, __BAUD) & 0x0F))

//............................................................................


void LPUSART_IRQHandler(void) { // used in QS-RX (kernel UNAWARE interrupt)
    // is RX register NOT empty?
    if( (QSPY_UART->ISR & (1U << 5U)) != 0U ) {
        uint32_t b = QSPY_UART->RDR;
        QS_RX_PUT(b);
    }

    QK_ARM_ERRATUM_838869();
}

uint8_t QS_onStartup(void const *arg) {
    Q_UNUSED_PAR(arg);

    static uint8_t qsTxBuf[2 * 1024]; // buffer for QS-TX channel
    QS_initBuf(qsTxBuf, sizeof(qsTxBuf));

    static uint8_t qsRxBuf[100];    // buffer for QS-RX channel
    QS_rxInitBuf(qsRxBuf, sizeof(qsRxBuf));

    // enable peripheral clock for USART2
    //RCC->IOPENR  |= ( 1U <<  0U);  // Enable GPIOA clock for USART pins
    //RCC->APB1ENR |= ( 1U << 17U);  // Enable USART#2 clock

    // Configure PA3 to USART2_RX, PA2 to USART2_TX
    /*GPIOA->AFR[0] &= ~((15U << 4U * QSPY_UART_RX_PIN) | (15U << 4U * QSPY_UART_TX_PIN));
    GPIOA->AFR[0] |=  (( 4U << 4U * QSPY_UART_RX_PIN) | ( 4U << 4U * QSPY_UART_TX_PIN));
    GPIOA->MODER  &= ~(( 3U << 2U * QSPY_UART_RX_PIN) | ( 3U << 2U * QSPY_UART_TX_PIN));
    GPIOA->MODER  |=  (( 2U << 2U * QSPY_UART_RX_PIN) | ( 2U << 2U * QSPY_UART_TX_PIN));

    QSPY_UART->BRR  = __USART_BRR(SystemCoreClock, 115200U);  // baud rate
    QSPY_UART->CR3  = 0x0000U |      // no flow control
                   (1U << 12U);   // disable overrun detection (OVRDIS)
    QSPY_UART->CR2  = 0x0000U;       // 1 stop bit
    QSPY_UART->CR1  = ((1U <<  2U) | // enable RX
                    (1U <<  3U) | // enable TX
                    (1U <<  5U) | // enable RX interrupt
                    (0U << 12U) | // 8 data bits
                    (0U << 28U) | // 8 data bits
                    (1U <<  0U)); // enable USART*/

    QS_tickPeriod_ = SystemCoreClock / BSP_TICKS_PER_SEC;
    QS_tickTime_ = QS_tickPeriod_; // to start the timestamp at zero

    return 1U; // return success
}
//............................................................................
void QS_onCleanup(void) {

}
//............................................................................
QSTimeCtr QS_onGetTime(void) { // NOTE: invoked with interrupts DISABLED
    if( (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0U ) // not set?
    	return QS_tickTime_ - (QSTimeCtr)SysTick->VAL;
    else // the rollover occurred, but the SysTick_ISR did not run yet
    	return QS_tickTime_ + QS_tickPeriod_ - (QSTimeCtr)SysTick->VAL;

}
//............................................................................
// NOTE:
// No critical section in QS_onFlush() to avoid nesting of critical sections
// in case QS_onFlush() is called from Q_onError().
void QS_onFlush(void) {
    for( ;; ) {
        uint16_t b = QS_getByte();
        if( b != QS_EOD ) { // NOT end-of-data
            // busy-wait as long as TX has data to transmit
            while( (QSPY_UART->ISR & (1U << 7U)) == 0U ) ;
            QSPY_UART->TDR = b; // put into the TDR register
        }else
            break; // break out of the loop
    }
}
//............................................................................
//! callback function to reset the target (to be implemented in the BSP)
void QS_onReset(void) {
    NVIC_SystemReset();
}
//............................................................................
void QS_onCommand(uint8_t cmdId, uint32_t param1, uint32_t param2, uint32_t param3){
    Q_UNUSED_PAR(cmdId);
    Q_UNUSED_PAR(param1);
    Q_UNUSED_PAR(param2);
    Q_UNUSED_PAR(param3);
}

#endif // Q_SPY

