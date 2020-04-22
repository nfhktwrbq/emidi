#include "debug.h"
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

int _write(int file, char *ptr, int len)
{
	int i = 0;
	for(i = 0; i < len; i++)
	{
		ITM_SendChar((*ptr++));
	}
	return len;
}

