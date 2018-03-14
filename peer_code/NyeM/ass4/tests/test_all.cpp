// dependencies
#include <iostream>
#include <iomanip>
#include <utility>
#include <chrono>
#include <ctime>

// test files
#include "test_class_classical.h"
#include "test_class_borrowmovie.h"


using namespace std;


/**
 *
 * @return
 */
int main() {

  time_t t = chrono::system_clock::to_time_t(chrono::system_clock::now());
  string s = ctime(&t);
  cout << s << endl;

  cout << "[+] Running all tests -" << endl;

  // Can't run independent unit tests non-static abstract class Action
//  cout << "[+]\t\t Action testing START" << endl;
//  test_class_action(false);
//  cout << "[+]\t\t Action testing END" << endl;


  cout << "[+]\t\t class Classical testing START" << endl;
  classical::test_class_classical(false);
  cout << "[+]\t\t class Classical testing END" << endl;

  // These test cases should come after testing class Movie's descendant classes
  // (class Classical, class Comedy, class Drama) on account of
  // BorrowMovie depends upon Movie.
  cout << "[+]\t\t BorrowMovie testing START" << endl;
  borrow::test_class_borrowmovie(false);
  cout << "[+]\t\t BorrowMovie testing END" << endl;

  cout << endl;


  return 0;
}
