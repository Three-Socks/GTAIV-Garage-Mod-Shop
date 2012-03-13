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

uint soundID = 2;

bool activateMenu = false;

bool menu_cam_set = false;
bool draw_menu_set = true;

int menu_level = 2;
int item_highlighted = 1;
int item_selected = 0;
int item_vehcat_selected = 0;
int item_vehspawn_selected = 0;
int item_up_selected = 0;
int item_colnum_selected = 0;
int item_col_selected = 0;

float spawn_x, spawn_y, spawn_z, spawn_h;
float exit_x, exit_y, exit_z, exit_h;
float quit_x, quit_y, quit_z, quit_h;

Vehicle v_spawn;
Vehicle v_modding;
bool inVehSpawn = false;
bool inVehMenu = false;
bool inVehUpgrade = false;
bool inVehCol = false;
bool inModVeh = false;
bool veh_change_set = false;

char *menu_items[14];
int menu_len;
uint spawn_cars[15];

typedef struct _rgbcolours
{
	uint r;
	uint g;
	uint b;
} rgbcolours;

rgbcolours car_colours[134];