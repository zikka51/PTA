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
    std::cin.ignore();
    system("clear");
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
