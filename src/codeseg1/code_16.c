#include "common.h"
#include <nusys.h>

// Data
s16 D_800A8850 = -1;

// externs
extern MATRIX gRotMatrix;
extern VECTOR gTransMatrix;
// extern u32 nuGfxTaskSpool;

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FD30);
UIStackHeader* func_8002FD30(UIStackHeader* stackTail, UIStackHeader* stackNew) {
    stackNew->header = stackNew->bitfield.flag | stackTail->bitfield.prev << 8;
    return stackTail->header = stackTail->bitfield.flag | (u32)stackNew << 8;
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FD5C);

void* func_8002FD88(void* arg0) {
    return arg0;
}
void* func_8002FD90(void* arg0) {
    return arg0;
}

void* func_8002FD98(void* arg0) {
    return arg0;
}

void* func_8002FDA0(void* arg0) {
    return arg0;
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FDA8);
s32 func_8002FDA8(int arg0) {
    if (arg0 != 0) {
        return nuGfxTaskSpool;
    } else {
        return 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FDC0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FDF4);

void func_80028470(s32);                                 /* extern */
void func_80028600(s32, Mtx*, u16);                      /* extern */
void func_800288D8(s32, Mtx*);                           /* extern */
void func_8002891C(s32);                                 /* extern */
void func_80028978(s32);                                 /* extern */
void func_80028A00(s8, s32, s32);                        /* extern */
void guPerspective(Mtx*, u16*, f32, f32, f32, f32, f32); /* extern */
// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030150);
s32 func_80030150(s32 arg0) {
    Mtx identMtx;
    Mtx projectionMtx;
    u16 perspNorm;

    if (arg0 != 1) {
        func_80028470(0);
        func_8002891C(0);
        func_80028978(0);
        func_80028A00(0, 9, 1);
        guPerspective(&projectionMtx, &perspNorm, 37.5f, 1.3333334f, 192.0f, 7168.0f, 1.0f);
        func_80028600(0, &projectionMtx, perspNorm);
        guMtxIdent(&identMtx);
        func_800288D8(0, &identMtx);
    }
    return 0;
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030204);
s32 func_80030204() {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8003020C);

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030264);
s32 func_80030264() {
    return 0;
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8003026C);
u32 func_8003026C(s32 arg0, u32 arg1) {
    return ((arg1 << 6) | ((arg0 >> 4) & 0x3F)) & 0xFFFF;
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030284);
s32 func_80030284(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return ((arg0 & 3) << 7) | ((arg1 & 3) << 5) | ((s32)(arg3 & 0x100) >> 4) | ((s32)(arg2 & 0x3FF) >> 6) |
           ((arg3 & 0x200) * 4);
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800302C0);
s32 func_800302C0() {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800302C8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800302F4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030320);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030334);

extern void func_8002CB20;
extern void func_8002CC58;
extern void func_8002E16C;
extern void func_8002E8FC;
extern void func_8002ED90;
extern void func_8002FA3C;
extern void func_8002FB2C;
extern void func_8002FC1C;
extern void func_800306B0;
extern void fadeout_gfx;

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030354_B754);
// ui_enqueue_gfx
void func_80030354(UiElementGeneric* elem, s8 pool, s8 gfxContextIndex) {
    s32 flag;
    UiElementGeneric* gfxData;
    u32 header;
    u32 nextHeader;

    header = elem->header.header;

    if ((header & 0xFFFFFF00) == 0xffffff00) {
        return;
    }

    gfxData = (UiElementGeneric*)((header >> 8) | 0x80000000);

    while (1) {
        flag = gfxData->rgba.c.a & 0xFC;
        switch (flag) {
            case 0xE0:
                func_800283A8(pool, gfxContextIndex, &func_800306B0, gfxData);
                break;
            case 0xD0:
                func_800283A8(pool, gfxContextIndex, &func_8002E8FC, gfxData);
                break;
            case 0xC0:
                func_800283A8(pool, gfxContextIndex, &fadeout_gfx, gfxData);
                break;
            case 0x28:
                func_800283A8(pool, gfxContextIndex, &func_8002FA3C, gfxData);
                break;
            case 0x2C:
                func_800283A8(pool, gfxContextIndex, &func_8002E16C, gfxData);
                break;
            case 0x30:
                func_800283A8(pool, gfxContextIndex, &func_8002FB2C, gfxData);
                break;
            case 0x38:
                func_800283A8(pool, gfxContextIndex, &func_8002ED90, gfxData);
                break;
            case 0x60:
                func_800283A8(pool, gfxContextIndex, &func_8002FC1C, gfxData);
                break;
            case 0x64:
                func_800283A8(pool, gfxContextIndex, &func_8002CB20, gfxData);
                break;
            case 0x74:
                func_800283A8(pool, gfxContextIndex, &func_8002CC58, gfxData);
                break;
        }
        nextHeader = gfxData->header.header;
        if ((nextHeader & 0xFFFFFF00) == 0xffffff00) {
            break;
        }
        gfxData = (UiElementGeneric*)((nextHeader >> 8) | 0x80000000);
    };
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030518);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030548);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8003055C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030574);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030588);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8003059C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800305BC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800305D0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800305E4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030600);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030614);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030628);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8003064C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030660);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030674);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030688);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8003069C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800306B0);

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800306C0);
void func_800306C0(void) {
    func_8002C654(&gRotMatrix);
    bzero(&gTransMatrix, 0x10);
    return;
}