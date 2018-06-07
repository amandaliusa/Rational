#include "rational.h"
#include <stdexcept>
#include <algorithm>

/**
* Constructor that sets numerator and denominator of Rational object. Default
* values for numerator and denominator are set as 0 and 1, respectively. If the
* denominator is 0, throws exception. If the denominator is negative, inverts
* sign of numerator and denominator so that the denominator is positive.
* @param numerator of rational number as integer
* @param denominator of rational number as integer
* @return Rational object with specified numerator and denominator
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

/**
* Returns the numerator of a Rational object.
* @param none
* @return numerator of Rational object that the function is called on as an
* integer
*/
int Rational::num() const {
    return numerator;
}

/**
* Returns the denominator of a Rational object.
* @param none
* @return denominator of Rational object that the function is called on as an
* integer
*/
int Rational::denom() const {
    return denominator;
}

/**
* Takes the reciprocal of a Rational object. Leaves the number itself unchanged.
* Throws exception if reciprocal has denominator of 0.
* @param none
* @return reciprocal of Rational object that the function is called on as a
* Rational object
*/
Rational Rational::reciprocal() const {
    return Rational{denominator, numerator};
}

/**
* Reduces a rational number so that the gcd of the numerator and denominator is
* 1. Mutates the Rational object that the function is called on. If the
* numerator is 0 and the denominator is not 1, modifies number to 0/1.
* @param none
* @return none
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
* Supports addition of Rationals and assignment in one step. Modifies the
* Rational object the function is called on. Reduces the result.
* @param a Rational object v to be added to the Rational object the function is
* called on
* @return reference to modified Rational object that the function is called on
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
* Supports subtraction of Rationals and assignment in one step. Modifies the
* Rational object the function is called on. Reduces the result.
* @param a Rational object v to be subtracted from the Rational object the
* function is called on
* @return reference to modified Rational object that the function is called on
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
* Supports multiplication of Rationals and assignment in one step. Modifies the
* Rational object the function is called on. Reduces the result.
* @param a Rational object v to be multiplied by the Rational object the
* function is called on
* @return reference to modified Rational object that the function is called on
*/
Rational & Rational::operator*=(const Rational &v) {
    Rational x = Rational{numerator * v.num(), denominator * v.denom()};
    x.reduce();
    numerator = x.num();
    denominator = x.denom();
    return *this;
}

/**
* Supports division of Rationals and assignment in one step. Modifies the
* Rational object the function is called on. Reduces the result.
* @param a Rational object v that the Rational object the function is called on
* is to be divided by
* @return reference to modified Rational object that the function is called on
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
    return Rational{r} += v;
}

/**
* Subtracts one Rational object from another.
* @param r Rational number to be subtracted from.
* @param v Rational number to be subtracted.
* @return difference between two arguments as a Rational object.
*/
Rational operator-(const Rational &r, const Rational &v) {
    return Rational{r} -= v;
}

/**
* Multiplies one Rational object by another.
* @param r first Rational number to be multiplied.
* @param v second Rational number to be multiplied.
* @return product of two arguments as a Rational object.
*/
Rational operator*(const Rational &r, const Rational &v) {
    return Rational{r} *= v;
}

/**
* Divides one Rational object by another.
* @param r Rational number to be divided.
* @param v Rational number to be divided by.
* @return quotient of two arguments as a Rational object.
*/
Rational operator/(const Rational &r, const Rational &v) {
    return Rational{r} /= v;
}

/**
* Supports stream-output of Rational objects in the form numerator/denominator.
* If the denominator is 1, outputs numerator only.
* @param ostream object to contain output
* @param Rational object to be outputted
* @return ostream object containing output
*/
ostream & operator<<(ostream &os, const Rational &r) {
    if (r.denom() == 1) {
        os << r.num();
        return os;
    }

    os << r.num() << "/" << r.denom();
    return os;
}
