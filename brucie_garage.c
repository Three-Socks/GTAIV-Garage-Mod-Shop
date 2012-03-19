#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

#include "globals.h"
#include "Locals.c"
#include "Functions.c"

/*

PushS 9088
GlobalVar
RefGet

*/

void Init(void)
{
	Vector3 vStartCoords;
	vStartCoords.x = 869.58590000;
	vStartCoords.y = -121.03340000;
	vStartCoords.z = 6.00050000;

	Blip blipgarage;
	ADD_BLIP_FOR_COORD(vStartCoords.x, vStartCoords.y, vStartCoords.z, &blipgarage);
	CHANGE_BLIP_DISPLAY(blipgarage, 2);
	CHANGE_BLIP_SPRITE(blipgarage, 79);
	CHANGE_BLIP_NAME_FROM_ASCII(blipgarage, "Garage Mod Shop");
	FLASH_BLIP(blipgarage, true);
	WAIT(5500);
	FLASH_BLIP(blipgarage, false);
	CHANGE_BLIP_PRIORITY(blipgarage, 0);
	SET_BLIP_AS_SHORT_RANGE(blipgarage, true);
}

void DoActivators(void)
{
	Object garage_object = 0x123;

	Vector3 upGarageCoords, downGarageCoords, currentGarageCoords, currentCharCoords;
	upGarageCoords.x = 864.32000000;
	upGarageCoords.y = -121.64500000;
	upGarageCoords.z = 12.00000000;

	downGarageCoords.x = 864.32000000;
	downGarageCoords.y = -121.64500000;
	downGarageCoords.z = 7.40000000;

	if (DOES_OBJECT_EXIST(garage_object))
	{
		if ((LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), 874.04070000, -111.15070000, 5.00040000, 9.60000000, 14.60000000, 4.00000000, 0)) || (LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), 861.12460000, -122.48690000, 5.93060000, 8.00000000, 8.00000000, 3.00000000, 0)))
		{
			GET_OBJECT_COORDINATES(garage_object, &currentGarageCoords.x, &currentGarageCoords.y, &currentGarageCoords.z);
			if (currentGarageCoords.z < upGarageCoords.z)
			{
				if (soundID == 2)
				{
					soundID = GET_SOUND_ID();
					PLAY_SOUND_FROM_OBJECT(soundID, "GARAGE_DOOR_BIG", garage_object);
				}
				if (SLIDE_OBJECT(garage_object, upGarageCoords.x, upGarageCoords.y, upGarageCoords.z, 0.00000000, 0.00000000, 0.07500000, 0))
				{
					if (soundID != 2)
					{
						STOP_SOUND(soundID);
						RELEASE_SOUND_ID(soundID);
						soundID = 2;
					}
				}
			}
		}
		else
		{
			if (soundID == 2)
			{
				soundID = GET_SOUND_ID();
				PLAY_SOUND_FROM_OBJECT(soundID, "GARAGE_DOOR_BIG", garage_object);
			}
			if (SLIDE_OBJECT(garage_object, downGarageCoords.x, downGarageCoords.y, downGarageCoords.z, 0.00000000, 0.00000000, 0.07500000, 0))
			{
				if (soundID != 2)
				{
					STOP_SOUND(soundID);
					RELEASE_SOUND_ID(soundID);
					soundID = 2;
				}
			}
		}
	}

	// Draw Garage cylinder
	DRAW_COLOURED_CYLINDER(869.01190000, -114.65010000, 6.00540000 - 1, 0.80000000, 0.20000000, 0, 132, 202, 255);
	if (LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), 869.01190000, -114.65010000, 6.00540000, 0.80000000, 0.80000000, 2.00000000, 0))
	{
		if (IS_CHAR_ON_FOOT(GetPlayerPed()))
		{
			G_activateMenu = true;
		}
	}

	// Brucie Heli pad down
	float helidown_x = 791.26930000, helidown_y = 126.93620000, helidown_z = 6.04020000;
	DRAW_COLOURED_CYLINDER(776.21300000, 153.28020000, 27.57500000 - 2, 0.80000000, 0.20000000, 0, 132, 202, 255);
	if (LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), 776.21300000, 153.28020000, 27.57500000, 0.80000000, 0.80000000, 2.00000000, 0 ))
	{
		if (IS_CHAR_ON_FOOT(GetPlayerPed()))
		{
			SET_CHAR_COORDINATES_NO_OFFSET(GetPlayerPed(), helidown_x, helidown_y, helidown_z);
			SET_CHAR_HEADING(GetPlayerPed(), 105.0);
			LOAD_SCENE(helidown_x, helidown_y, helidown_z);
			SET_CAM_BEHIND_PED(GetPlayerPed());
		}
	}

	// Brucie Heli pad
	float heliup_x = 778.40660000, heliup_y = 152.24480000, heliup_z = 27.83940000;
	DRAW_COLOURED_CYLINDER(794.39230000, 127.75230000, 6.04550000 - 2, 0.80000000, 0.20000000, 0, 132, 202, 255);
	if (LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), 794.39230000, 127.75230000, 6.04550000, 0.80000000, 0.80000000, 2.00000000, 0 ))
	{
		if (IS_CHAR_ON_FOOT(GetPlayerPed()))
		{
				SET_CHAR_COORDINATES_NO_OFFSET(GetPlayerPed(), heliup_x, heliup_y, heliup_z);
				SET_CHAR_HEADING(GetPlayerPed(), 268.0);
				LOAD_SCENE(heliup_x, heliup_y, heliup_z);
				SET_CAM_BEHIND_PED(GetPlayerPed());
		}
	}

}

void main(void)
{
	Init();
	
	while(true)
	{
		WAIT(0);
		if (G_activateMenu)
		{
			HIDE_HUD_AND_RADAR_THIS_FRAME();
			if (!G_scriptloaded)
			{
				if ((GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT("brucie_garage_menu")) >= 1)
				{
					G_scriptloaded = true;
				}
				else
				{
					REQUEST_SCRIPT("brucie_garage_menu");
					while (!HAS_SCRIPT_LOADED("brucie_garage_menu"))
					{
						REQUEST_SCRIPT("brucie_garage_menu");
						WAIT(0);
					}
					START_NEW_SCRIPT("brucie_garage_menu", 1024);
					MARK_SCRIPT_AS_NO_LONGER_NEEDED("brucie_garage_menu");
					G_scriptloaded = true;
				}
			}
		}
		DoActivators();
	}
}
