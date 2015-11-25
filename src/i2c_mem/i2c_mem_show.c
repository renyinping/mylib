#include "i2c.h"
#include <stdio.h>
#include "mylib.h"


#define PAGE_SIZE 16


void i2c_mem_show (unsigned int buf_size, unsigned int addr)
{
    unsigned char tmp[PAGE_SIZE];
    unsigned char len;
    
    printf("Addr:  0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F");
    
    for(;buf_size>0;)
    {
        len = PAGE_SIZE - (addr & (PAGE_SIZE - 1));
        len = (buf_size > len) ? len : buf_size;
        
        if(i2c_mem_read(tmp + (addr & (PAGE_SIZE - 1)), len, addr))
        {
            printf("\n      I2C Memory read error.");
            return;
        }
        
        mem_show(tmp, len, addr);
        
        addr     += len;
        buf_size -= len;
    }
    
    printf("\n");
}
