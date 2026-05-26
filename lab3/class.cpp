#include "class.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>

HospoduDaiSul::HospoduDaiSul() : a(0), b(0), eps(0.0001) {}

void HospoduDaiSul::setIntervals(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void HospoduDaiSul::setTolerance(double vol_eps) {
    eps = vol_eps;
}

// Функція за моїм варіантом: 3*sin(sqrt(x)) + 0.35*x - 3.8
double HospoduDaiSul::f(double x) {
    return 3 * std::sin(std::sqrt(x)) + 0.35 * x - 3.8;
}

// Похідна для методу Ньютона
double HospoduDaiSul::df(double x) {
    if (x <= 0) return 0.35; 
    return (3 * std::cos(std::sqrt(x))) / (2 * std::sqrt(x)) + 0.35;
}

// Метод Дихотомії
void HospoduDaiSul::Dyhotomia() {
    double temp_a = a;
    double temp_b = b;

    if ((f(temp_a) * f(temp_b)) == 0) {
        std::cout << "[Дихотомія] Немає розв'язків на проміжку: (" << temp_a << ":" << temp_b << ")" << std::endl;
        return;
    }

    while (std::abs(temp_a - temp_b) > eps) {
        double c = (temp_a + temp_b) / 2;   //перевіряємо добуток від числа та середини проміжку
        if ((f(temp_a) * f(c)) < 0) {
            temp_b = c;
        } else {
            temp_a = c;
        }
    }
    double x = (temp_a + temp_b) / 2;
    std::cout << "[Метод Дихотомії] Наш корінь: " << std::fixed << std::setprecision(5) << x << std::endl;
}

// Метод Ньютона (Дотичних)
void HospoduDaiSul::Newton() {
 
    double x = 5; // Початкове наближення посередині проміжку
    int iterations = 0;
    
    while (std::abs(f(x)) > eps && iterations < 1000) {
        double d = df(x);
        if (std::abs(d) < 1e-9) {
            std::cout << "[Ньютон] Похідна близька до 0. Зупинка." << std::endl;
            return;
        }
        x = x - f(x) / d;
        iterations++;
    }
    std::cout << "[Метод Ньютона] Наш корінь: " << std::fixed << std::setprecision(5) << x << std::endl;
}

HospoduDaiSul::~HospoduDaiSul() {
    std::cout << "Об'єкт класу видалено (пам'ять очищена)." << std::endl;
}

void Lab_3() {

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    HospoduDaiSul *cls = new HospoduDaiSul();
    double in_a, in_b, in_eps;

    std::cout << "Введіть проміжок (наприклад, 2 3): ";
    std::cin >> in_a >> in_b;
    std::cout << "Введіть точність eps (наприклад, 0.0001): ";
    std::cin >> in_eps;

    cls->setIntervals(in_a, in_b);   //викликаємо методи класу 
    cls->setTolerance(in_eps);

    cls->Dyhotomia();
    cls->Newton();

    delete cls;
}
