typedef struct _drawVNeonS
{
	uint toggle;
	uint togglefb;
	uint colour_r;
	uint colour_g;
	uint colour_b;
	uint colour_n;
	//float fxoff;
	float fyoff;
	//float bxoff;
	float byoff;
	uint fbintensity;
	float fbrange;
	//float mxoff;
	float myoff;
	uint mintensity;
	float mrange;
	float height;
} drawVNeonS;

typedef struct _saveVehicleS
{
	uint model_n;
	ColourIndex normal_colour1;
	ColourIndex normal_colour2;
	ColourIndex extra_colour1;
	ColourIndex extra_colour2;
	uint upgrade1;
	uint upgrade2;
	uint upgrade3;
	uint upgrade4;
	uint upgrade5;
	uint upgrade6;
	uint upgrade7;
	uint upgrade8;
	uint upgrade9;
	uint neon_toggle;
	uint neon_togglefb;
	uint neon_colour_r;
	uint neon_colour_g;
	uint neon_colour_b;
	uint neon_colour_n;
	float neon_fyoff;
	float neon_byoff;
	uint neon_fbintensity;
	float neon_fbrange;
	float neon_myoff;
	uint neon_mintensity;
	float neon_mrange;
	float neon_height;
} saveVehicleS;