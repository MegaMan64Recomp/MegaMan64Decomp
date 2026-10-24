#include "common.h"

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_65", func_80081380);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_65", func_80081398);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_65", func_80081688);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_65", func_80081778);


void func_80028220(s8, s8, void*, void*, s32);       /* extern */
void func_800283A8(s8, s8, void*, void*);            /* extern */
void func_8002C5A4(MATRIX*, Mtx*);                 /* extern */
extern void func_800805F8;
typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ char pad3[0x9];
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 unkD;
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 unkF;
    /* 0x10 */ u8 unk10;
    // /* 0x11 */ char pad11[0x3];
    /* 0x14 */ void* unk14;
    /* 0x18 */ Mtx mtx;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u16 unk64;
    /* 0x66 */ u8 unk66;
    /* 0x67 */ u8 unk67;
} ActorBuffer;

typedef struct {
    /* 0x00 */ char pad0[0xC];
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 unkD;
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 unkF;
} UnkStruct2;

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_65", func_800817BC);
void func_800817BC(s8 arg0, s8 arg1, s16 arg2, MATRIX* arg3, UnkStruct2* arg4, u16 arg5, u8 arg6, u8 arg7) {
    ActorBuffer* buff;
    
    buff = gfx_task_pool_alloc(sizeof(ActorBuffer));
    if (buff != NULL) {
        buff->unk0 = arg2;
        func_8002C5A4(arg3, &buff->mtx);
        buff->unkC = arg4->unkF;
        buff->unkD = 1;
        buff->unk2 = 0xFF;
        buff->unkE = arg4->unkD;
        buff->unkF = arg4->unkE | ((arg5 & 0x8000) >> 15);;
        buff->unk64 = arg5 & 0x7FFF;
        buff->unk10 = arg4->unkC;
        buff->unk14 = arg4;
        buff->unk60 = 0;
        buff->unk5C = 0;
        buff->unk66 = arg6;
        buff->unk67 = arg7;
        buff->unk58 = 0;
        
        if (buff->unkF != 0) {
            func_80028220(arg0, arg1, &func_800805F8, buff, (u16)arg3->t[2]);
        } else {
            func_800283A8(arg0, arg1, &func_800805F8, buff);
        }
    }
    return;
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_65", func_8008190C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_65", func_80081A88);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_65", func_80081A90);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_65", func_80082C70);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_65", func_80082F9C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_65", func_80082FA4);
