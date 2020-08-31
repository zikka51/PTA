#ifndef FOAMFILERW_H
#define FOAMFILERW_H

#include <vector>
#include <fstream>
#include <iostream>
#include <string>

namespace FoamFileRW
{
std::vector<std::string> readFile(std::string);
std::vector<double> getValue(std::vector<std::string> file, std::string varName);

}

#endif // FOAMFILERW_H
