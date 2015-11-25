#include "i2c.h"


void i2c_mem_write_wait (void)
{
    unsigned int i = 1000;
    while(--i);
}


bit i2c_mem_write (const unsigned char* buf, unsigned int buf_size, unsigned int addr)
{
    int len;
    
    for(;buf_size>0;)
    {
        len = i2c_mem_write_page(buf, buf_size, addr);
        if(0 > len) return 1;
        addr += len;
        buf  += len;
        buf_size -= len;
        
        i2c_mem_write_wait();
    }
    
    return 0;
}
