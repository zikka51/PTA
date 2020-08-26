#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <sstream>
namespace Menu
{
int menu(std::string opt[]);
void printMenu(std::string opt[]);
int readMenuInput();
double readValueInput(std::string variable);
}

#endif // MENU_H
