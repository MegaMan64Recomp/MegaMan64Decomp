#include "n_synthInternals.h"


void n_alSynSetFXParam(ALFxRef fx, s16 paramID, void *param)
{
    ALFx *f = (ALFx *)fx;
    
   n_alFxParamHdl(f, (s32)paramID, param);
}

