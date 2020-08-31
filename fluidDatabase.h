#ifndef FLUIDDATABASE_H
#define FLUIDDATABASE_H

#include "menu.h"
#include "nlohmann/json.hpp"


#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

namespace FluidDatabase
{
void menu();
nlohmann::json loadDatabase(std::string fullPath);
void saveDatabase(nlohmann::json fluidDatabase, std::string fullPath);

void getFluid(nlohmann::json fluidDatabase);
void addFluid(std::string fullPath);
void removeFluid(std::string fullPath);
void modifyFluid(std::string fullPath);

}


#endif // FLUIDDATABASE_H
