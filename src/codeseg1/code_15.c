#include "common.h"

// Data
//  sFlatQuadDL
Gfx D_800A8810[] = {
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPEndDisplayList(),
};

// sQuadType
u8 D_800A8848 = 0;

// externs/BSS?
extern u16 D_800A8850;
extern s32 D_80193C30;
extern Mtx D_801D8828;
extern Gfx* D_801A90F0;

extern void* gfx_task_pool_alloc(s32);

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_15", func_8002ED90);
void func_8002ED90(UIElemQuad* quad) {
    Mtx* mtx;
    s32 type;
    s16 ulx, uly, lrx, lry;
    s16 x0, x1, x2, x3;
    s16 y0, y1, y2, y3;
    u8 r, g, b;
    u32 a;
    s32 uVar18;
    volatile s32 pad;
    volatile s64 pad2;

    type = 0;
    if ((D_800A8848 == 1) || (D_800A8848 == 3) ||
        (quad->verts[0].rgba.c.r == quad->verts[1].rgba.c.r && quad->verts[0].rgba.c.r == quad->verts[2].rgba.c.r &&
         quad->verts[0].rgba.c.r == quad->verts[3].rgba.c.r && quad->verts[0].rgba.c.g == quad->verts[1].rgba.c.g &&
         quad->verts[0].rgba.c.g == quad->verts[2].rgba.c.g && quad->verts[0].rgba.c.g == quad->verts[3].rgba.c.g &&
         quad->verts[0].rgba.c.b == quad->verts[1].rgba.c.b && quad->verts[0].rgba.c.b == quad->verts[2].rgba.c.b &&
         quad->verts[0].rgba.c.b == quad->verts[3].rgba.c.b)) {

        if (quad->verts[0].v.x == quad->verts[2].v.x && quad->verts[1].v.x == quad->verts[3].v.x &&
            quad->verts[0].v.y == quad->verts[1].v.y && quad->verts[2].v.y == quad->verts[3].v.y) {
            type = 1;
        } else if (quad->verts[0].v.x == quad->verts[1].v.x && quad->verts[2].v.x == quad->verts[3].v.x &&
                   quad->verts[0].v.y == quad->verts[2].v.y && quad->verts[1].v.y == quad->verts[3].v.y) {
            type = 1;
        }
    }

    if (D_80193C30 != 6) {
        D_80193C30 = 6;
        gSPDisplayList(D_801A90F0++, D_800A8810);
        D_801D8828.m[1][3] = 0x04000001;
        gSPMatrix(D_801A90F0++, &D_801D8828, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    } else {
        gDPPipeSync(D_801A90F0++);
    }

    gDPSetPrimColor(D_801A90F0++, 0, 0, 0, 0, 0, 0);

    if ((D_800A8848 == 3) && (quad->verts[0].v.x == (quad->verts[3].v.x - 0x140)) &&
        (quad->verts[0].v.y == (quad->verts[3].v.y - 0xf0))) {
        gDPSetRenderMode(D_801A90F0++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    } else {
        gDPSetRenderMode(D_801A90F0++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    }

    gDPSetCombineLERP(D_801A90F0++, 1, 0, 0, PRIMITIVE, 1, 0, 0, PRIMITIVE, 1, 0, 0, PRIMITIVE, 1, 0, 0, PRIMITIVE);

    // func_8002ED90_inline(&quad->verts[0], &quad->verts[1]);
    // func_8002ED90_inline(&quad->verts[2], &quad->verts[3]);
    // func_8002ED90_inline(&quad->verts[0], &quad->verts[2]);
    // func_8002ED90_inline(&quad->verts[1], &quad->verts[3]);

    {
        s16 x0 = quad->verts[0].v.x;
        s16 y0 = quad->verts[0].v.y;
        s16 x1 = quad->verts[1].v.x;
        s16 y1 = quad->verts[1].v.y;

        if (x0 < x1) {
            ulx = x0;
            lrx = x1;
        } else {
            ulx = x1;
            lrx = x0;
        }

        if (y0 < y1) {
            uly = y0;
            lry = y1;
        } else {
            uly = y1;
            lry = y0;
        }

        gDPScisFillRectangle(D_801A90F0++, ulx - 1, uly - 1, lrx + 2, lry + 2);
    }

    {
        s16 x2 = quad->verts[2].v.x;
        s16 y2 = quad->verts[2].v.y;
        s16 x3 = quad->verts[3].v.x;
        s16 y3 = quad->verts[3].v.y;

        if (x2 < x3) {
            ulx = x2;
            lrx = x3;
        } else {
            ulx = x3;
            lrx = x2;
        }

        if (y2 < y3) {
            uly = y2;
            lry = y3;
        } else {
            uly = y3;
            lry = y2;
        }

        gDPScisFillRectangle(D_801A90F0++, ulx - 1, uly - 1, lrx + 2, lry + 2);
    }

    {
        s16 x0 = quad->verts[0].v.x;
        s16 y0 = quad->verts[0].v.y;
        s16 x2 = quad->verts[2].v.x;
        s16 y2 = quad->verts[2].v.y;

        if (x0 < x2) {
            ulx = x0;
            lrx = x2;
        } else {
            ulx = x2;
            lrx = x0;
        }

        if (y0 < y2) {
            uly = y0;
            lry = y2;
        } else {
            uly = y2;
            lry = y0;
        }

        gDPScisFillRectangle(D_801A90F0++, ulx - 1, uly - 1, lrx + 2, lry + 2);
    }

    {
        s16 x1 = quad->verts[1].v.x;
        s16 y1 = quad->verts[1].v.y;
        s16 x3 = quad->verts[3].v.x;
        s16 y3 = quad->verts[3].v.y;

        if (x1 < x3) {
            ulx = x1;
            lrx = x3;
        } else {
            ulx = x3;
            lrx = x1;
        }

        if (y1 < y3) {
            uly = y1;
            lry = y3;
        } else {
            uly = y3;
            lry = y1;
        }

        gDPScisFillRectangle(D_801A90F0++, ulx - 1, uly - 1, lrx + 2, lry + 2);
    }

    // x0 = quad->verts[0].v.x;
    // y0 = quad->verts[0].v.y;
    // x1 = quad->verts[1].v.x;
    // y1 = quad->verts[1].v.y;

    // if (x0 < x1) {
    //     ulx = x0;
    //     lrx = x1;
    // } else {
    //     ulx = x1;
    //     lrx = x0;
    // }

    // if (y0 < y1) {
    //     uly = y0;
    //     lry = y1;
    // } else {
    //     uly = y1;
    //     lry = y0;
    // }

    // gDPScisFillRectangle(D_801A90F0++, ulx - 1, uly - 1, lrx + 2, lry + 2);

    // x0 = quad->verts[2].v.x;
    // y0 = quad->verts[2].v.y;
    // x1 = quad->verts[3].v.x;
    // y1 = quad->verts[3].v.y;

    //  if (x0 < x1) {
    //     ulx = x0;
    //     lrx = x1;
    // } else {
    //     ulx = x1;
    //     lrx = x0;
    // }

    // if (y0 < y1) {
    //     uly = y0;
    //     lry = y1;
    // } else {
    //     uly = y1;
    //     lry = y0;
    // }

    // gDPScisFillRectangle(D_801A90F0++, ulx - 1, uly - 1, lrx + 2, lry + 2);

    // x0 = quad->verts[0].v.x;
    // y0 = quad->verts[0].v.y;
    // x1 = quad->verts[2].v.x;
    // y1 = quad->verts[2].v.y;

    //  if (x0 < x1) {
    //     ulx = x0;
    //     lrx = x1;
    // } else {
    //     ulx = x1;
    //     lrx = x0;
    // }

    // if (y0 < y1) {
    //     uly = y0;
    //     lry = y1;
    // } else {
    //     uly = y1;
    //     lry = y0;
    // }

    // gDPScisFillRectangle(D_801A90F0++, ulx - 1, uly - 1, lrx + 2, lry + 2);

    //  x0 = quad->verts[1].v.x;
    //  y0 = quad->verts[1].v.y;
    //  x1 = quad->verts[3].v.x;
    //  y1 = quad->verts[3].v.y;

    // if (x0 < x1) {
    //     ulx = x0;
    //     lrx = x1;
    // } else {
    //     ulx = x1;
    //     lrx = x0;
    // }

    // if (y0 < y1) {
    //     uly = y0;
    //     lry = y1;
    // } else {
    //     uly = y1;
    //     lry = y0;
    // }

    // gDPScisFillRectangle(D_801A90F0++, ulx - 1, uly - 1, lrx + 2, lry + 2);

    gDPPipeSync(D_801A90F0++);

    if (quad->verts[0].rgba.c.a & 2) {
        r = quad->verts[0].rgba.c.r;
        g = quad->verts[0].rgba.c.g;
        b = quad->verts[0].rgba.c.b;
        uVar18 = (D_800A8850 >> 5) & 3;

        switch (uVar18) {
            case 1:
                a = 0xbf;
                quad->verts[0].rgba.c.r = r + 0x3f;
                quad->verts[0].rgba.c.g += 0x3f;
                quad->verts[0].rgba.c.b += 0x3f;
                quad->verts[1].rgba.c.r += 0x3f;
                quad->verts[1].rgba.c.g += 0x3f;
                quad->verts[1].rgba.c.b += 0x3f;
                quad->verts[2].rgba.c.r += 0x3f;
                quad->verts[2].rgba.c.g += 0x3f;
                quad->verts[2].rgba.c.b += 0x3f;
                quad->verts[3].rgba.c.r += 0x3f;
                quad->verts[3].rgba.c.g += 0x3f;
                quad->verts[3].rgba.c.b += 0x3f;
                break;
            case 2:
                if (D_800A8848 == 3 && ((g != (r)) | (b != (r)))) {
                    a = 0x60;
                } else {
                    a = r + g;
                    a = a + b;
                    a /= 3;
                    a += 0x20;
                    if (a > 0xFF) {
                        a = 0xff;
                    }
                    b = 0;
                    g = 0;
                    r = 0;
                }

                break;
            case 0:
            default:
                a = 0x80;
                break;
        }

        if (((D_800A8848 == 3) && ((D_800A8850 >> 5 & 3) != 2 && r == g)) && (g == b)) {
            a = r + g;
            a = a + b;
            a /= 3;
            b = 0xff;
            g = 0xff;
            r = 0xff;
        }

        gDPSetPrimColor(D_801A90F0++, 0, 0, r, g, b, a);
    } else {
        gDPSetPrimColor(D_801A90F0++, 0, 0, quad->verts[0].rgba.c.r, quad->verts[0].rgba.c.g, quad->verts[0].rgba.c.b,
                        0xFF);
        gDPSetRenderMode(D_801A90F0++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    }

    switch ((u8)type) {
        case 0:
        case 2:
            mtx = (Mtx*)gfx_task_pool_alloc(sizeof(Mtx));
            if (mtx != NULL) {
                gDPSetCombineLERP(D_801A90F0++, 1, 0, 0, SHADE, 1, 0, 0, PRIMITIVE, 1, 0, 0, SHADE, 1, 0, 0, PRIMITIVE);
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

                gSPModifyVertex(D_801A90F0++, 0, G_MWO_POINT_RGBA,
                                (quad->verts[0].rgba.c.r << 24) | (quad->verts[0].rgba.c.g << 16) |
                                    (quad->verts[0].rgba.c.b << 8) | 0xFF);
                gSPModifyVertex(D_801A90F0++, 1, G_MWO_POINT_RGBA,
                                (quad->verts[1].rgba.c.r << 24) | (quad->verts[1].rgba.c.g << 16) |
                                    (quad->verts[1].rgba.c.b << 8) | 0xFF);
                gSPModifyVertex(D_801A90F0++, 2, G_MWO_POINT_RGBA,
                                (quad->verts[2].rgba.c.r << 24) | (quad->verts[2].rgba.c.g << 16) |
                                    (quad->verts[2].rgba.c.b << 8) | 0xFF);
                gSPModifyVertex(D_801A90F0++, 3, G_MWO_POINT_RGBA,
                                (quad->verts[3].rgba.c.r << 24) | (quad->verts[3].rgba.c.g << 16) |
                                    (quad->verts[3].rgba.c.b << 8) | 0xFF);

                if (D_800A8848 == 2) {
                    gSP1Triangle(D_801A90F0++, 0, 2, 1, 0);
                } else {
                    gSP2Triangles(D_801A90F0++, 0, 2, 1, 0, 2, 3, 1, 0);
                }
            }
            break;
        case 1:
            gDPScisFillRectangle(D_801A90F0++, quad->verts[0].v.x, quad->verts[0].v.y, quad->verts[3].v.x + 1,
                                 quad->verts[3].v.y + 1);
            break;
    }

    D_800A8848 = 0;
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_15", func_8002FA3C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_15", func_8002FB2C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_15", func_8002FC1C);
