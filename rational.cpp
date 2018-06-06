#include "rational.h"
#include <stdexcept>
#include <algorithm>

/**
* Constructor that sets numerator and denominator of Rational object. Default
* values for numerator and denominator are set as 0 and 1, respectively. If the
* denominator is 0, throws exception. If the denominator is negative, inverts
* sign of numerator and denominator so that the denominator is positive.
*/
Rational::Rational(int numerator, int denominator) {

    if (denominator == 0) {
        throw invalid_argument("Denominator cannot be 0.");
    }

    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }

    this->numerator = numerator;
    this->denominator = denominator;
}

/** Returns the numerator of a Rational object. */
int Rational::num() const {
    return numerator;
}

/** Returns the denominator of a Rational object. */
int Rational::denom() const {
    return denominator;
}

/**
* Returns Rational object containing reciprocal of the number. Leaves the
* number itself unchanged. Throws exception if reciprocal has denominator of 0.
*/
Rational Rational::reciprocal() const {
    return Rational{denominator, numerator};
}

/**
* Reduces the rational number that it is called on so that the gcd of the
* numerator and denominator is 1. If the numerator is 0 and the denominator is
* not 1, modifies number to 0/1.
*/
void Rational::reduce() {
    if ((numerator == 0) && (denominator != 1)) {
        denominator = 1;
    }
    else {
        int gcd = __gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }
}

/**
* Supports addition of Rationals and assignment in one step. Reduces the result.
*/
Rational & Rational::operator+=(const Rational &v) {
    Rational x = Rational{numerator * v.denom() + v.num() * denominator,
        denominator * v.denom()};
    x.reduce();
    numerator = x.num();
    denominator = x.denom();
    return *this;
}

/**
* Supports subtraction of Rationals and assignment in one step. Reduces the
* result.
*/
Rational & Rational::operator-=(const Rational &v) {
    Rational x = Rational{numerator * v.denom() + v.num() * -1 *
        denominator, denominator * v.denom()};
    x.reduce();
    numerator = x.num();
    denominator = x.denom();
    return *this;
}

/**
* Supports multiplication of Rationals and assignment in one step. Reduces the
* result.
*/
Rational & Rational::operator*=(const Rational &v) {
    Rational x = Rational{numerator * v.num(), denominator * v.denom()};
    x.reduce();
    numerator = x.num();
    denominator = x.denom();
    return *this;
}

/**
* Supports division of Rationals and assignment in one step. Reduces the result.
* Throws exception if Rational being divided by is zero.
*/
Rational & Rational::operator/=(const Rational &v) {
    if (v.num() == 0) {
        throw invalid_argument("Cannot divide by zero.");
    }

    Rational x = Rational{numerator * v.denom(), denominator * v.num()};
    x.reduce();
    numerator = x.num();
    denominator = x.denom();

    return *this;
}

/**
* Adds two Rational objects.
* @param r first Rational number to be added.
* @param v second Rational number to be added.
* @return sum of two arguments as a Rational object.
*/
Rational operator+(const Rational &r, const Rational &v) {
    return Rational{r.num() * v.denom() + v.num() * r.denom(),
        r.denom() * v.denom()};
}

/**
* Multiplies one Rational object by another.
* @param r first Rational number to be multiplied.
* @param v second Rational number to be multiplied.
* @return product of two arguments as a Rational object.
*/
Rational operator*(const Rational &r, const Rational &v) {
    Rational x = Rational{r.num() * v.num(), r.denom() * v.denom()};
    x.reduce();
    return x;
}

/**
* Subtracts one Rational object from another.
* @param r Rational number to be subtracted from.
* @param v Rational number to be subtracted.
* @return difference between two arguments as a Rational object.
*/
Rational operator-(const Rational &r, const Rational &v) {
    return r + v * -1;
}

/**
* Divides one Rational object by another.
* @param r Rational number to be divided.
* @param v Rational number to be divided by.
* @return quotient of two arguments as a Rational object.
*/
Rational operator/(const Rational &r, const Rational &v) {
    return r * v.reciprocal();
}

/**
* Supports stream-output of Rational objects in the form numerator/denominator.
* If the denominator is 1, outputs numerator only.
*/
ostream & operator<<(ostream &os, const Rational &r) {
    if (r.denom() == 1) {
        os << r.num();
        return os;
    }

    os << r.num() << "/" << r.denom();
    return os;
}
