/**
 * @file main.c
 * @author wenchen (wenchen.mails@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-05-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "s3c24x0.h"

static inline void delay(volatile unsigned long dly)
{
    for (; dly > 0; dly--)
        ;
}

int main(void)
{
    unsigned int index = 4;

    GPFCON |= (GPx4_OUT | GPx5_OUT | GPx6_OUT);
    while (1) {
        GPFDAT = 0xff;
        delay(300000);
        GPFDAT &= ~(1 << index);
        delay(300000);

        if (index++ == 6)
            index = 4;
    }

    return 0;
}