bool isAnoPressedLong(void)
{
	uint padleft_x, padleft_y, padright_x, padright_y;
	GET_POSITION_OF_ANALOGUE_STICKS(0, &padleft_x, &padleft_y, &padright_x, &padright_y);

	if (padleft_x > 100 || padleft_y < -100)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void StoreModify(bool notwindow, bool notbreak, bool notopen, uint itemwindow, uint itembreak, uint itemopen)
{
	// Store broken/open doors & windows.
	FREEZE_CAR_POSITION(v_modding, 0);
	LOCK_CAR_DOORS(v_modding, 1);

	int window_I;
	for (window_I = 0; window_I < 4; window_I++)
	{
		if (notwindow)
		{
			if (!IS_VEH_WINDOW_INTACT(v_modding, window_I) && window_I != itemwindow)
			{
				window_notintact[window_I] = 1;
			}
			else
			{
				window_notintact[window_I] = 0;
			}
		}
		else
		{
			if (!IS_VEH_WINDOW_INTACT(v_modding, window_I))
			{
				window_notintact[window_I] = 1;
			}
			else
			{
				window_notintact[window_I] = 0;
			}
		}
	}

	int door_I;
	for (door_I = 0; door_I < 6; door_I++)
	{
		if (notbreak)
		{
			if (IS_CAR_DOOR_DAMAGED(v_modding, door_I) && door_I != itembreak)
			{
				door_damaged[door_I] = 1;
			}
			else
			{
				door_damaged[door_I] = 0;
			}
		}
		else
		{
			if (IS_CAR_DOOR_DAMAGED(v_modding, door_I))
			{
				door_damaged[door_I] = 1;
			}
			else
			{
				door_damaged[door_I] = 0;
			}
		}
		
		float doorangle;
		GET_DOOR_ANGLE_RATIO(v_modding, door_I, &doorangle);

		if (notopen)
		{
			if (!IS_CAR_DOOR_DAMAGED(v_modding, door_I) && doorangle >= 0.5000 && door_I != itemopen)
			{
				door_opened[door_I] = 1;
			}
			else
			{
				door_opened[door_I] = 0;
			}
		}
		else
		{
			if (!IS_CAR_DOOR_DAMAGED(v_modding, door_I) && doorangle >= 0.5000)
			{
				door_opened[door_I] = 1;
			}
			else
			{
				door_opened[door_I] = 0;
			}
		}
	}

}

void ReApplyModify(void)
{
	// Re-Apply broken/open doors & windows.
	int door_I;
	for (door_I = 0; door_I < 6; door_I++)
	{
		if (door_damaged[door_I] == 1)
		{
			BREAK_CAR_DOOR(v_modding, door_I, false);
		}

		if (door_opened[door_I] == 1)
		{
			OPEN_CAR_DOOR(v_modding, door_I);
		}
	}

	int window_I;
	for (window_I = 0; window_I < 4; window_I++)
	{
		if (window_notintact[window_I] == 1)
		{
			REMOVE_CAR_WINDOW(v_modding, window_I);
		}
	}
	CLEAR_AREA_OF_OBJECTS(spawn_x, spawn_y, spawn_z, 5.0000);

	//FREEZE_CAR_POSITION(v_modding, 1);
	//LOCK_CAR_DOORS(v_modding, 4);

}

void LocateVehicle(float warp_x, float warp_y, float warp_z)
{

	if (DOES_VEHICLE_EXIST(v_spawn))
	{
		v_modding = v_spawn;
	}
	else if (IS_CHAR_IN_ANY_CAR(GetPlayerPed()))
	{
		GET_CAR_CHAR_IS_USING(GetPlayerPed(), &v_modding);
	}
	else
	{
		v_modding = GET_CLOSEST_CAR(warp_x, warp_y, warp_z, 6.00000000, 0, 70);
		if (!DOES_VEHICLE_EXIST(v_modding))
		{
			v_modding = GET_CLOSEST_CAR(warp_x, warp_y, warp_z, 6.00000000, 0, 69);
		}
		if (!DOES_VEHICLE_EXIST(v_modding))
		{
			v_modding = GET_CLOSEST_CAR(warp_x, warp_y, warp_z, 6.00000000, 0, 71);
		}
	}

}

void FixWashCar(float warp_x, float warp_y, float warp_z, float warp_h)
{

	LocateVehicle(warp_x, warp_y, warp_z);

	if (DOES_VEHICLE_EXIST(v_modding))
	{
		FIX_CAR(v_modding);
		SET_CAR_HEADING(v_modding, warp_h);
		SET_CAR_COORDINATES(v_modding, warp_x, warp_y, warp_z);
		SET_CAR_ON_GROUND_PROPERLY(v_modding);

		SET_VEHICLE_DIRT_LEVEL(v_modding, 0);
		WASH_VEHICLE_TEXTURES(v_modding, 255);
		menu_level = 2;
		item_selected = 0;
		PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Your vehicle has been fixed and cleaned.", 2500, 1);
	}
	else
	{
		G_item_highlighted[23] = 1;
		item_selected = 0;
		menu_level = 2;
		PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Unable to locate a vehicle.", 2500, 1);
	}

}

bool JumpToVehicle(float warp_x, float warp_y, float warp_z, float warp_h, bool delaysetground)
{
	SET_CAMERA_CONTROLS_DISABLED_WITH_PLAYER_CONTROLS(0);

	LocateVehicle(warp_x, warp_y, warp_z);
	
	if (DOES_VEHICLE_EXIST(v_modding))
	{
		SET_HAS_BEEN_OWNED_BY_PLAYER(v_modding, true);
		SET_NEEDS_TO_BE_HOTWIRED(v_modding, false);

		SET_CAR_HEADING(v_modding, warp_h);
		SET_CAR_COORDINATES(v_modding, warp_x, warp_y, warp_z);
		WARP_CHAR_INTO_CAR(GetPlayerPed(), v_modding);

		FREEZE_CAR_POSITION(v_modding, 1);
		LOCK_CAR_DOORS(v_modding, 4);

		if (!veh_cam_set)
		{
			//SET_CAM_IN_FRONT_OF_PED(GetPlayerPed());
			SET_GAME_CAM_HEADING(227.0000);
			//SET_GAME_CAM_PITCH(5.0000);
			veh_cam_set = true;
		}

		if (delaysetground)
		{
			WAIT(1000);
		}
		SET_CAR_ON_GROUND_PROPERLY(v_modding);
		return true;
	}
	else
	{
		G_item_highlighted[23] = 1;
		item_selected = 0;
		menu_level = 2;
		PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Unable to locate a vehicle.", 2500, 1);
		return false;
	}
}

void JumpOutVehicle(float warp_x, float warp_y, float warp_z)
{
	if (DOES_VEHICLE_EXIST(v_modding))
	{
		FREEZE_CAR_POSITION(v_modding, 0);
		LOCK_CAR_DOORS(v_modding, 1);
		if (warp_x != spawn_x && warp_y != spawn_y && warp_z != spawn_z)
		{
			WARP_CHAR_FROM_CAR_TO_COORD(GetPlayerPed(), warp_x, warp_y, warp_z);
			SET_CHAR_COORDINATES_NO_OFFSET(GetPlayerPed(), warp_x, warp_y, warp_z);
		}
		menu_cam_set = false;
		veh_cam_set = false;
	}
}

void set_up_draw(int type, float width, float height, uint r, uint g, uint b, uint a)
{

	SET_TEXT_FONT(0);

	SET_TEXT_BACKGROUND(0);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 255);
	SET_TEXT_EDGE(0, 0, 0, 0, 255);

	if (type == 1)
	{
		SET_TEXT_BACKGROUND(1);
	}
	else if (type == 2)
	{
		SET_TEXT_DROPSHADOW(1, 0, 0, 0, 255);
	}
	else if (type == 3)
	{
		SET_TEXT_EDGE(1, 0, 0, 0, 255);
	}

	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_SCALE(width, height);
	SET_TEXT_PROPORTIONAL(1);

	SET_TEXT_JUSTIFY(0);
	SET_TEXT_CENTRE(0);
	SET_TEXT_RIGHT_JUSTIFY(0);

}

void draw_text(char *gxtName, float x, float y, char *val)
{
	DISPLAY_TEXT_WITH_LITERAL_STRING(x, y, gxtName, val);
}

void draw_number(char *gxtName, float x, float y, int val)
{
	DISPLAY_TEXT_WITH_NUMBER(x, y, gxtName, val);
}

void draw_float(char *gxtName, float x, float y, float val, uint dp)
{
	DISPLAY_TEXT_WITH_FLOAT(x, y, gxtName, val, dp);
}