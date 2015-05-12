#include"loader.h"
#include"parser.h"

vector<Student> Loader::LoadStudentsDB(string _pathOfBD)
{
	//масив стічок, в яких міститься ім'я і рейтинг.
	vector<string> lines = vector<string>();	

	char* tmpLine = new char[200];

	ifstream* DBfile = new ifstream();


	try {

		// відкриття файлу в обгортці try для перехоплення можливих помилок
		DBfile->open(_pathOfBD);

		// "викидання" помилки при не відкритті файлу
		if (! DBfile->is_open() ) throw string("Can't open file");

		// зчитуємо стрічки з файлу даних
		while(!DBfile->eof())
		{
			if(DBfile->getline(tmpLine,200))
				lines.push_back(string(tmpLine));
		}
	}

	// Перехоплення "викинутих помилок" та вивід помилки на екран, пауза і вихід
	catch(string err){
		cout << err << '\n';
		system("pause");
		exit(1);
	}


	//закриваємо і занулюємо стрім
	DBfile->close();
	delete DBfile;
	DBfile = NULL;

	//масив студентів
	vector<Student> studentDB = vector<Student>();

	//одночасно парсимо кожну стрічку, витягуючи ім'я і 
	//рейтинг студента і зразу створюємо студента + заносимо його в масив.
	for(int i=0;i<lines.size();i++)
		studentDB.push_back(Student(Parser::GetName(lines[i]),	Parser::GetRate(lines[i])));

	//видаляємо масив стрічок (він нам більше не потрібен)

	return studentDB;
}