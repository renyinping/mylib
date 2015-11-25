#include "i2c.h"


bit i2c_mem_read (unsigned char* buf, unsigned int buf_size, unsigned int addr)
{
    int len;
    
    for(;buf_size>0;)
    {
        len = i2c_mem_read_page(buf, buf_size, addr);
        if(0 > len) return 1;
        addr += len;
        buf  += len;
        buf_size -= len;
    }
    
    return 0;
}
