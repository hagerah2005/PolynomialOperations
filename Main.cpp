
#include <iostream>
#include "Polynomial.h"

int main() {
    // Creating 3 polynomials
    Polynomial p1({3, -4, 2});   // Represents 2x^2 - 4x + 3
    Polynomial p2({1, 5});       // Represents 5x + 1
    Polynomial p3({2, -1, 3});   // Represents 3x^2 - x + 2

    // Display the polynomials
    cout << "Polynomial p1: " << p1 << endl;
    cout << "Polynomial p2: " << p2 << endl;
    cout << "Polynomial p3: " << p3 << endl;

    // Perform and display operations
    Polynomial sum = p2 + p3;
    Polynomial difference = p1 - p2;
    Polynomial product = p1 * p3;

    cout << "\nOperations between polynomials:" << endl;
    cout << "p2 + p3: " << sum << endl;
    cout << "p1 - p2: " << difference << endl;
    cout << "p1 * p3: " << product << endl;

    // Check equality
    Polynomial p4({3, -4, 2});   // Same as p1
    cout << "\nEquality check:" << endl;
    cout << "p1 == p4: " << (p1 == p4 ? "True" : "False") << endl;
    cout << "p1 == p2: " << (p1 == p2 ? "True" : "False") << endl;

    // Degree of p1
    cout << "\nDegree of polynomials:" << endl;
    cout << "Degree of p1: " << p1.degree() << endl;
    cout << "Degree of p2: " << p2.degree() << endl;
    cout << "Degree of p3: " << p3.degree() << endl;

    // Evaluate p1 at a certain value
    double x = 3.0;
    cout << "\np3 evaluated at x = " << x << ": " << p3.evaluate(x) << endl;

    // Derivative of p1
    cout << "\nDerivative of p1: " << p1.derivative() << endl;

    // Integral of p1
    cout << "\nIntegral of p2: " << p2.integral() << endl;

    // Definite integral of p1 from 0 to 2
    cout << "Definite integral of p1 from 3 to 8: " << p1.integral(3, 8) << endl;

    // Composition of p1 with p2
    cout << "\nComposition of p1 with p3: " << p1.compose(p3) << endl;

    // Find root of p1
    cout << "\nRoot of p1 (starting guess = 1): " << p1.getRoot(1) << endl;

    // Get and set coefficients
    cout << "\nCoefficient of x^2 in p1: " << p1.getCoefficient(2) << endl;
    p1.setCoefficients({4, 1, -5});
    cout << "New p1: " << p1 << endl;

    // Print new coefficients after modification
    cout << "Coefficient of x^2 in new p1: " << p1.getCoefficient(2) << endl;

    return 0;
}

