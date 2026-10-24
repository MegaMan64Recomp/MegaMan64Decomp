#include "common.h"
#include "actor.h"

//Structs
typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 rotation;
    s16 size;
    s16 opacity;
    s8 xOffset;
    s8 yOffset;
    s8 zOffset;
} ShadowUnkStruct;

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
} UnkArg_func_8003AA3C;

typedef struct {
    s32 unks[8];
} UnkStruct_D_801BC3BC;

typedef struct {
  MATRIX m;
  s16 unk40;
  s16 unk42;
  s16 unk44;
  s16 unk46;
} BufferObj;

// externs
extern void func_8002C654(MATRIX*);                   
extern MATRIX* RotMatrixZ(s32, MATRIX*);                
extern MATRIX* ScaleMatrix(MATRIX*, VECTOR*);       
extern void SetRotMatrix(MATRIX*);                   
extern void SetTransMatrix(MATRIX*);                   
extern void func_80032068(SVECTOR*, VECTOR*, VECTOR*);
extern s32 func_80038CF8(s16, s16);                   
extern BufferObj* func_80084CF0(void*, MATRIX*);      
extern MATRIX D_801D4760;
extern u8 D_80210B61;
extern s32 func_8003E934(void*);  
extern s32 D_801A9064;
extern ShadowUnkStruct shadowArray[64];

extern PlayerActor playerActor[2];
extern ProjectileActor playerProjectileActorArray[16];
extern Actor actorArray[18];
extern BossActor bossActorArray[4];
extern ProjectileActor enemyProjectileActorArray[32];
extern EffectActor effectActorArray[64];
extern StaticActor staticActorArray[32];
extern UnkActor unkActorArray[16];

extern void func_80084870(s8, s8, u16, MATRIX*, s32);
extern void func_8008498C(s8, s8, s8, s8, MATRIX*);
extern void func_8008128C;
extern MATRIX D_801D4760; //cameraViewMatrix
extern MATRIX D_80210990; //currModelViewMatrix
extern u8 D_80210B62;
extern u16 D_802049AC;

//Forwards Declarations
void func_8003AA3C(UnkArg_func_8003AA3C*, s32);
void func_8003AB60(StaticActor*, s32);
void func_8003AFB0(void*, s32);
void func_8003B27C(void*, s32);
void func_8003B298(void*, s32);

void func_8003A2EC(Actor*);
void func_8003A888();
void func_8003A94C();
void func_8003A9C4();
s32 func_8003B7D8();
void func_8003B994();

//Data

//Actor Functions
void (*D_800AC980[])(void*, s32) = {
    func_8003AA3C,
    func_8003AB60,
    func_8003AA3C,
    func_8003AB60,
    func_8003AFB0,
    func_8003B27C,
    func_8003B298,
};

s16 D_800AC99C[16] = { 64, 64, 64, 64,
                     64, 64, 64, 64, 
                     48, 32, 16, 0, 
                     0, 0, -8, -16 };

u8 D_800AC9BC[3][5] = {
                    {6, 1, 3, 3, 2},
                    {6, 1, 3, 3, 2},
                    {6, 1, 3, 3, 2}};

u8 D_800AC9CC[15] = { 0, 8, 9, 10, 12, 
                    13, 1, 2, 3, 4, 
                    5, 6, 7, 11, 14};

//End Data


//draw_megaman
// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_80039FE0);
void func_80039FE0(PlayerActor* player, s32 arg1) {
    VECTOR vecUnused;
    VECTOR vec;
    s32 arrSize;
    s32 type;
    s32 iter;
    s32 i,j;
    s32 total;

    if (player->combatState == 0) {
        type = 0;
    } else if (player->drawnSpecialWeapon == 0) {
        type = 2;
    } else {
        type = 1;
    }
    
    func_800283A8(0, 6, &func_8008128C, 0);

    arrSize = ARRLEN(D_800AC9BC[type]);
    
    for (i = total = 0;  i < arrSize; i++){
        iter = D_800AC9BC[type][i];
        for(j = 0; j < iter; total++, j++) {
            MulMatrix(&D_801D4760, &player->modelMatrixArray[D_800AC9CC[total]], &D_80210990);
            ApplyMatrix(&D_801D4760, &player->modelSVectorArray[D_800AC9CC[total]], &vec);
            D_80210990.t[0] = D_801D4760.t[0] + vec.vx;
            D_80210990.t[1] = D_801D4760.t[1] + vec.vy;
            D_80210990.t[2] = D_801D4760.t[2] + vec.vz;
            func_80084870(0, 6, D_800AC9CC[total], &D_80210990, D_80210B62);
        }
    }

    for(i = 0; i < 1; i++) {
        MulMatrix(&D_801D4760, &player->modelMatrixArray[1], &D_80210990);
        ApplyMatrix(&D_801D4760, &player->modelSVectorArray[1], &vec);
        
        D_80210990.t[0] = D_801D4760.t[0] + vec.vx;
        D_80210990.t[1] = D_801D4760.t[1] + vec.vy;
        D_80210990.t[2] = D_801D4760.t[2] + vec.vz;
        
        func_80084870(0, 6, i + 0xF, &D_80210990, (s32) D_80210B62);
    };
    
    func_8008498C(0, 6, player->unk168, player->unk169, &D_80210990);
}



// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003A248);
//process_all_actor_arrays
void func_8003A248(){
  volatile s32 pad;

  if (D_802049AC == 0) {

    if ((playerActor[0].state & playerActor[0].unk6 & 2)) {
      func_80039FE0(&playerActor[0], 0); //render_megaman
    }

    if ((playerActor[1].state & playerActor[1].unk6 & 2)) {
      func_80039FE0(&playerActor[1], 0); //render_megaman
    }

    func_8003A888(); //process_projectile_actors
    func_8003A94C(); //process_effects_actors
    func_8003A9C4(); //process_static_actors
    func_8003B7D8(); //call_process_shadows
    func_8003B994(); //process_sprites
  }
  return;
}

extern VECTOR D_801BC0A8;
extern s32 D_801D87F0;
extern s8 D_801D8D14;
extern SVECTOR D_801ADC94; //check type
extern SVECTOR D_801D886C; //check type
extern VECTOR D_80206B58;
extern SVECTOR D_8021D95C;
extern SVECTOR D_80206B34;
extern void func_80031F0C(SVECTOR*, SVECTOR*, SVECTOR*, SVECTOR*);

//draw_actors
INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003A2EC);
// void func_8003A2EC(Actor* actor){
//     s32 cull;
//     SVECTOR svec;
//     s32 z;

//     cull = func_80038CF8(actor->svecPosition.vx, actor->svecPosition.vz);
//     if(cull){
//         return;
//     }

//     SetRotMatrix(&D_801D4760);
//     memcpy(&D_801D4760, &D_80206B58, sizeof(VECTOR));
//     memcpy(&D_8021D95C, &actor->svecPosition, sizeof(SVECTOR));
//     func_80031F0C(&D_8021D95C, &D_80206B34, &D_801ADC94, &D_801D886C);
//     memcpy(&svec, &D_80206B34, 4);

//     z = D_801BC0A8.vz / 4;

//     //rework?
//     actor->unk6 &= 0x7F; 

//     if((actor->state & 64) == 0 || D_801D87F0 <= z){
//         if(D_801D87F0 < z){
//             return;
//         }
//         if(z < 30 >> D_801D8D14){
//             return;
//         }
//         if (svec.vx + 0x160 >= 0x400){
//             return;
//         }
//         if (svec.vy + 0x88 >= 0x400){
//             return;
//         }
//     }

//     actor->unk6 &= 0x80; 

// }

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003A7CC);
extern UnkStruct_D_801BC3BC D_801BC3A0;
//process_actor_arrays
void func_8003A7CC(void) {
    BossActor* bossActor;
    Actor* actor;
    s32 arraySize;
    u32 i;

    if (D_802049AC == 0) {

        arraySize = ARRLEN(bossActorArray);
        i = arraySize;
        bossActor = &bossActorArray[arraySize];
        while(i > 0){
            bossActor--;
            i--;
            if (bossActor->state & bossActor->unk6 & 2) {
                func_8003A2EC(bossActor);
            }
        }

        arraySize = ARRLEN(actorArray);
        i = arraySize;
        actor = &actorArray[arraySize];
        while(i > 0){
            actor--;
            i--;
            if (actor->state & actor->unk6 & 2) {
                func_8003A2EC(actor);
            }
        }

        if (D_801BC3A0.unks[7] != 0) {
            bzero(&D_801BC3A0, 0x20);
        }
    }
}


// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003A888);
// process_projectile_actor_arrays
void func_8003A888(void) {
    ProjectileActor *playerProjectile;
    ProjectileActor *enemyProjectile;
    s32 funcIndex;
    u32 i;

    for (i = 0; i < ARRLEN(playerProjectileActorArray); i++) {
        playerProjectile = &playerProjectileActorArray[i];
        funcIndex = playerProjectile->funcIndex;
        if (funcIndex & playerProjectile->unkFlag & 2) {
            D_800AC980[(funcIndex & 0x1C) >> 2](&playerProjectile->unkPtr, funcIndex);
        }
    }

    for (i = 0; i < ARRLEN(enemyProjectileActorArray); i++) {
        enemyProjectile = &enemyProjectileActorArray[i];
        funcIndex = enemyProjectile->funcIndex;
        if (funcIndex & enemyProjectile->unkFlag & 2) {
            D_800AC980[(funcIndex & 0x1C) >> 2](&enemyProjectile->unkPtr, funcIndex);
        }
    }
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003A94C);
//process_effect_actor_array
void func_8003A94C(void) {
    EffectActor *actor;
    s32 funcIndex;
    u32 i;

    for(i = 0; i < ARRLEN(effectActorArray); i++) {
        actor = &effectActorArray[i];
        funcIndex = actor->funcIndex;
        if (funcIndex & actor->unkFlag & 2) {
            D_800AC980[((funcIndex & 0x1C) >> 2)](&actor->unkPtr, funcIndex);
        }
    } ;
}




// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003A9C4);
// Process Static Actor Array
void func_8003A9C4(void) {
    StaticActor* actor;
    s32 index;
    u32 i;

    for(i = 0; i < ARRLEN(staticActorArray); i++) {
        actor = &staticActorArray[i];
        index = actor->funcIndex;
        if ((index & actor->actorState & 2) != 0) {
            D_800AC980[(index & 0x1c) >> 2](&actor->actorModelPtr, index);
        }
    }
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003AA3C);
void func_8003AA3C(UnkArg_func_8003AA3C* arg0, s32 arg1) {
    MATRIX matrix;
    SVECTOR svec;
    VECTOR vec;
    SVECTOR svec2;
    s32 var_v1;

    if (func_80038CF8(arg0->unk8, arg0->unkC) == 0) {
        func_8002C654(&matrix);
        if (arg1 & 32) {
            RotMatrixZ(arg0->unk12 * 64, &matrix);
        }
        if (D_80210B61 != 0) {
            var_v1 = arg0->unk10 << D_80210B61;
        } else {
            var_v1 = arg0->unk10;
        }
        if (var_v1 != 32) {
            vec.vx = vec.vy = vec.vz = var_v1 * 128;
            ScaleMatrix(&matrix, &vec);
        }
        if (D_80210B61 != 0) {
            svec.vx = arg0->unk8 << D_80210B61;
            svec.vy = arg0->unkA << D_80210B61;
            svec.vz = arg0->unkC << D_80210B61;
        } else {
            svec.vx = (u16) arg0->unk8;
            svec.vy = (u16) arg0->unkA;
            svec.vz = (u16) arg0->unkC;
        }
        SetRotMatrix(&D_801D4760);
        SetTransMatrix(&D_801D4760);
        func_80032068(&svec, &matrix.t, &svec2);
        func_80084CF0(arg0, &matrix);
    }
}

//draw_static_actors
INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003AB60);
extern s16 D_8021D9A2;
extern Actor* D_801FF364; //gCurrentActorPtr;
extern s32 func_80081778(Actor*);
extern void func_800817BC(s8, s8, s16, MATRIX*, Actor*, u16, u8, u8);
extern s16 D_800AC99C[16]; //RGBA related
// void func_8003AB60(StaticActor* actor, s32 arg1){
//     s32 cull;
//     SVECTOR svec;
//     VECTOR vec;
//     MATRIX modelView;
//     s32 z;
//     s32 lod;
//     s32 var2;
//     s32 bufferIndex;
//     s32 rgba16;
//     s32 rgba32;
//     s16 iVar5;

//     if ((actor->unk2C & 0xffffffU) == 0) {
//         return;
//     }

//     cull = func_80038CF8(actor->rotation.vx, actor->rotation.vz);

//     if (cull) {
//         return;
//     }

