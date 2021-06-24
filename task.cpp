#include "task.h"

//  Task class
    Task::Task()
    {
        //this->name = nullptr;
        //this->desc = nullptr;
        this->name = "";
        this->desc = "";
        this->status = false;
    }
    Task::~Task() { }

    void Task::print()
    {
        std::cout << name << "\n|\t(" << desc << ")\n";
    }

    void Task::set(std::string_view _name, std::string_view _desc, bool _status)
    {
        /*
        this->name = new char[_name.size() + 1];
        for (size_t i = 0; i < _name.size(); i++)
        {
            this->name[i] = _name[i];
        }
        this->name[_name.size()] = '\0';

        this->desc = new char[_desc.size() + 1];
        for (size_t i = 0; i < _desc.size(); i++)
        {
            this->desc[i] = _desc[i];
        }
        this->desc[_desc.size()] = '\0';
        */
        this->name = _name;
        this->desc = _desc;
        this->status = _status;
    }

//  Product class
    Product::Product()
    {
        //this->name = nullptr;
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
        /*
        this->name = new char[_name.size() + 1];
        for (size_t i = 0; i < _name.size(); i++)
        {
            this->name[i] = _name[i];
        }
        this->name[_name.size()] = '\0';
        */
        this->name = _name;
        this->cost = _cost;
        this->status = _status;
    }

    double Product::getCost() { return this->cost; }
