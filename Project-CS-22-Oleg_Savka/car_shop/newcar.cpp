#include "newcar.h"

NewCar::NewCar(string make, string model, int year, string fuelType, string transmission, double price, int guarantee) : Car(make, model, year, fuelType, transmission, price) {
	this->_guarantee = guarantee;
}

// Getter and setter for guarantee for car
int NewCar::getGuarantee(void) {
	return this->_guarantee;
}
void NewCar::setGuarantee(int guarantee) {
	this->_guarantee = guarantee;
}