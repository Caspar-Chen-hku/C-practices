#ifndef QUATERNION_H
#define QUATERNION_H
#include <iostream>
using namespace std;

class Quaternion{
      public:
              double a;
              double b;
              double c;
              double d;
      public:
             Quaternion();
             Quaternion(double q, double w, double e, double r);
             void setValue(double q,double w,double e,double r);
             friend ostream& operator<<( ostream& cout, const Quaternion m );
             friend Quaternion operator+(Quaternion m, Quaternion n );
            friend Quaternion operator-( Quaternion m,  Quaternion n );
            friend Quaternion operator*( Quaternion m,  Quaternion n );
             };
#endif