/**
 * @file main.c
 * @author wenchen (wenchen.mails@gmail.com)
 * @brief LED跑马灯实验代码（gpio引脚输出功能）
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

    while (1) {
        // 定义LED引脚掩码
        const unsigned int LED_MASK = (1 << 4) | (1 << 5) | (1 << 6);
        const unsigned int LED1 = 1 << 4;
        const unsigned int LED2 = 1 << 5;
        const unsigned int LED3 = 1 << 6;
        
        // LED1点亮，其他熄灭
        GPFDAT = (GPFDAT | LED_MASK) & ~LED1;
        for (volatile int i = 0; i < 50000; i++);  // 延时

        // LED2点亮，其他熄灭 
        GPFDAT = (GPFDAT | LED_MASK) & ~LED2;
        for (volatile int i = 0; i < 50000; i++);  // 延时

        // LED3点亮，其他熄灭
        GPFDAT = (GPFDAT | LED_MASK) & ~LED3;
        for (volatile int i = 0; i < 50000; i++);  // 延时
    }

    return 0;
}
