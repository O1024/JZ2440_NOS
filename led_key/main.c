/**
 * @file main.c
 * @author wenchen (wenchen.mails@gmail.com)
 * @brief LED按键实验代码（gpio引脚输入功能）
 * @version 0.1
 * @date 2024-05-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "s3c24x0.h"

int main()
{
    // GPF4/5/6引脚连接LED1/2/4，当输出低电平时LED点亮，同时作为输出引脚时关闭内部上拉
    GPFUP |= (GPx4_UP_DISABLE | GPx5_UP_DISABLE | GPx6_UP_DISABLE);
    GPFCON |= (GPx4_OUT | GPx5_OUT | GPx6_OUT);

    // GPF0/2引脚连接按键S2/S3，当输入为低电平时表示按键按下
    GPFCON &= ((GPx0_IN | GPx2_IN) | GPxFULL_MASK);
    // GPG3引脚连接按键S4，当输入为低电平时表示按键按下
    GPGCON |= GPx3_IN;

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
