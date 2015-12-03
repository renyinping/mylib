#include "uart.h"
#include <stdio.h>


#define DEL        0x7F
#define BACKSPACE  0x08
#define CR         0x0D
#define LF         0x0A

#define XON        0x11
#define XOFF       0x13


unsigned char getline (unsigned char* buf, unsigned char len)
{
    static unsigned char cnt;
           unsigned char c;
    
    while(0 == uart_rx_byte(&c))
    {
        /* 换行符 */
        if((LF == c) || (CR == c))
        {
            unsigned char count;
            buf[cnt] = 0;
            count = cnt;
            cnt = 0;
            return count;
        }
        
        /* 右边界 */
        if(cnt == (len-1)) continue;
        
        /* 空格 */
        if(' ' == c)
        {
            if(0 == cnt) continue;
            if(' ' == buf[cnt-1]) continue;
            buf[cnt] = ' ';
            cnt++;
            putchar(' ');
            continue;
        }
        
        /* 退格 */
        if(((DEL == c) || (BACKSPACE == c)) && (0 != cnt))
        {
            putchar(BACKSPACE);
            putchar(' ');
            putchar(BACKSPACE);
            continue;
        }
        
        if((XON != c) && (XOFF != c))
        {
            buf[cnt] = c;
            cnt++;
            putchar(c);
            continue;
        }
    }
    
    return 0;
}
