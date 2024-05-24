#include "s3c24x0.h"

/*
 * 对于MPLLCON寄存器，[19:12]为MDIV，[9:4]为PDIV，[1:0]为SDIV
 * 有如下计算公式：
 *  S3C2410: MPLL(FCLK) = (2 * m * Fin)/(p * 2^s)
 *  其中: m = MDIV + 8, p = PDIV + 2, s = SDIV
 * 对于本开发板，Fin = 12MHz
 */
#define S3C2440_MPLL_200MHZ     ((0x5c<<12)|(0x01<<4)|(0x02))

void disable_watch_dog()
{
	WTCON = 0;

    return;
}

void init_led()
{
    // GPF4/5/6引脚连接LED1/2/4，当输出低电平时LED点亮，同时作为输出引脚时关闭内部上拉
    GPFUP |= (GPx4_UP_DISABLE | GPx5_UP_DISABLE | GPx6_UP_DISABLE);
    GPFCON |= (GPx4_OUT | GPx5_OUT | GPx6_OUT);

    GPFDAT = 0x0;
    return;
}

void init_irq()
{
	INTMSK &= (~(1<<INT_TIMER4));     /* 使能INT_TIMER4中断 */

    return;
}

/*
 * 设置CLKDIVN，令分频比为：FCLK:HCLK:PCLK=1:2:4，
 * FCLK=200MHz,HCLK=100MHz,PCLK=50MHz
 */
void clock_init(void)
{
    // LOCKTIME = 0x00ffffff;                   /* 使用默认值即可 */
    CLKDIVN  = 0x03;                            /* FCLK:HCLK:PCLK=1:2:4, HDIVN=1, PDIVN=1 */

    /* 如果HDIVN非0，CPU的总线模式应该从“fast bus mode”变为“asynchronous bus mode” */
    __asm__(
        "mrc    p15, 0, r1, c1, c0, 0\n"        /* 读出控制寄存器 */ 
        "orr    r1, r1, #0xc0000000\n"          /* 设置为“asynchronous bus mode” */
        "mcr    p15, 0, r1, c1, c0, 0\n"        /* 写入控制寄存器 */
    );

    MPLLCON = S3C2440_MPLL_200MHZ;              /* FCLK=200MHz,HCLK=100MHz,PCLK=50MHz */
    
    return;
}

void timer4_init(void)
{
    /* 
     * 设置分频系数prescaler和divider 
     * Timer输入时钟 = PCLK / (prescaler + 1) / divider = 50MHz / 100 / 16 = 31250Hz
     */
	TCFG0 = (0x63 << 8);         
	TCFG1 = (0x03 << 16);
	TCNTB4 = 31250;  /* 定时器间隔时间1s */

    /* 首次需手动更新TCNTB4 */
    TCON = (TCON & (~(0x0f<<20))) | (0x02<<20);

    /* 设置timer4自动装载并启动timer4 */
    TCON = (TCON & (~(0x0f<<20))) | (0x05<<20);
}
