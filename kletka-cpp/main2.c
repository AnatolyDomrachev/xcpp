#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "kletka.h"

void getfiles(struct s_kletka* kletka)
{
	strcpy(kletka->base.tip_kletki.fname, "tip_kletki.txt" );
	strcpy(kletka->base.utochnenie_tipa1.fname, "Dlya_vsekh_kletok.txt" );
	strcpy(kletka->base.povtoryaemost_kletki.fname, "povtoryaemost_kletki.txt" );
	strcpy(kletka->base.uverennost_v_tipe.fname, "uverennost_v_tipe.txt" );
	strcpy(kletka->base.nedostatki_preparata.fname, "nedostatki_preparata.txt" );
	strcpy(kletka->yadro.celostnost_kletki.fname, "celostnost_kletki.txt" );
	strcpy(kletka->yadro.razmer_kletki.fname, "razmer_kletki.txt" );
	strcpy(kletka->yadro.forma_yadra.fname, "forma_yadra.txt" );
	strcpy(kletka->yadro.hromocentry.fname, "hromocentry.txt" );
	strcpy(kletka->yadro.yaderno_citoplazmaticheskoe_otnoshenie.fname, "yaderno_citoplazmaticheskoe_otnoshenie.txt" );
	strcpy(kletka->yadro.polozhenie_yadra_v_citoplazme.fname, "polozhenie_yadra_v_citoplazme.txt" );
	strcpy(kletka->yadro.klift.fname, "klift.txt" );
	strcpy(kletka->yadro.perinuklioparnoe_uplotnenie.fname, "perinuklioparnoe_uplotnenie.txt" );
	strcpy(kletka->yadro.grubost_hromatipa.fname, "grubost_hromatipa.txt" );
	strcpy(kletka->yadro.nukleoly.fname, "nukleoly.txt" );
	strcpy(kletka->citoplazma.kraya_citoplazmy.fname, "kraya_citoplazmy.txt" );
	strcpy(kletka->citoplazma.vakuolizaciya_citoplazmy.fname, "vakuolizaciya_citoplazmy.txt" );
	strcpy(kletka->citoplazma.okraska_citoplazmy.fname, "okraska_citoplazmy.txt" );
	strcpy(kletka->citoplazma.palochki_auehra.fname, "palochki_auehra.txt" );
	strcpy(kletka->citoplazma.perenaklearnoe_prosvetlenie.fname, "perenaklearnoe_prosvetlenie.txt" );
	strcpy(kletka->citoplazma.ten_na_citoplazme.fname, "ten_na_citoplazme.txt" );
	strcpy(kletka->citoplazma.nalichie_zernistosti.fname, "nalichie_zernistosti.txt" );

	int i;
	for(i=0;i<2;i++)
	{
		strcpy(kletka->zernistost[i].kolichestvo_zeren.fname, "kolichestvo_zeren.txt" );
		strcpy(kletka->zernistost[i].razmer_zeren.fname, "razmer_zeren.txt" );
		strcpy(kletka->zernistost[i].okraska_zernistosti.fname, "okraska_zernistosti.txt" );
	}
}

