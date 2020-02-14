#include <iostream>
#include "structs.h"

using namespace std;

class kletka
{
	private:
		struct s_base base;
		struct s_yadro yadro;
		struct s_citoplazma citoplazma;
		int n_zernistost;
		struct s_zernistost zernistost[2];
		void sravnenie_info(struct info inf1, struct info inf2);
		void sravnenie_info2(struct info2 inf1, struct info2 inf2);
		
	public:
		int operator + (kletka const &klt);
		struct info get_tip_kletki();
		struct info get_utochnenie_tipa1();
		struct info get_utochnenie_tipa2();
		struct info get_povtoryaemost_kletki();
		struct info get_uverennost_v_tipe();
		struct info2 get_nedostatki_preparata();
		struct info get_celostnost_kletki();
		struct info get_razmer_kletki();
		struct info get_forma_yadra();
		struct info get_hromocentry();
		struct info get_yaderno_citoplazmaticheskoe_otnoshenie();
		struct info get_polozhenie_yadra_v_citoplazme();
		struct info get_klift();
		struct info get_perinuklioparnoe_uplotnenie();
		struct info get_grubost_hromatipa();
		struct info2 get_nukleoly();
		struct info get_kraya_citoplazmy();
		struct info get_vakuolizaciya_citoplazmy();
		struct info get_okraska_citoplazmy();
		struct info get_palochki_auehra();
		struct info get_perenaklearnoe_prosvetlenie();
		struct info get_ten_na_citoplazme();
		struct info get_nalichie_zernistosti();
		struct info get_kolichestvo_zeren_1();
		struct info get_razmer_zeren_1();
		struct info get_okraska_zernistosti_1();
		struct info get_kolichestvo_zeren_2();
		struct info get_razmer_zeren_2();
		struct info get_okraska_zernistosti_2();
	
		void set_tip_kletki(struct info);
		void set_utochnenie_tipa1(struct info);
		void set_utochnenie_tipa2(struct info);
		void set_povtoryaemost_kletki(struct info);
		void set_uverennost_v_tipe(struct info);
		void set_nedostatki_preparata(struct info2);
		void set_celostnost_kletki(struct info);
		void set_razmer_kletki(struct info);
		void set_forma_yadra(struct info);
		void set_hromocentry(struct info);
		void set_yaderno_citoplazmaticheskoe_otnoshenie(struct info);
		void set_polozhenie_yadra_v_citoplazme(struct info);
		void set_klift(struct info);
		void set_perinuklioparnoe_uplotnenie(struct info);
		void set_grubost_hromatipa(struct info);
		void set_nukleoly(struct info2);
		void set_kraya_citoplazmy(struct info);
		void set_vakuolizaciya_citoplazmy(struct info);
		void set_okraska_citoplazmy(struct info);
		void set_palochki_auehra(struct info);
		void set_perenaklearnoe_prosvetlenie(struct info);
		void set_ten_na_citoplazme(struct info);
		void set_nalichie_zernistosti(struct info);
		void set_kolichestvo_zeren_1(struct info);
		void set_razmer_zeren_1(struct info);
		void set_okraska_zernistosti_1(struct info);
		void set_kolichestvo_zeren_2(struct info);
		void set_razmer_zeren_2(struct info);
		void set_okraska_zernistosti_2(struct info);
};
