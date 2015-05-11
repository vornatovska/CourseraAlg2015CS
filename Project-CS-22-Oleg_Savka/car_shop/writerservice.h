#pragma once
#include "usedcar.h"
#include "newcar.h"

void saveCar(UsedCar*);
void saveCar(NewCar*);

void updateCar(UsedCar*, string, string, int, string, string, double, string);
void updateCar(NewCar*, string, string, int, string, string, double, int);