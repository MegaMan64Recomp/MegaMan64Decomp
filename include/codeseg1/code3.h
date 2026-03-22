#ifndef _CODE3_H_
#define _CODE3_H_
#define F3DEX_GBI_2X
#include "PR/gbi.h"

#define FILL_COLOR(r, g, b) (((GPACK_RGBA5551(r, g, b, 0) | 1) << 16) | (GPACK_RGBA5551(r, g, b, 0) | 1))

typedef void (*ArenaFunc)(void* arg);

typedef struct ArenaFuncNode{
    struct ArenaFuncNode* next;
    struct ArenaFuncNode* prev;
    ArenaFunc func;
    void* arg;
    s8 arenaIndex;
    s8 unk11;
    s16 unk12;
    s32 unk14;
} ArenaFuncNode;

typedef union {
    struct {
        u8 r, g, b, a;
    } color;
    u32 word;
} RGBA_u32;

typedef struct {
    Gfx* dls[2];
} GfxBuffers;

typedef struct GfxContext {
    /* 0x00 */ ArenaFuncNode* arenaStart[16];
    /* 0x40 */ ArenaFuncNode* arenaNext[16];
    /* 0x80 */ s16 unk_80;
    /* 0x82 */ s16 unk_82;
    /* 0x84 */ s16 unk_84;
    /* 0x86 */ s16 unk_86;
    /* 0x88 */ s16 unk_88;
    /* 0x8A */ s16 unk_8A;
    /* 0x8C */ s16 uly;
    /* 0x8E */ s16 ulx;
    /* 0x90 */ s16 lrx;
    /* 0x92 */ s16 lry;
    /* 0x94 */ s16 fogStart;
    /* 0x96 */ s16 fogEnd;
    /* 0x98 */ s8 fogRed;
    /* 0x99 */ s8 fogGreen;
    /* 0x9A */ s8 fogBlue;
    /* 0x9B */ s8 fogAlpha;
    /* 0x9C */ RGBA_u32 rgba;
    // /* 0x9D */ s8 primGreen;
    // /* 0x9E */ s8 primBlue;
    // /* 0x9F */ s8 primAlpha;
    /* 0xA0 */ s8 primAlpha2;
    /* 0xA1 */ s8 fadeoutTimer;
    /* 0xA2 */ s8 unk_A2;
    /* 0xA3 */ s8 unk_A3;
    // /* 0xA4 */ RGBA bgPrimRGBA;
    /* 0xA4 */ u8 bgPrimRed;
    /* 0xA5 */ u8 bgPrimGreen;
    /* 0xA6 */ u8 bgPrimBlue;
    /* 0xA7 */ s8 bgPrimAlpha;
    /* 0xA8 */ s8 unk_A8;
    /* 0xA9 */ s8 hiResEnabled;
    /* 0xAA */ s8 bufferEnabled;
    /* 0xAB */ s8 bufferNum;
    /* 0xAC */ s8 unk_AC;
    /* 0xAD */ s8 unk_AD;
    /* 0xAE */ s8 unk_AE;
    /* 0xAF */ s8 unk_AF;
    /* 0xB0 */ Vp viewport;
    /* 0xC0 */ Mtx mtx;
    /* 0x100 */ Mtx viewFrustum;
    /* 0x140 */ u16 perspNorm;
    /* 0x142 */ s16 unk_142;
    /* 0x144 */ s32 unk_144[16];
} GfxContext; // size = 0x188;

extern u32 D_800D6FBC_B23BC;
extern s32 D_80193C30_16F030;
extern s32 D_801A53D8_1807D8;
extern s32 D_801ADC84_189084;
extern s32 D_801BC17C_19757C;
extern s32 D_800A6CA0_820A0;
// extern s32 D_800A6CA4_820A4;
// extern s32 D_800A6CA8_820A8;
extern void* D_80210980_1EBD80;
extern GfxContext D_802047F0_1DFBF0;
extern GfxContext* D_8019A6A4_175AA4;
extern ArenaFuncNode* D_800D6FA0_B23A0;
extern ArenaFuncNode* D_800D6FA4_B23A4;
extern ArenaFuncNode* D_800D6FA8_B23A8;
extern void* D_800D6FAC_B23AC;
extern s8 D_8020489B_1DFC9B;
extern u8 D_8020559C_1E099C;
extern Mtx D_801AF370_18A770;
extern Gfx D_80224E80;
extern Gfx D_80224F68;
extern u16 D_800A6C9A_8209A;
extern u16 D_800A6C9C_8209C;
extern void* D_800D6FB8_B23B8;
extern GfxBuffers D_800D6FB0_B23B0;
extern Gfx* D_801A90F0_1844F0;
extern Gfx D_800D6FC0_B23C0 [15360];
extern Gfx D_800F4FC0_D03C0 [15360];
extern s64 D_A4770[];
extern s64 D_A5B00[];
extern s64 D_D1450[];
extern s64 D_D1870[];
extern void* func_800281C8_35C8(s32);
extern void func_8002CAD0_7ED0(); 
extern int func_80089EA0_652A0();  
extern void func_80092C6C_6E06C(Gfx*, u32, s32, u32);  

#endif