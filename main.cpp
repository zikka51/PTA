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
    std::cout << std::scientific << "OpenFOAM easy tools\n";
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
            std::cout << "selected op 3\n"; //napisati kod
            break;

        }
    } while (m != EXIT_MENU);

//    std::string path{"/home/markok/FoamLib/U"};
//    Menu::getValue(Menu::readFile(path),"inlet");
//    Menu::readFile(path);

    return 0;
}
