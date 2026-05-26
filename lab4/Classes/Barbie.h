#ifndef BARBIE_H
#define BARBIE_H

#include "Doll.h"

class Barbie : public Doll {
public:
    Barbie();
    void doSomething() override; // Перевизначення (Override)

    // Перевантаження (Overloading)
    void talk();
    void talk(std::string message);
};

#endif