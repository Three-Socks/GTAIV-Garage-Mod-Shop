void DrawPalette(void)
{
	int I;
	int rows = 0;
	float Ipos_x = 0.05400000;
	float Ipos_y = 0.06350000;
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
		float pos_x = 0.05700000, num_pos_x = 0.12800000, onoff_pos_x = 0.20000000, width = 0.30000000, height = 0.30000000;
		uint r, g, b, a = 255;

		int I;
		float Ipos_y = 0.02000000;

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
	
		char *veh_doors[16];
		veh_doors[10] = "Left Front Door";
		veh_doors[11] = "Right Front Door";
		veh_doors[12] = "Left Rear Door";
		veh_doors[13] = "Right Rear Door";
		veh_doors[14] = "Hood";
		veh_doors[15] = "Trunk";

		Ipos_y = 0.38000000;

		for (I = 10; I < 16; I++)
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
			draw_text("STRING", pos_x, Ipos_y, veh_doors[I]);
			if (IS_CAR_DOOR_FULLY_OPEN(v_modding, I - 10))
			{
				set_up_draw(0, width, height, 233, 162, 0, a);
				draw_text("STRING", onoff_pos_x, Ipos_y, "Open");
			}
			else
			{
				set_up_draw(0, width, height, 255, 255, 255, a);
				draw_text("STRING", onoff_pos_x, Ipos_y, "Closed");
			}
		}
	
	}
	else
	{
		float pos_x = 0.05700000, width = 0.30000000, height = 0.30000000;
		uint r, g, b, a = 255;
		int I;
		float Ipos_y = 0.02000000;

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
			if (inVehMenu)
			{
				draw_text("STRING", pos_x, Ipos_y, GET_STRING_FROM_TEXT_FILE(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(spawn_cars[I])));
			}
			else
			{
				draw_text("STRING", pos_x, Ipos_y, menu_items[I]);
			}
		}
	}
}

void ExitMenu(void)
{
	spawn_x = 874.81200000; spawn_y = -114.20310000; spawn_z = 5.61220000; spawn_h = 180.0;
	exit_x = 869.01190000; exit_y = -114.65010000; exit_z = 5.50540000; exit_h = 270.00000000;
	item_highlighted = 1;
	item_selected = 0;
	menu_level = 2;
	menu_cam_set = false;
	G_activateMenu = false;
	G_scriptloaded = false;

	SET_PLAYER_CONTROL(GetPlayerIndex(), true);
	SET_CAMERA_CONTROLS_DISABLED_WITH_PLAYER_CONTROLS(0);

	SET_CHAR_COORDINATES_NO_OFFSET(GetPlayerPed(), quit_x, quit_y, quit_z);
	SET_CHAR_HEADING(GetPlayerPed(), quit_h);

	TERMINATE_THIS_SCRIPT();

}

