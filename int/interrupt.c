/**
 * @file interrupt.c
 * @author wenchen (wenchen.mails@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-05-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "s3c24x0.h"

void EINT_Handle()
{
    unsigned long oft = INTOFFSET;

    switch (oft) {
        // S2被按下
        case 0: {
            GPFDAT |= (0x7 << 4);  // 所有LED熄灭
            GPFDAT &= ~(1 << 4);   // LED1点亮
            break;
        }

        // S3被按下
        case 2: {
            GPFDAT |= (0x7 << 4);  // 所有LED熄灭
            GPFDAT &= ~(1 << 5);   // LED2点亮
            break;
        }

        // K4被按下
        case 5: {
            GPFDAT |= (0x7 << 4);  // 所有LED熄灭
            GPFDAT &= ~(1 << 6);   // LED4点亮
            break;
        }

        default: break;
    }

    // 清中断
    if (oft == 5)
        EINTPEND = (1 << 11);  // EINT8_23合用IRQ5
    SRCPND = 1 << oft;
    INTPND = 1 << oft;
}