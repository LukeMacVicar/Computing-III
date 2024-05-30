/***********************************************
Author: Luke MacVicar
Date: 2/19/24
Purpose: Make a class for rational numbers. Overwrite the operators to preform math.
***********************************************/
#include <iostream>
using namespace std;

class Rational {
public:
    //TODO: constructors
    Rational();//default constructor
    Rational(int wholeNumber);
    Rational(int num, int denom);
    
    //accessor functions (getters)
    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    //mutator functions (setters)
    Rational operator+(const Rational& other) const {
           int num = numerator * other.denominator + other.numerator * denominator;
           int denom = denominator * other.denominator;
           return Rational(num, denom);
       }

    Rational operator-(const Rational& other) const {
            int num = numerator * other.denominator - other.numerator * denominator;
            int denom = denominator * other.denominator;
            return Rational(num, denom);
        }

    Rational operator*(const Rational& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Rational(num, denom);
    }

    Rational operator/(const Rational& other) const {
        if (other.numerator == 0) {
            cerr << "Error: Division by zero." << endl;
            exit(1);
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Rational(num, denom);
    }
    
    bool operator==(const Rational& other) const {
        
        return (numerator == other.numerator && denominator == other.denominator);
    }
    
    bool operator<=(const Rational& other) const {
        return (numerator <= other.numerator && denominator <= other.denominator);
    }
    
    bool operator>=(const Rational& other) const {
        return (numerator >= other.numerator && denominator >= other.denominator);
    }
    
    bool operator<(const Rational& other) const {
        return (numerator < other.numerator && denominator < other.denominator);
    }
    
    bool operator>(const Rational& other) const {
        return (numerator > other.numerator && denominator > other.denominator);
    }
    
    friend ostream& operator<<(ostream& os, const Rational& rational);
    friend istream& operator>>(istream& is, Rational& rational);
    
private:
    int denominator;
    int numerator;
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void simplify(void) {
        int common = gcd(abs(numerator), denominator);
        numerator /= common;
        denominator /= common;
    }
};

int main(int argc, char* argv[]) {
    Rational num;
    Rational num2;
    Rational r;
    Rational r1(8, 4);
    Rational r2(3, 4);
    
    bool equals = r1 == r2;
    bool less_than = r1 < r2;
    bool less_than_equal = r1 <= r2;
    bool greater_than = r1 > r2;
    bool greater_than_equal = r1 >= r2;
    Rational sum = r1 + r2;
    Rational difference = r1 - r2;
    Rational product = r1 * r2;
    Rational quotient = r1 / r2;
    
    cout << "r = " << r << endl;
    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << r2 << endl;
    cout << "Equals = " << equals << endl;
    cout << "Less than = " << less_than << endl;
    cout << "Less than or equal to = " << less_than_equal << endl;
    cout << "Greater than = " << greater_than << endl;
    cout << "Greater than or equal to = " << greater_than_equal << endl;
    cout << "Sum = " << sum << endl;
    cout << "Difference = " << difference << endl;
    cout << "Product = " << product << endl;
    cout << "Quotient = " << quotient << endl;
    
    return 0;
}

//TODO: constructors
Rational::Rational(int wholeNumber) {
    denominator = 1;
    numerator = wholeNumber;
    simplify();
}

//default constructor
Rational::Rational() {
    denominator = 1;
    numerator = 0;
    simplify();
}

Rational::Rational(int num, int denom) {
    denominator = denom;
    numerator = num;
    simplify();
}

//mutator functions
ostream& operator<<(ostream& os, const Rational& rational) {
        os << rational.numerator << "/" << rational.denominator;
        return os;
    }

istream& operator>>(istream& is, Rational& rational) {
    char slash;
    is >> rational.numerator >> slash >> rational.denominator;
    if (slash != '/') {
        is.setstate(ios_base::failbit);
    }
    return is;
}

