#include "i2c.h"


#define PAGE_SIZE 16


bit i2c_mem_verify (const unsigned char* buf, unsigned int buf_size, unsigned int addr)
{
    unsigned char tmp[PAGE_SIZE];
    unsigned char len;
    unsigned char i;
    
    for(;buf_size>0;)
    {
        len = (buf_size > PAGE_SIZE) ? PAGE_SIZE : buf_size;
        if(i2c_mem_read(tmp, len, addr)) return 1;
        
        for(i=0;i<len;i++)
        {
            if(tmp[i] != buf[i]) return 1;
        }
        
        buf      += len;
        addr     += len;
        buf_size -= len;
    }
    
    return 0;
}
