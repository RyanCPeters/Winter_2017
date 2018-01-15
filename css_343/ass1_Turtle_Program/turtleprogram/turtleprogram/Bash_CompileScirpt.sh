script output.txt
	g++ -std=c++14 -g -Wall -Wextra *.cpp -o grindTurtle
	./grindTurtle
	valgrind ./grindTurtle
EOF