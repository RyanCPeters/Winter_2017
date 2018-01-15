#pragma once
#include <iosfwd>
#include <string>


class TurtleProgram {
public:

	TurtleProgram();
	TurtleProgram(const TurtleProgram &tp);
	TurtleProgram(const std::string &dir, const std::string &len);
	~TurtleProgram();


	std::string makeString()const;
	friend std::ostream& operator<<(std::ostream &os, const TurtleProgram &tp);
	
	bool operator==(const TurtleProgram &rhs);
	bool operator!=(const TurtleProgram &rhs);

	TurtleProgram& operator=( const TurtleProgram &rhs );
	TurtleProgram& operator=( const TurtleProgram * const rhs );

	const TurtleProgram operator+( const TurtleProgram &rhs ) const;
	const TurtleProgram operator+( const TurtleProgram * const rhs ) const;
	TurtleProgram& operator+=( const TurtleProgram &rhs);
	TurtleProgram& operator+=( const TurtleProgram * const rhs);

	const TurtleProgram operator*( const int &rhs) const;
	const TurtleProgram operator*( const int * const rhs) const;
	TurtleProgram& operator*=( const int &rhs);
	TurtleProgram& operator*=( const int * const rhs);

	const int getLength() const;
	std::string& getIndex(const int &pos)const;
	std::string& getIndex(const int* const pos)const;
	bool setIndex(const int &pos, const std::string &val);
	bool setIndex(const int &pos, std::string* const val);


private:
	int size;
	/** std::string *dirLenArr
	 * reads as: "direction-Length-Array"
	 * used for storing the program instructions in a dynamically allocated string array pointer.
	 */
	std::string *dirLenArr;
};