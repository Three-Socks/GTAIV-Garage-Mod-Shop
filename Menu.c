void DrawMenu(int array_len)
{
	uint d_r = 255, d_g = 255, d_b = 255, h_r = 253, h_g = 160, h_b = 35;
	float start_pos_x = 0.0553, toggle_pos_x = 0.1600, menu_spacing = 0.0400, menu_width = 0.3000, menu_height = 0.3000;

	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_DOWN))
	{
		if ((inNumberSelector || inFloatSelector) && (num_highlighted != 0 || floatnum_highlighted != 0))
		{
			num_highlighted = 0;
			floatnum_highlighted = 0;
		}

		if (G_item_highlighted[2398] == array_len)
		{
			G_item_highlighted[2398] = 1;
		}
		else
		{
			G_item_highlighted[2398]++;
		}
	}

	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_UP))
	{
		if ((inNumberSelector || inFloatSelector) && (num_highlighted != 0 || floatnum_highlighted != 0))
		{
			num_highlighted = 0;
			floatnum_highlighted = 0;
		}

		if (G_item_highlighted[2398] == 1)
		{
			G_item_highlighted[2398] = array_len;
		}
		else
		{
			G_item_highlighted[2398]--;
		}
	}
	
	if ((inNumberSelector || inFloatSelector) && num_item_highlighted != 0)
	{
		if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_LEFT) || isButtonPressedLong(BUTTON_DPAD_LEFT))
		{
			if (inFloatSelector)
			{
				if (floatnum_highlighted < 0.1)
				{
					floatnum_highlighted = num_len;
				}
				else
				{
					floatnum_highlighted -= 0.100;
				}
			}
			else
			{
				if (num_highlighted == 1)
				{
					num_highlighted = num_len;
				}
				else
				{
					num_highlighted--;
				}
			}
		}

		if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_RIGHT) || isButtonPressedLong(BUTTON_DPAD_RIGHT))
		{
			if (inFloatSelector)
			{
				if (floatnum_highlighted == num_len)
				{
					floatnum_highlighted = 0.0;
				}
				else
				{
					floatnum_highlighted += 0.100;
				}
			}
			else
			{
				if (num_highlighted == num_len)
				{
					num_highlighted = 1;
				}
				else
				{
					num_highlighted++;
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

				if (G_item_highlighted[2398] == I)
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

			if (G_item_highlighted[2398] == I)
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

			if (G_item_highlighted[2398] == I)
			{
				r =  h_r;
				g =  h_g;
				b =  h_b;
			}

			set_up_draw(0, menu_width, menu_height, r, g, b, a);
			draw_text("STRING", start_pos_x, Ipos_y, veh_windows[I]);

			if (!IS_VEH_WINDOW_INTACT(v_modding, I - 1))
			{
				set_up_draw(0, menu_width, menu_height, h_r, h_g, h_b, a);
				draw_text("STRING", toggle_pos_x, Ipos_y, "Removed");
			}
			else
			{
				set_up_draw(0, menu_width, menu_height, d_r, d_g, d_b, a);
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

			if ((inNumberSelector || inFloatSelector) && num_item_highlighted == I)
			{
				set_up_draw(0, menu_width, menu_height, r, g, b, a);
				draw_text("STRING", 0.2000, Ipos_y, "<");
				set_up_draw(0, menu_width, menu_height, r, g, b, a);
				if (inFloatSelector)
				{
					draw_float("NUMBR", 0.2150, Ipos_y, floatnum_highlighted);
				}
				else
				{
					draw_number("NUMBR", 0.2150, Ipos_y, num_highlighted);
				}
				set_up_draw(0, menu_width, menu_height, r, g, b, a);
				draw_text("STRING", 0.2400, Ipos_y, ">");
			}

			if (G_item_highlighted[2398] == I)
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
			else
			{
				draw_text("STRING", start_pos_x, Ipos_y, menu_item[I].name);
			}


			if (inVehModify && menu_item[I].type == 2)
			{
				if (modifyEnabled[menu_item[I].extraI] == 2)
				{
					set_up_draw(0, menu_width, menu_height, h_r, h_g, h_b, a);
					draw_text("STRING", toggle_pos_x, Ipos_y, "On");
				}
			}

		}
	}
}

void ExitMenu(void)
{
	G_activateMenu[2398] = false;
	G_scriptloaded[2398] = false;
	G_justexitmenu[2398] = G_garageId[2398];

	SET_PLAYER_CONTROL(GetPlayerIndex(), true);
	SET_CAMERA_CONTROLS_DISABLED_WITH_PLAYER_CONTROLS(0);

	SET_CHAR_COORDINATES_NO_OFFSET(GetPlayerPed(), quit_x, quit_y, quit_z);
	SET_CHAR_HEADING(GetPlayerPed(), quit_h);

	if (G_garageId[2398] == 6)
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
				G_item_highlighted[2398] = 1;
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
				menu_len = 6;
				inVehModify = true;
				G_item_highlighted[2398] = 1;
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
				menu_item[5].name = "Neon";
				menu_len = 5;

				GET_NUM_CAR_COLOURS(v_modding, &NumColours);
				if (NumColours > 0)
				{
					menu_item[6].name = "Color Variation";
					menu_len++;
				}

				//void GET_NUM_CAR_LIVERIES(Car car, int *num);
				menu_item[7].name = "Livery";
				menu_len++;

				menu_level = 4;
				G_item_highlighted[2398] = 1;
				num_highlighted = 1;
				inVehCol = true;
			}
			return;
		}
		else if (item_selected == 6)
		{
			LocateVehicle(spawn_x, spawn_y, spawn_z);
				
			if (DOES_VEHICLE_EXIST(v_modding))
			{
				menu_item[1].name = "Save";
				menu_item[2].name = "Load";
				menu_len = 2;
				G_item_highlighted[2398] = 1;
				menu_level = 4;
				inVehSaveLoad = true;
			}
			else
			{
				PRINT_STRING_WITH_LITERAL_STRING_NOW("STRING", "Your vehicle has been fixed and cleaned.", 2500, 1);
			}
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
			num_item_highlighted = 0;
			inNumberSelector = false;

			if (G_item_highlighted[2398] == 5 && NumColours > 0)
			{
				num_item_highlighted = 5;
				inNumberSelector = true;

				num_len = NumColours;
			}
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
				// HANDLING
				//void SET_CAR_FORWARD_SPEED(Vehicle vehicle, float speed);
				menu_item[1].name = "Speed";
				//void SET_VEHICLE_STEER_BIAS(Vehicle veh, float val);
				menu_item[2].name = "Steer Bias";
				//void SET_CAR_ALWAYS_CREATE_SKIDS(Car car, boolean set);
				menu_item[3].name = "Always Skid";
				menu_item[3].type = 2;
				menu_item[3].extraI = 1;
				//void SET_CAR_TRACTION(Car car, float traction);
				menu_item[4].name = "Traction";
				menu_len = 4;
				inVModifyHandling = true;

				veh_change_set = false;
				num_item_highlighted = 0;
				inNumberSelector = false;
				inFloatSelector = false;

				if (G_item_highlighted[2398] == 1)
				{
					num_item_highlighted = 1;
					inFloatSelector = true;
					num_len = 10;
				}
				else if (G_item_highlighted[2398] == 2)
				{
					num_item_highlighted = 2;
					inFloatSelector = true;
					num_len = 10;
				}
				else if (G_item_highlighted[2398] == 4)
				{
					num_item_highlighted = 4;
					inFloatSelector = true;
					num_len = 10;
				}
			}
			else if (item_modifytype_selected == 4)
			{
				// LIGHTS
				//void FORCE_CAR_LIGHTS(Car car, int lights);
				menu_item[1].name = "Head Lights";
				menu_item[1].type = 2;
				menu_item[1].extraI = 2;
				//void SET_VEH_HAZARDLIGHTS(Vehicle vehicle, boolean on);
				menu_item[2].name = "Hazard Lights";
				menu_item[2].type = 2;
				menu_item[2].extraI = 3;
				//void SET_VEH_INDICATORLIGHTS(Vehicle veh, boolean set);
				menu_item[3].name = "Indicator Lights";
				menu_item[3].type = 2;
				menu_item[3].extraI = 4;
				//void SET_VEH_INTERIORLIGHT(Vehicle veh, boolean set);
				menu_item[4].name = "Interior Light";
				menu_item[4].type = 2;
				menu_item[4].extraI = 5;
				//void SWITCH_CAR_SIREN(Car car, boolean siren);
				menu_item[5].name = "Siren";
				menu_item[5].type = 2;
				menu_item[5].extraI = 6;
				//void void SET_SIREN_WITH_NO_DRIVER(Car car, boolean set);
				menu_item[6].name = "Always Siren";
				menu_item[6].type = 2;
				menu_item[6].extraI = 7;
				//void SET_TAXI_LIGHTS(Car car, boolean set);
				menu_item[7].name = "Taxi Light";
				menu_item[7].type = 2;
				menu_item[7].extraI = 8;
				//void SET_CAR_LIGHT_MULTIPLIER(Car car, float multiplier);
				menu_item[8].name = "Light Multiplier";
				menu_len = 8;
				inVModifyLights = true;

				veh_change_set = false;
				num_item_highlighted = 0;
				inNumberSelector = false;
				inFloatSelector = false;

				if (G_item_highlighted[2398] == 8)
				{
					num_item_highlighted = 8;
					inFloatSelector = true;
					num_len = 10;
				}
			}
			else if (item_modifytype_selected == 5)
			{
				// HEALTH
				//void SET_CAR_HEALTH(Vehicle vehicle, uint Value);
				menu_item[1].name = "Health";
				//void SET_ENGINE_HEALTH(Vehicle vehicle, float health);
				menu_item[2].name = "Engine Health";
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
				menu_item[8].extraI = 9;
				//void SET_VEH_HAS_STRONG_AXLES(Vehicle veh, boolean set);
				menu_item[9].name = "Strong Axles";
				menu_item[9].type = 2;
				menu_item[9].extraI = 10;
				//void SET_CAR_COLLISION(Car car, boolean set);
				menu_item[10].name = "Collision";
				menu_item[10].type = 2;
				menu_item[10].extraI = 11;
				//void SET_CAR_CAN_BE_DAMAGED(Vehicle vehicle, boolean value);
				menu_item[11].name = "Damage";
				menu_item[11].type = 2;
				menu_item[11].extraI = 12;
				//void SET_CAR_CAN_BE_VISIBLY_DAMAGED(Vehicle vehicle, boolean value);
				menu_item[12].name = "Visible Damage";
				menu_item[12].type = 2;
				menu_item[12].extraI = 13;
				//void SET_VEHICLE_DEFORMATION_MULT(Vehicle veh, float multiplier);
				//menu_item[13].name = "Deformation Multiplier";
				//void SET_CAR_WATERTIGHT(Car car, boolean set);
				menu_item[13].name = "Watertight";
				menu_item[13].type = 2;
				menu_item[13].extraI = 14;
				menu_len = 13;
				inVModifyHealth = true;
				
				veh_change_set = false;
				num_item_highlighted = 0;
				inNumberSelector = false;
				inFloatSelector = false;

				if (G_item_highlighted[2398] == 1)
				{
					num_item_highlighted = 1;
					inNumberSelector = true;
					num_len = 1000;
				}
				else if (G_item_highlighted[2398] == 2)
				{
					num_item_highlighted = 2;
					inNumberSelector = true;
					num_len = 1000;
				}
			}
			else if (item_modifytype_selected == 6)
			{
				// MISC
				//void SET_VEHICLE_DIRT_LEVEL(Vehicle vehicle, float intensity);
				menu_item[1].name = "Dirt Level";
				//void SET_VEHICLE_CAN_BE_TARGETTED(Vehicle veh, boolean set);
				menu_item[2].name = "Can be Targetted";
				menu_item[2].type = 2;
				menu_item[2].extraI = 15;
				//void SET_VEHICLE_ALPHA(Vehicle veh, int alpha);
				menu_item[3].name = "Transparency";
				//void SET_VEH_ALARM_DURATION(Vehicle veh, int duration);
				menu_item[4].name = "Alarm Duration";
				//void SET_VEH_ALARM(Vehicle veh, boolean set);
				menu_item[5].name = "Alarm";
				menu_item[5].type = 2;
				menu_item[5].extraI = 16;
				//void SET_CAR_VISIBLE(Vehicle vehicle, boolean value);
				menu_item[6].name = "Visible";
				menu_item[6].type = 2;
				menu_item[6].extraI = 17;
				//void SET_CAR_AS_MISSION_CAR(Car car);
				menu_item[7].name = "Mission";
				menu_len = 7;
				inVModifyMisc = true;

				veh_change_set = false;
				num_item_highlighted = 0;
				inNumberSelector = false;
				inFloatSelector = false;

				if (G_item_highlighted[2398] == 1)
				{
					num_item_highlighted = 1;
					inFloatSelector = true;
					num_len = 15.9;
				}
				else if (G_item_highlighted[2398] == 3)
				{
					num_item_highlighted = 3;
					inNumberSelector = true;
					num_len = 255;
				}
				else if (G_item_highlighted[2398] == 4)
				{
					num_item_highlighted = 4;
					inNumberSelector = true;
					num_len = 30;
				}
			}
		}

		if (!veh_change_set && (DOES_VEHICLE_EXIST(v_modding) || inVehMenu))
		{
			if (inVehMenu && item_vehspawn_selected != 0)
			{
		    SET_CAR_GENERATORS_ACTIVE_IN_AREA(-9999.90000000, -9999.90000000, -9999.90000000, 9999.90000000, 9999.90000000, 9999.90000000, 0);
				SET_CHAR_VISIBLE(GetPlayerPed(), false);

				LocateVehicle(spawn_x, spawn_y, spawn_z);

				if (DOES_VEHICLE_EXIST(v_modding))
				{
					DELETE_CAR(&v_modding);
				}

				if (DOES_VEHICLE_EXIST(v_spawn))
				{
					DELETE_CAR(&v_spawn);
				}
				REQUEST_MODEL(spawn_cars[item_vehspawn_selected]);
				while (!HAS_MODEL_LOADED(spawn_cars[item_vehspawn_selected])) WAIT(0);
				//SUPPRESS_CAR_MODEL(spawn_cars[item_vehspawn_selected]);

				CREATE_CAR(spawn_cars[item_vehspawn_selected], 0, 0, 0, &v_spawn, false);
				//WAIT(100);
				MARK_MODEL_AS_NO_LONGER_NEEDED(spawn_cars[item_vehspawn_selected]);

				float last_spawn_x = spawn_x, last_spawn_y = spawn_y;

				if ((IS_BIG_VEHICLE(v_spawn) || spawn_cars[item_vehspawn_selected] == MODEL_RIPLEY)
					&& spawn_cars[item_vehspawn_selected] != MODEL_MERIT 
					&& spawn_cars[item_vehspawn_selected] != MODEL_PRES 
					&& spawn_cars[item_vehspawn_selected] != MODEL_WASHINGTON
					&& spawn_cars[item_vehspawn_selected] != MODEL_MINIVAN
					&& spawn_cars[item_vehspawn_selected] != MODEL_MOONBEAM
					&& spawn_cars[item_vehspawn_selected] != MODEL_PERENNIAL
					&& spawn_cars[item_vehspawn_selected] != MODEL_PERENNIAL2
					&& spawn_cars[item_vehspawn_selected] != MODEL_POLICE4
				)
				{
					// Warehouse
					exit_x = garage_big_exit_x; exit_y = garage_big_exit_y; exit_z = garage_big_exit_z; exit_h = garage_big_exit_h;
					quit_x = garage_big_quit_x; quit_y = garage_big_quit_y; quit_z = garage_big_quit_z; quit_h = garage_big_quit_h;
					spawn_x = garage_big_spawn_x; spawn_y = garage_big_spawn_y; spawn_z = garage_big_spawn_z; spawn_h = garage_big_spawn_h;
				}
				else if (IS_THIS_MODEL_A_BOAT(spawn_cars[item_vehspawn_selected]))
				{
					// Jetty
					exit_x = garage_boat_exit_x; exit_y = garage_boat_exit_y; exit_z = garage_boat_exit_z; exit_h = garage_boat_exit_h;
					quit_x = garage_boat_quit_x; quit_y = garage_boat_quit_y; quit_z = garage_boat_quit_z; quit_h = garage_boat_quit_h;
					spawn_x = garage_boat_spawn_x; spawn_y = garage_boat_spawn_y; spawn_z = garage_boat_spawn_z; spawn_h = garage_boat_spawn_h;
				}
				else if(IS_THIS_MODEL_A_HELI(spawn_cars[item_vehspawn_selected]))
				{
					// Helipad
					exit_x = garage_heli_exit_x; exit_y = garage_heli_exit_y; exit_z = garage_heli_exit_z; exit_h = garage_heli_exit_h;
					quit_x = garage_heli_quit_x; quit_y = garage_heli_quit_y; quit_z = garage_heli_quit_z; quit_h = garage_heli_quit_h;
					spawn_x = garage_heli_spawn_x; spawn_y = garage_heli_spawn_y; spawn_z = garage_heli_spawn_z; spawn_h = garage_heli_spawn_h;
				}
				else
				{
					// Garage
					exit_x = garage_main_exit_x; exit_y = garage_main_exit_y; exit_z = garage_main_exit_z; exit_h = garage_main_exit_h;
					quit_x = garage_main_quit_x; quit_y = garage_main_quit_y; quit_z = garage_main_quit_z; quit_h = garage_main_quit_h;
					spawn_x = garage_main_spawn_x; spawn_y = garage_main_spawn_y; spawn_z = garage_main_spawn_z; spawn_h = garage_main_spawn_h;
				}

				if (last_spawn_x != spawn_x && last_spawn_y != spawn_y)
				{
					float distfromlast;
					GET_DISTANCE_BETWEEN_COORDS_2D(last_spawn_x, last_spawn_y, spawn_x, spawn_y, &distfromlast);

					if (distfromlast > 50.0000)
					{
						while (IS_SCREEN_FADING())
						{
							WAIT(0);
						}
						DO_SCREEN_FADE_OUT(10);
						while (IS_SCREEN_FADING())
						{
							WAIT(0);
						}
						LOAD_SCENE(spawn_x, spawn_y, spawn_z);
					}
					CLEAR_AREA(spawn_x, spawn_y, spawn_z, 3.0000, true);
					veh_cam_set = false;
					JumpToVehicle(spawn_x, spawn_y, spawn_z, spawn_h, true);
					if (distfromlast > 50.0000)
					{
						while (IS_SCREEN_FADING())
						{
							WAIT(0);
						}
						DO_SCREEN_FADE_IN(10);
						while (IS_SCREEN_FADING())
						{
							WAIT(0);
						}
					}
				}
				else
				{
					JumpToVehicle(spawn_x, spawn_y, spawn_z, spawn_h, false);
				}
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
						SET_CAR_FORWARD_SPEED(v_modding, floatnum_selected);
					}
					else if (item_modify_selected == 2)
					{
						SET_VEHICLE_STEER_BIAS(v_modding, floatnum_selected);
					}
					else if (item_modify_selected == 3)
					{
						if (modifyEnabled[1] == 2)
						{
							SET_CAR_ALWAYS_CREATE_SKIDS(v_modding, false);
							modifyEnabled[1] = 0;
						}
						else
						{
							SET_CAR_ALWAYS_CREATE_SKIDS(v_modding, true);
							modifyEnabled[1] = 2;
						}
					}
					else if (item_modify_selected == 4)
					{
						SET_CAR_TRACTION(v_modding, floatnum_selected);
					}

				}
				else if (inVModifyLights)
				{
					if (item_modify_selected == 1)
					{
						if (modifyEnabled[2] == 2)
						{
							FORCE_CAR_LIGHTS(v_modding, 0);
							modifyEnabled[2] = 0;
						}
						else
						{
							FORCE_CAR_LIGHTS(v_modding, 2);
							modifyEnabled[2] = 2;
						}
					}
					if (item_modify_selected == 2)
					{
						if (modifyEnabled[3] == 2)
						{
							SET_VEH_HAZARDLIGHTS(v_modding, false);
							modifyEnabled[3] = 0;
						}
						else
						{
							SET_VEH_HAZARDLIGHTS(v_modding, true);
							modifyEnabled[3] = 2;
						}
					}
					else if (item_modify_selected == 3)
					{
						if (modifyEnabled[4] == 2)
						{
							SET_VEH_INDICATORLIGHTS(v_modding, false);
							modifyEnabled[4] = 0;
						}
						else
						{
							SET_VEH_INDICATORLIGHTS(v_modding, true);
							modifyEnabled[4] = 2;
						}
					}
					else if (item_modify_selected == 4)
					{
						if (modifyEnabled[5] == 2)
						{
							SET_VEH_INTERIORLIGHT(v_modding, false);
							modifyEnabled[5] = 0;
						}
						else
						{
							SET_VEH_INTERIORLIGHT(v_modding, true);
							modifyEnabled[5] = 2;
						}
					}
					else if (item_modify_selected == 5)
					{
						if (modifyEnabled[6] == 2)
						{
							SWITCH_CAR_SIREN(v_modding, false);
							modifyEnabled[6] = 0;
						}
						else
						{
							SWITCH_CAR_SIREN(v_modding, true);
							modifyEnabled[6] = 2;
						}
					}
					else if (item_modify_selected == 6)
					{
						if (modifyEnabled[7] == 2)
						{
							SET_SIREN_WITH_NO_DRIVER(v_modding, false);
							modifyEnabled[7] = 0;
						}
						else
						{
							SET_SIREN_WITH_NO_DRIVER(v_modding, true);
							modifyEnabled[7] = 2;
						}
					}
					else if (item_modify_selected == 7)
					{
						if (modifyEnabled[8] == 2)
						{
							SET_TAXI_LIGHTS(v_modding, false);
							modifyEnabled[8] = 0;
						}
						else
						{
							SET_TAXI_LIGHTS(v_modding, true);
							modifyEnabled[8] = 2;
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
						}
						else
						{
							SET_CAR_PROOFS(v_modding, true, modifyFireProof, modifyExplosionProof, modifyCollisionProof, modifyMeleeProof);
							modifyBulletProof = true;
						}
					}
					else if (item_modify_selected == 4)
					{
						if (modifyFireProof)
						{
							SET_CAR_PROOFS(v_modding, modifyBulletProof, false, modifyExplosionProof, modifyCollisionProof, modifyMeleeProof);
							modifyFireProof = false;
						}
						else
						{
							SET_CAR_PROOFS(v_modding, modifyBulletProof, true, modifyExplosionProof, modifyCollisionProof, modifyMeleeProof);
							modifyFireProof = true;
						}
					}
					else if (item_modify_selected == 5)
					{
						if (modifyExplosionProof)
						{
							SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, false, modifyCollisionProof, modifyMeleeProof);
							modifyExplosionProof = false;
						}
						else
						{
							SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, true, modifyCollisionProof, modifyMeleeProof);
							modifyExplosionProof = true;
						}
					}
					else if (item_modify_selected == 6)
					{
						if (modifyCollisionProof)
						{
							SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, modifyExplosionProof, false, modifyMeleeProof);
							modifyCollisionProof = false;
						}
						else
						{
							SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, modifyExplosionProof, true, modifyMeleeProof);
							modifyCollisionProof = true;
						}
					}
					else if (item_modify_selected == 7)
					{
						if (modifyMeleeProof)
						{
							SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, modifyExplosionProof, modifyCollisionProof, false);
							modifyMeleeProof = false;
						}
						else
						{
							SET_CAR_PROOFS(v_modding, modifyBulletProof, modifyFireProof, modifyExplosionProof, modifyCollisionProof, true);
							modifyMeleeProof = true;
						}
					}
					else if (item_modify_selected == 8)
					{
						if (modifyEnabled[9] == 2)
						{
							SET_CAR_STRONG(v_modding, false);
							modifyEnabled[9] = 0;
						}
						else
						{
							SET_CAR_STRONG(v_modding, true);
							modifyEnabled[9] = 2;
						}
					}
					else if (item_modify_selected == 9)
					{
						if (modifyEnabled[10] == 2)
						{
							SET_VEH_HAS_STRONG_AXLES(v_modding, false);
							modifyEnabled[10] = 0;
						}
						else
						{
							SET_VEH_HAS_STRONG_AXLES(v_modding, true);
							modifyEnabled[10] = 2;
						}
					}
					else if (item_modify_selected == 10)
					{
						if (modifyEnabled[11] == 2)
						{
							SET_CAR_COLLISION(v_modding, false);
							modifyEnabled[11] = 0;
						}
						else
						{
							SET_CAR_COLLISION(v_modding, true);
							modifyEnabled[11] = 2;
						}
					}
					else if (item_modify_selected == 11)
					{
						if (modifyEnabled[12] == 2)
						{
							SET_CAR_CAN_BE_DAMAGED(v_modding, false);
							modifyEnabled[12] = 0;
						}
						else
						{
							SET_CAR_CAN_BE_DAMAGED(v_modding, true);
							modifyEnabled[12] = 2;
						}
					}
					else if (item_modify_selected == 12)
					{
						if (modifyEnabled[13] == 2)
						{
							SET_CAR_CAN_BE_VISIBLY_DAMAGED(v_modding, false);
							modifyEnabled[13] = 0;
						}
						else
						{
							SET_CAR_CAN_BE_VISIBLY_DAMAGED(v_modding, true);
							modifyEnabled[13] = 2;
						}
					}
					else if (item_modify_selected == 13)
					{
						if (modifyEnabled[14] == 2)
						{
							SET_CAR_WATERTIGHT(v_modding, false);
							modifyEnabled[14] = 0;
						}
						else
						{
							SET_CAR_WATERTIGHT(v_modding, true);
							modifyEnabled[14] = 2;
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
						if (modifyEnabled[15] == 2)
						{
							SET_VEHICLE_CAN_BE_TARGETTED(v_modding, false);
							modifyEnabled[15] = 0;
						}
						else
						{
							SET_VEHICLE_CAN_BE_TARGETTED(v_modding, true);
							modifyEnabled[15] = 2;
						}
					}
					else if (item_modify_selected == 3)
					{
						SET_VEHICLE_ALPHA(v_modding, num_selected);
					}
					else if (item_modify_selected == 4)
					{
						SET_VEH_ALARM_DURATION(v_modding, num_selected * 100);
					}
					else if (item_modify_selected == 5)
					{
						if (modifyEnabled[16] == 2)
						{
							SET_VEH_ALARM(v_modding, false);
							modifyEnabled[16] = 0;
						}
						else
						{
							SET_VEH_ALARM(v_modding, true);
							modifyEnabled[16] = 2;
						}
					}
					else if (item_modify_selected == 6)
					{
						if (modifyEnabled[17] == 2)
						{
							SET_CAR_VISIBLE(v_modding, false);
							modifyEnabled[17] = 0;
						}
						else
						{
							SET_CAR_VISIBLE(v_modding, true);
							modifyEnabled[17] = 2;
						}
					}
					else if (item_modify_selected == 7)
					{
						SET_CAR_AS_MISSION_CAR(v_modding);
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
						G_drewrect[2398] = true;
						ColourIndex colour_normal1, colour_normal2, colour_extra1, colour_extra2;
						GET_CAR_COLOURS(v_modding, &colour_normal1, &colour_normal2);
						GET_EXTRA_CAR_COLOURS(v_modding, &colour_extra1, &colour_extra2);

						if (item_colnum_selected == 1)
							G_item_highlighted[2398] = colour_normal1 + 1;
						else if (item_selected == 2)
							G_item_highlighted[2398] = colour_normal2 + 1;
						else if (item_colnum_selected == 3)
							G_item_highlighted[2398] = colour_extra1 + 1;
						else if (item_colnum_selected == 4)
							G_item_highlighted[2398] = colour_extra2 + 1;
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
				else if (item_colnum_selected == 5)
				{
					if (item_col_selected == 0)
					{
						float v_attach_x, v_attach_y, v_attach_z;
						GET_CAR_COORDINATES(v_modding, &v_attach_x, &v_attach_y, &v_attach_z);
						G_drawVNeon[2398].intensity = 10.0000;
						G_drawVNeon[2398].range = 50.0000;
						G_drawVNeon[2398].height = v_attach_z;

						draw_menu_set = false;
						G_drewrect[2398] = true;
					}
					else if (item_col_selected != 0 && item_neon_selected == 0)
					{
						if (G_scriptloadedpalette[2398])
						{
							draw_menu_set = true;
							G_drewrect[2398] = false;

							G_scriptloadedpalette[2398] = false;
							TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("garage_menu_palette");
						}

						menu_item[1].name = "Enable/Disable";
						menu_item[2].name = "Height";
						menu_item[3].name = "Intensity";
						menu_item[4].name = "Range";
						menu_len = 4;
						G_inVNeon[2398] = true;

						veh_change_set = false;
						num_item_highlighted = 0;
						inNumberSelector = false;
						inFloatSelector = false;

						if (G_item_highlighted[2398] == 2)
						{
							num_item_highlighted = 2;
							inFloatSelector = true;
							num_len = 10;
						}
						else if (G_item_highlighted[2398] == 3)
						{
							num_item_highlighted = 3;
							inNumberSelector = true;
							num_len = 15;
						}
						else if (G_item_highlighted[2398] == 4)
						{
							num_item_highlighted = 4;
							inNumberSelector = true;
							num_len = 100;
						}						
					}
					else if (item_neon_selected != 0)
					{
						if (item_neon_selected == 1)
						{
							if (G_drawVNeon[2398].enabled)
							{
								G_drawVNeon[2398].enabled = false;
							}
							else
							{
								G_drawVNeon[2398].enabled = true;
							}
						}
						else if (item_neon_selected == 2)
						{
							G_drawVNeon[2398].height = floatnum_selected;
						}
						else if (item_neon_selected == 3)
						{
							G_drawVNeon[2398].intensity = num_selected;
						}
						else if (item_neon_selected == 4)
						{
							G_drawVNeon[2398].range = num_selected;
						}
					}
				}
				else if (item_colnum_selected >= 6)
				{
					if (item_colnum_selected == 6)
					{
						SET_CAR_COLOUR_COMBINATION(v_modding, num_selected - 1);
					}
					else if (item_colnum_selected == 7)
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
	float pos_x = 0.05000000, width = 0.30000000, height = 0.30000000;
	uint r = 255, g = 255, b = 255, a = 110, padleft_x, padleft_y, padright_x, padright_y;
	GET_POSITION_OF_ANALOGUE_STICKS(0, &padleft_x, &padleft_y, &padright_x, &padright_y);
	set_up_draw(2, width, height, r, g, b, a);
	draw_float("NUMBR", pos_x, 0.10000000, padleft_x);
	set_up_draw(2, width, height, r, g, b, a);
	draw_float("NUMBR", pos_x, 0.13000000, padleft_y);
	*/
	
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.08800000, menu_level);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.12800000, G_item_highlighted[2398]);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.16800000, item_selected);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.20800000, item_modify_selected);
	if (inNumberSelector)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.24800000, "inNumberSelector");
	}
	if (inFloatSelector)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.28800000, "inFloatSelector");
	}/*
	if (inModVeh)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.32800000, "inModVeh");
	}*/
	if (veh_change_set)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.36800000, "veh_change_set");
	}
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
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.48800000, num_highlighted);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.52800000, num_selected);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_float("NUMBR", 0.58700000, 0.56800000, floatnum_highlighted);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_float("NUMBR", 0.58700000, 0.60800000, floatnum_selected);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.64800000, num_item_highlighted);

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

	EnterMenu(item_selected);

	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_O))
	{
		int I;
		for (I = 1; I < (menu_len + 1); I++)
		{
			menu_item[I].name = " ";
			//spawn_cars[I] = ;
		}

		G_item_highlighted[2398] = 1;
		num_highlighted = 1;
		item_selected = 0;
		num_selected = 0;
		floatnum_selected = 0;

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
				inNumberSelector = false;
				num_item_highlighted = 0;
				JumpOutVehicle(exit_x, exit_y, exit_z);
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
				inNumberSelector = false;
				inFloatSelector = false;
				num_item_highlighted = 0;
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
			}
			else if (inVehCol)
			{
				if (G_inVNeon[2398])
				{
					G_inVNeon[2398] = false;
				}
				menu_level = 3;
				item_selected = 5;
				item_col_selected = 0;
				item_colnum_selected = 0;
				veh_change_set = false;
				draw_menu_set = true;
				G_drewrect[2398] = false;

				G_scriptloadedpalette[2398] = false;
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

	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_X))
	{
		if (inVehMenu && item_vehcat_selected != 0)
		{
			item_vehspawn_selected = G_item_highlighted[2398];
			veh_change_set = false;
		}
		else if (inVehCol && (item_colnum_selected != 0 || inNumberSelector || item_colnum_selected == 6))
		{
			if (!inNumberSelector && item_colnum_selected != 6)
			{
				item_col_selected = G_item_highlighted[2398];
			}
			veh_change_set = false;
		}
		else if (G_inVNeon[2398] && item_col_selected != 0)
		{
			if (inNumberSelector)
			{
				num_selected = num_highlighted;
			}
			else if (inFloatSelector)
			{
				floatnum_selected = floatnum_highlighted;
			}
			item_neon_selected = G_item_highlighted[2398];
			veh_change_set = false;
		}
		else if (inVModifyDoors && item_modifytype_selected != 0)
		{
			item_modify_selected = G_item_highlighted[2398];
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
			veh_change_set = false;
		}
		else if (inVModifyWindows && item_modifytype_selected != 0)
		{
			if (inNumberSelector)
			{
				num_selected = num_highlighted;
			}
			else if (inFloatSelector)
			{
				floatnum_selected = floatnum_highlighted;
			}
			item_modify_selected = G_item_highlighted[2398];
			veh_change_set = false;
		}
		else if (inVModifyHandling && item_modifytype_selected != 0)
		{
			if (inNumberSelector)
			{
				num_selected = num_highlighted;
			}
			else if (inFloatSelector)
			{
				floatnum_selected = floatnum_highlighted;
			}
			item_modify_selected = G_item_highlighted[2398];
			veh_change_set = false;
		}
		else if (inVModifyLights && item_modifytype_selected != 0)
		{
			if (inNumberSelector)
			{
				num_selected = num_highlighted;
			}
			else if (inFloatSelector)
			{
				floatnum_selected = floatnum_highlighted;
			}
			item_modify_selected = G_item_highlighted[2398];
			veh_change_set = false;
		}
		else if (inVModifyHealth && item_modifytype_selected != 0)
		{
			if (inNumberSelector)
			{
				num_selected = num_highlighted;
			}
			else if (inFloatSelector)
			{
				floatnum_selected = floatnum_highlighted;
			}
			item_modify_selected = G_item_highlighted[2398];
			veh_change_set = false;
		}
		else if (inVModifyMisc && item_modifytype_selected != 0)
		{
			if (inNumberSelector)
			{
				num_selected = num_highlighted;
			}
			else if (inFloatSelector)
			{
				floatnum_selected = floatnum_highlighted;
			}
			item_modify_selected = G_item_highlighted[2398];
			veh_change_set = false;
		}
		else if (inVehUpgrade)
		{
			item_up_selected = G_item_highlighted[2398];
			veh_change_set = false;
		}
		else
		{
			item_selected = G_item_highlighted[2398];
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
				item_vehcat_selected = G_item_highlighted[2398];
				G_item_highlighted[2398] = 1;
				menu_level = 5;
			}
			else if (inVehModify)
			{
				item_modifytype_selected = G_item_highlighted[2398];
				G_item_highlighted[2398] = 1;
				menu_level = 5;
			}
			else if (inVehCol)
			{
				if (inNumberSelector)
				{
					num_selected = num_highlighted;
				}

				item_colnum_selected = G_item_highlighted[2398];
				menu_level = 5;
			}
		}
		else if (menu_level == 6)
		{
			if (inVehSpawnDLC)
			{
				item_vehcat_selected = G_item_highlighted[2398];
				G_item_highlighted[2398] = 1;
				menu_level = 7;
			}
		}
	}

	if (draw_menu_set)
	{
		DrawMenu(menu_len);
	}
	else if (inVehCol)
	{
		if (!G_scriptloadedpalette[2398])
		{
			if ((GET_NUMBER_OF_INSTANCES_OF_STREAMED_SCRIPT("garage_menu_palette")) >= 1)
			{
				G_scriptloadedpalette[2398] = true;
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
				G_scriptloadedpalette[2398] = true;
			}
		}
	}

	// Not sure if it will stop the main while loop.
	//return;
}