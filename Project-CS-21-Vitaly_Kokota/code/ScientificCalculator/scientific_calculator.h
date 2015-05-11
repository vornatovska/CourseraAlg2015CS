#pragma once
class scientific_calculator
{
private:
	scientific_calculator();
public:
	~scientific_calculator();
	static double add(double first, double sec);
	static double sub(double f, double s);
	static double mul(double f, double s);
	static double div(double f, double s);


	static double pow(double number, double pow_value);
	static double sqrt(double number, double value);

	static double log(double val);
	static double fact(int val);
	static double tan(double val);
	static double sin(double val);
	static double cos(double val);
	static double mod(double number, double mod_val);
};

