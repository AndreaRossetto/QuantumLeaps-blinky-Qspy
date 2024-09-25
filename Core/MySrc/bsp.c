/*
 * bsp.c
 *
 *  Created on: Aug 28, 2024
 *      Author: pc-37c9l43
 */

//============================================================================
// Product: Blinky example, NUCLEO-C031C6 board, QK kernel
// Last updated for version 7.3.0
// Last updated on  2023-08-15
//
//                   Q u a n t u m  L e a P s
//                   ------------------------
//                   Modern Embedded Software
//
// Copyright (C) 2005 Quantum Leaps, LLC. <state-machine.com>
//
// This program is open source software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Alternatively, this program may be distributed and modified under the
// terms of Quantum Leaps commercial licenses, which expressly supersede
// the GNU General Public License and are specifically designed for
// licensees interested in retaining the proprietary status of their code.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <www.gnu.org/licenses/>.
//
// Contact information:
// <www.state-machine.com/licensing>
// <info@state-machine.com>
//============================================================================
#include "../MyInc/bsp.h"        // Board Support Package
// add other drivers if necessary...

//Q_DEFINE_THIS_FILE  // define the name of this file for assertions

// Local-scope defines -----------------------------------------------------
// LED pins available on the board (just one user LED LD4--Green on PA.5)
#define LD4_PIN  5U

// Button pins available on the board (just one user Button B1 on PC.13)
#define B1_PIN   13U

Q_DEFINE_THIS_FILE // necessary to use qspy

int isBlinking;

//============================================================================
// Error handler and ISRs...

Q_NORETURN Q_onError(char const *module, int_t const id) {
    // NOTE: this implementation of the assertion handler is intended only
    // for debugging and MUST be changed for deployment of the application
    // (assuming that you ship your production code with assertions enabled).
    Q_UNUSED_PAR(module);
    Q_UNUSED_PAR(id);
    QS_ASSERTION(module, id, (uint32_t)10000U);

#ifndef NDEBUG
    // light up the user LED
	GPIOA->BSRR = (1U << LD4_PIN);  // turn LED on
	  //char msg[200];
	  //sprintf(msg, "QonError\r\n");
	  //HAL_UART_Transmit(&lpuart, (uint8_t *)msg, strlen(msg), 2000);

    // for debugging, hang on in an endless loop...
    for (;;) {

    }
#endif

    NVIC_SystemReset();
}

//............................................................................
#ifdef QF_ON_CONTEXT_SW
// NOTE: the context-switch callback is called with interrupts DISABLED
void QF_onContextSw(QActive *prev, QActive *next) {
    QS_BEGIN_INCRIT(CONTEXT_SW, 0U) // in critical section!
        QS_OBJ(prev);
        QS_OBJ(next);
    QS_END_INCRIT()
}
#endif // QF_ON_CONTEXT_SW

/*
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	QK_ISR_ENTRY();   // inform QK about entering an ISR

	if( GPIO_Pin == GPIO_PIN_13 )
		BSP_BtnEvt();

	QK_ISR_EXIT();    // inform QK about exiting an ISR
}*/

//............................................................................
void assert_failed(char const * const module, int_t const id); // prototype
void assert_failed(char const * const module, int_t const id) {
    Q_onError(module, id);
}

//............................................................................
void SysTick_Handler(void); // prototype
void SysTick_Handler(void) {
    QK_ISR_ENTRY();   // inform QK about entering an ISR

    QTIMEEVT_TICK_X(0U, &l_SysTick_Handler); // time events at rate 0

	#ifdef Q_SPY
    	uint32_t tmp = SysTick->CTRL; // clear CTRL_COUNTFLAG
		QS_tickTime_ += QS_tickPeriod_; // account for the clock rollover
	#endif

    QK_ISR_EXIT();    // inform QK about exiting an ISR
}

//============================================================================
// BSP functions...

void BSP_init() {
	if( !QS_INIT((void *)0) )
		Q_ERROR();

	// dictionaries...
	QS_OBJ_DICTIONARY(&l_SysTick_Handler);
	QS_USR_DICTIONARY(BLINKY_STAT);
	QS_USR_DICTIONARY(PAUSED_STAT);
	QS_USR_DICTIONARY(CONTEXT_SW);

	QS_ONLY(produce_sig_dict());

	// setup the Global QS filters...
	QS_GLB_FILTER(QS_ALL_RECORDS);   // all records
	QS_GLB_FILTER(-QS_QF_TICK);      // exclude the clock tic
}
//............................................................................
void BSP_start(void) {
    // initialize event pools
    static QF_MPOOL_EL(QEvt) smlPoolSto[10];
    QF_poolInit(smlPoolSto, sizeof(smlPoolSto), sizeof(smlPoolSto[0]));

    // initialize publish-subscribe
    static QSubscrList subscrSto[MAX_PUB_SIG];
    QActive_psInit(subscrSto, Q_DIM(subscrSto));

    // instantiate and start AOs/threads...

    static QEvt const *blinkyQueueSto[10];
    Blinky_ctor();
    QACTIVE_START(AO_Blinky,
        1U,                          	// QP prio. of the AO
        blinkyQueueSto,               	// event queue storage
        Q_DIM(blinkyQueueSto),       	// queue length [events]
        (void *)0, 0U,               	// no stack storage
        (void *)0);             	// no initialization param

}
//............................................................................
void BSP_BtnEvt(void){
	//static QEvt const btnEvt = QEVT_INITIALIZER(TOGGLE_SIG);

	//QF_PUBLISH(&btnEvt, 0);
}
//............................................................................
//............................................................................

