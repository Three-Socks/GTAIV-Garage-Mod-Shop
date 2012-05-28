#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

#include "gmssl.h"
#include "globals.h"

/*

PS3 GTAIV
PushS 9088
GlobalVar
RefGet

PC GTAIV
PushS 9167
GlobalVar
RefGet

TLAD

PushS 10374
GlobalVar
RefGet

TBoGT

PushS 10438
GlobalVar
RefGet

*/

uint soundID = 2;

float garagesBlipCoords_x[8], garagesBlipCoords_y[8], garagesBlipCoords_z[8];

void Init(void)
{
	THIS_SCRIPT_IS_SAFE_FOR_NETWORK_GAME();

	G_scriptloaded[23] = false;
	G_scriptloadedpalette[23] = false;
	G_activateMenu[23] = false;
	G_justexitmenu[23] = 0;
	G_doneExitCheck[23] = false;
	G_drewrect[23] = false;
	G_inVNeonCol[23] = false;
	G_garageId[23] = 0;
	G_item_highlighted[23] = 0;
	G_v_domod[99] = 0;

	G_drawVNeon[99].toggle = 0;
	G_drawVNeon[99].togglefb = 0;
	G_drawVNeon[99].colour_r = 71;
	G_drawVNeon[99].colour_g = 120;
	G_drawVNeon[99].colour_b = 60;
	G_drawVNeon[99].colour_n = 60;
	//G_drawVNeon[99].fxoff = -20.0;
	G_drawVNeon[99].fyoff = 1.3;
	//G_drawVNeon[99].bxoff = -20.0;
	G_drawVNeon[99].byoff = -1.3;
	//G_drawVNeon[99].mxoff = -0.1;
	G_drawVNeon[99].myoff = 0.0;
	G_drawVNeon[99].height = 0.0;
	G_drawVNeon[99].fbrange = 2.7;
	G_drawVNeon[99].fbintensity = 85;
	G_drawVNeon[99].mrange = 2.5;
	G_drawVNeon[99].mintensity = 85;
	G_drawVNeon[99].dospeed = 1.0;
	G_drawVNeon[99].dobrake = 1.0;
	G_drawVNeon[99].dosteer = 1.0;

	if (!G_savedVehiclesLoaded[99])
	{
		int I;
		for (I = 1; I < 16; I++)
		{
			G_savedVehicles[I].model_n = 0;
			G_savedVehicles[I].normal_colour1 = 0;
			G_savedVehicles[I].normal_colour2 = 0;
			G_savedVehicles[I].extra_colour1 = 0;
			G_savedVehicles[I].extra_colour2 = 0;
			G_savedVehicles[I].upgrade1 = 0;
			G_savedVehicles[I].upgrade2 = 0;
			G_savedVehicles[I].upgrade3 = 0;
			G_savedVehicles[I].upgrade4 = 0;
			G_savedVehicles[I].upgrade5 = 0;
			G_savedVehicles[I].upgrade6 = 0;
			G_savedVehicles[I].upgrade7 = 0;
			G_savedVehicles[I].upgrade8 = 0;
			G_savedVehicles[I].upgrade9 = 0;
			G_savedVehicles[I].neon_toggle = 0;
			G_savedVehicles[I].neon_togglefb = 0;
			G_savedVehicles[I].neon_colour_r = 0;
			G_savedVehicles[I].neon_colour_g = 0;
			G_savedVehicles[I].neon_colour_b = 0;
			G_savedVehicles[I].neon_colour_n = 0;
			G_savedVehicles[I].neon_fyoff = 0;
			G_savedVehicles[I].neon_byoff = 0;
			G_savedVehicles[I].neon_myoff = 0;
			G_savedVehicles[I].neon_height = 0;
			G_savedVehicles[I].neon_fbrange = 0;
			G_savedVehicles[I].neon_fbintensity = 0;
			G_savedVehicles[I].neon_mrange = 0;
			G_savedVehicles[I].neon_mintensity = 0;
			G_savedVehicles[I].dospeed = 0;
			G_savedVehicles[I].dobrake = 0;
			G_savedVehicles[I].dosteer = 0;
		}
		G_savedVehiclesLoaded[99] = true;
	}

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

	// Meat MAIN
	garagesBlipCoords_x[5] = -422.4109;
	garagesBlipCoords_y[5] = -31.6985;
	garagesBlipCoords_z[5] = 9.5386 - 1;

	// showroom MAIN
	garagesBlipCoords_x[6] = -1496.8005;
	garagesBlipCoords_y[6] = 1118.9890;
	garagesBlipCoords_z[6] = 23.2138 - 1;
	
	// tudor MAIN
	garagesBlipCoords_x[7] = -1364.3031;
	garagesBlipCoords_y[7] = 11.7368;
	garagesBlipCoords_z[7] = 7.2487 - 1;

	int i;
	for (i = 1; i < 8; i++)
	{
		//CLEAR_AREA(garagesBlipCoords_x[i], garagesBlipCoords_y[i], garagesBlipCoords_z[i], 3.0000, true);
	
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

void DoVehicleMods(void)
{

//-0.00500000, -5.12500000, 1.41900000


/*
car front
-502.4153
1740.6450
7.9195
211.6515

car side
-501.4482  (spot -504.4058)
1739.0349
7.9641
300.3261

spot +5.0off
-505.3729
1740.7686
8.6050
211.6515



x = cos(heading) * distance + start_pos_x
y = sin(heading) * distance + start_pos_y

*/

	if (G_drawVNeon[99].dospeed != 1.0 && IS_PLAYER_PLAYING(GetPlayerIndex()))
	{
		if (DOES_VEHICLE_EXIST(G_v_domod[99]) && IS_VEH_DRIVEABLE(G_v_domod[99]))
		{
			if (IS_CONTROL_PRESSED(2, 40) && !IS_CONTROL_PRESSED(0, 41) && !IS_CONTROL_PRESSED(0, 45) !IS_CONTROL_PRESSED(0, 44) && IS_CHAR_IN_CAR(GetPlayerPed(), G_v_domod[99]))
			{
				if ((IS_CHAR_IN_ANY_HELI(GetPlayerPed()) || IS_CHAR_IN_ANY_BOAT(GetPlayerPed())) || (IS_VEHICLE_ON_ALL_WHEELS(G_v_domod[99]) && !IS_CAR_IN_WATER(G_v_domod[99]) && !IS_CAR_IN_AIR_PROPER(G_v_domod[99])))
				{
					APPLY_FORCE_TO_CAR(G_v_domod[99], 0, 0.0000, G_drawVNeon[99].dospeed, 0.0000, 0.0000, 0.0000, 0.0000, 0, 1, 1, 1);
				}
			}
		}
		else
		{
			G_drawVNeon[99].dospeed = 1.0;
			MARK_CAR_AS_NO_LONGER_NEEDED(&G_v_domod[99]);
		}
	}

	if (G_drawVNeon[99].dobrake != 1.0 && IS_PLAYER_PLAYING(GetPlayerIndex()))
	{
		if (DOES_VEHICLE_EXIST(G_v_domod[99]) && IS_VEH_DRIVEABLE(G_v_domod[99]))
		{
			if ((IS_CONTROL_PRESSED(0, 41) || IS_CONTROL_PRESSED(0, 45) || IS_CONTROL_PRESSED(0, 44)) && (IS_CHAR_IN_CAR(GetPlayerPed(), G_v_domod[99])))
			{
				float currentspeed;
				GET_CAR_SPEED(G_v_domod[99], &currentspeed);

				if (currentspeed > 12.5000 && ((IS_CHAR_IN_ANY_HELI(GetPlayerPed())) || (IS_VEHICLE_ON_ALL_WHEELS(G_v_domod[99]) && !IS_CAR_IN_WATER(G_v_domod[99]) && !IS_CAR_IN_AIR_PROPER(G_v_domod[99]))))
				{
					APPLY_FORCE_TO_CAR(G_v_domod[99], 0, 0.0000, 0.0 - G_drawVNeon[99].dobrake, 0.0000, 0.0000, 0.0000, 0.0000, 0, 1, 1, 1);
				}
			}
		}
		else
		{
			G_drawVNeon[99].dobrake = 1.0;
			MARK_CAR_AS_NO_LONGER_NEEDED(&G_v_domod[99]);
		}
	}

	if (G_drawVNeon[99].dosteer != 1.0 && IS_PLAYER_PLAYING(GetPlayerIndex()))
	{
		if (DOES_VEHICLE_EXIST(G_v_domod[99]) && IS_VEH_DRIVEABLE(G_v_domod[99]))
		{
			float currentspeed;
			GET_CAR_SPEED(G_v_domod[99], &currentspeed);

			if (currentspeed > 5.5000 && IS_CHAR_IN_CAR(GetPlayerPed(), G_v_domod[99]) && ((IS_CHAR_IN_ANY_HELI(GetPlayerPed()) || IS_CHAR_IN_ANY_BOAT(GetPlayerPed())) || (IS_VEHICLE_ON_ALL_WHEELS(G_v_domod[99]) && !IS_CAR_IN_WATER(G_v_domod[99]) && !IS_CAR_IN_AIR_PROPER(G_v_domod[99]))))
			{
				int stickleft_x;

				int nowhere, nowhere2, nowhere3;
				GET_POSITION_OF_ANALOGUE_STICKS(0, &stickleft_x, &nowhere, &nowhere2, &nowhere3);

				if (stickleft_x < -30 || IS_GAME_KEYBOARD_KEY_PRESSED(30))
				{
					APPLY_FORCE_TO_CAR(G_v_domod[99], 0, 0.0 - G_drawVNeon[99].dosteer, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0, 1, 1, 1);
				}
				else if (stickleft_x > 30 || IS_GAME_KEYBOARD_KEY_PRESSED(32))
				{
					APPLY_FORCE_TO_CAR(G_v_domod[99], 0, G_drawVNeon[99].dosteer, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0, 1, 1, 1);
				}
			}
		}
		else
		{
			G_drawVNeon[99].dosteer = 1.0;
			MARK_CAR_AS_NO_LONGER_NEEDED(&G_v_domod[99]);
		}
	}

	if (G_drawVNeon[99].toggle == 2)
	{
		if (DOES_VEHICLE_EXIST(G_v_domod[99]) && IS_VEH_DRIVEABLE(G_v_domod[99]))
		{
			float v_attach_x, v_attach_y, v_attach_z, v_attach_h;
			GET_CAR_HEADING(G_v_domod[99], &v_attach_h);
			GET_CAR_COORDINATES(G_v_domod[99], &v_attach_x, &v_attach_y, &v_attach_z);

			float v_moff_x, v_moff_y, v_moff_z;
			GET_OFFSET_FROM_CAR_IN_WORLD_COORDS(G_v_domod[99], -20.0, G_drawVNeon[99].myoff, G_drawVNeon[99].height, &v_moff_x, &v_moff_y, &v_moff_z);

			float mdist;
			GET_DISTANCE_BETWEEN_COORDS_2D(v_attach_x + -20.0, v_attach_y + G_drawVNeon[99].myoff, v_attach_x, v_attach_y, &mdist);
			float mx = COS(v_attach_h) * mdist + v_moff_x;
			float my = SIN(v_attach_h) * mdist + v_moff_y;

			DRAW_LIGHT_WITH_RANGE(mx, my, v_attach_z + G_drawVNeon[99].height, G_drawVNeon[99].colour_r, G_drawVNeon[99].colour_g, G_drawVNeon[99].colour_b, G_drawVNeon[99].mrange, G_drawVNeon[99].mintensity);

			if (G_drawVNeon[99].togglefb == 2)
			{
				float v_foff_x, v_foff_y, v_foff_z;
				GET_OFFSET_FROM_CAR_IN_WORLD_COORDS(G_v_domod[99], -20.0, G_drawVNeon[99].fyoff, G_drawVNeon[99].height, &v_foff_x, &v_foff_y, &v_foff_z);
				float v_boff_x, v_boff_y, v_boff_z;
				GET_OFFSET_FROM_CAR_IN_WORLD_COORDS(G_v_domod[99], -20.0, G_drawVNeon[99].byoff, G_drawVNeon[99].height, &v_boff_x, &v_boff_y, &v_boff_z);
				float fdist;
				GET_DISTANCE_BETWEEN_COORDS_2D(v_attach_x + -20.0, v_attach_y + G_drawVNeon[99].fyoff, v_attach_x, v_attach_y, &fdist);
				float bdist;
				GET_DISTANCE_BETWEEN_COORDS_2D(v_attach_x - -20.0, v_attach_y - G_drawVNeon[99].byoff, v_attach_x, v_attach_y, &bdist);
				float fx = COS(v_attach_h) * fdist + v_foff_x;
				float fy = SIN(v_attach_h) * fdist + v_foff_y;
				float bx = COS(v_attach_h) * bdist + v_boff_x;
				float by = SIN(v_attach_h) * bdist + v_boff_y;
				DRAW_LIGHT_WITH_RANGE(fx, fy, v_attach_z + G_drawVNeon[99].height, G_drawVNeon[99].colour_r, G_drawVNeon[99].colour_g, G_drawVNeon[99].colour_b, G_drawVNeon[99].fbrange, G_drawVNeon[99].fbintensity);
				DRAW_LIGHT_WITH_RANGE(bx, by, v_attach_z + G_drawVNeon[99].height, G_drawVNeon[99].colour_r, G_drawVNeon[99].colour_g, G_drawVNeon[99].colour_b, G_drawVNeon[99].fbrange, G_drawVNeon[99].fbintensity);
			}
		}
		else
		{
			G_drawVNeon[99].toggle = 0;
			MARK_CAR_AS_NO_LONGER_NEEDED(&G_v_domod[99]);
		}
	}
}

void DoActivators(void)
{

	int i;
	for (i = 1; i < 8; i++)
	{
		if (G_justexitmenu[23] == i && !LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), garagesBlipCoords_x[i], garagesBlipCoords_y[i], garagesBlipCoords_z[i], 5.00000000, 5.00000000, 6.00000000, 0))
		{
			G_justexitmenu[23] = 0;
		}

		if (G_justexitmenu[23] == 0 && !G_activateMenu[23])
		{
			DRAW_COLOURED_CYLINDER(garagesBlipCoords_x[i], garagesBlipCoords_y[i], garagesBlipCoords_z[i], 2.50000000, 2.50000000, 0, 132, 202, 255);
			if (LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), garagesBlipCoords_x[i], garagesBlipCoords_y[i], garagesBlipCoords_z[i], 2.50000000, 2.50000000, 4.00000000, 0))
			{
					G_activateMenu[23] = true;
					G_garageId[23] = i;
			}
		}
	}
	
	Vector3 upGarageCoords, downGarageCoords, currentGarageCoords, currentCharCoords;
	upGarageCoords.x = 864.32000000;
	upGarageCoords.y = -121.64500000;
	upGarageCoords.z = 12.00000000;

	downGarageCoords.x = 864.32000000;
	downGarageCoords.y = -121.64500000;
	downGarageCoords.z = 7.40000000;

	Object garage_object;

	if (GET_CURRENT_EPISODE() == 0)
	{
		garage_object = 0x123;
	}
	else if (GET_CURRENT_EPISODE() == 1)
	{
		garage_object = 0x456;
	}
	else if (GET_CURRENT_EPISODE() == 2)
	{
		garage_object = 0x789;
	}

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

	/*// Brucie Heli pad down
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
	}*/

}

void main(void)
{
	Init();

	while(true)
	{
		WAIT(0);
		if (G_activateMenu[23])
		{
			if (!G_drewrect[23])
			{
				DRAW_RECT(0.15000000, 0.35000000, 0.23000000, 0.63000000, 0, 0, 0, 167);
			}
			HIDE_HUD_AND_RADAR_THIS_FRAME();
			HIDE_HELP_TEXT_THIS_FRAME();
			if (!G_scriptloaded[23])
			{
				if ((GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT("garage_menu")) >= 1)
				{
					G_scriptloaded[23] = true;
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
					MARK_SCRIPT_AS_NO_LONGER_NEEDED("garage_menu");
					G_scriptloaded[23] = true;
				}
			}
		}
		DoActivators();
		DoVehicleMods();
	}
}