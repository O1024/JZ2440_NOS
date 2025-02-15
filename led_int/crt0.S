/**
 * @file crt0.S
 * @author wenchen (wenchen.mails@gmail.com)
 * @brief 初始化，设置中断模式、管理模式栈，设置中断处理函数
 * @version 0.1
 * @date 2024-05-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

.text
.global _start
_start:
@******************************************************************************       
@ 中断异常向量表，本程序除Reset和HandleIRQ外，其它异常都没有使用
@******************************************************************************       
    b   Reset

@ 0x04: 未定义指令中止模式的向量地址
HandleUndef:
    b   HandleUndef 
 
@ 0x08: 管理模式的向量地址，通过SWI指令进入此模式
HandleSWI:
    b   HandleSWI

@ 0x0c: 指令预取终止导致的异常的向量地址
HandlePrefetchAbort:
    b   HandlePrefetchAbort

@ 0x10: 数据访问终止导致的异常的向量地址
HandleDataAbort:
    b   HandleDataAbort

@ 0x14: 保留
HandleNotUsed:
    b   HandleNotUsed

@ 0x18: 中断模式的向量地址
    b   HandleIRQ

@ 0x1c: 快中断模式的向量地址
HandleFIQ:
    b   HandleFIQ

Reset:                  
    ldr sp, =4096           @ 设置栈指针，以下都是C函数，调用前需要设好栈
    bl  disable_watch_dog   @ 关闭WATCHDOG，否则CPU会不断重启
    
    msr cpsr_c, #0xd2       @ 进入中断模式
    ldr sp, =3072           @ 设置中断模式栈

    msr cpsr_c, #0xd3       @ 进入管理模式
    ldr sp, =4096           @ 设置管理模式栈指针，
                            @ 其实复位之后，CPU就处于管理模式，
                            @ 前面的“ldr sp, =4096”完成同样的功能，此句可省略

    bl  init_led            @ 初始化LED的GPIO管脚
    bl  init_irq            @ 调用中断初始化函数，在init.c中
    msr cpsr_c, #0x53       @ 设置I-bit=0，开IRQ中断
    
    ldr lr, =halt_loop      @ 设置返回地址
    ldr pc, =main           @ 调用main函数

halt_loop:
    b   halt_loop

HandleIRQ:
    sub lr, lr, #4                  @ 计算返回地址，由于ARM的流水线设计，当中断发生时，lr保存的是
                                    @ 当前指令+8的地址。但实际上我们需要在执行完当前指令后再返回，
                                    @ 所以要将lr减4，指向下一条指令

    stmdb   sp!,    { r0-r12,lr }   @ 保存寄存器r0-r12,lr内容
                                    @ 注意，此时的sp是中断模式的sp，初始值是上面设置的3072

    ldr lr, =int_return             @ 设置调用ISR即EINT_Handle函数后的返回地址  
    ldr pc, =EINT_Handle            @ 调用中断服务函数，在interrupt.c中
int_return:
    ldmia   sp!,    { r0-r12,pc }^  @ 中断返回, 将上面保存的lr直接恢复到pc，
                                    @  ^表示将spsr的值复制到cpsr
    
