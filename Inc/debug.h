/*
 * debug.h
 *
 *  Created on: Apr 22, 2020
 *      Author: muaddib
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include "stdio.h"

#define DEBUG_COMMON	1
int _write(int file, char *ptr, int len);

#define DEBUG_TEST 		(DEBUG_COMMON && 1)

#if DEBUG_TEST
#define dbg_test_printf(...) printf(__VA_ARGS__)
#else
#define dbg_test_printf(...)
#endif

#endif /* DEBUG_H_ */
