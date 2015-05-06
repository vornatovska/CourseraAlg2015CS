#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;



// Клас тексту з розшириними властивостями
class Text
{
private:
	string Data;
	vector<unsigned long> Crypted;
	unsigned long openKey;
	unsigned long secretKey;
	unsigned long N;
	bool crypted;
public:
	Text( string new_data = "", unsigned long new_OKey = 0, unsigned long new_SKey = 0, bool new_h = 0)
	{
		openKey = new_OKey;
		secretKey = new_SKey;
		Data = new_data;
		crypted = new_h;
		Crypted.resize( Data.length());
		N = 0;
	}
	void setCrypted(vector<unsigned long> crypted)
	{
		Crypted = crypted;
	}
 	void pushBackCrypred(unsigned long temp)
	{
		Crypted.push_back(temp);
	}
	unsigned long clearCrypted()
	{
		Crypted.clear();
		return 1;
	}
	vector<unsigned long> getCrypted()
	{
		return Crypted;
	}
	void outputCryptedText()
	{
		for(unsigned long i=0; i<Crypted.size(); i++)
			cout << (char)Crypted[i];
	}
 	void setN( unsigned long n)
	{
		N = n;
	}
 	 unsigned long getN()
	{
		return N;
	}
 	bool show_status()
	{
		if (crypted) return true;
		else return false;
	}
 	void change_status()
	{
		if (crypted) crypted = 0;
		else crypted = 1;
	}
 	void set_data( string new_data )
	{
		Data = new_data;
	}
 	void set_data_back(char _data)
	{
		Data.push_back(_data);
	}
 	void setOpenKey(  unsigned long new_key )
	{
		openKey = new_key;
	}
	void setSecretKey( unsigned long new_key)
	{
		secretKey = new_key;
	}
	 unsigned long getOpenKey()
	{
		return openKey;
	}
	 unsigned long getSecretKey()
	{
		return secretKey;
	}
	string get_data()
	{  
		return Data;
	}
};

#endif