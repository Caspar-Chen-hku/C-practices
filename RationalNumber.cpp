#include "RationalNumber.h"
#include <cstdlib>

// Calculate the GCD of two numbers
int GCD(int a, int b) {
        int a1=abs(a);
        int b1=abs(b);
    for (int i=(a1>b1?b1:a1); i>=1; i++){
        if (a1%i==0&&b1%i==0) return i;
    }
}

// Convert p/q to its reduced form
void RationalNumber::reduce() {
    if(q == 0){
        undefined = true;
        return;
    }
    else if(p == 0)
        q = 1;
    else {
        bool negative = false;
        if(p < 0) {
            negative = !negative;
            p *= -1;
        }
        if(q < 0) {
            negative = !negative;
            q *= -1;
        }
        int factor = GCD(p, q);
        p /= factor;
        q /= factor;
        if(negative)
            p *= -1;
    }
}

RationalNumber::RationalNumber() {
    RationalNumber::setNumber(0, 1);
}

RationalNumber::RationalNumber(int x, int y) {
    RationalNumber::setNumber(x, y);
}

void RationalNumber::setNumber(int x, int y) {
    if (y==0){
         undefined = true;
         return;
    }
    undefined = false;
    p = x;
    q = y;
    reduce();
}

ostream& operator<<(ostream & cout, RationalNumber b){
                if (b.undefined||b.q==0){
                        cout << "undefined";
                        return cout;}
               b.reduce();
               cout << b.p;
               if (b.q>0) cout << "+";
                cout << b.q;
               return cout;}

RationalNumber operator+(RationalNumber a, RationalNumber b ){
               RationalNumber c;
               if (a.undefined || b.undefined || a.q==0 || b.q==0){
                               c.undefined=true;
                               return c;}
               c.setNumber(a.p*b.q+a.q*b.p,abs(a.q*b.q));
               c.undefined=false;
               c.reduce();
               return c;}

RationalNumber operator-(RationalNumber a, RationalNumber b ){
               RationalNumber c;
               if (a.undefined || b.undefined){
                               c.undefined=true;
                               return c;}
               c.setNumber(a.p*b.q-a.q*b.p,abs(a.q*b.q));
               c.undefined = false;
               c.reduce();
               return c;}

RationalNumber operator*(RationalNumber a, RationalNumber b ){
                RationalNumber c;
               if (a.undefined || b.undefined){
                               c.undefined=true;
                               return c;}
               c.setNumber(a.p*b.p,a.q*b.q);
               c.undefined = false;
               c.reduce();
               return c;}

RationalNumber operator/(RationalNumber a, RationalNumber b ){
               RationalNumber c;
               if (a.undefined || b.undefined){
                               c.undefined=true;
                               return c;}
               c.setNumber(a.p*b.q,a.q*b.p);
               c.undefined = false;
               c.reduce();
               return c;}

bool operator==(RationalNumber a, RationalNumber b ){
    a.reduce();
    b.reduce();
     if (a.undefined&&b.undefined) return true;
     else if ((a.undefined&&!b.undefined) || (!a.undefined&&b.undefined)) return false;
     else if (a.p==b.p&&a.q==b.q) return true;
     else return false;}

bool operator>( RationalNumber a, RationalNumber b ){
      if (a.undefined&&b.undefined) return false;
     else if (a.undefined&&!b.undefined) return true;
     else if (!a.undefined&&b.undefined) return false;
     else { RationalNumber c(0,0);
            return (a-b)>c;}
}