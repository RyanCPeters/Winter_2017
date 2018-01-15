/** The TurtleProgram is designed according to the instructions given in the CSS343 course assigment #1 write up.
 *
 * Design Assumptions:
 * 		1) This program won't need to worry about memory allocations being greater than the available heap
 * 			memory. It is also assumed that arguments passed as inputs via the setIndex function are
 *
 * 		2) There
 *
 */

#include "turtleprogram.h"
#include <iostream>
#include <sstream>
#include <algorithm>

/** TurtleProgram::TurtleProgram() :dirLenArr(0), size(0) {}
 * The default empty constructor for the turtleprogram class
 */
TurtleProgram::TurtleProgram() :dirLenArr(0), size(0) {}


/** TurtleProgram::TurtleProgram(const TurtleProgram & tp) {
 * A copy constructor implementation
 * @param tp the TurtleProgram instance to be copied
 */
TurtleProgram::TurtleProgram(const TurtleProgram & tp) {
	size = tp.size;
	dirLenArr = new std::string[size];
	for (int i = 0; i < size; ++i) {
		dirLenArr[i] = tp.dirLenArr[i];
	}
}

/** TurtleProgram::TurtleProgram(const std::string &dir, const std::string &len) :dirLenArr(new std::string[2]{dir,len}), size(2) {
 * The two parameter constrcutor that takes the direction and the distance to travel or the number of degrees to turn.
 * @param dir a string representation of the direction to go, should be "F"(forward) or "R"
 * @param len a string representation of the number of pixels to travel or the number of degrees to turn
 */
TurtleProgram::TurtleProgram(const std::string &dir, const std::string &len) :dirLenArr(new std::string[2]{dir,len}), size(2) {}

/** TurtleProgram::~TurtleProgram() {
 * The destructor for this class needs only to delete the string array that stores the programs directions.
 */
TurtleProgram::~TurtleProgram() {
	delete[] dirLenArr;
}

/** std::string TurtleProgram::makeString() const {
 * This is a helper function for the operator<< output overload function. It generates the string representatino
 * of the current instruction set stored in the dirLenArr array.
 * @return the string representation of the instructions held in the dirlenArr array.
 */
std::string TurtleProgram::makeString() const {
	if (size < 1) return "[]";
	std::stringstream ss;
	ss << "[";
	ss <<  dirLenArr[0];
	for (int i = 1; i < size; ++i) {
		ss << " " << dirLenArr[i];
	}
	ss << "]";
	return ss.str();
}

/** bool TurtleProgram::operator==( const TurtleProgram & rhs) {
 * Overload of the equality operator, checks that the objects being compared have the same size array, if true
 * then it proceeds to check that both objects have stored identical sets of instructions in their dirLenArr array.
 * @param rhs the object on the right hand side of the == operator.
 * @return true if the size and contents of the dirlenArr arrays are the same, false otherwise.
 */
bool TurtleProgram::operator==( const TurtleProgram & rhs) {
	if (size != rhs.size)return false;
	bool isEqual = true;
	for (int i = 0; isEqual && i < size; ++i) {
		isEqual = dirLenArr[i] == rhs.dirLenArr[i];
	}
	return isEqual;
}

/** bool TurtleProgram::operator!=( const TurtleProgram & rhs) {
 * provides the NOT operator on the operator== overload.
 *
 * @param rhs
 * @return
 */
bool TurtleProgram::operator!=( const TurtleProgram & rhs) {
	return !(*this == rhs);
}


/** TurtleProgram & TurtleProgram::operator=( const TurtleProgram & rhs) {
 * Overloads the assignment operator: this function first sanity checks that the parameter being passed in
 * is not an alias to this object's memory address.
 *
 * If rhs is not an alias, then the function proceeds with deleting the current data in dirLenArr and then updates
 * the array to have deep copies of the the array held by rhs, along with this the variable 'size' is assigned the
 * same value as that stored in rhs.
 * @param rhs an instance of the TurtleProgram whos data will be copied into this instance.
 * @return the updated reference to this instance of the TurtleProgram.
 */
TurtleProgram & TurtleProgram::operator=( const TurtleProgram & rhs) {
	if (this == &rhs)return *this;
	size = rhs.size;
	delete[] dirLenArr;
	dirLenArr = new std::string[size];
	for (int i = 0; i < size; ++i)dirLenArr[i] = rhs.dirLenArr[i];
	return *this;
}

/** TurtleProgram& TurtleProgram::operator=( const TurtleProgram * const rhs) {
 * This Overload is simply a parameter variation that accepts pointers instead of lvalue references.
 * @param rhs
 * @return
 */
TurtleProgram& TurtleProgram::operator=( const TurtleProgram * const rhs) {
	if (this == rhs)return *this;
	*this = *rhs;
	return *this;
}

/**
 *
 * @param rhs
 * @return
 */
const TurtleProgram TurtleProgram::operator+(const TurtleProgram &rhs) const {
	TurtleProgram tmp(*this);
	tmp += rhs;
	return tmp;
}

const TurtleProgram TurtleProgram::operator+( const TurtleProgram * const rhs) const {
	TurtleProgram tmp(*this);
	tmp += *rhs;
	return tmp;
}

TurtleProgram & TurtleProgram::operator+=(const TurtleProgram & rhs) {
	int newSize = size + rhs.size;
	std::string *tmpArrPtr = new std::string[newSize];
	for (int i = 0; i < newSize; ++i) {
		tmpArrPtr[i] = (i < size) ? dirLenArr[i] : rhs.dirLenArr[i - size];
	}
	// clear out the old data now that it's copied
	delete[] dirLenArr;

	// update internal values to the new ones
	size = newSize;
	dirLenArr = tmpArrPtr;

	// delete the temp pointers
	tmpArrPtr = nullptr;
	delete[] tmpArrPtr;
	return *this;	
}

TurtleProgram& TurtleProgram::operator+=( const TurtleProgram * const rhs) {
	*this += *rhs;
	return *this;
}

const TurtleProgram TurtleProgram::operator*( const int & rhs) const {
	TurtleProgram tmp(*this);
	tmp *= rhs;
	return tmp;
}

const TurtleProgram TurtleProgram::operator*( const int * const rhs) const {	
	return (this->operator*(*rhs));
}

TurtleProgram & TurtleProgram::operator*=( const int & rhs) {
	int newSize = size * rhs;
	std::string *dest = new std::string[newSize];
	for (int mult = 0; mult < rhs; ++mult) {
		for (int i = size * mult, source = 0; source < size; ++i, ++source) {
			dest[i] = dirLenArr[source];
		}
	}
	delete[] dirLenArr;
	dirLenArr = dest;
	size = newSize;

	dest = nullptr;
	delete[] dest;

	return *this;
}

TurtleProgram& TurtleProgram::operator*=( const int * const rhs) {
	*this *= *rhs;
	return *this;
}

int TurtleProgram::getLength() const {
	return size;
}

std::string& TurtleProgram::getIndex(const int & pos) const {
	std::string nll = "NULL";
	return ((pos < getLength() && pos >= 0)? dirLenArr[pos] : nll);
}

std::string& TurtleProgram::getIndex(const int * const pos) const {
	return getIndex(*pos);
}

bool TurtleProgram::setIndex(const int &pos, const std::string &val) {
	if (pos > getLength() || pos < 0)return false;
	dirLenArr[pos] = val;
	return true;
}

bool TurtleProgram::setIndex(const int &pos, std::string* const val) {
	return setIndex(pos,*val);
}

std::ostream & operator<<(std::ostream & os, const TurtleProgram & tp) {
	os << tp.makeString();
	return os;
}

