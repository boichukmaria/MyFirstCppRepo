#include "Ken.h"

Ken::Ken() : Doll("Ken", "Beach Guy") {}

void Ken::doSomething() {
    std::cout << name << " йде на пляж. Його робота — просто кадрити Barbie." << std::endl;
}