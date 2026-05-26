#include "Doll.h"

Doll::Doll(std::string n, std::string r) : name(n), role(r) {}
Doll::~Doll() {}

void Doll::doSomething() {
    std::cout << name << " (" << role << ") просто відпочиває." << std::endl;
}