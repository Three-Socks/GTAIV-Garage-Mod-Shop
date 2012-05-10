void DrawMenu(int array_len)
{
	uint d_r = 255, d_g = 255, d_b = 255, h_r = 253, h_g = 160, h_b = 35;
	float start_pos_x = 0.0553, toggle_pos_x = 0.1600, menu_spacing = 0.0400, menu_width = 0.3000, menu_height = 0.3000;

	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_DOWN))
	{
		/*if ((inNumberSelector || inFloatSelector) && (num_highlighted > 1 || floatnum_highlighted > 1))
		{
			num_highlighted = 1;
			floatnum_highlighted = 1;
		}*/

		if (G_item_highlighted[23] == array_len)
		{
			G_item_highlighted[23] = 1;
		}
		else
		{
			G_item_highlighted[23]++;
		}
	}

	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_UP))
	{
		/*if ((inNumberSelector || inFloatSelector) && (num_highlighted > 1 || floatnum_highlighted > 1))
		{
			num_highlighted = 1;
			floatnum_highlighted = 1;
		}*/

		if (G_item_highlighted[23] == 1)
		{
			G_item_highlighted[23] = array_len;
		}
		else
		{
			G_item_highlighted[23]--;
		}
	}
	
	if (menu_item[item_high].type == 3 || menu_item[item_high].type == 4)
	{
		if (isNumSelPressed(1))
		{
			if (menu_item[item_high].type == 3)
			{
				if (menu_item[item_high].dfval == 1.0 && !menu_item[item_high].allow_neg)
				{
					menu_item[item_high].dfval = menu_item[item_high].num_len;
				}
				else
				{
					menu_item[item_high].dfval = menu_item[item_high].dfval - 0.100;
				}
			}
			else
			{
				if (menu_item[item_high].numval == 1)
				{
					menu_item[item_high].numval = menu_item[item_high].num_len;
				}
				else
				{
					menu_item[item_high].numval = menu_item[item_high].numval - 1;
				}
			}
		}

		if (isNumSelPressed(2))
		{
			if (menu_item[item_high].type == 3)
			{
				if (menu_item[item_high].dfval == menu_item[item_high].num_len)
				{
					menu_item[item_high].dfval = 1.0;
				}
				else
				{
					menu_item[item_high].dfval = menu_item[item_high].dfval + 0.100;
				}
			}
			else
			{
				if (menu_item[item_high].numval == menu_item[item_high].num_len)
				{
					menu_item[item_high].numval = 1;
				}
				else
				{
					menu_item[item_high].numval = menu_item[item_high].numval + 1;
				}
			}
		}
	}

	if (inVehUpgrade)
	{
		float num_pos_x = 0.1280, onoff_pos_x = 0.2000;
		uint r, g, b, a = 255;

		int I;
		float Ipos_y = 0.0200;

		for (I = 0; I < 10; I++)
		{
			if (I > 0)
			{
				r = d_r;
				g = d_g;
				b = d_b;
				Ipos_y = Ipos_y + menu_spacing;

				if (G_item_highlighted[23] == I)
				{
					r =  h_r;
					g =  h_g;
					b =  h_b;
				}

				if (IS_VEHICLE_EXTRA_TURNED_ON(v_modding, I))
				{
					set_up_draw(0, menu_width, menu_height, r, g, b, a);
					draw_text("STRING", start_pos_x, Ipos_y, "Upgrade");
					set_up_draw(0, menu_width, menu_height, r, g, b, a);
					draw_number("NUMBR", num_pos_x, Ipos_y, I);
					set_up_draw(0, menu_width, menu_height, h_r, h_g, h_b, a);
					draw_text("STRING", onoff_pos_x, Ipos_y, "On");
				}
				else
				{
					set_up_draw(0, menu_width, menu_height, r, g, b, a);
					draw_text("STRING", start_pos_x, Ipos_y, "Upgrade");
					set_up_draw(0, menu_width, menu_height, r, g, b, a);
					draw_number("NUMBR", num_pos_x, Ipos_y, I);
					set_up_draw(0, menu_width, menu_height, d_r, d_g, d_b, a);
					draw_text("STRING", onoff_pos_x, Ipos_y, "Off");
				}
			}
		}	
	}
	else if (inVModifyDoors)
	{
		uint r, g, b, a = 255;

		int I;
		float Ipos_y = 0.0200;
	
		char *veh_doors[8];
		veh_doors[1] = "Mode:";
		veh_doors[2] = "Left Front";
		veh_doors[3] = "Right Front";
		veh_doors[4] = "Left Rear";
		veh_doors[5] = "Right Rear";
		veh_doors[6] = "Hood";
		veh_doors[7] = "Trunk";

		for (I = 1; I < 8; I++)
		{
			r = d_r;
			g = d_g;
			b = d_b;
			Ipos_y = Ipos_y + menu_spacing;

			if (G_item_highlighted[23] == I)
			{
				r =  h_r;
				g =  h_g;
				b =  h_b;
			}

			set_up_draw(0, menu_width, menu_height, r, g, b, a);
			draw_text("STRING", start_pos_x, Ipos_y, veh_doors[I]);

			if (I == 1)
			{
				if (VehModifyMode == 2)
				{
					set_up_draw(0, menu_width, menu_height, h_r, h_g, h_b, a);
					draw_text("STRING", toggle_pos_x, Ipos_y, "Remove");
				}
				else
				{
					set_up_draw(0, menu_width, menu_height, h_r, h_g, h_b, a);
					draw_text("STRING", toggle_pos_x, Ipos_y, "Open");
				}
			}
			else
			{
				if (VehModifyMode == 2)
				{
					if (IS_CAR_DOOR_DAMAGED(v_modding, I - 2))
					{
						set_up_draw(0, menu_width, menu_height, h_r, h_g, h_b, a);
						draw_text("STRING", toggle_pos_x, Ipos_y, "Removed");
					}
				}
				else
				{
					float doorangle2;
					GET_DOOR_ANGLE_RATIO(v_modding, I - 2, &doorangle2);
					if (!IS_CAR_DOOR_DAMAGED(v_modding, I - 2) && doorangle2 >= 0.5000)
					{
						set_up_draw(0, menu_width, menu_height, h_r, h_g, h_b, a);
						draw_text("STRING", toggle_pos_x, Ipos_y, "Open");
					}
					else
					{
						set_up_draw(0, menu_width, menu_height, d_r, d_g, d_b, a);
						draw_text("STRING", toggle_pos_x, Ipos_y, "Closed");
					}
				}
			}

		}

	}
	else if (inVModifyWindows)
	{
		uint r, g, b, a = 255;

		int I;
		float Ipos_y = 0.0200;
	
		char *veh_windows[5];
		veh_windows[1] = "Left Front";
		veh_windows[2] = "Right Front";
		veh_windows[3] = "Left Rear";
		veh_windows[4] = "Right Rear";

		for (I = 1; I < 5; I++)
		{
			r = d_r;
			g = d_g;
			b = d_b;
			Ipos_y = Ipos_y + menu_spacing;

			if (G_item_highlighted[23] == I)
			{
				r = h_r;
				g = h_g;
				b = h_b;
			}

			set_up_draw(0, menu_width, menu_height, r, g, b, a);
			draw_text("STRING", start_pos_x, Ipos_y, veh_windows[I]);

			if (!IS_VEH_WINDOW_INTACT(v_modding, I - 1))
			{
				set_up_draw(0, menu_width, menu_height, h_r, h_g, h_b, a);
				draw_text("STRING", toggle_pos_x, Ipos_y, "Removed");
			}

		}

	}
	else
	{
		uint r, g, b, a = 255;
		int I;
		float Ipos_y = 0.0200;

		for (I = 1; I < (array_len + 1); I++)
		{
			r = d_r;
			g = d_g;
			b = d_b;
			Ipos_y = Ipos_y + menu_spacing;

			if (menu_item[I].type == 3 || menu_item[I].type == 4)
			{
				if (!menu_item[I].allow_neg)
				{
					if (menu_item[I].dfval == 0)
					{
						menu_item[I].dfval = 1;
					}
					else if (menu_item[I].numval == 0)
					{
						menu_item[I].numval = 1;
					}
				}

				if (menu_item[I].type == 3)
				{
					if (menu_item[I].dfval <= -0.0)
					{
						set_up_draw(0, menu_width, menu_height, r, g, b, a);
						draw_text("STRING", 0.2030, Ipos_y - 0.0010, "<");
						set_up_draw(0, menu_width, menu_height, r, g, b, a);
						draw_float("NUMBR", 0.2130, Ipos_y, menu_item[I].dfval, 1);
						set_up_draw(0, menu_width, menu_height, r, g, b, a);
						draw_text("STRING", 0.2450, Ipos_y - 0.0010, ">");
					}
					else
					{
						set_up_draw(0, menu_width, menu_height, r, g, b, a);
						draw_text("STRING", 0.2050, Ipos_y - 0.0010, "<");
						set_up_draw(0, menu_width, menu_height, r, g, b, a);
						draw_float("NUMBR", 0.2200, Ipos_y, menu_item[I].dfval, 1);
						set_up_draw(0, menu_width, menu_height, r, g, b, a);
						draw_text("STRING", 0.2450, Ipos_y - 0.0010, ">");
					}
				}
				else
				{
					float left_pos_x, main_pos_x;

					left_pos_x = 0.2100;
					main_pos_x = 0.2230;

					if (menu_item[I].numval >= 1000)
					{
						left_pos_x = 0.1970;
						main_pos_x = 0.2070;
					}
					else	if (menu_item[I].numval >= 100)
					{
						left_pos_x = 0.2000;
						main_pos_x = 0.2150;
					}
					else if (menu_item[I].numval < 10)
					{
						left_pos_x = 0.2200;
						main_pos_x = 0.2330;
					}

					set_up_draw(0, menu_width, menu_height, r, g, b, a);
					draw_text("STRING", left_pos_x, Ipos_y - 0.0010, "<");
					set_up_draw(0, menu_width, menu_height, r, g, b, a);
					draw_number("NUMBR", main_pos_x, Ipos_y, menu_item[I].numval);
					set_up_draw(0, menu_width, menu_height, r, g, b, a);
					draw_text("STRING", 0.2450, Ipos_y - 0.0010, ">");
				}
			}

			if (G_item_highlighted[23] == I)
			{
				r =  h_r;
				g =  h_g;
				b =  h_b;
			}

			set_up_draw(0, menu_width, menu_height, r, g, b, a);
			if (inVehMenu)
			{
				draw_text("STRING", start_pos_x, Ipos_y, GET_STRING_FROM_TEXT_FILE(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(spawn_cars[I])));
			}
			else if (inVehSaveLoad && item_saveloadtype_selected != 0)
			{
				if (spawn_cars[I] == 0)
				{
					draw_text("STRING", start_pos_x, Ipos_y, "Empty Slot");
				}
				else
				{
					draw_text("STRING", start_pos_x, Ipos_y, GET_STRING_FROM_TEXT_FILE(GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(spawn_cars[I])));
				}
			}
			else
			{
				draw_text("STRING", start_pos_x, Ipos_y, menu_item[I].name);
			}


			if (menu_item[I].type == 2)
			{
				if (menu_item[I].enabled == 2)
				{
					set_up_draw(0, menu_width, menu_height, h_r, h_g, h_b, a);
					draw_text("STRING", toggle_pos_x + 0.0600, Ipos_y, "On");
				}
				else
				{
					set_up_draw(0, menu_width, menu_height, d_r, d_g, d_b, a);
					draw_text("STRING", toggle_pos_x + 0.0600, Ipos_y, "Off");
				}
			}

		}
	}
}

