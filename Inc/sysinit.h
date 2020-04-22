/*
 * sysinit.h
 *
 *  Created on: Apr 22, 2020
 *      Author: muaddib
 */

#ifndef SYSINIT_H_
#define SYSINIT_H_

#include "stm32f4xx.h"
#include "system_stm32f4xx.h"


#include <inttypes.h>

extern volatile uint32_t SystemTicktimer;

void sysInit(void);

#endif /* SYSINIT_H_ */
