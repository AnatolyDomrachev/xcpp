#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct examen
{
	string name;
	float ocenka;
};

class Student
{
	private:
		string name;
		struct examen result[20];
		
	public:
		int ex_num ;

		void set_name();
		void set_exams(int count, string names[20]);
		stringstream get_exams();
		string get_name();
		void peresdacha();
	
		Student operator + (Student const &std);
		Student operator - (Student const &std);
		Student operator * (Student const &std);
};
