#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

#include "gmssl.h"
#include "globals.h"

void main(void)
{
	THIS_SCRIPT_IS_SAFE_FOR_NETWORK_GAME();
	while(true)
	{
		WAIT(0);
		if (IS_BUTTON_PRESSED(0, 6) && IS_BUTTON_PRESSED(0, 8))
		{
			if (!G_activateMenu[23])
			{
				G_activateMenu[23] = true;
				G_garageId[23] = 0;
			}
		}
	}
}