int BSP_isBlinking(void){
	return isBlinking;
}

void BSP_blinkyStart(void){
	char msg[200];
	sprintf(msg, "Start\r\n");
	isBlinking = 1;
	//HAL_UART_Transmit(&lpuart, (uint8_t *)msg, strlen(msg), 2000);
}
//............................................................................
void BSP_blinkyStop(void){
	char msg[200];
	sprintf(msg, "Stop\r\n");
	isBlinking = 0;
	//HAL_UART_Transmit(&lpuart, (uint8_t *)msg, strlen(msg), 2000);
}
//............................................................................
void BSP_ledOn(void) {
    GPIOA->BSRR = (1U << LD4_PIN);  // turn LED on
}
//............................................................................
void BSP_ledOff(void) {
    GPIOA->BSRR = (1U << (LD4_PIN + 16U));  // turn LED off
}
//............................................................................
void BSP_terminate(int16_t result) {
    Q_UNUSED_PAR(result);
}

//============================================================================
// QF callbacks...
void QF_onStartup(void) {
    // set up the SysTick timer to fire at BSP_TICKS_PER_SEC rate
    SysTick_Config(SystemCoreClock / BSP_TICKS_PER_SEC);

    // assign all priority bits for preemption-prio. and none to sub-prio.
    NVIC_SetPriorityGrouping(0U);

    // set priorities of ALL ISRs used in the system, see NOTE1
    NVIC_SetPriority(QSPY_IRQn,    0); // kernel UNAWARE interrupt
    //NVIC_SetPriority(EXTI0_1_IRQn,   QF_AWARE_ISR_CMSIS_PRI + 0U);
    NVIC_SetPriority(SysTick_IRQn,   QF_AWARE_ISR_CMSIS_PRI + 1U);
    // ...
    NVIC_SetPriority(EXTI15_10_IRQn, QF_AWARE_ISR_CMSIS_PRI + 1U);

    // enable IRQs...
    NVIC_EnableIRQ(EXTI15_10_IRQn);

	#ifdef Q_SPY
		NVIC_EnableIRQ(QSPY_IRQn); // UART2 interrupt used for QS-RX
	#endif
}
//............................................................................
void QF_onCleanup(void) {

}
//............................................................................
void QK_onIdle(void) {
    // toggle an LED on and then off (not enough LEDs, see NOTE02)
    //QF_INT_DISABLE();
    //QF_MEM_SYS();
    //GPIOA->BSRR = (1U << LD4_PIN);         // turn LED[n] on
    //GPIOA->BSRR = (1U << (LD4_PIN + 16U)); // turn LED[n] off
    //QF_MEM_APP();
    //QF_INT_ENABLE();

#ifdef Q_SPY
	QS_rxParse();  // parse all the received bytes

	if( (QSPY_UART->ISR & (1U << 7U)) != 0U ) {  // is TXE empty?
		QF_INT_DISABLE();
		uint16_t b = QS_getByte();
		QF_INT_ENABLE();

		if (b != QS_EOD) {   // not End-Of-Data?
			QSPY_UART->TDR = b; // put into the DR register
		}
	}
#elif defined NDEBUG
    // Put the CPU and peripherals to the low-power mode.
    // you might need to customize the clock management for your application,
    // see the datasheet for your particular Cortex-M MCU.
    //
    // !!!CAUTION!!!
    // The WFI instruction stops the CPU clock, which unfortunately disables
    // the JTAG port, so the ST-Link debugger can no longer connect to the
    // board. For that reason, the call to __WFI() has to be used with CAUTION.
    //
    // NOTE: If you find your board "frozen" like this, strap BOOT0 to VDD and
    // reset the board, then connect with ST-Link Utilities and erase the part.
    // The trick with BOOT(0) is it gets the part to run the System Loader
    // instead of your broken code. When done disconnect BOOT0, and start over.
    //
    //__WFI(); // Wait-For-Interrupt
#endif
}




