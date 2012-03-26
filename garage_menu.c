#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

#include "globals.h"
#include "Locals.h"

#include "Functions.c"

#include "Menu.c"

void Init(void)
{
	CLEAR_PRINTS();
	CLEAR_HELP();

// Brucie Garage
// Brucie MAIN
	garage_main_spawn_x = 874.8120;
	garage_main_spawn_y = -114.2031;
	garage_main_spawn_z = 5.6122;
	garage_main_spawn_h = 180.0000;

	garage_main_exit_x = 869.0119;
	garage_main_exit_y = -114.6501;
	garage_main_exit_z = 5.4054;
	garage_main_exit_h = 270.0000;

	garage_main_quit_x = 866.3309;
	garage_main_quit_y = -116.7025;
	garage_main_quit_z = 6.0054;
	garage_main_quit_h = 181.0000;

// Brucie BIG
	garage_big_spawn_x = 807.7111;
	garage_big_spawn_y = -161.0524;
	garage_big_spawn_z = 6.4449;
	garage_big_spawn_h = 335.8888;

	garage_big_exit_x = 799.8708;
	garage_big_exit_y = -161.9819;
	garage_big_exit_z = 5.8214;
	garage_big_exit_h = 291.4525;

	garage_big_quit_x = garage_big_exit_x;
	garage_big_quit_y = garage_big_exit_y;
	garage_big_quit_z = garage_big_exit_z;
	garage_big_quit_h = garage_big_exit_h;

	// Brucie BOAT
	garage_boat_spawn_x = 698.8500;
	garage_boat_spawn_y = -153.6000;
	garage_boat_spawn_z = 0.0000;
	garage_boat_spawn_h = 61.3000;
	
	garage_boat_exit_x = 696.3401;
	garage_boat_exit_y = -147.7382;
	garage_boat_exit_z = 1.2833;
	garage_boat_exit_h = 154.9767;

	garage_boat_quit_x = garage_boat_exit_x;
	garage_boat_quit_y = garage_boat_exit_y;
	garage_boat_quit_z = garage_boat_exit_z;
	garage_boat_quit_h = garage_boat_exit_h;

// Brucie HELI
	garage_heli_spawn_x = 786.5347;
	garage_heli_spawn_y = 150.7447;
	garage_heli_spawn_z = 27.7479;
	garage_heli_spawn_h = 180.0000;

	garage_heli_exit_x = 778.4066;
	garage_heli_exit_y = 152.2448;
	garage_heli_exit_z = 27.4394;
	garage_heli_exit_h = 268.0000;

	garage_heli_quit_x = garage_heli_exit_x;
	garage_heli_quit_y = garage_heli_exit_y;
	garage_heli_quit_z = garage_heli_exit_z;
	garage_heli_quit_h = garage_heli_exit_h;
	
	if (G_garageId[2398] == 2)
	{
	// Meadows park (1st island)
	// Meadows MAIN
		garage_main_spawn_x = 1775.6616;
		garage_main_spawn_y = 836.8135;
		garage_main_spawn_z = 16.2557;
		garage_main_spawn_h = 344.5343;

		garage_main_exit_x = garage_main_spawn_x;
		garage_main_exit_y = garage_main_spawn_y + 8;
		garage_main_exit_z = garage_main_spawn_z;
		garage_main_exit_h = garage_main_spawn_h;

		garage_main_quit_x = garage_main_spawn_x;
		garage_main_quit_y = garage_main_spawn_y + 8;
		garage_main_quit_z = garage_main_spawn_z;
		garage_main_quit_h = garage_main_spawn_h;

	// Meadows BIG
		garage_big_spawn_x = 1780.5695;
		garage_big_spawn_y = 853.7727;
		garage_big_spawn_z = 16.2572;
		garage_big_spawn_h = 77.0736;

		garage_big_exit_x = garage_big_spawn_x + 2;
		garage_big_exit_y = garage_big_spawn_y;
		garage_big_exit_z = garage_big_spawn_z;
		garage_big_exit_h = garage_big_spawn_h;

		garage_big_quit_x = garage_big_spawn_x + 2;
		garage_big_quit_y = garage_big_spawn_y;
		garage_big_quit_z = garage_big_spawn_z;
		garage_big_quit_h = garage_big_spawn_h;

	// Meadows BOAT (TEMP HELI COORDS)
		garage_boat_spawn_x = 1774.4158;
		garage_boat_spawn_y = 837.0033;
		garage_boat_spawn_z = 22.9287;
		garage_boat_spawn_h = 73.8474;

		garage_boat_exit_x = garage_boat_spawn_x;
		garage_boat_exit_y = garage_boat_spawn_y;
		garage_boat_exit_z = garage_boat_spawn_z;
		garage_boat_exit_h = garage_boat_spawn_h;

		garage_boat_quit_x = garage_boat_spawn_x;
		garage_boat_quit_y = garage_boat_spawn_y;
		garage_boat_quit_z = garage_boat_spawn_z;
		garage_boat_quit_h = garage_boat_spawn_h;
		
	// Meadows HELI
		garage_heli_spawn_x = 1774.4158;
		garage_heli_spawn_y = 837.0033;
		garage_heli_spawn_z = 22.9287;
		garage_heli_spawn_h = 73.8474;

		garage_heli_exit_x = garage_heli_spawn_x + 5;
		garage_heli_exit_y = garage_heli_spawn_y;
		garage_heli_exit_z = garage_heli_spawn_z;
		garage_heli_exit_h = garage_heli_spawn_h;

		garage_heli_quit_x = garage_heli_spawn_x + 5;
		garage_heli_quit_y = garage_heli_spawn_y;
		garage_heli_quit_z = garage_heli_spawn_z;
		garage_heli_quit_h = garage_heli_spawn_h;
	}
	else if (G_garageId[2398] == 3)
	{
	// Boulevard bohan (2nd island)
	// bohan MAIN
		garage_main_spawn_x = 303.5034;
		garage_main_spawn_y = 1877.3126;
		garage_main_spawn_z = 21.5842;
		garage_main_spawn_h = 269.7305;

		garage_main_exit_x = garage_main_spawn_x + 4;
		garage_main_exit_y = garage_main_spawn_y;
		garage_main_exit_z = garage_main_spawn_z;
		garage_main_exit_h = garage_main_spawn_h;

		garage_main_quit_x = garage_main_spawn_x + 4;
		garage_main_quit_y = garage_main_spawn_y;
		garage_main_quit_z = garage_main_spawn_z;
		garage_main_quit_h = garage_main_spawn_h;

	// bohan BIG
		garage_big_spawn_x = 308.0928;
		garage_big_spawn_y = 1854.0841;
		garage_big_spawn_z = 17.2733;
		garage_big_spawn_h = 268.0361;

		garage_big_exit_x = garage_big_spawn_x;
		garage_big_exit_y = garage_big_spawn_y;
		garage_big_exit_z = garage_big_spawn_z;
		garage_big_exit_h = garage_big_spawn_h;

		garage_big_quit_x = garage_big_spawn_x;
		garage_big_quit_y = garage_big_spawn_y;
		garage_big_quit_z = garage_big_spawn_z;
		garage_big_quit_h = garage_big_spawn_h;

	// bohan BOAT
		garage_boat_spawn_x = 267.5500;
		garage_boat_spawn_y = 1953.8890;
		garage_boat_spawn_z = 0.0000;
		garage_boat_spawn_h = 82.1200;

		garage_boat_exit_x = garage_boat_spawn_x;
		garage_boat_exit_y = garage_boat_spawn_y;
		garage_boat_exit_z = garage_boat_spawn_z;
		garage_boat_exit_h = garage_boat_spawn_h;

		garage_boat_quit_x = garage_boat_spawn_x;
		garage_boat_quit_y = garage_boat_spawn_y;
		garage_boat_quit_z = garage_boat_spawn_z;
		garage_boat_quit_h = garage_boat_spawn_h;
		
	// bohan HELI
		garage_heli_spawn_x = 310.4410;
		garage_heli_spawn_y = 1889.7988;
		garage_heli_spawn_z = 21.8017;
		garage_heli_spawn_h = 269.7008;

		garage_heli_exit_x = garage_heli_spawn_x;
		garage_heli_exit_y = garage_heli_spawn_y + 4;
		garage_heli_exit_z = garage_heli_spawn_z;
		garage_heli_exit_h = garage_heli_spawn_h;

		garage_heli_quit_x = garage_heli_spawn_x;
		garage_heli_quit_y = garage_heli_spawn_y + 4;
		garage_heli_quit_z = garage_heli_spawn_z;
		garage_heli_quit_h = garage_heli_spawn_h;
	}
	else if (G_garageId[2398] == 4)
	{
	// Northwood scrapyard (3rd island)
	// scrapyard MAIN
		garage_main_spawn_x = -502.4153;
		garage_main_spawn_y = 1740.6450;
		garage_main_spawn_z = 8.3289;
		garage_main_spawn_h = 211.6515;

		garage_main_exit_x = garage_main_spawn_x + 4;
		garage_main_exit_y = garage_main_spawn_y;
		garage_main_exit_z = garage_main_spawn_z;
		garage_main_exit_h = garage_main_spawn_h;

		garage_main_quit_x = garage_main_spawn_x + 4;
		garage_main_quit_y = garage_main_spawn_y;
		garage_main_quit_z = garage_main_spawn_z;
		garage_main_quit_h = garage_main_spawn_h;

	// scrapyard BIG
		garage_big_spawn_x = garage_main_spawn_x;
		garage_big_spawn_y = garage_main_spawn_y;
		garage_big_spawn_z = garage_main_spawn_z;
		garage_big_spawn_h = garage_main_spawn_h;

		garage_big_exit_x = garage_main_spawn_x + 4;
		garage_big_exit_y = garage_main_spawn_y;
		garage_big_exit_z = garage_main_spawn_z;
		garage_big_exit_h = garage_main_spawn_h;

		garage_big_quit_x = garage_main_spawn_x + 4;
		garage_big_quit_y = garage_main_spawn_y;
		garage_big_quit_z = garage_main_spawn_z;
		garage_big_quit_h = garage_main_spawn_h;

	// scrapyard BOAT
		garage_boat_spawn_x = 550.0000;
		garage_boat_spawn_y = 1776.0000;
		garage_boat_spawn_z = 0.0000;
		garage_boat_spawn_h = 120.1200;

		garage_boat_exit_x = garage_boat_spawn_x;
		garage_boat_exit_y = garage_boat_spawn_y;
		garage_boat_exit_z = garage_boat_spawn_z;
		garage_boat_exit_h = garage_boat_spawn_h;

		garage_boat_quit_x = garage_boat_spawn_x;
		garage_boat_quit_y = garage_boat_spawn_y;
		garage_boat_quit_z = garage_boat_spawn_z;
		garage_boat_quit_h = garage_boat_spawn_h;
		
	// scrapyard HELI
		garage_heli_spawn_x = garage_main_spawn_x;
		garage_heli_spawn_y = garage_main_spawn_y;
		garage_heli_spawn_z = garage_main_spawn_z;
		garage_heli_spawn_h = garage_main_spawn_h;

		garage_heli_exit_x = garage_main_spawn_x + 4;
		garage_heli_exit_y = garage_main_spawn_y;
		garage_heli_exit_z = garage_main_spawn_z;
		garage_heli_exit_h = garage_main_spawn_h;

		garage_heli_quit_x = garage_main_spawn_x + 4;
		garage_heli_quit_y = garage_main_spawn_y;
		garage_heli_quit_z = garage_main_spawn_z;
		garage_heli_quit_h = garage_main_spawn_h;
	}
	else if (G_garageId[2398] == 5)
	{
	// Westminster packie garage (3rd island)
	// packie MAIN
		garage_main_spawn_x = -513.8602;
		garage_main_spawn_y = 332.2618;
		garage_main_spawn_z = 6.2173;
		garage_main_spawn_h = 88.3298;

		garage_main_exit_x = garage_main_spawn_x;
		garage_main_exit_y = garage_main_spawn_y;
		garage_main_exit_z = garage_main_spawn_z;
		garage_main_exit_h = garage_main_spawn_h;

		garage_main_quit_x = garage_main_spawn_x;
		garage_main_quit_y = garage_main_spawn_y;
		garage_main_quit_z = garage_main_spawn_z;
		garage_main_quit_h = garage_main_spawn_h;

	// packie BIG
		garage_big_spawn_x = garage_main_spawn_x;
		garage_big_spawn_y = garage_main_spawn_y;
		garage_big_spawn_z = garage_main_spawn_z;
		garage_big_spawn_h = garage_main_spawn_h;

		garage_big_exit_x = garage_main_spawn_x;
		garage_big_exit_y = garage_main_spawn_y;
		garage_big_exit_z = garage_main_spawn_z;
		garage_big_exit_h = garage_main_spawn_h;

		garage_big_quit_x = garage_main_spawn_x;
		garage_big_quit_y = garage_main_spawn_y;
		garage_big_quit_z = garage_main_spawn_z;
		garage_big_quit_h = garage_main_spawn_h;

	// packie BOAT
		garage_boat_spawn_x = 646.0000;
		garage_boat_spawn_y = 304.0000;
		garage_boat_spawn_z = 0.0000;
		garage_boat_spawn_h = 89.0000;

		garage_boat_exit_x = garage_boat_spawn_x;
		garage_boat_exit_y = garage_boat_spawn_y;
		garage_boat_exit_z = garage_boat_spawn_z;
		garage_boat_exit_h = garage_boat_spawn_h;

		garage_boat_quit_x = garage_boat_spawn_x;
		garage_boat_quit_y = garage_boat_spawn_y;
		garage_boat_quit_z = garage_boat_spawn_z;
		garage_boat_quit_h = garage_boat_spawn_h;
		
	// packie HELI
		garage_heli_spawn_x = 708.9586;
		garage_heli_spawn_y = 357.4991;
		garage_heli_spawn_z = 3.9857;
		garage_heli_spawn_h = 270.0002;

		garage_heli_exit_x = garage_main_spawn_x;
		garage_heli_exit_y = garage_main_spawn_y;
		garage_heli_exit_z = garage_main_spawn_z;
		garage_heli_exit_h = garage_main_spawn_h;

		garage_heli_quit_x = garage_main_spawn_x;
		garage_heli_quit_y = garage_main_spawn_y;
		garage_heli_quit_z = garage_main_spawn_z;
		garage_heli_quit_h = garage_main_spawn_h;		
	}
	else if (G_garageId[2398] == 6)
	{
	// alderney showroom (4th island)
	// showroom MAIN
		garage_main_spawn_x = -1492.3105;
		garage_main_spawn_y = 1131.0712;
		garage_main_spawn_z = 22.5675;
		garage_main_spawn_h = 272.6053;

		garage_main_exit_x = garage_main_spawn_x;
		garage_main_exit_y = garage_main_spawn_y;
		garage_main_exit_z = garage_main_spawn_z;
		garage_main_exit_h = garage_main_spawn_h;

		garage_main_quit_x = garage_main_spawn_x;
		garage_main_quit_y = garage_main_spawn_y;
		garage_main_quit_z = garage_main_spawn_z;
		garage_main_quit_h = garage_main_spawn_h;

	// showroom BIG
		garage_big_spawn_x = garage_main_spawn_x;
		garage_big_spawn_y = garage_main_spawn_y;
		garage_big_spawn_z = garage_main_spawn_z;
		garage_big_spawn_h = garage_main_spawn_h;

		garage_big_exit_x = garage_main_spawn_x;
		garage_big_exit_y = garage_main_spawn_y;
		garage_big_exit_z = garage_main_spawn_z;
		garage_big_exit_h = garage_main_spawn_h;

		garage_big_quit_x = garage_main_spawn_x;
		garage_big_quit_y = garage_main_spawn_y;
		garage_big_quit_z = garage_main_spawn_z;
		garage_big_quit_h = garage_main_spawn_h;

	// showroom BOAT
		garage_boat_spawn_x = 1633.0000;
		garage_boat_spawn_y = 1220.0000;
		garage_boat_spawn_z = 0.0000;
		garage_boat_spawn_h = 83.0000;

		garage_boat_exit_x = garage_boat_spawn_x;
		garage_boat_exit_y = garage_boat_spawn_y;
		garage_boat_exit_z = garage_boat_spawn_z;
		garage_boat_exit_h = garage_boat_spawn_h;

		garage_boat_quit_x = garage_boat_spawn_x;
		garage_boat_quit_y = garage_boat_spawn_y;
		garage_boat_quit_z = garage_boat_spawn_z;
		garage_boat_quit_h = garage_boat_spawn_h;
		
	// showroom HELI
		garage_heli_spawn_x = -1529.0396;
		garage_heli_spawn_y = 1104.2229;
		garage_heli_spawn_z = 26.4210;
		garage_heli_spawn_h = 174.8738;

		garage_heli_exit_x = garage_main_spawn_x;
		garage_heli_exit_y = garage_main_spawn_y;
		garage_heli_exit_z = garage_main_spawn_z;
		garage_heli_exit_h = garage_main_spawn_h;

		garage_heli_quit_x = garage_main_spawn_x;
		garage_heli_quit_y = garage_main_spawn_y;
		garage_heli_quit_z = garage_main_spawn_z;
		garage_heli_quit_h = garage_main_spawn_h;
	}

	exit_x = garage_main_exit_x; exit_y = garage_main_exit_y; exit_z = garage_main_exit_z; exit_h = garage_main_exit_h;
	quit_x = garage_main_quit_x; quit_y = garage_main_quit_y; quit_z = garage_main_quit_z; quit_h = garage_main_quit_h;
	spawn_x = garage_main_spawn_x; spawn_y = garage_main_spawn_y; spawn_z = garage_main_spawn_z; spawn_h = garage_main_spawn_h;
	
	G_item_highlighted[2398] = 1;

}

