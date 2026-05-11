#include <iostream>
#include <cmath>
#include <algorithm>
#include <windows.h>

struct Point {
    double x, y;
};

class Triangle {
public:
    Point A, B, C;

    // Площа через векторний добуток
    double area() const {
        return 0.5 * std::fabs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
    }

    // Статичний метод для обчислення площі довільного трикутника за трьома точками
    static double areaOf(Point p1, Point p2, Point p3) {
        return 0.5 * std::fabs((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y));
    }

    bool isValid() const {
        return area() > 1e-9; 
    }

    // МЕТОД 1: Векторний (черех косої добуток)
    bool containsVector(const Point &P) const {
        auto crossProduct = [](Point a, Point b, Point p) {
            return (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
        };

        double cp1 = crossProduct(A, B, P);
        double cp2 = crossProduct(B, C, P);
        double cp3 = crossProduct(C, A, P);

        bool has_neg = (cp1 < -1e-12) || (cp2 < -1e-12) || (cp3 < -1e-12);
        bool has_pos = (cp1 > 1e-12) || (cp2 > 1e-12) || (cp3 > 1e-12);
        
        return !(has_neg && has_pos);
    }

    // МЕТОД 2: Площинний (через суму площ підтрикутників)
    bool containsArea(const Point &P) const {
        double mainArea = area();
        double area1 = areaOf(P, A, B);
        double area2 = areaOf(P, B, C);
        double area3 = areaOf(P, C, A);

        // Якщо сума площ частин дорівнює цілому, точка всередині
        return std::fabs(mainArea - (area1 + area2 + area3)) < 1e-9;
    }
};

void Lab_2() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Triangle tri;
    
    while (true) {
        std::cout << "Введіть x y для вершин A, B, C:\n";
        std::cin >> tri.A.x >> tri.A.y >> tri.B.x >> tri.B.y >> tri.C.x >> tri.C.y;

        if (tri.isValid()) {
            std::cout << "Площа трикутника: " << tri.area() << "\n";
            break;
        } else {
            std::cout << "Увага: Трикутник вироджений (площа 0)!\n";
            std::cout << "Бажаєте спробувати ще раз? (1 - так, 0 - продовжити як є): ";
            bool retry;
            std::cin >> retry;
            if (!retry) break;
        }
    }

    int n;
    std::cout << "\nСкільки точок перевірити? ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        Point P;
        std::cout << "\nВведіть координати точки P (x y): ";
        std::cin >> P.x >> P.y;

        // Висновок за двома методами
        std::cout << "    Результати для точки (" << P.x << ", " << P.y << ")    \n";
        
        std::cout << "1. Векторний метод: " 
                  << (tri.containsVector(P) ? "Всередині" : "Зовні") << "\n";
        
        std::cout << "2. Метод площ:     " 
                  << (tri.containsArea(P) ? "Всередині" : "Зовні") << "\n";
    }
}
