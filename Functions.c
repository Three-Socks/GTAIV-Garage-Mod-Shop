void FixWashCar(void)
{

	v_modding = GET_CLOSEST_CAR(874.81200000, -114.20310000, 5.61220000, 6.00000000, 0, 70);
	if (!DOES_VEHICLE_EXIST(v_modding))
	{
		v_modding = GET_CLOSEST_CAR(874.81200000, -114.20310000, 5.61220000, 6.00000000, 0, 69);
	}
	if (!DOES_VEHICLE_EXIST(v_modding))
	{
		v_modding = GET_CLOSEST_CAR(874.81200000, -114.20310000, 5.61220000, 6.00000000, 0, 71);
	}

	if (DOES_VEHICLE_EXIST(v_modding))
	{
		FIX_CAR(v_modding);
		SET_CAR_HEADING(v_modding, 179.56390000);
		SET_CAR_COORDINATES(v_modding, 874.81200000, -114.20310000, 5.61220000);
		SET_CAR_ON_GROUND_PROPERLY(v_modding);

		SET_VEHICLE_DIRT_LEVEL(v_modding, 0);
		WASH_VEHICLE_TEXTURES(v_modding, 255);
		menu_level = 2;
		item_selected = 0;
		PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Your Vehicle has been fixed and cleaned.", 7500, 1);
	}
	else
	{
		item_highlighted = 1;
		item_selected = 0;
		menu_level = 2;
		PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Unable to locate a vehicle in the garage. Place it in the metal strip near the window.", 7500, 1);
	}

}

bool JumpToVehicle(void)
{
	SET_CAMERA_CONTROLS_DISABLED_WITH_PLAYER_CONTROLS(0);

	v_modding = GET_CLOSEST_CAR(874.81200000, -114.20310000, 5.61220000, 6.00000000, 0, 70);
	if (!DOES_VEHICLE_EXIST(v_modding))
	{
		v_modding = GET_CLOSEST_CAR(874.81200000, -114.20310000, 5.61220000, 6.00000000, 0, 69);
	}
	if (!DOES_VEHICLE_EXIST(v_modding))
	{
		v_modding = GET_CLOSEST_CAR(874.81200000, -114.20310000, 5.61220000, 6.00000000, 0, 71);
	}

	if (DOES_VEHICLE_EXIST(v_modding))
	{
		inModVeh = true;
		SET_CAR_HEADING(v_modding, 179.56390000);
		SET_CAR_COORDINATES(v_modding, 874.81200000, -114.20310000, 5.61220000);
		SET_CAR_ON_GROUND_PROPERLY(v_modding);
		FREEZE_CAR_POSITION(v_modding, 1);

		WARP_CHAR_INTO_CAR(GetPlayerPed(), v_modding);
		LOCK_CAR_DOORS(v_modding, 4);
		return true;
	}
	else
	{
		item_highlighted = 1;
		item_selected = 0;
		menu_level = 2;
		PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Unable to locate a vehicle in the garage. Place it in the metal strip near the window.", 7500, 1);
		return false;
	}
}

void PlayAsBrucie(void)
{
	REQUEST_MODEL(MODEL_IG_BRUCIE);
	while (!HAS_MODEL_LOADED(MODEL_IG_BRUCIE)) WAIT(0);
	CHANGE_PLAYER_MODEL(GetPlayerIndex(), MODEL_IG_BRUCIE);
	MARK_MODEL_AS_NO_LONGER_NEEDED(MODEL_IG_BRUCIE);
	SET_CHAR_COMPONENT_VARIATION(GetPlayerPed(), 0, 0, 0 );
	SET_CHAR_COMPONENT_VARIATION(GetPlayerPed(), 1, 1, 0 );
	SET_CHAR_COMPONENT_VARIATION(GetPlayerPed(), 2, 0, 0 );
	SET_CHAR_COMPONENT_VARIATION(GetPlayerPed(), 5, 0, 0 );
	SET_CHAR_COMPONENT_VARIATION(GetPlayerPed(), 4, 0, 0 );
	SET_CHAR_COMPONENT_VARIATION(GetPlayerPed(), 3, 0, 0 );
	SET_CHAR_COMPONENT_VARIATION(GetPlayerPed(), 7, 0, 0 );

	SET_LOCAL_PLAYER_VOICE("BRUCIE");
	SET_LOCAL_PLAYER_PAIN_VOICE("BRUCIE");
	FORCE_FULL_VOICE(GetPlayerPed());

	return;
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

void draw_float(char *gxtName, float x, float y, float val)
{
	DISPLAY_TEXT_WITH_FLOAT(x, y, gxtName, val, 4);
}