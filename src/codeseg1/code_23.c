#include "common.h"
#include "actor.h"

extern void func_80029114(s16);

typedef struct {
    /* 0x00 */ s8 funcIndex;
    /* 0x01 */ s8 unk_unused;
    /* ... */
} Struct_D_801D4780; // D_801D4780

void func_80037BDC(Struct_D_801D4780*);
void func_80037CA0(Struct_D_801D4780*);
void func_80037D68(Struct_D_801D4780*);

void (*D_800AC950[])(Struct_D_801D4780*) = {
    func_80037BDC,
    func_80037CA0,
    func_80037D68,
};

extern Struct_D_801D4780 D_801D4780;
extern void (*D_800AC950[])(Struct_D_801D4780*);

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_23", func_80037B70);
void func_80037B70(void) {
    D_801D4780.funcIndex = 0;
    D_801D4780.unk_unused = 0;

    while (1) {
        D_800AC950[D_801D4780.funcIndex](&D_801D4780);
        func_80029114(1);
    }
}

void func_80030518(s32); /* extern */
void func_80061404();    /* extern */
void func_80073E14();    /* extern */
void func_800875B0();    /* extern */
extern s32 D_801BC3F8;
extern s32 D_801BC3FC;
extern s16 D_801BC400;
extern s16 D_801BC402;
extern s8 D_801BC43C;
extern s8 D_801BC43D;
extern s8 D_801BC440;
extern s8 D_801BC441;
extern s8 D_801BC443;
extern s16 D_801BC458;
extern s16 D_801BC45A;
extern s16 D_801BC45C;
extern s16 D_801BC45E;
extern u8 D_80210B61;
// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_23", func_80037BDC);
void func_80037BDC(Struct_D_801D4780* arg0) {
    func_80030518(1);
    func_80061404();
    func_80073E14();
    func_800875B0();
    D_801BC443 = 1;
    D_80210B61 = 0;
    D_801BC3F8 = 0;
    D_801BC3FC = 0;
    D_801BC400 = 0;
    D_801BC402 = 0;
    D_801BC43C = 0;
    D_801BC43D = 0;
    D_801BC440 = 0;
    D_801BC441 = 0;
    D_801BC458 = -1;
    D_801BC45A = -1;
    D_801BC45C = -1;
    D_801BC45E = -1;
    arg0->funcIndex += 1;
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_23", func_80037CA0);

void func_80037D68(Struct_D_801D4780* arg0) {
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_23", func_80037D70);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_23", func_80037D80);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_23", func_80037F78);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_23", func_80038550);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_23", func_800387F0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_23", func_800387FC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_23", func_80038934);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_23", func_80038CF8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_23", func_80038DB8);

typedef struct { /* 0xC */
    s16 x, y, z;
    s16 collisionEnabled;
    void* data;
} LevelTile;

typedef struct { /* 0x28 */
    u16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s16 unk24;
    u16 unk26;
} UnkTileStruct;

typedef struct { /* 0x48 */
    Mtx m;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s16 unk46;
} BufferObj;

void* gfx_task_pool_alloc(s32);
void func_800283A8(s8, s8, void*, void*);
Mtx* func_8002C5A4(MATRIX*, Mtx*);
void func_8002C678(MATRIX*);
MATRIX* MulMatrix(MATRIX*, MATRIX*, MATRIX*);
VECTOR* ApplyMatrix(MATRIX*, SVECTOR*, VECTOR*);
MATRIX* RotMatrixY(s32, MATRIX*);
void func_80038934(void);
s32 func_80038DB8(VECTOR*, u32);
void func_8007F2D4(void);
void func_800868C0(s16, s16, s16, s16);
s32 func_8008699C(s32, s32);
void func_8023C500(void);

extern s32 D_800AC960[4];
extern s32 D_800AC978;
extern UnkTileStruct* D_800BD9A0;
extern void* D_800BD9A4;
extern s32 D_8017AA10;
extern s32 D_8017AA14;
extern s32 D_8017AA18;
extern s32 D_8017AA20[];
extern s32 D_8017B220;
extern s32 D_8017B224;
extern s32 D_8017B228;
extern s32 D_8017B22C;
extern s16 D_80195E92;
extern u16* D_801ACA40;
extern u16 D_801ADCCE;
extern s8 D_801BC438;
extern s8 D_801BC439;
extern u8 D_801BC5B0;
extern u8 D_801BC65A;
extern MATRIX D_801D4760;

