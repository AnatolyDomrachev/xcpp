#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "kletka.h"

using namespace std;

void kletka::sravnenie_info(struct info inf1, struct info inf2)
{
	char buf[50];
	if(strcmp(inf1.value, inf2.value) == 0)
		strcpy(buf, "Совпадают");
	else
		strcpy(buf, "Не совпадают");
	printf("\n%s\n\t%s | %s | %s\n", inf1.name, inf1.value, inf2.value, buf);
}

void kletka::sravnenie_info2(struct info2 inf1, struct info2 inf2)
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

int kletka::operator + (kletka const &kletka2) {
	sravnenie_info(base.tip_kletki, kletka2.base.tip_kletki);
	sravnenie_info(base.utochnenie_tipa1, kletka2.base.utochnenie_tipa1);
	sravnenie_info(base.utochnenie_tipa2, kletka2.base.utochnenie_tipa2);
	sravnenie_info(base.povtoryaemost_kletki, kletka2.base.povtoryaemost_kletki);
	sravnenie_info(base.uverennost_v_tipe, kletka2.base.uverennost_v_tipe);
	sravnenie_info2(base.nedostatki_preparata, kletka2.base.nedostatki_preparata);
	sravnenie_info(yadro.celostnost_kletki, kletka2.yadro.celostnost_kletki);
	sravnenie_info(yadro.razmer_kletki, kletka2.yadro.razmer_kletki);
	sravnenie_info(yadro.forma_yadra, kletka2.yadro.forma_yadra);
	sravnenie_info(yadro.hromocentry, kletka2.yadro.hromocentry);
	sravnenie_info(yadro.yaderno_citoplazmaticheskoe_otnoshenie, kletka2.yadro.yaderno_citoplazmaticheskoe_otnoshenie);
	sravnenie_info(yadro.polozhenie_yadra_v_citoplazme, kletka2.yadro.polozhenie_yadra_v_citoplazme);
	sravnenie_info(yadro.klift, kletka2.yadro.klift);
	sravnenie_info(yadro.perinuklioparnoe_uplotnenie, kletka2.yadro.perinuklioparnoe_uplotnenie);
	sravnenie_info(yadro.grubost_hromatipa, kletka2.yadro.grubost_hromatipa);
	sravnenie_info2(yadro.nukleoly, kletka2.yadro.nukleoly);
	sravnenie_info(citoplazma.kraya_citoplazmy, kletka2.citoplazma.kraya_citoplazmy);
	sravnenie_info(citoplazma.vakuolizaciya_citoplazmy, kletka2.citoplazma.vakuolizaciya_citoplazmy);
	sravnenie_info(citoplazma.okraska_citoplazmy, kletka2.citoplazma.okraska_citoplazmy);
	sravnenie_info(citoplazma.palochki_auehra, kletka2.citoplazma.palochki_auehra);
	sravnenie_info(citoplazma.perenaklearnoe_prosvetlenie, kletka2.citoplazma.perenaklearnoe_prosvetlenie);
	sravnenie_info(citoplazma.ten_na_citoplazme, kletka2.citoplazma.ten_na_citoplazme);
	sravnenie_info(citoplazma.nalichie_zernistosti, kletka2.citoplazma.nalichie_zernistosti);

	for(int i = 0 ; i<2; i++)
	{
		sravnenie_info(zernistost[i].kolichestvo_zeren, kletka2.zernistost[i].kolichestvo_zeren);
		sravnenie_info(zernistost[i].razmer_zeren, kletka2.zernistost[i].razmer_zeren);
		sravnenie_info(zernistost[i].okraska_zernistosti, kletka2.zernistost[i].okraska_zernistosti);
	}
}

