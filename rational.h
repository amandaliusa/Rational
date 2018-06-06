#include <string>
#include <iostream>

using namespace std;

/**
* Represents a rational number as an integer divided by a positive whole number.
*/
class Rational {

    /** Data member that stores value of the numerator. Can be any integer. */
    int numerator;
    
    /**
    * Data member that stores value of the denominator. Must be a positive
    * integer.
    */
    int denominator;

    public:

        /**
        * Constructor that takes a numerator and denominator, then stores them
        * into the UValue object. Default values for numerator and denominator
        * are set as 0 and 1, respectively.
        */
        Rational(int numerator = 0, int denominator = 1);

        /** Member function that returns the numerator. */
        int num() const;

        /** Member function that returns the denominator. */
        int denom() const;

        /**
        * Member function that returns a Rational object containing the
        * reciprocal of the number. Leaves the number itself unchanged.
        * Throws exception if reciprocal has denominator of 0.
        */
        Rational reciprocal() const;

        /**
        * Member function that reduces the rational number that it is called
        * on so that the gcd of the numerator and denominator is 1. If the
        * numerator is 0 and the denominator is not 1, modifies number to 0/1.
        */
        void reduce();

        /**
        * Member function that supports simultaneous addition and assignment.
        */
        Rational & operator+=(const Rational &v);

        /**
        * Member function that supports simultaneous subtraction and assignment.
        */
        Rational & operator-=(const Rational &v);

        /**
        * Member function that supports simultaneous multiplication and
        * assignment.
        */
        Rational & operator*=(const Rational &v);

        /**
        * Member function that supports simultaneous division and assignment.
        */
        Rational & operator/=(const Rational &v);

};

/** Supports addition of Rational objects. */
Rational operator+(const Rational &r, const Rational &v);

/** Supports subtraction of Rational objects. */
Rational operator-(const Rational &r, const Rational &v);

/** Supports multiplication of Rational objects. */
Rational operator*(const Rational &r, const Rational &v);

/** Supports division of Rational objects. */
Rational operator/(const Rational &r, const Rational &v);

/** Supports stream-output for Rational objects. */
ostream & operator<<(ostream &os, const Rational &r);
