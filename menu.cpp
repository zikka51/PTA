#include "menu.h"


namespace Menu
{
void printMenu(std::vector<std::string> opt)
{
    std::cout << "Avilable option:\n";
    int numOfOptions = opt.size();
    for(int i{ 0 }; i<numOfOptions;i++)
    {
        std::cout << i+1 << ". " << opt[i] << '\n';
    }
    std::cout << numOfOptions+1 << ". Exit\n";


}

int readMenuInput()
{
    std::cout << "Please choose one option: ";
    int choice{ 0 };
    std::cin >> choice;
    std::cin.ignore(32767, '\n');
    choice -= 1;

    return choice;
}

int menu(std::vector<std::string> opt)
    {
        printMenu(opt);
        int choice {readMenuInput()};
        system("clear");
        return choice;
}

void backToMenu()
{
    std::cout << "Press Enter to return to main screen.";
    std::cout << std::defaultfloat;
    std::cin.ignore();
    system("clear");
}


double readValueInput(std::string variable)
{
    std::cout << "Please input the value for " << variable << ": ";
    double choice{ 0.0 };
    std::cin >> choice;
    std::cin.ignore(32767, '\n');

    return choice;
}

std::string readStringInput(std::string variable)
{
    std::cout << "Please enter the " << variable << ": ";
    std::string name;
    std::getline(std::cin, name);

    return name;
}

bool readBoolInput()
{
    std::cout << "Please input 1(true) or 0(false): ";
    bool line;
    bool lineOK = false;
    do
    {
        try
        {
            std::cin >> line;
            lineOK = true;
        }  catch (...)
        {
            std::cout << "Pease enter 1 or 0!\n";
        }
    } while (!lineOK);

    return line;
}



}
