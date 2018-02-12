 // Created by Manuel E Santiago on 2/5/2018
 // Copyright (c) 2018 Manuel. All rights reserved.


 #include <stdio.h>
 #include <stdlib.h>
 #include <iostream>
 #include <string.h>
 #include <cstring>

// #include "./Model/Money.h"
// #include "./Model/User.h"
// #include "./Utilities/MyString.h"
// #include "./Utilities/MyDate.h"
// #include "./Utilities/MyTime.h"

#include "./Test/Test.h"


// #include <chrono>
// using namespace std::chrono;

// using namespace std;

int main(int argc, const char * argv[]) {

  cout << "Starting program..."<< endl;

  // cout << "C++ Version: " << __cplusplus << endl;

  if( __cplusplus == 201103L ) std::cout << "C++11\n" ;
  else if( __cplusplus == 2017701L ) std::cout << "C++17\n" ;
  else if( __cplusplus == 199711L ) std::cout << "C++98\n" ;
  else std::cout << "pre-standard C++\n" ;


  Test testing;
  
  try{
    // if(testing.testMoney()){
    //   cout << "\n\t SUCCESS TESTING: " << "Money\n" << endl;
    // }else{
    //   cout << "\n\t FAILED TESTING: " << "Money\n" << endl;
    // }
    //
    // if(testing.testPerson()){
    //   cout << "\n\t SUCCESS TESTING: " << "Person\n" << endl;
    // }else{
    //   cout << "\n\t FAILED TESTING: " << "Person\n" << endl;
    // }
    //
    // if(testing.testMyDate()){
    //   cout << "\n\t SUCCESS TESTING: " << "MyDate\n"<< endl;
    // }else{
    //   cout << "\n\t FAILED TESTING: " << "MyDate\n" << endl;
    // }
    //
    // if(testing.testMyTime()){
    //   cout << "\n\t SUCCESS TESTING: " << "MyTime\n" << endl;
    // }else{
    //   cout << "\n\t FAILED TESTING: " << "MyTime\n" << endl;
    // }

    if(testing.testMyString()){
      cout << "\n\t SUCCESS TESTING: " << "MyString\n" << endl;
    }else{
      cout << "\n\t FAILED TESTING: " << "MyString\n" << endl;
    }
  }
  catch (MyString e)
  {
    cout << "Error: " << e << endl;
  }
  return 0;
}
