#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

class Complex{
    private:
    double a;
    double b;
public:
    Complex();
    Complex(double real,double imagine);
    void setReal(double real);
    void setImaginary(double imagine);
    double getReal();
    double getImaginary();
    friend ostream& operator<<(ostream& cout, const Complex x);
    friend Complex operator+(Complex x,Complex y);
    friend Complex operator+ (Complex x,double y);
    friend Complex operator+(double y,Complex x);
    friend Complex operator-(Complex x,Complex y);
    friend Complex operator- (Complex x,double y);
    friend Complex operator-(double y,Complex x);
    friend Complex operator*(Complex x,Complex y);
    friend Complex operator*(Complex x,double y);
    friend Complex operator*(double y,Complex x);
    friend Complex operator*=(Complex& x,Complex& y);
};

#endif // COMPLEX_H
