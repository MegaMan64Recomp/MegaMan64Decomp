#include "common.h"

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FD30_B130);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FD5C_B15C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FD88_B188);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FD90_B190);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FD98_B198);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FDA0_B1A0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FDA8_B1A8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FDC0_B1C0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FDF4_B1F4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030150_B550);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030204_B604);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8003020C_B60C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030264_B664);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8003026C_B66C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030284_B684);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800302C0_B6C0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800302C8_B6C8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800302F4_B6F4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030320_B720);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030334_B734);

extern void func_8002CB20_7F20;
extern void func_8002CC58_8058;
extern void func_8002E16C_956C;
extern void func_8002E8FC_9CFC;
extern void func_8002ED90_A190;
extern void func_8002FA3C_AE3C;
extern void func_8002FB2C_AF2C;
extern void func_8002FC1C_B01C;
extern void func_800306B0_BAB0;
extern void func_800861E0_615E0;

typedef union {
    struct {
        u8 r, g, b, a;
    } c;
    u32 rgba32;
} RGBA32;

typedef union {
    struct {
        u32 flag : 8;
        u32 prev : 24;
    } bitfield;
    u32 header;
} UIStackHeader;

typedef struct {
    UIStackHeader header;
    RGBA32 rgba;
    void* data;
} UiElementGeneric;

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030354_B754);
// ui_enqueue_gfx
void func_80030354_B754(UiElementGeneric* elem, s8 pool, s8 gfxContextIndex) {
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
                func_800283A8_37A8(pool, gfxContextIndex, &func_800306B0_BAB0, gfxData);
                break;
            case 0xD0:
                func_800283A8_37A8(pool, gfxContextIndex, &func_8002E8FC_9CFC, gfxData);
                break;
            case 0xC0:
                func_800283A8_37A8(pool, gfxContextIndex, &func_800861E0_615E0, gfxData);
                break;
            case 0x28:
                func_800283A8_37A8(pool, gfxContextIndex, &func_8002FA3C_AE3C, gfxData);
                break;
            case 0x2C:
                func_800283A8_37A8(pool, gfxContextIndex, &func_8002E16C_956C, gfxData);
                break;
            case 0x30:
                func_800283A8_37A8(pool, gfxContextIndex, &func_8002FB2C_AF2C, gfxData);
                break;
            case 0x38:
                func_800283A8_37A8(pool, gfxContextIndex, &func_8002ED90_A190, gfxData);
                break;
            case 0x60:
                func_800283A8_37A8(pool, gfxContextIndex, &func_8002FC1C_B01C, gfxData);
                break;
            case 0x64:
                func_800283A8_37A8(pool, gfxContextIndex, &func_8002CB20_7F20, gfxData);
                break;
            case 0x74:
                func_800283A8_37A8(pool, gfxContextIndex, &func_8002CC58_8058, gfxData);
                break;
        }
        nextHeader = gfxData->header.header;
        if ((nextHeader & 0xFFFFFF00) == 0xffffff00){
            break;
        }
        gfxData = (UiElementGeneric*)((nextHeader >> 8) | 0x80000000);
    };
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030518_B918);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030548_B948);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8003055C_B95C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030574_B974);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030588_B988);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8003059C_B99C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800305BC_B9BC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800305D0_B9D0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800305E4_B9E4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030600_BA00);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030614_BA14);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030628_BA28);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8003064C_BA4C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030660_BA60);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030674_BA74);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030688_BA88);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8003069C_BA9C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800306B0_BAB0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800306C0_BAC0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800306F0_BAF0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8003077C_BB7C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030834_BC34);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800308E8_BCE8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030AA0_BEA0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031270_C670);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031428_C828);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031600_CA00);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800317C0_CBC0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800318C8_CCC8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031938_CD38);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800319B4_CDB4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031AC0_CEC0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031B40_CF40);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031BB4_CFB4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031CBC_D0BC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031D38_D138);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031DA8_D1A8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031E10_D210);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031E5C_D25C);

void func_80031E84_D284(void) {
}

void func_80031E8C_D28C(void) {
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031E94_D294);

void func_80031EBC_D2BC(void) {
}

void func_80031EC4_D2C4(void) {
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031ECC_D2CC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031F00_D300);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031F0C_D30C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80032068_D468);

void func_800320DC_D4DC(void) {
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800320E4_D4E4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8003216C_D56C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800321EC_D5EC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80032308_D708);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80032424_D824);

void func_80032490_D890(void) {
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80032498_D898);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800324B4_D8B4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800324D0_D8D0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80032510_D910);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80032554_D954);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80032664_DA64);
