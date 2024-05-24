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

.text 
.global _start
_start:
    b Reset

@ 未定义指令中止模式的向量地址
HandleUnder:
	b HandleUnder

@ 管理模式的向量地址
HandleSWI:
	b HandleSWI

@ 指令预取异常的向量地址
HanledPrefetchAbort:	
	b HanledPrefetchAbort

@ 数据访问异常的向量地址
HandleDataAbort:
	b HandleDataAbort

@ 保留
HandleNotUsed:
	b HandleNotUsed

@ 中断模式向量地址
	b HandleIRQ

@ 快速中断模式的向量地址
HandleFIQ:
	b HandleFIQ

Reset:
    ldr sp, =4096           @ 设置栈指针，以下都是C函数，调用前需要设好栈
    bl  disable_watch_dog   @ 关闭WATCHDOG，否则CPU会不断重启
    bl  clock_init          @ 设置系统时钟
    bl  init_led

    msr cpsr_c, #0xd2       @ 进入中断模式，设置中断模式栈指针
    ldr sp, =2048
    msr cpsr_c, #0xd3       @ 进入管理模式，设置管理模式栈指针
    ldr sp, =4096

    bl  timer4_init         @ 配置TIMER0定时器
    bl  init_irq            @ 使能中断

    msr cpsr_c, #0x53       @ 设置I-bit=0，开IRQ中断
    ldr lr, =halt_loop      @ 设置返回地址
    ldr pc, =main           @ 调用main函数

halt_loop:
    b   halt_loop

HandleIRQ:
	sub lr, lr, #4
	stmdb sp!, {r0-r12,lr}  @ 保存寄存器的值

	ldr lr, =int_return 
	ldr pc, =timer4_handle
	
int_return: 
	ldmia sp!, {r0-r12,pc}^ @ 中断返回, ^表示将spsr的值复制到cpsr

