

#ifndef MEDIA_INVENTORY_MANAGER_FORMATTED_TEST_OUTPUT_FUNCS_H
#define MEDIA_INVENTORY_MANAGER_FORMATTED_TEST_OUTPUT_FUNCS_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// length of longest string used in test results output
static const int testNameLen = 48;

// used to set a consistent with for pass or fail results
static const int pf = 20;

/**
 *
 * @param testName
 * @param testNameLen
 */
void passed_test_cout(const string &testName) {
  int l = testNameLen;
  cout << left << setw(pf) << "[+] passed" << left << ":" << setw(l) << right
       << testName << endl;
}

/**
 *
 * @param testName
 * @param testNameLen
 */
void failed_test_cout(const string &testName) {
  int l = testNameLen;
  cout << left << setw(pf) << "[-] failed" << left << ":" << setw(l) << right
       << testName << endl;
}

void introduce_test(const string &testName){
  cout << left << setw(pf) << "[+] performing test" << left << ":"
       << setw(testNameLen) << right << testName << endl;
}

/*
[+] performing test :                     test_each_genre_constructor
[+] passed          :                     test_each_genre_constructor
*/
#endif //MEDIA_INVENTORY_MANAGER_FORMATTED_TEST_OUTPUT_FUNCS_H
