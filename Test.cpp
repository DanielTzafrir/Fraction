#include <sstream>
#include "doctest.h"
#include "sources/Fraction.hpp"
#include <limits>

using namespace std;
using namespace ariel;

TEST_CASE("Fraction operations") {
    	// Create Fractions for testing
    	Fraction frac1(2, 3);
    	Fraction frac2(1, 4);
    	Fraction frac3(6, 8);

    	// Check addition
    	CHECK_NOTHROW(frac1 + frac2);
    	CHECK_EQ(frac1 + frac2, Fraction(11, 12));
    	CHECK_NE(frac1 + frac2, Fraction(2, 3));

    	// Check subtraction
    	CHECK_NOTHROW(frac1 - frac2);
    	CHECK_EQ(frac1 - frac2, Fraction(5, 12));
    	CHECK_NE(frac1 - frac2, Fraction(2, 3));

    	// Check multiplication
    	CHECK_NOTHROW(frac1 * frac2);
    	CHECK_EQ(frac1 * frac2, Fraction(1, 6));
    	CHECK_NE(frac1 * frac2, Fraction(2, 3));

    	// Check division
    	CHECK_NOTHROW(frac1 / frac2);
    	CHECK_EQ(frac1 / frac2, Fraction(8, 3));
    	CHECK_NE(frac1 / frac2, Fraction(2, 3));
}

TEST_CASE("Fraction operations") {
    	// Create Fractions for testing
    	Fraction frac1(2, 3);
    	Fraction frac2(1, 4);
    	Fraction frac3(6, 8);

    	// Check prefix increment
    	CHECK_NOTHROW(++frac1);
    	CHECK_EQ(frac1, Fraction(5, 3));

    	// Check postfix increment
    	CHECK_NOTHROW(frac2++);
    	CHECK_EQ(frac2, Fraction(5, 4));

    	// Check prefix decrement
    	CHECK_NOTHROW(--frac3);
    	CHECK_EQ(frac3, Fraction(-1, 4));

    	// Check postfix decrement
    	CHECK_NOTHROW(frac1--);
    	CHECK_EQ(frac1, Fraction(2, 3));

    	// Check comparison operators
    	CHECK(frac1 < frac2);
    	CHECK(frac2 > frac3);
    	CHECK(frac3 <= frac2);
    	CHECK(frac2 >= frac1);
}
