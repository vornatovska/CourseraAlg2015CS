#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h>
#include "Jordan.h"

using namespace std;



int main(){
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	Jordan jo;
	jo.setJordan();
	jo.doCalculate();
	
}
