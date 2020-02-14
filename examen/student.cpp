#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "student.h"

using namespace std;

void Student::set_name()
{
	cout << "Введите имя студента: ";
	cin >> name;
}

void Student::set_exams(int count, string names[20])
{
	ex_num = count;
	for(int i = 0; i < ex_num; i++)
	{
		result[i].name = names[i];
		cout << "Введите оценку за экзамен " << names[i] << ": ";
		cin >> result[i].ocenka;
	}
}

stringstream Student::get_exams()
{
	stringstream sstr;
	for(int i = 0; i < ex_num; i++)
		sstr << result[i].name << ": " << result[i].ocenka << endl;
	return sstr;
}

string Student::get_name()
{
	return name;
}

void Student::peresdacha()
{
	int num;
	cout << "Выберите предмет:\n";

	for(int i = 0; i < ex_num; i++)
		cout << i << " " << result[i].name << ": " << result[i].ocenka << endl;

	cin >> num;

	cout << "Введите оценку за экзамен " << result[num].name << ": ";
	cin >> result[num].ocenka;
}


Student Student::operator + (Student const &student2) 
{
	Student max_oc;
	max_oc.name = "Группа";
	max_oc.ex_num = ex_num;

	for(int i = 0; i < ex_num; i++)
	{
		max_oc.result[i].name = result[i].name;
		max_oc.result[i].ocenka = max(result[i].ocenka, student2.result[i].ocenka);
	}


	return max_oc;
}

Student Student::operator - (Student const &student2) 
{
	Student min_oc;
	min_oc.name = "Группа";
	min_oc.ex_num = ex_num;

	for(int i = 0; i < ex_num; i++)
	{
		min_oc.result[i].name = result[i].name;
		min_oc.result[i].ocenka = min(result[i].ocenka, student2.result[i].ocenka);
	}


	return min_oc;
}

Student Student::operator * (Student const &student2) 
{
	Student sred_oc;
	sred_oc.name = "Группа";
	sred_oc.ex_num = ex_num;

	for(int i = 0; i < ex_num; i++)
	{
		sred_oc.result[i].name = result[i].name;
		sred_oc.result[i].ocenka = (result[i].ocenka + student2.result[i].ocenka)/2;
	}


	return sred_oc;
}
