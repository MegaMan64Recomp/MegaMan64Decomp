#include "common.h"

typedef struct {
    s16 m[3][3];
} ViewMtx;

typedef struct {
    s32 x,y,z;
} Vec3;

typedef struct {
    s16 x,y,z;
} Vec3s;

typedef struct {
    s16 m[3][3];
    s16 pad;
    s32 x,y,z;
} CameraView;

//PSX Defs
typedef struct {
	s16	m[3][3];
	s32	t[3];
} MATRIX;

typedef struct {		/* int  word type 3D vector */
	s32		vx, vy;
	s32		vz, pad;
} VECTOR;

typedef struct {
	s16	vx, vy;
	s16	vz, pad;
} SVECTOR;

#define	FIXED(a) ((a) >> 12)

extern void memcpy(void*, void*, s32);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FD30);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FD5C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FD88);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FD90);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FD98);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FDA0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FDA8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FDC0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8002FDF4);

void func_80028470(s32);                                 /* extern */
void func_80028600(s32, Mtx*, u16);                        /* extern */
void func_800288D8(s32, Mtx*);                           /* extern */
void func_8002891C(s32);                                 /* extern */
void func_80028978(s32);                                 /* extern */
void func_80028A00(s8, s32, s32);                           /* extern */
void func_8002C238(Mtx*, u16*, f32, f32, f32, f32, f32);     /* extern */
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
        func_8002C238(&projectionMtx, &perspNorm, 37.5f, 1.3333334f, 192.0f, 7168.0f, 1.0f);
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
    return ((arg0 & 3) << 7) | ((arg1 & 3) << 5) | ((s32) (arg3 & 0x100) >> 4) | ((s32) (arg2 & 0x3FF) >> 6) | ((arg3 & 0x200) * 4);
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
extern void func_800861E0;

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
                func_800283A8(pool, gfxContextIndex, &func_800861E0, gfxData);
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
        if ((nextHeader & 0xFFFFFF00) == 0xffffff00){
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

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800306C0);

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800306F0);
CameraView* func_800306F0(CameraView* m1, CameraView* m2, CameraView* m3) {
    s32 temp;
    s32 x,y,z;
    s32 row, col;

    for (row = 0; row < 3; row++){
        for (col = 0; col < 3; col++){
            m3->m[row][col] = (
                m1->m[row][0] * m2->m[0][col] +
                m1->m[row][1] * m2->m[1][col] +
                m1->m[row][2] * m2->m[2][col]) >> 0xC;
        }
    }
    
    return m3;
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8003077C);
ViewMtx* func_8003077C(ViewMtx* m1, ViewMtx* m2) {
    ViewMtx tempMtx;
    s16 mtx3[3];
    s32 row, col;

    for (row = 0; row < 3; row++){
        for (col = 0; col < 3; col++){
            tempMtx.m[row][col] = (
                m1->m[row][0] * m2->m[0][col] +
                m1->m[row][1] * m2->m[1][col] +
                m1->m[row][2] * m2->m[2][col]) >> 0xC;
        }
    }
    memcpy(m1, &tempMtx, 0x12);
    return m1;
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030834);
ViewMtx* func_80030834(ViewMtx* m1, ViewMtx* m2) {
    ViewMtx tempMtx;
    s16 mtx3[3];
    s32 row, col;

    for (row = 0; row < 3; row++){
        for (col = 0; col < 3; col++){
            tempMtx.m[row][col] = (
                m1->m[row][0] * m2->m[0][col] +
                m1->m[row][1] * m2->m[1][col] +
                m1->m[row][2] * m2->m[2][col]) >> 0xC;
        }
    }
    memcpy(m2, &tempMtx, 0x12);
    return m2;
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800308E8);
VECTOR* func_800308E8(MATRIX* m1, SVECTOR* sv, VECTOR* v) {
    VECTOR tempVec;

    if (sv == v) {
        tempVec.vx = FIXED(m1->m[0][0] * sv->vx + m1->m[0][1] * sv->vy + m1->m[0][2] * sv->vz);
        tempVec.vy = FIXED(m1->m[1][0] * sv->vx + m1->m[1][1] * sv->vy + m1->m[1][2] * sv->vz);
        tempVec.vz = FIXED(m1->m[2][0] * sv->vx + m1->m[2][1] * sv->vy + m1->m[2][2] * sv->vz);
        v->vx = tempVec.vx;
        v->vy = tempVec.vy;
        v->vz = tempVec.vz;
    } else {
        v->vx = FIXED(m1->m[0][0] * sv->vx + m1->m[0][1] * sv->vy + m1->m[0][2] * sv->vz);
        v->vy = FIXED(m1->m[1][0] * sv->vx + m1->m[1][1] * sv->vy + m1->m[1][2] * sv->vz);
        v->vz = FIXED(m1->m[2][0] * sv->vx + m1->m[2][1] * sv->vy + m1->m[2][2] * sv->vz);
    }
    return v;
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80030AA0);
VECTOR* func_80030AA0(MATRIX* m, VECTOR* v0, VECTOR* v1) {
    VECTOR tempVec;
    
    if (v0 == v1) {
        tempVec.vx = ((long long)m->m[0][0] * v1->vx + (long long)m->m[0][1] * v1->vy + (long long)m->m[0][2] * v1->vz) >> 12;
        tempVec.vy = ((long long)m->m[1][0] * v1->vx + (long long)m->m[1][1] * v1->vy + (long long)m->m[1][2] * v1->vz) >> 12;
        tempVec.vz = ((long long)m->m[2][0] * v1->vx + (long long)m->m[2][1] * v1->vy + (long long)m->m[2][2] * v1->vz) >> 12;
        v1->vx = tempVec.vx;
        v1->vy = tempVec.vy;
        v1->vz = tempVec.vz;
    } else {
        v1->vx = ((long long)m->m[0][0] * v0->vx + (long long)m->m[0][1] * v0->vy + (long long)m->m[0][2] * v0->vz) >> 12;
        v1->vy = ((long long)m->m[1][0] * v0->vx + (long long)m->m[1][1] * v0->vy + (long long)m->m[1][2] * v0->vz) >> 12;
        v1->vz = ((long long)m->m[2][0] * v0->vx + (long long)m->m[2][1] * v0->vy + (long long)m->m[2][2] * v0->vz) >> 12;
    }
    return v1;
}


// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031270);
SVECTOR* func_80031270(MATRIX *m, SVECTOR *v1, SVECTOR *v2) {
    SVECTOR tempVec;

    if (v1 == v2) {
        tempVec.vx = FIXED((m->m[0][0] * v2->vx) + (m->m[0][1] * v2->vy) + (m->m[0][2] * v2->vz));
        tempVec.vy = FIXED((m->m[1][0] * v2->vx) + (m->m[1][1] * v2->vy) + (m->m[1][2] * v2->vz));
        tempVec.vz = FIXED((m->m[2][0] * v2->vx) + (m->m[2][1] * v2->vy) + (m->m[2][2] * v2->vz));
        v2->vx = (s16) tempVec.vx;
        v2->vy = (s16) tempVec.vy;
        v2->vz = (s16) tempVec.vz;
    } else {
        v2->vx = FIXED((m->m[0][0] * v1->vx) + (m->m[0][1] * v1->vy) + (m->m[0][2] * v1->vz));
        v2->vy = FIXED((m->m[1][0] * v1->vx) + (m->m[1][1] * v1->vy) + (m->m[1][2] * v1->vz));
        v2->vz = FIXED((m->m[2][0] * v1->vx) + (m->m[2][1] * v1->vy) + (m->m[2][2] * v1->vz));
    }
    return v2;
}

//RotMatrix
// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031428);
MATRIX* func_80031428(SVECTOR *r,MATRIX *m){
    s32 sx, sy, sz;
    s32 cx, cy, cz;
    
    sx = func_80032510(r->vx);
    cx = func_800324D0(r->vx);
    sy = func_80032510(r->vy);
    cy = func_800324D0(r->vy);
    sz = func_80032510(r->vz);
    cz = func_800324D0(r->vz);
    
    m->m[0][0] = FIXED(cy * cz);
    m->m[0][1] = FIXED(-cy * sz);
    m->m[0][2] = sy;
    m->m[1][0] = FIXED((sx * sy >> 0xc) * cz + cx * sz);
    m->m[1][1] = FIXED((-sx * sy >> 0xc) * sz + cx * cz);
    m->m[1][2] = FIXED(-sx * cy);
    m->m[2][0] = FIXED((-cx * sy >> 0xc) * cz + sx * sz);
    m->m[2][1] = FIXED((cx * sy >> 0xc) * sz + sx * cz);
    m->m[2][2] = FIXED(cx * cy);
    
    return m;
}

