//============================================================================
// Name        : displayinventory.h
// Author(s)   : Team 7 (Brady Pascoe)
// Created     : Feb 25, 2018
// Version     : Feb 25, 2018
// Description : The DisplayInventory class will print out the contents of the
//				 inventory to the console.
//============================================================================

#ifndef DISPLAYINVENTORY_H_
#define DISPLAYINVENTORY_H_
#include "action/action.h"

#include <ostream>

class DisplayInventory : public Action {

	/*
	* Name:
	* 	Output stream << overload
	* Description:
	* 	Will output a String-friendly representation of the DisplayInventory
	*/
	//friend std::ostream& operator<<(std::ostream&, const DisplayInventory&);

public:

	/*
	* Name:
	* 	General (No-Args) Constructor
	* Description:
	* 	Will call the Action(char) constructor and give it 'I'
	*/
	DisplayInventory();

	/*
	* Name:
	*	Copy Constructor
	* Description:
	* 	Will copy the contents of one DisplayInventory to the other
	*/
	DisplayInventory(const DisplayInventory&);

	/*
	* Name:
	*	Destructor
	* Description:
	* 	Should properly delete the Action object
	*/
	virtual ~DisplayInventory();

	/*
	* Name:
	*	doAction
	* Description:
	* 	The contents of the Inventory should be printed out
	* Parameter:
	*	The Inventory object that will have Actions performed upon
	* Return:
	*	Whether or not the action performed was successful or not
	*/
	virtual bool doAction(Inventory&) const override;

	Action* copy() const override;

	//bool parse(std::string) override;

	/*
	* Name:
	*	operator == overload
	* Description:
	* 	Checks whether or not the Actions are the same
	* Parameter:
	*	The other Action to compare with
	* Return:
	*	Whether or not the the two Actions are the same
	*/
	//bool operator==(const DisplayInventory&) const;

	/*
	* Name:
	*	operator != overload
	* Description:
	* 	Checks whether or not the Actions are NOT the same
	* Parameter:
	*	The other Action to compare with
	* Return:
	*	Whether or not the the two Actions are NOT the same
	*/
	//bool operator!=(const DisplayInventory&) const;
};

#endif /* DISPLAYINVENTORY_H_ */