struct info kletka::get_tip_kletki() {
    return base.tip_kletki;
}
struct info kletka::get_utochnenie_tipa1() {
    return base.utochnenie_tipa1;
}
struct info kletka::get_utochnenie_tipa2() {
    return base.utochnenie_tipa2;
}
struct info kletka::get_povtoryaemost_kletki() {
    return base.povtoryaemost_kletki;
}
struct info kletka::get_uverennost_v_tipe() {
    return base.uverennost_v_tipe;
}
struct info2 kletka::get_nedostatki_preparata() {
    return base.nedostatki_preparata;
}
struct info kletka::get_celostnost_kletki() {
    return yadro.celostnost_kletki;
}
struct info kletka::get_razmer_kletki() {
    return yadro.razmer_kletki;
}
struct info kletka::get_forma_yadra() {
    return yadro.forma_yadra;
}
struct info kletka::get_hromocentry() {
    return yadro.hromocentry;
}
struct info kletka::get_yaderno_citoplazmaticheskoe_otnoshenie() {
    return yadro.yaderno_citoplazmaticheskoe_otnoshenie;
}
struct info kletka::get_polozhenie_yadra_v_citoplazme() {
    return yadro.polozhenie_yadra_v_citoplazme;
}
struct info kletka::get_klift() {
    return yadro.klift;
}
struct info kletka::get_perinuklioparnoe_uplotnenie() {
    return yadro.perinuklioparnoe_uplotnenie;
}
struct info kletka::get_grubost_hromatipa() {
    return yadro.grubost_hromatipa;
}
struct info2 kletka::get_nukleoly() {
    return yadro.nukleoly;
}
struct info kletka::get_kraya_citoplazmy() {
    return citoplazma.kraya_citoplazmy;
}
struct info kletka::get_vakuolizaciya_citoplazmy() {
    return citoplazma.vakuolizaciya_citoplazmy;
}
struct info kletka::get_okraska_citoplazmy() {
    return citoplazma.okraska_citoplazmy;
}
struct info kletka::get_palochki_auehra() {
    return citoplazma.palochki_auehra;
}
struct info kletka::get_perenaklearnoe_prosvetlenie() {
    return citoplazma.perenaklearnoe_prosvetlenie;
}
struct info kletka::get_ten_na_citoplazme() {
    return citoplazma.ten_na_citoplazme;
}
struct info kletka::get_nalichie_zernistosti() {
    return citoplazma.nalichie_zernistosti;
}
struct info kletka::get_kolichestvo_zeren_1() {
    return zernistost[0].kolichestvo_zeren;
}
struct info kletka::get_razmer_zeren_1() {
    return zernistost[0].razmer_zeren;
}
struct info kletka::get_okraska_zernistosti_1() {
    return zernistost[0].okraska_zernistosti;
}
struct info kletka::get_kolichestvo_zeren_2() {
    return zernistost[1].kolichestvo_zeren;
}
struct info kletka::get_razmer_zeren_2() {
    return zernistost[1].razmer_zeren;
}
struct info kletka::get_okraska_zernistosti_2() {
    return zernistost[1].okraska_zernistosti;
}///////////////////////

