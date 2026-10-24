#include "common.h"
#include "nusys.h"

s32 DrawnFramesUnused = 0;
s32 DrawnFrames = 0;
s16 D_800A6C98 = 0;
// SVECTOR screen = { 320, 240, 0, 0 };
s16 ScissorX = 320;
s16 ScissorY = 240;
s32 HiResEnabledBool = 0;
s32 D_800A6CA4 = 0xFFFFFFFF;
s32 additionalScanlines = 0;
// s32 pad = 0;
// s32 unk = 0;

static NUUcode nugfx_ucode[] = {
    {(u64*)gspF3DEX2_fifoTextStart, gspF3DEX2_fifoDataStart},	/*0*/
    {(u64*)gspL3DEX2_fifoTextStart, 0},	/*1*/
};

static u16*	FrameBuf[2] = {
		(u16*)NU_GFX_FRAMEBUFFER0_ADDR,
		(u16*)NU_GFX_FRAMEBUFFER1_ADDR,
};

static Gfx rdpstateinit_dl[] = {

    /* set all of the attribute registers to zero */
    gsDPSetEnvColor(0,0,0,0),
    gsDPSetPrimColor(0,0,0,0,0,0),
    gsDPSetBlendColor(0,0,0,0),
    gsDPSetFogColor(0,0,0,0),
    gsDPSetFillColor(0),
    gsDPSetPrimDepth(0,0),
    gsDPSetConvert(0,0,0,0,0,0),
    gsDPSetKeyR(0,0,0),
    gsDPSetKeyGB(0,0,0,0,0,0),

    /* set combine mode */
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),

    /* initialize the scissor box */
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0,
		   NU_GFX_INIT_SCREEN_WD, NU_GFX_INIT_SCREEN_HT),

    /* initialize all the texture tile descriptors to zero */
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0),

    gsDPSetTileSize(0, 0, 0, (1 - 1) << G_TEXTURE_IMAGE_FRAC, (1 - 1) <<
		G_TEXTURE_IMAGE_FRAC),
    gsDPSetTileSize(1, 0, 0, (1 - 1) << G_TEXTURE_IMAGE_FRAC, (1 - 1) <<
		G_TEXTURE_IMAGE_FRAC),
    gsDPSetTileSize(2, 0, 0, (1 - 1) << G_TEXTURE_IMAGE_FRAC, (1 - 1) <<
		G_TEXTURE_IMAGE_FRAC),
    gsDPSetTileSize(3, 0, 0, (1 - 1) << G_TEXTURE_IMAGE_FRAC, (1 - 1) <<
		G_TEXTURE_IMAGE_FRAC),
    gsDPSetTileSize(4, 0, 0, (1 - 1) << G_TEXTURE_IMAGE_FRAC, (1 - 1) <<
		G_TEXTURE_IMAGE_FRAC),
    gsDPSetTileSize(5, 0, 0, (1 - 1) << G_TEXTURE_IMAGE_FRAC, (1 - 1) <<
		G_TEXTURE_IMAGE_FRAC),
    gsDPSetTileSize(6, 0, 0, (1 - 1) << G_TEXTURE_IMAGE_FRAC, (1 - 1) <<
		G_TEXTURE_IMAGE_FRAC),
    gsDPSetTileSize(7, 0, 0, (1 - 1) << G_TEXTURE_IMAGE_FRAC, (1 - 1) <<
		G_TEXTURE_IMAGE_FRAC),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

extern u8 nuRDPOutputBuf[];

extern u8 D_801DEBE0[0x20000];
extern Gfx* D_801A90F0_1844F0;

