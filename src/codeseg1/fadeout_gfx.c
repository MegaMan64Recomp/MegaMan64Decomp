#include "common.h"

//Data
Gfx sFadeoutDL[] = {
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(1, 0, PRIMITIVE, 0, 1, 0, SHADE, 0, 1, 0, PRIMITIVE, 0, 1, 0, SHADE, 0),
    gsDPSetRenderMode(G_RM_CLD_SURF, G_RM_CLD_SURF2),
    gsSPEndDisplayList(),
};

//Externs
void* gfx_task_pool_alloc(s32);
extern Mtx D_801D8828;
extern s32 D_80193C30;
extern Gfx* D_801A90F0;
extern Mtx D_801D8844;

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_69", func_800861E0);

void fadeout_gfx(UIElemQuad* quad) {
    u32 vert;
    Mtx* mtx;
    Gfx* gfx;
    u8 r, g, b, a;
    volatile s32 pad;
    volatile s64 pad2;

    D_80193C30 = -1;

    gSPDisplayList(D_801A90F0++, &sFadeoutDL);
    D_801D8828.m[1][3] = 0x4000001;
    gSPMatrix(D_801A90F0++, &D_801D8828, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gDPPipeSync(D_801A90F0++);
    gDPSetPrimColor(D_801A90F0++, 0, 0, quad->verts[0].rgba.c.r, quad->verts[0].rgba.c.g, quad->verts[0].rgba.c.b,
                    0xFF);

    mtx = gfx_task_pool_alloc(sizeof(Mtx));
    if (mtx != NULL) {
        // TODO hacky pointless if-statement to force match
        if (quad->verts[0].v.y) {
            bzero(mtx, sizeof(Mtx));
            gSPVertex(D_801A90F0++, mtx, 4, 0);
            gSPModifyVertex(D_801A90F0++, 0, G_MWO_POINT_XYSCREEN,
                            (quad->verts[0].v.x << 18) | ((quad->verts[0].v.y << 2) & 0xFFFF));
            gSPModifyVertex(D_801A90F0++, 1, G_MWO_POINT_XYSCREEN,
                            (quad->verts[1].v.x << 18) | ((quad->verts[1].v.y << 2) & 0xFFFF));
            gSPModifyVertex(D_801A90F0++, 2, G_MWO_POINT_XYSCREEN,
                            (quad->verts[2].v.x << 18) | ((quad->verts[2].v.y << 2) & 0xFFFF));
            gSPModifyVertex(D_801A90F0++, 3, G_MWO_POINT_XYSCREEN,
                            (quad->verts[3].v.x << 18) | ((quad->verts[3].v.y << 2) & 0xFFFF));
            gSPModifyVertex(D_801A90F0++, 0, G_MWO_POINT_RGBA, quad->verts[1].rgba.c.r | (~0xFF));
            gSPModifyVertex(D_801A90F0++, 1, G_MWO_POINT_RGBA, quad->verts[1].rgba.c.g | (~0xFF));
            gSPModifyVertex(D_801A90F0++, 2, G_MWO_POINT_RGBA, quad->verts[1].rgba.c.b | (~0xFF));
            gSPModifyVertex(D_801A90F0++, 3, G_MWO_POINT_RGBA, quad->verts[1].rgba.c.a | (~0xFF));
            gSP2Triangles(D_801A90F0++, 0, 2, 1, 0, 2, 3, 1, 0);
        } else {
            bzero(mtx, sizeof(Mtx));
            gSPVertex(D_801A90F0++, mtx, 4, 0);
            gSPModifyVertex(D_801A90F0++, 0, G_MWO_POINT_XYSCREEN,
                            (quad->verts[0].v.x << 18) | ((quad->verts[0].v.y << 2) & 0xFFFF));
            gSPModifyVertex(D_801A90F0++, 1, G_MWO_POINT_XYSCREEN,
                            (quad->verts[1].v.x << 18) | ((quad->verts[1].v.y << 2) & 0xFFFF));
            gSPModifyVertex(D_801A90F0++, 2, G_MWO_POINT_XYSCREEN,
                            (quad->verts[2].v.x << 18) | ((quad->verts[2].v.y << 2) & 0xFFFF));
            gSPModifyVertex(D_801A90F0++, 3, G_MWO_POINT_XYSCREEN,
                            (quad->verts[3].v.x << 18) | ((quad->verts[3].v.y << 2) & 0xFFFF));
            gSPModifyVertex(D_801A90F0++, 0, G_MWO_POINT_RGBA, quad->verts[1].rgba.c.r | (~0xFF));
            gSPModifyVertex(D_801A90F0++, 1, G_MWO_POINT_RGBA, quad->verts[1].rgba.c.g | (~0xFF));
            gSPModifyVertex(D_801A90F0++, 2, G_MWO_POINT_RGBA, quad->verts[1].rgba.c.b | (~0xFF));
            gSPModifyVertex(D_801A90F0++, 3, G_MWO_POINT_RGBA, quad->verts[1].rgba.c.a | (~0xFF));
            gSP2Triangles(D_801A90F0++, 0, 2, 1, 0, 2, 3, 1, 0);
        }
    }
}
