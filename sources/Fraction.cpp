#include <cmath>
#include <cctype> // for isspace
#include <stdexcept> // for std::invalid_argument
#include <limits.h>
#include "Fraction.hpp"

using namespace std;

namespace ariel {

Fraction::Fraction() : numerator(1), denominator(1) { }

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
	if(denom == 0) {  
		throw invalid_argument("Invalid fraction: denominator cannot be zero.");
	}

	reduce();
}

Fraction::Fraction(float value) {
    	int precision = 1000; // Adjust the precision based on your desired number of decimal places
    	float roundedValue = std::round(value * precision) / precision;
    	numerator = static_cast<int>(roundedValue * precision);
    	denominator = precision;
    	reduce();
}

int Fraction::getNumerator() const {
    	return numerator;
}

int Fraction::getDenominator() const {
        return denominator;
}
int Fraction::gcd(int a, int b) {
    	while (b != 0) {
        	int temp = b;
        	b = a % b;
        	a = temp;
    	}
   	return a;
}

void Fraction::reduce() {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
        
        // Preserve the sign of the fraction
    	if (denominator < 0) {
        	numerator *= -1;
        	denominator *= -1;
    	}
}


Fraction& Fraction::operator++() {
        numerator = numerator + denominator;
        return *this;
}
    	
Fraction Fraction::operator++(int dummy_flag_for_postfix_increment) {
        Fraction copy = *this;
        numerator = numerator + denominator;
        return copy;
}

Fraction& Fraction::operator--() {
        numerator = numerator - denominator;
        return *this;
}	

Fraction Fraction::operator--(int dummy_flag_for_postfix_increment) {
        Fraction copy = *this;
        numerator = numerator - denominator;
        return copy;
}
// '+'
Fraction Fraction::operator+(const Fraction& other) const {
	// Check for potential arithmetic overflow
    	if ((other.numerator > 0 && numerator > (INT_MAX - other.numerator)) || (other.numerator < 0 && numerator < (INT_MIN - other.numerator))) {
    		throw std::overflow_error("Arithmetic overflow occurred during adding.");
	}

    	if ((other.denominator > 0 && denominator > (INT_MAX - other.denominator)) || (other.denominator < 0 && denominator < (INT_MIN - other.denominator))) {
        	throw std::overflow_error("Arithmetic overflow occurred during adding.");
    	}
    	
	int newDenominator = denominator * other.denominator;
        int newNumerator = (numerator * other.denominator) + (other.numerator * denominator);
        return Fraction(newNumerator, newDenominator);
}

Fraction operator+(const Fraction& fraction, float value) {
        return fraction + Fraction(value);
}

Fraction operator+(float value, const Fraction& fraction) {
        return Fraction(value) + fraction;
}

// '-'
Fraction Fraction::operator-(const Fraction& other) const {
	// Check for potential arithmetic overflow
	if ((other.numerator < 0 && numerator > (INT_MAX + other.numerator)) || (other.numerator > 0 && numerator < (INT_MIN + other.numerator))) {
    		throw std::overflow_error("Arithmetic overflow occurred during multiplication.");
	}

    	if ((other.denominator < 0 && denominator > (INT_MAX + other.denominator)) || (other.denominator > 0 && denominator < (INT_MIN + other.denominator))) {
        	throw std::overflow_error("Arithmetic overflow occurred during multiplication.");
    	}
    	
	int newDenominator = denominator * other.denominator;
        int newNumerator = (numerator * other.denominator) - (other.numerator * denominator);
        return Fraction(newNumerator, newDenominator);
}

Fraction operator-(const Fraction& fraction, float value) { 
        return fraction - Fraction(value);
}

Fraction operator-(float value, const Fraction& fraction) {
        return Fraction(value) - fraction;
}

// '*'
Fraction Fraction::operator*(const Fraction& other) const {
	// Check for potential arithmetic overflow
    	if ((other.numerator > 0 && numerator > INT_MAX / other.numerator) || (other.numerator < 0 && numerator < (INT_MAX / other.numerator))) {
    		throw std::overflow_error("Arithmetic overflow occurred during multiplication.");
	}

    	if ((other.denominator > 0 && denominator > INT_MAX / other.denominator) || (other.denominator < 0 && denominator < (INT_MAX / other.denominator))) {
        	throw std::overflow_error("Arithmetic overflow occurred during multiplication.");
    	}
    	
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
}

Fraction operator*(const Fraction& fraction, float value) {
        return fraction * Fraction(value);
}

Fraction operator*(float value, const Fraction& fraction) {
        return Fraction(value) * fraction;
}

