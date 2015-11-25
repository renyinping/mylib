#include <reg51.h>


sbit SCL = P2^1;
sbit SDA = P2^2;


#define i2c_scl_out(b)    do{SCL = b;}while(0);
#define i2c_sda_out(b)    do{SDA = b;}while(0);
#define i2c_sda_in()      SDA
#define i2c_clock_wait()  do{unsigned char i=5;while(--i);}while(0);
