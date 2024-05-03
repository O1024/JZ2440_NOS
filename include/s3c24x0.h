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
#define MEM_CTL_BASE 0x48000000
#define SDRAM_BASE 0x30000000

/* WOTCH DOG register */
#define WTCON (*(volatile unsigned long*)0x53000000)

/* GPIO registers */
#define GPBCON (*(volatile unsigned long*)0x56000010)
#define GPBDAT (*(volatile unsigned long*)0x56000014)

#define GPFCON (*(volatile unsigned long*)0x56000050)
#define GPFDAT (*(volatile unsigned long*)0x56000054)
#define GPFUP (*(volatile unsigned long*)0x56000058)

#define GPGCON (*(volatile unsigned long*)0x56000060)
#define GPGDAT (*(volatile unsigned long*)0x56000064)
#define GPGUP (*(volatile unsigned long*)0x56000068)

#define GPHCON (*(volatile unsigned long*)0x56000070)
#define GPHDAT (*(volatile unsigned long*)0x56000074)
#define GPHUP (*(volatile unsigned long*)0x56000078)

/* UART registers */
#define ULCON0 (*(volatile unsigned long*)0x50000000)
#define UCON0 (*(volatile unsigned long*)0x50000004)
#define UFCON0 (*(volatile unsigned long*)0x50000008)
#define UMCON0 (*(volatile unsigned long*)0x5000000c)
#define UTRSTAT0 (*(volatile unsigned long*)0x50000010)
#define UTXH0 (*(volatile unsigned char*)0x50000020)
#define URXH0 (*(volatile unsigned char*)0x50000024)
#define UBRDIV0 (*(volatile unsigned long*)0x50000028)

/* interrupt registes */
#define SRCPND (*(volatile unsigned long*)0x4A000000)
#define INTMOD (*(volatile unsigned long*)0x4A000004)
#define INTMSK (*(volatile unsigned long*)0x4A000008)
#define PRIORITY (*(volatile unsigned long*)0x4A00000c)
#define INTPND (*(volatile unsigned long*)0x4A000010)
#define INTOFFSET (*(volatile unsigned long*)0x4A000014)
#define SUBSRCPND (*(volatile unsigned long*)0x4A000018)
#define INTSUBMSK (*(volatile unsigned long*)0x4A00001c)

/* external interrupt registers */
#define EINTMASK (*(volatile unsigned long*)0x560000a4)
#define EINTPEND (*(volatile unsigned long*)0x560000a8)

#define GSTATUS1 (*(volatile unsigned int*)0x560000B0)

#define GPF0_IN (0 << (0 * 2))
#define GPF2_IN (0 << (2 * 2))
#define GPG3_IN (0 << (3 * 2))

#define GPF4_OUT (1 << (4 * 2))
#define GPF5_OUT (1 << (5 * 2))
#define GPF6_OUT (1 << (6 * 2))

#define GPF0_MASK (3 << (0 * 2))
#define GPF1_MASK (3 << (1 * 2))
#define GPF2_MASK (3 << (2 * 2))
#define GPF3_MASK (3 << (3 * 2))
#define GPF4_MASK (3 << (4 * 2))
#define GPF5_MASK (3 << (5 * 2))
#define GPF6_MASK (3 << (6 * 2))

#define GPG3_MASK (3 << (3 * 2))

/* S2,S3,S4对应GPF0、GPF2、GPG3 */
#define GPF0_EINT (0x2 << (0 * 2))
#define GPF2_EINT (0x2 << (2 * 2))
#define GPG3_EINT (0x2 << (3 * 2))

#define GPF0_MASK (3 << (0 * 2))
#define GPF2_MASK (3 << (2 * 2))
