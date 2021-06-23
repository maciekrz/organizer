#include "organizer.h"

//	Organizer class
    void Organizer::printAll()
    {
        std::string heading = "+===  " + this->listName + "  ===+";
        int headingLength = heading.length();
        std::cout << "\n" << heading << "\n|\n";
        int i = 1;
        for (auto x : this->list)
        {
            std::string X = " ";
            if (x.status)
                X = "X";
            std::cout << "| [" << X <<"] " << i << ") ";
            std::cout << x;
            i++;
        }
        std::cout << "|\n+" << std::string(headingLength-2, '=') << "+ \n\n";
    }

    void Organizer::printListToFile()
    {
        std::string fileName = this->listName + ".txt";
        std::cout << "Printing to file " << fileName << "\n";
        std::ofstream outputfile;
        outputfile.open(fileName);
        std::string heading = "+===  " + this->listName + "  ===+";
        int headingLength = heading.length();
        outputfile << "\n" << heading << "\n|\n";
        int i = 1;
        for (auto x : this->list)
        {
            std::string X = " ";
            if (x.status)
                X = "X";
            outputfile << "| [" << X << "] " << i << ") ";
            outputfile << x;
            i++;
        }
        outputfile << "|\n+" << std::string(headingLength-2, '=') << "+ \n\n";
        outputfile.close();
    }

    void Organizer::addTask()
    {
        std::string _name, _desc;
        std::cout << "Task name:  ";
        std::cin.ignore();
        std::getline(std::cin, _name);
        if (_name == "")
            std::getline(std::cin, _name);

        std::cout << "Task description:  ";
        std::getline(std::cin, _desc);
        this->_task.set(_name, _desc, 0);
        this->list.push_back(_task);
    }

    void Organizer::updateTask()
    {
        std::string tmp;
        int pos;
        std::cout << "Position of task to change status:  ";
        std::cin >> tmp;
        std::istringstream iss(tmp);
        if (iss >> pos && this->list.size() >= pos && pos > 0)
            this->list[pos - 1].status = !this->list[pos - 1].status;
        else
            std::cout << "No such position in the list!\n";
    }

    void Organizer::removeTask()
    {
        std::string tmp;
        int pos;
        std::cout << "Position of task to remove:  ";
        std::cin >> tmp;
        std::istringstream iss(tmp);
        iss >> pos;
        if (iss.eof() && this->list.size() >= pos && pos > 0)
            this->list.erase(this->list.begin() + pos - 1);
        else
            std::cout << "\nNo such position in the list!\n";
    }
    void Organizer::removeAll()
    {
        this->list.clear();
    }
    void Organizer::removeFinished()
    {
        int i = 0;
        for (auto x : this->list)
        {
            if (x.status)
            {
                this->list.erase(this->list.begin() + i);
            }
            i++;
        }
    }

    void Organizer::printHelp()
    {
        std::cout << "\n  Available commands:\n";
        std::cout << "\n add - adds a task\n"
            << " remove - removes a task\n"
            << " update - changes task's status\n"
            << " print - prints the list to a file\n"
            << " rename *new name* - renames the list\n"
            << " help - shows this message\n"
            << " quit - quits the list\n";
    }

    int Organizer::countTasks()
    {
        return this->list.size();
    }

    std::string Organizer::getName()
    {
        return this->listName;
    }

    void Organizer::setName()
    {
        std::string _name;
        std::getline(std::cin, _name);
        this->listName = _name;
    }

    // function to handle interface
    void Organizer::interactiveMode()
    {
        std::string command;
        this->printHelp();
        while (1)
        {
            command = "";
            this->printAll();
            std::cout << " ~> ";
            std::cin >> command;
            if ("add" == command)
            {
                this->addTask();
            }
            else if ("remove" == command)
            {
                char choice;
                std::cout << "(S)pecific / (F)inished / (A)ll:  ";
                std::cin >> choice;
                if ('s' == choice || 'S' == choice)
                    this->removeTask();
                else if ('f' == choice || 'F' == choice)
                    this->removeFinished();
                else if ('a' == choice || 'A' == choice)
                    this->removeAll();
            }
            else if ("update" == command)
            {
                this->updateTask();
            }
            else if ("print" == command)
            {
                this->printListToFile();
            }
            else if ("rename" == command)
            {
                this->setName();
            }
            else if ("help" == command)
            {
                this->printHelp();
            }
            else if ("quit" == command)
            {
                break;
            }
            else
            {
                std::cout << "Error: unknown command (" << command << "), try again\n";
            }
        }
        return;
    }

    Organizer::Organizer(std::string _listName) : listName(_listName) {}
    Organizer::Organizer() 
    {
        this->listName = "";
    }
    Organizer::~Organizer() { }