void kletka::set_tip_kletki(struct info inf) {
    memcpy(&base.tip_kletki, &inf, sizeof(inf)) ;
}void kletka::set_utochnenie_tipa1(struct info inf) {
    memcpy(&base.utochnenie_tipa1, &inf, sizeof(inf)) ;
}
void kletka::set_utochnenie_tipa2(struct info inf) {
    memcpy(&base.utochnenie_tipa2, &inf, sizeof(inf)) ;
}
void kletka::set_povtoryaemost_kletki(struct info inf) {
    memcpy(&base.povtoryaemost_kletki, &inf, sizeof(inf)) ;
}
void kletka::set_uverennost_v_tipe(struct info inf) {
    memcpy(&base.uverennost_v_tipe, &inf, sizeof(inf)) ;
}
void kletka::set_nedostatki_preparata(struct info2 inf) {
    memcpy(&base.nedostatki_preparata, &inf, sizeof(inf)) ;
}
void kletka::set_celostnost_kletki(struct info inf) {
    memcpy(&yadro.celostnost_kletki, &inf, sizeof(inf)) ;
}
void kletka::set_razmer_kletki(struct info inf) {
    memcpy(&yadro.razmer_kletki, &inf, sizeof(inf)) ;
}
void kletka::set_forma_yadra(struct info inf) {
    memcpy(&yadro.forma_yadra, &inf, sizeof(inf)) ;
}
void kletka::set_hromocentry(struct info inf) {
    memcpy(&yadro.hromocentry, &inf, sizeof(inf)) ;
}
void kletka::set_yaderno_citoplazmaticheskoe_otnoshenie(struct info inf) {
    memcpy(&yadro.yaderno_citoplazmaticheskoe_otnoshenie, &inf, sizeof(inf)) ;
}
void kletka::set_polozhenie_yadra_v_citoplazme(struct info inf) {
    memcpy(&yadro.polozhenie_yadra_v_citoplazme, &inf, sizeof(inf)) ;
}
void kletka::set_klift(struct info inf) {
    memcpy(&yadro.klift, &inf, sizeof(inf)) ;
}
void kletka::set_perinuklioparnoe_uplotnenie(struct info inf) {
    memcpy(&yadro.perinuklioparnoe_uplotnenie, &inf, sizeof(inf)) ;
}
void kletka::set_grubost_hromatipa(struct info inf) {
    memcpy(&yadro.grubost_hromatipa, &inf, sizeof(inf)) ;
}
void kletka::set_nukleoly(struct info2 inf) {
    memcpy(&yadro.nukleoly, &inf, sizeof(inf)) ;
}
void kletka::set_kraya_citoplazmy(struct info inf) {
    memcpy(&citoplazma.kraya_citoplazmy, &inf, sizeof(inf)) ;
}
void kletka::set_vakuolizaciya_citoplazmy(struct info inf) {
    memcpy(&citoplazma.vakuolizaciya_citoplazmy, &inf, sizeof(inf)) ;
}
void kletka::set_okraska_citoplazmy(struct info inf) {
    memcpy(&citoplazma.okraska_citoplazmy, &inf, sizeof(inf)) ;
}
void kletka::set_palochki_auehra(struct info inf) {
    memcpy(&citoplazma.palochki_auehra, &inf, sizeof(inf)) ;
}
void kletka::set_perenaklearnoe_prosvetlenie(struct info inf) {
    memcpy(&citoplazma.perenaklearnoe_prosvetlenie, &inf, sizeof(inf)) ;
}
void kletka::set_ten_na_citoplazme(struct info inf) {
    memcpy(&citoplazma.ten_na_citoplazme, &inf, sizeof(inf)) ;
}
void kletka::set_nalichie_zernistosti(struct info inf) {
    memcpy(&citoplazma.nalichie_zernistosti, &inf, sizeof(inf)) ;
}
void kletka::set_kolichestvo_zeren_1(struct info inf) {
    memcpy(&zernistost[0].kolichestvo_zeren, &inf, sizeof(inf)) ;
}
void kletka::set_razmer_zeren_1(struct info inf) {
    memcpy(&zernistost[0].razmer_zeren, &inf, sizeof(inf)) ;
}
void kletka::set_okraska_zernistosti_1(struct info inf) {
    memcpy(&zernistost[0].okraska_zernistosti, &inf, sizeof(inf)) ;
}
void kletka::set_kolichestvo_zeren_2(struct info inf) {
    memcpy(&zernistost[1].kolichestvo_zeren, &inf, sizeof(inf)) ;
}
void kletka::set_razmer_zeren_2(struct info inf) {
    memcpy(&zernistost[1].razmer_zeren, &inf, sizeof(inf)) ;
}
void kletka::set_okraska_zernistosti_2(struct info inf) {
    memcpy(&zernistost[1].okraska_zernistosti, &inf, sizeof(inf)) ;
}
