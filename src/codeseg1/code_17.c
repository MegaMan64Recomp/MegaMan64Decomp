#include "common.h"

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_17", func_800328E0);

s32 func_800328E0(s32 retraceNum) {
    
    if(retraceNum < 0){
        return 0;
    } 

    if(retraceNum == 1){
        return 0;
    }

    if(retraceNum == 0){
        nuGfxRetraceWait(1);
    } else {
        nuGfxRetraceWait(retraceNum);
    }

    return 0;
}
