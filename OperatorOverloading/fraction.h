#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class Fraction
{
  public:
    /// @brief Constructs a fraction with numerator 0 and denominator 1. 
    Fraction();

    /// @brief Constructs a fraction with numerator t and denominator 1.
    /// @param t the numberator for the fraction
    Fraction(int t);

    /// @brief Constucts a fraction with given numerator and denominator.
    /// @param t the initial numerator
    /// @param b the initial denominator
    Fraction(int t, int b);

    /// @brief Returns the numerator.
    /// @return the numerator value
    int numerator() const;

    /// @brief Returns the denominator
    /// @return the denominator value
    int denominator() const;

    /// @brief Updates a fraction by adding in another fraction value
    /// @param right the fraction to be added
    /// @return the updated fraction value
    Fraction& operator+=(const Fraction& right);

    /// @brief Prefix from increments fraction by 1
    /// @return 
    Fraction& operator++();

    /// @brief Postfix from increments fraction by 1
    /// @param unused 
    /// @return 
    Fraction operator++(int unused);

    

  private:
    void normalize();

};

#endif 