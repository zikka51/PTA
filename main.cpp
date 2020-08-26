#include "menu.h"
#include "turbulanceCalculator.h"
#include "yppCalculator.h"

#include <iostream>
#include <string>






int main()
{
    std::string opt[]{"3", "Turbulance calculator","Y+ calculator",
                       "Fluid Database"};
    std::cout << "OpenFOAM easy tools\n";
    int m;
    do
    {
        m = Menu::menu(opt);
        switch (m)
        {
        case 1:
            TurbulanceCalculator::menu();
            break;
        case 2:
            YppCalculator::calculateYPP(1.0,1.205,1.82e-5,1.0,1.0);
            break;
        case 3:
            std::cout << "selected op 3\n";
            break;

        }
    } while (m);




    return 0;
}
