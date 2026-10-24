#include "common.h"

// Defines
#define maxAngle 4096
#define ninetyDegree 1024

// externs/BSS
extern MATRIX gRotMatrix;
extern VECTOR gTransMatrix;
extern s16 D_8019A7AC;
extern s32 D_801ADCD8;
extern s32 D_80204698;
extern s16 D_8020469C;
extern s32 D_80195470;
extern VECTOR D_801BC0A8;

// Data
static s16 ratan_tbl[648] = {
    0x0,   0x1,   0x2,   0x3,   0x4,   0x5,   0x6,   0x7,   0x8,   0x9,   0xA,   0xB,   0xC,   0xD,   0xE,   0xF,
    0x10,  0x11,  0x12,  0x13,  0x14,  0x15,  0x16,  0x17,  0x18,  0x19,  0x1A,  0x1B,  0x1C,  0x1D,  0x1E,  0x1F,
    0x20,  0x21,  0x22,  0x23,  0x24,  0x25,  0x26,  0x27,  0x28,  0x29,  0x2A,  0x2B,  0x2C,  0x2D,  0x2E,  0x2F,
    0x30,  0x31,  0x32,  0x33,  0x34,  0x35,  0x36,  0x37,  0x38,  0x39,  0x3A,  0x3B,  0x3C,  0x3D,  0x3E,  0x3F,
    0x40,  0x41,  0x42,  0x43,  0x45,  0x46,  0x47,  0x48,  0x49,  0x4A,  0x4B,  0x4C,  0x4D,  0x4E,  0x4F,  0x50,
    0x51,  0x52,  0x53,  0x54,  0x55,  0x56,  0x57,  0x58,  0x59,  0x5A,  0x5B,  0x5C,  0x5D,  0x5E,  0x5F,  0x60,
    0x61,  0x62,  0x63,  0x64,  0x65,  0x66,  0x67,  0x68,  0x69,  0x6A,  0x6A,  0x6B,  0x6C,  0x6D,  0x6E,  0x6F,
    0x70,  0x71,  0x72,  0x73,  0x74,  0x75,  0x76,  0x77,  0x78,  0x79,  0x7A,  0x7B,  0x7C,  0x7D,  0x7E,  0x7F,
    0x80,  0x81,  0x82,  0x83,  0x84,  0x85,  0x86,  0x87,  0x88,  0x89,  0x8A,  0x8B,  0x8C,  0x8D,  0x8E,  0x8F,
    0x90,  0x91,  0x92,  0x93,  0x94,  0x95,  0x96,  0x97,  0x98,  0x98,  0x99,  0x9A,  0x9B,  0x9C,  0x9D,  0x9E,
    0x9F,  0xA0,  0xA1,  0xA2,  0xA3,  0xA4,  0xA5,  0xA6,  0xA7,  0xA8,  0xA9,  0xAA,  0xAB,  0xAC,  0xAD,  0xAD,
    0xAE,  0xAF,  0xB0,  0xB1,  0xB2,  0xB3,  0xB4,  0xB5,  0xB6,  0xB7,  0xB8,  0xB9,  0xBA,  0xBB,  0xBC,  0xBD,
    0xBD,  0xBE,  0xBF,  0xC0,  0xC1,  0xC2,  0xC3,  0xC4,  0xC5,  0xC6,  0xC7,  0xC8,  0xC9,  0xCA,  0xCB,  0xCB,
    0xCC,  0xCD,  0xCE,  0xCF,  0xD0,  0xD1,  0xD2,  0xD3,  0xD4,  0xD5,  0xD6,  0xD6,  0xD7,  0xD8,  0xD9,  0xDA,
    0xDB,  0xDC,  0xDD,  0xDE,  0xDF,  0xE0,  0xE0,  0xE1,  0xE2,  0xE3,  0xE4,  0xE5,  0xE6,  0xE7,  0xE8,  0xE8,
    0xE9,  0xEA,  0xEB,  0xEC,  0xED,  0xEE,  0xEF,  0xF0,  0xF0,  0xF1,  0xF2,  0xF3,  0xF4,  0xF5,  0xF6,  0xF7,
    0xF8,  0xF8,  0xF9,  0xFA,  0xFB,  0xFC,  0xFD,  0xFE,  0xFF,  0xFF,  0x100, 0x101, 0x102, 0x103, 0x104, 0x105,
    0x105, 0x106, 0x107, 0x108, 0x109, 0x10A, 0x10B, 0x10B, 0x10C, 0x10D, 0x10E, 0x10F, 0x110, 0x111, 0x111, 0x112,
    0x113, 0x114, 0x115, 0x116, 0x117, 0x117, 0x118, 0x119, 0x11A, 0x11B, 0x11C, 0x11C, 0x11D, 0x11E, 0x11F, 0x120,
    0x121, 0x121, 0x122, 0x123, 0x124, 0x125, 0x126, 0x126, 0x127, 0x128, 0x129, 0x12A, 0x12A, 0x12B, 0x12C, 0x12D,
    0x12E, 0x12F, 0x12F, 0x130, 0x131, 0x132, 0x133, 0x133, 0x134, 0x135, 0x136, 0x137, 0x137, 0x138, 0x139, 0x13A,
    0x13B, 0x13B, 0x13C, 0x13D, 0x13E, 0x13F, 0x13F, 0x140, 0x141, 0x142, 0x143, 0x143, 0x144, 0x145, 0x146, 0x147,
    0x147, 0x148, 0x149, 0x14A, 0x14A, 0x14B, 0x14C, 0x14D, 0x14E, 0x14E, 0x14F, 0x150, 0x151, 0x151, 0x152, 0x153,
    0x154, 0x154, 0x155, 0x156, 0x157, 0x157, 0x158, 0x159, 0x15A, 0x15B, 0x15B, 0x15C, 0x15D, 0x15E, 0x15E, 0x15F,
    0x160, 0x161, 0x161, 0x162, 0x163, 0x164, 0x164, 0x165, 0x166, 0x166, 0x167, 0x168, 0x169, 0x169, 0x16A, 0x16B,
    0x16C, 0x16C, 0x16D, 0x16E, 0x16F, 0x16F, 0x170, 0x171, 0x171, 0x172, 0x173, 0x174, 0x174, 0x175, 0x176, 0x177,
    0x177, 0x178, 0x179, 0x179, 0x17A, 0x17B, 0x17C, 0x17C, 0x17D, 0x17E, 0x17E, 0x17F, 0x180, 0x180, 0x181, 0x182,
    0x183, 0x183, 0x184, 0x185, 0x185, 0x186, 0x187, 0x187, 0x188, 0x189, 0x18A, 0x18A, 0x18B, 0x18C, 0x18C, 0x18D,
    0x18E, 0x18E, 0x18F, 0x190, 0x190, 0x191, 0x192, 0x192, 0x193, 0x194, 0x194, 0x195, 0x196, 0x196, 0x197, 0x198,
    0x198, 0x199, 0x19A, 0x19A, 0x19B, 0x19C, 0x19C, 0x19D, 0x19E, 0x19E, 0x19F, 0x1A0, 0x1A0, 0x1A1, 0x1A2, 0x1A2,
    0x1A3, 0x1A4, 0x1A4, 0x1A5, 0x1A6, 0x1A6, 0x1A7, 0x1A8, 0x1A8, 0x1A9, 0x1A9, 0x1AA, 0x1AB, 0x1AB, 0x1AC, 0x1AD,
    0x1AD, 0x1AE, 0x1AF, 0x1AF, 0x1B0, 0x1B0, 0x1B1, 0x1B2, 0x1B2, 0x1B3, 0x1B4, 0x1B4, 0x1B5, 0x1B5, 0x1B6, 0x1B7,
    0x1B7, 0x1B8, 0x1B9, 0x1B9, 0x1BA, 0x1BA, 0x1BB, 0x1BC, 0x1BC, 0x1BD, 0x1BE, 0x1BE, 0x1BF, 0x1BF, 0x1C0, 0x1C1,
    0x1C1, 0x1C2, 0x1C2, 0x1C3, 0x1C4, 0x1C4, 0x1C5, 0x1C5, 0x1C6, 0x1C7, 0x1C7, 0x1C8, 0x1C8, 0x1C9, 0x1CA, 0x1CA,
    0x1CB, 0x1CB, 0x1CC, 0x1CD, 0x1CD, 0x1CE, 0x1CE, 0x1CF, 0x1CF, 0x1D0, 0x1D1, 0x1D1, 0x1D2, 0x1D2, 0x1D3, 0x1D4,
    0x1D4, 0x1D5, 0x1D5, 0x1D6, 0x1D6, 0x1D7, 0x1D8, 0x1D8, 0x1D9, 0x1D9, 0x1DA, 0x1DA, 0x1DB, 0x1DC, 0x1DC, 0x1DD,
    0x1DD, 0x1DE, 0x1DE, 0x1DF, 0x1DF, 0x1E0, 0x1E1, 0x1E1, 0x1E2, 0x1E2, 0x1E3, 0x1E3, 0x1E4, 0x1E4, 0x1E5, 0x1E6,
    0x1E6, 0x1E7, 0x1E7, 0x1E8, 0x1E8, 0x1E9, 0x1E9, 0x1EA, 0x1EA, 0x1EB, 0x1EC, 0x1EC, 0x1ED, 0x1ED, 0x1EE, 0x1EE,
    0x1EF, 0x1EF, 0x1F0, 0x1F0, 0x1F1, 0x1F1, 0x1F2, 0x1F3, 0x1F3, 0x1F4, 0x1F4, 0x1F5, 0x1F5, 0x1F6, 0x1F6, 0x1F7,
    0x1F7, 0x1F8, 0x1F8, 0x1F9, 0x1F9, 0x1FA, 0x1FA, 0x1FB, 0x1FB, 0x1FC, 0x1FC, 0x1FD, 0x1FD, 0x1FE, 0x1FE, 0x1FF,
    0x1FF, 0x1FF, 0x1FF, 0x1FF, 0x1FF, 0x1FF, 0x1FF, 0x1FF
};

