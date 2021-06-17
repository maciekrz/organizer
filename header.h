#pragma once
#include <map>
#include <string>
#include <iostream>
#include <fstream>

class Organizer
{

protected:
    char* listName;
    std::map<std::string, bool> tasks;

public:
    int countTasks();

    virtual void printTasks();

    void addTask(std::string name, bool status);

    void removeTask(std::string mode);

    virtual void toFile(std::string fileName);

    Organizer();
    Organizer(std::string _listName);
    ~Organizer();
};

class ShoppingList :public Organizer
{
public:
    void printTasks();

    void toFile(std::string fileName);

    ShoppingList();
    ShoppingList(std::string _listName);
    ~ShoppingList();
};

void interactiveMode(Organizer& list);