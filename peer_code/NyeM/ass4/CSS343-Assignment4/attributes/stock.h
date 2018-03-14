//------------------------Stock.h----------------------------
//
// Author: Mitchell Nye CSS343 Section B (Team 7)
// Created: 2/26/2018
// Modified: 2/26/2018
//-----------------------------------------------------------
// Purpose: Stores the given string in Stock.
//-----------------------------------------------------------
// Notes: 
//-----------------------------------------------------------

#ifndef STOCK_H
#define STOCK_H

#include "attributes/movieattribute.h"

class Stock : public virtual MovieAttribute
{
	/*
	* Name:
	* 	Output stream << overload
	* Description:
	* 	Will output a String-friendly representation of the Attribute
	*/
	friend std::ostream& operator<<(std::ostream&, const Stock&);

public:
	//------------------------Stock------------------------
	// Description: Default, takes in the attribute type.
	//-----------------------------------------------------------
	Stock(); //took out parameter "const string attritype"

	//---------------------- ~Stock------------------------
	// Description: Cleans up stock.
	//-----------------------------------------------------------
	~Stock();

	//----------------------- SetData----------------------------
	// Description: Sets the data of this attribute.
	//-----------------------------------------------------------
	void setData(const std::string input);

	//----------------------- GetYear----------------------------
	// Description: Returns the stock.
	//-----------------------------------------------------------
	int getStock();

private:
	const std::string type = "Stock: ";
	int stock;
};
#endif // !STOCK_H