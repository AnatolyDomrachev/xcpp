#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "include/kletka.h"

void sravnenie_info(struct info inf1, struct info inf2)
{
	char buf[50];
	if(strcmp(inf1.value, inf2.value) == 0)
		strcpy(buf, "Совпадают");
	else
		strcpy(buf, "Не совпадают");
	printf("\n%s\n\t%s | %s | %s\n", inf1.name, inf1.value, inf2.value, buf);
}

void sravnenie_info2(struct info2 inf1, struct info2 inf2)
{
	char buf[50];
	int i;
	for(i=0; i<inf1.num || i<inf2.num; i++)
	{
		if(inf1.num <= i)
			strcpy(inf1.value[i], "Признак не задан");
		if(inf2.num <= i)
			strcpy(inf2.value[i], "Признак не задан");
		if(strcmp(inf1.value[i], inf2.value[i]) == 0)
			strcpy(buf, "Совпадают");
		else
			strcpy(buf, "Не совпадают");
		printf("\n%s\n\t%s | %s | %s\n", inf1.name, inf1.value[i], inf2.value[i], buf);
	}

}

void sravnenie(kletka kletka1, kletka kletka2)
{
	sravnenie_info(kletka1.get_tip_kletki(), kletka2.get_tip_kletki());
	sravnenie_info(kletka1.get_utochnenie_tipa1(), kletka2.get_utochnenie_tipa1());
	sravnenie_info(kletka1.get_utochnenie_tipa2(), kletka2.get_utochnenie_tipa2());
	sravnenie_info(kletka1.get_povtoryaemost_kletki(), kletka2.get_povtoryaemost_kletki());
	sravnenie_info(kletka1.get_uverennost_v_tipe(), kletka2.get_uverennost_v_tipe());
	sravnenie_info2(kletka1.get_nedostatki_preparata(), kletka2.get_nedostatki_preparata());
	sravnenie_info(kletka1.get_celostnost_kletki(), kletka2.get_celostnost_kletki());
	sravnenie_info(kletka1.get_razmer_kletki(), kletka2.get_razmer_kletki());
	sravnenie_info(kletka1.get_forma_yadra(), kletka2.get_forma_yadra());
	sravnenie_info(kletka1.get_hromocentry(), kletka2.get_hromocentry());
	sravnenie_info(kletka1.get_yaderno_citoplazmaticheskoe_otnoshenie(), kletka2.get_yaderno_citoplazmaticheskoe_otnoshenie());
	sravnenie_info(kletka1.get_polozhenie_yadra_v_citoplazme(), kletka2.get_polozhenie_yadra_v_citoplazme());
	sravnenie_info(kletka1.get_klift(), kletka2.get_klift());
	sravnenie_info(kletka1.get_perinuklioparnoe_uplotnenie(), kletka2.get_perinuklioparnoe_uplotnenie());
	sravnenie_info(kletka1.get_grubost_hromatipa(), kletka2.get_grubost_hromatipa());
	sravnenie_info2(kletka1.get_nukleoly(), kletka2.get_nukleoly());
	sravnenie_info(kletka1.get_kraya_citoplazmy(), kletka2.get_kraya_citoplazmy());
	sravnenie_info(kletka1.get_vakuolizaciya_citoplazmy(), kletka2.get_vakuolizaciya_citoplazmy());
	sravnenie_info(kletka1.get_okraska_citoplazmy(), kletka2.get_okraska_citoplazmy());
	sravnenie_info(kletka1.get_palochki_auehra(), kletka2.get_palochki_auehra());
	sravnenie_info(kletka1.get_perenaklearnoe_prosvetlenie(), kletka2.get_perenaklearnoe_prosvetlenie());
	sravnenie_info(kletka1.get_ten_na_citoplazme(), kletka2.get_ten_na_citoplazme());
	sravnenie_info(kletka1.get_nalichie_zernistosti(), kletka2.get_nalichie_zernistosti());
	sravnenie_info(kletka1.get_kolichestvo_zeren_1(), kletka2.get_kolichestvo_zeren_1());
	sravnenie_info(kletka1.get_razmer_zeren_1(), kletka2.get_razmer_zeren_1());
	sravnenie_info(kletka1.get_okraska_zernistosti_1(), kletka2.get_okraska_zernistosti_1());
	sravnenie_info(kletka1.get_kolichestvo_zeren_2(), kletka2.get_kolichestvo_zeren_2());
	sravnenie_info(kletka1.get_razmer_zeren_2(), kletka2.get_razmer_zeren_2());
	sravnenie_info(kletka1.get_okraska_zernistosti_2(), kletka2.get_okraska_zernistosti_2());

}

