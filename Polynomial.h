#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
    vector<double> coeffs;

public:
    Polynomial();
    Polynomial(const vector<double>& coefficients);
    Polynomial(const Polynomial& other);

    ~Polynomial();

    Polynomial& operator=(const Polynomial& other);

    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator-(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;

    bool operator==(const Polynomial& other) const;

    friend ostream& operator<<(ostream& out, const Polynomial& poly);

    int degree() const;
    double evaluate(double x) const;
    Polynomial compose(const Polynomial& q) const;
    Polynomial derivative() const;
    Polynomial integral() const;
    double integral(double x1, double x2) const;
    double getRoot(double guess = 1, double tolerance = 1e-6, int maxIter = 100);

    void setCoefficients(const vector<double>& coefficients);
    double getCoefficient(int degree) const;
};

#endif // POLYNOMIAL_H

