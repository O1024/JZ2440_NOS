/**
 * @file s3c24x0.h
 * @author wenchen (wenchen.mails@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-05
 *
 * @copyright Copyright (c) 2022
 *
 */

/* SDRAM regisers */
#define MEM_CTL_BASE        (*(volatile unsigned long*)0x48000000)
#define SDRAM_BASE          (*(volatile unsigned long*)0x30000000)

/* WOTCH DOG register */
#define WTCON               (*(volatile unsigned long*)0x53000000)

/* GPIO registers */
#define GPBCON              (*(volatile unsigned long*)0x56000010)
#define GPBDAT              (*(volatile unsigned long*)0x56000014)

#define GPFCON              (*(volatile unsigned long*)0x56000050)
#define GPFDAT              (*(volatile unsigned long*)0x56000054)
#define GPFUP               (*(volatile unsigned long*)0x56000058)

#define GPGCON              (*(volatile unsigned long*)0x56000060)
#define GPGDAT              (*(volatile unsigned long*)0x56000064)
#define GPGUP               (*(volatile unsigned long*)0x56000068)

#define GPHCON              (*(volatile unsigned long*)0x56000070)
#define GPHDAT              (*(volatile unsigned long*)0x56000074)
#define GPHUP               (*(volatile unsigned long*)0x56000078)

/* UART registers */
#define ULCON0              (*(volatile unsigned long*)0x50000000)
#define UCON0               (*(volatile unsigned long*)0x50000004)
#define UFCON0              (*(volatile unsigned long*)0x50000008)
#define UMCON0              (*(volatile unsigned long*)0x5000000c)
#define UTRSTAT0            (*(volatile unsigned long*)0x50000010)
#define UTXH0               (*(volatile unsigned char*)0x50000020)
#define URXH0               (*(volatile unsigned char*)0x50000024)
#define UBRDIV0             (*(volatile unsigned long*)0x50000028)

/* interrupt registes */
#define SRCPND              (*(volatile unsigned long*)0x4A000000)
#define INTMOD              (*(volatile unsigned long*)0x4A000004)
#define INTMSK              (*(volatile unsigned long*)0x4A000008)
#define PRIORITY            (*(volatile unsigned long*)0x4A00000c)
#define INTPND              (*(volatile unsigned long*)0x4A000010)
#define INTOFFSET           (*(volatile unsigned long*)0x4A000014)
#define SUBSRCPND           (*(volatile unsigned long*)0x4A000018)
#define INTSUBMSK           (*(volatile unsigned long*)0x4A00001c)

/* external interrupt registers */
#define EINTMASK            (*(volatile unsigned long*)0x560000a4)
#define EINTPEND            (*(volatile unsigned long*)0x560000a8)

#define GSTATUS1            (*(volatile unsigned int*)0x560000B0)

/*clock registers*/
#define LOCKTIME            (*(volatile unsigned long*)0x4c000000)
#define MPLLCON             (*(volatile unsigned long*)0x4c000004)
#define UPLLCON             (*(volatile unsigned long*)0x4c000008)
#define CLKCON              (*(volatile unsigned long*)0x4c00000c)
#define CLKSLOW             (*(volatile unsigned long*)0x4c000010)
#define CLKDIVN             (*(volatile unsigned long*)0x4c000014)

/*PWM & Timer registers*/
#define TCFG0               (*(volatile unsigned long*)0x51000000)
#define TCFG1               (*(volatile unsigned long*)0x51000004)
#define TCON                (*(volatile unsigned long*)0x51000008)
#define TCNTB0              (*(volatile unsigned long*)0x5100000c)
#define TCMPB0              (*(volatile unsigned long*)0x51000010)
#define TCNTO0              (*(volatile unsigned long*)0x51000014)
#define TCNTB4              (*(volatile unsigned long*)0x5100003c)
#define TCNTO4              (*(volatile unsigned long*)0x51000040)

#define GPx0_IN             (0x00 << (0 * 2))
#define GPx2_IN             (0x00 << (2 * 2))
#define GPx3_IN             (0x00 << (3 * 2))

#define GPx4_OUT            (0x01 << (4 * 2))
#define GPx5_OUT            (0x01 << (5 * 2))
#define GPx6_OUT            (0x01 << (6 * 2))

#define GPx0_EINT           (0x02 << (0 * 2))
#define GPx1_EINT           (0x02 << (1 * 2))
#define GPx2_EINT           (0x02 << (2 * 2))
#define GPx3_EINT           (0x02 << (3 * 2))

#define INT_TIMER0 10
#define INT_TIMER1 11
#define INT_TIMER2 12
#define INT_TIMER3 13
#define INT_TIMER4 14

#define GPxFULL_MASK 0xffffffff

#define GPx0_UP_DISABLE (1 << 0)
#define GPx1_UP_DISABLE (1 << 1)
#define GPx2_UP_DISABLE (1 << 2)
#define GPx3_UP_DISABLE (1 << 3)
#define GPx4_UP_DISABLE (1 << 4)
#define GPx5_UP_DISABLE (1 << 5)
#define GPx6_UP_DISABLE (1 << 6)
#define GPx7_UP_DISABLE (1 << 7)
