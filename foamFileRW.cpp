#include "foamFileRW.h"


std::vector<std::string> FoamFileRW::readFile(std::string path)
{
    std::vector<std::string> fileContenst;
    std::string str;
    std::ifstream file(path);
    while (file >> str)
    {
        fileContenst.push_back(str);
    }

    return fileContenst;
}

std::vector<double> FoamFileRW::getValue(std::vector<std::string> file, std::string varName)
{
    std::vector<double> value{1.0};
    bool varNameFound{false};
    for (uint i{0};i<file.size();++i)
    {
        if (file.at(i) == varName)
            varNameFound = true;
        if (varNameFound && file.at(i) == "value")
        {
            if (file.at(i+2)[0] == '(')
            {
                std::string s = file.at(i+2);
                value[0] = std::stod(s.erase(0, 1));
                value.push_back(std::stod(file.at(i+3)));
                s = file.at(i+4);
                s.erase(s.end()-2,s.end());
                value.push_back(std::stod(s));
                varNameFound = false;
            }
            else
            {
                std::string s = file.at(i+2);
                s.erase(s.end(),s.end());
                value[0] = std::stod(s);
                varNameFound = false;
            }
        }
    }
    return value;
}
