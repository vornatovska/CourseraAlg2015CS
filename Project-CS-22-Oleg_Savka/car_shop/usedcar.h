#pragma once
#include "car.h"

class UsedCar : public Car {
private:
	string _condition;

public:
	UsedCar(string make, string model, int year, string fuelType, string transmission, double price, string condition);

	string getCondition(void);
	void setCondition(string);
};

