#ifndef RSA_H
#define RSA_H

#include <iostream>
#include <string>
#include <cstdlib> // Для rand()
#include <time.h> // Для time
#include <cmath>
#include <vector>

#include "asymmetric_encryption.h"

using namespace std;

class RSA : public asymmetric_encryption
{
private:
	string Text;
	vector<unsigned long> Crypted;
	unsigned long p_simple;
	unsigned long q_simple;
	unsigned long p2;
	unsigned long Fn;
public:
	RSA(string _data = "")
	{
		Text = _data;
		generateKeys();
	}
	RSA(vector<unsigned long> _crypted, unsigned long openK = 0, unsigned long secretK = 0, unsigned long _N = 0 , unsigned long _Fn = 0)
	{
		Crypted.resize( _crypted.size() );
		Crypted = _crypted;
		e = openK;
		d = secretK;
		n = _N;
		Fn = _Fn;
	}
	RSA(string _data,  unsigned long ok,  unsigned long sk,  unsigned long N) 
	{
		Text = _data;
		d =  sk;
		e = ok;
		n = N;
	}
	// Методи-аксесори {
	void setSecretKey(unsigned long  sk)
	{
		d = sk;
	}
	unsigned long  getSecretKey()
	{
		return d;
	}
	void setOpentKey(unsigned long  ok)
	{
		e = ok;
	}
	unsigned long  getOpentKey()
	{
		return e;
	}
	unsigned long getN()
	{
		return n;
	}
	void setFN( unsigned long fn)
	{
		Fn = fn;
	}
	void setN( unsigned long _n)
	{
		n = _n;
	}
	 unsigned long getFN()
	{
		return Fn;
	}
	string getText()
	{
		return Text;
	}
	void setText(string _text)
	{
		Text = _text;
	}
	vector<unsigned long> getCrypted()
	{
		return Crypted;
	}
	void setCrepted(vector<unsigned long> crypted)
	{
		Crypted = crypted;
	}
	// } Методи-аксесори
	
	// Методи для генерації ключів
	unsigned long sundaram(unsigned long n) // Алгоритм "Решето Сундарама"
	{
		unsigned long *a = new unsigned long [n], i, j, k;
		memset(a, 0, sizeof(unsigned long) * n);
		for(i = 1; 3*i+1 < n; i++)
		{
			for(j = 1; (k = i+j+2*i*j) < n && j <= i; j++)
				a[k] = 1;
		}
		// Повертання найближчого числа до заданого
		for(i = n-1; i >= 1; i--)
			if(a[i] == 0)
			{
				return (2 * i + 1);
				break;
			}	  
			delete [] a;
	}
	void generateKeys(unsigned long p = 0, unsigned long q = 0)
	{
		srand( (unsigned)time( NULL ) );
		if (!p && !q)
		{
			p = rand()%1000;
			q = rand()%1000;
		}
		p_simple = sundaram(p);
		q_simple = sundaram(q);
		//Находимо число n.
		n = p_simple*q_simple;
		Fn = ((p_simple-1)*(q_simple-1));
		////Генерація числа d і провірка його на взаємопростоту
		////з числом Fn.
		unsigned long e_simple = 0;
		while (e_simple !=1)
		{
			e = rand()%1000;
			e_simple = gcd (e, ((p_simple-1)*(q_simple-1)));
		}
		//Визначення числа e, для якого є істинним
		//відношення (e*d)%Fn=1.
		unsigned long d_simple = 0;
		d = 0;
		while (d_simple !=1)
		{
			d += 1;
			d_simple = (e*d)%((p_simple-1)*(q_simple-1));
		}
	}
	unsigned long gcd(unsigned long a, unsigned long b) // Алгоритм Евклида
	{
		unsigned long c;
		while (b)
		{
			c = a % b;
			a = b;
			b = c;
		}
		return a;
	}
	// --------------------------
	
	// Методи шифрування - дишифрування
	vector<unsigned long> encrypt() // Метод шифрування
	{
		if (n == 0 || e == 0 || d == 0)
			generateKeys();

		Text.c_str();
		Crypted.resize( Text.length());
		unsigned long long c;
 		unsigned long b =301;
		for (unsigned long j = 0; j < Text.length(); j++)
		{
			c = 1;
			unsigned long i = 0;
			unsigned long ASCIIcode = (static_cast<unsigned long>(Text[j]))+b;
			while (i<e)
			{
				c = c*ASCIIcode;
				c = c%n;
				i++;
			}
			Crypted[j] = c;
			b+=1;
		}
		return Crypted;
	}
	string unencrypt() // Метод для розшифрування
	{
		unsigned long b = 301;
		unsigned long long m ;
		for(unsigned long j = 0; j < Crypted.size(); j++)
		{
			m=1;
			unsigned long i = 0; 
			while (i<d)
			{
				m = m * Crypted[j];	 
				m = m%n;
				i++;
			}
			m -= b;
			b+=1;
			Text.push_back(static_cast<char>(m));
		}
		return Text;
	}
	//---------------------------------

};
#endif