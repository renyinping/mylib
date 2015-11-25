#ifndef __UART_H__
#define __UART_H__ 1


extern char uart_tx_byte (unsigned char c);
extern char uart_rx_byte (unsigned char* c);


extern void uart_init (void);


#endif
