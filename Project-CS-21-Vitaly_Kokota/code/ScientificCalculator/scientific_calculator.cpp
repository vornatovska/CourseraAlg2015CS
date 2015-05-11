#include "scientific_calculator.h"

#include <math.h>

scientific_calculator::scientific_calculator()
{
}


scientific_calculator::~scientific_calculator()
{
}

double scientific_calculator::add(double first, double sec)
{
	return first + sec;
}
double scientific_calculator::sub(double f, double s)
{
	return f - s;
}
double scientific_calculator::mul(double f, double s)
{
	return f * s;
}
double scientific_calculator::div(double f, double s)
{
	return f / s;
}


double scientific_calculator::pow(double number, double pow_value)
{
	return ::pow(number, pow_value);
}
double scientific_calculator::sqrt(double number, double value)
{
	return ::pow(number, 1 / value);
}

double scientific_calculator::log(double val)
{
	return ::log(val);
}
double scientific_calculator::fact(int val)
{
	if (val > 1)
	{
		return scientific_calculator::fact(val - 1) * val;
	}
	return val;
}
double scientific_calculator::tan(double val)
{
	return ::tan(val);
}
double scientific_calculator::sin(double val)
{
	return ::sin(val);
}
double scientific_calculator::cos(double val)
{
	return ::cos(val);
}
double scientific_calculator::mod(double number, double mod_val)
{
	return ::fmod(number, mod_val);
}