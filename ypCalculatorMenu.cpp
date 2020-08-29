#include "ypCalculatorMenu.h"

namespace YpCalculatorMenu
{

CalcResultNames varNames;

void calculateYPMenu()
{
    std::cout << "Y+ Wall Distance Estimation\n";
    double re;
    double d;
    std::tie(re, d) = YpCalculator::calculateYP(Menu::readValueInput(varNames.u),
                              Menu::readValueInput(varNames.rho),
                              Menu::readValueInput(varNames.mi),
                              Menu::readValueInput(varNames.l),
                              Menu::readValueInput(varNames.yp));
    std::cout.precision(5);
    std::cout << varNames.re <<": " << re << ", " << varNames.d << ": " << d << '\n';
    Menu::backToMenu();
}

}
