#include "uart.h"
#include <stdio.h>
#include <ctype.h>
#include "mylib.h"
#include "cfg/project_cfg.h"


code char menu[] = 
   "\n"
   "+ command -+ syntax -----+ function ---------------------------+\n"
   "| Version  | V           | Display version information         |\n"
   "| Show     | S addr len  | Show address length                 |\n"
   "| Read     | R addr len  | Read address length                 |\n"
   "+----------+-------------+-------------------------------------+\n";


void command (void)
{
    static unsigned char buf[20];
           unsigned char n;
           unsigned char i;
    
    n = getline(buf, sizeof(buf));
    if(0 == n) return;
    for(i=0;i<n;i++) buf[i] = toupper(buf[i]);
    printf("\n");
    switch(buf[0])
    {
        case 'V':
            printf("  " VER "\n");
            break;
        
        case 'S':
            printf("  Show\n");
            break;
        
        case 'R':
            printf("  Read\n");
            break;
        
        default:
            printf(menu);
            break;
    }
    printf("\n> ");
}
