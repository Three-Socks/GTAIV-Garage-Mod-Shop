#include <natives.h>
#include <common.h>
#include <strings.h>
#include <types.h>
#include <consts.h>

#include "Locals.c"
#include "Functions.c"

#include "Menu.c"

/*

PushS 9088
GlobalVar
RefGet

*/

void Init(void)
{
	car_colours[1].r = 10;
	car_colours[1].g = 10;
	car_colours[1].b = 10;

	car_colours[2].r = 37;
	car_colours[2].g = 37;
	car_colours[2].b = 39;

	car_colours[3].r = 101;
	car_colours[3].g = 106;
	car_colours[3].b = 121;

	car_colours[4].r = 88;
	car_colours[4].g = 89;
	car_colours[4].b = 90;

	car_colours[5].r = 156;
	car_colours[5].g = 161;
	car_colours[5].b = 163;

	car_colours[6].r = 150;
	car_colours[6].g = 145;
	car_colours[6].b = 140;

	car_colours[7].r = 81;
	car_colours[7].g = 84;
	car_colours[7].b = 89;

	car_colours[8].r = 63;
	car_colours[8].g = 62;
	car_colours[8].b = 69;

	car_colours[9].r = 165;
	car_colours[9].g = 169;
	car_colours[9].b = 167;

	car_colours[10].r = 151;
	car_colours[10].g = 149;
	car_colours[10].b = 146;

	car_colours[11].r = 118;
	car_colours[11].g = 123;
	car_colours[11].b = 124;

	car_colours[12].r = 90;
	car_colours[12].g = 87;
	car_colours[12].b = 82;

	car_colours[13].r = 173;
	car_colours[13].g = 176;
	car_colours[13].b = 176;

	car_colours[14].r = 132;
	car_colours[14].g = 137;
	car_colours[14].b = 136;

	car_colours[15].r = 148;
	car_colours[15].g = 157;
	car_colours[15].b = 159;

	car_colours[16].r = 164;
	car_colours[16].g = 167;
	car_colours[16].b = 165;

	car_colours[17].r = 88;
	car_colours[17].g = 88;
	car_colours[17].b = 83;

	car_colours[18].r = 164;
	car_colours[18].g = 160;
	car_colours[18].b = 150;

	car_colours[19].r = 175;
	car_colours[19].g = 177;
	car_colours[19].b = 177;

	car_colours[20].r = 109;
	car_colours[20].g = 108;
	car_colours[20].b = 110;

	car_colours[21].r = 100;
	car_colours[21].g = 104;
	car_colours[21].b = 106;

	car_colours[22].r = 82;
	car_colours[22].g = 86;
	car_colours[22].b = 97;

	car_colours[23].r = 140;
	car_colours[23].g = 146;
	car_colours[23].b = 154;

	car_colours[24].r = 91;
	car_colours[24].g = 93;
	car_colours[24].b = 94;

	car_colours[25].r = 189;
	car_colours[25].g = 190;
	car_colours[25].b = 198;

	car_colours[26].r = 182;
	car_colours[26].g = 182;
	car_colours[26].b = 182;

	car_colours[27].r = 100;
	car_colours[27].g = 100;
	car_colours[27].b = 100;

	car_colours[28].r = 226;
	car_colours[28].g = 6;
	car_colours[28].b = 6;

	car_colours[29].r = 150;
	car_colours[29].g = 8;
	car_colours[29].b = 0;

	car_colours[30].r = 107;
	car_colours[30].g = 0;
	car_colours[30].b = 0;

	car_colours[31].r = 97;
	car_colours[31].g = 16;
	car_colours[31].b = 9;

	car_colours[32].r = 74;
	car_colours[32].g = 10;
	car_colours[32].b = 10;

	car_colours[33].r = 115;
	car_colours[33].g = 11;
	car_colours[33].b = 11;

	car_colours[34].r = 87;
	car_colours[34].g = 7;
	car_colours[34].b = 7;

	car_colours[35].r = 38;
	car_colours[35].g = 3;
	car_colours[35].b = 6;

	car_colours[36].r = 158;
	car_colours[36].g = 0;
	car_colours[36].b = 0;

	car_colours[37].r = 20;
	car_colours[37].g = 0;
	car_colours[37].b = 2;

	car_colours[38].r = 15;
	car_colours[38].g = 4;
	car_colours[38].b = 4;

	car_colours[39].r = 15;
	car_colours[39].g = 8;
	car_colours[39].b = 10;

	car_colours[40].r = 57;
	car_colours[40].g = 25;
	car_colours[40].b = 29;

	car_colours[41].r = 85;
	car_colours[41].g = 39;
	car_colours[41].b = 37;

	car_colours[42].r = 76;
	car_colours[42].g = 41;
	car_colours[42].b = 41;

	car_colours[43].r = 116;
	car_colours[43].g = 29;
	car_colours[43].b = 40;

	car_colours[44].r = 109;
	car_colours[44].g = 40;
	car_colours[44].b = 55;

	car_colours[45].r = 115;
	car_colours[45].g = 10;
	car_colours[45].b = 39;

	car_colours[46].r = 100;
	car_colours[46].g = 13;
	car_colours[46].b = 27;

	car_colours[47].r = 98;
	car_colours[47].g = 11;
	car_colours[47].b = 28;

	car_colours[48].r = 115;
	car_colours[48].g = 24;
	car_colours[48].b = 39;

	car_colours[49].r = 171;
	car_colours[49].g = 152;
	car_colours[49].b = 143;

	car_colours[50].r = 32;
	car_colours[50].g = 32;
	car_colours[50].b = 44;

	car_colours[51].r = 68;
	car_colours[51].g = 98;
	car_colours[51].b = 79;

	car_colours[52].r = 46;
	car_colours[52].g = 91;
	car_colours[52].b = 32;

	car_colours[53].r = 30;
	car_colours[53].g = 46;
	car_colours[53].b = 50;

	car_colours[54].r = 48;
	car_colours[54].g = 79;
	car_colours[54].b = 69;

	car_colours[55].r = 77;
	car_colours[55].g = 98;
	car_colours[55].b = 104;

	car_colours[56].r = 94;
	car_colours[56].g = 112;
	car_colours[56].b = 114;

	car_colours[57].r = 25;
	car_colours[57].g = 56;
	car_colours[57].b = 38;

	car_colours[58].r = 45;
	car_colours[58].g = 58;
	car_colours[58].b = 53;

	car_colours[59].r = 51;
	car_colours[59].g = 95;
	car_colours[59].b = 63;

	car_colours[60].r = 71;
	car_colours[60].g = 120;
	car_colours[60].b = 60;

	car_colours[61].r = 147;
	car_colours[61].g = 163;
	car_colours[61].b = 150;

	car_colours[62].r = 154;
	car_colours[62].g = 167;
	car_colours[62].b = 144;

	car_colours[63].r = 38;
	car_colours[63].g = 55;
	car_colours[63].b = 57;

	car_colours[64].r = 76;
	car_colours[64].g = 117;
	car_colours[64].b = 183;

	car_colours[65].r = 70;
	car_colours[65].g = 89;
	car_colours[65].b = 122;

	car_colours[66].r = 93;
	car_colours[66].g = 126;
	car_colours[66].b = 141;

	car_colours[67].r = 59;
	car_colours[67].g = 78;
	car_colours[67].b = 120;

	car_colours[68].r = 61;
	car_colours[68].g = 74;
	car_colours[68].b = 104;

	car_colours[69].r = 109;
	car_colours[69].g = 122;
	car_colours[69].b = 136;

	car_colours[70].r = 22;
	car_colours[70].g = 34;
	car_colours[70].b = 72;

	car_colours[71].r = 39;
	car_colours[71].g = 47;
	car_colours[71].b = 75;

	car_colours[72].r = 78;
	car_colours[72].g = 104;
	car_colours[72].b = 129;

	car_colours[73].r = 106;
	car_colours[73].g = 122;
	car_colours[73].b = 140;

	car_colours[74].r = 111;
	car_colours[74].g = 130;
	car_colours[74].b = 151;

	car_colours[75].r = 14;
	car_colours[75].g = 49;
	car_colours[75].b = 109;

	car_colours[76].r = 57;
	car_colours[76].g = 90;
	car_colours[76].b = 131;

	car_colours[77].r = 32;
	car_colours[77].g = 75;
	car_colours[77].b = 107;

	car_colours[78].r = 43;
	car_colours[78].g = 62;
	car_colours[78].b = 87;

	car_colours[79].r = 54;
	car_colours[79].g = 65;
	car_colours[79].b = 85;

	car_colours[80].r = 108;
	car_colours[80].g = 132;
	car_colours[80].b = 149;

	car_colours[81].r = 77;
	car_colours[81].g = 93;
	car_colours[81].b = 96;

	car_colours[82].r = 64;
	car_colours[82].g = 108;
	car_colours[82].b = 143;

	car_colours[83].r = 19;
	car_colours[83].g = 69;
	car_colours[83].b = 115;

	car_colours[84].r = 16;
	car_colours[84].g = 80;
	car_colours[84].b = 130;

	car_colours[85].r = 56;
	car_colours[85].g = 86;
	car_colours[85].b = 148;

	car_colours[86].r = 0;
	car_colours[86].g = 28;
	car_colours[86].b = 50;

	car_colours[87].r = 89;
	car_colours[87].g = 110;
	car_colours[87].b = 135;

	car_colours[88].r = 34;
	car_colours[88].g = 52;
	car_colours[88].b = 87;

	car_colours[89].r = 32;
	car_colours[89].g = 32;
	car_colours[89].b = 44;

	car_colours[90].r = 245;
	car_colours[90].g = 137;
	car_colours[90].b = 15;

	car_colours[91].r = 145;
	car_colours[91].g = 115;
	car_colours[91].b = 71;

	car_colours[92].r = 142;
	car_colours[92].g = 140;
	car_colours[92].b = 70;

	car_colours[93].r = 170;
	car_colours[93].g = 173;
	car_colours[93].b = 142;

	car_colours[94].r = 174;
	car_colours[94].g = 155;
	car_colours[94].b = 127;

	car_colours[95].r = 150;
	car_colours[95].g = 129;
	car_colours[95].b = 108;

	car_colours[96].r = 122;
	car_colours[96].g = 117;
	car_colours[96].b = 96;

	car_colours[97].r = 157;
	car_colours[97].g = 152;
	car_colours[97].b = 114;

	car_colours[98].r = 152;
	car_colours[98].g = 149;
	car_colours[98].b = 134;

	car_colours[99].r = 156;
	car_colours[99].g = 141;
	car_colours[99].b = 113;

	car_colours[100].r = 105;
	car_colours[100].g = 30;
	car_colours[100].b = 59;

	car_colours[101].r = 114;
	car_colours[101].g = 42;
	car_colours[101].b = 63;

	car_colours[102].r = 124;
	car_colours[102].g = 27;
	car_colours[102].b = 68;

	car_colours[103].r = 34;
	car_colours[103].g = 25;
	car_colours[103].b = 24;

	car_colours[104].r = 127;
	car_colours[104].g = 105;
	car_colours[104].b = 86;

	car_colours[105].r = 71;
	car_colours[105].g = 53;
	car_colours[105].b = 50;

	car_colours[106].r = 105;
	car_colours[106].g = 88;
	car_colours[106].b = 83;

	car_colours[107].r = 98;
	car_colours[107].g = 68;
	car_colours[107].b = 40;

	car_colours[108].r = 125;
	car_colours[108].g = 98;
	car_colours[108].b = 86;

	car_colours[109].r = 170;
	car_colours[109].g = 157;
	car_colours[109].b = 132;

	car_colours[110].r = 123;
	car_colours[110].g = 113;
	car_colours[110].b = 94;

	car_colours[111].r = 171;
	car_colours[111].g = 146;
	car_colours[111].b = 118;

	car_colours[112].r = 99;
	car_colours[112].g = 92;
	car_colours[112].b = 90;

	car_colours[113].r = 201;
	car_colours[113].g = 201;
	car_colours[113].b = 201;

	car_colours[114].r = 214;
	car_colours[114].g = 218;
	car_colours[114].b = 214;

	car_colours[115].r = 159;
	car_colours[115].g = 157;
	car_colours[115].b = 148;

	car_colours[116].r = 147;
	car_colours[116].g = 163;
	car_colours[116].b = 150;

	car_colours[117].r = 156;
	car_colours[117].g = 156;
	car_colours[117].b = 152;

	car_colours[118].r = 167;
	car_colours[118].g = 162;
	car_colours[118].b = 143;

	car_colours[119].r = 15;
	car_colours[119].g = 106;
	car_colours[119].b = 137;

	car_colours[120].r = 161;
	car_colours[120].g = 153;
	car_colours[120].b = 131;

	car_colours[121].r = 163;
	car_colours[121].g = 173;
	car_colours[121].b = 198;

	car_colours[122].r = 155;
	car_colours[122].g = 139;
	car_colours[122].b = 128;

	car_colours[123].r = 132;
	car_colours[123].g = 148;
	car_colours[123].b = 171;

	car_colours[124].r = 158;
	car_colours[124].g = 164;
	car_colours[124].b = 171;

	car_colours[125].r = 134;
	car_colours[125].g = 68;
	car_colours[125].b = 110;

	car_colours[126].r = 226;
	car_colours[126].g = 6;
	car_colours[126].b = 6;

	car_colours[127].r = 71;
	car_colours[127].g = 120;
	car_colours[127].b = 60;

	car_colours[128].r = 215;
	car_colours[128].g = 142;
	car_colours[128].b = 16;

	car_colours[129].r = 42;
	car_colours[129].g = 119;
	car_colours[129].b = 161;

	car_colours[130].r = 66;
	car_colours[130].g = 31;
	car_colours[130].b = 33;

	car_colours[131].r = 111;
	car_colours[131].g = 103;
	car_colours[131].b = 95;

	car_colours[132].r = 252;
	car_colours[132].g = 38;
	car_colours[132].b = 0;

	car_colours[133].r = 252;
	car_colours[133].g = 109;
	car_colours[133].b = 0;

	/*car_colours[134].r = 255;
	car_colours[134].g = 255;
	car_colours[134].b = 255;*/

	Vector3 vStartCoords;
	vStartCoords.x = 869.58590000;
	vStartCoords.y = -121.03340000;
	vStartCoords.z = 6.00050000;

	CLEAR_PRINTS();
	CLEAR_HELP();
	CLEAR_WANTED_LEVEL(GetPlayerIndex());

	SET_PED_DENSITY_MULTIPLIER(1.0);
	SET_CAR_DENSITY_MULTIPLIER(1.0);

	PlayAsBrucie();

	REQUEST_MODEL(MODEL_BANSHEE);
	while (!HAS_MODEL_LOADED(MODEL_BANSHEE)) WAIT(0);
	SUPPRESS_CAR_MODEL(MODEL_BANSHEE);
	Vehicle v_banshee;
	CREATE_CAR(MODEL_BANSHEE, 874.81200000, -114.20310000, 5.61220000, &v_banshee, FALSE);
	SET_CAR_AS_MISSION_CAR(v_banshee);
	SET_HAS_BEEN_OWNED_BY_PLAYER(v_banshee, TRUE);
	SET_NEEDS_TO_BE_HOTWIRED(v_banshee, FALSE);
	SET_VEH_HAS_STRONG_AXLES(v_banshee, 1);
	FREEZE_CAR_POSITION(v_banshee, 0);

	// This must be set before set_char_coords or brucies garage interior will not load.
	SET_PLAYER_CONTROL(GetPlayerIndex(), true);

	SET_CHAR_COORDINATES_NO_OFFSET(GetPlayerPed(), vStartCoords.x, vStartCoords.y, vStartCoords.z);
	CLEAR_CHAR_TASKS(GetPlayerPed());

	// Load brucie's garage
  //CLEAR_AREA(870.37810000, -121.81840000, 5.00001000, 50.00000000, 1);
	LOAD_SCENE(vStartCoords.x, vStartCoords.y, vStartCoords.z);
	SET_CHAR_HEADING(GetPlayerPed(), 312.0);
	/*Interior bruInterior;
	GET_INTERIOR_AT_COORDS(869.58590000, -121.03340000, 5.00050000, &bruInterior);
  uint bruhash = GET_HASH_KEY("BrucieMain");
  LOAD_SCENE_FOR_ROOM_BY_KEY(bruInterior, bruhash);*/

	SET_LOAD_COLLISION_FOR_CAR_FLAG(v_banshee, 1);
	SET_ROOM_FOR_CAR_BY_NAME(v_banshee, "GtaMloRoom08");

	SET_CAR_HEADING(v_banshee, 180.0);
	SET_CAR_COORDINATES(v_banshee, 874.81200000, -114.20310000, 5.61220000);
	SET_CAR_ON_GROUND_PROPERLY(v_banshee);

	SET_CONVERTIBLE_ROOF(v_banshee, TRUE);
	CHANGE_CAR_COLOUR(v_banshee, 0, 89);
  SET_EXTRA_CAR_COLOURS(v_banshee, 0, 0);
  SET_VEHICLE_DIRT_LEVEL(v_banshee, 0);
  WASH_VEHICLE_TEXTURES(v_banshee, 255);
	MARK_MODEL_AS_NO_LONGER_NEEDED(MODEL_BANSHEE);

	ENABLE_MAX_AMMO_CAP(FALSE);
	UpdateWeaponOfPed(GetPlayerPed(), WEAPON_BASEBALLBAT);
	UpdateWeaponOfPed(GetPlayerPed(), WEAPON_AK47);
	UpdateWeaponOfPed(GetPlayerPed(), WEAPON_PISTOL);

	SET_GAME_CAM_HEADING(0.0);

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
			activateMenu = true;
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
	SET_MISSION_FLAG(1);
	SET_PLAYER_CONTROL(GetPlayerIndex(), false);
	DO_SCREEN_FADE_OUT(500);
	while (!IS_SCREEN_FADED_OUT())
	{
		WAIT(0);
	}
	Init();
	WAIT(1000);
	DO_SCREEN_FADE_IN(500);
	while (!IS_SCREEN_FADED_IN())
	{
		WAIT( 0 );
	}

	while(true)
	{
		WAIT(0);
		if (activateMenu)
		{
			DoMenu();
		}
		DoActivators();
	}
}
