#include "i2c.h"


void i2c_dev_wait_offline (void)
{
    unsigned char result = 0;
    
    for(;0x0f != result;)
    {
        result <<= 1;
        result &= 0xfe;
        result |= i2c_dev_test();
    }
}