//  ShoppingList class
    void ShoppingList::printListToFile()
    {
        std::string fileName = this->listName + ".txt";
        std::cout << "Printing to file " << fileName << "\n";
        std::ofstream outputfile;
        outputfile.open(fileName);
        std::string heading = "+===  " + this->listName + "  ===+";
        int headingLength = heading.length();
        outputfile << "\n" << heading << "\n|\n";
        int i = 1;
        double totalCost = 0;
        for (auto x : this->list)
        {
            std::string X = " ";
            if (x.status)
                X = "X";
            outputfile << "| [" << X << "] " << i << ") ";
            outputfile << x;
            totalCost += x.getCost();
            i++;
        }
        outputfile << "|\n+===\n|Total cost:\n| " << totalCost << " PLN\n+" << std::string(headingLength-2, '=') << "+ \n\n";
        outputfile.close();
    }

    void ShoppingList::addTask()
    {
        std::string _name, tmp;
        double _cost;
        std::cout << "Product:  ";
        std::cin.ignore();
        std::getline(std::cin, _name);
        if (_name == "")
            std::getline(std::cin, _name);

        std::cout << "Cost:  ";
        std::cin >> tmp;
        std::istringstream iss(tmp);
        iss >> _cost;
        if (iss.eof())
        {
            this->_product.set(_name, _cost, 0);
            this->list.push_back(_product);
        }
        else
            std::cout << "Cost must be a number, try again.\n";
    }

    void ShoppingList::printAll()
    {
        std::string heading = "+===  " + this->listName + "  ===+";
        int headingLength = heading.length();
        std::cout << "\n" << heading << "\n|\n";
        int i = 1;
        double totalCost = 0;
        for (auto x : this->list)
        {
            std::string X = " ";
            if (x.status)
                X = "X";
            std::cout << "| [" << X << "] " << i << ") ";
            std::cout << x;
            totalCost += x.getCost();
            i++;
        }
        std::cout << "|\n+===\n|Total cost:\n| " << totalCost << " PLN\n+" << std::string(headingLength-2, '=') << "+ \n\n";
    }

    void ShoppingList::removeTask()
    {
        std::string tmp;
        int pos;
        std::cout << "Position of task to remove:  ";
        std::cin >> tmp;
        std::istringstream iss(tmp);
        iss >> pos;
        if (iss.eof() && this->list.size() >= pos && pos > 0)
            this->list.erase(this->list.begin() + pos - 1);
        else
            std::cout << "\nNo such position in the list!\n";
    }
    void ShoppingList::removeAll()
    {
        this->list.clear();
    }
    void ShoppingList::removeFinished()
    {
        int i = 0;
        for (auto x : this->list)
        {
            if (x.status)
            {
                this->list.erase(this->list.begin() + i);
            }
            i++;
        }
    }

    void ShoppingList::updateTask()
    {
        std::string tmp;
        int pos;
        std::cout << "Position of task to change status:  ";
        std::cin >> tmp;
        std::istringstream iss(tmp);
        if (iss >> pos && this->list.size() >= pos && pos > 0)
            this->list[pos - 1].status = !this->list[pos - 1].status;
        else
            std::cout << "No such position in the list!\n";
    }

    ShoppingList::ShoppingList(std::string _listName) : Organizer(_listName) {}
    ShoppingList::ShoppingList() 
    {
        this->listName = "";
    }
    ShoppingList::~ShoppingList() { }

    int ShoppingList::countTasks()
    {
        return this->list.size();
    }
