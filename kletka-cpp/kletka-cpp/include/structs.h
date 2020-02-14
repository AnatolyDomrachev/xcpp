#define STR_SIZE 100
#define NUM_VARS 20

struct info
{
	char fname[STR_SIZE];
	char value[STR_SIZE];
	char name[STR_SIZE];
};

struct info2
{
	char fname[STR_SIZE];
	char value[NUM_VARS][STR_SIZE];
	char name[STR_SIZE];
	unsigned num : 4;
};

struct s_base
{
	struct info tip_kletki;
	struct info utochnenie_tipa1;
	struct info utochnenie_tipa2;
	struct info povtoryaemost_kletki;
	struct info uverennost_v_tipe;
	struct info2 nedostatki_preparata; //_nedostatkov_mozhet_byt_neskolko;
};

struct s_yadro
{
	struct info celostnost_kletki;
	struct info razmer_kletki;
	struct info forma_yadra;
	struct info hromocentry;
	struct info yaderno_citoplazmaticheskoe_otnoshenie;
	struct info polozhenie_yadra_v_citoplazme;
	struct info klift;
	struct info perinuklioparnoe_uplotnenie;
	struct info grubost_hromatipa;
	struct info2 nukleoly; //u_vsekh_parametry_mogut_byt_ot_0_do_2;
};

struct s_citoplazma
{
	struct info kraya_citoplazmy;
	struct info vakuolizaciya_citoplazmy;
	struct info okraska_citoplazmy;
	struct info palochki_auehra;
	struct info perenaklearnoe_prosvetlenie;
	struct info ten_na_citoplazme;
	struct info nalichie_zernistosti;
};

struct s_zernistost
{
	struct info kolichestvo_zeren;
	struct info razmer_zeren;
	struct info okraska_zernistosti;
};