void read_file(struct info* inf)
{
	FILE* fin;
	int num = 0, index, res;
	char buf[NUM_VARS][STR_SIZE], buf2[STR_SIZE], buf3[STR_SIZE];
	char* c;

	sprintf(buf[0], "data2/%s", inf->fname);
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

void priznak_ne_zadan(struct info* inf)
{
	FILE* fin;
	int num = 0;
	char buf[STR_SIZE];
	char* c;

	sprintf(buf, "data2/%s", inf->fname);
	fin = fopen( buf , "r");
	if(!fin)
		perror(buf);
	fgets(buf, STR_SIZE, fin);
	strcpy(inf->name, buf);
	strcpy(inf->value, "признак не задан");
	fclose(fin);
}

void f_utochnenie_tipa(struct s_base* base)
{
	read_file(&base->utochnenie_tipa1);

	if( strcmp(base->tip_kletki.value,"Гранулоцит") == 0)
		strcpy(base->utochnenie_tipa2.fname , "utochnenie_tipa/Dlya_granulocitov.txt");
	else if( strcmp(base->tip_kletki.value,"Лимфоцит") == 0)
		strcpy(base->utochnenie_tipa2.fname , "utochnenie_tipa/Dlya_limfocitov.txt");
	else if( strcmp(base->tip_kletki.value,"Миелоцит") == 0)
		strcpy(base->utochnenie_tipa2.fname , "utochnenie_tipa/Dlya_mielocitov.txt");
	else if( strcmp(base->tip_kletki.value,"Моноцит") == 0)
		strcpy(base->utochnenie_tipa2.fname , "utochnenie_tipa/Dlya_monocitov.txt");
	else if( strcmp(base->tip_kletki.value,"Нормоцит") == 0)
		strcpy(base->utochnenie_tipa2.fname , "utochnenie_tipa/Dlya_normocitov.txt");
	else
		strcpy(base->utochnenie_tipa2.fname , "utochnenie_tipa/Dlya_ostalnyh.txt");

	read_file(&base->utochnenie_tipa2);
}

void get_info2(struct info2* inf2)
{
	int i;
	struct info inf;

	for(i=0; i< inf2->num; i++)
	{
		strcpy(inf.fname, inf2->fname);
		read_file(&inf);
		strcpy(inf2->name, inf.name);
		strcpy(inf2->value[i], inf.value);
	}
}

void get_base(struct s_base* base)
{
	read_file(&base->tip_kletki);
	f_utochnenie_tipa(base);
	read_file(&base->povtoryaemost_kletki);
	read_file(&base->uverennost_v_tipe);

	char buf2[5];
	int res;
	printf("Количество недостатков препарата (0-2): ");
	for(;;)
	{
	    char buf2[5];
        fgets(buf2, 5 ,stdin);
		fflush(stdin);
        res = sscanf(buf2, "%d", &base->nedostatki_preparata.num);
		if(res == 0 || base->nedostatki_preparata.num < 0 || base->nedostatki_preparata.num > 2)
			printf("Выберите значние из указанного диапазона\n");
		else
			break;
	}
	get_info2(&base->nedostatki_preparata);
}

void get_yadro(struct s_yadro* yadro)
{
	read_file(&yadro->celostnost_kletki);
	read_file(&yadro->razmer_kletki);
	read_file(&yadro->forma_yadra);
	read_file(&yadro->hromocentry);
	read_file(&yadro->yaderno_citoplazmaticheskoe_otnoshenie);
	read_file(&yadro->polozhenie_yadra_v_citoplazme);
	read_file(&yadro->klift);
	read_file(&yadro->perinuklioparnoe_uplotnenie);
	read_file(&yadro->grubost_hromatipa);

    char buf2[5];
	int res;
	printf("Количество нуклеолов (0-3): ");
	for(;;)
	{
        fgets(buf2, 5 ,stdin);
		fflush(stdin);
        res = sscanf(buf2, "%d", &yadro->nukleoly.num);
		if(res == 0 || yadro->nukleoly.num < 0 || yadro->nukleoly.num > 3)
			printf("Выберите значние из указанного диапазона\n");
		else
			break;
	}

	get_info2(&yadro->nukleoly);
}

void get_citoplazma(struct s_citoplazma* citoplazma)
{
	read_file(&citoplazma->kraya_citoplazmy);
	read_file(&citoplazma->vakuolizaciya_citoplazmy);
	read_file(&citoplazma->okraska_citoplazmy);
	read_file(&citoplazma->palochki_auehra);
	read_file(&citoplazma->perenaklearnoe_prosvetlenie);
	read_file(&citoplazma->ten_na_citoplazme);
	read_file(&citoplazma->nalichie_zernistosti);
}

void get_zernistost(struct s_zernistost* zernistost, struct info nalichie_zernistosti)
{
	int i;
	if( strcmp(nalichie_zernistosti.value, "Отсутствует") == 0 )
		for(i=0; i<2; i++)
		{
			priznak_ne_zadan(&zernistost[i].kolichestvo_zeren);
			priznak_ne_zadan(&zernistost[i].razmer_zeren);
			priznak_ne_zadan(&zernistost[i].okraska_zernistosti);

		}

	if( strcmp(nalichie_zernistosti.value, "зернистость одного вида") == 0 )
	{
			read_file(&zernistost[0].kolichestvo_zeren);
			read_file(&zernistost[0].razmer_zeren);
			read_file(&zernistost[0].okraska_zernistosti);
			priznak_ne_zadan(&zernistost[1].kolichestvo_zeren);
			priznak_ne_zadan(&zernistost[1].razmer_zeren);
			priznak_ne_zadan(&zernistost[1].okraska_zernistosti);
	}

	if( strcmp(nalichie_zernistosti.value, "зернистость двух видов") == 0 )
		for(i=0; i<2; i++)
		{
			read_file(&zernistost[i].kolichestvo_zeren);
			read_file(&zernistost[i].razmer_zeren);
			read_file(&zernistost[i].okraska_zernistosti);
		}
}

void get_info(struct s_kletka* kletka)
{
	get_base(&kletka->base);
	get_yadro(&kletka->yadro);
	get_citoplazma(&kletka->citoplazma);
	get_zernistost(kletka->zernistost, kletka->citoplazma.nalichie_zernistosti);
}

sravnenie_info(struct info inf1, struct info inf2)
{
	char buf[50];
	if(strcmp(inf1.value, inf2.value) == 0)
		strcpy(buf, "Совпадают");
	else
		strcpy(buf, "Не совпадают");
	printf("\n%s\n\t%s | %s | %s\n", inf1.name, inf1.value, inf2.value, buf);
}

sravnenie_info2(struct info2 inf1, struct info2 inf2)
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

sravnenie_base(struct s_base base1, struct s_base base2)
{
	sravnenie_info(base1.tip_kletki, base2.tip_kletki);
	sravnenie_info(base1.utochnenie_tipa1, base2.utochnenie_tipa1);
	sravnenie_info(base1.utochnenie_tipa2, base2.utochnenie_tipa2);
	sravnenie_info(base1.povtoryaemost_kletki, base2.povtoryaemost_kletki);
	sravnenie_info(base1.uverennost_v_tipe, base2.uverennost_v_tipe);
	sravnenie_info2(base1.nedostatki_preparata, base2.nedostatki_preparata);
}

sravnenie_yadro(struct s_yadro yadro1, struct s_yadro yadro2)
{
	sravnenie_info(yadro1.celostnost_kletki, yadro2.celostnost_kletki);
	sravnenie_info(yadro1.razmer_kletki, yadro2.razmer_kletki);
	sravnenie_info(yadro1.forma_yadra, yadro2.forma_yadra);
	sravnenie_info(yadro1.hromocentry, yadro2.hromocentry);
	sravnenie_info2(yadro1.nukleoly, yadro2.nukleoly);
}

sravnenie_citoplazma(struct s_citoplazma citoplazma1, struct s_citoplazma citoplazma2)
{
	sravnenie_info(citoplazma1.kraya_citoplazmy, citoplazma2.kraya_citoplazmy);
	sravnenie_info(citoplazma1.vakuolizaciya_citoplazmy, citoplazma2.vakuolizaciya_citoplazmy);
	sravnenie_info(citoplazma1.okraska_citoplazmy, citoplazma2.okraska_citoplazmy);
	sravnenie_info(citoplazma1.palochki_auehra, citoplazma2.palochki_auehra);
	sravnenie_info(citoplazma1.perenaklearnoe_prosvetlenie, citoplazma2.perenaklearnoe_prosvetlenie);
	sravnenie_info(citoplazma1.ten_na_citoplazme, citoplazma2.ten_na_citoplazme);
	sravnenie_info(citoplazma1.nalichie_zernistosti, citoplazma2.nalichie_zernistosti);
}

sravnenie_zernistost(struct s_zernistost* zernistost1, struct s_zernistost* zernistost2)
{
	int i;
	for(i=0; i<2; i++)
	{
		sravnenie_info(zernistost1[i].kolichestvo_zeren, zernistost2[i].kolichestvo_zeren);
		sravnenie_info(zernistost1[i].razmer_zeren, zernistost2[i].razmer_zeren);
		sravnenie_info(zernistost1[i].okraska_zernistosti, zernistost2[i].okraska_zernistosti);
	}
}

void sravnenie(struct s_kletka kletka1, struct s_kletka kletka2)
{
	sravnenie_base(kletka1.base, kletka2.base);
	sravnenie_yadro(kletka1.yadro, kletka2.yadro);
	sravnenie_citoplazma(kletka1.citoplazma, kletka2.citoplazma);
	sravnenie_zernistost(kletka1.zernistost, kletka2.zernistost);
}

int main()
{
    setlocale(0, "Russian");
	struct s_kletka kletka1, kletka2;
	getfiles(&kletka1);
	getfiles(&kletka2);
	get_info(&kletka1);
	get_info(&kletka2);
	sravnenie(kletka1, kletka2);
	return 0;
}

