#pragma once

#include "libraries.h"
#include "task.h"

class Organizer
{
private:
    std::vector<Task> list;
    Task _task;

protected:
    std::string listName;

    virtual void printAll();    
    virtual void printListToFile();
    virtual void addTask();
    virtual void updateTask();
    virtual void removeTask();    
    virtual void removeFinished();
    void printHelp();

public:
    virtual void removeAll();    
    virtual int countTasks();
    std::string getName();
    void setName();
    void interactiveMode();
    Organizer(std::string _listName);
    Organizer();    
    ~Organizer();
};

class ShoppingList :public Organizer
{
private:
    Product _product;
    std::vector<Product> list;

    void printListToFile();
    void addTask();
    void printAll();
    void removeTask();
    void removeFinished();
    void updateTask();

public:
    ShoppingList(std::string _listName);
    ShoppingList();
    ~ShoppingList();
    void removeAll();
    int countTasks();
};
