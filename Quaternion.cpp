#include <iostream>
#include "Quaternion.h"
#include <iomanip>

Quaternion operator+(Quaternion m, Quaternion n ){
           Quaternion x(m.a+n.a,m.b+n.b,m.c+n.c,m.d+n.d);
           
           return x;}
Quaternion operator-(Quaternion m, Quaternion n ){
            Quaternion x(m.a-n.a,m.b-n.b,m.c-n.c,m.d-n.d);
            
            return x;}
Quaternion operator*( Quaternion m,  Quaternion n ){
            Quaternion x(m.a*n.a-m.b*n.b-m.c*n.c-m.d*n.d,
            m.a*n.b+m.b*n.a-m.d*n.c+m.c*n.d,m.a*n.c+m.c*n.a+m.d*n.b-m.b*n.d,
            m.a*n.d+m.d*n.a+m.b*n.c-m.c*n.b);
           
            return x;}
Quaternion::Quaternion(){
             a=0;
             b=0;
             c=0;
             d=0;}
Quaternion::Quaternion(double q, double w, double e, double r){
                   a=q;
                   b=w;
                   c=e;
                   d=r;}
void Quaternion::setValue(double q,double w,double e,double r){
                   a=q;
                   b=w;
                   c=e;
                   d=r;}
     
           
ostream& operator<<( ostream& cout, const Quaternion m ){
         string s="";
        cout << std::fixed << std::setprecision(1) << m.a;
        if (m.b>=0) cout << '+';
         cout << std::fixed << std::setprecision(1)<<m.b<<"i";
        if (m.c>=0) cout<<"+";
         cout << std::fixed << std::setprecision(1)<<m.c<<"j";
        if (m.d>=0) cout<<"+";
         cout << std::fixed << std::setprecision(1)<<m.d<<"k";
        
         return cout;}