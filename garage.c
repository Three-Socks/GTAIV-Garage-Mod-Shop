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


EFLC

PushS 10438
GlobalVar
RefGet

*/

uint soundID = 2;

float garagesBlipCoords_x[7], garagesBlipCoords_y[7], garagesBlipCoords_z[7];

void Init(void)
{
	G_scriptloaded[2398] = false;
	G_scriptloadedpalette[2398] = false;
	G_activateMenu[2398] = false;
	G_justexitmenu[2398] = 0;
	G_doneExitCheck[2398] = false;
	G_drewrect[2398] = false;
	G_garageId[2398] = 0;
	G_item_highlighted[2398] = 0;

	// Brucie Garage
	garagesBlipCoords_x[1] = 869.0119;
	garagesBlipCoords_y[1] = -114.6501;
	garagesBlipCoords_z[1] = 6.0054 - 1;

	// Meadows Park
	garagesBlipCoords_x[2] = 1775.6616;
	garagesBlipCoords_y[2] = 836.8135;
	garagesBlipCoords_z[2] = 16.2557 - 1;

	// bohan
	garagesBlipCoords_x[3] = 307.5034;
	garagesBlipCoords_y[3] = 1877.3126;
	garagesBlipCoords_z[3] = 21.5842 - 1;
		
	// scrapyard
	garagesBlipCoords_x[4] = -502.4153;
	garagesBlipCoords_y[4] = 1740.6450;
	garagesBlipCoords_z[4] = 8.3289 - 1;

	// packie MAIN
	garagesBlipCoords_x[5] = -513.8602;
	garagesBlipCoords_y[5] = 332.2618;
	garagesBlipCoords_z[5] = 6.2173 - 1;

	// showroom MAIN
	garagesBlipCoords_x[6] = -1496.8005;
	garagesBlipCoords_y[6] = 1118.9890;
	garagesBlipCoords_z[6] = 23.2138 - 1;

	int i;
	for (i = 1; i < 7; i++)
	{
		CLEAR_AREA(garagesBlipCoords_x[i], garagesBlipCoords_y[i], garagesBlipCoords_z[i], 3.0000, true);
	
		Blip blipgarage;
		ADD_BLIP_FOR_COORD(garagesBlipCoords_x[i], garagesBlipCoords_y[i], garagesBlipCoords_z[i], &blipgarage);
		CHANGE_BLIP_DISPLAY(blipgarage, 2);
		CHANGE_BLIP_SPRITE(blipgarage, 79);
		CHANGE_BLIP_NAME_FROM_ASCII(blipgarage, "Garage Mod Shop");
		CHANGE_BLIP_PRIORITY(blipgarage, 0);
		SET_BLIP_AS_SHORT_RANGE(blipgarage, true);
	}
	
/*	Vector3 vStartCoords;
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
	SET_BLIP_AS_SHORT_RANGE(blipgarage2, true);*/
}

void DoActivators(void)
{
	int i;
	for (i = 1; i < 7; i++)
	{
		if (G_justexitmenu[2398] == i && !LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), garagesBlipCoords_x[i], garagesBlipCoords_y[i], garagesBlipCoords_z[i], 5.00000000, 5.00000000, 5.00000000, 0))
		{
			G_justexitmenu[2398] = 0;
		}

		if (G_justexitmenu[2398] == 0 && !G_activateMenu[2398])
		{
			DRAW_COLOURED_CYLINDER(garagesBlipCoords_x[i], garagesBlipCoords_y[i], garagesBlipCoords_z[i], 2.50000000, 2.50000000, 0, 132, 202, 255);
			if (LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), garagesBlipCoords_x[i], garagesBlipCoords_y[i], garagesBlipCoords_z[i], 2.50000000, 2.50000000, 4.00000000, 0))
			{
					G_activateMenu[2398] = true;
					G_garageId[2398] = i;
			}
		}
	}

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
	
	char *GenGarage = "PaulMH3";
	// Packie's Garage - used in "Harboring a Grudge"
	if (IS_GARAGE_CLOSED(GenGarage) && LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), -513.50000000, 332.00000000, 7.00000000, 35.00000000, 35.00000000, 10.00000000, 0))
	{
		SET_GARAGE_LEAVE_CAMERA_ALONE(GenGarage, 1);
		OPEN_GARAGE(GenGarage);
	}
	else
	{
		CLOSE_GARAGE(GenGarage);
	}

}

void main(void)
{
	Init();

	while(true)
	{
		WAIT(0);
		if (G_activateMenu[2398])
		{
			if (!G_drewrect[2398])
			{
				DRAW_RECT(0.15000000, 0.35000000, 0.23000000, 0.63000000, 0, 0, 0, 230);
			}
			HIDE_HUD_AND_RADAR_THIS_FRAME();
			if (!G_scriptloaded[2398])
			{
				if ((GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT("garage_menu")) >= 1)
				{
					G_scriptloaded[2398] = true;
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
					G_scriptloaded[2398] = true;
				}
			}
		}
		DoActivators();
	}
}
