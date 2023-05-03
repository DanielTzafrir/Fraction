#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    // Create Fractions using different constructors
    Fraction frac1; // Default constructor, initializes to 1/1
    Fraction frac2(3, 4); // Fraction with numerator = 3 and denominator = 4
    Fraction frac3(1.5); // Fraction created from float value 1.5

    // Perform arithmetic operations
    Fraction result1 = frac1 + frac2; // Addition
    Fraction result2 = frac2 - frac3; // Subtraction
    Fraction result3 = frac1 * frac3; // Multiplication
    Fraction result4 = frac2 / frac3; // Division

    // Use comparison operators
    bool isEqual = frac1 == frac2;
    bool isLessThan = frac1 < frac2;
    bool isGreaterThan = frac1 > frac2;
    bool isGreaterThanOrEqual = frac2 >= frac3;
    bool isLessThanOrEqual = frac3 <= frac1;

    // Output the results
    cout << "Result 1: " << result1 << endl;
    cout << "Result 2: " << result2 << endl;
    cout << "Result 3: " << result3 << endl;
    cout << "Result 4: " << result4 << endl;

    cout << "Is Equal? " << isEqual << endl;
    cout << "Is Less Than? " << isLessThan << endl;
    cout << "Is Greater Than? " << isGreaterThan << endl;
    cout << "Is Greater Than or Equal? " << isGreaterThanOrEqual << endl;
    cout << "Is Less Than or Equal? " << isLessThanOrEqual << endl;

    return 0;


}