void read_file(struct info* inf, char* fname)
{
	FILE* fin;
	int num = 0, index, res;
	char buf[NUM_VARS][STR_SIZE], buf2[STR_SIZE], buf3[STR_SIZE];
	char* c;

	sprintf(buf[0], "data2/%s", fname);
	fin = fopen( buf[0] , "r");
	if(!fin)
		perror(buf[0]);
	fgets(buf[0], STR_SIZE, fin);
	strcpy(inf->name, buf[0]);
	if(c=strchr(inf->name, '\n'))
		strcpy(c, "\0");
	printf("%s\n",inf->name);
	while(fgets(buf[num], STR_SIZE, fin))
	{
		printf("%d %s", num, buf[num]);
		num++;
	}

	if(num == 0)
		strcpy(inf->value, "Не установлено");
	else
	{
		for(;;)
		{
			strcpy(buf3,"");
			fgets(buf2, 5 ,stdin);
			fflush(stdin);
			res = sscanf(buf2, "%d%s", &index, buf3);
			if(res == 0 || index < 0 || index >= num || strlen(buf3) != 0)
				printf("Выберите значние из указанного диапазона\n");
			else
				break;
		}

		strcpy(inf->value, buf[index]);
		if(c=strchr(inf->value, '\n'))
			strcpy(c, "\0");
	}
	fclose(fin);
}

void f_utochnenie_tipa(kletka *klt)
{
	struct info inf;

	read_file(&inf, "Dlya_vsekh_kletok.txt");
	klt->set_utochnenie_tipa1(inf);

	if( strcmp(klt->get_tip_kletki().value,"Гранулоцит") == 0)
	{
		read_file(&inf, "utochnenie_tipa/Dlya_granulocitov.txt");
		klt->set_utochnenie_tipa2(inf);
	}
	else
	if( strcmp(klt->get_tip_kletki().value,"Лимфоцит") == 0)
	{
		read_file(&inf, "utochnenie_tipa/Dlya_limfocitov.txt");
		klt->set_utochnenie_tipa2(inf);
	}
	else
	if( strcmp(klt->get_tip_kletki().value,"Миелоцит") == 0)
	{
		read_file(&inf, "utochnenie_tipa/Dlya_mielocitov.txt");
		klt->set_utochnenie_tipa2(inf);
	}
	else
	if( strcmp(klt->get_tip_kletki().value,"Моноцит") == 0)
	{
		read_file(&inf, "utochnenie_tipa/Dlya_monocitov.txt");
		klt->set_utochnenie_tipa2(inf);
	}
	else
	if( strcmp(klt->get_tip_kletki().value,"Нормоцит") == 0)
	{
		read_file(&inf, "utochnenie_tipa/Dlya_normocitov.txt");
		klt->set_utochnenie_tipa2(inf);
	}
	else
	{
		read_file(&inf, "utochnenie_tipa/Dlya_ostalnyh.txt");
		klt->set_utochnenie_tipa2(inf);
	}
}

void get_info2(struct info2* inf2, char* fname)
{
	int i;
	struct info inf;

	for(i=0; i< inf2->num; i++)
	{
		read_file(&inf, fname);
		strcpy(inf2->name, inf.name);
		strcpy(inf2->value[i], inf.value);
	}
}

void get_base(kletka *klt)
{
	struct info inf;
	struct info2 inf2;

	read_file(&inf, "tip_kletki.txt");
	klt->set_tip_kletki(inf);

	f_utochnenie_tipa(klt);

	read_file(&inf, "povtoryaemost_kletki.txt");
	klt->set_povtoryaemost_kletki(inf);

	read_file(&inf, "uverennost_v_tipe.txt");
	klt->set_uverennost_v_tipe(inf);

	char buf2[5];
	int buf3;
	int res;
	printf("Количество недостатков препарата (0-2): ");
	for(;;)
	{
	    char buf2[5];
        fgets(buf2, 5 ,stdin);
		fflush(stdin);
        res = sscanf(buf2, "%d", &buf3);
		if(res == 0 || buf3 < 0 || buf3 > 3)
			printf("Выберите значние из указанного диапазона\n");
		else
		{
			inf2.num = buf3;
			break;
		}
	}

	get_info2(&inf2, "nedostatki_preparata.txt");
	klt->set_nedostatki_preparata(inf2);
}

void get_yadro(kletka *klt)
{
	struct info inf;
	struct info2 inf2;

	read_file(&inf, "celostnost_kletki.txt");
	klt->set_celostnost_kletki(inf);

	read_file(&inf, "razmer_kletki.txt");
	klt->set_razmer_kletki(inf);

	read_file(&inf, "forma_yadra.txt");
	klt->set_forma_yadra(inf);

	read_file(&inf, "hromocentry.txt");
	klt->set_hromocentry(inf);

	read_file(&inf, "yaderno_citoplazmaticheskoe_otnoshenie.txt");
	klt->set_yaderno_citoplazmaticheskoe_otnoshenie(inf);

	read_file(&inf, "polozhenie_yadra_v_citoplazme.txt");
	klt->set_polozhenie_yadra_v_citoplazme(inf);

	read_file(&inf, "klift.txt");
	klt->set_klift(inf);

	read_file(&inf, "perinuklioparnoe_uplotnenie.txt");
	klt->set_perinuklioparnoe_uplotnenie(inf);

	read_file(&inf, "grubost_hromatipa.txt");
	klt->set_grubost_hromatipa(inf);

	char buf2[5];
	int buf3;
	int res;
	printf("Количество нуклеолов (0-3): ");
	for(;;)
	{
        fgets(buf2, 5 ,stdin);
		fflush(stdin);
        res = sscanf(buf2, "%d", &buf3);
		if(res == 0 || buf3 < 0 || buf3 > 3)
			printf("Выберите значние из указанного диапазона\n");
		else
		{
			inf2.num = buf3;
			break;
		}
	}

	get_info2(&inf2, "nukleoly.txt");
	klt->set_nukleoly(inf2);
}

