#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H
#include <iostream>
using namespace std;

class RationalNumber {
private:
    bool undefined;
    int p;
    int q;
    void reduce();
public:
    RationalNumber();
    RationalNumber(int x, int y);
    void setNumber(int x, int y);
    friend int isPositive( const RationalNumber & a);
    friend ostream& operator<<(ostream & cout, const RationalNumber b);
    friend RationalNumber operator+(RationalNumber a, RationalNumber b );
    friend RationalNumber operator-(RationalNumber a, RationalNumber b );
    friend RationalNumber operator*(RationalNumber a, RationalNumber b );
    friend RationalNumber operator/(RationalNumber a, RationalNumber b );
    friend bool operator==(RationalNumber a,RationalNumber b );
    friend bool operator>(RationalNumber a, RationalNumber b );
};

#endif
