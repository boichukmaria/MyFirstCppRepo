#include "triangle.h"
#include <iostream>
#include <cmath>

double dist(Point p1, Point p2) {
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

double Triangle::sideAB() const { return dist(A, B); }
double Triangle::sideBC() const { return dist(B, C); }
double Triangle::sideCA() const { return dist(C, A); }

double Triangle::perimeter() const {
    return sideAB() + sideBC() + sideCA();
}

double Triangle::area() const {
    return std::abs((A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y)) / 2.0);
}

bool Triangle::isDegenerate() const {
    return area() < 1e-9;
}

double crossProduct(Point a, Point b, Point p) {
    return (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
}

bool Triangle::containsByArea(const Point &P) const {
    double S_main = area();
    Triangle T1 = {A, B, P}, T2 = {B, C, P}, T3 = {C, A, P};
    return std::abs(S_main - (T1.area() + T2.area() + T3.area())) < 1e-9;
}

int Triangle::checkPointPosition(const Point &P) const {
    double cp1 = crossProduct(A, B, P);
    double cp2 = crossProduct(B, C, P);
    double cp3 = crossProduct(C, A, P);

    // Перевірка на якій саме стороні лежить точка
    if (std::abs(cp1) < 1e-9 && ((P.x - A.x)*(P.x - B.x) <= 1e-9 && (P.y - A.y)*(P.y - B.y) <= 1e-9)) return 21; // Сторона AB
    if (std::abs(cp2) < 1e-9 && ((P.x - B.x)*(P.x - C.x) <= 1e-9 && (P.y - B.y)*(P.y - C.y) <= 1e-9)) return 22; // Сторона BC
    if (std::abs(cp3) < 1e-9 && ((P.x - C.x)*(P.x - A.x) <= 1e-9 && (P.y - C.y)*(P.y - A.y) <= 1e-9)) return 23; // Сторона CA

    bool allPositive = (cp1 > 1e-9 && cp2 > 1e-9 && cp3 > 1e-9);
    bool allNegative = (cp1 < -1e-9 && cp2 < -1e-9 && cp3 < -1e-9);

    return (allPositive || allNegative) ? 1 : 0;
}

void lab_2() {
    Triangle t;
    std::cout << " " << std::endl;
    std::cout << "Введіть координати вершин (x1 y1 x2 y2 x3 y3): ";
    if (!(std::cin >> t.A.x >> t.A.y >> t.B.x >> t.B.y >> t.C.x >> t.C.y)) return;

    std::cout << "\nІнформація про трикутник:" << std::endl;
    std::cout << "- Сторони: AB=" << t.sideAB() << ", BC=" << t.sideBC() << ", CA=" << t.sideCA() << std::endl;
    std::cout << "- Периметр: " << t.perimeter() << std::endl;
    std::cout << "- Площа: " << t.area() << std::endl;
    std::cout << "- Вироджений трикутник: " << (t.isDegenerate() ? "Так" : "Ні") << std::endl;

    if (t.isDegenerate()) return;

    int n;
    std::cout << "\nСкільки точок перевірити? ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        Point p;
        std::cout << "\nТочка " << i + 1 << " (x y): ";
        std::cin >> p.x >> p.y;

        int pos = t.checkPointPosition(p);

        std::cout << "Результат за методом площі: " 
                  << (t.containsByArea(p) ? "Належить" : "Не належить") << std::endl;

        std::cout << "Результат за векторним методом: " 
                  << (pos > 0 ? "Належить" : "Не належить") << std::endl;

        std::cout << "Місцезнаходження точки: ";
        if (pos == 1) std::cout << "Всередині трикутника" << std::endl;
        else if (pos == 21) std::cout << "На межі (сторона AB)" << std::endl;
        else if (pos == 22) std::cout << "На межі (сторона BC)" << std::endl;
        else if (pos == 23) std::cout << "На межі (сторона CA)" << std::endl;
        else std::cout << "Зовні трикутника" << std::endl;
    }
}