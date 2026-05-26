#ifndef STACIE_H
#define STACIE_H

#include "Doll.h"

class Stacie : public Doll {
public:
    Stacie();
    void doSomething() override;
};

#endif