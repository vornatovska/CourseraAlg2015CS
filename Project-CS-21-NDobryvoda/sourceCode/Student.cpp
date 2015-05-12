#include"Student.h"
#include<string>
using namespace std;
//створення нового студента (конструктор)
Student::Student(string _name, vector<int> _rate)
{
	this->name = _name;
	this->rate = _rate;
} 

//вивід рейтингу по вказаному предмету
int Student::GetRateOfTraining(int trainingIndex)
{
	return (trainingIndex < rate.size()) ? this->rate[trainingIndex] : -1;
}

//вивід середнього балу по всім предметам
double Student::GetMiddleRate()
{
	double tmpMiddleRate = 0;

	for (int i = 0; i < this->rate.size(); i++)
		tmpMiddleRate += ((double)this->rate[i]);

	return tmpMiddleRate /= ((double)(this->rate.size()));
}
	
//вивід на екран інформації про студента
void Student::Show()
{
	cout <<setw(40) <<this->name << " ";
	for (int i = 0; i < this->rate.size(); i++)
		cout << rate[i] << ' ';
	cout << endl;
}
	
//вивід імені студента
string Student::Name()
{
	return this->name;
}

//вивід списку оцінок студента
vector<int> Student::GetRate()
{
	return this->rate;
}
