#ifndef _MACROS_H_
#define _MACROS_H_

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240

#define ALIGNED(x) __attribute__((aligned(x)))

#define ARRLEN(x) ((s32)(sizeof(x) / sizeof(x[0])))

#define STUBBED_PRINTF(x) ((void)(x))

#define UNUSED __attribute__((unused))

#ifndef __GNUC__
#define __attribute__(x)
#endif

#endif //_MACROS_H_