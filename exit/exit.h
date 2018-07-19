#ifndef __Exit_H
#define	__Exit_H

#include "stm32f10x.h"


void EXIT_Init(void);
void mpu_exit_int(u8 PreempPriority,u8 SubPriority);
#endif


