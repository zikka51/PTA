#ifndef MENU_H
#define MENU_H

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
namespace Menu
{
int menu(std::vector<std::string> opt);
void printMenu(std::vector<std::string> opt);
void backToMenu();

int readMenuInput();
double readValueInput(std::string variable);


}

#endif // MENU_H