// '/'
Fraction Fraction::operator/(const Fraction& other) const {
	// Check for potential arithmetic overflow
    	if ((other.denominator > 0 && numerator > INT_MAX / other.denominator) || (other.denominator < 0 && numerator < (INT_MAX / other.denominator))) {
    		throw std::overflow_error("Arithmetic overflow occurred during division.");
	}

    	if ((other.numerator > 0 && denominator > INT_MAX / other.numerator) || (other.numerator < 0 && denominator < (INT_MAX / other.numerator))) {
        	throw std::overflow_error("Arithmetic overflow occurred during division.");
    	}
    	
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        if(newDenominator == 0) {
        	throw runtime_error("Invalid fraction: denominator cannot be zero.");
        }
        return Fraction(newNumerator, newDenominator);
}

Fraction operator/(const Fraction& fraction, float value) {
        return fraction / Fraction(value);
}

Fraction operator/(float value, const Fraction& fraction) {
        return Fraction(value) / fraction;
}

// '=='
bool Fraction::operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
}

bool operator==(const Fraction& fr, float fl) {
    	Fraction temp(fl);
    	return fr == temp;
}

bool operator==(float fl, const Fraction& fr) {
    	Fraction temp(fl);
    	return temp == fr;
}

// '<'
bool Fraction::operator<(const Fraction& other) const {
    	int crossProduct = numerator * other.denominator;
    	int otherCrossProduct = other.numerator * denominator;

    	return crossProduct < otherCrossProduct;
}

bool operator<(const Fraction& fr, float fl) {
    	Fraction temp(fl);
    	return fr < temp;
}

bool operator<(float fl, const Fraction& fr) {
    	Fraction temp(fl);
    	return temp < fr;
}

// '>'
bool Fraction::operator>(const Fraction& other) const {
    	int crossProduct = numerator * other.denominator;
    	int otherCrossProduct = other.numerator * denominator;

    	return crossProduct > otherCrossProduct;
}

bool operator>(const Fraction& fr, float fl) {
    	Fraction temp(fl);
    	return fr > temp;
}

bool operator>(float fl, const Fraction& fr) {
    	Fraction temp(fl);
    	return temp > fr;
}

// '<='
bool Fraction::operator<=(const Fraction& other) const {
    	int crossProduct = numerator * other.denominator;
    	int otherCrossProduct = other.numerator * denominator;

    	return crossProduct <= otherCrossProduct;
}

bool operator<=(const Fraction& fr, float fl) {
    	Fraction temp(fl);
    	return fr <= temp;
}

bool operator<=(float fl, const Fraction& fr) {
    	Fraction temp(fl);
    	return temp <= fr;
}

// '>='
bool Fraction::operator>=(const Fraction& other) const {
    	int crossProduct = numerator * other.denominator;
    	int otherCrossProduct = other.numerator * denominator;

    	return crossProduct >= otherCrossProduct;
}

bool operator>=(const Fraction& fr, float fl) {
    	Fraction temp(fl);
    	return fr >= temp;
}

bool operator>=(float fl, const Fraction& fr) {
    	Fraction temp(fl);
    	return temp >= fr;
}

// Print and input
ostream& operator<<(ostream& output, const Fraction& f) {
    	output << f.numerator << "/" << f.denominator;
    	return output;
}

istream& operator>>(istream& input, Fraction& f) {
    	char slash;
    	char delimiter;
    	
    	// check if there is '.'
    	if(input.peek() == '.') { 
    		throw runtime_error("Invalid input: No Dots are allowed.");
    	}
    	
    	input >> f.numerator;
	
	// check if there is '.'
    	if(input.peek() == '.') { 
    		throw runtime_error("Invalid input: No Dots are allowed.");
    	}
    	
    	// Check if the next character is a delimiter (space or comma)
    	if (input.peek() == ',' || input.peek() == ' ') {
    		delimiter = input.get(); // consume the delimiter
    	} else {
        	// If the next character is not a delimiter, assume it's the slash character
        	input >> slash;
        	delimiter = '/';
    	}
	
	// check if there is '.'
    	if(input.peek() == '.') { 
    		throw runtime_error("Invalid input: No Dots are allowed.");
    	}
    	
    	// Check if there is only one number provided as input
    	if (input.peek() == EOF || isspace(input.peek())) {
        	throw runtime_error("Invalid input: Denominator is missing.");
    	}

    	// Read the denominator
    	input >> f.denominator;
	
	// check if there is '.'
    	if(input.peek() == '.') { 
    		throw runtime_error("Invalid input: No Dots are allowed.");
    	}
    	
    	// Check if the denominator is zero
    	if (f.denominator == 0) {
        	throw runtime_error("Invalid input: Denominator cannot be zero.");
    	}

    	// Handle whitespace characters after the denominator
    	while (isspace(input.peek())) {
        	input.ignore(); // ignore any additional whitespace characters
    	}

    	f.reduce();

    	return input;
}
}