// Forward declarations
s32 sqrt(s32);
s32 rsin(s32);
s32 rcos(s32);

MATRIX* MulMatrix(MATRIX* m1, MATRIX* m2, MATRIX* m3) {
    s32 row, col;

    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            m3->m[row][col] =
                FIXED(m1->m[row][0] * m2->m[0][col] + m1->m[row][1] * m2->m[1][col] + m1->m[row][2] * m2->m[2][col]);
        }
    }

    return m3;
}

MATRIX* MulMatrix2(MATRIX* m1, MATRIX* m2) {
    s16 tempMtx[3][3];
    s32 row, col;
    SVECTOR v;

    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            tempMtx[row][col] =
                FIXED(m1->m[row][0] * m2->m[0][col] + m1->m[row][1] * m2->m[1][col] + m1->m[row][2] * m2->m[2][col]);
        }
    }

    memcpy(m1, &tempMtx, 0x12);

    return m1;
}

MATRIX* MulMatrix3(MATRIX* m1, MATRIX* m2) {
    s16 tempMtx[3][3];
    SVECTOR v;
    s32 row, col;

    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            tempMtx[row][col] =
                FIXED(m1->m[row][0] * m2->m[0][col] + m1->m[row][1] * m2->m[1][col] + m1->m[row][2] * m2->m[2][col]);
        }
    }

    memcpy(m2, &tempMtx, 0x12);

    return m2;
}

