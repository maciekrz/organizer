#include "header.h"

// methods for Organizer
int Organizer::countTasks()
{
    int counter = 0;
    for (const auto& [key, value] : this->tasks)
    {
        counter++;
    }
    return counter;
}

void Organizer::printTasks()
{
    std::string done = "";
    int counter = 1;
    std::cout << "\n\t=== " << this->listName << " ===\n";
    if (this->tasks.empty())  std::cout << "\t*empty*\n";
    else
    {
        for (const auto& [key, value] : this->tasks)
        {
            if (value == true)  done = "X";
            else                done = " ";
            std::cout << " " << counter << ")\t[" << done << "]\t" << key << "\n";
            counter++;
        }
    }
    std::cout << "\n == what to do? ==\n> ";
    return;
}

void Organizer::addTask(std::string name, bool status)
{
    this->tasks[name] = status;
    this->printTasks();
    return;
}

void Organizer::removeTask(std::string mode)
{
    if (mode == "-a" || mode == "--all")
        this->tasks.erase(this->tasks.begin(), this->tasks.end());
    if (mode == "-f" || mode == "--finished")
    {
        for (std::map<std::string, bool>::iterator it = this->tasks.begin(); it != this->tasks.end();)
        {
            if (it->second == true)
            {
                it = this->tasks.erase(it);
            }
            else    it++;
        }
    }
    else
        tasks.erase(mode);
    this->printTasks();
    return;
}

void Organizer::toFile(std::string fileName)
{
    std::ofstream outputfile;
    outputfile.open(fileName);

    std::string done = "";
    int counter = 1;
    outputfile << "\n\t=== " << this->listName << " ===\n";
    if (this->tasks.empty())  std::cout << "\t*empty*\n";
    else
    {
        for (const auto& [key, value] : this->tasks)
        {
            if (value == true)  done = "X";
            else                done = " ";
            outputfile << " " << counter << ")\t[" << done << "]\t" << key << "\n";
            counter++;
        }
    }
    outputfile.close();
    this->printTasks();
}

// constructors and destructors
Organizer::Organizer()
{
    this->listName = nullptr;
}
Organizer::Organizer(std::string _listName)
{
    this->listName = new char[_listName.size() + 1];
    for (size_t i = 0; i < _listName.size(); i++)
    {
        this->listName[i] = _listName[i];
    }
    this->listName[_listName.size()] = '\0';
}
Organizer::~Organizer()
{
    std::cout << "\nDeleting the class " << listName;
    delete[] this->listName;
}

// methods for Shopping List
void ShoppingList::printTasks()
{
    std::string done = "";
    int counter = 1;
    double totalCost = 0;
    std::string temp;
    std::cout << "\n\t=== " << this->listName << " ===\n";
    if (this->tasks.empty())  std::cout << "\t*empty*\n";
    else
    {
        for (const auto& [key, value] : this->tasks)
        {
            temp = "";
            if (value == true)  done = "X";
            else                done = " ";
            std::cout << " " << counter << ")\t[" << done << "]\t" << key << " PLN\n";

            // calculating the cost - looking for a number in the string that isn't on the position 0
            size_t i = 0;
            for (; i < key.length(); i++)
            {
                if (isdigit(key[i]) && i != 0)    break;
            }
            temp = key.substr(i, key.length() - i);     // splitting the string to name and number
            totalCost += atof(temp.c_str());            // atof converts string to double

            counter++;
        }
    }
    std::cout << "Total cost: " << totalCost << " PLN\n";
    std::cout << "\n == what to do? ==\n> ";
    return;
}

void ShoppingList::toFile(std::string fileName)
{
    std::ofstream outputfile;
    outputfile.open(fileName);

    std::string done = "";
    int counter = 1;
    double totalCost = 0;
    std::string temp;
    outputfile << "\n\t=== " << this->listName << " ===\n";
    if (this->tasks.empty())  std::cout << "\t*empty*\n";
    else
    {
        for (const auto& [key, value] : this->tasks)
        {
            temp = "";
            if (value == true)  done = "X";
            else                done = " ";
            outputfile << " " << counter << ")\t[" << done << "]\t" << key << " PLN\n";

            // calculating the cost - looking for a number in the string that isn't on the position 0
            size_t i = 0;
            for (; i < key.length(); i++)
            {
                if (isdigit(key[i]) && i != 0)    break;
            }
            temp = key.substr(i, key.length() - i);
            totalCost += atof(temp.c_str());

            counter++;
        }
    }
    outputfile << "Total cost: " << totalCost << " PLN\n";
    outputfile.close();
    this->printTasks();
}

// constructors and destructors
ShoppingList::ShoppingList()
{
    this->listName = nullptr;
}
ShoppingList::ShoppingList(std::string _listName)
{
    this->listName = new char[_listName.size() + 1];
    for (size_t i = 0; i < _listName.size(); i++)
    {
        this->listName[i] = _listName[i];
    }
    this->listName[_listName.size()] = '\0';
}
ShoppingList::~ShoppingList() {}


// function to handle interface
void interactiveMode(Organizer& list)
{
    std::string input = "";
    list.printTasks();
    while (1)
    {
        input = "";
        std::string taskName = "";
        getline(std::cin, input);

        // splitting input into two substrings
        std::string choice = input.substr(0, 1);

        if (input.length() > 1)
            taskName = input.substr(2);

        if ("p" == choice)      // printing list
        {
            list.printTasks();
        }
        else if ("a" == choice) // adding tasks
        {
            if ("" == taskName)
            {
                std::cout << "You need to provide the task's name!\n";
            }
            else
                list.addTask(taskName, 0);
        }
        else if ("r" == choice) // removing tasks
        {
            if ("" == taskName)
            {
                std::cout << "You need to provide the task's name!\n";
            }
            else
                list.removeTask(taskName);
        }
        else if ("u" == choice) // changing task's status
        {
            if ("" == taskName)
            {
                std::cout << "You need to provide the task's name!\n";
            }
            else
            {
                list.removeTask(taskName);      // sometimes there are duplicates of the same task when updating (not sure why)
                list.addTask(taskName, 1);
            }
        }
        else if ("f" == choice) // output to file
        {
            if ("" == taskName)
            {
                std::cout << "You need to provide the file name!\n";
            }
            else
                list.toFile(taskName);
        }
        else if ("h" == choice) // printing help
        {
            std::cout << "\np - prints the list\na *name* - adds a task\nr *name* - removes a task\nr [-a/--all] - removes all tasks\nr [-f/--finished] - removes finished tasks\nu *name* - updates task's status to 'done'\nf *name* - prints the list to a file with given name\nh - shows this message\nq - goes back to choosing a list\n(for shopping list include the cost at the end of the name)\n\n> ";
        }
        else if ("q" == choice) // exiting
        {
            break;
        }
        else
        {
            std::cout << "(type 'h' to print help)\n> ";
        }
    }
    return;
}