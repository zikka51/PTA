#include "foamFileRW.h"

namespace FoamFileRW
{
std::vector<std::string> readFile(std::string fullPath)
{
    std::vector<std::string> fileContenst;
    std::string str;
    std::ifstream file(fullPath);
    while (file >> str)
    {
        fileContenst.push_back(str);
    }

    return fileContenst;
}

std::string getValueU(std::string fullPath, std::string varName)
{
    std::vector<std::string> file{readFile(fullPath)};
    std::string value;
    bool varNameFound{false};
    for (uint i{0};i<file.size();++i)
    {
        if (file.at(i) == varName)
            varNameFound = true;
        if (varNameFound && file.at(i) == "value")
        {
            if (file.at(i+2)[0] == '(')
            {
                for (int j{2}; j<4; ++j)
                    value += file.at(i+j) + ' ';
                value += file.at(i+4);
                varNameFound = false;
            }
            else
            {
                value = file.at(i+2);
                varNameFound = false;
            }
        }
    }
//    std::cout << value << '\n';
    return value;
}

std::string getValue(std::string fullPath)
{
    std::vector<std::string> file{readFile(fullPath)};
    std::string value;
    for (uint i{0};i<file.size();++i)
    {
        if (file.at(i) == "uniform")
        {
            value = file.at(i+1);
            break;
        }
    }

//    std::cout << value << '\n';
    return value;
}

void replace(std::string &initialString, std::string whatToReplace, std::string withWhat){
    size_t rpos=initialString.find(whatToReplace);
    bool noMore{false};
    do
    {
        if (rpos!=std::string::npos)
            initialString.replace(initialString.begin()+rpos, initialString.begin()+rpos+whatToReplace.length(), withWhat);
        else
            noMore =true;
        rpos=initialString.find(whatToReplace);
    } while (!noMore);
}

std::string loadFile(std::string fullPath)
{
  std::ifstream ifs(fullPath);
  std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
  return content;
}



void writeToFile(std::string fullPath, std::string fileName, double var)
{
    std::string file{FoamFileRW::loadFile(fullPath+"/0/"+fileName)};
    FoamFileRW::replace(file,FoamFileRW::getValue(fullPath+"/0/"+fileName),std::to_string(var)+';');
    std::ofstream newFile{fullPath+"/0/"+fileName};
    newFile << file;
}

void writeToFileMenu(std::string name, double var)
{
    std::cout << "Write to file 1(yes) or 0(no): ";
    bool writeOK{false};
    std::cin >> writeOK;
    if (writeOK)
    {
        std::string path;
        std::cout << "Enter full path to case folder:\n";
        std::cin >> path;
        FoamFileRW::writeToFile(path,name,var);
    }
}

void writeToFileMenu(std::string name[], double var[])
{
    std::cout << "Write to file 1(yes) or 0(no): ";
    bool writeOK{false};
    std::cin >> writeOK;
    if (writeOK)
    {
        std::string path;
        std::cout << "Enter full path to case folder:\n";
        std::cin >> path;
        for (int i{0}; i<3; ++i)
            FoamFileRW::writeToFile(path,name[i],var[i]);
    }
}



}
