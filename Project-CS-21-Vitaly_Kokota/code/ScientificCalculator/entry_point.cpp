#include <iostream>

#include "scientific_calculator.h"
#include "CalcUI.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true);
	Application::Run(gcnew ScientificCalculator::CalcUI());
	/*using namespace std;
	typedef scientific_calculator sc;
	cout << sc::sqrt(27, 3);
	system("pause");*/
}