#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

#include "globals.h"

/*

PushS 9088
GlobalVar
RefGet

*/

uint soundID = 2;

void Init(void)
{
	Vector3 vStartCoords;
	vStartCoords.x = 869.58590000;
	vStartCoords.y = -121.03340000;
	vStartCoords.z = 6.00050000;

	Blip blipgarage, blipgarage2;
	ADD_BLIP_FOR_COORD(vStartCoords.x, vStartCoords.y, vStartCoords.z, &blipgarage);
	CHANGE_BLIP_DISPLAY(blipgarage, 2);
	CHANGE_BLIP_SPRITE(blipgarage, 79);
	CHANGE_BLIP_NAME_FROM_ASCII(blipgarage, "Garage Mod Shop");
	FLASH_BLIP(blipgarage, true);

	ADD_BLIP_FOR_COORD(1775.6616, 836.8135, 16.2557, &blipgarage2);
	CHANGE_BLIP_DISPLAY(blipgarage2, 2);
	CHANGE_BLIP_SPRITE(blipgarage2, 79);
	CHANGE_BLIP_NAME_FROM_ASCII(blipgarage2, "Garage Mod Shop");
	FLASH_BLIP(blipgarage2, true);

	WAIT(5500);

	FLASH_BLIP(blipgarage, false);
	CHANGE_BLIP_PRIORITY(blipgarage, 0);
	SET_BLIP_AS_SHORT_RANGE(blipgarage, true);

	FLASH_BLIP(blipgarage2, false);
	CHANGE_BLIP_PRIORITY(blipgarage2, 0);
	SET_BLIP_AS_SHORT_RANGE(blipgarage2, true);
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

	// Brucie Garage cylinder
	DRAW_COLOURED_CYLINDER(869.01190000, -114.65010000, 6.00540000 - 1, 0.80000000, 0.20000000, 0, 132, 202, 255);
	if (LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), 869.01190000, -114.65010000, 6.00540000, 0.80000000, 0.80000000, 2.00000000, 0))
	{
		if (IS_CHAR_ON_FOOT(GetPlayerPed()))
		{
			G_activateMenu = true;
			G_garageId = 1;
		}
	}
	//else
	//{
	//	G_activateMenu = false;
	//}
	
	// Meadows park (1st island)
	DRAW_COLOURED_CYLINDER(1775.6616, 836.8135, 16.2557 - 1, 0.80000000, 0.20000000, 0, 132, 202, 255);
	if (LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), 1775.6616, 836.8135, 16.2557, 0.80000000, 0.80000000, 2.00000000, 0))
	{
			G_activateMenu = true;
			G_garageId = 2;
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

/* Meadows park (1st island)
// MAIN
	garage.main.spawn.x = 1775.6616;
	garage.main.spawn.y = 836.8135;
	garage.main.spawn.z = 16.2557;
	garage.main.spawn.h = 344.5343;

	garage.main.exit.x = garage.main.spawn.x;
	garage.main.exit.y = garage.main.spawn.y;
	garage.main.exit.z = garage.main.spawn.z;
	garage.main.exit.h = garage.main.spawn.h;

	garage.main.quit.x = garage.main.spawn.x;
	garage.main.quit.y = garage.main.spawn.y;
	garage.main.quit.z = garage.main.spawn.z;
	garage.main.quit.h = garage.main.spawn.h;

// Big
	garage.big.spawn.x = 1780.5695;
	garage.big.spawn.y = 853.7727;
	garage.big.spawn.z = 16.2572;
	garage.big.spawn.h = 77.0736;

	garage.big.exit.x = garage.big.spawn.x;
	garage.big.exit.y = garage.big.spawn.y;
	garage.big.exit.z = garage.big.spawn.z;
	garage.big.exit.h = garage.big.spawn.h;

	garage.big.quit.x = garage.big.spawn.x;
	garage.big.quit.y = garage.big.spawn.y;
	garage.big.quit.z = garage.big.spawn.z;
	garage.big.quit.h = garage.big.spawn.h;
	
// HELI
	garage.heli.spawn.x = 1774.4158;
	garage.heli.spawn.y = 837.0033;
	garage.heli.spawn.z = 22.9287;
	garage.heli.spawn.h = 73.8474;

	garage.heli.exit.x = garage.heli.spawn.x;
	garage.heli.exit.y = garage.heli.spawn.y;
	garage.heli.exit.z = garage.heli.spawn.z;
	garage.heli.exit.h = garage.heli.spawn.h;

	garage.heli.quit.x = garage.heli.spawn.x;
	garage.heli.quit.y = garage.heli.spawn.y;
	garage.heli.quit.z = garage.heli.spawn.z;
	garage.heli.quit.h = garage.heli.spawn.h;

*/

/* Brucie Garage
// MAIN
	garage.main.exit.x = 869.0119;
	garage.main.exit.y = -114.6501;
	garage.main.exit.z = 5.5054;
	garage.main.exit.h = 270.0000;

	garage.main.quit.x = 866.3309;
	garage.main.quit.y = -116.7025;
	garage.main.quit.z = 6.0054;
	garage.main.quit.h = 181.0000;

	garage.main.spawn.x = 874.8120;
	garage.main.spawn.y = -114.2031;
	garage.main.spawn.z = 5.6122;
	garage.main.spawn.h = 180.0000;

// BIG
	garage.big.exit.x = 799.8708;
	garage.big.exit.y = -161.9819;
	garage.big.exit.z = 6.1214;
	garage.big.exit.h = 291.4525;

	garage.big.quit.x = 799.8708;
	garage.big.quit.y = -161.9819;
	garage.big.quit.z = 6.1214;
	garage.big.quit.h = 291.4525;

	garage.big.spawn.x = 807.7111;
	garage.big.spawn.y = -161.0524;
	garage.big.spawn.z = 6.4449;
	garage.big.spawn.h = 335.8888;

// HELI
	garage.heli.exit.x = 869.0119;
	garage.heli.exit.y = -114.6501;
	garage.heli.exit.z = 5.5054;
	garage.heli.exit.h = 270.0000;

	garage.heli.quit.x = 866.3309;
	garage.heli.quit.y = -116.7025;
	garage.heli.quit.z = 6.0054;
	garage.heli.quit.h = 181.0000;

	garage.heli.spawn.x = 874.8120;
	garage.heli.spawn.y = -114.2031;
	garage.heli.spawn.z = 5.6122;
	garage.heli.spawn.h = 180.0000;
*/
	while(true)
	{
		WAIT(0);
		if (G_activateMenu)
		{
			HIDE_HUD_AND_RADAR_THIS_FRAME();
			if (!G_scriptloaded)
			{
				if ((GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT("garage_menu")) >= 1)
				{
					G_scriptloaded = true;
				}
				else
				{
					REQUEST_SCRIPT("garage_menu");
					while (!HAS_SCRIPT_LOADED("garage_menu"))
					{
						REQUEST_SCRIPT("garage_menu");
						WAIT(0);
					}
					START_NEW_SCRIPT("garage_menu", 1024);
					//START_NEW_SCRIPT_WITH_ARGS("garage_menu", &G_testarg, 1, 1024);
					MARK_SCRIPT_AS_NO_LONGER_NEEDED("garage_menu");
					G_scriptloaded = true;
				}
			}
		}
		DoActivators();
	}
}
