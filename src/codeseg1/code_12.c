#include "common.h"

extern MATRIX* TransposeMatrix(MATRIX*, MATRIX*);

//Data
MATRIX D_800A8720 = {{{0x1000, 0, 0}, {0, 0x1000, 0}, {0, 0, 0x1000}}, {0, 0, 0}}; //Identity MATRIX
MATRIX D_800A8740 = {{{0x0200, 0, 0}, {0, 0x0200, 0}, {0, 0, 0x0200}}, {0, 0, 0}}; //Identity MATRIX, 8th scale?
MATRIX D_800A8760 = {{{0xFE00, 0, 0}, {0, 0xFE00, 0}, {0, 0, 0xFE00}}, {0, 0, 0}}; //Identity MATRIX, 8th scale and inverted?

//MATRIX_to_mtx
//Converts the PSX style MATRIX into the n64 format Mtx
// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_12", func_8002C420);
Mtx* func_8002C420(MATRIX* matrix, Mtx* mtx) {
    //Integer
    mtx->m[0][0] = (matrix->m[0][0] << 0x4 & 0xFFFF0000) + (matrix->m[0][1] >> 0xC & 0xFFFF);
    mtx->m[0][1] = matrix->m[0][2] << 0x4 & 0xFFFF0000;
    mtx->m[0][2] = (matrix->m[1][0] << 0x4 & 0xFFFF0000) + (matrix->m[1][1] >> 0xC  & 0xFFFF);
    mtx->m[0][3] = matrix->m[1][2] << 0x4 & 0xFFFF0000;
    mtx->m[1][0] = (matrix->m[2][0] << 0x4 & 0xFFFF0000) + (matrix->m[2][1] >> 0xC  & 0xFFFF);
    mtx->m[1][1] = matrix->m[2][2] << 0x4 & 0xFFFF0000;
    mtx->m[1][2] = (matrix->t[0] & 0xFFFF0000) + (u16)(matrix->t[1] >> 0x10);
    mtx->m[1][3] = (matrix->t[2] & 0xFFFF0000) + 1;

    //Fractional
    mtx->m[2][0] = (matrix->m[0][0] << 0x14 & 0xFFFF0000) + (matrix->m[0][1] << 4 & 0xFFFF);
    mtx->m[2][1] = (matrix->m[0][2] << 0x14) & 0xFFFF0000;
    mtx->m[2][2] = (matrix->m[1][0] << 0x14 & 0xFFFF0000) + (matrix->m[1][1] << 4 & 0xFFFF);
    mtx->m[2][3] = (matrix->m[1][2] << 0x14) & 0xFFFF0000;
    mtx->m[3][0] = (matrix->m[2][0] << 0x14 & 0xFFFF0000) + (matrix->m[2][1] << 4 & 0xFFFF);
    mtx->m[3][1] = matrix->m[2][2] << 0x14 & 0xFFFF0000;
    mtx->m[3][2] = (matrix->t[0] << 0x10 & 0xFFFF0000) + (u16)matrix->t[1];
    mtx->m[3][3] = matrix->t[2] << 0x10 & 0xFFFF0000;
    return mtx;
}


// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_12", func_8002C5A4);
//convert_matrix
Mtx* func_8002C5A4(MATRIX* matrix, Mtx* mtx){
    MATRIX m;
    MATRIX* mPtr;

    mPtr = &m; //probable inline

    memcpy(mPtr, matrix, sizeof(MATRIX));
    TransposeMatrix(matrix, mPtr);
    m.t[0] <<= 16;
    m.t[1] <<= 16;
    m.t[2] <<= 16;
    func_8002C420(mPtr, mtx);
    return mtx;

}

static inline Mtx* func_8002C62C_inline(MATRIX* m1, Mtx* m2){
    return func_8002C420(m1, m2);
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_12", func_8002C62C);
//MATRIX_to_mtx_UNUSED
Mtx* func_8002C62C(MATRIX* matrix, Mtx* mtx){
    func_8002C420(matrix, mtx);
    return mtx;
}


// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_12", func_8002C654);
//load_ident_mtx
void func_8002C654(MATRIX* m){
    memcpy(m, &D_800A8720, sizeof(MATRIX));
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_12", func_8002C678);
//load_ident_rotation
//loads only the 3x3 portion of the identity MATRIX
void func_8002C678(void* m){
    memcpy(m, &D_800A8720, 0x14);
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_12", func_8002C69C);
//load_ident_rotation_2
void func_8002C69C(MATRIX* m){
    memcpy(m, &D_800A8740, 0x14);
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_12", func_8002C6C0);
//load_ident_rotation_3
void func_8002C6C0(MATRIX* m){
    memcpy(m, &D_800A8760, 0x14);
}
