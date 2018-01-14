/*
	Author:		Ryan Peters
	Date:		January 12, 2017 -- (1/12/2017)
*/
#include "parse_hex.h"

int main() {

	std::vector<std::string> test_strings = { "#800080", "#F00", "#ffa500","oops", "#000000", "#000", "#00f000"};

	std::vector<int> test_answers = { 8388736, 255, 42495, -1, 0, 0, 61440 };
	
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

