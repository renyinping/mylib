#include "i2c.h"


void i2c_dev_wait_online (void)
{
    unsigned char result = 0xff;
    
    for(;0 != result;)
    {
        result <<= 1;
        result &= 0xfe;
        result |= i2c_dev_test();
    }
}
