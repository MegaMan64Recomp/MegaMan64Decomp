#include <os_internal.h>
#include "n_synthInternals.h"

void n_alSynRemovePlayer(ALPlayer *client)
{
    ALPlayer *thing;
    ALPlayer *prev = 0;

    if (n_syn->head != 0)
    {
	OSIntMask mask = osSetIntMask(OS_IM_NONE);

        for (thing = n_syn->head; thing != 0; thing = thing->next) {
            if (thing == client) {
		if(prev)
		    prev->next = thing->next;
		else
		    n_syn->head = thing->next;

                client->next = 0;
		break;
            }
	    prev = thing;
        }

	osSetIntMask(mask);
    }
}

