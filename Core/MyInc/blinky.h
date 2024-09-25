//============================================================================
// Product: "Blinky" example
// Last updated for version 7.2.0
// Last updated on  2023-01-08
//
//                   Q u a n t u m  L e a P s
//                   ------------------------
//                   Modern Embedded Software
//
// Copyright (C) 2005 Quantum Leaps, LLC. All rights reserved.
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
#ifndef BLINKY_H_
#define BLINKY_H_

#include <stdio.h>
#include "stm32g4xx.h"

enum BlinkySignals {
    DUMMY_SIG = Q_USER_SIG,
	//TOGGLE_SIG,
    MAX_PUB_SIG,          // the last published signal

    TIMEOUT_SIG,
    MAX_SIG               // the last signal
};

#ifdef Q_SPY
static inline void produce_sig_dict(void) {
    QS_SIG_DICTIONARY(TIMEOUT_SIG, (void *)0);
}
#endif // def Q_SPY

typedef struct {
	// protected:
    QEvt super;

    // public:
    //uint8_t philoId;
} BlinkEvt;

void Blinky_ctor(void);
extern QActive * const AO_Blinky; // opaque pointer

#endif // BLINKY_H_