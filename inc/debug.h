#ifndef __DEBUG_H__
#define __DEBUG_H__ 1

#if defined DEBUG
    #if DEBUG > 0
        #define D(codes) do{codes;}while(0);
    #else
        #define D(codes)
    #endif
#else
    #define D(codes)
#endif

#endif
