#include "i2c.h"


/* i2c总线字节读 */
unsigned char i2c_byte_read (bit b)
{
    unsigned char i;
    unsigned char result = 0;
    
    for(i=0;i<8;i++) 
    {
        result <<= 1;
        result |= i2c_bit_rw(1);
    }
    
    i2c_bit_rw(b);
    
    return result;
}
