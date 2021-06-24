#include "task.h"
#include "organizer.h"
#include "libraries.h"


int main()    
{
    Organizer o1("home"), o2("work");
    ShoppingList sl("groceries");
    int choice;

	std::cout << "\nType in the number of a list to see its content. Anything else will exit the program\n";

    while (1)
    {
        //choice = NULL;
        std::cout << "\nChoose the list:\n[ 1. " << o1.getName() << " (" << o1.countTasks() << ") ][ 2. " << o2.getName() << " (" << o2.countTasks() << ") ][ 3. " << sl.getName() << " (" << sl.countTasks() << ") ]\n ~> ";
        std::cin >> choice;
        
        switch (choice)
        {
        case 1:
            o1.interactiveMode();
            break;
        case 2:
            o2.interactiveMode();
            break;
        case 3:
            sl.interactiveMode();
            break;
        default:
            o1.removeAll();
            o2.removeAll();
            sl.removeAll();
            return 0;
        }
    }
 

    std::cout << "\n";
    return 0;
}
