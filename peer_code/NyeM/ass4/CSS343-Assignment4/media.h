
//============================================================================
// Name        : media.h
// Author(s)   : Sean Chen Team 7
// Created     : Feb 28, 2018
// Version     : Feb 28, 2018
// Description : This is the design for media class, which is general guide
			 //	 for all the media types possible
//============================================================================


#ifndef MEDIA_H_
#define MEDIA_H_

class Media
{
public:
	const char MEDIA_TYPE; 

	/*
	* Name:
		No-Arg constructor for Media
	* Description:
		Will initialize a Media object with the type given from child classes
	*/
	explicit Media(char mediaType):MEDIA_TYPE(mediaType) {};

	/*
	* Name:
		Destructor
	* Description:z
		Will properly delete a Media object and its children
	*/
	virtual ~Media() = default;

	bool operator==(const Media&) const;

	bool operator!=(const Media&) const;

};
bool Media::operator==(const Media& OTHER) const {
	return MEDIA_TYPE == OTHER.MEDIA_TYPE;
}

bool Media::operator!=(const Media& OTHER) const {
	return MEDIA_TYPE != OTHER.MEDIA_TYPE;
}
#endif /* MEDIA_H_ */