void ExitMenu(void)
{
	G_activateMenu[23] = false;
	G_scriptloaded[23] = false;
	G_justexitmenu[23] = G_garageId[23];

	SET_PLAYER_CONTROL(GetPlayerIndex(), true);
	SET_CAMERA_CONTROLS_DISABLED_WITH_PLAYER_CONTROLS(0);

	SET_CHAR_COORDINATES_NO_OFFSET(GetPlayerPed(), quit_x, quit_y, quit_z);
	SET_CHAR_HEADING(GetPlayerPed(), quit_h);

	if (G_garageId[23] == 6)
	{
		CLEAR_WANTED_LEVEL(GetPlayerIndex());
	}

	TERMINATE_THIS_SCRIPT();
}

void EnterMenu(int item_selected)
{
	if (menu_level == 2)
	{
		menu_item[1].name = "Spawn a Vehicle";
		menu_item[2].name = "Upgrade Vehicle";
		menu_item[3].name = "Modify Vehicle";
		menu_item[4].name = "Fix & Wash Vehicle";
		menu_item[5].name = "Change Vehicle Color";
		menu_item[6].name = "Save/Load Vehicle";
		menu_item[7].name = "Exit";
		menu_len = 7;
		return;
	}
	else if (menu_level == 3)
	{
		if (item_selected == 1)
		{
			menu_item[1].name = "Sports";
			menu_item[2].name = "Muscle and Vintage";
			menu_item[3].name = "Two-Doors";
			menu_item[4].name = "Four-Door";
			menu_item[5].name = "...Four-Door";
			menu_item[6].name = "SUVs, Pick-ups & Vans";
			menu_item[7].name = "Commercial/Industrial";
			menu_item[8].name = "...Commercial/Industrial";
			menu_item[9].name = "Emergency";
			menu_item[10].name = "Public Service";
			menu_item[11].name = "Motorcycles";
			menu_item[12].name = "Boats";
			menu_item[13].name = "Aircraft";
			menu_item[14].name = "Beater";
			if (GET_CURRENT_EPISODE() == 1)
			{
				menu_item[15].name = "The Lost And Damned";
				menu_len = 15;
			}
			else if (GET_CURRENT_EPISODE() == 2)
			{
				menu_item[15].name = "The Ballad of Gay Tony";
				menu_len = 15;
			}
			else
			{
				menu_len = 14;
			}
			menu_level = 4;
			inVehSpawn = true;
			return;
		}
		else if (item_selected == 2)
		{
			if (JumpToVehicle(spawn_x, spawn_y, spawn_z, spawn_h, false))
			{
				menu_len = 9;
				inVehUpgrade = true;
				G_item_highlighted[23] = 1;
				menu_level = 5;
			}
			return;
		}
		else if (item_selected == 3)
		{
			if (JumpToVehicle(spawn_x, spawn_y, spawn_z, spawn_h, false))
			{
				menu_item[1].name = "Doors";
				menu_item[2].name = "Windows";
				menu_item[3].name = "Handling";
				menu_item[4].name = "Lights";
				menu_item[5].name = "Health";
				menu_item[6].name = "Misc";
				menu_item[7].name = "Neon";
				menu_len = 7;
				inVehModify = true;
				G_item_highlighted[23] = 1;
				menu_level = 4;
			}
			return;
		}
		else if (item_selected == 4)
		{
			FixWashCar(spawn_x, spawn_y, spawn_z, spawn_h);
			menu_level = 2;
			return;
		}
		else if (item_selected == 5)
		{
			if (JumpToVehicle(spawn_x, spawn_y, spawn_z, spawn_h, false))
			{
				menu_item[1].name = "Color 1";
				menu_item[2].name = "Color 2";
				menu_item[3].name = "Specular Color 1";
				menu_item[4].name = "Specular Color 2";
				menu_len = 4;

				uint NumColours = 0;
				GET_NUM_CAR_COLOURS(v_modding, &NumColours);
				if (NumColours > 0)
				{
					menu_item[5].name = "Color Variation";
					menu_item[5].type = 4;
					menu_item[5].num_len = NumColours;
					menu_item[5].numval = 1;
					menu_len++;
				}

				//void GET_NUM_CAR_LIVERIES(Car car, int *num);
				menu_item[6].name = "Cycle Livery";
				menu_len++;

				menu_level = 4;
				G_item_highlighted[23] = 1;
				inVehCol = true;
			}
			return;
		}
		else if (item_selected == 6)
		{
			menu_item[1].name = "Save";
			menu_item[2].name = "Load";
			menu_len = 2;
			G_item_highlighted[23] = 1;
			menu_level = 4;
			inVehSaveLoad = true;
			return;
		}
		else if (item_selected == 7)
		{
			ExitMenu();
			return;
		}
		return;
	}
	else if (menu_level == 4)
	{
		if (inVehCol)
		{
			veh_change_set = false;
		}
		return;
	}
	else if (menu_level == 5)
	{
		if (inVehSpawn && !inVehSpawnDLC && item_vehcat_selected != 0)
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
				spawn_cars[6] = MODEL_FLATBED;
				spawn_cars[7] = MODEL_FEROCI2;
				spawn_cars[8] = MODEL_PERENNIAL2;
				spawn_cars[9] = MODEL_FORKLIFT;
				spawn_cars[10] = MODEL_BURRITO2;
				spawn_cars[11] = MODEL_MRTASTY;
				spawn_cars[12] = MODEL_MULE;
				spawn_cars[13] = MODEL_PACKER;
				spawn_cars[14] = MODEL_PHANTOM;
				menu_len = 14;
			}
			else if(item_vehcat_selected == 8)
			{
				spawn_cars[1] = MODEL_PONY;
				spawn_cars[2] = MODEL_RIPLEY;
				spawn_cars[3] = MODEL_STOCKADE;
				spawn_cars[4] = MODEL_SPEEDO;
				spawn_cars[5] = MODEL_STEED;
				spawn_cars[6] = MODEL_YANKEE;
				menu_len = 6;
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
			else if(item_vehcat_selected == 14)
			{
				spawn_cars[1] = MODEL_EMPEROR2;
				spawn_cars[2] = MODEL_SABRE2;
				spawn_cars[3] = MODEL_VIGERO2;
				menu_len = 3;
			}
			else if (item_vehcat_selected == 15 && GET_CURRENT_EPISODE() == 1)
			{
				menu_item[1].name = "Cars";
				menu_item[2].name = "Motorcycles";
				menu_item[3].name = "...Motorcycles";
				menu_len = 3;
				menu_level = 6;
				inVehSpawnDLC = true;
				return;
			}
			else if (item_vehcat_selected == 15 && GET_CURRENT_EPISODE() == 2)
			{
				menu_item[1].name = "Cars";
				menu_item[2].name = "...Cars";
				menu_item[3].name = "Motorcycles";
				menu_item[4].name = "Boats";
				menu_item[5].name = "Aircraft";
				menu_len = 5;
				menu_level = 6;
				inVehSpawnDLC = true;
				return;
			}
			inVehMenu = true;
		}
		else if (inVehModify && item_modifytype_selected != 0)
		{
			if (item_modifytype_selected == 1)
			{
				menu_len = 7;
				inVModifyDoors = true;
			}
			else if (item_modifytype_selected == 2)
			{
				menu_len = 4;
				inVModifyWindows = true;		
			}
			else if (item_modifytype_selected == 3)
			{
				if (!menu_items_set)
				{
					// HANDLING
					//void SET_CAR_FORWARD_SPEED(Vehicle vehicle, float speed);
					menu_item[1].name = "Speed";
					menu_item[1].type = 4;
					menu_item[1].num_len = 100;
					//void SET_VEHICLE_STEER_BIAS(Vehicle veh, float val);
					menu_item[2].name = "Steer Bias";
					menu_item[2].type = 3;
					menu_item[2].num_len = 10;

					menu_len = 2;

					if (GET_CURRENT_EPISODE() == 2)
					{
						//void SET_CAR_TRACTION(Car car, float traction);
						menu_item[3].name = "Traction";
						menu_item[3].type = 3;
						menu_item[3].num_len = 10;
						menu_len = 3;
					}

					inVModifyHandling = true;
					menu_items_set = true;
				}

				veh_change_set = false;
			}
			else if (item_modifytype_selected == 4)
			{
				if (!menu_items_set)
				{
					// LIGHTS
					//void FORCE_CAR_LIGHTS(Car car, int lights);
					menu_item[1].name = "Head Lights";
					menu_item[1].type = 2;
					//void SET_VEH_HAZARDLIGHTS(Vehicle vehicle, boolean on);
					menu_item[2].name = "Hazard Lights";
					menu_item[2].type = 2;
					
					//void SET_VEH_INDICATORLIGHTS(Vehicle veh, boolean set);
					menu_item[3].name = "Indicator Lights";
					menu_item[3].type = 2;
					
					//void SET_VEH_INTERIORLIGHT(Vehicle veh, boolean set);
					menu_item[4].name = "Interior Light";
					menu_item[4].type = 2;
					
					//void SWITCH_CAR_SIREN(Car car, boolean siren);
					menu_item[5].name = "Siren";
					menu_item[5].type = 2;
					bool v_siren = IS_CAR_SIREN_ON(v_modding);
					if (v_siren)
					{
						menu_item[5].enabled = 2;
					}
					
					//void void SET_SIREN_WITH_NO_DRIVER(Car car, boolean set);
					menu_item[6].name = "Always Siren";
					menu_item[6].type = 2;
					
					//void SET_TAXI_LIGHTS(Car car, boolean set);
					menu_item[7].name = "Taxi Light";
					menu_item[7].type = 2;
					bool v_taxi_light = ARE_TAXI_LIGHTS_ON(v_modding);
					if (v_taxi_light)
					{
						menu_item[7].enabled = 2;
					}

					//void SET_CAR_LIGHT_MULTIPLIER(Car car, float multiplier);
					menu_item[8].name = "Light Multiplier";
					menu_item[8].type = 3;
					menu_item[8].num_len = 10;
					menu_len = 8;
					inVModifyLights = true;
					menu_items_set = true;
				}

				veh_change_set = false;
			}
			else if (item_modifytype_selected == 5)
			{
				if (!menu_items_set)
				{
					// HEALTH
					//void SET_CAR_HEALTH(Vehicle vehicle, uint Value);
					menu_item[1].name = "Health";
					menu_item[1].type = 4;
					menu_item[1].num_len = 1000;
					uint v_health;
					GET_CAR_HEALTH(v_modding, &v_health);
					menu_item[1].numval = v_health;
					//void SET_ENGINE_HEALTH(Vehicle vehicle, float health);
					menu_item[2].name = "Engine Health";
					menu_item[2].type = 4;
					menu_item[2].num_len = 1000;
					float v_engine_health = GET_ENGINE_HEALTH(v_modding);
					uint v_numengine_health = FLOOR(v_engine_health);
					menu_item[2].numval = v_numengine_health;
					//void SET_CAR_PROOFS(Vehicle vehicle, boolean bulletProof, boolean fireProof, boolean explosionProof, boolean collisionProof, boolean meleeProof);
					menu_item[3].name = "Bullet Proof";
					menu_item[3].type = 2;
					menu_item[3].extraVar = modifyBulletProof;
					menu_item[4].name = "Fire Proof";
					menu_item[4].type = 2;
					menu_item[4].extraVar = modifyFireProof;
					menu_item[5].name = "Explosion Proof";
					menu_item[5].type = 2;
					menu_item[5].extraVar = modifyExplosionProof;
					menu_item[6].name = "Collision Proof";
					menu_item[6].type = 2;
					menu_item[6].extraVar = modifyCollisionProof;
					menu_item[7].name = "Melee Proof";
					menu_item[7].type = 2;
					menu_item[7].extraVar = modifyMeleeProof;
					//void SET_CAR_STRONG(Vehicle vehicle, boolean strong);
					menu_item[8].name = "Strong";
					menu_item[8].type = 2;

					//void SET_VEH_HAS_STRONG_AXLES(Vehicle veh, boolean set);
					menu_item[9].name = "Strong Axles";
					menu_item[9].type = 2;

					//void SET_CAR_COLLISION(Car car, boolean set);
					menu_item[10].name = "Collision";
					menu_item[10].type = 2;

					//void SET_CAR_CAN_BE_DAMAGED(Vehicle vehicle, boolean value);
					menu_item[11].name = "Damage";
					menu_item[11].type = 2;

					//void SET_CAR_CAN_BE_VISIBLY_DAMAGED(Vehicle vehicle, boolean value);
					menu_item[12].name = "Visible Damage";
					menu_item[12].type = 2;

					//void SET_CAR_WATERTIGHT(Car car, boolean set);
					menu_item[13].name = "Watertight";
					menu_item[13].type = 2;

					menu_len = 13;

					if (GET_CURRENT_EPISODE() == 2)
					{
						//void SET_VEHICLE_DEFORMATION_MULT(Vehicle veh, float multiplier);
						menu_item[14].name = "Deformation Multiplier";
						menu_len = 14;
					}

					inVModifyHealth = true;
					menu_items_set = true;
				}

				veh_change_set = false;
			}
			else if (item_modifytype_selected == 6)
			{
				if (!menu_items_set)
				{
					// MISC
					//void SET_VEHICLE_DIRT_LEVEL(Vehicle vehicle, float intensity);
					menu_item[1].name = "Dirt Level";
					menu_item[1].type = 3;
					menu_item[1].num_len = 15.9;
					float v_intensity;
					GET_VEHICLE_DIRT_LEVEL(v_modding, &v_intensity);
					menu_item[1].dfval = v_intensity;
					//void SET_VEHICLE_CAN_BE_TARGETTED(Vehicle veh, boolean set);
					menu_item[2].name = "Can be Targetted";
					menu_item[2].type = 2;

					//void SET_VEHICLE_ALPHA(Vehicle veh, int alpha);
					menu_item[3].name = "Transparency";
					menu_item[3].type = 4;
					menu_item[3].num_len = 255;
					//void SET_VEH_ALARM(Vehicle veh, boolean set);
					menu_item[4].name = "Alarm";
					menu_item[4].type = 2;

					//void SET_CAR_VISIBLE(Vehicle vehicle, boolean value);
					menu_item[5].name = "Visible";
					menu_item[5].type = 2;

					//void SET_CAR_AS_MISSION_CAR(Car car);
					menu_item[6].name = "Mission Vehicle";
					menu_len = 6;
					inVModifyMisc = true;
					menu_items_set = true;
				}

				veh_change_set = false;
			}
			else if (item_modifytype_selected == 7)
			{
				if (!menu_items_set)
				{
					menu_item[1].name = "Toggle";
					menu_item[1].type = 2;
					if (G_drawVNeon[99].toggle == 2)
					{
						menu_item[1].enabled = 2;
					}
					menu_item[2].name = "Color";
					menu_item[3].name = "Front & Back";
					menu_item[3].type = 2;
					if (G_drawVNeon[99].togglefb == 2)
					{
						menu_item[3].enabled = 2;
					}
					menu_item[4].name = "Front Offset";
					menu_item[4].type = 3;
					menu_item[4].num_len = 5;
					menu_item[4].allow_neg = true;
					menu_item[4].dfval = G_drawVNeon[99].fyoff;

					menu_item[5].name = "Back Offset";
					menu_item[5].type = 3;
					menu_item[5].num_len = 5;
					menu_item[5].allow_neg = true;
					menu_item[5].dfval = G_drawVNeon[99].byoff;

					menu_item[6].name = "F/B Range";
					menu_item[6].type = 3;
					menu_item[6].num_len = 20;
					menu_item[6].allow_neg = false;
					menu_item[6].dfval = G_drawVNeon[99].fbrange;

					menu_item[7].name = "F/B Intensity";
					menu_item[7].type = 4;
					menu_item[7].num_len = 100;
					menu_item[7].allow_neg = false;
					menu_item[7].numval = G_drawVNeon[99].fbintensity;

					menu_item[8].name = "Main Offset";
					menu_item[8].type = 3;
					menu_item[8].num_len = 5;
					menu_item[8].allow_neg = true;
					menu_item[8].dfval = G_drawVNeon[99].myoff;

					menu_item[9].name = "Main Range";
					menu_item[9].type = 3;
					menu_item[9].num_len = 20;
					menu_item[9].allow_neg = false;
					menu_item[9].dfval = G_drawVNeon[99].mrange;

					menu_item[10].name = "Main Intensity";
					menu_item[10].type = 4;
					menu_item[10].num_len = 100;
					menu_item[10].allow_neg = false;
					menu_item[10].numval = G_drawVNeon[99].mintensity;

					menu_item[11].name = "Height Offset";
					menu_item[11].type = 3;
					menu_item[11].num_len = 5;
					menu_item[11].allow_neg = true;
					menu_item[11].dfval = G_drawVNeon[99].height;

					menu_len = 11;
					inVNeon = true;
					menu_items_set = true;
				}

				veh_change_set = false;
			}
		}
		else if (inVehSaveLoad && item_saveloadtype_selected != 0)
		{

			INIT_FRONTEND_HELPER_TEXT();
			DRAW_FRONTEND_HELPER_TEXT("EMAIL_DELETE", "INPUT_F_Y", 0);
			DRAW_FRONTEND_HELPER_TEXT("CONFIRM", "INPUT_F_ACCEPT", 0);

			if (!menu_items_set)
			{
				int I;
				for (I = 1; I < 16; I++)
				{
					if (G_savedVehicles[I].model_n == 0)
					{
						spawn_cars[I] = 0;
					}
					else
					{
						spawn_cars[I] = G_savedVehicles[I].model_n;
					}
				}

				menu_len = 15;
				menu_items_set = true;
			}
			
			if (IS_BUTTON_JUST_PRESSED(0, BUTTON_T) && spawn_cars[item_high] != 0)
			{
				spawn_cars[item_high] = 0;
				G_savedVehicles[item_high].model_n = 0;
				G_savedVehicles[item_high].normal_colour1 = 0;
				G_savedVehicles[item_high].normal_colour2 = 0;
				G_savedVehicles[item_high].extra_colour1 = 0;
				G_savedVehicles[item_high].extra_colour2 = 0;
				G_savedVehicles[item_high].upgrade1 = 0;
				G_savedVehicles[item_high].upgrade2 = 0;
				G_savedVehicles[item_high].upgrade3 = 0;
				G_savedVehicles[item_high].upgrade4 = 0;
				G_savedVehicles[item_high].upgrade5 = 0;
				G_savedVehicles[item_high].upgrade6 = 0;
				G_savedVehicles[item_high].upgrade7 = 0;
				G_savedVehicles[item_high].upgrade8 = 0;
				G_savedVehicles[item_high].upgrade9 = 0;
				G_savedVehicles[item_high].neon_toggle = 0;
				G_savedVehicles[item_high].neon_togglefb = 0;
				G_savedVehicles[item_high].neon_colour_r = 0;
				G_savedVehicles[item_high].neon_colour_g = 0;
				G_savedVehicles[item_high].neon_colour_b = 0;
				G_savedVehicles[item_high].neon_colour_n = 0;
				G_savedVehicles[item_high].neon_fyoff = 0;
				G_savedVehicles[item_high].neon_byoff = 0;
				G_savedVehicles[item_high].neon_myoff = 0;
				G_savedVehicles[item_high].neon_height = 0;
				G_savedVehicles[item_high].neon_fbrange = 0;
				G_savedVehicles[item_high].neon_fbintensity = 0;
				G_savedVehicles[item_high].neon_mrange = 0;
				G_savedVehicles[item_high].neon_mintensity = 0;
			}

			if (item_saveloadtype_selected == 2)
			{
				inVehLoad = true;
			}
		}

		if (!veh_change_set && (DOES_VEHICLE_EXIST(v_modding) || inVehMenu || inVehSaveLoad))
		{
			if (inVehSaveLoad && item_saveload_selected != 0)
			{
				if (item_saveloadtype_selected == 1)
				{
					uint v_mod_model;
					GET_CAR_MODEL(v_modding, &v_mod_model);

					ColourIndex colour_normal1, colour_normal2, colour_extra1, colour_extra2;
					GET_CAR_COLOURS(v_modding, &colour_normal1, &colour_normal2);
					GET_EXTRA_CAR_COLOURS(v_modding, &colour_extra1, &colour_extra2);

					uint v_upgrade[10];
					int I;
					for (I = 1; I < 10; I++)
					{
						if (IS_VEHICLE_EXTRA_TURNED_ON(v_modding, I))
						{
							v_upgrade[I] = 1;
						}
						else
						{
							v_upgrade[I] = 0;
						}
					}

					G_savedVehicles[item_saveload_selected].model_n = v_mod_model;
					G_savedVehicles[item_saveload_selected].normal_colour1 = colour_normal1;
					G_savedVehicles[item_saveload_selected].normal_colour2 = colour_normal2;
					G_savedVehicles[item_saveload_selected].extra_colour1 = colour_extra1;
					G_savedVehicles[item_saveload_selected].extra_colour2 = colour_extra2;
					G_savedVehicles[item_saveload_selected].upgrade1 = v_upgrade[1];
					G_savedVehicles[item_saveload_selected].upgrade2 = v_upgrade[2];
					G_savedVehicles[item_saveload_selected].upgrade3 = v_upgrade[3];
					G_savedVehicles[item_saveload_selected].upgrade4 = v_upgrade[4];
					G_savedVehicles[item_saveload_selected].upgrade5 = v_upgrade[5];
					G_savedVehicles[item_saveload_selected].upgrade6 = v_upgrade[6];
					G_savedVehicles[item_saveload_selected].upgrade7 = v_upgrade[7];
					G_savedVehicles[item_saveload_selected].upgrade8 = v_upgrade[8];
					G_savedVehicles[item_saveload_selected].upgrade9 = v_upgrade[9];
					G_savedVehicles[item_saveload_selected].neon_toggle = G_drawVNeon[99].toggle;
					G_savedVehicles[item_saveload_selected].neon_togglefb = G_drawVNeon[99].togglefb;
					G_savedVehicles[item_saveload_selected].neon_colour_r = G_drawVNeon[99].colour_r;
					G_savedVehicles[item_saveload_selected].neon_colour_g = G_drawVNeon[99].colour_g;
					G_savedVehicles[item_saveload_selected].neon_colour_b = G_drawVNeon[99].colour_b;
					G_savedVehicles[item_saveload_selected].neon_colour_n = G_drawVNeon[99].colour_n;
					G_savedVehicles[item_saveload_selected].neon_fyoff = G_drawVNeon[99].fyoff;
					G_savedVehicles[item_saveload_selected].neon_byoff = G_drawVNeon[99].byoff;
					G_savedVehicles[item_saveload_selected].neon_myoff = G_drawVNeon[99].myoff;
					G_savedVehicles[item_saveload_selected].neon_height = G_drawVNeon[99].height;
					G_savedVehicles[item_saveload_selected].neon_fbrange = G_drawVNeon[99].fbrange;
					G_savedVehicles[item_saveload_selected].neon_fbintensity = G_drawVNeon[99].fbintensity;
					G_savedVehicles[item_saveload_selected].neon_mrange = G_drawVNeon[99].mrange;
					G_savedVehicles[item_saveload_selected].neon_mintensity = G_drawVNeon[99].mintensity;

					menu_items_set = false;
				}
				else if (item_saveloadtype_selected == 2 && item_saveload_selected != 0 && IS_THIS_MODEL_A_VEHICLE(spawn_cars[item_saveload_selected]))
				{
					//SET_CAR_GENERATORS_ACTIVE_IN_AREA(-9999.90000000, -9999.90000000, -9999.90000000, 9999.90000000, 9999.90000000, 9999.90000000, 0);
					SET_CHAR_VISIBLE(GetPlayerPed(), false);
					SpawnCar(item_saveload_selected);

					CHANGE_CAR_COLOUR(v_modding, G_savedVehicles[item_saveload_selected].normal_colour1, G_savedVehicles[item_saveload_selected].normal_colour2);
					SET_EXTRA_CAR_COLOURS(v_modding, G_savedVehicles[item_saveload_selected].extra_colour1, G_savedVehicles[item_saveload_selected].extra_colour2);

					if (G_savedVehicles[item_saveload_selected].upgrade1 == 1)
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 1, false);
					}
					else
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 1, true);
					}

					if (G_savedVehicles[item_saveload_selected].upgrade2 == 1)
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 2, false);
					}
					else
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 2, true);
					}

					if (G_savedVehicles[item_saveload_selected].upgrade3 == 1)
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 3, false);
					}
					else
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 3, true);
					}

					if (G_savedVehicles[item_saveload_selected].upgrade4 == 1)
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 4, false);
					}
					else
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 4, true);
					}

					if (G_savedVehicles[item_saveload_selected].upgrade5 == 1)
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 5, false);
					}
					else
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 5, true);
					}

					if (G_savedVehicles[item_saveload_selected].upgrade6 == 1)
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 6, false);
					}
					else
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 6, true);
					}

					if (G_savedVehicles[item_saveload_selected].upgrade7 == 1)
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 7, false);
					}
					else
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 7, true);
					}

					if (G_savedVehicles[item_saveload_selected].upgrade8 == 1)
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 8, false);
					}
					else
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 8, true);
					}

					if (G_savedVehicles[item_saveload_selected].upgrade9 == 1)
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 9, false);
					}
					else
					{
						TURN_OFF_VEHICLE_EXTRA(v_modding, 9, true);
					}

					G_drawVNeon[99].toggle = G_savedVehicles[item_saveload_selected].neon_toggle;
					G_drawVNeon[99].togglefb = G_savedVehicles[item_saveload_selected].neon_togglefb;
					G_drawVNeon[99].colour_r = G_savedVehicles[item_saveload_selected].neon_colour_r;
					G_drawVNeon[99].colour_g = G_savedVehicles[item_saveload_selected].neon_colour_g;
					G_drawVNeon[99].colour_b = G_savedVehicles[item_saveload_selected].neon_colour_b;
					G_drawVNeon[99].colour_n = G_savedVehicles[item_saveload_selected].neon_colour_n;
					G_drawVNeon[99].fyoff = G_savedVehicles[item_saveload_selected].neon_fyoff;
					G_drawVNeon[99].byoff = G_savedVehicles[item_saveload_selected].neon_byoff;
					G_drawVNeon[99].myoff = G_savedVehicles[item_saveload_selected].neon_myoff;
					G_drawVNeon[99].height = G_savedVehicles[item_saveload_selected].neon_height;
					G_drawVNeon[99].fbrange = G_savedVehicles[item_saveload_selected].neon_fbrange;
					G_drawVNeon[99].fbintensity = G_savedVehicles[item_saveload_selected].neon_fbintensity;
					G_drawVNeon[99].mrange = G_savedVehicles[item_saveload_selected].neon_mrange;
					G_drawVNeon[99].mintensity = G_savedVehicles[item_saveload_selected].neon_mintensity;

					G_v_domod[99] = v_modding;

					SET_CHAR_VISIBLE(GetPlayerPed(), true);
				}

			}
			else if (inVehMenu && item_vehspawn_selected != 0)
			{
				SET_CAR_GENERATORS_ACTIVE_IN_AREA(-9999.90000000, -9999.90000000, -9999.90000000, 9999.90000000, 9999.90000000, 9999.90000000, 0);
				SET_CHAR_VISIBLE(GetPlayerPed(), false);
				SpawnCar(item_vehspawn_selected);
				G_v_domod[99] = v_modding;
				SET_CHAR_VISIBLE(GetPlayerPed(), true);
			}
			else if (inVehUpgrade && item_up_selected != 0)
			{
				StoreModify(false, false, false, 0, 0, 0);

				if (IS_VEHICLE_EXTRA_TURNED_ON(v_modding, item_up_selected))
				{
					TURN_OFF_VEHICLE_EXTRA(v_modding, item_up_selected, true);
				}
				else
				{
					TURN_OFF_VEHICLE_EXTRA(v_modding, item_up_selected, false);
					if (!IS_VEHICLE_EXTRA_TURNED_ON(v_modding, item_up_selected))
					{
						PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Upgrade not available.", 1000, 1);
					}
				}
				
				ReApplyModify();
			}
			else if (inVehModify && item_modify_selected != 0 && item_modifytype_selected != 0)
			{
				if (inVModifyDoors && item_modify_selected != 1)
				{
					if (VehModifyMode == 2)
					{
						if (IS_CAR_DOOR_DAMAGED(v_modding, item_modify_selected - 2))
						{
							StoreModify(false, true, false, 0, item_modify_selected - 2, 0);

							FIX_CAR(v_modding);
							
							ReApplyModify();
						}
						else
						{
							BREAK_CAR_DOOR(v_modding, item_modify_selected - 2, false);
						}
						CLEAR_AREA_OF_OBJECTS(spawn_x, spawn_y, spawn_z, 5.0000);
					}
					else
					{
						FREEZE_CAR_POSITION(v_modding, 0);
						LOCK_CAR_DOORS(v_modding, 1);
						float doorangle;
						GET_DOOR_ANGLE_RATIO(v_modding, item_modify_selected - 2, &doorangle);

						if (!IS_CAR_DOOR_DAMAGED(v_modding, item_modify_selected - 2) && doorangle >= 0.5000)
						{
							SHUT_CAR_DOOR(v_modding, item_modify_selected - 2);
						}
						else if (!IS_CAR_DOOR_DAMAGED(v_modding, item_modify_selected - 2) && doorangle <= 0.5000)
						{
							OPEN_CAR_DOOR(v_modding, item_modify_selected - 2);
						}
					}
				}
				else if (inVModifyWindows)
				{
					if (IS_VEH_WINDOW_INTACT(v_modding, item_modify_selected - 1))
					{
						REMOVE_CAR_WINDOW(v_modding, item_modify_selected - 1);
					}
					else
					{
						StoreModify(true, false, false, item_modify_selected - 1, 0, 0);

						FIX_CAR(v_modding);

						ReApplyModify();
					}
				}
				else if (inVModifyHandling)
				{
					if (item_modify_selected == 1)
					{
						SET_CAR_FORWARD_SPEED(v_modding, num_selected);
					}
					else if (item_modify_selected == 2)
					{
						SET_VEHICLE_STEER_BIAS(v_modding, floatnum_selected);
					}
					else if (item_modify_selected == 3)
					{
						SET_CAR_TRACTION(v_modding, floatnum_selected);
					}
				}
				else if (inVModifyLights)
				{
					if (item_modify_selected == 1)
					{
						if (menu_item[item_modify_selected].enabled == 2)
						{
							FORCE_CAR_LIGHTS(v_modding, 0);
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							FORCE_CAR_LIGHTS(v_modding, 2);
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					if (item_modify_selected == 2)
					{
						if (menu_item[item_modify_selected].enabled == 2)
						{
							SET_VEH_HAZARDLIGHTS(v_modding, false);
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_VEH_HAZARDLIGHTS(v_modding, true);
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 3)
					{
						if (menu_item[item_modify_selected].enabled == 2)
						{
							SET_VEH_INDICATORLIGHTS(v_modding, false);
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_VEH_INDICATORLIGHTS(v_modding, true);
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 4)
					{
						if (menu_item[item_modify_selected].enabled == 2)
						{
							SET_VEH_INTERIORLIGHT(v_modding, false);
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_VEH_INTERIORLIGHT(v_modding, true);
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 5)
					{
						if (menu_item[item_modify_selected].enabled == 2)
						{
							SWITCH_CAR_SIREN(v_modding, false);
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SWITCH_CAR_SIREN(v_modding, true);
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 6)
					{
						if (menu_item[item_modify_selected].enabled == 2)
						{
							SET_SIREN_WITH_NO_DRIVER(v_modding, false);
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_SIREN_WITH_NO_DRIVER(v_modding, true);
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 7)
					{
						if (menu_item[item_modify_selected].enabled == 2)
						{
							SET_TAXI_LIGHTS(v_modding, false);
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_TAXI_LIGHTS(v_modding, true);
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 8)
					{
						SET_CAR_LIGHT_MULTIPLIER(v_modding, floatnum_selected);
					}

				}
				else if (inVModifyHealth)
				{
				
					if (item_modify_selected == 1)
					{
						SET_CAR_HEALTH(v_modding, num_selected);
					}
					else if (item_modify_selected == 2)
					{
						SET_ENGINE_HEALTH(v_modding, floatnum_selected);
					}
					else if (item_modify_selected == 3)
					{
						if (modifyBulletProof)
						{
							SET_CAR_PROOFS(v_modding, false, modifyFireProof, modifyExplosionProof, modifyCollisionProof, modifyMeleeProof);
							modifyBulletProof = false;
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_CAR_PROOFS(v_modding, true, modifyFireProof, modifyExplosionProof, modifyCollisionProof, modifyMeleeProof);
							modifyBulletProof = true;
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 4)
					{
						if (modifyFireProof)
						{
							SET_CAR_PROOFS(v_modding, modifyBulletProof, false, modifyExplosionProof, modifyCollisionProof, modifyMeleeProof);
							modifyFireProof = false;
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_CAR_PROOFS(v_modding, modifyBulletProof, true, modifyExplosionProof, modifyCollisionProof, modifyMeleeProof);
							modifyFireProof = true;
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 5)
					{
						if (modifyExplosionProof)
						{
							SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, false, modifyCollisionProof, modifyMeleeProof);
							modifyExplosionProof = false;
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, true, modifyCollisionProof, modifyMeleeProof);
							modifyExplosionProof = true;
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 6)
					{
						if (modifyCollisionProof)
						{
							SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, modifyExplosionProof, false, modifyMeleeProof);
							modifyCollisionProof = false;
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, modifyExplosionProof, true, modifyMeleeProof);
							modifyCollisionProof = true;
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 7)
					{
						if (modifyMeleeProof)
						{
							SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, modifyExplosionProof, modifyCollisionProof, false);
							modifyMeleeProof = false;
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, modifyExplosionProof, modifyCollisionProof, true);
							modifyMeleeProof = true;
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 8)
					{
						if (menu_item[item_modify_selected].enabled == 2)
						{
							SET_CAR_STRONG(v_modding, false);
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_CAR_STRONG(v_modding, true);
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 9)
					{
						if (menu_item[item_modify_selected].enabled == 2)
						{
							SET_VEH_HAS_STRONG_AXLES(v_modding, false);
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_VEH_HAS_STRONG_AXLES(v_modding, true);
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 10)
					{
						if (menu_item[item_modify_selected].enabled == 2)
						{
							SET_CAR_COLLISION(v_modding, false);
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_CAR_COLLISION(v_modding, true);
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 11)
					{
						if (menu_item[item_modify_selected].enabled == 2)
						{
							SET_CAR_CAN_BE_DAMAGED(v_modding, false);
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_CAR_CAN_BE_DAMAGED(v_modding, true);
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 12)
					{
						if (menu_item[item_modify_selected].enabled == 2)
						{
							SET_CAR_CAN_BE_VISIBLY_DAMAGED(v_modding, false);
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_CAR_CAN_BE_VISIBLY_DAMAGED(v_modding, true);
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 13)
					{
						if (menu_item[item_modify_selected].enabled == 2)
						{
							SET_CAR_WATERTIGHT(v_modding, false);
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_CAR_WATERTIGHT(v_modding, true);
							menu_item[item_modify_selected].enabled = 2;
						}
					}
			
				}
				else if (inVModifyMisc)
				{
					if (item_modify_selected == 1)
					{
						SET_VEHICLE_DIRT_LEVEL(v_modding, floatnum_selected);
					}
					else if (item_modify_selected == 2)
					{
						if (menu_item[item_modify_selected].enabled == 2)
						{
							SET_VEHICLE_CAN_BE_TARGETTED(v_modding, false);
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_VEHICLE_CAN_BE_TARGETTED(v_modding, true);
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 3)
					{
						SET_VEHICLE_ALPHA(v_modding, num_selected);
					}
					else if (item_modify_selected == 4)
					{
						if (menu_item[item_modify_selected].enabled == 2)
						{
							SET_VEH_ALARM(v_modding, false);
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_VEH_ALARM(v_modding, true);
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 5)
					{
						if (menu_item[item_modify_selected].enabled == 2)
						{
							SET_CAR_VISIBLE(v_modding, false);
							menu_item[item_modify_selected].enabled = 0;
						}
						else
						{
							SET_CAR_VISIBLE(v_modding, true);
							menu_item[item_modify_selected].enabled = 2;
						}
					}
					else if (item_modify_selected == 6)
					{
						SET_CAR_AS_MISSION_CAR(v_modding);
					}

				}
				else if (inVNeon && !G_inVNeonCol[23])
				{
					if (item_modify_selected == 1)
					{
						if (G_drawVNeon[99].toggle == 2)
						{
							menu_item[item_modify_selected].enabled = 0;
							G_drawVNeon[99].toggle = 0;
							MARK_CAR_AS_NO_LONGER_NEEDED(&G_v_domod[99]);
						}
						else
						{
							menu_item[item_modify_selected].enabled = 2;
							G_drawVNeon[99].toggle = 2;
						}
						G_v_domod[99] = v_modding;
					}
					else if (item_modify_selected == 2)
					{
						draw_menu_set = false;
						G_drewrect[23] = true;
						G_inVNeonCol[23] = true;
						G_item_highlighted[23] = G_drawVNeon[99].colour_n;
					}
					else if (item_modify_selected == 3)
					{
						if (G_drawVNeon[99].togglefb == 2)
						{
							menu_item[item_modify_selected].enabled = 0;
							G_drawVNeon[99].togglefb = 0;
						}
						else
						{
							menu_item[item_modify_selected].enabled = 2;
							G_drawVNeon[99].togglefb = 2;
						}
					}
					else if (item_modify_selected == 4)
					{
						G_drawVNeon[99].fyoff = floatnum_selected;
					}
					else if (item_modify_selected == 5)
					{
						G_drawVNeon[99].byoff = floatnum_selected;
					}
					else if (item_modify_selected == 6)
					{
						G_drawVNeon[99].fbrange = floatnum_selected;
					}
					else if (item_modify_selected == 7)
					{
						G_drawVNeon[99].fbintensity = num_selected;
					}
					else if (item_modify_selected == 8)
					{
						G_drawVNeon[99].myoff = floatnum_selected;
					}
					else if (item_modify_selected == 9)
					{
						G_drawVNeon[99].mrange = floatnum_selected;
					}
					else if (item_modify_selected == 10)
					{
						G_drawVNeon[99].mintensity = num_selected;
					}
					else if (item_modify_selected == 11)
					{
						G_drawVNeon[99].height = floatnum_selected;
					}
				}
				item_modify_selected = 0;
			}
			else if (inVehCol)
			{
				if (item_colnum_selected <= 4)
				{
					if (item_col_selected == 0)
					{
						draw_menu_set = false;
						G_drewrect[23] = true;
						ColourIndex colour_normal1, colour_normal2, colour_extra1, colour_extra2;
						GET_CAR_COLOURS(v_modding, &colour_normal1, &colour_normal2);
						GET_EXTRA_CAR_COLOURS(v_modding, &colour_extra1, &colour_extra2);

						if (item_colnum_selected == 1)
							G_item_highlighted[23] = colour_normal1 + 1;
						else if (item_selected == 2)
							G_item_highlighted[23] = colour_normal2 + 1;
						else if (item_colnum_selected == 3)
							G_item_highlighted[23] = colour_extra1 + 1;
						else if (item_colnum_selected == 4)
							G_item_highlighted[23] = colour_extra2 + 1;
					}
					else if (item_col_selected != 0)
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
				else if (item_colnum_selected >= 5)
				{
					if (item_colnum_selected == 5)
					{
						SET_CAR_COLOUR_COMBINATION(v_modding, num_selected - 1);
					}
					else if (item_colnum_selected == 6)
					{
						SET_CAR_LIVERY(v_modding, -1);
					}
					menu_level = 4;
					item_colnum_selected = 0;
				}
			}
			veh_change_set = true;
		}
		return;
	}
	else if (menu_level == 6)
	{
		return;
	}
	else if (menu_level == 7)
	{
		if (inVehSpawnDLC && item_vehcat_selected != 0)
		{
			if (GET_CURRENT_EPISODE() == 1)
			{
				if (item_vehcat_selected == 1)
				{
					spawn_cars[1] = MODEL_GBURRITO;
					spawn_cars[2] = MODEL_SLAMVAN;
					spawn_cars[3] = MODEL_TOWTRUCK;
					spawn_cars[4] = MODEL_PACKER2;
					spawn_cars[5] = MODEL_PBUS;
					spawn_cars[6] = MODEL_YANKEE2;
					spawn_cars[7] = MODEL_RHAPSODY;
					spawn_cars[8] = MODEL_REGINA;
					spawn_cars[9] = MODEL_TAMPA;
					menu_len = 9;
				}
				else if (item_vehcat_selected == 2)
				{
					spawn_cars[1] = MODEL_ANGEL;
					spawn_cars[2] = MODEL_BATI;
					spawn_cars[3] = MODEL_BATI2;
					spawn_cars[4] = MODEL_DAEMON;
					spawn_cars[5] = MODEL_DIABOLUS;
					spawn_cars[6] = MODEL_DOUBLE;
					spawn_cars[7] = MODEL_DOUBLE2;
					spawn_cars[8] = MODEL_HAKUCHOU;
					spawn_cars[9] = MODEL_HAKUCHOU2;
					spawn_cars[10] = MODEL_HEXER;
					spawn_cars[11] = MODEL_INNOVATION;
					spawn_cars[12] = MODEL_LYCAN;
					spawn_cars[13] = MODEL_NIGHTBLADE;
					spawn_cars[14] = MODEL_REVENANT;
					menu_len = 14;
				}
				else if (item_vehcat_selected == 3)
				{
					spawn_cars[1] = MODEL_WAYFARER;
					spawn_cars[2] = MODEL_WOLFSBANE;
					menu_len = 2;
				}
			}
			else if (GET_CURRENT_EPISODE() == 2)
			{
				if (item_vehcat_selected == 1)
				{
					spawn_cars[1] = MODEL_SLAMVAN;
					spawn_cars[2] = MODEL_CADDY;
					spawn_cars[3] = MODEL_APC;
					spawn_cars[4] = MODEL_SUPERD;
					spawn_cars[5] = MODEL_SUPERD2;
					spawn_cars[6] = MODEL_SERRANO;
					spawn_cars[7] = MODEL_SERRANO2;
					spawn_cars[8] = MODEL_BUFFALO;
					spawn_cars[9] = MODEL_AVAN;
					spawn_cars[10] = MODEL_SCHAFTER2;
					spawn_cars[11] = MODEL_SCHAFTER3;
					spawn_cars[12] = MODEL_BULLET;
					spawn_cars[13] = MODEL_TAMPA;
					spawn_cars[14] = MODEL_CAVALCADE2;
					menu_len = 14;
				}
				else if (item_vehcat_selected == 2)
				{
					spawn_cars[1] = MODEL_F620;
					spawn_cars[2] = MODEL_LIMO2;
					spawn_cars[3] = MODEL_POLICE3;
					spawn_cars[4] = MODEL_POLICEW;
					spawn_cars[5] = MODEL_POLICE4;
					spawn_cars[6] = MODEL_POLICEB;
					menu_len = 6;
				}
				else if (item_vehcat_selected == 3)
				{
					spawn_cars[1] = MODEL_HEXER;
					spawn_cars[2] = MODEL_FAGGIO2;
					spawn_cars[3] = MODEL_BATI2;
					spawn_cars[4] = MODEL_VADER;
					spawn_cars[5] = MODEL_AKUMA;
					spawn_cars[6] = MODEL_HAKUCHOU;
					spawn_cars[7] = MODEL_DOUBLE;
					menu_len = 7;
				}
				else if (item_vehcat_selected == 4)
				{
					spawn_cars[1] = MODEL_SMUGGLER;
					spawn_cars[2] = MODEL_FLOATER;
					spawn_cars[3] = MODEL_BLADE;
					menu_len = 3;
				}
				else if (item_vehcat_selected == 5)
				{
					spawn_cars[1] = MODEL_BUZZARD;
					spawn_cars[2] = MODEL_SWIFT;
					spawn_cars[3] = MODEL_SKYLIFT;
					menu_len = 3;
				}
			}
			menu_level = 5;
			inVehMenu = true;
		}
		return;
	}
}

void DoMenu(void)
{
	// Debug
	/*Camera game_cam;
	if (IS_BUTTON_PRESSED(0, BUTTON_DPAD_LEFT))
	{
		GET_GAME_CAM_CHILD(&game_cam);
	}
	else
	{
		GET_GAME_CAM(&game_cam);
	}
	float game_cam_x, game_cam_y, game_cam_z, start_pos_x = 0.05000000, width = 0.30000000, height = 0.30000000;
	uint r = 255, g = 255, b = 255, a = 110;
	if (IS_CAM_ACTIVE(game_cam))
	{
		GET_CAM_POS(game_cam, &game_cam_x, &game_cam_y, &game_cam_z);
		set_up_draw(2, width, height, r, g, b, a);
		draw_float("NUMBR", start_pos_x, 0.10000000, game_cam_x);
		set_up_draw(2, width, height, r, g, b, a);
		draw_float("NUMBR", start_pos_x, 0.13000000, game_cam_y);
		set_up_draw(2, width, height, r, g, b, a);
		draw_float("NUMBR", start_pos_x, 0.16000000, game_cam_z);
	}*/
	/*
	// Ano pad
	float pos_x = 0.05400000, width = 0.30000000, height = 0.30000000;
	uint r = 255, g = 255, b = 255, a = 110, padleft_x, padleft_y, padright_x, padright_y;
	// LEFT -128.0000  RIGHT 127.0000
	GET_POSITION_OF_ANALOGUE_STICKS(0, &padleft_x, &padleft_y, &padright_x, &padright_y);
	set_up_draw(2, width, height, r, g, b, a);
	draw_number("NUMBR", pos_x, 0.10000000, padleft_x);
	set_up_draw(2, width, height, r, g, b, a);
	draw_number("NUMBR", pos_x, 0.13000000, padleft_y);
	*/
	
	/*
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.08800000, menu_level);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.12800000, G_item_highlighted[23]);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.16800000, item_selected);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.20800000, item_modify_selected);
	/*if (inNumberSelector)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.24800000, "inNumberSelector");
	}
	if (inFloatSelector)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.28800000, "inFloatSelector");
	}
	if (inModVeh)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.32800000, "inModVeh");
	}*/
	
	/*
	if (veh_change_set)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.36800000, "veh_change_set");
	}
	*/
	
	/*
	if (inVehSpawn)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.40800000, "inVehSpawn");
	}
	if (inVehMenu)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.44800000, "inVehMenu");
	}*/
	
	/*
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.48800000, G_drawVNeon[99].toggle);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.52800000, G_drawVNeon[99].mintensity);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_float("NUMBR", 0.58700000, 0.56800000, G_drawVNeon[99].mrange, 4);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_float("NUMBR", 0.58700000, 0.60800000, G_drawVNeon[99].height, 4);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.64800000, G_drawVNeon[99].colour_r);
	*/
	//DRAW_RECT(0.15000000, 0.35000000, 0.23000000, 0.63000000, 0, 0, 0, 230);

	if (!menu_cam_set)
	{
		SET_CHAR_COORDINATES_NO_OFFSET(GetPlayerPed(), exit_x, exit_y, exit_z);
		SET_CHAR_HEADING(GetPlayerPed(), exit_h);
		SET_CAM_BEHIND_PED(GetPlayerPed());
		SET_PLAYER_CONTROL(GetPlayerIndex(), false);
		SET_CAMERA_CONTROLS_DISABLED_WITH_PLAYER_CONTROLS(1);
		menu_cam_set = true;
	}

	// In case where coming out of menu_palette
	// and general error catching
	//if (item_high <= menu_len)
	//{
		item_high = G_item_highlighted[23];
	//}

	EnterMenu(item_selected);

	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_O))
	{
		if (draw_menu_set)
		{
			int I;
			for (I = 1; I < (menu_len + 1); I++)
			{
				menu_item[I].name = " ";
				menu_item[I].type = 0;
				menu_item[I].enabled = 0;
				menu_item[I].dfval = 0.0000;
				menu_item[I].num_len = 0;
				menu_item[I].allow_neg = false;
				menu_item[I].numval = 0;
				//spawn_cars[I] = ;
			}
		}

		G_item_highlighted[23] = 1;
		item_high = 1;
		item_selected = 0;
		num_selected = 0;
		floatnum_selected = 0;
		menu_items_set = false;

		if (menu_level == 3)
		{
			menu_level = 2;
			JumpOutVehicle(exit_x, exit_y, exit_z);
		}
		else if (menu_level == 4)
		{
			menu_level = 3;
			if (inVehSpawn)
			{
				menu_level = 2;
				inVehSpawn = false;
			}
			else if (inVehModify)
			{
				menu_level = 2;
				inVehModify = false;
				JumpOutVehicle(exit_x, exit_y, exit_z);
			}
			else if (inVehCol)
			{
				menu_level = 2;
				inVehCol = false;
				JumpOutVehicle(exit_x, exit_y, exit_z);
			}
			else if (inVehSaveLoad)
			{
				menu_level = 2;
				inVehSaveLoad = false;
			}
		}
		else if (menu_level == 5)
		{
			menu_level = 4;
			if (inVehMenu)
			{
				if (inVehSpawnDLC)
				{
					inVehSpawnDLC = false;
					menu_level = 5;
					item_vehcat_selected = 15;
				}
				else
				{
					menu_level = 3;
					item_selected = 1;
					item_vehcat_selected = 0;
				}
				item_vehspawn_selected = 0;
				inVehMenu = false;
				veh_change_set = false;
				SET_ALL_CAR_GENERATORS_BACK_TO_ACTIVE();
				JumpOutVehicle(exit_x, exit_y, exit_z);
			}
			else if (inVehUpgrade)
			{
				inVehUpgrade = false;
				menu_level = 2;
				item_up_selected = 0;
				veh_change_set = false;
				JumpOutVehicle(exit_x, exit_y, exit_z);
			}
			else if (inVehModify)
			{
				menu_level = 3;
				item_selected = 3;
				item_modify_selected = 0;
				item_modifytype_selected = 0;
				VehModifyMode = 1;
				veh_change_set = false;
				//JumpOutVehicle(exit_x, exit_y, exit_z);
				if (inVModifyDoors)
				{
					inVModifyDoors = false;
				}
				else if (inVModifyWindows)
				{
					inVModifyWindows = false;
				}
				else if (inVModifyHandling)
				{
					inVModifyHandling = false;
				}
				else if (inVModifyLights)
				{
					inVModifyLights = false;
				}
				else if (inVModifyHealth)
				{
					inVModifyHealth = false;
				}
				else if (inVModifyMisc)
				{
					inVModifyMisc = false;
				}
				else if (inVNeon)
				{
					inVNeon = false;
					//allow_negative_high = false;

					if (G_inVNeonCol[23])
					{
						menu_level = 5;
						item_modifytype_selected = 7;
						G_inVNeonCol[23] = false;
						draw_menu_set = true;
						G_drewrect[23] = false;

						G_scriptloadedpalette[23] = false;
						TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("garage_menu_palette");
					}
				}
			}
			else if (inVehSaveLoad)
			{
				menu_level = 3;
				item_selected = 6;
				item_saveloadtype_selected = 0;
				item_saveload_selected = 0;
				veh_change_set = false;

				if (inVehLoad)
				{
					//SET_ALL_CAR_GENERATORS_BACK_TO_ACTIVE();
					JumpOutVehicle(exit_x, exit_y, exit_z);
					inVehLoad = false;
				}
			}
			else if (inVehCol)
			{
				menu_level = 3;
				item_selected = 5;
				item_col_selected = 0;
				item_colnum_selected = 0;
				veh_change_set = false;
				draw_menu_set = true;
				G_drewrect[23] = false;

				G_scriptloadedpalette[23] = false;
				TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("garage_menu_palette");
			}
		}
		else if (menu_level == 6)
		{
			if (inVehSpawnDLC)
			{
				menu_level = 3;
				item_selected = 1;
				item_vehcat_selected = 0;
				item_vehspawn_selected = 0;
				inVehMenu = false;
				inVehSpawnDLC = false;
				veh_change_set = false;
			}
		}
	}

	if (draw_menu_set)
	{
		if (IS_BUTTON_JUST_PRESSED(0, BUTTON_X))
		{
			if (inVehMenu && item_vehcat_selected != 0)
			{
				item_vehspawn_selected = G_item_highlighted[23];
				veh_change_set = false;
			}
			else if (inVehCol && (item_colnum_selected != 0 || menu_item[item_high].type == 4 || item_colnum_selected == 6))
			{
				if (menu_item[item_high].type != 4 && item_colnum_selected != 6)
				{
					item_col_selected = G_item_highlighted[23];
				}
				veh_change_set = false;
			}
			else if (inVehModify && item_modifytype_selected != 0)
			{
				item_modify_selected = G_item_highlighted[23];
				if (menu_item[item_modify_selected].type == 4)
				{
					num_selected = menu_item[item_modify_selected].numval;
				}
				else if (menu_item[item_modify_selected].type == 3)
				{
					floatnum_selected = menu_item[item_modify_selected].dfval;
				}
				
				if (inVModifyDoors)
				{
					if (item_modify_selected == 1)
					{
						if (VehModifyMode == 1)
						{
							VehModifyMode = 2;
						}
						else
						{
							VehModifyMode = 1;
						}
					}
				}
				veh_change_set = false;
			}
			else if (inVehUpgrade)
			{
				item_up_selected = G_item_highlighted[23];
				veh_change_set = false;
			}
			else if (inVehSaveLoad && item_saveloadtype_selected != 0)
			{
				item_saveload_selected = G_item_highlighted[23];
				veh_change_set = false;
			}
			else
			{
				item_selected = G_item_highlighted[23];
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
					item_vehcat_selected = G_item_highlighted[23];
					G_item_highlighted[23] = 1;
					menu_level = 5;
				}
				else if (inVehModify)
				{
					item_modifytype_selected = G_item_highlighted[23];
					G_item_highlighted[23] = 1;
					menu_level = 5;
				}
				else if (inVehCol)
				{
					item_colnum_selected = G_item_highlighted[23];

					if (menu_item[item_colnum_selected].type == 4)
					{
						num_selected = menu_item[item_colnum_selected].numval;
					}

					menu_level = 5;
				}
				else if (inVehSaveLoad)
				{
					item_saveloadtype_selected = G_item_highlighted[23];
					G_item_highlighted[23] = 1;
					menu_level = 5;

					if (item_saveloadtype_selected == 1)
					{
						LocateVehicle(spawn_x, spawn_y, spawn_z);

						if (!DOES_VEHICLE_EXIST(v_modding))
						{
							item_saveloadtype_selected = 0;
							menu_level = 4;
							PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Unable to locate a vehicle.", 2500, 1);
						}
					}
				}
			}
			else if (menu_level == 6)
			{
				if (inVehSpawnDLC)
				{
					item_vehcat_selected = G_item_highlighted[23];
					G_item_highlighted[23] = 1;
					menu_level = 7;
				}
			}
		}

		DrawMenu(menu_len);
	}
	else if (G_drewrect[23])
	{
		if (!G_scriptloadedpalette[23])
		{
			if ((GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT("garage_menu_palette")) >= 1)
			{
				G_scriptloadedpalette[23] = true;
			}
			else
			{
				REQUEST_SCRIPT("garage_menu_palette");
				while (!HAS_SCRIPT_LOADED("garage_menu_palette"))
				{
					REQUEST_SCRIPT("garage_menu_palette");
					WAIT(0);
				}
				START_NEW_SCRIPT("garage_menu_palette", 1024);
				MARK_SCRIPT_AS_NO_LONGER_NEEDED("garage_menu_palette");
				G_scriptloadedpalette[23] = true;
			}
		}
		
		if (IS_BUTTON_JUST_PRESSED(0, BUTTON_X))
		{
			if (inVehCol)
			{
				item_col_selected = G_item_highlighted[23];
				veh_change_set = false;
			}
		}

	}

	// Not sure if it will stop the main while loop.
	//return;
}