#include "n_synthInternals.h"

ALFxRef n_alSynGetFXRef(s16 bus, s16 index)
{
    N_ALMainBus     *m = n_syn->mainBus;

    if( m->filter.handler == (N_ALCmdHandler)n_alFxPull )
	return (ALFxRef)(n_syn->auxBus->fx);
    else
	return 0;
}

