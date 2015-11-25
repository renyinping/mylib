#include <reg51.h>
#include "cfg/cpu_cfg.h"
#include "cfg/uart_cfg.h"


sfr AUXR = 0x8E;   /* 0000,0000 STC15-MCU 辅助寄存器 */


/* 串口初始化 */
void uart_init (void)
{
    ES    = 0;
    TR1   = 0;

    SCON  = 0;
    SCON |= 0x50;
    TMOD &= 0x0f;
    TMOD |= 0x20;

#if UART_SPEED > 0
        PCON |= 0x80;
#else
        PCON &= 0x7f;
#endif

    // STC 定时器1时钟源分频比
#if UART_T1CLK == 1
        AUXR |= 0x40; // 1T
#else
        AUXR &= 0xbf; // 12T
#endif

    AUXR &= 0xfe; // 串口1选择定时器1作为波特率发生器

#if UART_SPEED > 0
        TH1 = 256-(unsigned char)((float)(FOSC)/(UART_T1CLK)/16/(UART_BAUD)+0.5);
#else
        TH1 = 256-(unsigned char)((float)(FOSC)/(UART_T1CLK)/32/(UART_BAUD)+0.5);
#endif

    ET1 = 0; // 关定时器中断
    TR1 = 1;

    // 初始化串口接收数据缓冲区
#if UART_INT_EN > 0
    RI = 0;
    TI = 0;
    ES = 1;
#else
    ES = 0;
    RI = 0;
    TI = 1;
#endif
}
