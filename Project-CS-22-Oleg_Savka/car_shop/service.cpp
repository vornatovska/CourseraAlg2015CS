#include "service.h"
#include "newcar.h"
#include "usedcar.h"
#include "writerservice.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <math.h>

void sellCar() {
	string mark, model, fuelType, transmission;
	int year, type;
	double price;

	cout << "Please enter details for your car:" << endl;

	cout << "Mark: ";
	cin >> mark;

	cout << "Model: ";
	cin >> model;

	cout << "Year: ";
	cin >> year;

	cout << "Fuel Type: ";
	cin >> fuelType;

	cout << "Transmission: ";
	cin >> transmission;

	cout << "Price: ";
	cin >> price;

	cout << "Which type your car of?" << endl;
	cout << "1) Used car\n2) New car" << endl;
	cin >> type;

	if (type == 1) {
		string condition;

		cout << "Car condition (Bad, Good, Wonderful): ";
		cin >> condition;

		UsedCar *car = new UsedCar(mark, model, year, fuelType, transmission, price, condition);
		saveCar(car);
		cout << "Success! Used car has been added!" << endl;
	}
	else if (type == 2) {
		int guarantee;

		cout << "Guarantee (How many years): ";
		cin >> guarantee;

		NewCar *car = new NewCar(mark, model, year, fuelType, transmission, price, guarantee);
		saveCar(car);
		cout << "Success! New car has been added!" << endl;
	}
	cout << "Write any char to continue...";
}

