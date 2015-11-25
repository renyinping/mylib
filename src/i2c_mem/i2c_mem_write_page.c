#include "i2c.h"


#define PAGE_SIZE 8


int i2c_mem_write_page (const unsigned char* buf, unsigned int buf_size, unsigned int addr)
{
    int result;
    unsigned char addrh, addrl, len;
    
    addrh = (unsigned char)(addr >> 7) & 0x0e;
    addrl = (unsigned char)addr;
    
    len = PAGE_SIZE - (addr & (PAGE_SIZE - 1));
    len = (buf_size > len) ? len : buf_size;
    
    result = len;
    
    i2c_start();
    
    if(i2c_byte_write(addrh | 0xa0))
    {
        i2c_stop();
        return -1;
    }
    
    if(i2c_byte_write(addrl))
    {
        i2c_stop();
        return -1;
    }
    
    for(;len>0;len--)
    {
        if(i2c_byte_write(*buf))
        {
            i2c_stop();
            return -1;
        }
        buf++;
    }
    
    i2c_stop();
    return result;
}
