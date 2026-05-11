#ifndef CLASS_H
#define CLASS_H

class HospoduDaiSul {
private:
    double a, b, eps;
    // Твої функції з варіанту
    double f(double x);
    double df(double x);

public:
    HospoduDaiSul();
    ~HospoduDaiSul();

    // Методи для встановлення параметрів (інкапсуляція)
    void setIntervals(double vol_a, double vol_b);
    void setTolerance(double vol_eps);

    // Методи розв'язання
    void Dyhotomia();
    void Newton();
};

// Функція виклику лабораторної
void Lab_3();

#endif
