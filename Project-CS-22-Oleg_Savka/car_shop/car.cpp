#include "car.h"

// Constructor for Car class
Car::Car(string mark, string model, int year, string fuelType, string transmission, double price) {
	this->_mark = mark;
	this->_model = model;
	this->_year = year;
	this->_fuelType = fuelType;
	this->_transmission = transmission;
	this->_price = price;
}

// Getter and setter for car mark
string Car::getMark(void) {
	return this->_mark;
}
void Car::setMark(string mark) {
	this->_mark = mark;
}

// Getter and setter for car model
string Car::getModel(void) {
	return this->_model;
}
void Car::setModel(string model) {
	this->_model = model;
}

// Getter and setter for car year
int Car::getYear(void) {
	return this->_year;
}
void Car::setYear(int year) {
	this->_year = year;
}

// Getter and setter for car fuel type
string Car::getFuelType(void) {
	return this->_fuelType;
}
void Car::setFuelType(string fuelType) {
	this->_fuelType = fuelType;
}

// Getter and setter for car transmission
string Car::getTransmission(void) {
	return this->_transmission;
}
void Car::setTransmission(string transmission) {
	this->_transmission = transmission;
}

// Getter and setter for car price
double Car::getPrice() {
	return this->_price;
}
void Car::setPrice(double price) {
	this->_price = price;
}