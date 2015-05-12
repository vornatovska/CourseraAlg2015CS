#ifndef encryption_h
#endif encryption_h

#include <vector>
#include <string>

class encryption
{
protected:
	unsigned long e; // key
public:
	virtual std::vector<unsigned long> encrypt() =0;
	virtual std::string unencrypt() = 0;
};