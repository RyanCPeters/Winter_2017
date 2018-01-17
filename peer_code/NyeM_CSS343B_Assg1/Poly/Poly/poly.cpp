//-------------------------poly.cpp--------------------------
//
// Author: Mitchell Nye CSS343 Section B
// Created: 1/14/2018
// Modified: 1/14/2018
//-----------------------------------------------------------
// Purpose: A program that manages polynomial algebra
//-----------------------------------------------------------
// Notes: This program assumes correct input types.
//-----------------------------------------------------------

#include "poly.h"

using namespace std;

//-------------------------poly------------------------------
// Description: Default, initializes array with one value = 0
//-----------------------------------------------------------
Poly::Poly()
{
	power = 0;
	coefficients = new int[power + 1];
	coefficients[0] = 0;
}

//-------------------------poly------------------------------
// Description: Takes in coefficient, initializes array, sets 
//				one val = parameter.
//-----------------------------------------------------------
Poly::Poly(int coeff)
{
	power = 0;
	coefficients = new int[1];
	coefficients[0] = coeff;
}

//-------------------------poly------------------------------
// Description: Takes in coefficient, initializes array, sets 
//				all values = 0, except for the index at pow,
//				which is set to coeff.
//-----------------------------------------------------------
Poly::Poly(int coeff, int pow)
{
	power = pow;
	coefficients = new int[power + 1];

	for (int i = 0; i < power; i++)
	{
		coefficients[i] = 0;
	}

	coefficients[pow] = coeff;
}

//-------------------------poly------------------------------
// Description: Deep copies the poly passed in.
//-----------------------------------------------------------
Poly::Poly(const Poly & copy)
{
	power = copy.power;
	coefficients = new int[power + 1];

	for (int i = 0; i < copy.power + 1; i++)
	{
		coefficients[i] = copy.coefficients[i];
	}
}

//------------------------~poly------------------------------
// Description: Deletes the poly's array and frees memory.
//-----------------------------------------------------------
Poly::~Poly()
{
	delete[] coefficients;
}

//-------------------------operator+-------------------------
// Description: Uses the += operator to add polynomials.
//-----------------------------------------------------------
Poly Poly::operator+(const Poly & p) const
{
	Poly combined = *this;
	combined += p;
	return combined;
}

//-------------------------operator- ------------------------
// Description: Uses the -= operator to subtract polynomials.
//-----------------------------------------------------------
Poly Poly::operator-(const Poly & p) const
{
	Poly combined = *this;
	combined -= p;
	return combined;
}

//-------------------------operator- ------------------------
// Description: Uses the -= operator to subtract an int.
//-----------------------------------------------------------
Poly Poly::operator-(const int & subtract) const
{
	Poly combined = *this;
	combined -= subtract;
	return combined;
}

//-------------------------operator*-------------------------
// Description: Uses the *= operator to multiply polynomials.
//-----------------------------------------------------------
Poly Poly::operator*(const Poly & p) const
{
	Poly combined = *this;
	combined *= p;
	return combined;
}

//-------------------------operator+=------------------------
// Description: Adds two polynomials together and returns the
//				result.
//-----------------------------------------------------------
Poly & Poly::operator+=(const Poly & p)
{
	//See if array size needs to be changed
	if (power >= p.power)
	{
		for (int i = 0; i <= p.power; i++)
		{
			coefficients[i] += p.coefficients[i];
		}
	}
	else
	{
		//Copy original poly and zero-out free space
		int * copy = new int[p.power + 1];
		for (int i = 0; i <= power; i++)
		{
			copy[i] = coefficients[i];
		}
		for (int i = power + 1; i <= p.power; i++)
		{
			copy[i] = 0;
		}

		//Add second poly to first
		for (int i = 0; i <= p.power; i++) 
		{
			copy[i] += p.coefficients[i];
		}
		power = p.power;
		delete[] coefficients;
		coefficients = copy;
	}
	return *this;
}

