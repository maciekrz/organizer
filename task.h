#pragma once

#include "libraries.h"

/// <summary>
/// Base class that represents a task.
/// </summary>
/// <param name="desc">A description of the task</param>
/// <param name="name">A name of the task</param>
/// <param name="status">A status of the task represented by a boolean value</param>
class Task    
{
    std::string desc;   // description of the task

public:
    std::string name;   // name of the task
    bool status;        // status of the task

    Task();
    ~Task();

    /// <summary>
    /// An overloaded operator for outputting object's values.
    /// </summary>
    /// <returns>A string that is ready for being put either on screen or to file</returns>
    friend std::ostream& operator<<(std::ostream& os, Task const& task) 
    {
        return os << task.name << "\n|\t(" << task.desc << ")\n";
    }

    virtual void print();
    /// <summary>
    /// A three-argument method that changes object's values.
    /// </summary>
    /// <param name="_name">The new name for the task</param>
    /// <param name="_desc">The new description for the task</param>
    /// <param name="_status">The new status of the task</param>
    virtual void set(std::string_view _name, std::string_view _desc, bool _status);
    /// <summary>
    /// An overloaded two-argument method that changes object's values.
    /// Works the same as its original version, but sets status value as false by default.
    /// </summary>
    virtual void set(std::string_view _name, std::string_view _desc);
};

/// <summary>
/// Derived class from class Task that becomes a product for purchase.
/// Methods and overloaded operator work the same as in base class but are slighty changed.
/// </summary>
/// <param name="cost">A cost of the product</param>
class Product :public Task
{
    double cost;        // cost of the product

public:
    Product();
    ~Product();

    friend std::ostream& operator<<(std::ostream& os, Product const& prod) 
    {
        return os << prod.name << ": " << prod.cost << " PLN\n";
    }

    void print();
    void set(std::string_view _name, double _cost, bool _status);
    void set(std::string_view _name, double _cost);
    double getCost();
};
