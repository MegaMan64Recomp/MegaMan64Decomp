#include "n_synthInternals.h"


ALFxRef n_alReverbSetType(s16 bus, ALFxId fxid, s32 rate)
{
  n_syn->mainBus->filter.handler = (N_ALCmdHandler)n_alFxPull;
  return( n_syn->auxBus->fx_array[bus] );
}

void n_alSynSetFXtype(s16 bus, ALFxId fxid, s32 rate)
{
    n_syn->auxBus->fx = n_alReverbSetType(bus, fxid, rate);
}