extern u16 D_801D87F0;
extern s8 D_801D8D14;
extern MATRIX D_801FEE38[4];
extern MATRIX D_801FF2C0[4];
extern SVECTOR D_801FFBB4;
extern s32* D_80204000;
extern u16 D_802049AE;
// extern SVECTOR D_802049C4;
extern PlayerActor playerActor;
extern s32 D_802055A0;
extern u8 D_80206B40;
extern LevelTile* D_80210B5C;
extern u8 D_80210B61;

extern void func_8007F27C;
extern void func_800887B4;
extern void func_80088DD0;

#define FLOOR_TILE 1
#define FLOOR_TILE_DECAL 2
#define UNIQUE_TILE 3
// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_23", func_8003912C);
void func_8003912C(void) {
    VECTOR vec;                   // sp_0x10
    VECTOR currentTileTranslate;  // sp_0x30?
    VECTOR currentTileTranslate2; // sp_0x20?
    VECTOR unusedVec;             // sp_0x40?
    UnkTileStruct* unkTileStruct; // sp_0x54
    u16* tileTypePtr;             // sp_0x5C
    LevelTile* tileDataPtr;       // sp_0x64
    s32 cullDistance;             // sp_0x6C
    s32 gridSize;                 // sp_0x74
    u16* scalePtr;
    s32 xTile, zTile; // sp_0x80 and sp_0x84;

    u32 currentTile;
    s32 tileIter;
    s32 temp_val;
    s32 var_a0;
    s32 var_a3;
    MATRIX* tile;
    MATRIX* cameraViewMatrix;
    s32 unkVar3;
    s32 unkVar6;
    s32 unkFlag;
    s32 scale;
    s32 xTranslate;
    s32 iVar2;
    s32 iVar2_2;
    s32 yTranslate;
    s32 switchCaseFlag;
    u32 tileStructIndex;
    s32 textureLod;
    s32 sVar10;
    s32 tileTypeFlag;
    LevelTile* levelTile;
    void* tileData;
    s32 unkVar5;
    s32 unkVar5_2;
    s32 unkVar5_3;
    s32 zTranslate;
    BufferObj* buffObj;
    BufferObj* buffObj2;

    if ((D_800AC978 == 0) && (D_801ACA40 != 0) && (D_80210B5C != 0) && (D_800BD9A0 != 0) && (D_800BD9A4 != 0)) {
        gridSize = 4000;
        switch (D_801BC438) {
            case 0:
                if (D_801BC439 == 4) {
                    func_8023C500();
                }
                break;
            case 8:
                if (D_801BC439 == 0) {
                    gridSize = 4500;
                }
                break;
        }

        func_8007F2D4();

        cameraViewMatrix = &D_801D4760;
        tileTypePtr = D_801ACA40;
        D_8017AA10 = 1;
        tileDataPtr = D_80210B5C;
        unkTileStruct = NULL;

        for (tileIter = 0; tileIter < 4; tileIter++) {
            func_8002C678(&D_801FF2C0[tileIter]);
            if (D_80210B61 != 0) {
                D_801FF2C0[tileIter].m[0][0] <<= D_80210B61;
                D_801FF2C0[tileIter].m[0][1] <<= D_80210B61;
                D_801FF2C0[tileIter].m[0][2] <<= D_80210B61;
                D_801FF2C0[tileIter].m[1][0] <<= D_80210B61;
                D_801FF2C0[tileIter].m[1][1] <<= D_80210B61;
                D_801FF2C0[tileIter].m[1][2] <<= D_80210B61;
                D_801FF2C0[tileIter].m[2][0] <<= D_80210B61;
                D_801FF2C0[tileIter].m[2][1] <<= D_80210B61;
                D_801FF2C0[tileIter].m[2][2] <<= D_80210B61;
            }
        }

        RotMatrixY(0x400, &D_801FF2C0[1]);
        RotMatrixY(0x800, &D_801FF2C0[2]);
        RotMatrixY(0xC00, &D_801FF2C0[3]);
        MulMatrix(&D_801D4760, &D_801FF2C0[0], &D_801FEE38[0]);
        MulMatrix(&D_801D4760, &D_801FF2C0[1], &D_801FEE38[1]);
        MulMatrix(&D_801D4760, &D_801FF2C0[2], &D_801FEE38[2]);
        MulMatrix(&D_801D4760, &D_801FF2C0[3], &D_801FEE38[3]);

        D_8017AA14 = (playerActor.svecPosition.vx + 0x8000) / 512 - D_80206B40;
        D_8017AA18 = (playerActor.svecPosition.vz + 0x8000) / 512 - D_801BC65A;

        ApplyMatrix(&D_801D4760, &playerActor.svecPosition, &vec);

        vec.vx += cameraViewMatrix->t[0];
        vec.vy += cameraViewMatrix->t[1];
        vec.vz += cameraViewMatrix->t[2];
        D_801FFBB4.vx = vec.vx << D_80210B61;
        D_801FFBB4.vy = vec.vy << D_80210B61;
        D_801FFBB4.vz = vec.vz << D_80210B61;

        func_80038934();
        func_800868C0((s16)(D_8017B220 + D_80206B40), (s16)(D_80206B40 + D_8017B228), (s16)(D_8017B224 + D_801BC65A),
                      (s16)(D_801BC65A + D_8017B22C));

        if (D_801BC5B0 != 0) {
            cullDistance = -0x1000 << D_801D8D14;
        } else {
            cullDistance = -0x280 << D_80210B61;
        }

        for (zTile = D_8017B224; zTile < D_8017B22C; zTile++) {
            for (xTile = D_8017B220; xTile < D_8017B228; xTile++) {
                tileStructIndex = 0;
                currentTile = tileTypePtr[D_802049AE * zTile + xTile];
                unkVar3 = func_8008699C(D_80206B40 + xTile, D_801BC65A + zTile);
                if (unkVar3 == 0) {
                    if ((u16)currentTile != 0) {
                        if (xTile < 0) {
                            unkVar6 = xTile + 0x1f;
                        } else {
                            unkVar6 = xTile;
                        }
                        if ((D_8017AA20[zTile * 4 + (unkVar6 >> 5)] & (1 << (xTile & 0x1f))) == 0) {
                            scale = D_80210B61;
                            currentTileTranslate.vx = ((D_80206B40 + xTile) * 0x200 - 0x7f00) << scale;
                            currentTileTranslate.vz = ((D_801BC65A + zTile) * 0x200 - 0x7f00) << scale;
                            currentTileTranslate2.vx = currentTileTranslate.vx;
                            currentTileTranslate2.vz = currentTileTranslate.vz;

                            zTranslate = currentTileTranslate.vx;
                            zTranslate = ((cameraViewMatrix->m[2][0] * currentTileTranslate.vx +
                                           cameraViewMatrix->m[2][2] * currentTileTranslate.vz) >>
                                          0xc) +
                                         cameraViewMatrix->t[2];

                            if (zTranslate < (D_801D87F0 << 2) && cullDistance < zTranslate) {
                                unkFlag = 0;
                                levelTile = NULL;
                                tileData = NULL;
                                switchCaseFlag = 0;

                                xTranslate = ((cameraViewMatrix->m[0][0] * currentTileTranslate.vx +
                                               cameraViewMatrix->m[0][2] * currentTileTranslate.vz) >>
                                              0xc) +
                                             cameraViewMatrix->t[0];

                                // Common Ground Tiles (Negative values)
                                if (currentTile >> 0xf) {
                                    currentTileTranslate.vy = -((currentTile & 0x1f00) >> 1) << scale;

                                    if (D_801BC5B0 == 0 && currentTileTranslate.vy < D_80195E92 - 0xc0) {
                                        continue;
                                    }

                                    if (currentTileTranslate.vy != 0) {
                                        xTranslate += (cameraViewMatrix->m[0][1] * currentTileTranslate.vy) >> 0xc;

                                        yTranslate = ((cameraViewMatrix->m[1][0] * currentTileTranslate.vx +
                                                       cameraViewMatrix->m[1][1] * currentTileTranslate.vy +
                                                       cameraViewMatrix->m[1][2] * currentTileTranslate.vz) >>
                                                      0xc) +
                                                     cameraViewMatrix->t[1];

                                        zTranslate += (cameraViewMatrix->m[2][1] * currentTileTranslate.vy) >> 0xc;
                                    } else {
                                        yTranslate = ((cameraViewMatrix->m[1][0] * currentTileTranslate.vx +
                                                       cameraViewMatrix->m[1][2] * currentTileTranslate.vz) >>
                                                      0xc) +
                                                     cameraViewMatrix->t[1];
                                    }

                                    if (zTranslate < (-0x80 << D_80210B61)) {
                                        continue;
                                    }

                                    iVar2_2 = ((yTranslate << 8) / (zTranslate | 1)) + 0x78;

                                    if ((0x80 << D_80210B61) < abs(zTranslate)) {
                                        if (iVar2_2 < -0x140) {
                                            continue;
                                        }
                                        if (D_801BC5B0 == 0) {
                                            if ((iVar2_2 > 0x230)) {
                                                continue;
                                            }
                                        }
                                    }

                                    switchCaseFlag = 1;
                                    unkFlag = (currentTile & 0x7c) >> 2;
                                    tileTypeFlag = currentTile & 3;
                                    if (currentTile & 0x80) {
                                        switchCaseFlag = FLOOR_TILE_DECAL;
                                        tileData = (void*)D_80204000[unkFlag * 2 + 1] + D_802055A0;
                                        tileStructIndex = ((u32)tileData - D_802055A0) / 0x30;
                                    }
                                }
                                //'Unique' Ground Tiles (Positive values)
                                else {
                                    levelTile = &tileDataPtr[(u16)currentTile];

                                    currentTileTranslate.vx = levelTile->x << scale;
                                    currentTileTranslate.vy = levelTile->y << scale;
                                    currentTileTranslate.vz = levelTile->z << scale;

                                    // TODO fix this
                                    xTranslate = ((cameraViewMatrix->m[0][0] * currentTileTranslate.vx +
                                                   cameraViewMatrix->m[0][1] * currentTileTranslate.vy +
                                                   cameraViewMatrix->m[0][2] * currentTileTranslate.vz) >>
                                                  0xc) +
                                                 cameraViewMatrix->t[0];
                                    yTranslate = ((cameraViewMatrix->m[1][0] * currentTileTranslate.vx +
                                                   cameraViewMatrix->m[1][1] * currentTileTranslate.vy +
                                                   cameraViewMatrix->m[1][2] * currentTileTranslate.vz) >>
                                                  0xc) +
                                                 cameraViewMatrix->t[1];
                                    zTranslate = ((cameraViewMatrix->m[2][0] * currentTileTranslate.vx +
                                                   cameraViewMatrix->m[2][1] * currentTileTranslate.vy +
                                                   cameraViewMatrix->m[2][2] * currentTileTranslate.vz) >>
                                                  0xc) +
                                                 cameraViewMatrix->t[2];

                                    tileStructIndex = ((u32)levelTile->data - (u32)D_802055A0) / 0x30;
                                    tileData = levelTile->data;
                                    unkTileStruct = &D_800BD9A0[tileStructIndex];

                                    if (unkTileStruct->unkC == 0) {
                                        continue;
                                    }

                                    tileTypeFlag = unkTileStruct->unk26 & 3;
                                    switchCaseFlag = 3;
                                }

                                if (switchCaseFlag != 0) {
                                    tile = &D_801FEE38[tileTypeFlag];
                                    tile->t[0] = xTranslate;
                                    tile->t[1] = yTranslate;
                                    tile->t[2] = zTranslate;

                                    iVar2 = (xTranslate << 8) / (zTranslate | 1);

                                    switch (switchCaseFlag) {
                                        case FLOOR_TILE:
                                            if (((u32)(iVar2 + 0x280) > 0x500)) {
                                                if ((0x80 << D_80210B61) < abs(zTranslate) && D_801BC5B0 == 0) {
                                                    break;
                                                }
                                            }
                                            buffObj = gfx_task_pool_alloc(sizeof(BufferObj));
                                            if (buffObj != NULL) {
                                                bzero(buffObj, sizeof(BufferObj));
                                                *(s32*)&buffObj->unk40 = unkFlag;
                                                func_8002C5A4(tile, &buffObj->m);
                                                if (tile->t[2] > 5500) {
                                                    // Low LOD
                                                    func_800283A8(0, 4, &func_80088DD0, buffObj);
                                                } else {
                                                    // Normal LOD
                                                    func_800283A8(0, 4, &func_800887B4, buffObj);
                                                }
                                            }
                                            break;

                                        case FLOOR_TILE_DECAL:
                                            if (((u32)(iVar2 + 0x280) > 0x500)) {
                                                if ((0x80 << D_80210B61) < abs(zTranslate) && D_801BC5B0 == 0) {
                                                    break;
                                                }
                                            }
                                            buffObj2 = gfx_task_pool_alloc(sizeof(BufferObj));
                                            if (buffObj2 != NULL && tileData != NULL) {
                                                bzero(buffObj2, sizeof(BufferObj));
                                                if (gridSize < tile->t[2]) {
                                                    buffObj2->unk46 = (buffObj2->unk46 & 0x8fff) | 0x1000;
                                                } else if ((tile->t[2] > 6000)) {
                                                    buffObj2->unk46 = (buffObj2->unk46 & 0x8fff) | 0x2000;
                                                }
                                                buffObj2->unk46 =
                                                    (buffObj2->unk46 & 0xfe00) | (tileStructIndex & 0x1ff);
                                                func_8002C5A4(tile, &buffObj2->m);
                                                func_800283A8(0, 4, &func_8007F27C, buffObj2);
                                            }
                                            break;

                                        case UNIQUE_TILE:
                                            if (D_801BC5B0 != 0) {
                                                unkVar5_2 = (u32)(iVar2 + 0xaa0) < 0x1541;
                                            } else {
                                                unkVar5_2 = (u32)(iVar2 + 0x520) < 0xa41;
                                            }
                                            if (!unkVar5_2) {
                                                if ((0x80 << D_80210B61) < abs(zTranslate)) {
                                                    break;
                                                }
                                            }

                                            buffObj2 = gfx_task_pool_alloc(sizeof(BufferObj));
                                            if (buffObj2 != NULL && tileData != NULL) {
                                                textureLod = 0;
                                                unkVar5 = 0;
                                                sVar10 = 0;

                                                bzero(buffObj2, sizeof(BufferObj));
                                                buffObj2->unk40 = currentTileTranslate.vx;
                                                buffObj2->unk42 = currentTileTranslate.vy;
                                                buffObj2->unk44 = currentTileTranslate.vz;

                                                if (tile->t[2] > gridSize) {
                                                    textureLod = 1;
                                                } else if ((tile->t[2] > 6000)) {
                                                    textureLod = 2;
                                                }
                                                if (levelTile->collisionEnabled == 0) {
                                                    textureLod += 3;
                                                }

                                                temp_val = (textureLod & 7) << 12;
                                                buffObj2->unk46 &= 0x8e00;
                                                buffObj2->unk46 |= temp_val;
                                                buffObj2->unk46 |= (tileStructIndex & 0x1ff);
                                                func_8002C5A4(tile, &buffObj2->m);

                                                if (D_801BC5B0 == 0) {

                                                    unkVar5_3 = unkTileStruct->unk0 >> 0xe;
                                                    if (D_801ADCCE == 1) {
                                                        unkVar5 = 1;
                                                    } else if ((tile->t[2] - (D_800AC960[unkVar5_3]) < vec.vz)) {
                                                        currentTileTranslate2.vy = vec.vy;
                                                        unkVar5 = func_80038DB8(&currentTileTranslate2, unkVar5_3);

                                                        if (D_801ADCCE == 2) {
                                                            sVar10 = 2;
                                                        }
                                                    } else if (D_801ADCCE == 2) {
                                                        sVar10 = 1;
                                                    }
                                                }

                                                if (unkVar5 != 0) {
                                                    buffObj2->unk46 = (buffObj2->unk46 & 0xf1ff) | 0x600;
                                                    func_800283A8(0, 4, &func_8007F27C, buffObj2);
                                                    buffObj = gfx_task_pool_alloc(sizeof(BufferObj));
                                                    if (buffObj != NULL) {
                                                        memcpy(buffObj, buffObj2, sizeof(BufferObj));
                                                        buffObj->unk46 = (buffObj->unk46 & 0xf1ff) | 0x800;
                                                        func_800283A8(0, 8, &func_8007F27C, buffObj);
                                                    }

                                                } else {
                                                    buffObj2->unk46 = buffObj2->unk46 & 0xf1ff;
                                                    func_800283A8(0, 4, &func_8007F27C, buffObj2);
                                                }

                                                if (sVar10 != 0) {
                                                    buffObj = gfx_task_pool_alloc(sizeof(BufferObj));
                                                    if (buffObj != NULL) {
                                                        memcpy(buffObj, buffObj2, sizeof(BufferObj));
                                                        buffObj->unk46 = (buffObj->unk46 & 0xf1ff) | (sVar10 << 9);
                                                        func_800283A8(0, 5, &func_8007F27C, buffObj);
                                                    }
                                                }
                                            }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_23", func_80039F18);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_23", func_80039F68);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_23", func_80039FBC);

INCLUDE_RODATA("asm/nonmatchings/codeseg1/code_23", D_800D1DF0);

INCLUDE_RODATA("asm/nonmatchings/codeseg1/code_23", D_800D1E04);
