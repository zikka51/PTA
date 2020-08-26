#include "menu.h"


namespace Menu
{
void printMenu(std::string opt[])
{
    std::cout << "Avilable option:\n";
    int numOfOptions{std::stoi(opt[0])};
    for(int i{ 1 }; i<=numOfOptions;i++)
    {
        std::cout << i << ". " << opt[i] << '\n';
    }

}

int readMenuInput()
{
//    std::cin.ignore(32767, '\n');
    std::cout << "Please choose one option: ";
    int choice{ 0 };
    std::cin >> choice;
    std::cin.ignore(32767, '\n');

    return choice;
}

int menu(std::string opt[])
    {
        printMenu(opt);
        std::cout << "0. Exit\n";
        int choice {readMenuInput()};
        system("clear");
        return choice;
}

double readValueInput(std::string variable)
{
    std::cout << "Please input the value for " << variable << ": ";
    double choice{ 0.0 };
    std::cin >> choice;
//    std::cout << "Enterd: " << choice << '\n';
    std::cin.ignore(32767, '\n');

    return choice;
}

}