//-------------------------operator-=------------------------
// Description: Subtracts two polynomials and returns the
//				result.
//-----------------------------------------------------------
Poly & Poly::operator-=(const Poly & p)
{
	//See if array size needs to be changed
	if (power >= p.power)
	{
		for (int i = 0; i <= p.power; i++)
		{
			coefficients[i] -= p.coefficients[i];
		}
	}
	else
	{
		//Copy original poly into larger array
		int * copy = new int[p.power + 1];
		for (int i = 0; i <= power; ++i)
		{
			copy[i] = coefficients[i] - p.coefficients[i];
		}

		//Subtract second poly's values
		for (int i = power + 1; i <= p.power; ++i)
		{
			copy[i] = -p.coefficients[i];
		}

		power = p.power;
		delete[] coefficients;
		coefficients = copy;
	}
	return *this;
}

//-------------------------operator-=------------------------
// Description: Subtracts an integer from poly and returns
//				result.
//-----------------------------------------------------------
Poly & Poly::operator-=(const int & subtract)
{
	coefficients[0] -= subtract;
	return *this;
}

//-------------------------operator*=------------------------
// Description: Multiplies two polynomials, returns result.
//-----------------------------------------------------------
Poly & Poly::operator*=(const Poly & p)
{
	if (p.power > 0 && power > 0)
	{
		int newArrayPower = p.power + power;
		int * newArray = new int[newArrayPower + 1];

		for (int i = 0; i <= newArrayPower; i++) {
			newArray[i] = 0;
		}

		for (int i = 0; i <= power; i++)
		{
			for (int j = 0; j <= p.power; j++)
			{
				newArray[i + j] += coefficients[i] * p.coefficients[j];
			}
		}
		power += p.power;
		delete[] coefficients;
		coefficients = newArray;
	}
	else if (p.power == 0 && power == 0)
	{
		coefficients[0] *= p.coefficients[0];
	}
	return *this;
}

//-------------------------operator=-------------------------
// Description: Deep copies a polynomial into another.
//-----------------------------------------------------------
Poly & Poly::operator=(const Poly & p)
{
	//Check to see if there needs to be resizing or not
	if (power == p.power)
	{
		for (int i = 0; i <= power; i++)
		{
			coefficients[i] = p.coefficients[i];
		}
	}
	else
	{
		int * copy = new int[p.power + 1];
		for (int i = 0; i <= p.power; i++)
		{
			copy[i] = p.coefficients[i];
		}
		power = p.power;
		delete[] coefficients;
		coefficients = copy;
	}
	return *this;
}

//-------------------------operator==------------------------
// Description: Compares polynomials, returns true if equal.
//-----------------------------------------------------------
bool Poly::operator==(const Poly & p) const
{
	if (power > p.power)
	{
		//Check to see if the extra values are zeros or not.
		for (int i = p.power; i <= power; i++)
		{
			if (coefficients[i] != 0)
				return false;
		}
		//Compare the part that is the same length
		for (int i = 0; i <= p.power; i++)
		{
			if (coefficients[i] != p.coefficients[i])
				return false;
		}
		return true;
	}
	else if (power < p.power)
	{
		//Check to see if the extra values are zeros or not.
		for (int i = power; i <= p.power; i++)
		{
			if (p.coefficients[i] != 0)
				return false;
		}
		//Compare the part that is the same length
		for (int i = 0; i <= power; i++)
		{
			if (coefficients[i] != p.coefficients[i])
				return false;
		}
		return true;
	}
	else //They are the same size.
	{
		for (int i = 0; i <= power; i++)
		{
			if (coefficients[i] != p.coefficients[i])
				return false;
		}
		return true;
	}
}

