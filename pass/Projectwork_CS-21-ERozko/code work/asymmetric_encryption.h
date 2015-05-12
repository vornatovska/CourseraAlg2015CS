#ifndef asymmetric_h
#endif asymmetric_h


#include <vector>
#include <string>

#include "encryption.h"

class asymmetric_encryption : public encryption
{
protected:
	unsigned long d; // secret key
	unsigned long n;
private:
	virtual std::vector<unsigned long> encrypt() =0;
	virtual std::string unencrypt() = 0;
	virtual void generateKeys(unsigned long, unsigned long) = 0;
};