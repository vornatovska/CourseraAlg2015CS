#include"loader.h"
#include"parser.h"

vector<Student> Loader::LoadStudentsDB(string _pathOfBD)
{
	//����� �����, � ���� �������� ��'� � �������.
	vector<string> lines = vector<string>();	

	char* tmpLine = new char[200];

	ifstream* DBfile = new ifstream();


	try {

		// �������� ����� � �������� try ��� ������������ �������� �������
		DBfile->open(_pathOfBD);

		// "���������" ������� ��� �� ������� �����
		if (! DBfile->is_open() ) throw string("Can't open file");

		// ������� ������ � ����� �����
		while(!DBfile->eof())
		{
			if(DBfile->getline(tmpLine,200))
				lines.push_back(string(tmpLine));
		}
	}

	// ������������ "��������� �������" �� ���� ������� �� �����, ����� � �����
	catch(string err){
		cout << err << '\n';
		system("pause");
		exit(1);
	}


	//��������� � ��������� ����
	DBfile->close();
	delete DBfile;
	DBfile = NULL;

	//����� ��������
	vector<Student> studentDB = vector<Student>();

	//��������� ������� ����� ������, ��������� ��'� � 
	//������� �������� � ����� ��������� �������� + �������� ���� � �����.
	for(int i=0;i<lines.size();i++)
		studentDB.push_back(Student(Parser::GetName(lines[i]),	Parser::GetRate(lines[i])));

	//��������� ����� ������ (�� ��� ����� �� �������)

	return studentDB;
}