#define UART_BAUD   9600       /* 串口波特率 */
#define UART_SPEED  1          /* 允许(1)或禁止(0)波特率翻倍 */
#define UART_T1CLK  12         /* STC定时器1时钟源分频比: 1 或者 12 */
#define UART_INT_EN 0          /* 允许(1)或禁止(0)串口中断使能 */
#define UART_INT_ID 4          /* 串口中断号-ID */


#define UART_RX_BUF_SIZE 8     /* 串口接收数据缓冲区大小 2,4,8,16,32,64,128 */
#define UART_TX_BUF_SIZE 8     /* 串口发送数据缓冲区大小 2,4,8,16,32,64,128 */
