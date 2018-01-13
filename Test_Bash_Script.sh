#!/bin/bash
# Ask the user for their name
read -p 'Hello, who am I talking to?' varname
echo It\'s nice to meet you $varname
read -p 'enter file names, seperated by spaces, that you want compiled' varFileNames
cat > output.txt 
	g++ -std=c++14 -g -Wall -Wextra $varFileNames -o grindable_output
	./grindable_output
	valgrind ./grindable_output
EOF