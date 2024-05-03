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

int main()
{
    // GPF4/5/6引脚连接LED1/2/4，当输出低电平时LED点亮
    GPFCON &= ~(GPF4_MASK | GPF5_MASK | GPF6_MASK);
    GPFCON |= GPF4_OUT | GPF5_OUT | GPF6_OUT;

    // GPF0/2/GPG3引脚连接按键S2/S3/S4，当输入为低电平时表示按键按下
    GPFCON &= ~(GPF0_MASK | GPF2_MASK);
    GPFCON |= GPF0_IN | GPF2_IN;
    GPGCON &= ~GPG3_MASK;
    GPGCON |= GPG3_IN;

    while (1) {
        if (GPFDAT & (1 << 0))   // bit[0]高电平表示S2没有按下
            GPFDAT |= (1 << 4);  // LED1熄灭
        else
            GPFDAT &= ~(1 << 4);  // LED1点亮

        if (GPFDAT & (1 << 2))
            GPFDAT |= (1 << 5);
        else
            GPFDAT &= ~(1 << 5);

        if (GPGDAT & (1 << 3))
            GPFDAT |= (1 << 6);
        else
            GPFDAT &= ~(1 << 6);
    }

    return 0;
}
