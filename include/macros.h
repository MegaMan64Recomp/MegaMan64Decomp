#ifndef MACROS_H
#define MACROS_H

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240

#define ALIGNED(x) __attribute__((aligned(x)))

#define ARRLEN(x) ((s32)(sizeof(x) / sizeof(x[0])))

//User Defined
#define ARRAY_END(arr) ((u32*)(arr + ARRLEN(arr)) - 1)
//End User Defined

#define STUBBED_PRINTF(x) ((void)(x))

#define UNUSED __attribute__((unused))

#ifndef __GNUC__
#define __attribute__(x)
#endif

#endif