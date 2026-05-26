#ifndef DOLL_H
#define DOLL_H

#include <string>
#include <iostream>

class Doll {
protected:
    std::string name;
    std::string role;

public:
    Doll(std::string n, std::string r);
    virtual ~Doll(); 

    virtual void doSomething(); // Поліморфний метод
};

#endif