//-------------------------operator==------------------------
// Description: Compares polynomials, returns false if equal.
//-----------------------------------------------------------
bool Poly::operator!=(const Poly & p) const
{
	if (power > p.power)
	{
		//Check to see if the extra values are zeros or not.
		for (int i = p.power; i <= power; i++)
		{
			if (coefficients[i] != 0)
				return true;
		}
		//Compare the part that is the same length
		for (int i = 0; i <= p.power; i++)
		{
			if (coefficients[i] != p.coefficients[i])
				return true;
		}
		return false;
	}
	else if (power < p.power)
	{
		//Check to see if the extra values are zeros or not.
		for (int i = power; i <= p.power; i++)
		{
			if (p.coefficients[i] != 0)
				return true;
		}
		//Compare the part that is the same length
		for (int i = 0; i <= power; i++)
		{
			if (coefficients[i] != p.coefficients[i])
				return true;
		}
		return true;
	}
	else //They are the same size.
	{
		for (int i = 0; i <= power; i++)
		{
			if (coefficients[i] != p.coefficients[i])
				return true;
		}
		return false;
	}
}

//-------------------------setCoeff--------------------------
// Description: Sets the coefficient at specified power,
//				resizes and initializes array if needed.
//-----------------------------------------------------------
void Poly::setCoeff(int coeff, int pow)
{
	if(power >= pow)
		coefficients[pow] = coeff;
	else if (pow > power) //Need to resize the array
	{
		int * copy = new int[pow + 1];
		//Copy until old power level
		for (int i = 0; i <= power; i++) 
		{
			copy[i] = coefficients[i];
		}

		//Set new "in-between" values to 0
		for (int i = power + 1; i < pow; i++) 
		{
			copy[i] = 0;
		}

		copy[pow] = coeff; //Set the highest index
		power = pow; //Set new power level of poly
		delete[] coefficients;
		coefficients = copy;
	}
}

//-------------------------getCoeff--------------------------
// Description: Gets the coefficient at specified power.
//-----------------------------------------------------------
int Poly::getCoeff(int pow) const
{
	if (pow > power || pow < 0)
		return 0;
	else
		return coefficients[pow];
}

//-------------------------operator<<------------------------
// Description: Fills ostream with formatted polynomial 
//				output.
//-----------------------------------------------------------
std::ostream & operator<<(std::ostream & os, const Poly & poly)
{
	bool allZeros = true; //Used to see if entire array is 0
	//Iterate backwards to print largest powers first
	for (int i = poly.power; i >= 0; i--)
	{
		if (poly.coefficients[i] != 0)
		{
			//Don't want to print out 0's
			if (!allZeros && poly.coefficients[i] > 0) {
				allZeros = false;
			}

			if (i > 1)
			{
				//showpos toggles the sign for the cout object
				//don't forget to toggle it with noshowpos
				if (poly.coefficients[i] != 1) 
				{
					os << " " << showpos << poly.coefficients[i]
						<< "x^" << noshowpos << i;
				}
				else
				{
					//Change if want to hide 1
					os << " +1x^" << noshowpos << i;
				}
				os.flush();

			}
			else if (i == 1) //Don't want to show power
			{
				if (poly.coefficients[i] != 1)
				{
					os << " " << showpos << poly.coefficients[i] 
						<< "x";
				}
				else
				{
					os << " +1x";//Change if want to hide 1
				}
				os.flush();
			}
			else if (i == 0) //Don't want to show x or power
			{
				if (poly.coefficients[i] != 0)
				{
					os << " " << showpos << poly.coefficients[i];
					os.flush();
				}
			}
		}
	}
	if (allZeros == 0) //All that was in the array is 0's
		os << noshowpos << " " << 0;
	return os;
}

//-------------------------operator>>------------------------
// Description: Takes input until two -1's are entered, and
//				fills the specified polynomial with input.
//				Input is taken in pairs, coefficient,
//				followed by power.
//-----------------------------------------------------------
std::istream & operator>>(std::istream & is, Poly & poly)
{
	int coeff = 0;
	int pow = 0;

	do 
	{
		is >> coeff >> pow;

		if (pow >= 0)
			poly.setCoeff(coeff, pow);
		//If the second number is negative, we treat
		//the first input as the coefficient for
		//index 1, and we treat the second as the
		//coefficient for index 0
		else if (pow < 0 && !(pow == -1 && coeff == -1))
		{
			poly.setCoeff(pow, 0);
			poly.setCoeff(coeff, 1); 
		}
	} while (!(coeff == -1 && pow == -1));
	return is;
}