VECTOR* ApplyMatrix(MATRIX* m1, SVECTOR* sv, VECTOR* v) {
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

VECTOR* ApplyMatrixLV(MATRIX* m, VECTOR* v0, VECTOR* v1) {
    VECTOR tempVec;

    if (v0 == v1) {
        tempVec.vx =
            FIXED((long long)m->m[0][0] * v1->vx + (long long)m->m[0][1] * v1->vy + (long long)m->m[0][2] * v1->vz);
        tempVec.vy =
            FIXED((long long)m->m[1][0] * v1->vx + (long long)m->m[1][1] * v1->vy + (long long)m->m[1][2] * v1->vz);
        tempVec.vz =
            FIXED((long long)m->m[2][0] * v1->vx + (long long)m->m[2][1] * v1->vy + (long long)m->m[2][2] * v1->vz);
        v1->vx = tempVec.vx;
        v1->vy = tempVec.vy;
        v1->vz = tempVec.vz;
    } else {
        v1->vx =
            FIXED((long long)m->m[0][0] * v0->vx + (long long)m->m[0][1] * v0->vy + (long long)m->m[0][2] * v0->vz);
        v1->vy =
            FIXED((long long)m->m[1][0] * v0->vx + (long long)m->m[1][1] * v0->vy + (long long)m->m[1][2] * v0->vz);
        v1->vz =
            FIXED((long long)m->m[2][0] * v0->vx + (long long)m->m[2][1] * v0->vy + (long long)m->m[2][2] * v0->vz);
    }
    return v1;
}

SVECTOR* ApplyMatrixSV(MATRIX* m, SVECTOR* v1, SVECTOR* v2) {
    SVECTOR tempVec;

    if (v1 == v2) {
        tempVec.vx = FIXED((m->m[0][0] * v2->vx) + (m->m[0][1] * v2->vy) + (m->m[0][2] * v2->vz));
        tempVec.vy = FIXED((m->m[1][0] * v2->vx) + (m->m[1][1] * v2->vy) + (m->m[1][2] * v2->vz));
        tempVec.vz = FIXED((m->m[2][0] * v2->vx) + (m->m[2][1] * v2->vy) + (m->m[2][2] * v2->vz));
        v2->vx = tempVec.vx;
        v2->vy = tempVec.vy;
        v2->vz = tempVec.vz;
    } else {
        v2->vx = FIXED((m->m[0][0] * v1->vx) + (m->m[0][1] * v1->vy) + (m->m[0][2] * v1->vz));
        v2->vy = FIXED((m->m[1][0] * v1->vx) + (m->m[1][1] * v1->vy) + (m->m[1][2] * v1->vz));
        v2->vz = FIXED((m->m[2][0] * v1->vx) + (m->m[2][1] * v1->vy) + (m->m[2][2] * v1->vz));
    }
    return v2;
}

MATRIX* RotMatrix(SVECTOR* r, MATRIX* m) {
    s32 sx, sy, sz;
    s32 cx, cy, cz;

    sx = rsin(r->vx);
    cx = rcos(r->vx);
    sy = rsin(r->vy);
    cy = rcos(r->vy);
    sz = rsin(r->vz);
    cz = rcos(r->vz);

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

MATRIX* RotMatrixYXZ(SVECTOR* r, MATRIX* m) {
    s32 sx, sy, sz;
    s32 cx, cy, cz;

    sx = rsin(r->vx);
    cx = rcos(r->vx);

    sy = rsin(r->vy);
    cy = rcos(r->vy);

    sz = rsin(r->vz);
    cz = rcos(r->vz);

    m->m[0][0] = FIXED(cy * cz + FIXED(sy * sx) * sz);
    m->m[0][1] = FIXED(-cy * sz + FIXED(sy * sx) * cz);
    m->m[0][2] = FIXED(sy * cx);
    m->m[1][0] = FIXED(cx * sz);
    m->m[1][1] = FIXED(cx * cz);
    m->m[1][2] = -sx;
    m->m[2][0] = FIXED(-sy * cz + FIXED(cy * sx) * sz);
    m->m[2][1] = FIXED(sy * sz + FIXED(cy * sx) * cz);
    m->m[2][2] = FIXED(cy * cx);

    return m;
}

MATRIX* RotMatrixX(s32 r, MATRIX* m1) {
    MATRIX m2;
    MATRIX m3;
    s32 row, col;
    s16 sin, cos;

    memcpy(&m3, m1, 0x20);

    sin = rsin(r);
    cos = rcos(r);

    m2.m[0][0] = 0x1000;
    m2.m[0][1] = 0;
    m2.m[0][2] = 0;
    m2.m[1][0] = 0;
    m2.m[1][1] = cos;
    m2.m[1][2] = -sin;
    m2.m[2][0] = 0;
    m2.m[2][1] = sin;
    m2.m[2][2] = cos;

    MulMatrix(&m2, &m3, m1);

    return m1;
}

// RotateMatrixX_inline_1
MATRIX* func_800318C8(s32 r, MATRIX* m1) {
    s16 sin, cos;

    sin = rsin(r);
    cos = rcos(r);

    m1->m[0][0] = 0x1000;
    m1->m[0][1] = 0;
    m1->m[0][2] = 0;
    m1->m[1][0] = 0;
    m1->m[1][1] = cos;
    m1->m[1][2] = -sin;
    m1->m[2][0] = 0;
    m1->m[2][1] = sin;
    m1->m[2][2] = cos;

    return m1;
}

// RotateMatrixX_inline_2
MATRIX* func_80031938(s32 r, MATRIX* m1) {
    s16 sin, cos;

    sin = rsin(r);
    cos = rcos(r);

    m1->m[0][0] = 0x1000;
    m1->m[0][1] = 0;
    m1->m[0][2] = 0;
    m1->m[1][0] = 0;
    m1->m[1][1] = cos;
    m1->m[1][2] = -sin;
    m1->m[2][0] = 0;
    m1->m[2][1] = sin;
    m1->m[2][2] = cos;

    m1->t[0] = 0;
    m1->t[1] = 0;
    m1->t[2] = 0;

    return m1;
}

MATRIX* RotMatrixY(s32 r, MATRIX* m1) {
    MATRIX m2;
    MATRIX m3;
    s32 row, col;
    s16 sin, cos;

    memcpy(&m3, m1, 0x20);

    sin = rsin(r);
    cos = rcos(r);

    m2.m[0][0] = cos;
    m2.m[0][1] = 0;
    m2.m[0][2] = sin;
    m2.m[1][0] = 0;
    m2.m[1][1] = 0x1000;
    m2.m[1][2] = 0;
    m2.m[2][0] = -sin;
    m2.m[2][1] = 0;
    m2.m[2][2] = cos;

    MulMatrix(&m2, &m3, m1);

    return m1;
}

// RotateMatrixY_inline_1
MATRIX* func_80031AC0(s32 r, MATRIX* m) {
    s16 sin, cos;

    sin = rsin(r);
    cos = rcos(r);

    m->m[0][0] = cos;
    m->m[0][1] = 0;
    m->m[0][2] = sin;
    m->m[1][0] = 0;
    m->m[1][1] = 0x1000;
    m->m[1][2] = 0;
    m->m[2][0] = -sin;
    m->m[2][1] = 0;
    m->m[2][2] = cos;

    m->t[0] = 0;
    m->t[1] = 0;
    m->t[2] = 0;

    return m;
}

// RotateMatrixY_inline_2
MATRIX* func_80031B40(s32 r, MATRIX* m) {
    s16 sin, cos;

    sin = rsin(r);
    cos = rcos(r);

    m->m[0][0] = cos;
    m->m[0][1] = 0;
    m->m[0][2] = sin;
    m->m[1][0] = 0;
    m->m[1][1] = 0x1000;
    m->m[1][2] = 0;
    m->m[2][0] = -sin;
    m->m[2][1] = 0;
    m->m[2][2] = cos;

    return m;
}

MATRIX* RotMatrixZ(s32 r, MATRIX* m1) {
    MATRIX m2;
    MATRIX m3;
    s32 row, col;
    s16 sin, cos;

    memcpy(&m3, m1, 0x20);

    sin = rsin(r);
    cos = rcos(r);

    m2.m[0][0] = cos;
    m2.m[0][1] = -sin;
    m2.m[0][2] = 0;
    m2.m[1][0] = sin;
    m2.m[1][1] = cos;
    m2.m[1][2] = 0;
    m2.m[2][0] = 0;
    m2.m[2][1] = 0;
    m2.m[2][2] = 0x1000;

    MulMatrix(&m2, &m3, m1);

    return m1;
}

// RotateMatrixZ_inline_1
MATRIX* func_80031CBC(s32 r, MATRIX* m) {
    s16 sin, cos;

    sin = rsin(r);
    cos = rcos(r);

    m->m[0][0] = cos;
    m->m[0][1] = -sin;
    m->m[0][2] = 0;
    m->m[1][0] = sin;
    m->m[1][1] = cos;
    m->m[1][2] = 0;
    m->m[2][0] = 0;
    m->m[2][1] = 0;
    m->m[2][2] = 0x1000;

    m->t[0] = 0;
    m->t[1] = 0;
    m->t[2] = 0;

    return m;
}

// RotateMatrixZ_inline_2
MATRIX* func_80031D38(s32 r, MATRIX* m) {
    s16 sin, cos;

    sin = rsin(r);
    cos = rcos(r);

    m->m[0][0] = cos;
    m->m[0][1] = -sin;
    m->m[0][2] = 0;
    m->m[1][0] = sin;
    m->m[1][1] = cos;
    m->m[1][2] = 0;
    m->m[2][0] = 0;
    m->m[2][1] = 0;
    m->m[2][2] = 0x1000;
    return m;
}

MATRIX* ScaleMatrix(MATRIX* m, VECTOR* v) {
    s32 i;

    for (i = 0; i < 3; i++) {
        m->m[i][0] = FIXED(m->m[i][0] * v->vx);
        m->m[i][1] = FIXED(m->m[i][1] * v->vy);
        m->m[i][2] = FIXED(m->m[i][2] * v->vz);
    };
    return m;
}

MATRIX* TransposeMatrix(MATRIX* m1, MATRIX* m2) {
    s32 row, col;

    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            m2->m[col][row] = m1->m[row][col];
        }
    }

    return m2;
}

