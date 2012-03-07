void DrawPalette(void)
{
	int I;
	int rows = 0;
	float Ipos_x = 0.05400000;
	float Ipos_y = 0.06800000;
	uint r, g, b, a;

	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_LEFT) && item_highlighted != 1)
	{
		item_highlighted = item_highlighted - 1;
	}

	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_RIGHT) && item_highlighted != 133)
	{
		item_highlighted = item_highlighted + 1;
	}

	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_UP))
	{
		if (item_highlighted > 6)
			item_highlighted = item_highlighted - 7;
	}

	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_DOWN))
	{
		if (item_highlighted < 127)
			item_highlighted = item_highlighted + 7;
	}

	for (I = 1; I < 134; I++)
	{
		r = car_colours[I].r, g = car_colours[I].g, b = car_colours[I].b, a = 255;

		if (I != 1)
		{
			Ipos_x = Ipos_x + 0.03200000;
			if (rows == 7)
			{
				Ipos_x = 0.05400000;
				Ipos_y = Ipos_y + 0.03200000;
				rows = 0;
			}
		}

		if (item_highlighted == I)
		{
			DRAW_RECT(Ipos_x, Ipos_y, 0.03300000, 0.03300000, 255, 255, 255, a);
		}

		rows++;

		DRAW_RECT(Ipos_x, Ipos_y, 0.02900000, 0.02900000, r, g, b, a);

	}

}

void DrawMenu(int array_len)
{
	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_DOWN))
	{
		if (item_highlighted == array_len)
		{
			item_highlighted = 1;
		}
		else
		{
			item_highlighted++;
		}
	}

	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_UP))
	{
		if (item_highlighted == 1)
		{
			item_highlighted = array_len;
		}
		else
		{
			item_highlighted--;
		}
	}

	if (inVehUpgrade)
	{
		float pos_x = 0.05700000, num_pos_x = 0.13500000, onoff_pos_x = 0.20000000, width = 0.30000000, height = 0.30000000;
		uint r, g, b, a = 255;

		int I;
		float Ipos_y = 0.04800000;

		for (I = 0; I < 10; I++)
		{
			if (I > 0)
			{
				r = 255;
				g = 255;
				b = 255;
				Ipos_y = Ipos_y + 0.04000000;

				if (item_highlighted == I)
				{
					r = 253;
					g = 160;
					b = 35;
				}

				if (IS_VEHICLE_EXTRA_TURNED_ON(v_modding, I))
				{
					set_up_draw(0, width, height, r, g, b, a);
					draw_text("STRING", pos_x, Ipos_y, "Upgrade");
					set_up_draw(0, width, height, r, g, b, a);
					draw_number("NUMBR", num_pos_x, Ipos_y, I);
					set_up_draw(0, width, height, 233, 162, 0, a);
					draw_text("STRING", onoff_pos_x, Ipos_y, "On");
				}
				else
				{
					set_up_draw(0, width, height, r, g, b, a);
					draw_text("STRING", pos_x, Ipos_y, "Upgrade");
					set_up_draw(0, width, height, r, g, b, a);
					draw_number("NUMBR", num_pos_x, Ipos_y, I);
					set_up_draw(0, width, height, 255, 255, 255, a);
					draw_text("STRING", onoff_pos_x, Ipos_y, "Off");
				}
			}
		}
	}
	else
	{
		float pos_x = 0.05700000, width = 0.30000000, height = 0.30000000;
		uint r, g, b, a = 255;
		int I;
		float Ipos_y = 0.04800000;

		for (I = 1; I < (array_len + 1); I++)
		{
			r = 255;
			g = 255;
			b = 255;
			Ipos_y = Ipos_y + 0.04000000;

			if (item_highlighted == I)
			{
				r = 253;
				g = 160;
				b = 35;
			}

			set_up_draw(0, width, height, r, g, b, a);
			draw_text("STRING", pos_x, Ipos_y, menu_items[I]);
		}
	}
}

void ExitMenu(void)
{
	item_highlighted = 1;
	item_selected = 0;
	menu_level = 2;
	menu_cam_set = false;
	activateMenu = false;

	PlayAsBrucie();

	SET_PLAYER_CONTROL(GetPlayerIndex(), true);
	SET_CAMERA_CONTROLS_DISABLED_WITH_PLAYER_CONTROLS(0);

	SET_CHAR_COORDINATES_NO_OFFSET(GetPlayerPed(), 866.33090000, -116.70250000, 6.00540000);
	SET_CHAR_HEADING(GetPlayerPed(), 181.0);

}

