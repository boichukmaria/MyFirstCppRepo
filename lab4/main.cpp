#include "Barbie.h"
#include "Ken.h"
#include "Stacie.h"
#include "Raquelle.h"
#include <vector>
#include <iostream>
#include <windows.h> 

void runLab() {

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Поліморфізм: список вказівників на базовий клас
    std::vector<Doll*> box;

    box.push_back(new Barbie());
    box.push_back(new Ken());
    box.push_back(new Stacie());
    box.push_back(new Raquelle());    

    std::cout << "--- Barbie World Simulation ---" << std::endl;

    for (Doll* d : box) {
        d->doSomething(); 
    }

    // Демонстрація перевантаження
    std::cout << "\n--- Overloading Demo ---" << std::endl;
    Barbie* b = static_cast<Barbie*>(box[0]);
    b->talk();
    b->talk("Today is the best day ever!");

    // Очищення пам'яті
    for (Doll* d : box) delete d;
}

int main() {
    runLab();
    return 0;
}