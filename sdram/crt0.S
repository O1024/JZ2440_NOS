/**
 * @file crt0.S
 * @author wenchen (wenchen.mails@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-05-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */

.equ WTCON,         0x53000000
.equ MEM_CTL_BASE,  0x48000000
.equ SDRAM_BASE,    0x30000000

.text
.global _start
_start:
    ldr sp, =4096
    bl  disable_watch_dog
    bl  mem_ctl_setup
    bl  copy_steppingstone_to_sdram
    ldr pc, =on_sdram

disable_watch_dog:
    mov r1, #WTCON
    mov r2, #0x0
    str r2, [r1]  /* *r1 = r2 */
    mov pc, lr

mem_ctl_setup:
    adrl r1, mem_cfg_val /* r1 = &mem_cfg_val */
    mov r2, #MEM_CTL_BASE
    add r3, r1, #4*13
1:
    ldr r4, [r1],#4  /* r4 = &r1, r1 += 4 */
    str r4, [r2],#4  /* *r2 = r4, r2 += 4 */
    cmp r1, r3
    bne 1b
    mov pc, lr

.align 4
mem_cfg_val:
    @ 存储控制器13个寄存器的设置值
    .long   0x22011110      @ BWSCON
    .long   0x00000700      @ BANKCON0
    .long   0x00000700      @ BANKCON1
    .long   0x00000700      @ BANKCON2
    .long   0x00000700      @ BANKCON3  
    .long   0x00000700      @ BANKCON4
    .long   0x00000700      @ BANKCON5
    .long   0x00018005      @ BANKCON6
    .long   0x00018005      @ BANKCON7
    .long   0x008C07A3      @ REFRESH
    .long   0x000000B1      @ BANKSIZE
    .long   0x00000030      @ MRSRB6
    .long   0x00000030      @ MRSRB7     


copy_steppingstone_to_sdram:
    mov r1, #0
    ldr r2, =SDRAM_BASE
    add r3, r1, #4096
1:  
    ldr r4, [r1],#4  /* r4 = &r1, r1 += 4 */
    str r4, [r2],#4  /* *r2 = r4, r2 += 4 */
    cmp r1, r3
    bne 1b
    mov pc, lr

on_sdram:
    ldr sp, =0x34000000
    ldr pc, =main
    
halt_loop:
    b   halt_loop

