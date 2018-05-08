#include "Suma.h"

SumaNum::SumaNum(double numero1, double numero2) {
	num1 = numero1;
	num2 = numero2;
}
double SumaNum::SumaTotal() {
	return num1 + num2;
}