void EnterMenu(int item_selected)
{
	if (menu_level == 2)
	{
		menu_items[1] = "Spawn a Vehicle";
		menu_items[2] = "Upgrade Vehicle";
		menu_items[3] = "Fix & Wash Car";
		menu_items[4] = "Change Vehicle Colour";
		menu_items[5] = "Exit";
		menu_len = 5;
		return;
	}
	else if (menu_level == 3)
	{
		if (item_selected == 1)
		{
			menu_items[1] = "Sports";
			menu_items[2] = "Muscle and Vintage";
			menu_items[3] = "Two-Doors and Hatchbacks";
			menu_items[4] = "Four-Door Sedans/Saloons";
			menu_items[5] = "SUVs/Crossovers, Pick-ups and Vans";
			menu_items[6] = "Commercial/Industrial";
			menu_items[7] = "Emergency";
			menu_items[8] = "Public Service";
			menu_items[9] = "Motorcycles";
			menu_items[10] = "Boats";
			menu_items[11] = "Aircraft";
			menu_len = 11;
			return;
		}
		else if (item_selected == 2)
		{
			if (JumpToVehicle())
			{
				menu_len = 9;
				inVehUpgrade = true;
				item_highlighted = 1;
				menu_level = 5;
			}
			return;
		}
		else if (item_selected == 3)
		{
			FixWashCar();
			menu_level = 2;
			return;
		}
		else if (item_selected == 4)
		{
			if (JumpToVehicle())
			{
				menu_items[1] = "Colour 1";
				menu_items[2] = "Colour 2";
				menu_items[3] = "Specular Colour 1";
				menu_items[4] = "Specular Colour 2";
				menu_len = 4;
				menu_level = 4;
				item_highlighted = 1;
				inVehCol = true;
			}
			return;
		}
		else if (item_selected == 5)
		{
			ExitMenu();
			return;
		}
		return;
	}
	else if (menu_level == 4)
	{
		return;
	}
	else if (menu_level == 5)
	{
		if (!veh_change_set && DOES_VEHICLE_EXIST(v_modding))
		{
			if (inVehUpgrade && item_up_selected != 0)
			{
				if (IS_VEHICLE_EXTRA_TURNED_ON(v_modding, item_up_selected))
				{
					TURN_OFF_VEHICLE_EXTRA(v_modding, item_up_selected, true);
				}
				else
				{
					TURN_OFF_VEHICLE_EXTRA(v_modding, item_up_selected, false);
				}
			}
			else if (inVehCol)
			{
				if (item_col_selected == 0)
				{
					draw_menu_set = false;
					ColourIndex colour_normal1, colour_normal2, colour_extra1, colour_extra2;
					GET_CAR_COLOURS(v_modding, &colour_normal1, &colour_normal2);
					GET_EXTRA_CAR_COLOURS(v_modding, &colour_extra1, &colour_extra2);

					if (item_colnum_selected == 1)
						item_highlighted = colour_normal1 + 1;
					else if (item_selected == 2)
						item_highlighted = colour_normal2 + 1;
					else if (item_colnum_selected == 3)
						item_highlighted = colour_extra1 + 1;
					else if (item_colnum_selected == 4)
						item_highlighted = colour_extra2 + 1;
				}
				if (item_col_selected != 0 && item_colnum_selected != 0)
				{
					if (item_colnum_selected == 1)
					{
						ColourIndex normal1, normal2;
						GET_CAR_COLOURS(v_modding, &normal1, &normal2);
						CHANGE_CAR_COLOUR(v_modding, item_col_selected - 1, normal2);
					}
					else if (item_colnum_selected == 2)
					{
						ColourIndex normal1, normal2;
						GET_CAR_COLOURS(v_modding, &normal1, &normal2);
						CHANGE_CAR_COLOUR(v_modding, normal1, item_col_selected - 1);
					}
					else if (item_colnum_selected == 3)
					{
						ColourIndex normal1, normal2;
						GET_EXTRA_CAR_COLOURS(v_modding, &normal1, &normal2);
						SET_EXTRA_CAR_COLOURS(v_modding, item_col_selected - 1, normal2);
					}
					else if (item_colnum_selected == 4)
					{
						ColourIndex normal1, normal2;
						GET_EXTRA_CAR_COLOURS(v_modding, &normal1, &normal2);
						SET_EXTRA_CAR_COLOURS(v_modding, normal1, item_col_selected - 1);
					}
					item_col_selected = 0;
				}
			}
			veh_change_set = true;
		}
		return;
	}
}

