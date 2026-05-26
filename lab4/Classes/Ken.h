#ifndef KEN_H
#define KEN_H

#include "Doll.h"

class Ken : public Doll {
public:
    Ken();
    void doSomething() override;
};

#endif