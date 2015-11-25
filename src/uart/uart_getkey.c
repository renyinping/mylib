#include "uart.h"


/* _getkey */
char _getkey (void)
{
    char c;
    
    while(uart_rx_byte(&c));
    return c;
}