void get_citoplazma(kletka *klt)
{
	struct info inf;
	struct info2 inf2;

	read_file(&inf, "kraya_citoplazmy.txt");
	klt->set_kraya_citoplazmy(inf);

	read_file(&inf, "vakuolizaciya_citoplazmy.txt");
	klt->set_vakuolizaciya_citoplazmy(inf);

	read_file(&inf, "okraska_citoplazmy.txt");
	klt->set_okraska_citoplazmy(inf);

	read_file(&inf, "palochki_auehra.txt");
	klt->set_palochki_auehra(inf);

	read_file(&inf, "perenaklearnoe_prosvetlenie.txt");
	klt->set_perenaklearnoe_prosvetlenie(inf);

	read_file(&inf, "ten_na_citoplazme.txt");
	klt->set_ten_na_citoplazme(inf);

	read_file(&inf, "nalichie_zernistosti.txt");
	klt->set_nalichie_zernistosti(inf);
}

void priznak_ne_zadan(struct info* inf, char* fname)
{
	FILE* fin;
	int num = 0;
	char buf[STR_SIZE];
	char* c;

	sprintf(buf, "data2/%s", fname);
	fin = fopen( buf , "r");
	if(!fin)
		perror(buf);
	fgets(buf, STR_SIZE, fin);
	strcpy(inf->name, buf);
	strcpy(inf->value, "признак не задан");
	fclose(fin);
}

void get_zernistost(kletka *klt)
{
	struct info inf;
	int i;
	inf = klt->get_nalichie_zernistosti();
	if( strcmp(klt->get_nalichie_zernistosti().value, "Отсутствует") == 0 )
	{
		priznak_ne_zadan(&inf, "kolichestvo_zeren.txt");
		klt->set_kolichestvo_zeren_1(inf);
		klt->set_kolichestvo_zeren_2(inf);
		priznak_ne_zadan(&inf, "razmer_zeren.txt");
		klt->set_razmer_zeren_1(inf);
		klt->set_razmer_zeren_2(inf);
		priznak_ne_zadan(&inf, "okraska_zernistosti.txt");
		klt->set_okraska_zernistosti_1(inf);
		klt->set_okraska_zernistosti_2(inf);
	}

	if( strcmp(klt->get_nalichie_zernistosti().value, "зернистость одного вида") == 0 )
	{
		read_file(&inf,"kolichestvo_zeren.txt");
		klt->set_kolichestvo_zeren_1(inf);
		read_file(&inf,"razmer_zeren.txt");
		klt->set_razmer_zeren_1(inf);
		read_file(&inf,"okraska_zernistosti.txt");
		klt->set_okraska_zernistosti_1(inf);
		priznak_ne_zadan(&inf,"kolichestvo_zeren.txt");
		klt->set_kolichestvo_zeren_2(inf);
		priznak_ne_zadan(&inf,"razmer_zeren.txt");
		klt->set_razmer_zeren_2(inf);
		priznak_ne_zadan(&inf,"okraska_zernistosti.txt");
		klt->set_okraska_zernistosti_2(inf);
	}

	if( strcmp(klt->get_nalichie_zernistosti().value, "зернистость двух видов") == 0 )
	{
		read_file(&inf,"kolichestvo_zeren.txt");
		klt->set_kolichestvo_zeren_1(inf);
		read_file(&inf,"razmer_zeren.txt");
		klt->set_razmer_zeren_1(inf);
		read_file(&inf,"okraska_zernistosti.txt");
		klt->set_okraska_zernistosti_1(inf);
		read_file(&inf,"kolichestvo_zeren.txt");
		klt->set_kolichestvo_zeren_2(inf);
		read_file(&inf,"razmer_zeren.txt");
		klt->set_razmer_zeren_2(inf);
		read_file(&inf,"okraska_zernistosti.txt");
		klt->set_okraska_zernistosti_2(inf);
	}
}



void get_info(kletka *klt)
{
	get_base(klt);
	get_yadro(klt);
	get_citoplazma(klt);
	get_zernistost(klt);
}

int main()
{
    setlocale(0, "Russian");
	kletka kletka1, kletka2;
	get_info(&kletka1);
	get_info(&kletka2);
	int tmp = kletka1 + kletka2;
	return 0;
}