//     SetRotMatrix(&D_801D4760);
//     memcpy(&D_801D4760, &D_80206B58, sizeof(VECTOR));
//     memcpy(&D_8021D95C, &actor->position, sizeof(SVECTOR));
//     func_80031F0C(&D_8021D95C, &D_80206B34, &D_801ADC94, &D_801D886C);
//     memcpy(&svec, &D_80206B34, 4);

//     z = D_801BC0A8.vz / 4;

//     //rework?

//     if((arg1 & 64) == 0 || D_801D87F0 <= z){
//         if(D_801D87F0 < z){
//             return;
//         }
//         if(z < 30 >> D_801D8D14){
//             return;
//         }
//         if (svec.vx + 0x160 >= 0x400){
//             return;
//         }
//         if (svec.vy + 0x88 >= 0x400){
//             return;
//         }
//     }

//     memcpy(&svec,&actor->rotation,8);
//     memcpy(&modelView,&actor->matrix,0x20);
//     if (D_80210B61 != 0) {
//         svec.vx = (svec.vx << (D_80210B61 & 0x1f));
//         svec.vy = (svec.vy << (D_80210B61 & 0x1f));
//         svec.vz = (svec.vz << (D_80210B61 & 0x1f));
//         modelView.m[0][0] = modelView.m[0][0] << (D_80210B61 & 0x1f);
//         modelView.m[0][1] = modelView.m[0][1] << (D_80210B61 & 0x1f);
//         modelView.m[0][2] = modelView.m[0][2] << (D_80210B61 & 0x1f);
//         modelView.m[1][0] = modelView.m[1][0] << (D_80210B61 & 0x1f);
//         modelView.m[1][1] = modelView.m[1][1] << (D_80210B61 & 0x1f);
//         modelView.m[1][2] = modelView.m[1][2] << (D_80210B61 & 0x1f);
//         modelView.m[2][0] = modelView.m[2][0] << (D_80210B61 & 0x1f);
//         modelView.m[2][1] = modelView.m[2][1] << (D_80210B61 & 0x1f);
//         modelView.m[2][2] = modelView.m[2][2] << (D_80210B61 & 0x1f);
//     }

//     if(z <= 700){
//         lod = 0;
//     } else if (z <= 1800){
//         lod = 1;
//     } else if((D_8021D9A2 & 8) == 0){
//         lod = 2;
//     }

//     D_801FF364 = actor;
//     actor->unkF = lod;

//     if((actor->unk2C & 0x20000000) == 0){
//         actor->unkE = 0;
//         var2 = func_80081778(&D_801FF364);

//         if(var2 == 0) {
//             bufferIndex = 8;
//         } else {
//             bufferIndex = 6;
//         }
        
//     } else {
//         actor->unkE = 1;
//         bufferIndex = 8;
//     }

//     rgba16 = 0x4210;

//     //Something RGBA related
//     if (actor->unkE == 0) {
//         rgba32 = actor->unk2C;
//         if (rgba32 & 0x00FFFFFF == 0x00808080) {
//             if (actor->unk36 != 0) {
//                 rgba16 = actor->unk36;
//                 actor->unk36 = 0;
//             }
//         }
//         else {
//             rgba16 = (rgba32 & 0xFF) >> 3 | rgba32 >> 6 & 0x3E0 | rgba32 >> 9 & 0x7C00;
//         }
//     }
//     else {
//         rgba32 = actor->unk2C;
//         rgba32 = ((rgba32 & 0xFF) + (rgba32 >> 8 & 0xFF) + (rgba32 >> 16 & 0xFF)) / 3;
//         iVar5 = rgba32 + D_800AC99C[rgba32 / 16];

//         // Clamp?
//         if (0xFF < iVar5) {
//             actor->unkD = 0xF8;
//         }
//         actor->unkD = iVar5;
//     }

//     MulMatrix(&D_801D4760, &modelView, &D_80210990);
//     ApplyMatrix(&D_801D4760, &svec, &vec);
//     D_801D4760.t[0] += vec.vx;
//     D_801D4760.t[1] += vec.vy;
//     D_801D4760.t[2] += vec.vz;
//     SetRotMatrix(&D_80210990);
//     SetTransMatrix(&D_80210990);
//     func_800283A8(0, bufferIndex, &func_8008128C, 0);
//     func_800817BC(0, bufferIndex, actor->rotation.pad, &D_80210990, &D_801FF364, rgba16, actor->unk34, actor->unk35);
// }

