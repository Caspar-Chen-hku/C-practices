#include "Complex.h"
#include <iostream>
using namespace std;

Complex::Complex(){a=0;b=0;}
Complex::Complex(double real,double imagine){
a=real;
b=imagine;}
double Complex::getReal(){return a;}
double Complex::getImaginary(){return b;}
void Complex::setReal(double real){a=real;}
void Complex::setImaginary(double imagine){b=imagine;}
ostream& operator<<(ostream& cout, const Complex x){
  
    if (x.b>0) 
   cout << x.a << "+" << x.b << "i";
   else  cout << x.a << x.b << "i";
    return cout;
}
Complex operator+(Complex x,Complex y){
Complex z(x.a+y.a,x.b+y.b);
return z;}
Complex operator+ (Complex x,double y){
Complex z(x.a+y,x.b);
return z;}
Complex operator+(double y,Complex x){
Complex z(x.a+y,x.b);
return z;}
Complex operator-(Complex x,Complex y){
Complex z(x.a-y.a,x.b-y.b);
return z;}
Complex operator- (Complex x,double y){
Complex z(x.a-y,x.b);
return z;}
Complex operator-(double y,Complex x){
Complex z(y-x.a,-x.b);
return z;}
Complex operator*(Complex x,Complex y){
Complex z(x.a*y.a-x.b*y.b,x.b*y.a+x.a*y.b);
return z;}
Complex operator*(Complex x,double y){
Complex z(y*x.a,y*x.b);
return z;}
Complex operator*(double y,Complex x){
Complex z(y*x.a,y*x.b);
return z;}
Complex operator*=(Complex& x,Complex& y){
        double temp=x.a;
x.a=x.a*y.a-x.b*y.b;

x.b=x.b*y.a+temp*y.b;

return x;}
