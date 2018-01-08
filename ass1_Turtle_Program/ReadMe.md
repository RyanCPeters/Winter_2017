Turtle Program
[Turtle Graphics](https://en.wikipedia.org/wiki/Turtle_graphics) as part of [Logo](https://en.wikipedia.org/wiki/Logo_(programming_language) was one of the first languages explicitly designed for teaching beginning programming.

A TurtleProgram is a set of instructions directing the on-screen turtle to draw graphics. To draw a square, one would execute:

Forward 10 Right 90 Forward 10 Right 90 Forward 10 Right 90 Forward 10 Right 90 
To practice dynamically allocated arrays and operator overloading, create a TurtleProgram class that supports the following functionality. For simplicity, use “F” instead of “Forward” and “R” instead of “Right”.

Constructors and destructor

Overload <<, so programs can be printed as below

Overload equality and inequality operators: operator== and operator!=. Two programs are == if all their instructions are the same.

Overload the following operators: operator=, operator+ and operator+=. Adding 2 programs creates a longer program.

Multiplying a program with an integer creates a larger program where the same program is repeated that many times. Write the * and *= operators. Multiplying by 0 or negative numbers is not defined. You can silently ignore the operation, throw an error or handle it in a different way. Similarly, multiplying two TurtleProgram’s is not defined.

Index 0 of a program is defined as the first string in the program (i.e. for program [F 10] index 0 is "F". Implement getLength,  getIndex and setIndex so the program can be modified.

The data for the TurtleProgram must be in a private dynamically allocated array of just the right size. Normally, we would allocate a much larger array, but for this exercise, we are practicing dynamically resizing our data array.
```
int main()
{
    TurtleProgram tp1;
    cout << "tp1: " << tp1 << endl;
    TurtleProgram tp2("F", "10");
    cout << "tp2: " << tp2 << endl;
    TurtleProgram tp3("R", "90");
    tp1 = tp2 + tp3;
    cout << "tp1 now as tp2+tp3: " << tp1 << endl;
    tp1 = tp2 * 3;
    cout << "tp1 now as tp2 * 3: " << tp1 << endl;
    TurtleProgram tp4(tp1);
    cout << "tp4 is a copy of tp1: " << tp4 << endl;
    TurtleProgram tp5("F", "10");
    cout << "tp5: " << tp5 << endl;
    cout << boolalpha;
    cout << "tp2 and tp5 are == to each other: " << (tp2 == tp5) << endl;
    cout << "tp2 and tp3 are != to each other: " << (tp2 != tp3) << endl;
    cout << "index 0 of tp2 is " << tp2.getIndex(0) << endl;
    tp2.setIndex(0, "R");
    tp2.setIndex(1, "90");
    cout << "tp2 after 2 calls to setIndex: " << tp2 << endl;
    cout << "tp2 and tp3 are == to each other: " << (tp2 == tp3) << endl;
    // need to write additional tests for += *=
    cout << "Done." << endl;
    return 0;
}

```

output:

```
tp1: []
tp2: [F 10]
tp1 now as tp2+tp3: [F 10 R 90]
tp1 now as tp2 * 3: [F 10 F 10 F 10]
tp4 is a copy of tp1: [F 10 F 10 F 10]
tp5: [F 10]
tp2 and tp5 are == to each other: true
tp2 and tp3 are != to each other: true
index 0 of tp2 is F
tp2 after 2 calls to setIndex: [R 90]
tp2 and tp3 are == to each other: true
Done.
```

As always expected when programming, comment clearly and thoroughly. Clearly state any assumptions you make in the beginning comment block of the appropriate place, e.g., the class definition. Comments in the class definition file should describe the ADT, all functionality, and assumptions so someone could use the class and understand behavior and restrictions. Pre and post conditions are fine, but not required. See the example on Assignments page for a well-documented program.

You do NOT need to handle data type errors, such as NULL being passed to constructors, or commands other than “F” and “R” being passed. We are not executing the program, so any two strings would be acceptable parameters for constructors. You are not allowed to use anything from the STL or 342’s Array class. You may not fix the array size at some large constant (although you may make an assumption that arrays larger than can be held in memory will not be handled). The point of this assignment is to review memory management; you will be allocating/deallocating memory often.

I will run my own main to test your code. The main function provided doesn’t test TurtleProgram fully, so you need to supplement it.

Write one function at a time. Test it before moving on to the next function. I suggest starting with operator== Use valgrind to check for memory leaks as you develop the program. Much easier to fix things early on.

Submit a single zip file, ass1.zip with the following files:

TurtleProgram.h
TurtleProgram.cpp
ass1.cpp – your own testing functions and main
output.txt - the script file, as defined in Connecting and compiling files on linux labs
comments.txt - your comments. Includes several bits of information

“Secret Number: XXXX” where XXXX is a 4 digit number not starting with 0. This will be your secret number. I will show how each student is doing relative to others using this number later in the quarter.

“Hours: XX” where XX is approximate number of hours it took you to complete this assignment

“Comments:” Optional comments, weird compiler error messages you got while developping, problems in setting things up etc. This is intended as for your information. If you want a response from me, email me instead.

Once your code is working on your own machine, test it once more on the linux machines (you have been testing incrementally and using  valgrind, right?). See Connecting and compiling files on linux labs

Under unix, compile your code using

g++ -std=c++14 -g -Wall -Wextra ass1.cpp TurtleProgram.cpp -o ass1
and create the output.txt file following the instructions on that page.

See Creating a zip file under Assignments on how to create and test your zip file. See the sample program on Assignments on how to properly document your code.

Yusuf Pisan pisan@uw.edu 
http://courses.washington.edu/css343/pisan/