#include "fluidDatabase.h"
#include "foamFileRW.h"
#include "menu.h"
#include "turbulanceCalculatorMenu.h"
#include "ypCalculatorMenu.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <string>





int main()
{
    enum Options
    {
        TURBULANCE_CALCULATOR,
        YP_CALCULATOR,
        FLUID_DATABASE,
        EXIT_MENU
    };

    std::vector<std::string> opt{"Turbulance calculator", "Y+ calculator", "Fluid Database"};
    std::cout << "OpenFOAM easy tools\n";
    int m;
    do
    {
        m = Menu::menu(opt);
        switch (m)
        {
        case TURBULANCE_CALCULATOR:
            TurbulanceCalculatorMenu::menu();
            break;
        case YP_CALCULATOR:
            YpCalculatorMenu::calculateYPMenu();
            break;
        case FLUID_DATABASE:
            FluidDatabase::menu();
            break;


        }
    } while (m != EXIT_MENU);




    return 0;
}
