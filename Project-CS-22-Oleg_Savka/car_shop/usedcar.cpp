#include "usedcar.h"

UsedCar::UsedCar(string make, string model, int year, string fuelType, string transmission, double price, string condition) : Car(make, model, year, fuelType, transmission, price) {
	this->_condition = condition;
}

// Getter and setter for guarantee for car
string UsedCar::getCondition(void) {
	return this->_condition;
}
void UsedCar::setCondition(string condition) {
	this->_condition = condition;
}