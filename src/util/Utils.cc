#include "Utils.h"
#include <math.h>

double Utils::Round(double value,int digit)
{
	return ((long)(value * pow(10, digit) + 0.5)) / pow(10, digit);
}
