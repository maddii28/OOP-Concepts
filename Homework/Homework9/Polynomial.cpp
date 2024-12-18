/*
    FileName: Polynomial.cpp
    Name: Maddhav Suneja
    Purpose: Implementation of a Polynomial Class
*/

#include "Polynomial.hpp"
using namespace std;

//Prints a polynomial term.
void printTerm(Polynomial::Term* tptr, int dgre) {
    if (tptr->next) {
        printTerm(tptr->next, dgre + 1);
        if (tptr->coefficient) cout << " + ";
    }

    if (tptr->coefficient) {
        if (tptr->coefficient == 1 && dgre > 0)
            cout << "x";
        else if (tptr->coefficient == -1 && dgre > 0)
            cout << "-x";
        else {
            cout << tptr->coefficient;
            if (dgre > 0) {
                cout << "x";
                if (dgre > 1) cout << "^" << dgre;
            }
        }
    } else if (!tptr->next) {
        cout << 0;
    }
}

//Overloads stream output for polynomials
ostream& operator<<(ostream& os, const Polynomial& pol) {
    printTerm(pol.headptr, 0);
    return os;
}

//Compares two polynomials for equality.
bool operator==(const Polynomial& pol1, const Polynomial& pol2) {
    if (pol1.degree != pol2.degree)
        return false;

    Polynomial::Term* lhs_curr = pol1.headptr;
    Polynomial::Term* rhs_curr = pol2.headptr;
    while (lhs_curr) {
        if (lhs_curr->coefficient != rhs_curr->coefficient) return false;
        lhs_curr = lhs_curr->next;
        rhs_curr = rhs_curr->next;
    }
    return true;
}

//Adds two polynomials.
Polynomial operator+(const Polynomial& pol1, const Polynomial& pol2) {
    Polynomial result(pol1);
    return result += pol2;
}

//Checks if two polynomials are unequal.
bool operator!=(const Polynomial& pol1, const Polynomial& pol2) {
    return !(pol1 == pol2);
}

//Default constructor for polynomials.
Polynomial::Polynomial() : headptr(new Term()), degree(0) {}

//Constructor from coefficient list.
Polynomial::Polynomial(const std::vector<int>& coefficients)
    : headptr(nullptr), degree(-1) {
    for (int coefficient : coefficients) addLowestTerm(coefficient);
    clearLeadingZeroes();
}

//Copy constructor for polynomials.
Polynomial::Polynomial(const Polynomial& pol)
    : headptr(nullptr), degree(0) {
    Term* curr_term = pol.headptr;
    Term* lhs_prior = nullptr;
    while (curr_term) {
        lhs_prior = addHighestTerm(curr_term->coefficient, lhs_prior);
        curr_term = curr_term->next;
    }
}

//Adds a polynomial to another.
Polynomial& Polynomial::operator+=(const Polynomial& pol) {
    Term* lhs_curr = headptr;
    Term* rhs_curr = pol.headptr;
    Term* lhs_prior;
    while (lhs_curr) {
        if (!rhs_curr) break;
        lhs_curr->coefficient += rhs_curr->coefficient;
        if (!lhs_curr->next) {
            lhs_prior = lhs_curr;
        }
        lhs_curr = lhs_curr->next;
        rhs_curr = rhs_curr->next;
    }
    while (rhs_curr) {
        lhs_prior = addHighestTerm(rhs_curr->coefficient, lhs_prior);
        rhs_curr = rhs_curr->next;
    }
    clearLeadingZeroes();
    return *this;
}

//Assignment operator for polynomials.
Polynomial& Polynomial::operator=(const Polynomial& pol) {
    if (this != &pol) {
        clearPolynomial(headptr);
        degree = 0;
        Term* curr_term = pol.headptr;
        Term* lhs_prior = nullptr;
        while (curr_term) {
            lhs_prior = addHighestTerm(curr_term->coefficient, lhs_prior);
            curr_term = curr_term->next;
        }
    }
    return *this;
}

//Adds a term at the start.
void Polynomial::addLowestTerm(int data) {
    headptr = new Term(data, headptr);
    ++degree;
}

//Adds a term at the end.
Polynomial::Term* Polynomial::addHighestTerm(int data, Term* curr_high) {
    if (!curr_high) {
        headptr = new Term(data);
        return headptr;
    }
    curr_high->next = new Term(data);
    ++degree;
    return curr_high->next;
}

// Removes leading zero terms.
void Polynomial::clearLeadingZeroes() {
    Term* curr_term = headptr;
    Term* prior = nullptr;
    while (curr_term->next) {
        if (!curr_term->next->coefficient) {
            if (!prior) prior = curr_term;
        } else {
            if (prior) prior = nullptr;
        }
        curr_term = curr_term->next;
    }
    if (prior) {
        clearPolynomial(prior->next);
        prior->next = nullptr;
    }
}

//Evaluates polynomial at value.
int Polynomial::evaluate(int val) const {
    int result = 0;
    Term* curr_term = headptr;
    while (curr_term) {
        result = result * val + curr_term->coefficient;
        curr_term = curr_term->next;
    }
    return result;
}

//Clears all polynomial terms.
void Polynomial::clearPolynomial(Term* curr_term) {
    while (curr_term) {
        Term* prior = curr_term;
        curr_term = curr_term->next;
        delete prior;
        --degree;
    }
    curr_term = nullptr;
}

// Destructor for polynomial object.
Polynomial::~Polynomial() {
    clearPolynomial(headptr);
}

//Constructor for polynomial term.
Polynomial::Term::Term(int coefficient, Term* next)
    : coefficient(coefficient), next(next) {}
