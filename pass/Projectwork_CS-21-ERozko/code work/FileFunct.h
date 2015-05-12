#ifndef _FileFunct_H_
#define _FileFinct_H_

#include <string>
#include <cstdio>

using namespace std;
			  
class MyFile
{
protected:
	FILE *mf;
	string standartName;	// ��'� �����
	string mode;			// ����� �������� �����
public:
	MyFile(string Name = "temp.dat", string Mode = "rt+")
	{
		standartName = Name;
		mode = Mode;
	}
	bool FindFIle(string name = "") // ����� ������ �����: ���� ���� �� �������� ��'�� ���� �� �� ������ true (1), ���� � - false (0)
	{
		if( name == "" ) name = standartName;

		if ((mf = fopen( name.c_str() , "rt" )) != NULL)
		{
			fclose(mf);
			return true;
		}
		else
		{
			return false;
		}
	}
	string StandartName() const { return standartName; }
	void StandartName(string val) { standartName = val; }
	string NameOfFile() // ����� ��� ���� ���� �����
	{
		setlocale(LC_ALL, "rus");

		cout << "\n ����i�� ����� ����� ( �����.���������� )"
			<< "\n (����i�� Enter ��� ����� i���i \""
			<< standartName << "\" ) : \n\t";

		string _NameOfFile("");
		getline(cin, _NameOfFile);

		// ���� ����� �� ���� ������� �� ����� ����� ���������� ����������� 
		// (�����������, ������� ��� ����������� ��'����)
		if (_NameOfFile == "")  _NameOfFile = standartName;
		// -----------------------------------------------------------------


		// �������� ����� ����� �� ������ � ����� �� �� ������ '_'
		_NameOfFile.c_str();
		unsigned long i;
		for (i=0; i<_NameOfFile.length(); i++)
		{
			if (_NameOfFile[i] == ' ' ) _NameOfFile[i] = '_';
		}
		// ------------------------------------------------------

		return _NameOfFile;
	}
	unsigned long loadFile(Text& text, string temp = "")
	{
		setlocale(LC_ALL, "rus");

		if (temp == "settings")
		{
			if(FindFIle())
			{
				SetFileAttributes( TEXT("settings.key") ,FILE_ATTRIBUTE_NORMAL);	   // ������� ����� �������� �����, ������ ������� 'hide'
			
				mf = fopen(standartName.c_str(),"rt");
				unsigned long temp;
				fscanf(mf,"%lu",&temp);
				text.setOpenKey(temp);
				fscanf(mf,"%lu",&temp);
 				text.setSecretKey(temp);
				fscanf(mf,"%lu",&temp);
 				text.setN(temp);
				
				SetFileAttributes( TEXT("settings.key") ,FILE_ATTRIBUTE_HIDDEN);	   // ������� ����� �������� ����� �� ������� (����� ���� �� �������)
				
				return 0;
			}
			else
				return -1;
			
		}
		else
		{
			while (!FindFIle()) 
			{
				cout << "\n\n ���� \"" << standartName <<"\" �� ��������! \n";
				renameFile();
				cout << "\n\t ���������� ����� �����? (y/n) ";
				char answ = _getche();
				if (answ == 'n') return -1;
			}

			mf = fopen(standartName.c_str(), "rt");
			
			char temp;
			unsigned long temp2;
			fscanf(mf,"%c",&temp);
			if ( temp == '1')
			{
				text.clearCrypted();
				if (!text.show_status()) text.change_status();
				while(!feof(mf))
				{
					fscanf(mf,"%lu",&temp2);
					text.pushBackCrypred(temp2);
				}
			}
			else if( temp == '0')
			{
				text.set_data("");
				if (text.show_status()) text.change_status();
				while(!feof(mf))
				{
					fscanf(mf,"%c",&temp);
					text.set_data_back(temp);
				}
			}
			else return -1;
		}
		return 0;
	}
	unsigned long saveFile(Text& text, string atrubute = "auto")
	{
		setlocale(LC_ALL,NULL);
		if( atrubute == "settings")
		{
			SetFileAttributes( TEXT("settings.key") ,FILE_ATTRIBUTE_NORMAL);	   // ������� ����� �������� �����, ������ ������� 'hide'
			mf = fopen( standartName.c_str(), "wt");
			fprintf(mf, "%i %i %i ",text.getOpenKey(), text.getSecretKey(), text.getN());
			fclose(mf);
			SetFileAttributes( TEXT("settings.key") ,FILE_ATTRIBUTE_HIDDEN);	   // ������� ����� �������� ����� �� ������� (����� ���� �� �������)
		}
		else 
		{
				if (atrubute == "saveAs" ) renameFile();
		
				mf = fopen( standartName.c_str(), "wt");
				string toWrite = text.get_data();
				if (!text.show_status())
				{
					fprintf(mf, "0\n%s",toWrite.c_str());
				}
				else 
				{
					vector <unsigned long> a ;
					a = text.getCrypted();
					fprintf(mf,"1\n");
					for (unsigned long i =0; i<a.size() ; i++ )
							fprintf(mf, "%lu ",a[i]);
				}
				fprintf(mf,"\n");
		
				fclose(mf);
		}
		return 0;
	}
	void renameFile()
	{
		string temp =standartName;
		standartName = NameOfFile();
		rename(temp.c_str() , standartName.c_str() );
	} 
};




#endif