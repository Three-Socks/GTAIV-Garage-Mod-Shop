void DrawMenu(int array_len)
{
	if (IS_BUTTON_JUST_PRESSED(0, BUTTON_DPAD_DOWN))
	{
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
		if (G_item_highlighted[2398] == 1)
		{
			G_item_highlighted[2398] = array_len;
		}
		else
		{
			G_item_highlighted[2398]--;
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

				if (G_item_highlighted[2398] == I)
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
	else if (inVModifyDoors)
	{
		float pos_x = 0.05700000, num_pos_x = 0.12800000, onoff_pos_x = 0.160000000, width = 0.30000000, height = 0.30000000;
		uint r, g, b, a = 255;

		int I;
		float Ipos_y = 0.02000000;
	
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
			r = 255;
			g = 255;
			b = 255;
			Ipos_y = Ipos_y + 0.04000000;

			if (G_item_highlighted[2398] == I)
			{
				r = 253;
				g = 160;
				b = 35;
			}

			set_up_draw(0, width, height, r, g, b, a);
			draw_text("STRING", pos_x, Ipos_y, veh_doors[I]);

			if (I == 1)
			{
				if (VehModifyMode == 2)
				{
					set_up_draw(0, width, height, 233, 162, 0, a);
					draw_text("STRING", onoff_pos_x, Ipos_y, "Remove");
				}
				else
				{
					set_up_draw(0, width, height, 233, 162, 0, a);
					draw_text("STRING", onoff_pos_x, Ipos_y, "Open");
				}
			}
			else
			{
				if (VehModifyMode == 2)
				{
					if (IS_CAR_DOOR_DAMAGED(v_modding, I - 2))
					{
						set_up_draw(0, width, height, 233, 162, 0, a);
						draw_text("STRING", onoff_pos_x, Ipos_y, "Removed");
					}
				}
				else
				{
					float doorangle2;
					GET_DOOR_ANGLE_RATIO(v_modding, I - 2, &doorangle2);
					if (!IS_CAR_DOOR_DAMAGED(v_modding, I - 2) && doorangle2 >= 0.5000)
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

			if (G_item_highlighted[2398] == I)
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
	// Don't think this is needed no more.
	/*spawn_x = 874.81200000; spawn_y = -114.20310000; spawn_z = 5.61220000; spawn_h = 180.0;
	exit_x = 869.01190000; exit_y = -114.65010000; exit_z = 5.50540000; exit_h = 270.00000000;
	G_item_highlighted[2398] = 1;
	item_selected = 0;
	menu_level = 2;
	menu_cam_set = false;
	*/
	G_activateMenu[2398] = false;
	G_scriptloaded[2398] = false;
	G_justexitmenu[2398] = G_garageId[2398];

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
		menu_items[3] = "Modify Vehicle";
		menu_items[4] = "Fix & Wash Vehicle";
		menu_items[5] = "Change Vehicle Color";
		menu_items[6] = "Exit";
		menu_len = 6;
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
			if (GET_CURRENT_EPISODE() == 2)
			{
				menu_items[14] = "The Ballad of Gay Tony";
				menu_len = 14;
			}
			else
			{
				menu_len = 13;
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
				menu_items[1] = "Doors";
				menu_len = 1;
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
				menu_items[1] = "Color 1";
				menu_items[2] = "Color 2";
				menu_items[3] = "Specular Color 1";
				menu_items[4] = "Specular Color 2";
				menu_len = 4;
				menu_level = 4;
				G_item_highlighted[2398] = 1;
				inVehCol = true;
			}
			return;
		}
		else if (item_selected == 6)
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
		if (inVehSpawn && !inVehSpawnTBoGT && item_vehcat_selected != 0)
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
			else if (item_vehcat_selected == 14 && GET_CURRENT_EPISODE() == 2)
			{
				menu_items[1] = "Cars";
				menu_items[2] = "...Cars";
				menu_items[3] = "Motorcycles";
				menu_items[4] = "Boats";
				menu_items[5] = "Aircraft";
				menu_len = 5;
				menu_level = 6;
				inVehSpawnTBoGT = true;
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
				//CLEAR_CHAR_SECONDARY_TASK(GetPlayerPed());
			}
			//else if (item_modifytype_selected == 2)
			//{
			//}
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
				SUPPRESS_CAR_MODEL(spawn_cars[item_vehspawn_selected]);

				CREATE_CAR(spawn_cars[item_vehspawn_selected], 0, 0, 0, &v_spawn, false);
				//WAIT(100);
				MARK_MODEL_AS_NO_LONGER_NEEDED(spawn_cars[item_vehspawn_selected]);

				float last_spawn_x = spawn_x;

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

				if (last_spawn_x != spawn_x)
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
						CLEAR_AREA(spawn_x, spawn_y, spawn_z, 3.0000, true);
						LOAD_SCENE(spawn_x, spawn_y, spawn_z);
						//WAIT(100);
						veh_cam_set = false;
						JumpToVehicle(spawn_x, spawn_y, spawn_z, spawn_h, true);
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
				else
				{
					JumpToVehicle(spawn_x, spawn_y, spawn_z, spawn_h, false);
				}
				SET_CHAR_VISIBLE(GetPlayerPed(), true);
			}
			else if (inVehUpgrade && item_up_selected != 0)
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
			else if (inVModifyDoors && item_modify_selected > 1 && item_modifytype_selected != 0)
			{
				if (VehModifyMode == 2)
				{
					if (IS_CAR_DOOR_DAMAGED(v_modding, item_modify_selected - 2))
					{
						int door_I, door_damaged[7];
						for (door_I = 0; door_I < 6; door_I++)
						{
							if (IS_CAR_DOOR_DAMAGED(v_modding, door_I) && door_I != item_modify_selected - 2)
							{
								door_damaged[door_I] = 1;
							}
						}
						FIX_CAR(v_modding);
						for (door_I = 0; door_I < 6; door_I++)
						{
							if (door_damaged[door_I] == 1)
							{
								BREAK_CAR_DOOR(v_modding, door_I, false);
							}
						}
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
			else if (inVehCol)
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
	else if (menu_level == 6)
	{
		return;
	}
	else if (menu_level == 7)
	{
		if (inVehSpawnTBoGT && item_vehcat_selected != 0)
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
			menu_level = 5;
		}
		inVehMenu = true;
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
	float game_cam_x, game_cam_y, game_cam_z, pos_x = 0.05000000, width = 0.30000000, height = 0.30000000;
	uint r = 255, g = 255, b = 255, a = 110;
	if (IS_CAM_ACTIVE(game_cam))
	{
		GET_CAM_POS(game_cam, &game_cam_x, &game_cam_y, &game_cam_z);
		set_up_draw(2, width, height, r, g, b, a);
		draw_float("NUMBR", pos_x, 0.10000000, game_cam_x);
		set_up_draw(2, width, height, r, g, b, a);
		draw_float("NUMBR", pos_x, 0.13000000, game_cam_y);
		set_up_draw(2, width, height, r, g, b, a);
		draw_float("NUMBR", pos_x, 0.16000000, game_cam_z);
	}*/
	/*
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.08800000, menu_level);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.12800000, G_item_highlighted[2398]);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.16800000, item_selected);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.20800000, VehModifyMode);
	if (inVehModify)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.24800000, "inVehModify");
	}
	if (inVModifyDoors)
	{
		set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
		draw_text("STRING", 0.58700000, 0.28800000, "inVModifyDoors");
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
	draw_number("NUMBR", 0.58700000, 0.48800000, item_modify_selected);
	set_up_draw(0, 0.30000000, 0.30000000, 255, 255, 255, 255);
	draw_number("NUMBR", 0.58700000, 0.51800000, item_modifytype_selected);
	*/

	//DRAW_RECT(0.15000000, 0.35000000, 0.23000000, 0.63000000, 0, 0, 0, 230);

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
		G_item_highlighted[2398] = 1;
		item_selected = 0;

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
				inVehSpawnTBoGT = false;
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
			else if (inVModifyDoors)
			{
				menu_level = 3;
				item_selected = 3;
				menu_len = 2;
				item_modify_selected = 0;
				item_modifytype_selected = 0;
				VehModifyMode = 1;
				inVModifyDoors = false;
				veh_change_set = false;
				JumpOutVehicle(exit_x, exit_y, exit_z);
			}
			else if (inVehCol)
			{
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
			if (inVehSpawnTBoGT)
			{
				menu_level = 5;
				menu_len = 5;
				item_vehcat_selected = 1;
				item_vehspawn_selected = 0;
				inVehMenu = false;
				inVehSpawnTBoGT = false;
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
		else if (inVehCol && item_colnum_selected != 0)
		{
			item_col_selected = G_item_highlighted[2398];
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
				menu_level = 5;
			}
			else if (inVehCol)
			{
				item_colnum_selected = G_item_highlighted[2398];
				menu_level = 5;
			}
		}
		else if (menu_level == 6)
		{
			if (inVehSpawnTBoGT)
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