#pragma once
#include <iostream>
using namespace std;

// Car class
class Car {
protected:
	string _mark;
	string _model;
	int _year;
	string _fuelType;
	string _transmission;
	double _price;
	Car() {}

public:
	Car(string mark, string model, int year, string fuelType, string transmission, double price);

	string getMark(void);
	void setMark(string);

	string getModel(void);
	void setModel(string);

	int getYear(void);
	void setYear(int);

	string getFuelType(void);
	void setFuelType(string);

	string getTransmission(void);
	void setTransmission(string);

	double getPrice(void);
	void setPrice(double);
};