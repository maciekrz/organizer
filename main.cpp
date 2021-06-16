#include <map>
#include <string>
#include <iostream>
#include <fstream>

class Organizer
{
    //char* listname;
    //std::map<std::string, bool> tasks;

public:

    char* listName;
    std::map<std::string, bool> tasks;      // string is the task and bool is its status (finished or not)

    int countTasks()
    {
        int counter = 0;
        for (const auto& [key, value] : this->tasks)
        {
            counter++;
        }
        return counter;
    }

    virtual void printTasks()
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

    void addTask(std::string name, bool status)
    {
        this->tasks[name] = status;
        this->printTasks();
        return;
    }

    void removeTask(std::string mode)
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

    void toFile(std::string fileName)
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

    Organizer()
    {
        this->listName = nullptr;
    }
    Organizer(std::string _listName)    // constructor
    {
        this->listName = new char[_listName.size() + 1];
        for (size_t i = 0; i < _listName.size(); i++)
        {
            this->listName[i] = _listName[i];
        }
        this->listName[_listName.size()] = '\0';
    }
    ~Organizer()                        // destructor
    {
//        std::cout << "\nDeleting the class " << listName;
//        delete[] this->listName;
    }
};

class ShoppingList :public Organizer
{
public:

    void printTasks()
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
                std::cout << " " << counter << ")\t[" << done << "]\t" << key << "\n";

                // calculating the cost
                size_t i = 0;
                for (; i < key.length(); i++)
                {
                    if (isdigit(key[i]))    break;
                }
                temp = key.substr(i, key.length() - i);
                totalCost += atof(temp.c_str());

                counter++;
            }
        }
        std::cout << "Total cost: " << totalCost << "\n";
        std::cout << "\n == what to do? ==\n> ";
        return;
    }

    ShoppingList()
    {
        this->listName = nullptr;
    }
    ShoppingList(std::string _listName)    // constructor
    {
        this->listName = new char[_listName.size() + 1];
        for (size_t i = 0; i < _listName.size(); i++)
        {
            this->listName[i] = _listName[i];
        }
        this->listName[_listName.size()] = '\0';
    }
    ~ShoppingList()                        // destructor
    {
        std::cout << "\nDeleting the class " << listName;
        delete[] this->listName;
    }
};

/*
class ShoppingList :public Organizer
{
public:
    char* listName;

    ShoppingList()
    {
        this->listName = nullptr;
    }
    ShoppingList(std::string _listName)    // constructor
    {
        this->listName = new char[_listName.size() + 1];
        for (size_t i = 0; i < _listName.size(); i++)
        {
            this->listName[i] = _listName[i];
        }
        this->listName[_listName.size()] = '\0';
    }
    ~ShoppingList()                        // destructor
    {
        std::cout << "\nDeleting the class " << listName;
        delete[] this->listName;
    }
};
*/

void interactiveMode(Organizer& list)
{
    std::string input = "";
    std::cout << "\np - prints the list\na *name* - adds a task\nr *name* - removes a task\nr [-a/--all] - removes all tasks\nr [-f/--finished] - removes finished tasks\nu *name* - updates task's status to 'done'\nf *name* - prints the list to a file with given name\nh - shows this message\nq - goes back to choosing a list\n\n";
    list.printTasks();
    while (1)
    {
        input = "";
        std::string taskName = "";
        getline(std::cin, input);

        // splitting input into two substrings
        std::string choice = input.substr(0,1);

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
            std::cout << "\np - prints the list\na *name* - adds a task\nr *name* - removes a task\nr [-a/--all] - removes all tasks\nr [-f/--finished] - removes finished tasks\nu *name* - updates task's status to 'done'\nf *name* - prints the list to a file with given name\nh - shows this message\nq - goes back to choosing a list\n\n";
        }
        else if ("q" == choice) // exiting
        {
            break;
        }
        else
        {
            std::cout << "Wrong command! (type 'h' to print help!)\n> ";
        }
    }
    return;
}

int main()
{
    Organizer home("HOME"), work("WORK"), shopping("SHOPPING");
    ShoppingList SL("SHOPPING LIST");
    std::cout << "\nType in the name of a list to see its content or \"end\" to exit the program\n";
    std::string listName = "";
    while (1)
    {
        std::cout << "\nChoose the list:\n[ home (" << home.countTasks() << ") ][ work (" << work.countTasks() << ") ][ shopping (" << SL.countTasks() << ") ][ end ]: ";
        std::cin >> listName;
        if ("home" == listName)             interactiveMode(home);
        else if ("work" == listName)        interactiveMode(work);
        //else if ("shopping" == listName)    interactiveMode(shopping);
        else if ("shopping" == listName)    interactiveMode(SL);
        else if ("end" == listName)         break;
        else                                std::cout << "Wrong name!";
    }
    
    std::cout << "\n";
    return 0;
}

