/**
 * @file init.c
 * @author wenchen (wenchen.mails@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-05-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "s3c24x0.h"

void disable_watch_dog(void)
{
    WTCON = 0;

    return;
}

void clock_init()
{
    CLKDIVN = 0x5;
    // when HDIV not equal 0, set CPU mode from FastBus mode to Asynchronous bus mode
    __asm__ __volatile__(
        "mrc     p15, 0, r0, c1, c0, 0\n"
        "orr     r0, r0, #(1<<12)\n"
        "mcr     p15, 0, r0, c1, c0, 0\n"
    );

    MPLLCON = ((0x5c << 12) | (0x1 << 4) | (0x00));

    return;
}