#ifndef _COMMON_H_
#define _COMMON_H_

#include "ultra64.h"
#include "types.h"
#include "include_asm.h"
#include "ld_addrs.h"
#include "macros.h"

#define true 1
#define false 0
#define bool s32


void memcpy(void*, void*, s32); // TODO this shouldn't need to be declared here

// TODO migrate struct defs
// PSX Defs
typedef struct {
    s16 m[3][3];
    s32 t[3];
} MATRIX;

typedef struct {
    s32 vx, vy;
    s32 vz, pad;
} VECTOR;

typedef struct {
    s16 vx, vy;
    s16 vz, pad;
} SVECTOR;

#define FIXED(a) ((a) >> 12)

// UI
typedef union {
    struct {
        u8 r, g, b, a;
    } c;
    u32 rgba32;
} RGBA32;

typedef struct {
    s16 x, y;
} Vec2s;

typedef struct {
    RGBA32 rgba;
    Vec2s v;
} ColoredVert;

typedef struct {
    void* ptr;
    ColoredVert verts[4];
} UIElemQuad;

typedef union {
    struct {
        u32 prev : 24;
        u32 flag : 8;
    } bitfield;
    u32 header;
} UIStackHeader;

typedef struct {
    UIStackHeader header;
    RGBA32 rgba;
    void* data;
} UiElementGeneric;

#endif
