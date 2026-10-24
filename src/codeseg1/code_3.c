#include "common.h"
#include "viint.h"

#define ALIGN8(val) (((val) + 7) & ~7)
#define ALIGN16(val) (((val) + 0xF) & ~0xF)
#define ALIGN32(val) (((val) + 0x1F) & ~0x1F)
#define ALIGN64(val) (((val) + 0x3F) & ~0x3F)
#define ALIGN256(val) (((val) + 0xFF) & ~0xFF)

typedef struct GfxTaskNode {
    void* next; // GfxTaskNode
    void* prev; // GfxTaskNode
    void* callbackFunc;
    void* callbackArg;
    s8 poolIndex;
    s8 unk11_pad;
    s16 unk12;
    s32 unk14;
} GfxTaskNode;

// Data
extern s32 D_800A6CA8;

// Rodata

// BSS
void* D_800D6FA8; // sTaskPoolHead
void* D_800D6FAC; // sTaskPoolEnd

// Externs
extern void process_rumble(); // process_rumble

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", Main_ThreadEntry);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80026A30);
// void func_80026A30(u32 gfxTaskNum){

// }

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80026B9C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", PadMgr_ThreadEntry);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80026C80);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_800270F8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002724C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80027334);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", Overlay_Loader);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80027490);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002753C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80027550);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_800276EC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_800281BC);

// INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_800281C8);
// gfx_task_pool_alloc
void* gfx_task_pool_alloc(u32 size) {
    void* allocPtr;
    void* nextHead;

    if (D_800A6CA8 > 1) {
        return NULL;
    }

    size = ALIGN8(size);
    nextHead = D_800D6FA8 + size;

    if (nextHead <= D_800D6FAC) {
        allocPtr = D_800D6FA8;
        D_800D6FA8 = nextHead;
    } else {
        allocPtr = NULL;
    }

    return allocPtr;
}

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028220);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_800283A8);
// void func_800283A8_37A8(s8 bufferIndex, s8 arenaIndex, void* func, void* funcArg) {
//     GfxTaskNode* arenaNode;
//     GfxTaskNode* head;
//     GfxTaskNode* arenaBody;
//     GfxContext* gfxContext;
//     GfxContext* temp_t1;

//     temp_t1 = &D_802047F0[bufferIndex];

//     if (temp_t1->bufferEnabled != 0) {
//         arenaNode = NULL;
//         // Check if Additional Scanlines < 2
//         if (D_800A6CA8 < 2) {
//             head = D_800D6FA8;
//             arenaNode = (GfxTaskNode*)((char*)head + 0x18);
//             if ((u32)D_800D6FAC < (u32)arenaNode) {
//                 arenaNode = NULL;
//             } else {
//                 D_800D6FA8 = arenaNode;
//                 arenaNode = head;
//             }
//         }
//         if (arenaNode != NULL) {
//             gfxContext = (GfxContext*)((arenaIndex << 2) + (char*) temp_t1);
//             arenaBody = (GfxTaskNode*)&arenaNode->body;
//             arenaNode->next = NULL;
//             arenaNode->prev = NULL;
//             arenaBody->func = func;
//             arenaBody->arenaIndex = arenaIndex;
//             arenaBody->arg = funcArg;
//             arenaBody->unk12 = 0;
//             if (gfxContext->arenaNext[0] != NULL) {
//                 arenaNode->prev = gfxContext->arenaNext[0];
//                 gfxContext->arenaNext[0]->next = arenaNode;
//             } else {
//                 gfxContext->arenaStart[0] = arenaNode;
//             }
//             gfxContext->arenaNext[0] = arenaNode;
//         }
//     }
// }

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028470);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028600);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028660);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_800286A8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028794);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_800287CC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028850);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028888);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_800288D8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002891C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002894C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028978);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_800289A8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_800289D4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028A00);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028A3C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028A4C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028A58);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028B28);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028BF0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028C14);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028C90);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028CB0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028CFC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028D30);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028DE0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028E40);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028EAC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80028F58);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_800290C8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80029114);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_800291B8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80029250);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_800292E8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80029394);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80029400);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_800294F0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80029554);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80029884);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80029C04);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80029C7C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80029CF4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80029D9C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80029E48);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80029F00);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_80029F1C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A02C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A110);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A1C4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A290);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A2AC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A2F8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A33C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A398);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A3B4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A3F0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A46C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A488);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A4A4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A4C0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A514);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A584);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A5A8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A5F8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A634);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A670);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A6A0);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A6D8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A710);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A7AC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A8E0);

INCLUDE_RODATA("asm/nonmatchings/codeseg1/code_3", D_800D1C60);

INCLUDE_RODATA("asm/nonmatchings/codeseg1/code_3", D_800D1C84);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002A994);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002AB8C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002AC34);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002AD74);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002B038);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002B138);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002B1D4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002B274);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002B29C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002B2C8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002B3C4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002B9F8);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002BA1C);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002BB34);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002BBBC);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002BC54);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002BE78);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002BE98);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002BEC4);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002BF14);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002BF38);

INCLUDE_ASM("asm/nonmatchings/codeseg1/code_3", func_8002BFFC);
