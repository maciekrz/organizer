#pragma once

#include "libraries.h"

struct Task    
{
    char* name;
    bool status;

    Task();
    ~Task();

    friend std::ostream& operator<<(std::ostream& os, Task const& task) 
    {
        return os << task.name << "\n|\t(" << task.desc << ")\n";
    }

    virtual void print();
    virtual void set(std::string _name, std::string _desc, bool _status);
private:
    char* desc;
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
    void set(std::string _name, double _cost, bool _status);
    double getCost();

private:
    double cost;
};
