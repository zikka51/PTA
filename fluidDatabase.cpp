#include "fluidDatabase.h"

namespace FluidDatabase
{


void menu()
{
    enum MenuOptions
    {
        GET_FLUID,
        ADD_FLUID,
        REMOVE_FLUID,
        MODIFY_FLUID,
        EXIT_MENU,
    };

    std::vector<std::string> opt{"Get fluid", "Add fluid", "Remove fluid", "Modify fluid"};
    std::string path{"/home/markok/FoamLib/fluidData.json"};
    int m;
    do
    {
        m = Menu::menu(opt);
        switch (m)
        {
        case GET_FLUID:
            getFluid(loadDatabase(path));
            Menu::backToMenu();
            break;
        case ADD_FLUID:
            addFluid(path);
            Menu::backToMenu();
            break;
        case REMOVE_FLUID:
            removeFluid(path);
            Menu::backToMenu();
            break;
        case MODIFY_FLUID:
            modifyFluid(path);
            Menu::backToMenu();
            break;
        default:
            system("clear");
            std::cout << "Option " << m << " does not exist, Please try again.\n";
            menu();
            break;

        }
    } while (m != EXIT_MENU);
}
nlohmann::json loadDatabase(std::string fullPath)
{
    std::ifstream i(fullPath);
    nlohmann::json j;
    i >> j;

    return j;
}

void saveDatabase(nlohmann::json fluidDatabase, std::string fullPath)
{
        std::ofstream o(fullPath);
        o << std::setw(4) << fluidDatabase << std::endl;
}

void getFluid(nlohmann::json fluidDatabase)
{

    std::vector<std::string> opt;
    for (auto& element : fluidDatabase)
    {
        opt.push_back(element["name"]);
        std::cout << element["name"] << '\n';
    }
    std::string name = Menu::readStringInput("name");
    for (uint i{0}; i<opt.size();++i)
    {
        if ( fluidDatabase[i]["name"] == name)
        {
            std::cout << std::setw(4) << fluidDatabase[i] << '\n';
        }

    }
}

void addFluid(std::string fullPath)
{
    nlohmann::json fluidDatabase = loadDatabase(fullPath);
    nlohmann::json temp;
    temp["name"] = Menu::readStringInput("name");
    std::cout << "Is fluid compressable?\n";
    temp["compressable"] = Menu::readBoolInput();
    temp["density"] = Menu::readValueInput("density");
    temp["viscosity"] = Menu::readValueInput("viscosity");

    fluidDatabase.push_back(temp);
    saveDatabase(fluidDatabase,fullPath);
}

void removeFluid(std::string fullPath)
{
    nlohmann::json fluidDatabase = loadDatabase(fullPath);
    nlohmann::json temp;
    for (auto& element : fluidDatabase)
    {
        std::cout << element["name"] << '\n';
    }
    std::string name = Menu::readStringInput("name");
    for (auto& element : fluidDatabase)
    {
        if (element["name"] != name)
            temp.push_back(element);
    }
    saveDatabase(temp,fullPath);


}

void modifyFluid(std::string fullPath)
{
    nlohmann::json fluidDatabase = loadDatabase(fullPath);
    for (auto& element : fluidDatabase)
    {
        std::cout << element["name"] << '\n';
    }
    std::string name = Menu::readStringInput("name");
    for (auto& element : fluidDatabase)
    {
        if (element["name"] == name)
        {
            std::string temp = "new name ";
            element["name"] = Menu::readStringInput(temp.append(element["name"]));
            std::cout << "Is fluid compressable?\n";
            element["compressable"] = Menu::readBoolInput();
            temp = "new density ";
            element["density"] = Menu::readValueInput(temp.append(element["density"]));
            temp = "new viscosity ";
            element["viscosity"] = Menu::readValueInput(temp.append(element["viscosity"]));
        }
    }
    saveDatabase(fluidDatabase,fullPath);
}



}
