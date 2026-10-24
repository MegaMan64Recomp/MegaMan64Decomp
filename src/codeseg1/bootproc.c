#include "common.h"

// externs
extern u8 shouldRumble;
extern u32 D_800A6DB0;

INCLUDE_ASM("asm/nonmatchings/codeseg1/bootproc", bootproc);
// void bootproc() {
//     int rmbStatus;

//     shouldRumble = FALSE;
//     D_800A6DB0 = 0;
//     osUnmapTLBAll();
//     Main_ClearMemory();
//     init_dma_mgr();
//     overlay_loader(0xae8d0, 0xb6040, 0xffffffff8021d9d0, 0xffffffff8021d9d0, 0x8021de70, 0x8021de70, &DAT_80225140,
//                    &DAT_80225140, 0x80225150);
//     FUN_80026100(0xffffffff80028c90, 0, 0, 4);
//     init_controller();
//     init_audio();
//     load_text_glyphs();
//     nuPreNMIFuncSet((NUScPreNMIFunc*)FUN_80026b9c);
//     rmbStatus = rumble_status();
//     if (rmbStatus == 0) {
//         nuContRmbModeSet(0, NU_CONT_RMB_MODE_AUTORUN);
//     }
//     init_graphics(retrace_func);

//     do {
//     } while (true);
// }

INCLUDE_ASM("asm/nonmatchings/codeseg1/bootproc", func_8008A02C);
