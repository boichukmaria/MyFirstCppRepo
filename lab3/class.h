#ifndef CLASS_H
#define CLASS_H

class HospoduDaiSul {
private:
    double a, b, eps;   //доступитись через конструктор або сеттери і гетери  

public:
 // Мої функції з варіанту
    double f(double x);
    double df(double x);  
    
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
