#include<fstream>
#include"utils.h"
#include"Student.h" 
#include"parser.h"
#include"global.h"
#include"loader.h"
#include <cstdlib>

using namespace std;

//#define null NULL

int main()
{
	vector<Student> tmpArray = Loader::LoadStudentsDB("d:\\students.txt"); //���� d, 

	string tmpLine = "............................................................................\n";
	string downLine ="____________________________________________________________________________\n";
	//-----------------------------------------------------------------------------
	//���� ��� �������� � ������� ���������� ��������.
	cout<< tmpLine;
	for(int i=0;i<tmpArray.size();i++)
	{
		cout << right << setw(3) <<i + 1 
			<< " " << left <<setw(37) << tmpArray[i].Name()
			<< tmpArray[i].GetMiddleRate() << '\n';
	}

	//-----------------------------------------------------------------------------
	//������ �������
	cout<< downLine;
	cout<<"Best student: \n";
	cout<< tmpLine;

	Utils::GetBestStudent(tmpArray).Show();

	//-----------------------------------------------------------------------------
	//����� �������
	cout<< downLine;
	cout<<"Worse student: \n";
	cout<< tmpLine;

	Utils::GetWorseStudent(tmpArray).Show();

	//-----------------------------------------------------------------------------
	//���������� �� ������ �� �������
	cout << downLine;
	cout<<"Normal sort: \n";
	cout<< tmpLine;
	vector<Student> sortedArray1 = Utils::OrderBy(tmpArray);

	for(int i=0;i<sortedArray1.size();i++)
		cout<<setw(40)<<sortedArray1[i].Name()<<" "<<sortedArray1[i].GetMiddleRate()<<'\n';

	//-----------------------------------------------------------------------------
	//���������� �� ������� �� ������
	cout << downLine;
	cout<<"Reverse sort: \n";
	cout<< tmpLine;

	vector<Student> sortedArray2 = Utils::OrderBy(tmpArray, true);

	for(int i=0;i<sortedArray2.size();i++)
		cout<<setw(40)<<sortedArray2[i].Name()<<" "<<sortedArray2[i].GetMiddleRate()<<'\n';

	//-----------------------------------------------------------------------------
	//���������� �� ������ �� ������� �� ���� � Electrical.
	cout << downLine;
	cout<<"Normal sort by rate[0]: \n";
	cout<< tmpLine;

	vector<Student> sortedArray3 = Utils::OrderByTraining(tmpArray,Utils::Electrical);

	for(int i=0;i<sortedArray3.size();i++)
		sortedArray3[i].Show();

	//-----------------------------------------------------------------------------
	//���������� �� ������� �� ������ �� ���� � Electrical.
	cout << downLine;
	cout<<"Reverse sort by rate[0]: \n";
	cout<< tmpLine;

	vector<Student> sortedArray4 = Utils::OrderByTraining(tmpArray,Utils::Electrical,true);

	for(int i=0;i<sortedArray4.size();i++)
		sortedArray4[i].Show();

	//-----------------------------------------------------------------------------
	//��������� ��� ��������, �� ����� ����.
	vector<Student> sesCompl = Utils::GetStudents(tmpArray, 80, true);
	cout << downLine;
	cout<<"session complete: \n";
	cout<< tmpLine;
	
	for(int i=0;i<sesCompl.size();i++)
		cout<<setw(40)<<sesCompl[i].Name()<<" "<<sesCompl[i].GetMiddleRate()<<endl;

	//-----------------------------------------------------------------------------
	//��������� ��������, �� �� ����� ����.
	vector<Student> sesNonCompl = Utils::GetStudents(tmpArray, 80, false);
	cout << downLine;
	cout<<"session not complete: \n";
	cout<< tmpLine;
	
	for(int i=0;i<sesNonCompl.size();i++)
		cout << setw(40)<<sesNonCompl[i].Name() << " " << sesNonCompl[i].GetMiddleRate() << endl;

	cout<<"\n\n";
	//-----------------------------------------------------------------------------
	//��������� ������ ��������, ��� ��� �� �������� Utils::Electrical ������ �� ��������� 80
	vector<Student> stdMFRBT = Utils::getStudentsMoreFrom_byTraining(tmpArray, 80,Utils::Electrical);
	cout << downLine;
	cout<<"more from rate : training index: "<< (int)Utils::Electrical <<": \n";
	cout<< tmpLine;
	for(int i=0;i<stdMFRBT.size();i++)
		cout << setw(40)<<stdMFRBT[i].Name() << " " << stdMFRBT[i].GetRateOfTraining((int)Utils::Electrical) << endl;
	cout<<"\n\n";
	//-----------------------------------------------------------------------------
	//��������� ������ ��������, ��� ��� �� �������� Utils::Electrical ������ �� ��������� 80
	vector<Student> stdLSBT = Utils::getStudentsLessThan_byTraining(tmpArray, 80,Utils::Electrical);
	cout << downLine;
	cout<<"less than, rate : training index: "<< Utils::Electrical <<": \n";
	cout<< tmpLine;
	for(int i=0;i<stdLSBT.size();i++)
		cout << setw(40) << stdLSBT[i].Name() << " " << stdLSBT[i].GetRateOfTraining((int)Utils::Electrical) << endl;
	cout<<"\n\n";
	cout << "\3\n";
	 system("pause");
	 return 0;
}