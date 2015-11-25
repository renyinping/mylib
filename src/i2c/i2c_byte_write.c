#include "i2c.h"


/* i2c总线字节写 */
bit i2c_byte_write (unsigned char c)
{
    unsigned char i;
    
    for(i=0;i<8;i++)
    {
        i2c_bit_rw(0x80&c);
        c <<= 1;
    }
    
    return i2c_bit_rw(1);
}