//draw_drop_actors (consider renaming)
INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003AFB0);

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003B27C);
void func_8003B27C(void* actor, s32 arg1) {
    func_8003AFB0(actor, arg1);
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003B298);
void func_8003B298(void* actor, s32 arg1) {
    func_8003AFB0(actor, arg1);
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003B2B4);
//push_player_shadow
void func_8003B2B4(PlayerActor* player, s32 arg1, s32 arg2, s32 arg3) {
    u32 i;
    s32 y;

    i = D_801A9064;
    if (i < 64) {
        shadowArray[i].x = player->svecPosition.vx;
        
        if (player->unk76 != 0) {
            y = player->svecPosition.vy;
            shadowArray[i].y = y;
        } else {
            y = func_8003E934(player);
            shadowArray[i].y = y;
        }
        
        shadowArray[i].z = player->svecPosition.vz;
        shadowArray[i].rotation = (( player->rotVec.vy -  player->unk116) & 0xFFF) | ((arg2 >> 6) << 0xC);
        shadowArray[i].size = arg1 | (arg3 << 0xE);
        shadowArray[i].opacity = y - player->svecPosition.vy;
        shadowArray[i].xOffset = 0;
        shadowArray[i].yOffset = -3;
        shadowArray[i].zOffset = 0;
        
        D_801A9064++;
    }
}

//push_cutscene_shadows?
INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003B3F8);

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003B564);
// push_actor_shadow
void func_8003B564(Actor* actor, s32 arg1, s32 arg2, s32 arg3) {
    ShadowUnkStruct* shadow;
    s32 y;
    s32 yOffset;
    u32 i;
    
    i = D_801A9064;
    yOffset = -3;
    
    if (i < 64U) {
        shadowArray[i].x = actor->svecPosition.vx;

        if (actor->unk76 != 0) {
            y = actor->svecPosition.vy;
            shadowArray[i].y = y;
        } else {
            y = func_8003E934(actor);
            if (y < actor->svecPosition.vy) {
                y = actor->svecPosition.vy;
            }
            shadowArray[i].y = y;
        }

        shadowArray[i].z = actor->svecPosition.vz;
        shadowArray[i].rotation = (actor->rotVec.vy & 0xFFF) | ((arg2 >> 6) << 0xC);
        shadowArray[i].size = arg1 | (arg3 << 0xE);
        shadowArray[i].opacity = y - actor->svecPosition.vy;
        shadowArray[i].xOffset = 0;
        shadowArray[i].yOffset = yOffset;
        shadowArray[i].zOffset = 0;

        D_801A9064++;
    }
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003B6B8);
//Likely just the vector for the actor is being passed, not the actor pointer itself
//BossActor?
void func_8003B6B8(SVECTOR* actorVec, s32 arg1, s32 arg2, s32 arg3) {
    s16 y;
    u32 i;

    i = D_801A9064;
    if (i < 64) {
        shadowArray[i].x = actorVec->vx;
        y = func_8003E964(actorVec, 0, 0, 0xFFFF);
        shadowArray[i].y = y;
        shadowArray[i].z = actorVec->vz;
        shadowArray[i].rotation = (arg3 & 0xFFF) | ((arg2 >> 6) << 0xC);
        shadowArray[i].size = arg1 | (actorVec->pad << 0xE);
        shadowArray[i].opacity = y - actorVec->vy;
        shadowArray[i].xOffset = 0;
        shadowArray[i].yOffset = -3;
        shadowArray[i].zOffset = 0;

        D_801A9064++;
    }
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003B7D8);
s32 func_8003B7D8(){
    return func_800893E4(); //process_shadows
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003B7F4);
extern s8 D_80203FFC;
extern s16 D_801ADC80;
void func_8003B7F4(){
    D_801A9064 = 0;
    D_80203FFC = 0;
    D_801ADC80 = 0;
}

void func_8003B810(void) {
}

void func_8003B818(void) {
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003B820);
s32 func_8003B820(s32 arg0) {
    return arg0;
}

void func_8003B828(void) {
}

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003B830);
s32 func_8003B830(s32 arg0) {
    return arg0;
}

void func_8003B838(void) {
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003B840);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003B85C);

//alloc_sprite
INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003B878);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003B8FC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003B994);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003BA58);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003BB80);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_26", func_8003BC68);
