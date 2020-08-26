#ifndef YPPCALCULATOR_H
#define YPPCALCULATOR_H

#include "menu.h"

#include <cmath>
#include <iostream>
#include <string>

namespace YppCalculator
{
struct YPdata
{
    double u{0.0};
    double rho{0.0};
    double mu{0.0};
    double l{0.0};
    double yp{0.0};
    double re{0.0};
    double d{0.0};

    std::string name_u{"Freestream velocity"};
    std::string name_rho{"Density"};
    std::string name_mu{"Dynamic viscosity"};
    std::string name_l{"Boundary layer length"};
    std::string name_yp{"Desired Y+ value"};
    std::string name_re{"Reynolds number"};
    std::string name_d{"Estimated wall distance"};

};

YPdata calculateYPP(double u, double rho, double nu, double l, double yp);

}
#endif // YPPCALCULATOR_H
