#include "common.h"

f32 __cosf(f32);
f32 __sinf(f32);
extern f32 D_80210B18;
extern f32 D_8021D928;

void guPerspectiveF(f32 mf[4][4], u16* perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale) {
    float cot;
    s32 row, col;

    D_80210B18 = near;
    D_8021D928 = far;
    guMtxIdentF(mf);

    fovy *= 3.1415926 / 180.0;
    cot = __cosf(fovy / 2) / __sinf(fovy / 2);

    mf[0][0] = (cot) / aspect;
    mf[1][1] = -(cot);
    mf[2][2] = (-(near + far)) / (near - far);
    mf[2][3] = 1.0f;
    mf[3][2] = ((near + near) * far) / (near - far);
    mf[3][3] = 0;
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            mf[row][col] *= scale;
        }
    }

    if (perspNorm != (u16*)NULL) {
        if (near + far <= 2.0) {
            *perspNorm = (u16)0xFFFF;
        } else {
            *perspNorm = (u16)((2.0 * 65536.0) / (near + far));
            if (*perspNorm <= 0)
                *perspNorm = (u16)0x0001;
        }
    }
}

void guPerspective(Mtx* m, u16* perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale) {
    float mat[4][4];

    guPerspectiveF(mat, perspNorm, fovy, aspect, near, far, scale);
    guMtxF2L(mat, m);
}
