#ifndef OVERLAY_H
#define OVERLAY_H

#include "common.h"

typedef struct OverlayTable {
/* 0x00 */ u8* romStart;
/* 0x04 */ u8* romEnd;
/* 0x08 */ u8* vramStart;
/* 0x0C */ u8* textVramStart;
/* 0x10 */ u8* textVramEnd;
/* 0x14 */ u8* dataVramStart;
/* 0x18 */ u8* dataVramEnd;
/* 0x1C */ u8* bssVramStart;
/* 0x20 */ u8* bssVramEnd;
} OverlayTable; //sizeof 0x24

typedef enum {
  #define OVL_DEFINE(name)  name,
    #include "ovl_table.h"
  #undef OVL_DEFINE

    OVL_COUNT
} OverlayID;

extern OverlayTable _ovltbl[OVL_COUNT];

extern Addr name_20_ROM_START;
extern Addr name_20_ROM_END;
extern Addr name_20_VRAM;
extern Addr name_20_TEXT_START;
extern Addr name_20_TEXT_END;
extern Addr name_20_DATA_START;
extern Addr name_20_RODATA_END;
extern Addr name_20_BSS_START;
extern Addr name_20_BSS_END;

extern Addr name_21_ROM_START;
extern Addr name_21_ROM_END;
extern Addr name_21_VRAM;
extern Addr name_21_TEXT_START;
extern Addr name_21_TEXT_END;
extern Addr name_21_DATA_START;
extern Addr name_21_RODATA_END;
extern Addr name_21_BSS_START;
extern Addr name_21_BSS_END;

#endif // OVERLAY_H