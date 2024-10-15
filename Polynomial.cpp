#include "Polynomial.h"
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

Polynomial::Polynomial() {}

Polynomial::Polynomial(const vector<double>& coefficients) : coeffs(coefficients) {}

Polynomial::Polynomial(const Polynomial& other) : coeffs(other.coeffs) {}

Polynomial::~Polynomial() {}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        coeffs = other.coeffs;
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    vector<double> result_coeffs(max(coeffs.size(), other.coeffs.size()), 0.0);
    for (size_t i = 0; i < coeffs.size(); ++i) result_coeffs[i] += coeffs[i];
    for (size_t i = 0; i < other.coeffs.size(); ++i) result_coeffs[i] += other.coeffs[i];
    return Polynomial(result_coeffs);
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    vector<double> result_coeffs(max(coeffs.size(), other.coeffs.size()), 0.0);
    for (size_t i = 0; i < coeffs.size(); ++i) result_coeffs[i] += coeffs[i];
    for (size_t i = 0; i < other.coeffs.size(); ++i) result_coeffs[i] -= other.coeffs[i];
    return Polynomial(result_coeffs);
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    vector<double> result_coeffs(coeffs.size() + other.coeffs.size() - 1, 0.0);
    for (size_t i = 0; i < coeffs.size(); ++i)
        for (size_t j = 0; j < other.coeffs.size(); ++j)
            result_coeffs[i + j] += coeffs[i] * other.coeffs[j];
    return Polynomial(result_coeffs);
}

bool Polynomial::operator==(const Polynomial& other) const {
    return coeffs == other.coeffs;
}

ostream& operator<<(ostream& out, const Polynomial& poly) {
    for (int i = poly.coeffs.size() - 1; i >= 0; --i) {
        out << poly.coeffs[i];
        if (i > 0) out << "x^" << i << " + ";
    }
    return out;
}

int Polynomial::degree() const {
    return coeffs.size() - 1;
}

double Polynomial::evaluate(double x) const {
    double result = 0;
    for (int i = coeffs.size() - 1; i >= 0; --i) {
        result = result * x + coeffs[i];
    }
    return result;
}

Polynomial Polynomial::derivative() const {
    vector<double> derivative_coeffs(coeffs.size() - 1, 0.0);
    for (int i = 1; i < coeffs.size(); ++i) {
        derivative_coeffs[i - 1] = coeffs[i] * i;
    }
    return Polynomial(derivative_coeffs);
}

Polynomial Polynomial::integral() const {
    vector<double> integral_coeffs(coeffs.size() + 1, 0.0);
    for (int i = 0; i < coeffs.size(); ++i) {
        integral_coeffs[i + 1] = coeffs[i] / (i + 1);
    }
    return Polynomial(integral_coeffs);
}

double Polynomial::integral(double x1, double x2) const {
    Polynomial integral_poly = this->integral();
    return integral_poly.evaluate(x2) - integral_poly.evaluate(x1);
}

Polynomial Polynomial::compose(const Polynomial& q) const {
    Polynomial result;
    for (int i = coeffs.size() - 1; i >= 0; --i) {
        result = result * q + Polynomial(vector<double>{coeffs[i]});
    }
    return result;
}

double Polynomial::getRoot(double guess, double tolerance, int maxIter) {
    double x = guess;
    for (int i = 0; i < maxIter; ++i) {
        double fx = evaluate(x);
        if (abs(fx) < tolerance) return x;
        double dfx = derivative().evaluate(x);
        if (dfx == 0) break;
        x = x - fx / dfx;
    }
    return x;
}

void Polynomial::setCoefficients(const vector<double>& coefficients) {
    coeffs = coefficients;
}

double Polynomial::getCoefficient(int degree) const {
    if (degree < coeffs.size()) {
        return coeffs[degree];
    } else {
        return 0.0;
    }
}