void SetRotMatrix(s16 m[3][3]) {
    memcpy(&gRotMatrix, m, 0x12);
    return;
}

void func_80031E84(void) {
}

void func_80031E8C(void) {
}

void SetTransMatrix(MATRIX* m) {
    gTransMatrix.vx = m->t[0];
    gTransMatrix.vy = m->t[1];
    gTransMatrix.vz = m->t[2];
    return;
}

void func_80031EBC(void) {
}

void func_80031EC4(void) {
}

void func_80031ECC(s32 arg0, s32 arg1) {
    D_8020469C = 160 - arg0;
    D_8019A7AC = 120 - arg1;
    D_80204698 = arg0;
    D_801ADCD8 = arg1;
    return;
}

void func_80031F00(s32 arg0) {
    D_80195470 = arg0;
    return;
}

s32 func_80031F0C(SVECTOR* v1, SVECTOR* v2) {
    ApplyMatrix(&gRotMatrix, v1, &D_801BC0A8);
    D_801BC0A8.vx += gTransMatrix.vx;
    D_801BC0A8.vy += gTransMatrix.vy;
    D_801BC0A8.vz += gTransMatrix.vz;

    v2->vx = ((D_80195470 / 2) * D_801BC0A8.vx / (D_801BC0A8.vz | 1)) + D_80204698;
    v2->vy = ((D_80195470 / 2) * D_801BC0A8.vy / (D_801BC0A8.vz | 1)) + D_801ADCD8;

    return D_801BC0A8.vz / 4;
}