void DoMenu(void)
{
	// Debug
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.08800000, menu_level);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.12800000, item_highlighted);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.16800000, item_selected);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.20800000, item_col_selected);
	if (inVehUpgrade)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.24800000, "inVehUpgrade");
	}
	if (inVehCol)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.28800000, "inVehCol");
	}
	if (inModVeh)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.32800000, "inModVeh");
	}
	if (veh_change_set)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.36800000, "veh_change_set");
	}

	HIDE_HUD_AND_RADAR_THIS_FRAME();
	DRAW_RECT(0.15000000, 0.35000000, 0.23000000, 0.63000000, 0, 0, 0, 230);

	if (!menu_cam_set)
	{
		SET_CHAR_HEADING(GetPlayerPed(), 270.0);
		SET_CAM_BEHIND_PED(GetPlayerPed());
		SET_PLAYER_CONTROL(GetPlayerIndex(), false);
		SET_CAMERA_CONTROLS_DISABLED_WITH_PLAYER_CONTROLS(1);
		menu_cam_set = true;
	}

	EnterMenu(item_selected);

	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_O))
	{
		item_highlighted = 1;
		item_selected = 0;

		if (menu_level == 3)
		{
			menu_level = 2;
			if (inModVeh)
			{
				inModVeh = false;
				FREEZE_CAR_POSITION(v_modding, 0);
				LOCK_CAR_DOORS(v_modding, 1);
				WARP_CHAR_FROM_CAR_TO_COORD(GetPlayerPed(), 869.01190000, -114.65010000, 6.00540000);
				menu_cam_set = 0;
			}
		}
		else if (menu_level == 4)
		{
			menu_level = 3;
			if (inVehCol)
			{
				menu_level = 2;
				inVehCol = false;
				if (inModVeh)
				{
					inModVeh = false;
					FREEZE_CAR_POSITION(v_modding, 0);
					LOCK_CAR_DOORS(v_modding, 1);
					WARP_CHAR_FROM_CAR_TO_COORD(GetPlayerPed(), 869.01190000, -114.65010000, 6.00540000);
					menu_cam_set = false;
				}
			}
		}
		else if (menu_level == 5)
		{
			menu_level = 4;
			if (inVehUpgrade)
			{
				inVehUpgrade = false;
				menu_level = 2;
				item_up_selected = 0;
				veh_change_set = false;
				if (inModVeh)
				{
					inModVeh = false;
					FREEZE_CAR_POSITION(v_modding, 0);
					LOCK_CAR_DOORS(v_modding, 1);
					WARP_CHAR_FROM_CAR_TO_COORD(GetPlayerPed(), 869.01190000, -114.65010000, 6.00540000);
					menu_cam_set = false;
				}
			}
			if (inVehCol)
			{
				item_col_selected = 0;
				item_colnum_selected = 0;
				veh_change_set = false;
				draw_menu_set = true;
			}
		}
	}

	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_X))
	{
		if (inVehCol && item_colnum_selected != 0)
		{
			item_col_selected = item_highlighted;
			veh_change_set = false;
		}
		else if (inVehUpgrade)
		{
			item_up_selected = item_highlighted;
			veh_change_set = false;
		}
		else
		{
			item_selected = item_highlighted;
		}

		if (menu_level == 2)
		{
			menu_level = 3;
		}
		//else if (menu_level == 3)
		//{
			//menu_level = 4;
		//}
		else if (menu_level == 4)
		{
			if (inVehCol)
			{
				item_colnum_selected = item_highlighted;
				menu_level = 5;
			}
		}
	}

	if (draw_menu_set)
	{
		DrawMenu(menu_len);
	}
	else if (inVehCol)
	{
		DrawPalette();
	}

	// Not sure if it will stop the main while loop.
	//return;
}