void findCar() {
	string mark, model, fuelType, transmission;
	int type, year;
	double price;

	cout << "Which car type do you want to find?" << endl;
	cout << "1) Used car\n2) New car" << endl;
	cin >> type;

	if (type == 1) {
		string condition;
		list<UsedCar*> cars;

		ifstream input("usedCars.txt");
		while (input >> mark >> model >> year >> fuelType >> transmission >> price >> condition) {
			cars.push_back(new UsedCar(mark, model, year, fuelType, transmission, price, condition));
		}
		cout << "By which field you want to find (mark - 1, year - 2, price - 3, transmission - 4)? ";
		cin >> type;

		if (type == 1) {
			cout << "What mark you want to find? ";
			cin >> mark;

			for (list<UsedCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
				if ((*it)->getMark() == mark) {
					cout << endl;
					cout << "Car found!" << endl;
					cout << "Mark: " << (*it)->getMark() << endl;
					cout << "Model: " << (*it)->getModel() << endl;
					cout << "Year: " << (*it)->getYear() << endl;
					cout << "Fuel Type: " << (*it)->getFuelType() << endl;
					cout << "Transmission: " << (*it)->getTransmission() << endl;
					cout << "Price: " << (*it)->getPrice() << endl;
					cout << "Condition: " << (*it)->getCondition() << endl << endl;

					cout << "Do you want to update this car? (y/n)";
					string update;
					cin >> update;

					if (update == "n")
						continue;

					string newMark, newModel, newFuelType, newTransmission, newCondition;
					int newYear;
					double newPrice;

					cout << "Please update details for your car:" << endl;

					cout << "New Mark: ";
					cin >> newMark;

					cout << "New Model: ";
					cin >> newModel;

					cout << "New Year: ";
					cin >> newYear;

					cout << "New Fuel Type: ";
					cin >> newFuelType;

					cout << "New Transmission: ";
					cin >> newTransmission;

					cout << "New Price: ";
					cin >> newPrice;

					cout << "New condition: ";
					cin >> newCondition;

					updateCar(*it, newMark, newModel, newYear, newFuelType, newTransmission, newPrice, newCondition);
					cout << "Car updated!" << endl;
					cout << "Write any char to continue...";
				}
			}

			ofstream output("usedCars.txt");
			for (list<UsedCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
				output << (*it)->getMark() + " ";
				output << (*it)->getModel() + " ";
				output << to_string((*it)->getYear()) + " ";
				output << (*it)->getFuelType() + " ";
				output << (*it)->getTransmission() + " ";
				output << to_string((*it)->getPrice()) + " ";
				output << (*it)->getCondition();
				output << endl;
			}
			output.close();
		}
		else if (type == 2) {
			int yearFrom, yearTo;
			cout << "Enter years interval.\nFrom: ";
			cin >> yearFrom;
			cout << "To: ";
			cin >> yearTo;

			for (list<UsedCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
				if (yearFrom < (*it)->getYear() && (*it)->getYear() < yearTo) {
					cout << endl;
					cout << "Car found!" << endl;
					cout << "Mark: " << (*it)->getMark() << endl;
					cout << "Model: " << (*it)->getModel() << endl;
					cout << "Year: " << (*it)->getYear() << endl;
					cout << "Fuel Type: " << (*it)->getFuelType() << endl;
					cout << "Transmission: " << (*it)->getTransmission() << endl;
					cout << "Price: " << (*it)->getPrice() << endl;
					cout << "Condition: " << (*it)->getCondition() << endl << endl;

					cout << "Do you want to update this car? (y/n)";
					string update;
					cin >> update;

					if (update == "n")
						continue;
					string newMark, newModel, newFuelType, newTransmission, newCondition;
					int newYear;
					double newPrice;

					cout << "Please update details for your car:" << endl;

					cout << "New Mark: ";
					cin >> newMark;

					cout << "New Model: ";
					cin >> newModel;

					cout << "New Year: ";
					cin >> newYear;

					cout << "New Fuel Type: ";
					cin >> newFuelType;

					cout << "New Transmission: ";
					cin >> newTransmission;

					cout << "New Price: ";
					cin >> newPrice;

					cout << "New condition: ";
					cin >> newCondition;

					updateCar(*it, newMark, newModel, newYear, newFuelType, newTransmission, newPrice, newCondition);
					cout << "Car updated!" << endl;
					cout << "Write any char to continue...";
				}
			}

			ofstream output("usedCars.txt");
			for (list<UsedCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
				output << (*it)->getMark() + " ";
				output << (*it)->getModel() + " ";
				output << to_string((*it)->getYear()) + " ";
				output << (*it)->getFuelType() + " ";
				output << (*it)->getTransmission() + " ";
				output << to_string((*it)->getPrice()) + " ";
				output << (*it)->getCondition();
				output << endl;
			}
			output.close();
		}
		else if (type == 3) {
			double priceFrom, priceTo;
			cout << "Enter price interval.\nFrom: ";
			cin >> priceFrom;
			cout << "To: ";
			cin >> priceTo;

			for (list<UsedCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
				if (priceFrom < (*it)->getPrice() && (*it)->getPrice() < priceTo) {
					cout << endl;
					cout << "Car found!" << endl;
					cout << "Mark: " << (*it)->getMark() << endl;
					cout << "Model: " << (*it)->getModel() << endl;
					cout << "Year: " << (*it)->getYear() << endl;
					cout << "Fuel Type: " << (*it)->getFuelType() << endl;
					cout << "Transmission: " << (*it)->getTransmission() << endl;
					cout << "Price: " << (*it)->getPrice() << endl;
					cout << "Condition: " << (*it)->getCondition() << endl << endl;

					cout << "Do you want to update this car? (y/n)";
					string update;
					cin >> update;

					if (update == "n")
						continue;
					string newMark, newModel, newFuelType, newTransmission, newCondition;
					int newYear;
					double newPrice;

					cout << "Please update details for your car:" << endl;

					cout << "New Mark: ";
					cin >> newMark;

					cout << "New Model: ";
					cin >> newModel;

					cout << "New Year: ";
					cin >> newYear;

					cout << "New Fuel Type: ";
					cin >> newFuelType;

					cout << "New Transmission: ";
					cin >> newTransmission;

					cout << "New Price: ";
					cin >> newPrice;

					cout << "New condition: ";
					cin >> newCondition;

					updateCar(*it, newMark, newModel, newYear, newFuelType, newTransmission, newPrice, newCondition);
					cout << "Car updated!" << endl;
					cout << "Write any char to continue...";
				}
			}

			ofstream output("usedCars.txt");
			for (list<UsedCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
				output << (*it)->getMark() + " ";
				output << (*it)->getModel() + " ";
				output << to_string((*it)->getYear()) + " ";
				output << (*it)->getFuelType() + " ";
				output << (*it)->getTransmission() + " ";
				output << to_string((*it)->getPrice()) + " ";
				output << (*it)->getCondition();
				output << endl;
			}
			output.close();
		}
		else if (type == 4) {
			cout << "Enter transmission type: ";
			cin >> transmission;

			for (list<UsedCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
				if (transmission == (*it)->getTransmission()) {
					cout << endl;
					cout << "Car found!" << endl;
					cout << "Mark: " << (*it)->getMark() << endl;
					cout << "Model: " << (*it)->getModel() << endl;
					cout << "Year: " << (*it)->getYear() << endl;
					cout << "Fuel Type: " << (*it)->getFuelType() << endl;
					cout << "Transmission: " << (*it)->getTransmission() << endl;
					cout << "Price: " << (*it)->getPrice() << endl;
					cout << "Condition: " << (*it)->getCondition() << endl << endl;

					cout << "Do you want to update this car? (y/n)";
					string update;
					cin >> update;

					if (update == "n")
						continue;
					string newMark, newModel, newFuelType, newTransmission, newCondition;
					int newYear;
					double newPrice;

					cout << "Please update details for your car:" << endl;

					cout << "New Mark: ";
					cin >> newMark;

					cout << "New Model: ";
					cin >> newModel;

					cout << "New Year: ";
					cin >> newYear;

					cout << "New Fuel Type: ";
					cin >> newFuelType;

					cout << "New Transmission: ";
					cin >> newTransmission;

					cout << "New Price: ";
					cin >> newPrice;

					cout << "New condition: ";
					cin >> newCondition;

					updateCar(*it, newMark, newModel, newYear, newFuelType, newTransmission, newPrice, newCondition);
					cout << "Car updated!" << endl;
					cout << "Write any char to continue...";
				}
			}

			ofstream output("usedCars.txt");
			for (list<UsedCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
				output << (*it)->getMark() + " ";
				output << (*it)->getModel() + " ";
				output << to_string((*it)->getYear()) + " ";
				output << (*it)->getFuelType() + " ";
				output << (*it)->getTransmission() + " ";
				output << to_string((*it)->getPrice()) + " ";
				output << (*it)->getCondition();
				output << endl;
			}
			output.close();
		}
	}
	else if (type == 2) {
		int guarantee;
		list<NewCar*> cars;

		ifstream input("newCars.txt");
		while (input >> mark >> model >> year >> fuelType >> transmission >> price >> guarantee) {
			cars.push_back(new NewCar(mark, model, year, fuelType, transmission, price, guarantee));
		}
		cout << "By which field you want to find (mark - 1, year - 2, price - 3, transmission - 4)? ";
		cin >> type;

		if (type == 1) {
			cout << "What mark you want to find? ";
			cin >> mark;

			for (list<NewCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
				if ((*it)->getMark() == mark) {
					cout << endl;
					cout << "Car found!" << endl;
					cout << "Mark: " << (*it)->getMark() << endl;
					cout << "Model: " << (*it)->getModel() << endl;
					cout << "Year: " << (*it)->getYear() << endl;
					cout << "Fuel Type: " << (*it)->getFuelType() << endl;
					cout << "Transmission: " << (*it)->getTransmission() << endl;
					cout << "Price: " << (*it)->getPrice() << endl;
					cout << "Guarantee: " << (*it)->getGuarantee() << endl << endl;

					cout << "Do you want to update this car? (y/n)";
					string update;
					cin >> update;

					if (update == "n")
						continue;
					string newMark, newModel, newFuelType, newTransmission;
					int newYear, newGuarantee;
					double newPrice;

					cout << "Please update details for your car:" << endl;

					cout << "New Mark: ";
					cin >> newMark;

					cout << "New Model: ";
					cin >> newModel;

					cout << "New Year: ";
					cin >> newYear;

					cout << "New Fuel Type: ";
					cin >> newFuelType;

					cout << "New Transmission: ";
					cin >> newTransmission;

					cout << "New Price: ";
					cin >> newPrice;

					cout << "New guarantee: ";
					cin >> newGuarantee;

					updateCar(*it, newMark, newModel, newYear, newFuelType, newTransmission, newPrice, newGuarantee);
					cout << "Car updated!" << endl;
					cout << "Write any char to continue...";
				}
			}

			ofstream output("newCars.txt");
			for (list<NewCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
				output << (*it)->getMark() + " ";
				output << (*it)->getModel() + " ";
				output << to_string((*it)->getYear()) + " ";
				output << (*it)->getFuelType() + " ";
				output << (*it)->getTransmission() + " ";
				output << to_string((*it)->getPrice()) + " ";
				output << (*it)->getGuarantee();
				output << endl;
			}
			output.close();
		}
		else if (type == 2) {
			int yearFrom, yearTo;
			cout << "Enter years interval.\nFrom: ";
			cin >> yearFrom;
			cout << "To: ";
			cin >> yearTo;

			for (list<NewCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
				if (yearFrom < (*it)->getYear() && (*it)->getYear() < yearTo) {
					cout << endl;
					cout << "Car found!" << endl;
					cout << "Mark: " << (*it)->getMark() << endl;
					cout << "Model: " << (*it)->getModel() << endl;
					cout << "Year: " << (*it)->getYear() << endl;
					cout << "Fuel Type: " << (*it)->getFuelType() << endl;
					cout << "Transmission: " << (*it)->getTransmission() << endl;
					cout << "Price: " << (*it)->getPrice() << endl;
					cout << "Guarantee: " << (*it)->getGuarantee() << endl << endl;

					cout << "Do you want to update this car? (y/n)";
					string update;
					cin >> update;

					if (update == "n")
						continue;
					string newMark, newModel, newFuelType, newTransmission;
					int newYear, newGuarantee;
					double newPrice;

					cout << "Please update details for your car:" << endl;

					cout << "New Mark: ";
					cin >> newMark;

					cout << "New Model: ";
					cin >> newModel;

					cout << "New Year: ";
					cin >> newYear;

					cout << "New Fuel Type: ";
					cin >> newFuelType;

					cout << "New Transmission: ";
					cin >> newTransmission;

					cout << "New Price: ";
					cin >> newPrice;

					cout << "New guarantee: ";
					cin >> newGuarantee;

					updateCar(*it, newMark, newModel, newYear, newFuelType, newTransmission, newPrice, newGuarantee);
					cout << "Car updated!" << endl;
					cout << "Write any char to continue...";
				}
			}

			ofstream output("newCars.txt");
			for (list<NewCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
				output << (*it)->getMark() + " ";
				output << (*it)->getModel() + " ";
				output << to_string((*it)->getYear()) + " ";
				output << (*it)->getFuelType() + " ";
				output << (*it)->getTransmission() + " ";
				output << to_string((*it)->getPrice()) + " ";
				output << (*it)->getGuarantee();
				output << endl;
			}
			output.close();
		}
		else if (type == 3) {
			double priceFrom, priceTo;
			cout << "Enter price interval.\nFrom: ";
			cin >> priceFrom;
			cout << "To: ";
			cin >> priceTo;

			for (list<NewCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
				if (priceFrom < (*it)->getPrice() && (*it)->getPrice() < priceTo) {
					cout << endl;
					cout << "Car found!" << endl;
					cout << "Mark: " << (*it)->getMark() << endl;
					cout << "Model: " << (*it)->getModel() << endl;
					cout << "Year: " << (*it)->getYear() << endl;
					cout << "Fuel Type: " << (*it)->getFuelType() << endl;
					cout << "Transmission: " << (*it)->getTransmission() << endl;
					cout << "Price: " << (*it)->getPrice() << endl;
					cout << "Guarantee: " << (*it)->getGuarantee() << endl << endl;

					cout << "Do you want to update this car? (y/n)";
					string update;
					cin >> update;

					if (update == "n")
						continue;
					string newMark, newModel, newFuelType, newTransmission;
					int newYear, newGuarantee;
					double newPrice;

					cout << "Please update details for your car:" << endl;

					cout << "New Mark: ";
					cin >> newMark;

					cout << "New Model: ";
					cin >> newModel;

					cout << "New Year: ";
					cin >> newYear;

					cout << "New Fuel Type: ";
					cin >> newFuelType;

					cout << "New Transmission: ";
					cin >> newTransmission;

					cout << "New Price: ";
					cin >> newPrice;

					cout << "New guarantee: ";
					cin >> newGuarantee;

					updateCar(*it, newMark, newModel, newYear, newFuelType, newTransmission, newPrice, newGuarantee);
					cout << "Car updated!" << endl;
					cout << "Write any char to continue...";
				}
			}

			ofstream output("newCars.txt");
			for (list<NewCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
				output << (*it)->getMark() + " ";
				output << (*it)->getModel() + " ";
				output << to_string((*it)->getYear()) + " ";
				output << (*it)->getFuelType() + " ";
				output << (*it)->getTransmission() + " ";
				output << to_string((*it)->getPrice()) + " ";
				output << (*it)->getGuarantee();
				output << endl;
			}
			output.close();
		}
		else if (type == 4) {
			cout << "Enter transmission type: ";
			cin >> transmission;

			for (list<NewCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
				if (transmission == (*it)->getTransmission()) {
					cout << endl;
					cout << "Car found!" << endl;
					cout << "Mark: " << (*it)->getMark() << endl;
					cout << "Model: " << (*it)->getModel() << endl;
					cout << "Year: " << (*it)->getYear() << endl;
					cout << "Fuel Type: " << (*it)->getFuelType() << endl;
					cout << "Transmission: " << (*it)->getTransmission() << endl;
					cout << "Price: " << (*it)->getPrice() << endl;
					cout << "Guarantee: " << (*it)->getGuarantee() << endl << endl;

					cout << "Do you want to update this car? (y/n)";
					string update;
					cin >> update;

					if (update == "n")
						continue;
					string newMark, newModel, newFuelType, newTransmission;
					int newYear, newGuarantee;
					double newPrice;

					cout << "Please update details for your car:" << endl;

					cout << "New Mark: ";
					cin >> newMark;

					cout << "New Model: ";
					cin >> newModel;

					cout << "New Year: ";
					cin >> newYear;

					cout << "New Fuel Type: ";
					cin >> newFuelType;

					cout << "New Transmission: ";
					cin >> newTransmission;

					cout << "New Price: ";
					cin >> newPrice;

					cout << "New guarantee: ";
					cin >> newGuarantee;

					updateCar(*it, newMark, newModel, newYear, newFuelType, newTransmission, newPrice, newGuarantee);
					cout << "Car updated!" << endl;
					cout << "Write any char to continue...";
				}
			}

			ofstream output("newCars.txt");
			for (list<NewCar*>::iterator it = cars.begin(); it != cars.end(); ++it) {
				output << (*it)->getMark() + " ";
				output << (*it)->getModel() + " ";
				output << to_string((*it)->getYear()) + " ";
				output << (*it)->getFuelType() + " ";
				output << (*it)->getTransmission() + " ";
				output << to_string((*it)->getPrice()) + " ";
				output << (*it)->getGuarantee();
				output << endl;
			}
			output.close();
		}
	}
	
}