void func_80032068(SVECTOR* vs, VECTOR* v) {
    ApplyMatrix(&gRotMatrix, vs, v);
    v->vx += gTransMatrix.vx;
    v->vy += gTransMatrix.vy;
    v->vz += gTransMatrix.vz;
    return;
}

void func_800320DC(void) {
}

void CrossProductSV(VECTOR* v1, VECTOR* v2, VECTOR* v3) {
    v3->vx = FIXED(v1->vy * v2->vz - v1->vz * v2->vy);
    v3->vy = FIXED(v1->vz * v2->vx - v1->vx * v2->vz);
    v3->vz = FIXED(v1->vx * v2->vy - v1->vy * v2->vx);
    return;
}

void CrossProduct(VECTOR* v1, VECTOR* v2, VECTOR* v3) {
    v3->vx = v1->vy * v2->vz - v1->vz * v2->vy;
    v3->vy = v1->vz * v2->vx - v1->vx * v2->vz;
    v3->vz = v1->vx * v2->vy - v1->vy * v2->vx;
    return;
}

s32 normalize(VECTOR* v1, VECTOR* v2) {
    s32 val;

    val = sqrt((v1->vx * v1->vx) + (v1->vy * v1->vy) + (v1->vz * v1->vz));
    if (val != 0) {
        v2->vx = ((v1->vx << 12) / val);
        v2->vy = ((v1->vy << 12) / val);
        v2->vz = ((v1->vz << 12) / val);
    }

    return val;
}

