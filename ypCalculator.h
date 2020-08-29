#ifndef YPCALCULATOR_H
#define YPCALCULATOR_H

#include "menu.h"

#include <cmath>
#include <iostream>
#include <string>
#include <tuple>

namespace YpCalculator
{

std::tuple<double, double> calculateYP(double u, double rho, double nu, double l, double yp);

}
#endif // YPCALCULATOR_H
