bool G_scriptloaded[2398];
bool G_scriptloadedpalette[2398];
bool G_activateMenu[2398];
bool G_doneExitCheck[2398];
bool G_drewrect[2398];

bool G_inVNeon[2398];
typedef struct _drawVNeonS
{
	bool enabled;
	uint colour_r;
	uint colour_g;
	uint colour_b;
	float height;
	float intensity;
	float range;
} drawVNeonS;

drawVNeonS G_drawVNeon[2398];

uint G_garageId[2398];
uint G_justexitmenu[2398];
uint G_item_highlighted[2398];