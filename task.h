#pragma once

#include "libraries.h"

struct Task    
{
    std::string name;   // name of the task
    bool status;        // status of the task

    Task();
    ~Task();

    // overloaded operator for outputting values
    friend std::ostream& operator<<(std::ostream& os, Task const& task) 
    {
        return os << task.name << "\n|\t(" << task.desc << ")\n";
    }

    virtual void print();
    virtual void set(std::string_view _name, std::string_view _desc, bool _status);
    virtual void set(std::string_view _name, std::string_view _desc);
private:
    std::string desc;   // description of the task
};

struct Product :public Task
{
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
private:
    double cost;        // cost of the product
};