void EnterMenu(int item_selected)
{
	if (menu_level == 2)
	{
		menu_items[1] = "Spawn a Vehicle";
		menu_items[2] = "Upgrade Vehicle";
		menu_items[3] = "Fix & Wash vehicle";
		menu_items[4] = "Change Vehicle Color";
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
			menu_items[3] = "Two-Doors";
			menu_items[4] = "Four-Door";
			menu_items[5] = "...Four-Door";
			menu_items[6] = "SUVs, Pick-ups & Vans";
			menu_items[7] = "Commercial/Industrial";
			menu_items[8] = "...Commercial/Industrial";
			menu_items[9] = "Emergency";
			menu_items[10] = "Public Service";
			menu_items[11] = "Motorcycles";
			menu_items[12] = "Boats";
			menu_items[13] = "Aircraft";
			menu_len = 13;
			menu_level = 4;
			inVehSpawn = true;
			return;
		}
		else if (item_selected == 2)
		{
			if (JumpToVehicle(spawn_x, spawn_y, spawn_z, spawn_h))
			{
				menu_len = 15;
				inVehUpgrade = true;
				item_highlighted = 1;
				menu_level = 5;
			}
			return;
		}
		else if (item_selected == 3)
		{
			FixWashCar(spawn_x, spawn_y, spawn_z, spawn_h);
			menu_level = 2;
			return;
		}
		else if (item_selected == 4)
		{
			if (JumpToVehicle(spawn_x, spawn_y, spawn_z, spawn_h))
			{
				menu_items[1] = "Color 1";
				menu_items[2] = "Color 2";
				menu_items[3] = "Specular Color 1";
				menu_items[4] = "Specular Color 2";
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
		if (inVehSpawn && item_vehcat_selected != 0)
		{
			if (item_vehcat_selected == 1)
			{
				spawn_cars[1] = MODEL_BANSHEE;
				spawn_cars[2] = MODEL_COMET;
				spawn_cars[3] = MODEL_COQUETTE;
				spawn_cars[4] = MODEL_FELTZER;
				spawn_cars[5] = MODEL_INFERNUS;
				spawn_cars[6] = MODEL_SULTAN;
				spawn_cars[7] = MODEL_SULTANRS;
				spawn_cars[8] = MODEL_SUPERGT;
				spawn_cars[9] = MODEL_TURISMO;
				menu_len = 9;
			}
			else if(item_vehcat_selected == 2)
			{
				spawn_cars[1] = MODEL_BUCCANEER;
				spawn_cars[2] = MODEL_DUKES;
				spawn_cars[3] = MODEL_FACTION;
				spawn_cars[4] = MODEL_MANANA;
				spawn_cars[5] = MODEL_PEYOTE;
				spawn_cars[6] = MODEL_RUINER;
				spawn_cars[7] = MODEL_SABRE;
				spawn_cars[8] = MODEL_SABREGT;
				spawn_cars[9] = MODEL_STALION;
				spawn_cars[10] = MODEL_VIGERO;
				spawn_cars[11] = MODEL_VIRGO;
				spawn_cars[12] = MODEL_VOODOO;
				menu_len = 12;
			}
			else if(item_vehcat_selected == 3)
			{
				spawn_cars[1] = MODEL_BLISTA;
				spawn_cars[2] = MODEL_FORTUNE;
				spawn_cars[3] = MODEL_FUTO;
				spawn_cars[4] = MODEL_SENTINEL;
				spawn_cars[5] = MODEL_URANUS;
				menu_len = 5;
			}
			else if(item_vehcat_selected == 4)
			{
				spawn_cars[1] = MODEL_ADMIRAL;
				spawn_cars[2] = MODEL_CHAVOS;
				spawn_cars[3] = MODEL_COGNOSCENTI;
				spawn_cars[4] = MODEL_DF8;
				spawn_cars[5] = MODEL_DILETTANTE;
				spawn_cars[6] = MODEL_EMPEROR;
				spawn_cars[7] = MODEL_ESPERANTO;
				spawn_cars[8] = MODEL_FEROCI;
				spawn_cars[9] = MODEL_HAKUMAI;
				spawn_cars[10] = MODEL_INGOT;
				spawn_cars[11] = MODEL_INTRUDER;
				spawn_cars[12] = MODEL_LOKUS;
				spawn_cars[13] = MODEL_MARBELLA;
				spawn_cars[14] = MODEL_MERIT;
				menu_len = 14;
			}
			else if(item_vehcat_selected == 5)
			{
				spawn_cars[1] = MODEL_ORACLE;
				spawn_cars[2] = MODEL_PINNACLE;
				spawn_cars[3] = MODEL_PMP600;
				spawn_cars[4] = MODEL_PREMIER;
				spawn_cars[5] = MODEL_PRES;
				spawn_cars[6] = MODEL_PRIMO;
				spawn_cars[7] = MODEL_ROM;
				spawn_cars[8] = MODEL_SCHAFTER;
				spawn_cars[9] = MODEL_SOLAIR;
				spawn_cars[10] = MODEL_STRATUM;
				spawn_cars[11] = MODEL_STRETCH;
				spawn_cars[12] = MODEL_VINCENT;
				spawn_cars[13] = MODEL_WASHINGTON;
				spawn_cars[14] = MODEL_WILLARD;
				menu_len = 14;
			}
			else if(item_vehcat_selected == 6)
			{
				spawn_cars[1] = MODEL_BOBCAT;
				spawn_cars[2] = MODEL_CAVALCADE;
				spawn_cars[3] = MODEL_FXT;
				spawn_cars[4] = MODEL_E109;
				spawn_cars[5] = MODEL_HABANERO;
				spawn_cars[6] = MODEL_HUNTLEY;
				spawn_cars[7] = MODEL_LANDSTALKER;
				spawn_cars[8] = MODEL_MINIVAN;
				spawn_cars[9] = MODEL_MOONBEAM;
				spawn_cars[10] = MODEL_PATRIOT;
				spawn_cars[11] = MODEL_PERENNIAL;
				spawn_cars[12] = MODEL_RANCHER;
				spawn_cars[13] = MODEL_REBLA;
				menu_len = 13;
			}
			else if(item_vehcat_selected == 7)
			{
				spawn_cars[1] = MODEL_AIRTUG;
				spawn_cars[2] = MODEL_BENSON;
				spawn_cars[3] = MODEL_BIFF;
				spawn_cars[4] = MODEL_BOXVILLE;
				spawn_cars[5] = MODEL_BURRITO;
				spawn_cars[6] = MODEL_BIFF;
				spawn_cars[7] = MODEL_BOXVILLE;
				spawn_cars[8] = MODEL_BURRITO;
				spawn_cars[9] = MODEL_FLATBED;
				spawn_cars[10] = MODEL_FEROCI2;
				spawn_cars[11] = MODEL_PERENNIAL2;
				spawn_cars[12] = MODEL_FORKLIFT;
				menu_len = 12;
			}
			else if(item_vehcat_selected == 8)
			{
				spawn_cars[1] = MODEL_BURRITO2;
				spawn_cars[2] = MODEL_MRTASTY;
				spawn_cars[3] = MODEL_MULE;
				spawn_cars[4] = MODEL_PACKER;
				spawn_cars[5] = MODEL_PHANTOM;
				spawn_cars[6] = MODEL_PONY;
				spawn_cars[7] = MODEL_RIPLEY;
				spawn_cars[8] = MODEL_STOCKADE;
				spawn_cars[9] = MODEL_SPEEDO;
				spawn_cars[10] = MODEL_STEED;
				spawn_cars[11] = MODEL_YANKEE;
				menu_len = 11;
			}
			else if(item_vehcat_selected == 9)
			{
				spawn_cars[1] = MODEL_AMBULANCE;
				spawn_cars[2] = MODEL_NSTOCKADE;
				spawn_cars[3] = MODEL_FBI;
				spawn_cars[4] = MODEL_FIRETRUK;
				spawn_cars[5] = MODEL_NOOSE;
				spawn_cars[6] = MODEL_POLPATRIOT;
				spawn_cars[7] = MODEL_POLICE;
				spawn_cars[8] = MODEL_POLICE2;
				spawn_cars[9] = MODEL_PSTOCKADE;
				menu_len = 9;
			}
			else if(item_vehcat_selected == 10)
			{
				spawn_cars[1] = MODEL_BUS;
				spawn_cars[2] = MODEL_CABBY;
				spawn_cars[3] = MODEL_ROMERO;
				spawn_cars[4] = MODEL_TAXI;
				spawn_cars[5] = MODEL_TAXI2;
				spawn_cars[6] = MODEL_TRASH;
				menu_len = 6;
			}
			else if(item_vehcat_selected == 11)
			{
				spawn_cars[1] = MODEL_FAGGIO;
				spawn_cars[2] = MODEL_BOBBER;
				spawn_cars[3] = MODEL_HELLFURY;
				spawn_cars[4] = MODEL_NRG900;
				spawn_cars[5] = MODEL_PCJ;
				spawn_cars[6] = MODEL_SANCHEZ;
				spawn_cars[7] = MODEL_ZOMBIEB;
				menu_len = 7;
			}
			else if(item_vehcat_selected == 12)
			{
				spawn_cars[1] = MODEL_DINGHY;
				spawn_cars[2] = MODEL_JETMAX;
				spawn_cars[3] = MODEL_MARQUIS;
				spawn_cars[4] = MODEL_PREDATOR;
				spawn_cars[5] = MODEL_REEFER;
				spawn_cars[6] = MODEL_SQUALO;
				spawn_cars[7] = MODEL_TROPIC;
				spawn_cars[8] = MODEL_TUGA;
				menu_len = 8;
			}
			else if(item_vehcat_selected == 13)
			{
				spawn_cars[1] = MODEL_ANNIHILATOR;
				spawn_cars[2] = MODEL_TOURMAV;
				spawn_cars[3] = MODEL_MAVERICK;
				spawn_cars[4] = MODEL_POLMAV;
				menu_len = 4;
			}
			inVehMenu = true;
		}

		if (!veh_change_set && (DOES_VEHICLE_EXIST(v_modding) || inVehMenu))
		{
			if (inVehMenu && item_vehspawn_selected != 0)
			{
				if (DOES_VEHICLE_EXIST(v_spawn))
				{
					DELETE_CAR(&v_spawn);
				}
				REQUEST_MODEL(spawn_cars[item_vehspawn_selected]);
				while (!HAS_MODEL_LOADED(spawn_cars[item_vehspawn_selected])) WAIT(0);
				SUPPRESS_CAR_MODEL(spawn_cars[item_vehspawn_selected]);

				// Garage
				exit_x = 869.01190000; exit_y = -114.65010000; exit_z = 5.50540000; exit_h = 270.00000000;
				quit_x = 866.33090000; quit_y = -116.70250000; quit_z = 6.00540000; quit_h = 181.00000000;
				spawn_x = 874.81200000; spawn_y = -114.20310000; spawn_z = 5.61220000; spawn_h = 180.0;
				bool placeauto = false;

				if (item_vehcat_selected == 7 || item_vehcat_selected == 8)
				{
					// Warehouse
					exit_x = 799.87080000; exit_y = -161.98190000; exit_z = 6.12140000; exit_h = 291.45250000;
					quit_x = 799.87080000; quit_y = -161.98190000; quit_z = 6.12140000; quit_h = 291.45250000;
					spawn_x = 807.7111; spawn_y = -161.0524; spawn_z = 6.4449; spawn_h = 335.8888, placeauto = false;
				}
				else if (item_vehcat_selected == 12)
				{
					// Jetty
					exit_x = 696.34010000; exit_y = -147.73820000; exit_z = 1.48330000; exit_h = 154.97670000;
					quit_x = 696.34010000; quit_y = -147.73820000; quit_z = 1.48330000; quit_h = 154.97670000;
					spawn_x = 698.8500; spawn_y = -153.6000; spawn_z = 0.0000; spawn_h = 61.3000, placeauto = false;
				}
				else if(item_vehcat_selected == 13)
				{
					// Helipad
					exit_x = 778.40660000, exit_y = 152.24480000, exit_z = 27.83940000, exit_h = 268.0;
					quit_x = 778.40660000, quit_y = 152.24480000, quit_z = 27.83940000, quit_h = 268.0;
					spawn_x = 786.53470000; spawn_y = 150.74470000; spawn_z = 27.74790000; spawn_h = 180.0000, placeauto = true;
				}

				CREATE_CAR(spawn_cars[item_vehspawn_selected], spawn_x, spawn_y, spawn_z, &v_spawn, placeauto);
				SET_HAS_BEEN_OWNED_BY_PLAYER(v_spawn, TRUE);
				SET_NEEDS_TO_BE_HOTWIRED(v_spawn, FALSE);
				SET_CAR_HEADING(v_spawn, spawn_h);
				SET_CAR_COORDINATES(v_spawn, spawn_x, spawn_y, spawn_z);
				SET_CAR_ON_GROUND_PROPERLY(v_spawn);
				MARK_MODEL_AS_NO_LONGER_NEEDED(spawn_cars[item_vehspawn_selected]);
				JumpToVehicle(spawn_x, spawn_y, spawn_z, spawn_h);
			}
			else if (inVehUpgrade && item_up_selected != 0)
			{
				if (item_up_selected <= 9)
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
				else
				{
					if (IS_CAR_DOOR_FULLY_OPEN(v_modding, item_up_selected - 10))
					{
						SHUT_CAR_DOOR(v_modding, item_up_selected - 10);
					}
					else
					{
						OPEN_CAR_DOOR(v_modding, item_up_selected - 10);
					}
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
	/*
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
	if (inVehSpawn)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.40800000, "inVehSpawn");
	}
	if (inVehMenu)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.44800000, "inVehMenu");
	}
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.48800000, item_vehcat_selected);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.51800000, item_vehspawn_selected);
	*/
	
	HIDE_HUD_AND_RADAR_THIS_FRAME();
	DRAW_RECT(0.15000000, 0.35000000, 0.23000000, 0.63000000, 0, 0, 0, 230);

	if (!menu_cam_set)
	{
		SET_CHAR_HEADING(GetPlayerPed(), exit_h);
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
				WARP_CHAR_FROM_CAR_TO_COORD(GetPlayerPed(), exit_x, exit_y, exit_z);
				menu_cam_set = false;
			}
		}
		else if (menu_level == 4)
		{
			menu_level = 3;
			if (inVehSpawn)
			{
				menu_level = 2;
				inVehSpawn = false;
			}
			if (inVehCol)
			{
				menu_level = 2;
				inVehCol = false;
				if (inModVeh)
				{
					inModVeh = false;
					FREEZE_CAR_POSITION(v_modding, 0);
					LOCK_CAR_DOORS(v_modding, 1);
					WARP_CHAR_FROM_CAR_TO_COORD(GetPlayerPed(), exit_x, exit_y, exit_z);
					menu_cam_set = false;
				}
			}
		}
		else if (menu_level == 5)
		{
			menu_level = 4;
			if (inVehMenu)
			{
				menu_level = 3;
				item_selected = 1;
				menu_len = 13;
				item_vehcat_selected = 0;
				item_vehspawn_selected = 0;
				inVehMenu = false;
				veh_change_set = false;
				if (inModVeh)
				{
					inModVeh = false;
					FREEZE_CAR_POSITION(v_spawn, 0);
					LOCK_CAR_DOORS(v_spawn, 1);
					WARP_CHAR_FROM_CAR_TO_COORD(GetPlayerPed(), exit_x, exit_y, exit_z);
					menu_cam_set = false;
				}
			}
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
					WARP_CHAR_FROM_CAR_TO_COORD(GetPlayerPed(), exit_x, exit_y, exit_z);
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
		if (inVehMenu && item_vehcat_selected != 0)
		{
			item_vehspawn_selected = item_highlighted;
			veh_change_set = false;
		}
		else if (inVehCol && item_colnum_selected != 0)
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
			if (inVehSpawn)
			{
				item_vehcat_selected = item_highlighted;
				item_highlighted = 1;
				menu_level = 5;
			}
			else if (inVehCol)
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