#ifndef RAR_H
#define RAR_H

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;
   
    double area() const;                               
    bool isValid() const;                              // VRoDZHENUI
    bool contains(const Point &D) const;       // Point in triangle(heron)
    bool contains2(const Point &D) const;      //point in triangle(vector)
    void verifyPointLocation(const Point &D) const;    // all about the point D
};

double distance(const Point &A, const Point &B);
void Lab_2();                                         

#endif