s32 normalizeSV(VECTOR* v, SVECTOR* vs) {
    s32 val;

    val = sqrt((v->vx * v->vx) + (v->vy * v->vy) + (v->vz * v->vz));
    if (val != 0) {
        vs->vx = ((v->vx << 12) / val);
        vs->vy = ((v->vy << 12) / val);
        vs->vz = ((v->vz << 12) / val);
    }

    return val;
}

s32 sqrt(s32 num) {
    u32 temp_a1;
    u32 var_v1;

    var_v1 = 1;
    if (num == 0) {
        return 0;
    }

    temp_a1 = num;
    while (var_v1 < temp_a1) {
        var_v1 *= 2;
        temp_a1 /= 2;
    }

    do {
        temp_a1 = var_v1;
        var_v1 = ((num / temp_a1) + temp_a1) / 2;
    } while (var_v1 < temp_a1);

    return temp_a1;
}

void func_80032490(void) {
}

s32 rcos_thunk(s32 a) {
    return rcos(a);
}

s32 rsin_thunk(s32 a) {
    return rsin(a);
}

s32 rcos(s32 a) {
    a &= 0xfff;
    if (a == 0) {
        return 0x1000;
    } else if (a == 0x800) {
        return -0x1000;
    } else {
        return coss(a * 0x10) >> 3;
    }
}

