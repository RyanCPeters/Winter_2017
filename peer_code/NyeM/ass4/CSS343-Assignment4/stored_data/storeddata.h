//============================================================================
// Name        : storeddata.h
// Author(s)   : Team 7 (Brady Pascoe)
// Created     : Feb 22, 2018
// Version     : Feb 22, 2018
// Description : This is the design for the StoredData class, which is used to
//				 store data within the Manager class.
//============================================================================

#ifndef STOREDDATA_H_
#define STOREDDATA_H_

class StoredData {
public:

	/*
	* Name:
	* 	General (No-Args) Constructor
	* Description:
	* 	Will just initialize the Object
	*/
	StoredData();

	/*
	* Name:
	* 	Destructor
	* Description:
	* 	Will properly delete the Object.
	*/
	virtual ~StoredData();

	/*
	* Name:
	* 	hash()
	* Description:
	* 	Will calculate a hash based on the current StoredData instance and
	*	return an index at which to insert into the Manager list.
	*	The hash will be an open hash, so collision detection is
	*	not neccessary.
	* Return: 
	*	The index at which to insert into the Manager list
	*/
	virtual int hash() const = 0;
};

#endif /* STOREDDATA_H_ */