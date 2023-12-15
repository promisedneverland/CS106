#ifndef RATIONAL_H__
#define RATIONAL_H__

#include<string>
#include<iostream>

class Rational {
public:
    Rational();
    Rational(int x, int y);
    Rational(int n);
    std::string toString();

    Rational operator+(Rational rhs);
    Rational operator-(Rational rhs);
    friend Rational operator*(Rational lhs, Rational rhs);
    friend Rational operator/(Rational lhs, Rational rhs);
private:
    int num, den;
};

Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);
std::ostream& operator<<(std::ostream& os, Rational r);

#endif