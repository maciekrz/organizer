#include"header.h"

int main()
{
    Organizer home("HOME"), work("WORK");
    ShoppingList SL("SHOPPING LIST");
    std::cout << "\nType in the name of a list to see its content or \"end\" to exit the program\n";
    std::string listName = "";
    while (1)
    {
        std::cout << "\nChoose the list:\n[ home (" << home.countTasks() << ") ][ work (" << work.countTasks() << ") ][ shopping (" << SL.countTasks() << ") ][ end ]: ";
        std::cin >> listName;
        if ("home" == listName)             interactiveMode(home);
        else if ("work" == listName)        interactiveMode(work);
        else if ("shopping" == listName)    interactiveMode(SL);
        else if ("end" == listName)         break;
        else                                std::cout << "Wrong name!";
    }
    
    std::cout << "\n";
    return 0;
}
