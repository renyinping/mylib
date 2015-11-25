#include "uart.h"


/* putchar */
char putchar (char c)
{
    if ('\n' == c) while(uart_tx_byte(0x0d));
    while(uart_tx_byte(c));
    return c;
}
