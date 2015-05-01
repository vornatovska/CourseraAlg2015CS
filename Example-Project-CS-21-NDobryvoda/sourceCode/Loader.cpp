#include"loader.h"
#include"parser.h"

vector<Student> Loader::LoadStudentsDB(string _pathOfBD)
	{
		//масив стічок, в яких міститься ім'я і рейтинг.
		vector<string> lines = vector<string>();	
		
		char* tmpLine = new char[200];
		
		ifstream* DBfile = new ifstream(_pathOfBD);
			
		//зачитуємо стрічки з файлу імпровізованої БД.
		while(!DBfile->eof())
		{
			if(DBfile->getline(tmpLine,200))
				lines.push_back(string(tmpLine));
		}
		
		//закриваємо і занулюємо стрім
		DBfile->close();
		delete DBfile;
		DBfile = NULL;
		
		//масив студентів.
		vector<Student> studentDB = vector<Student>();

		//одночасно парсимо кожну стрічку, витягуючи ім'я і 
		//рейтинг студента і зразу створюємо студента + заносимо його в масив.
		for(int i=0;i<lines.size();i++)
			studentDB.push_back(Student(Parser::GetName(lines[i]),	Parser::GetRate(lines[i])));

		//видаляємо масив стрічок (він нам більше не потрібен)
		
		return studentDB;
	}