/*
    FileName: Polynomial.hpp
    Name: Maddhav Suneja
    Purpose: Header file of a Polynomial Class
*/

#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <iostream>
#include <vector>

class Polynomial {
    struct Term;

    friend void printTerm(Polynomial::Term* tptr, int degree);
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& pol);
    friend bool operator==(const Polynomial& pol1, const Polynomial& pol2);

public:
    Polynomial();
    Polynomial(const std::vector<int>& coefficients);
    Polynomial(const Polynomial& pol);

    Polynomial& operator+=(const Polynomial& pol);
    Polynomial& operator=(const Polynomial& pol);

    void addLowestTerm(int data);
    Polynomial::Term* addHighestTerm(int data, Term* curr_high);
    void clearLeadingZeroes();
    void clearPolynomial(Term* curr_term);

    int evaluate(int val) const;

    ~Polynomial();

private:
    struct Term {
        Term(int coefficient = 0, Term* next = nullptr);

        int coefficient;
        Term* next;
    };

    Term* headptr;
    int degree;
};

Polynomial operator+(const Polynomial& pol1, const Polynomial& pol2);
bool operator!=(const Polynomial& pol1, const Polynomial& pol2);

#endif // POLYNOMIAL_HPP
