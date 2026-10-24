#include "common.h"

typedef struct{
    VECTOR viewPos;
    VECTOR viewPosPrev;
    SVECTOR viewRot;
} CameraVectors;

extern VECTOR D_80162830;

//VECTOR?
extern s32 D_80162840; //Pitch
extern s32 D_80162844; //Yaw
extern s32 D_80162848; //Roll

extern SVECTOR D_80195E90;

extern MATRIX D_801D4760; //ViewCopy

extern CameraVectors D_802043B0;

extern VECTOR D_80204390;
extern SVECTOR D_80204400;
extern VECTOR D_80206B58;

//ARRAY?
extern MATRIX D_80210990; //view?
extern MATRIX D_802109B0;

extern u8 D_80210B61;

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80032FC0);
// void func_80032FC0(VECTOR* v0, s32 roll, s32 yaw, s32 pitch) {
//     VECTOR v1;
//     VECTOR v2;
//     VECTOR* v3;
//     s32 roll2;
//     void* viewMatrix;

//     memcpy(&D_80162830, v0, 0x10);

//     D_80162840 = roll;
//     D_80162844 = yaw;
//     D_80162848 = pitch;
    
//     D_802043B0.viewRot.vx = -pitch & 0xFFF;
//     D_802043B0.viewRot.vy = yaw & 0xFFF;
//     D_802043B0.viewRot.vz = 0;

//     RotMatrixYXZ(&D_802043B0.viewRot, &D_80210990);
//     viewMatrix = &D_80210990 + 0x1;
//     func_80031E10(&D_80210990, viewMatrix);
//     roll2 = roll << D_80210B61;
    
//     v1.vx = (-v0->vx << D_80210B61) + FIXED(FIXED(roll2 * rsin_thunk(yaw)) * rcos_thunk(pitch));
//     v1.vy = (-v0->vy << D_80210B61) + FIXED(roll2 * rsin_thunk(pitch));
//     v1.vz = (-v0->vz << D_80210B61) + FIXED(FIXED(roll2 * rcos_thunk(yaw)) * rcos_thunk(pitch));
    
//     ApplyMatrixLV(viewMatrix, &v1, (VECTOR*)&D_80210990.t[0] + 2);
//     memcpy(&gCameraView, viewMatrix, 0x20);
    
//     v1.vx = FIXED(FIXED(roll * rsin_thunk(yaw)) * rcos_thunk(pitch)) - v0->vx;
//     v1.vy = FIXED(roll * rsin_thunk(pitch)) - v0->vy;
//     v1.vz = FIXED(FIXED(roll * rcos_thunk(yaw)) * rcos_thunk(pitch)) - v0->vz;
    
//     memcpy(&D_802043B0.viewPosPrev, &D_802043B0.viewPos, 0x10);

//     v3 = &D_802043B0.viewPos;
    
//     D_80195E90.vx = -v1.vx;
//     v3->vx = (s16) -v1.vx;
    
//     D_80195E90.vy = -v1.vy;
//     v3->vy = (s16) -v1.vy;
    
//     D_80195E90.vz = -v1.vz;
//     v3->vz = (s16) -v1.vz;
    
//     ApplyMatrixLV(viewMatrix, &v1, &v2);
//     D_80206B58.vx = v2.vx;
//     D_80206B58.vy = v2.vy;
//     D_80206B58.vz = v2.vz;
// }

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_800332EC);
// void func_800332EC(VECTOR *v, s32 pitch, s32 yaw, s32 roll) {
//   memcpy(&D_80204390,v,0x10);
//   func_80032FC0(v, pitch, yaw, roll);
//   return;
// }

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80033358);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80033468);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_8003358C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_800336AC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80033950);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034338);

void func_80034508(void) {
}

void func_80034510(void) {
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034518);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034634);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034678);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_8003480C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034844);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034904);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_8003491C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034A00);



INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034A54);

extern s32 D_800A8DE4;
extern s32 D_800A8DE8;
extern u8 D_80162738[228];
extern s32* D_80162898[8];
extern u8 D_80204348[228];
extern s8 D_8020434D;
INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034A7C);
// void func_80034A7C(void) {
//     if (D_800A8DE8 != 0) {
//         D_800A8DE8 -= 1;
//         switch(*(D_80162898)[D_800A8DE4]) {
//         case 1:
//             D_8020434D = 0;
//             break;
//         case 2:
//             D_8020434D = 4;
//             break;
//         case 3:
//             memcpy(&D_80162738, &D_80204348, sizeof(D_80204348));
//             D_8020434D = 6;
//             break;
//         case 4:
//             memcpy(&D_80204348, &D_80162738, sizeof(D_80162738));
//             D_8020434D = 4;
//             break;
//         case 0:
//         case 6:
//             break;
//     }
//   }
// }

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034B34);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034B54);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034B68);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034BD0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034C38);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034CA0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034D08);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034D70);
// void func_80034D70(SVECTOR* arg0) {
//     D_802043B0.viewPos.vx += arg0->vx;
//     D_802043B0.viewPos.vy += arg0->vy;
//     D_802043B0.viewPos.vz += arg0->vz;
    
//     D_802043B0.viewPosPrev.vx += arg0->vx;
//     D_802043B0.viewPosPrev.vy += arg0->vy;
//     D_802043B0.viewPosPrev.vz += arg0->vz;
// }

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034E04);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034E3C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034E74);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80034FCC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_8003501C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_8003516C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80035180);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80035240);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_19", func_80035288);

void func_800353E0(void) {
}

void func_800353E8(void) {
}

void func_800353F0(void) {
}

void func_800353F8(void) {
}

void func_80035400(void) {
}

void func_80035408(void) {
}

void func_80035410(void) {
}

void func_80035418(void) {
}

void func_80035420(void) {
}

void func_80035428(void) {
}

void func_80035430(void) {
}

void func_80035438(void) {
}

void func_80035440(void) {
}

void func_80035448(void) {
}

void func_80035450(void) {
}

void func_80035458(void) {
}

void func_80035460(void) {
}

void func_80035468(void) {
}

void func_80035470(void) {
}

void func_80035478(void) {
}

void func_80035480(void) {
}

void func_80035488(void) {
}

void func_80035490(void) {
}

void func_80035498(void) {
}

void func_800354A0(void) {
}

void func_800354A8(void) {
}

void func_800354B0(void) {
}

void func_800354B8(void) {
}

void func_800354C0(void) {
}
