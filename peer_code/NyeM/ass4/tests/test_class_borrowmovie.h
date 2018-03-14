#ifndef CSS343_ASSIGNMENT4_TEST_CLASS_BORROWMOVIE_H
#define CSS343_ASSIGNMENT4_TEST_CLASS_BORROWMOVIE_H

#include "stored_data/movie/classical.h"
#include "stored_data/movie/comedy.h"
#include "stored_data/movie/drama.h"
#include "action/borrowmovie.h"
#include "tools_for_testing.h"

using namespace std;


namespace borrow {
/**
 *
 */
  void testing_char_ctor() {
    BorrowMovie a = BorrowMovie('F');
  }

/**
 *
 */
  void testing_movie_customerID_ctor() {
    Comedy    f_movie = Comedy();
    Drama     d_movie = Drama();
    Classical c_movie = Classical();

    BorrowMovie   f   = BorrowMovie(&f_movie, 0);
    BorrowMovie   d   = BorrowMovie(&d_movie, 1);
    BorrowMovie   c   = BorrowMovie(&c_movie, 2);
  }

  /**
   *
   */
  void testing_movie_ctor(){
    Comedy f = Comedy();

    BorrowMovie bmf = BorrowMovie(&f);
  }

  /**
   *
   */
  void testing_copy_ctor() {
    BorrowMovie target = BorrowMovie('F');
    BorrowMovie copy = BorrowMovie(target);
  }




  /**
   *
   */
  void test_class_borrowmovie(const bool &print_per_case) {
    std::string func_name;
// testing BorrowMovie('F')
    try {
      func_name = "testing_char_ctor";
      if (print_per_case) {
        introduce_test(func_name);
      }
      testing_char_ctor();
      if (print_per_case) {
        passed_test_cout(func_name);
      }
    } catch (exception &err) {
      failed_test_cout(func_name);
      std::cout << err.what() << std::endl;
    }
// testing the copy constructor
    try {
      func_name = "testing_copy_ctor";
      if (print_per_case) {
        introduce_test(func_name);
      }
      testing_copy_ctor();
      if (print_per_case) {
        passed_test_cout(func_name);
      }
    } catch (string &serr) {
      failed_test_cout(func_name);
      std::cout << serr << std::endl;
    }

// testing the movie with customer id ctors
    try {
      func_name = "testing_equals_operator";
      if (print_per_case) {
        introduce_test(func_name);
      }
      testing_movie_customerID_ctor();
      if (print_per_case) {
        passed_test_cout(func_name);
      }
    } catch (string &serr) {
      failed_test_cout(func_name);
      std::cout << serr << std::endl;
    }
// testing the single movie param ctor
    try {
      func_name = "testing_not_equals_operator";
      if (print_per_case) {
        introduce_test(func_name);
      }
      testing_movie_ctor();
      if (print_per_case) {
        passed_test_cout(func_name);
      }
    } catch (string &serr) {
      failed_test_cout(func_name);
      std::cout << serr << std::endl;
    }

    passed_test_cout("class Action");

  }
}


#endif //CSS343_ASSIGNMENT4_TEST_CLASS_BORROWMOVIE_H
