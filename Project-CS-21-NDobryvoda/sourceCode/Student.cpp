#include"Student.h"
#include<string>
using namespace std;
//��������� ������ �������� (�����������)
Student::Student(string _name, vector<int> _rate)
{
	this->name = _name;
	this->rate = _rate;
} 

//���� �������� �� ��������� ��������
int Student::GetRateOfTraining(int trainingIndex)
{
	return (trainingIndex < rate.size()) ? this->rate[trainingIndex] : -1;
}

//���� ���������� ���� �� ��� ���������
double Student::GetMiddleRate()
{
	double tmpMiddleRate = 0;

	for (int i = 0; i < this->rate.size(); i++)
		tmpMiddleRate += ((double)this->rate[i]);

	return tmpMiddleRate /= ((double)(this->rate.size()));
}
	
//���� �� ����� ���������� ��� ��������
void Student::Show()
{
	cout <<setw(40) <<this->name << " ";
	for (int i = 0; i < this->rate.size(); i++)
		cout << rate[i] << ' ';
	cout << endl;
}
	
//���� ���� ��������
string Student::Name()
{
	return this->name;
}

//���� ������ ������ ��������
vector<int> Student::GetRate()
{
	return this->rate;
}
