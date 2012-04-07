#define BUTTON_SELECT  0xD
#define BUTTON_START  0xC
#define BUTTON_S  0xE
#define BUTTON_T  0xF
#define BUTTON_X  0x10
#define BUTTON_O  0x11
#define BUTTON_DPAD_UP  0x8
#define BUTTON_DPAD_DOWN  0x9
#define BUTTON_DPAD_LEFT  0xA
#define BUTTON_DPAD_RIGHT  0xB
#define BUTTON_L2  0x5
#define BUTTON_R2  0x7
#define BUTTON_L1  0x4
#define BUTTON_R1  0x6
#define BUTTON_STICK_LEFT  0x12
#define BUTTON_STICK_RIGHT  0x13

// MAIN
	float garage_main_exit_x,
	garage_main_exit_y,
	garage_main_exit_z,
	garage_main_exit_h,

	garage_main_quit_x,
	garage_main_quit_y,
	garage_main_quit_z,
	garage_main_quit_h,

	garage_main_spawn_x,
	garage_main_spawn_y,
	garage_main_spawn_z,
	garage_main_spawn_h,

// BIG
	garage_big_exit_x,
	garage_big_exit_y,
	garage_big_exit_z,
	garage_big_exit_h,

	garage_big_quit_x,
	garage_big_quit_y,
	garage_big_quit_z,
	garage_big_quit_h,

	garage_big_spawn_x,
	garage_big_spawn_y,
	garage_big_spawn_z,
	garage_big_spawn_h,

// BOAT
	garage_boat_exit_x,
	garage_boat_exit_y,
	garage_boat_exit_z,
	garage_boat_exit_h,

	garage_boat_quit_x,
	garage_boat_quit_y,
	garage_boat_quit_z,
	garage_boat_quit_h,

	garage_boat_spawn_x,
	garage_boat_spawn_y,
	garage_boat_spawn_z,
	garage_boat_spawn_h,

// HELI
	garage_heli_exit_x,
	garage_heli_exit_y,
	garage_heli_exit_z,
	garage_heli_exit_h,

	garage_heli_quit_x,
	garage_heli_quit_y,
	garage_heli_quit_z,
	garage_heli_quit_h,

	garage_heli_spawn_x,
	garage_heli_spawn_y,
	garage_heli_spawn_z,
	garage_heli_spawn_h;

bool menu_cam_set = false;
bool veh_cam_set = false;
bool draw_menu_set = true;

uint menu_level = 2;
uint item_selected = 0;
uint item_vehcat_selected = 0;
uint item_vehspawn_selected = 0;
uint item_up_selected = 0;
uint item_colnum_selected = 0;
uint item_col_selected = 0;
uint item_modifytype_selected = 0;
uint item_modify_selected = 0;
uint VehModifyMode = 1;
uint num_item_highlighted = 0;
uint num_highlighted = 1;
uint num_selected = 0;
float floatnum_highlighted = 1;
float floatnum_selected = 0;

float spawn_x, spawn_y, spawn_z, spawn_h;
float exit_x, exit_y, exit_z, exit_h;
float quit_x, quit_y, quit_z, quit_h;

Vehicle v_spawn;
Vehicle v_modding;

bool inVehSpawn = false;
bool inVehSpawnDLC = false;
bool inVehMenu = false;

bool inVehUpgrade = false;

bool inVehModify = false;
bool inVModifyDoors = false;
bool inVModifyWindows = false;
bool inVModifyHandling = false;
bool inVModifyLights = false;
bool inVModifyHealth = false;
bool inVModifyMisc = false;
bool inVNeon = false;

bool inVehCol = false;
bool veh_change_set = false;

bool inNumberSelector = false;
bool inFloatSelector = false;

bool inVehSaveLoad = false;

//char *menu_items[16];

typedef struct _menu
{
	char *name;
	uint type;
	uint extraI;
	bool extraVar;
} menu;

/*
 name: Display name

 type: 
   2 = toggle

 extraI: Extra identifier
 extraVar: Extra var
*/


menu menu_item[16];

uint menu_len;
uint num_len;
uint spawn_cars[15];

uint NumColours = 0;
uint window_notintact[5], door_damaged[7], door_opened[7];
uint modifyEnabled[18];
bool modifyBulletProof = false;
bool modifyFireProof = false;
bool modifyExplosionProof = false;
bool modifyCollisionProof = false;
bool modifyMeleeProof = false;

int longPress = 0;