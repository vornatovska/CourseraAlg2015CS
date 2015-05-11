#include"utils.h"

//вивід кращого студента (по середньому балу)
Student Utils::GetBestStudent(vector<Student> _dbStudent)
{
	
	double  minMiddleRate = 0;

	int index = -1;
	for (int i = 0; i < _dbStudent.size(); i++)
		if (_dbStudent[i].GetMiddleRate() > minMiddleRate)
		{//якщо в студента середній бал більший ніж максимальний середній бал - запам'ятовуємо його інтекс
		//і змінюємо максимальний бал на бал цього студента. 
		minMiddleRate = _dbStudent[i].GetMiddleRate();	
		index = i;
		}

	return _dbStudent[index];	//повертаємо студента, який має найбільший бал.
}

//вивід гіршого студента (по середньому балу)
Student Utils::GetWorseStudent(vector<Student> _dbStudent)
{
	double  maxMiddleRate = 100;

	int index = -1;
	for (int i = 0; i < _dbStudent.size(); i++)
		if (_dbStudent[i].GetMiddleRate() < maxMiddleRate)
		{
		//якщо в студента середній бал менший ніж найменший середній бал - запам'ятовуємо його індекс
		//і змінюємо мінімальний бал на бал цього студента
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
		 //порівнює середній бал двох студентів
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

 //сортування студентів від гіршого до кращого по вказаному предмету
 vector<Student> Utils::OrderByTraining(vector<Student> _dbStudent, Trainings trainingIndex, bool reverse)
 {
	 for (int i = 0; i < _dbStudent.size() - 1; i++)
		 for (int j = i + 1; j < _dbStudent.size(); j++)
			 if (reverse)
			 {
		 //порівнює бали студентів  по вказаному trainingIndex
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

 //сортування студентів від кращого до гіршого по вказаному предмету
 vector<Student> Utils::GetStudents(vector<Student> _dbStudent, double minMiddleRate, bool sessionComplete)
 {
	 return (sessionComplete) ?
		 GetStudetsMoreFromRate(_dbStudent, minMiddleRate) :
		 GetStudetsLessThanRate(_dbStudent, minMiddleRate);
 }

 //всі студенти, чий середній рейтинг більший-рівний вказаному 
vector<Student> Utils::GetStudetsMoreFromRate(vector<Student> _dbStudent, double middleRate)
{
	vector<Student>resDB_students = vector<Student>();

	for (int i = 0; i < _dbStudent.size(); i++)
		if (_dbStudent[i].GetMiddleRate() >= middleRate) // студент в якого середній бал більше рівне вказаного додається в базу
			resDB_students.push_back(_dbStudent[i]);

	return resDB_students;
}

//всі студенти, чий середній рейтинг менший ніж вказаний
vector<Student> Utils::GetStudetsLessThanRate(vector<Student> _dbStudents, double middleRate)
{
	vector<Student>resDB_students = vector<Student>();

	for (int i = 0; i < _dbStudents.size(); i++)
		if (_dbStudents[i].GetMiddleRate() < middleRate)
			resDB_students.push_back(_dbStudents[i]);

	return resDB_students;
}

//всі студенти, чий середній рейтинг більший-рівний вказаному рейтингу по заданому предету. 
vector<Student> Utils::getStudentsMoreFrom_byTraining(vector<Student> _dbStudent, int rate, Trainings indexOfTraining)
{
	vector<Student>resDB_students = vector<Student>();

	for (int i = 0; i < _dbStudent.size(); i++)
		if (_dbStudent[i].GetRate()[(int)indexOfTraining] >= rate)
			resDB_students.push_back(_dbStudent[i]);

	return resDB_students;
}

//всі студенти, чий середній рейтинг менший за вказаний рейтинг по заданому предету. 
vector<Student> Utils::getStudentsLessThan_byTraining(vector<Student> _dbStudents, int rate, Trainings indexOfTraining)
{
	vector<Student>resDB_students = vector<Student>();

	for (int i = 0; i < _dbStudents.size(); i++)
		if (_dbStudents[i].GetRate()[(int)indexOfTraining] < rate)
			resDB_students.push_back(_dbStudents[i]);

	return resDB_students;
}
