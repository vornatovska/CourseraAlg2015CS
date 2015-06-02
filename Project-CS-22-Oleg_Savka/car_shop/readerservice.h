#pragma once
#include "usedcar.h"
#include "newcar.h"

#include <stdio.h>

UsedCar findUsedCar(string mark, string model, int year, string fuelType, string transmission, double price, string condition);
NewCar findNewCar(string mark, string model, int year, string fuelType, string transmission, double price, int guarantee);