#include <fstream>
#include <locale.h>
#include "student.h"

void set_data(int* stud_num, string* exams, Student* group)
{
	cout << "Введите количество студентов: ";
	cin >> *stud_num;

	int ex_num;

	cout << "Введите количество экзаменов: ";
	cin >> ex_num;

	for(int i=0; i<ex_num; i++)
	{
		cout << "Введите название экзамена: ";
		cin >> exams[i];
	}
		
	for(int i = 0; i < *stud_num; i++)
	{
		group[i].set_name();
		group[i].set_exams(ex_num, exams);
	}
}

void get_data(int stud_num, Student* group)
{
	Student oc_max, oc_min, oc_sr;
	stringstream sstr;

	oc_max = oc_min = oc_sr = group[0];
	cout << "Оценки группы\n";

	for(int i = 0; i<stud_num; i++)
	{
		cout << group[i].get_name() << endl;
		sstr = group[i].get_exams();
		cout << sstr.str();
	}

	for(int i = 1; i<stud_num; i++)
	{
		oc_max =group[i] + oc_max  ;
		oc_min = group[i] - oc_min ;
		oc_sr = group[i] * oc_sr;
	}

	cout << endl;
	cout << "Оценки группы максимальные\n";
	sstr = oc_max.get_exams();
	cout << sstr.str();
	cout << "Оценки группы минимальные\n";
	sstr = oc_min.get_exams();
	cout << sstr.str();
	cout << "Оценки группы средние\n";
	sstr = oc_sr.get_exams();
	cout << sstr.str();
}

void zapis_file(int stud_num, Student* group)
{
	char fname[50];

	cout << "Введите имя файла: ";
	cin >> fname;
	ofstream fout (fname);
	
	Student oc_max, oc_min, oc_sr;
	stringstream sstr;

	oc_max = oc_min = oc_sr = group[0];
	fout << "Оценки группы\n";

	for(int i = 0; i<stud_num; i++)
	{
		sstr = group[i].get_exams();
		fout << sstr.str();
	}

	for(int i = 1; i<stud_num; i++)
	{
		oc_max =group[i] + oc_max  ;
		oc_min = group[i] - oc_min ;
		oc_sr = group[i] * oc_sr;
	}

	fout << endl;
	fout << "Оценки группы максимальные\n";
	sstr = oc_max.get_exams();
	fout << sstr.str();
	fout << "Оценки группы минимальные\n";
	sstr = oc_min.get_exams();
	fout << sstr.str();
	fout << "Оценки группы средние\n";
	sstr = oc_sr.get_exams();
	fout << sstr.str();
}

void peresdacha(int stud_num, Student* group)
{
	int num;
	cout << "Выберите стyдента:\n";

	for(int i = 0; i < stud_num; i++)
		cout << i << " " << group[i].get_name() << endl;

	cin >> num;
	group[num].peresdacha();
}

int main()
{
	setlocale(0, "Russian");

	int stud_num, vvod;
	Student group[40];
	string exams[20];

	set_data(&stud_num, exams, group);

	while(1)
	{
		cout << "1 - Печать резyльтатов\n";
		cout << "2 - Пересдача\n";
		cout << "3 - Запись в файл\n";
		cout << "4 - Выход\n";
		cin >> vvod;
		if(vvod == 1)
			get_data(stud_num, group);
		else if(vvod == 2)
			peresdacha(stud_num, group);
		else if(vvod == 3)
			zapis_file(stud_num, group);
		else if(vvod == 4)
			break;
		else
			cout << "Неверный ввод\n" ;
	}

	return 0;
}
