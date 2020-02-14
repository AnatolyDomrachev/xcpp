#include <stdio.h>
#include <ctype.h>
#include <locale>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int A = 26; // Размер кодируемого алфавита

string new_gamma(string gamma,string  text)
{
	while(gamma.length() < text.length())
		gamma = gamma + gamma;
	return gamma;
}

// Шифрование строки in по ключу gamma
string encode(const string & in, const string & gamma) { //Возвращает строку, так как в начале написано string
	string result; // Результат в него будут добавляться зашифрованные символы
	unsigned char newc; //символ, получаемый в результате шифрования

	for (int i = 0; i < in.length(); i++) { // Перебираем символы строки
		if (in[i] >= 'a' && in[i] <= 'z') { // Если это символ алфавита в нижнем регистре
			//result += ('a' + ((in[i]-'a') + (gamma[g]-'a')) % A); // то гаммируем вычисляем по формуле алгоритма шифрования Вижинера
			newc = in[i] + (gamma[i] - 'a');
			if(newc > 'z')
				newc = newc - ('z' - 'a');
			result += newc; // то гаммируем вычисляем по формуле алгоритма шифрования Вижинера
		} else // если условие в if не выполняется
			result += in[i]; // оставляем символ без изменений
	}

	return result;//возвращаем зашифрованную строку в то место, откуда была вызвана функция encode
}

// Дешифрование строки in по ключу gamma
string decode(const string & in, const string & gamma) {
	string result; // Результат
	char newc; //символ, получаемый в результате шифрования

	for (int i = 0; i < in.length(); i++) { // Перебираем символы строки
		if (in[i] >= 'a' && in[i] <= 'z') { // Если это символ алфавита в нижнем регистре
			//result += ('a' + ((A + (in[i]-'a') - (gamma[g]-'a')) % A)); // то дегаммируем
			//g = (g + 1) % gamma.length();
			newc = in[i] - (gamma[i] - 'a');
			if(newc < 'a')
				newc = newc + 'z'-'a';
			result += newc; // то гаммируем вычисляем по формуле алгоритма шифрования Вижинера
		} else // иначе
			result += in[i]; // оставляем символ без изменений
	}

	return result;
}

// Функция , которая сперва выводит приглашение msg, затем вводит имя файла и пытается прочитать из него строку text
// Возвращает флаг успешности данной операции
bool input(const string & msg, string & text) {
	ifstream in; // Входной файл
	string fname; // Имя файла

	cout << msg; // Выводим приглашение
	fflush(stdin); // На всякий случай сбрасываем буфер ввода
	cin >> fname; // Вводим имя файла

	in.open(fname.c_str()); // Пытаемся открыть файл
	if (in) { // Если открыли файл успешно
		getline(in, text); // Читаем из файла строку текста
		in.close(); // Файл закрываем
		return true; // Возвращаем признак успеха //возвращаемя в то место функции main откуда эта функция была вызвана
	} else { // Если не смогли открыть файл
		cout << "Не удалось открыть файл!" << endl;
		return false; // Возвращаем признак неуспеха
	}
}

int main() { // Должна обязательно быть в программе. С неё начинается выполнение.

	// Объявление переменны. Нужно обьявить перед использованием.
	string text; // Строка текста
	string gamma; // Строка текста
	int choise; // Номер выбранного пункта меню int -целое число

	// Устанавливаем русский шрифт в консоли
	setlocale(LC_ALL, "Ru-ru");

	do { // Цикл главного меню
		cout << "1. Шифровать файл" << endl; // вывод на экран
		cout << "2. Дешифровать файл" << endl;
		cout << "3. Выход" << endl;
		cout << endl; //переход на новую строку

		cout << "Ваш выбор = ";
		fflush(stdin); // На всякий случай сбрасываем буфер ввода
		cin >> choise; // ввод числа

		switch (choise) {
			case 1: { // Шифрование
				// Ввод имен файлов с текстом и с гаммой
				if (!input("Имя файла с текстом для шифрования = ", text)) break;
				if (!input("Имя файла с гаммой = ", gamma)) break;
				gamma = new_gamma(gamma, text);//дополняем гамму до длинны текста
				string encoded = encode(text, gamma); // Кодированный текст заносится в переменную encoded
				cout << "Получили: " << encoded << endl;//вывод на экран
				break;
			}
			case 2: { // Дешифрование
				// Ввод имен файлов с текстом и с гаммой
				if (!input("Имя файла с текстом для дешифрования = ", text)) break;
				if (!input("Имя файла с гаммой = ", gamma)) break;
				string decoded = decode(text, gamma); // Декодированный текст
				cout << "Получили: " << decoded << endl;
				break;
			}
			case 3: break; // Просто выход
			default: // Любой иной выбор
				cout << "Неверный номер пункта меню!" << endl;
		}
	} while (choise != 3);

	getchar(); // Ждем нажатия Enter
	return 0;
}

