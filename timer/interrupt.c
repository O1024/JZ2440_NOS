#include "s3c24x0.h"

void timer4_handle(void)
{
    /* 每次中断令3个LED改变状态 */
    if(INTOFFSET == INT_TIMER4)
        GPFDAT = ~(GPFDAT & (0x7 << 4));

    /* 清中断 */
    SRCPND = 1 << INTOFFSET;
    INTPND = 1 << INTOFFSET;     
}

