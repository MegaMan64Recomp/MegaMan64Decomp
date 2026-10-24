#include "common.h"

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_27", func_8003BD00);
s32* func_8003BD00(s32 *arg0, s32 *arg1, s32 arg2) {
    s32 i;      
  
    for(i = 0; i < arg2; i++, arg1++){
        *arg1 = *arg0++;
    }
    
    return;
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_27", func_8003BD34);
u8* func_8003BD34(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 i;      
  
    for(i = 0; i < arg2 * 16; i++, arg1++){
        *arg1 = *arg0++;
    }
    
    return;
}


// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_27", func_8003BD6C);
u8* func_8003BD6C(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 i;      
  
    for(i = 0; i < arg2 * 32; i++, arg1++){
        *arg1 = *arg0++;
    }
    
    return;
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_27", func_8003BDA4);
void func_8003BDA4(s32* start, s32* end) {
    while (start <= end) {
        *start = 0;
        start++;
    }
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_27", func_8003BDCC);
void func_8003BDCC(s32* start, s32* end) {
    while (start <= end) {
        *start = 0xFFFFFFFF;
        start++;
    }
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_27", func_8003BDF8);
s32 func_8003BDF8(s32* start, s32* end) {
    s32 val = -1;
    while(start <= end) {
        if(val != *start) {
            return 1;
        }
        start++;
   }
    
    return 0;
}
