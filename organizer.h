#pragma once

#include "libraries.h"
#include "task.h"

/// <summary>
/// Base class used as a list of tasks to do.
/// </summary>
/// <param name="list">A vector of objects of type Task</param>
/// <param name="listName">Name of the list</param>
/// <param name="_task">An object that is being modified with its copy being pushed on the list</param>
class Organizer
{
private:
    std::vector<Task> list;
    Task _task;

protected:
    std::string listName;

    /// <summary>
    /// A method for printing the list.
    /// </summary>
    virtual void printAll();
    /// <summary>
    /// A method for printing the list to file.
    /// </summary>
    virtual void printListToFile();
    /// <summary>
    /// A method for pushing a new task on the list.
    /// </summary>
    virtual void addTask();
    /// <summary>
    /// A method for changing task's status.
    /// </summary>
    virtual void updateTask();
    /// <summary>
    /// A method for removing a specific task from the list.
    /// </summary>
    virtual void removeTask();
    /// <summary>
    /// A method for removing finished tasks.
    /// </summary>
    virtual void removeFinished();
    /// <summary>
    /// A method that prints available options for the user.
    /// </summary>
    void printHelp();

public:
    /// <summary>
    /// A method for removing all tasks.
    /// </summary>
    virtual void removeAll();
    /// <summary>
    /// A method for calculating number of tasks in the list.
    /// </summary>
    /// <returns>Number of tasks</returns>
    virtual int countTasks();
    /// <summary>
    /// A method for getting a name of the list.
    /// </summary>
    /// <returns>Name of the list</returns>
    std::string getName();
    /// <summary>
    /// A method that sets a new name for the list.
    /// </summary>
    void setName();
    /// <summary>
    /// A method that calls other methods depending on user's input.
    /// </summary>
    void interactiveMode();
    /// <summary>
    /// One-argument constructor.
    /// </summary>
    /// <param name="_listName">A name for the list</param>
    Organizer(std::string_view _listName);
    /// <summary>
    /// Default constructor.
    /// </summary>
    Organizer();
    ~Organizer();
};

/// <summary>
/// Derived class from class Organizer that is a shopping list.
/// Instead of vector of objects of type Task, it holds objects of type Product.
/// Its methods work the same as in class Organizer but were changed to work with Products and not Tasks.
/// </summary>
/// <param name="list">A vector of objects of type Product</param>
/// <param name="_product">An object that is being modified with its copy being pushed on the list</param>
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
    ShoppingList(std::string_view _listName);
    ShoppingList();
    ~ShoppingList();
    void removeAll();
    int countTasks();
};
