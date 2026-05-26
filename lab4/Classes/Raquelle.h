#ifndef RAQUELLE_H
#define RAQUELLE_H

#include "Doll.h" // Або "Barbie.h", якщо наслідувати від Барбі

class Raquelle : public Doll {
public:
    Raquelle();
    void doSomething() override;
};

#endif