s32 rsin(s32 a) {
    a &= 0xfff;
    if (a == 0x400)
        return 0x1000;
    else if (a == 0xc00)
        return -0x1000;
    else
        return sins(a * 16) >> 3;
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/libgte", func_80032554);
// ratan?
s32 func_80032554(s32 angle) {
    s32 mask = 0xFFF;

    if (angle > 0) {
        if (angle < 4096) {
            angle = angle * 640 >> 12;
            angle = ratan_tbl[angle];
            return angle & mask;
        } else {
            angle = 0x280000 / angle;
            angle = 0x400 - ratan_tbl[angle];
            return angle & mask;
        }
    }

    if (angle < 0) {
        angle = -angle;
        if (angle < 4096) {
            angle = angle * 640 >> 12;
            angle = 0x1000 - ratan_tbl[angle];
            return angle & mask;
        } else {
            angle = 0x280000 / angle;
            angle = ratan_tbl[angle] + 0xc00;
            return angle & mask;
        }
    }

    return 0;
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/libgte", func_80032664);
// ratan_long
//  s64 func_80032664(s64 y, s64 x)
//  {
//      s64 result;
//      s32 temp1;
//      s32 temp2;

//     s32 xInt;
//     s32 yInt;

//     s32 ret;

//     if(x == 0 && y == 0){
//         return 0;
//     }

//     // xInt = x;
//     // yInt = y;

//     // temp2 = -(~xInt & ~yInt) >> 0x1F;

//     if(x > 0 && y > 0){
//         if(-x > y){
//             return 0x400 - ratan_tbl[(y * 0x280 >> 12) / x];
//         } else {
//             return 0x800 - ratan_tbl[x / (y * 0x280 >> 12)] & 0xFFF;
//         }
//     } else if(xInt & yInt < 0){

//     } else  {
//         return 0;
//     }

//     // if(-xInt < yInt){
//     //     temp1 = -xInt * 0x280  / yInt;
//     //     temp1 = 0x800 - ratan_tbl[temp1];
//     //     ret =  temp1 & 0xFFF;

//     // }

//     return ret;

// }