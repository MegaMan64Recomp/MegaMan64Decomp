#include "common.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s8 unkC;
    s8 unkD;
    s8 unkE;
} ShadowUnkStruct;

typedef struct {
    Mtx mtx;
    SVECTOR vec;
    s16 size;
    s16 opacity;
    s32 index;
} ShadowBuffer;

typedef struct {
    s32 unk0;
    s32 unk4;
} UnkStruct;

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_73", func_800892B0);

extern s32 D_801A9064;
extern ShadowUnkStruct shadowArray[64];
extern VECTOR D_801BC0A8;
extern s32 D_801BC0B0;
extern MATRIX D_801D4760;
extern u16 D_801D87F0;
extern s32 D_801D886C;
extern s32 D_801DEB14;
extern s16 gTransMatrix;
extern s16 D_80206B58;
extern u8 D_80210B61;
extern s32 D_8021D95C;
extern void func_800896D8;
void* gfx_task_pool_alloc(s32);                 // alloc_arena
void func_800283A8(s8, s8, void*, void*); // push_arena_gfx
void func_8002C5A4(MATRIX*, void*);
void SetRotMatrix(MATRIX*);
void func_80032068(void*, void*, void*);

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_73", func_800893E4);

// Inlined func for func_800893E4
static inline void func_800893E4_inlined(ShadowBuffer* shadowBuff, s32 i) {
    memcpy(&shadowBuff->vec, &shadowArray[i].unk0, sizeof(SVECTOR));
    shadowBuff->size = shadowArray[i].unk8;
    shadowBuff->opacity = shadowArray[i].unkA;
    SetRotMatrix(&D_801D4760);
    memcpy(&gTransMatrix, &D_80206B58, sizeof(VECTOR));
    memcpy(&D_8021D95C, &shadowBuff->vec, sizeof(SVECTOR));
    func_80032068(&D_8021D95C, &D_801BC0A8, &D_801D886C);
    return;
}

void func_800893E4(void) {
    MATRIX* cameraView;
    MATRIX mtx;
    VECTOR vec;
    UnkStruct temp;
    MATRIX* mtxPtr;
    ShadowBuffer* shadowBuff;
    s32 arraySize;
    s32 x, y, z;
    s32 i;

    arraySize = D_801A9064;
    for (i = 0; i < arraySize; i++) {
        shadowBuff = gfx_task_pool_alloc(sizeof(ShadowBuffer));
        mtxPtr = &mtx;
        if (shadowBuff != NULL) {
            cameraView = &D_801D4760;
            bzero(shadowBuff, sizeof(ShadowBuffer));
            memcpy(&mtx, cameraView, sizeof(MATRIX));
            func_800893E4_inlined(shadowBuff, i);

            temp.unk0 = D_801BC0A8.vz / 4;
            if (temp.unk0 <= D_801D87F0) {

                vec.vx = shadowBuff->vec.vx << D_80210B61;
                vec.vy = shadowBuff->vec.vy << D_80210B61;
                vec.vz = shadowBuff->vec.vz << D_80210B61;

                x = (cameraView->m[0][0] * vec.vx + cameraView->m[0][1] * vec.vy + cameraView->m[0][2] * vec.vz) /
                        4096 +
                    cameraView->t[0];

                y = (cameraView->m[1][0] * vec.vx + cameraView->m[1][1] * vec.vy + cameraView->m[1][2] * vec.vz) /
                        4096 +
                    cameraView->t[1];

                z = (cameraView->m[2][0] * vec.vx + cameraView->m[2][1] * vec.vy + cameraView->m[2][2] * vec.vz) /
                        4096 +
                    cameraView->t[2];

                mtx.t[0] = x + shadowArray[i].unkC;
                mtx.t[1] = y + shadowArray[i].unkD;
                mtx.t[2] = z + shadowArray[i].unkE;

                shadowBuff->index = i;

                func_8002C5A4(mtxPtr, shadowBuff);
                func_800283A8(0, 6, &func_800896D8, shadowBuff);
            }
        }
    }
    D_801DEB14 = D_801A9064;
    D_801A9064 = 0;
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_73", func_800896D8);
