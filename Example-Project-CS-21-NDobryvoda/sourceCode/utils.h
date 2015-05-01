#include"global.h"
#include"Student.h"

class Utils
{
public:
	enum Trainings {
		Electrical,
		PhysicalEducation,
		UkrainianLanguage,
		TIMS,
		English,
		Mathematics,
		Programming,
		Physics,
		Politics,
		German
	};

	static Student GetBestStudent(vector<Student> _dbStudent);
	static Student GetWorseStudent(vector<Student> _dbStudent);
	static vector<Student> OrderBy(vector<Student> _dbStudent, bool reverse = false);
	static vector<Student> OrderByTraining(vector<Student> _dbStudent, Trainings trainingIndex, bool reverse = false);
	static vector<Student> GetStudents(vector<Student> _dbStudent, double minMiddleRate, bool sessionComplete);
	static vector<Student> GetStudetsMoreFromRate(vector<Student> _dbStudent, double middleRate);
	static vector<Student> GetStudetsLessThanRate(vector<Student> _dbStudents, double middleRate);
	static vector<Student> getStudentsMoreFrom_byTraining(vector<Student> _dbStudent, int rate, Trainings indexOfTraining);
	static vector<Student> getStudentsLessThan_byTraining(vector<Student> _dbStudents, int rate, Trainings indexOfTraining);
};
