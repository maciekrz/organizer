#include "task.h"

//  Task class
    Task::Task()
    {
        this->name = "";
        this->desc = "";
        this->status = false;
    }
    Task::~Task() { }

    void Task::print()
    {
        std::cout << name << "\n|\t(" << desc << ")\n";
    }

    void Task::set(std::string_view _name, std::string_view _desc, bool _status)    // setting new values to the task
    {
        this->name = _name;
        this->desc = _desc;
        this->status = _status;
    }


//  Product class
    Product::Product()
    {
        this->name = "";
        this->cost = 0;
        this->status = false;
    }
    Product::~Product() { }

    void Product::print()
    {
        std::cout << name << ": " << cost << " PLN\n";
    }

    void Product::set(std::string_view _name, double _cost, bool _status)
    {
        this->name = _name;
        this->cost = _cost;
        this->status = _status;
    }

    double Product::getCost() { return this->cost; }
