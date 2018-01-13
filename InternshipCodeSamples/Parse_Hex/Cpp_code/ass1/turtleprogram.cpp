/*
	Author:		Ryan Peters
	Date:		January 12, 2017 -- (1/12/2017)
*/
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <fstream>

int convert_to_int(const char charAtPosI) {
	switch (charAtPosI) {
		case '#':
		case '0':	//0000
			return 0;
		case '1':	//0001
			return 1;
		case '2':	//0010
			return 2;
		case '3':	//0011
			return 3;
		case '4':	//0100
			return 4;
		case '5':	//0101
			return 5;
		case '6':	//0110
			return 6; 
		case '7':	//0111
			return 7;
		case '8':	//1000
			return 8;
		case '9':	//1001
			return 9;
		case 'a':
		case 'A':	//1010
			return 10;
		case 'b':
		case 'B':	//1011
			return 11;
		case 'c':
		case 'C':	//1100
			return 12;
		case 'd':
		case 'D':	//1101
			return 13;
		case 'e':
		case 'E':	//1110
			return 14;
		case 'f':
		case 'F':	//1111
			return 15;
		default:
			return -1;
	} // end switch block
}

/*
 * Complete the function below.
 */
int css_string_to_color(const std::string &color_string) {
	auto stringSize = color_string.size();
	if ((stringSize != 4 && stringSize != 7) || color_string.at(0) != '#') {
		throw std::exception("Error");
	}

	int charArrSize = 6;
	char *charArr = new char[charArrSize];
	int red = 0, blue = 0, green = 0, ret = 0;

	for (int colorStrIdx = 1, chArIdx = 0; colorStrIdx < stringSize; ++colorStrIdx) {
		char c = color_string.at(colorStrIdx);
		switch (stringSize) {
			default:
				break;
			case 4:
				charArr[chArIdx++] = c;
			case 7:
				charArr[chArIdx++] = c;				
		}// end of switch(stringSize) block
	}// end of for(colorStrIdx, chArIdx) loop

	for (int i = 0; i < charArrSize; i+=2) {
		// binNum and binNum2 are each assigned a 4-bit representation of the hex-to-int conversions for each char from color_string
		// The reason these values aren't directly assigned to red, green, and blue is that it forced me to write redundant code when sanity checking.
		int binNum = convert_to_int(charArr[i]), binNum2 = convert_to_int(charArr[i+1]);

		// sanity checking our values at each character, I wish I could think of a more efficient way to do this
		if (binNum < 0 || binNum2 < 0) {
			throw std::exception("Error");
		}
		/*
			red		represents the values from color_string[1] and color_string[2]
			green	represents the values from color_string[3] and color_string[4]
			blue	represents the values from color_string[5] and color_string[6]
		*/
		switch (i) {
			case 0:
				red |= binNum << 4;
				red |= binNum2;
				break;
			case 2:
				green |= binNum << 4;
				green |= binNum2;
				break;
			case 4:
				blue |= binNum << 4;
				blue |= binNum2;
				break;
			default:
				break;
		} // end of switch(i) block
	}// end of for(i) loop

	int bitPos = 0;


	/*
		After the following if block, ret should be have 8 bit increments that express color data
		in the following order: ret = 00000000 bbbbbbbb gggggggg rrrrrrrr
			NOTE: the leading 8 bits of the 32 bit int that ret is mapped to are unused
			
		eg., to show the colors red, purple, or orange, ret should have the following bits patterns:
			pure red:
						unused  | blue   | green  | red
				ret = 00000000 00000000 00000000 11111111

			purple:   unused  | blue   | green  | red
				ret = 00000000 10000000 00000000 10000000

			orange:   unused  | blue   | green  | red
				ret = 00000000 00000000 01011010 11111111
	*/

	if (red > 0) {
		ret |= red << bitPos;
		bitPos += 8;
			
		ret |= green << bitPos;
		bitPos += 8;
			
		ret |= blue << bitPos;
		bitPos += 8;

	} else if (green > 0) {
		ret |= green << bitPos;
		bitPos += 8;

		ret |= blue << bitPos;
		bitPos += 8;
			
	} else {
		ret |= blue << bitPos;
		bitPos += 8;
	}
	delete[] charArr;
	return ret;
	

}// end of int css_string_to_color(const std::string &color_string) 



int main() {

	std::vector<std::string> test_strings = { "#800080", "#F00", "#ffa500","oops", "#000000", "#000"};

	std::vector<int> test_answers = { 8388736, 255, 42495, -1, 0, 0 };
	
		std::ofstream collect_output;
		collect_output.open("zillow_problem1_output.txt", std::ofstream::app);
		for (unsigned int i = 0; i < test_strings.size(); ++i) {
			try{
				int tmp = css_string_to_color(test_strings.at(i));
				collect_output << "expecting " << test_answers.at(i) << " and got " << tmp << std::endl;
			}
			catch (const std::exception& str)
			{
				 collect_output << "shit went sideways on " << std::setw(7) << std::left << test_strings.at(i) << " expected " << test_answers.at(i) << ", but got " << str.what() << std::endl;
			}
		}
		collect_output << std::endl;
		collect_output.close();
	
	return 0;
}