extern void* D_800A6CB0;
extern void* D_800A6CB8;
// extern void* D_801DEBE0;
extern Gfx D_A6CC0[]; // rdpstateinit_dl

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_1", func_80025C60);
 void func_80025C60(void) {
    Gfx		gfxList[0x100];
    Gfx*	gfxList_ptr;
    
    nuGfxTaskAllEndWait();
    nuGfxSetCfb(&FrameBuf, 2);
    nuGfxSetZBuffer((u16*)NU_GFX_ZBUFFER_ADDR);

    nuGfxSwapCfbFuncSet(nuGfxSwapCfb);
    nuGfxSetUcodeFifo(&nuRDPOutputBuf, NU_GFX_RDP_OUTPUTBUFF_SIZE);
    nuGfxSetUcode(&nugfx_ucode);
    nuGfxTaskMgrInit();

    gfxList_ptr = gfxList;
    gSPDisplayList(gfxList_ptr++, rdpstateinit_dl);
    gDPFullSync(gfxList_ptr++);
    gSPEndDisplayList(gfxList_ptr++);
    nuGfxTaskStart(gfxList,
		   (gfxList_ptr - gfxList) * sizeof (Gfx),
		   NU_GFX_UCODE_F3DEX , 0x40000);

    nuGfxTaskAllEndWait();
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_1", func_80025D14);
void func_80025D14(void) {
    Gfx		gfxList[0xff];
    Gfx*	gfxList_ptr;
    
    nuGfxThreadStart();
    nuGfxTaskAllEndWait();
    nuGfxSetCfb(&FrameBuf, 2);
    nuGfxSetZBuffer((u16*)NU_GFX_ZBUFFER_ADDR);

    nuGfxSwapCfbFuncSet(nuGfxSwapCfb);
    nuGfxSetUcodeFifo(&nuRDPOutputBuf, NU_GFX_RDP_OUTPUTBUFF_SIZE);
    nuGfxSetUcode(&nugfx_ucode);
    nuGfxTaskMgrInit();

    gfxList_ptr = gfxList;
    gSPDisplayList(gfxList_ptr++, rdpstateinit_dl);
    gDPFullSync(gfxList_ptr++);
    gSPEndDisplayList(gfxList_ptr++);
    nuGfxTaskStart(gfxList,
		   (gfxList_ptr - gfxList) * sizeof (Gfx),
		   NU_GFX_UCODE_F3DEX , 0x40000);

    nuGfxTaskAllEndWait();
}

typedef struct {
    s32 unk;
    s32 unk2;
} UnkStruct;

typedef struct {
    void* unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    void* unk14;
    void* unk18;
    s32 unk1C;
} UnkStruct_D_800D34D0;

extern UnkStruct_D_800D34D0 D_800D34D0;
// extern void* D_802592E0;
extern void* D_802592E0[];
INCLUDE_ASM("asm/nonmatchings/codeseg1/code_1", Main_ClearMemory);
// void Main_ClearMemory(void) {
//     // volatile s32 pad;
//     UnkStruct unk;
//     u32 start;
//     u32 size;
//     u32 i;
    
//     D_800D34D0.unk0 = 0;
//     start = 0x803B5000;
//     size = 0x803B5000 - (u32)&D_802592E0;
//     i = 0;
//     if (size != 0) {
//         do {
//             D_802592E0[i] = 0;
//             i++;
//         } while (i < size);
//     }
// }

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_1", func_80025E1C);
extern s32 func_80025E3C(s32, void*, s8*);
void func_80025E1C(void* ptr) {
    void* ptr2;
    func_80025E3C(ptr, NULL, &ptr2);
}



//BSS?
// UnkStruct_D_800D34D0* D_800D34D0;

extern s16 D_802592FC;

extern s32 D_802592E4;

extern s32 D_802592E8;
extern s32 D_802592F4;
extern s32 D_802592F0;
extern s32 D_802592EC;


INCLUDE_ASM("asm/nonmatchings/codeseg1/code_1", func_80025E3C);
// s32 func_80025E3C(s32 arg0, void* arg1, s8* arg2) {
//     UnkStruct_D_800D34D0* temp_a2;
//     UnkStruct_D_800D34D0* temp_a2_2;
//     void* temp_v1;
//     UnkStruct_D_800D34D0* var_a3;
//     UnkStruct_D_800D34D0* var_a3_2;
//     UnkStruct_D_800D34D0* var_v0;
//     UnkStruct_D_800D34D0* temp_t0;
//     s32 temp_v1_2;
//     u32 temp_a0;

//     *arg2 = 0;
//     temp_a0 = ((arg0 + 0xF) & ~0xF) + 0x40;
//     if (arg1 >= 0x100U) {
//         for(var_a3 = &D_800D34D0; var_a3 != NULL; var_a3 = var_a3->unk0) {
//             if (var_a3->unk10 == arg1) {
//                 var_a3->unk8 = -1;
//                 var_a3->unk14 = (s32) (var_a3->unk14 + 1);
//                 if (var_a3->unkC == temp_a0) {
//                     *arg2 = 1;
//                     return var_a3 + 0x40;
//                 }
//                 // goto block_18;
//             }
//         }
//     }


//     if (D_800D34D0.unk0 != NULL) {
//         var_a3_2 = &D_800D34D0;
//         if (*var_a3_2 != NULL) {
// loop_13:
//             temp_v1 = var_a3_2->unk0;
//             temp_t0 = var_a3_2->unkC;
//             if ((u32) (temp_v1 - var_a3_2) >= (u32) (temp_a0 + temp_t0)) {
//                 temp_a2 = (u32)var_a3_2 + (u32)temp_t0;
//                 temp_a2->unk4 = var_a3_2;
//                 temp_a2->unk14 = 1;
//                 temp_a2->unk10 = arg1;
//                 temp_a2->unkC = temp_a0;
//                 temp_a2->unk1C = 0;
//                 temp_a2->unk8 = -1;
//                 temp_a2->unk0 = var_a3_2->unk0;
//                 var_a3_2->unk0 = temp_a2;
//                 // temp_a2->unk0->unk4 = temp_a2;
//                 return temp_a2 + 0x40;
//             }
//             var_a3_2 = temp_v1;
//             if (temp_v1 == NULL) {
//                 goto block_17;
//             }
//             goto loop_13;
//         }


// block_17:
//         temp_v1_2 = var_a3_2->unkC;
//         temp_a2_2 = (u32)var_a3_2 + (u32)temp_v1_2;
//         if ((u32) (0x803B5000 - var_a3_2) < (u32) (temp_a0 + temp_v1_2)) {
// block_18:
//             return NULL;
//         }
//         var_v0 = temp_a2_2 + 0x40;
//         temp_a2_2->unk14 = 1;
//         temp_a2_2->unk4 = var_a3_2;
//         temp_a2_2->unk0 = NULL;
//         temp_a2_2->unk10 = arg1;
//         temp_a2_2->unkC = temp_a0;
//         temp_a2_2->unk1C = 0;
//         temp_a2_2->unk8 = -1;
//         var_a3_2->unk0 = temp_a2_2;
//         /* Duplicate return node #21. Try simplifying control flow for better match */
//         return var_v0;
//     }
//     var_v0 = NULL;
//     if ((u32) (0x803B5000 - &D_802592E0) >= temp_a0) {
//         D_800D34D0 = &D_802592E0;
//         D_802592E4 = 0;
//         D_802592E0 = NULL;
//         D_802592F4 = 1;
//         D_802592F0 = arg1;
//         D_802592EC = temp_a0;
//         D_802592FC = 0;
//         D_802592E8 = -1;
//         return &D_802592E0[40];
//     }
//     return var_v0;
// }

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_1", func_80025FF8);

void func_8002609C(void) {
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_1", func_800260A4);
void func_800260A4(s16* arg0) {
    arg0[-18] = 1;
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_1", func_800260B0);
void func_800260B0(s16* arg0) {
    u32 mask; 
    mask = osSetIntMask(1);
    arg0[-18] = 0;
    osSetIntMask(mask);
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_1", func_800260E4);
u16* func_800260E4(u16* arg0) {
    return arg0[-18];
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_1", func_800260EC);
void func_800260EC(u32* arg0, u32* arg1) {
    arg0[-10] = arg1;
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_1", func_800260F4);

s32* func_800260F4(s32* arg0) {
    return arg0[-10];
}
