#ifndef FOAMFILERW_H
#define FOAMFILERW_H

#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

namespace FoamFileRW
{
std::vector<std::string> readFile(std::string fullPath);
std::string getValueU(std::string fullPath, std::string varName);
std::string getValue(std::string fullPath);

std::string loadFile(std::string fullPath);
void replace(std::string &initialString, std::string whatToReplace, std::string withWhat);

void writeToFileMenu(std::string name, double var);
void writeToFileMenu(std::string name[], double var[]);
void writeToFile(std::string fullPath, std::string fileName, double var);
void writeToFile(std::string fullPath,  std::string fileName, double var1, double var2, double var3);

}

#endif // FOAMFILERW_H
