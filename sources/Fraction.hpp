#pragma once

#include <iostream>
#include <string>


using std::string, std::cout, std::ostream, std::endl, std::istream;

namespace ariel {

class Fraction {
private:
	int numerator, denominator;

public:
	// Constractors
	Fraction();
	Fraction(int num, int den);
	Fraction(float flo);
	
	int getNumerator() const;
    	int getDenominator() const;
    	
	// GCD
	int gcd(int num1, int num2);
	
	// Reduce form
	void reduce();
	
	// prefix increment:
    	Fraction& operator++();
    	
    	// postfix increment:
    	Fraction operator++(int dummy_flag_for_postfix_increment);
    	
    	// prefix decrement:
    	Fraction& operator--();
    	
    	// postfix decrement:
    	Fraction operator--(int dummy_flag_for_postfix_increment);
    	
	// For Fraction with Fraction
	Fraction operator+(const Fraction& other) const;
	Fraction operator-(const Fraction& other) const;
	Fraction operator*(const Fraction& other) const;
	Fraction operator/(const Fraction& other) const;
	bool operator==(const Fraction& other) const;
	bool operator<(const Fraction& other) const;
	bool operator>(const Fraction& other) const;
	bool operator>=(const Fraction& other) const;
	bool operator<=(const Fraction& other) const;
	
	
    	
    	// For Fraction with float
    	friend Fraction operator+ (const Fraction& fra, float flo);
    	friend Fraction operator- (const Fraction& fra, float flo);
    	friend Fraction operator* (const Fraction& fra, float flo);
    	friend Fraction operator/ (const Fraction& fra, float flo);
    	friend bool operator== (const Fraction& fra, float flo);
    	friend bool operator< (const Fraction& fra, float flo);
    	friend bool operator> (const Fraction& fra, float flo);
    	friend bool operator<= (const Fraction& fra, float flo);
    	friend bool operator>= (const Fraction& fra, float flo);
    	
    	// For float with Fraction
    	friend Fraction operator+ (float flo, const Fraction& fra);
    	friend Fraction operator- (float flo, const Fraction& fra);
    	friend Fraction operator* (float flo, const Fraction& fra);
    	friend Fraction operator/ (float flo, const Fraction& fra);
    	friend bool operator== (float flo, const Fraction& fra);
    	friend bool operator< (float flo, const Fraction& fra);
    	friend bool operator> (float flo, const Fraction& fra);
    	friend bool operator<= (float flo, const Fraction& fra);
    	friend bool operator>= (float flo, const Fraction& fra);
    	
    	// Print and write
    	friend ostream& operator<< (ostream& output, const Fraction& fra);
    	friend istream& operator>> (istream& input , Fraction& fra);
    	
    	
};
}

