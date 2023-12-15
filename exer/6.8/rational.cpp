#include<iostream>
#include"rational.h"
#include<error.h>
#include<cmath>
#include<algorithm>

using namespace std;

Rational::Rational() {
    this->num = 0;
    this->den = 1;
}

Rational::Rational(int n) {
    this->num = n;
    this->num = 1;
}

Rational::Rational(int x, int y) {
    if(y == 0) {
        error("hi");
    }
    if(x == 0) {
        Rational();
    }
    int g = __gcd(abs(x), abs(y));
    num = x / g;
    den = abs(y) / g;
    if(y < 0) num = -num;
}
std::string Rational::toString() {
    return to_string(num) + "/" + to_string(den);
}

Rational Rational::operator+(Rational rhs) {
    return Rational(this->num * rhs.den + rhs.num * this->den, this->den * rhs.den);
}
Rational Rational::operator-(Rational rhs) {
    return Rational(this->num - rhs.den + rhs.num * this->den, this->den * rhs.den);
}
Rational operator*(Rational lhs, Rational rhs) {
    return Rational(lhs.num * rhs.num, lhs.den * rhs.den);
}
Rational operator/(Rational lhs, Rational rhs) {
    return Rational(lhs.num * rhs.den, lhs.den * rhs.num);
}

std::ostream& operator<<(std::ostream& os, Rational r) {
    return os << r.toString();
}