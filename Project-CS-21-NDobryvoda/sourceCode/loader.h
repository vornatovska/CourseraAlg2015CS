#include<fstream>
#include"global.h"
#include"Student.h"

class Loader
{
public:
	//������������ ��������
	//RELEASE
	static vector<Student> LoadStudentsDB(string _pathOfBD);
};