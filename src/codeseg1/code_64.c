#include "common.h"

extern s32 func_80087248(s32, u32);
extern u16 D_8017BB1A;
extern u8 D_8017BB20;
extern Gfx* D_801A90F0;

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007BEA0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007BF08);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007BF70);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007BF9C);

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007BFC8);
s32 func_8007BFC8(u16* arg0) {
    s32 textureTlut;
    s32 temp_a0;
    u16 temp_a1;

    temp_a0 = *arg0  & 0x7FFF;
    temp_a1 = temp_a0;
    if (D_8017BB1A != temp_a1) {
        D_8017BB1A = temp_a0;
        textureTlut = func_80087248((temp_a0 & 0x3F) * 0x10, temp_a1 >> 6);
        
        if (textureTlut != NULL) {
            if (D_8017BB20 == 0) {
                D_8017BB20 = 1;
                gDPPipeSync(D_801A90F0++);
            }
            gDPLoadTLUT_pal16(D_801A90F0++, 0, textureTlut);
            
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007C108);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007C450);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007C930);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007CC94);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007D434);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007D538);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007D63C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007D798);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007DA78);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007E024);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007E324);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007E5F8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007E8D4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007F27C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007F2A8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007F2D4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007F360);

void func_8007FB70(void) {
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007FB78);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007FBC0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8007FC44);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_800805F8);

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_64", func_8008128C);
extern s32 D_80193C30;
extern u8 D_8017C281;
extern u8 D_8017C282;
extern u8 D_8017C283;
extern s32 D_80210208;
void func_8008128C(){
    D_80193C30 = 10;
    D_8017C281 = 0xff;
    D_8017C282 = 0xff;
    D_8017C283 = 0xff;
    D_80210208 = 0;

    gSPClearGeometryMode(D_801A90F0++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
    gDPPipeSync(D_801A90F0++);
    gDPSetCycleType(D_801A90F0++, G_CYC_2CYCLE);
    gDPSetTextureLUT(D_801A90F0++, G_TT_RGBA16);
    gDPSetTexturePersp(D_801A90F0++, G_TP_PERSP);
    gDPSetTextureFilter(D_801A90F0++, G_TF_BILERP);
}
