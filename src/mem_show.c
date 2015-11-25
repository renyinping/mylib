#include <stdio.h>
#include <ctype.h>


void mem_show (unsigned char* buf, unsigned char len, unsigned int addr)
{
    unsigned char i;
    
    if(0x10>addr) printf("\n000");  //地址
    else if(0x100>addr) printf("\n00");
    else if(0x1000>addr) printf("\n0");
    printf("%X: ", addr & 0xfff0);
    
    for(i=0; i<(addr & 0x0f); i++) printf("   ");  //hex
    for(; i<(len+(addr & 0x0f)); i++)
    {
        if(0x10>buf[i]) printf("0"); 
        printf("%BX ", buf[i]);
    }
    for(; i<16;i++) printf("   ");
    
    for(i=0;i<(addr & 0x0f);i++) printf(" ");  //ASCII
    for(; i<(len+(addr & 0x0f)); i++) printf("%c", isprint(buf[i]) ? buf[i] : ' ');
    for(;i<16;i++) printf(" ");
}
