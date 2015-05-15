#pragma once
#include "car.h"

// Class for new cars
class NewCar : public Car {
private:
	int _guarantee;

public:
	NewCar(string make, string model, int year, string fuelType, string transmission, double price, int guarantee);

	int getGuarantee(void);
	void setGuarantee(int);
};