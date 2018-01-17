//-------------------------poly.h--------------------------
//
// Author: Mitchell Nye CSS343 Section B
// Created: 1/14/2018
// Modified: 1/14/2018
//-----------------------------------------------------------
// Purpose: A program that manages polynomial algebra
//-----------------------------------------------------------
// Notes: This program assumes correct input types.
//		  Function descriptions are located in poly.cpp
//-----------------------------------------------------------

#ifndef POLY_H
#define POLY_H
#include <iostream>

class Poly {

public:
	Poly();
	Poly(int);
	Poly(int, int);
	Poly(const Poly &copy);
	~Poly();

	Poly operator+(const Poly&) const;
	Poly operator-(const Poly&) const;
	Poly operator-(const int&) const;
	Poly operator*(const Poly&) const;

	Poly& operator+=(const Poly&);
	Poly& operator-=(const Poly&);
	Poly& operator-=(const int&);
	Poly& operator*=(const Poly&);

	Poly& operator=(const Poly&);

	bool operator==(const Poly&) const;
	bool operator!=(const Poly&) const;

	friend std::ostream& operator<<(std::ostream& os, const Poly &poly);
	friend std::istream& operator>>(std::istream& is, Poly &poly);

	void setCoeff(int, int);
	int getCoeff(int) const;

private:
	int * coefficients;
	int power;
};
#endif