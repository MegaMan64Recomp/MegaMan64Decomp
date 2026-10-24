#include "common.h"
#include "nusys.h"

// Data
u8 shouldRumble = 0;

// BSS
u8 rmbContNum;
s16 rmbFreq;
s16 rmbFrame;
s32 rmbPakStatus;

s32 rumble_status() {
    rmbPakStatus = nuContRmbCheck(0);
    if (rmbPakStatus == 0) {
        nuContRmbModeSet(0, NU_CONT_RMB_MODE_AUTORUN);
        stop_rumble();
    }
    return rmbPakStatus;
}

void do_rumble(u32 contNum, u16 freq, u16 frame) {
    if (rmbPakStatus == 0) {
        rmbContNum = contNum;
        rmbFreq = freq;
        rmbFrame = frame;
        shouldRumble = 1;
    }
}

void process_rumble() {
    if (rmbPakStatus == 0) {
        if (shouldRumble != FALSE) {
            nuContRmbStart(rmbContNum, rmbFreq, rmbFrame);
        }
        shouldRumble = FALSE;
    }
    return;
}

//These two stop_rumble funcs appear to be completely identical, but are used in different locations
void stop_rumble2(){
    if(rmbPakStatus == 0) {
        nuContRmbForceStop();
        nuContRmbForceStopEnd();
    }
}

void stop_rumble(){
    if(rmbPakStatus == 0){
        nuContRmbForceStop();
        nuContRmbForceStopEnd();
    }
}