//RotMatrixYXZ
// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031600);
MATRIX* func_80031600(SVECTOR* r, MATRIX* m) {
    int sx = func_80032510(r->vx); // rsin
    int cx = func_800324D0(r->vx); // rcos

    int sy = func_80032510(r->vy); // rsin
    int cy = func_800324D0(r->vy); // rcos

    int sz = func_80032510(r->vz); // rsin
    int cz = func_800324D0(r->vz); // rcos

    m->m[0][0] = FIXED(cy * cz + (((sy * sx) >> 12) * sz));
    m->m[0][1] = FIXED(-cy * sz + (((sy * sx) >> 12) * cz));
    m->m[0][2] = FIXED(sy * cx);
    m->m[1][0] = FIXED(cx * sz);
    m->m[1][1] = FIXED(cx * cz);
    m->m[1][2] = (-sx);
    m->m[2][0] = FIXED(-sy * cz + (((cy * sx) >> 12) * sz));
    m->m[2][1] = FIXED(sy * sz + (((cy * sx) >> 12) * cz));
    m->m[2][2] = FIXED(cy * cx);

    return m;
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800317C0);
MATRIX* func_800317C0(s32 r, MATRIX* m1) {
    MATRIX m2;
    MATRIX m3;
    MATRIX* m3Ptr;
    s32 row, col;
    s16 rsin, rcos;

    memcpy(&m3, m1, 0x20);
    rsin = func_80032510(r);
    rcos = func_800324D0(r);
    m2.m[0][0] = 0x1000;
    m2.m[0][1] = 0;
    m2.m[0][2] = 0;
    m2.m[1][0] = 0;
    m2.m[1][1] = rcos;
    m2.m[1][2] = -rsin;
    m2.m[2][0] = 0;
    m2.m[2][1] = rsin;
    m2.m[2][2] = rcos;

    m3Ptr = &m3;
    for(row=0; row<3; row++){
        for(col=0; col<3; col++){
            m1->m[row][col] = FIXED(
                m2.m[row][0] * m3Ptr->m[0][col] +
                m2.m[row][1] * m3Ptr->m[1][col] +
                m2.m[row][2] * m3Ptr->m[2][col]);
        }
    }
    return m1;
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800318C8);
// MATRIX* func_800318C8(s32 r, MATRIX* m1) {
//     s16 rsin, rcos;

//     rsin = func_80032510(r);
//     rcos = func_800324D0(r);
//     m1->m[0][0] = 0x1000;
//     m1->m[0][1] = 0;
//     m1->m[0][2] = 0;
//     m1->m[1][0] = 0;
//     m1->m[1][1] = rcos;
//     m1->m[1][2] = -rsin;
//     m1->m[2][0] = 0;
//     m1->m[2][1] = rsin;
//     m1->m[2][2] = rcos;

//     return m1;
// }

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031938);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800319B4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031AC0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031B40);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031BB4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031CBC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031D38);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031DA8);

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031E10);
//Transpose 3x3 matrix
Mtx* func_80031E10(short vp[3][3] , short mtx[3][3]) {
    s32 i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++){
            mtx[j][i] = vp[i][j];
        }
    }
    
    return (Mtx*)mtx;
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031E5C);

void func_80031E84(void) {
}

void func_80031E8C(void) {
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031E94);

void func_80031EBC(void) {
}

void func_80031EC4(void) {
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031ECC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031F00);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80031F0C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80032068);

void func_800320DC(void) {
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800320E4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_8003216C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800321EC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80032308);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80032424);

void func_80032490(void) {
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80032498);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800324B4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_800324D0);

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80032510);
int func_80032510(s32 a) {
    a &= 0xfff;
    if (a == 0x400) {
        return 0x1000;
    }
    else if (a == 0xc00) {
        return -0x1000;
    }
    else {
        return sins(a * 0x10) << 0x10 >> 0x13;
    }
}


INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80032554);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_16", func_80032664);
