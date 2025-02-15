/**
 * @file init.c
 * @author wenchen (wenchen.mails@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-05-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "s3c24x0.h"

/*
 * 关闭WATCHDOG，否则CPU会不断重启
 */
void disable_watch_dog(void)
{
    WTCON = 0;  // 关闭WATCHDOG很简单，往这个寄存器写0即可
}

void init_led(void)
{
    // LED1,LED2,LED4对应的3根引脚设为输出
    GPFCON |= (GPx4_OUT | GPx5_OUT | GPx6_OUT);
    GPFDAT |= (0x7 << 4);  // 所有LED熄灭
}

/*
 * 初始化GPIO引脚为外部中断
 * GPIO引脚用作外部中断时，默认为低电平触发、IRQ方式(不用设置INTMOD)
 */
void init_irq()
{
    // S2,S3对应的2根引脚设为中断引脚 EINT0,ENT2
    GPFCON |= (GPx0_EINT | GPx2_EINT);

    // S4对应的引脚设为中断引脚EINT11
    GPGCON |= GPx3_EINT;

    // 对于EINT11，需要在EINTMASK寄存器中使能它
    EINTMASK &= ~(1 << 11);

    /*
     * 设定优先级：
     * ARB_SEL0 = 00b, ARB_MODE0 = 0: REQ1 > REQ3，即EINT0 > EINT2
     * 仲裁器1、6无需设置
     * 最终：
     * EINT0 > EINT2 > EINT11即K2 > K3 > K4
     */
    PRIORITY = (PRIORITY & ((~0x01) | (0x3 << 7))) | (0x0 << 7);

    // EINT0、EINT2、EINT8_23使能
    INTMSK &= (~(1 << 0)) & (~(1 << 2)) & (~(1 << 5));
}
