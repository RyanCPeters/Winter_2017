#ifndef CSS343_ASSIGNMENT4_TEST_CLASS_CUSTOMERACTION_H
#define CSS343_ASSIGNMENT4_TEST_CLASS_CUSTOMERACTION_H

#include "action/customeraction.h"
#include "tools_for_testing.h"

using namespace std;


/**
 *
 * @return
 */
CustomerAction testing_char_ctor(){
  CustomerAction a = CustomerAction('F');
}

/**
 *
 */
CustomerAction testing_char_int_ctor(){
  CustomerAction b = CustomerAction('F',0);
}

/**
 *
 * @return
 */
void testing_copy_ctor(){

}

/**
 *
 * @return
 */
void testing_getLetter(){

}

/**
 *
 * @return
 */
void testing_parse(){

}


/**
 *
 * @return
 */
void testing_equals_operator(){

}

/**
 *
 * @return
 */
void testing_not_equals_operator(){

}

/**
 *
 */
void test_class_action(const bool& print_per_case){
  std::string func_name;
// testing Action('F')
  try {
    func_name = "testing_char_ctor";
    if(print_per_case){
      introduce_test(func_name);
    }
    testing_char_ctor();
    if(print_per_case){
      passed_test_cout(func_name);
    }
  }catch (exception& err){
    failed_test_cout(func_name);
    std::cout << err.what() << std::endl;
  }
// testing the copy constructor
  try {
    func_name = "testing_copy_ctor";
    if(print_per_case){
      introduce_test(func_name);
    }
    testing_copy_ctor();
    if(print_per_case){
      passed_test_cout(func_name);
    }
  }catch (string& serr){
    failed_test_cout(func_name);
    std::cout << serr << std::endl;
  }
// testing the getLetter function
  try {
    func_name = "testing_getLetter";
    if(print_per_case){
      introduce_test(func_name);
    }
    testing_getLetter();
    if(print_per_case){
      passed_test_cout(func_name);
    }
  }catch (string& serr){
    failed_test_cout(func_name);
    std::cout << serr << std::endl;
  }
// testing the parse function
  try {
    func_name = "testing_parse";
    if(print_per_case){
      introduce_test(func_name);
    }
    testing_parse();
    if(print_per_case){
      passed_test_cout(func_name);
    }
  }catch (string& serr){
    failed_test_cout(func_name);
    std::cout << serr << std::endl;
  }
// testing the operator== overload
  try {
    func_name = "testing_equals_operator";
    if(print_per_case){
      introduce_test(func_name);
    }
    testing_equals_operator();
    if(print_per_case){
      passed_test_cout(func_name);
    }
  }catch (string& serr){
    failed_test_cout(func_name);
    std::cout << serr << std::endl;
  }
// testing the operator!= overload
  try {
    func_name = "testing_not_equals_operator";
    if(print_per_case){
      introduce_test(func_name);
    }
    testing_not_equals_operator();
    if(print_per_case){
      passed_test_cout(func_name);
    }
  }catch (string& serr){
    failed_test_cout(func_name);
    std::cout << serr << std::endl;
  }

  passed_test_cout("class Action");

}



#endif //CSS343_ASSIGNMENT4_TEST_CLASS_CUSTOMERACTION_H