void main(void)
{
	Init();
	while(true)
	{
		WAIT(0);
		DoMenu();
		if (!G_doneExitCheck[2398] && HAS_DEATHARREST_EXECUTED() 
		//|| 
		//(
		//!LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), garage_main_spawn_x, garage_main_spawn_y, garage_main_spawn_z, 50.00000000, 50.00000000, 50.00000000, 0) && 
		//!LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), garage_big_spawn_x, garage_big_spawn_y, garage_big_spawn_z, 50.00000000, 50.00000000, 50.00000000, 0) && 
		//!LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), 698.8500, -153.6000, 0.0000, 50.00000000, 50.00000000, 50.00000000, 0) && 
		//!LOCATE_CHAR_ANY_MEANS_3D(GetPlayerPed(), garage_heli.spawn_x, garage_heli.spawn_y, garage_heli.spawn_z, 50.00000000, 50.00000000, 50.00000000, 0)
		//)
		)
		{
			G_activateMenu[2398] = false;
			G_scriptloaded[2398] = false;
			G_doneExitCheck[2398] = true;
			SET_PLAYER_CONTROL(GetPlayerIndex(), true);
			SET_CAMERA_CONTROLS_DISABLED_WITH_PLAYER_CONTROLS(0);
			TERMINATE_THIS_SCRIPT();
		}
	}
}