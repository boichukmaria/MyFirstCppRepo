#include "Barbie.h"

Barbie::Barbie() : Doll("Barbie", "Fashion Icon") {}

void Barbie::doSomething() {
    std::cout << name << " влаштовує вечірку в Dreamhouse!" << std::endl;
}

void Barbie::talk() {
    std::cout << name << " каже: 'Hi!'" << std::endl;
}

void Barbie::talk(std::string message) {
    std::cout << name << " каже: '" << message << "'" << std::endl;
}