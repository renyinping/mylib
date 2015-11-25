#include "cfg/i2c_cfg.h"


/* i2c总线启动 */
void i2c_start (void)
{
    i2c_scl_out(1);
    i2c_sda_out(1);
    i2c_clock_wait();
    
    i2c_sda_out(0);
    i2c_clock_wait();
    i2c_scl_out(0);
    i2c_clock_wait();
}


/* i2c总线停止 */
void i2c_stop (void)
{
    i2c_sda_out(0);
    i2c_clock_wait();
    
    i2c_scl_out(1);
    i2c_clock_wait();
    i2c_sda_out(1);
    i2c_clock_wait();
}


/* i2c总线位操作 */
bit i2c_bit_rw (bit b)
{
    bit result;
    
    i2c_sda_out(b);
    i2c_clock_wait();
    i2c_scl_out(1);
    i2c_clock_wait();
    if(b) result = i2c_sda_in();
    i2c_scl_out(0);
    i2c_clock_wait();
    
    return result;
}

