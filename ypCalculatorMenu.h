#ifndef YPCALCULATORMENU_H
#define YPCALCULATORMENU_H

#include "menu.h"
#include "ypCalculator.h"

#include <iostream>
#include <string>
#include <tuple>

namespace YpCalculatorMenu
{

struct CalcResultNames
{
    std::string u{"Freestream velocity U [m/s]"};
    std::string rho{"Density [kg/m3]"};
    std::string mi{"Dynamic viscosity [kg/ms]"};
    std::string l{"Boundary layer length [m]"};
    std::string yp{"Desired Y+ value []"};
    std::string re{"Reynolds number []"};
    std::string d{"Estimated wall distance [m]"};

};

void calculateYPMenu();

}

#endif // YPCALCULATORMENU_H
