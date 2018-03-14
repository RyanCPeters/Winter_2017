
//============================================================================
// Name        : dvd.h
// Author(s)   : Sean Chen Team 7
// Created     : Feb 28, 2018
// Version     : Feb 28, 2018
// Description : This is the design for the DVD class, which is a media type
			//   and is able to store movie name, publisher and year info
//============================================================================


#ifndef DVD_H_
#define DVD_H_

#include "media.h"

//DVD inherits from Media
class DVD : public Media
{
public:

	/*
	* Name:
	Constructor for DVD
	* Description:
	Will initialize a DVD object and call the 
	base(char) constructor and give it 'd'
	*/
	DVD();

	/*
	* Name:
		Destructor
	* Description:
		Will properly delete the DVD object
	*/
	virtual ~DVD();


	/*
	* Name:
		isStacakble()
	* Description:z
		Will return the stackable property of the DVD
	*/
	//bool isStackable();

/*
private:
	string dvdName;
	string publisher;
	int year;
	float price;
	bool stackable = true;
*/
};

#endif /* DVD_H_ */
