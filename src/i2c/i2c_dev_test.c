#include "i2c.h"


bit i2c_dev_test (void)
{
    bit result;
    
    i2c_start();
    result = i2c_byte_write(0xa0);
    i2c_stop();
    
    return result;
}
