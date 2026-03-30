#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;

    double sideAB() const;
    double sideBC() const;
    double sideCA() const;
    double perimeter() const;
    double area() const;
    bool isDegenerate() const;

    bool containsByArea(const Point &P) const;
    int checkPointPosition(const Point &P) const; // 0 - зовні, 1 - всередині, 2 - на межі
};

double crossProduct(Point a, Point b, Point p);

// Основна функція лабораторної роботи
void lab_2();

#endif
