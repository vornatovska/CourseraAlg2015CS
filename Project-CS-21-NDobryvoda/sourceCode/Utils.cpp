#include"utils.h"

//���� ������� �������� (�� ���������� ����)
Student Utils::GetBestStudent(vector<Student> _dbStudent)
{
	
	double  minMiddleRate = 0;

	int index = -1;
	for (int i = 0; i < _dbStudent.size(); i++)
		if (_dbStudent[i].GetMiddleRate() > minMiddleRate)
		{//���� � �������� ������� ��� ������ �� ������������ ������� ��� - �����'������� ���� ������
		//� ������� ������������ ��� �� ��� ����� ��������. 
		minMiddleRate = _dbStudent[i].GetMiddleRate();	
		index = i;
		}

	return _dbStudent[index];	//��������� ��������, ���� �� ��������� ���.
}

//���� ������ �������� (�� ���������� ����)
Student Utils::GetWorseStudent(vector<Student> _dbStudent)
{
	double  maxMiddleRate = 100;

	int index = -1;
	for (int i = 0; i < _dbStudent.size(); i++)
		if (_dbStudent[i].GetMiddleRate() < maxMiddleRate)
		{
		//���� � �������� ������� ��� ������ �� ��������� ������� ��� - �����'������� ���� ������
		//� ������� ��������� ��� �� ��� ����� ��������
		maxMiddleRate = _dbStudent[i].GetMiddleRate();
		index = i;
		}
	
	return _dbStudent[index];
}

 vector<Student> Utils::OrderBy(vector<Student> _dbStudent, bool reverse)
 {
	 for (int i = 0; i < _dbStudent.size() - 1; i++)
		 for (int j = i + 1; j < _dbStudent.size(); j++)
			 if (reverse)
			 {
		 //������� ������� ��� ���� ��������
		 if (_dbStudent[j].GetMiddleRate() > _dbStudent[i].GetMiddleRate())
		 {
			 Student tmp = _dbStudent[i];
			 _dbStudent[i] = _dbStudent[j];
			 _dbStudent[j] = tmp;
		 }
			 }
			 else
			 {
				 if (_dbStudent[j].GetMiddleRate() < _dbStudent[i].GetMiddleRate())
				 {
					 Student tmp = _dbStudent[i];
					 _dbStudent[i] = _dbStudent[j];
					 _dbStudent[j] = tmp;
				 }
			 }

	 return _dbStudent;
	
 }

 //���������� �������� �� ������ �� ������� �� ��������� ��������
 vector<Student> Utils::OrderByTraining(vector<Student> _dbStudent, Trainings trainingIndex, bool reverse)
 {
	 for (int i = 0; i < _dbStudent.size() - 1; i++)
		 for (int j = i + 1; j < _dbStudent.size(); j++)
			 if (reverse)
			 {
		 //������� ���� ��������  �� ��������� trainingIndex
		 if (_dbStudent[j].GetRateOfTraining(trainingIndex) > _dbStudent[i].GetRateOfTraining(trainingIndex))
		 {
			 Student tmp = _dbStudent[i];
			 _dbStudent[i] = _dbStudent[j];
			 _dbStudent[j] = tmp;
		 }
			 }
			 else
			 {
				 if (_dbStudent[j].GetRateOfTraining(trainingIndex) < _dbStudent[i].GetRateOfTraining(trainingIndex))
				 {
					 Student tmp = _dbStudent[i];
					 _dbStudent[i] = _dbStudent[j];
					 _dbStudent[j] = tmp;
				 }
			 }

	 return _dbStudent;
 }

 //���������� �������� �� ������� �� ������ �� ��������� ��������
 vector<Student> Utils::GetStudents(vector<Student> _dbStudent, double minMiddleRate, bool sessionComplete)
 {
	 return (sessionComplete) ?
		 GetStudetsMoreFromRate(_dbStudent, minMiddleRate) :
		 GetStudetsLessThanRate(_dbStudent, minMiddleRate);
 }

 //�� ��������, ��� ������� ������� ������-����� ��������� 
vector<Student> Utils::GetStudetsMoreFromRate(vector<Student> _dbStudent, double middleRate)
{
	vector<Student>resDB_students = vector<Student>();

	for (int i = 0; i < _dbStudent.size(); i++)
		if (_dbStudent[i].GetMiddleRate() >= middleRate) // ������� � ����� ������� ��� ����� ���� ��������� �������� � ����
			resDB_students.push_back(_dbStudent[i]);

	return resDB_students;
}

//�� ��������, ��� ������� ������� ������ �� ��������
vector<Student> Utils::GetStudetsLessThanRate(vector<Student> _dbStudents, double middleRate)
{
	vector<Student>resDB_students = vector<Student>();

	for (int i = 0; i < _dbStudents.size(); i++)
		if (_dbStudents[i].GetMiddleRate() < middleRate)
			resDB_students.push_back(_dbStudents[i]);

	return resDB_students;
}

//�� ��������, ��� ������� ������� ������-����� ��������� �������� �� �������� �������. 
vector<Student> Utils::getStudentsMoreFrom_byTraining(vector<Student> _dbStudent, int rate, Trainings indexOfTraining)
{
	vector<Student>resDB_students = vector<Student>();

	for (int i = 0; i < _dbStudent.size(); i++)
		if (_dbStudent[i].GetRate()[(int)indexOfTraining] >= rate)
			resDB_students.push_back(_dbStudent[i]);

	return resDB_students;
}

//�� ��������, ��� ������� ������� ������ �� �������� ������� �� �������� �������. 
vector<Student> Utils::getStudentsLessThan_byTraining(vector<Student> _dbStudents, int rate, Trainings indexOfTraining)
{
	vector<Student>resDB_students = vector<Student>();

	for (int i = 0; i < _dbStudents.size(); i++)
		if (_dbStudents[i].GetRate()[(int)indexOfTraining] < rate)
			resDB_students.push_back(_dbStudents[i]);

	return resDB_students;
}
