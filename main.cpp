 // Created by Manuel E Santiago on 2/5/2018
 // Copyright (c) 2018 Manuel. All rights reserved.


 #include <stdio.h>
 #include <stdlib.h>
 #include <iostream>
 #include <string.h>
 #include <cstring>

#include "./Model/Money.h"
#include "./Model/User.h"
#include "./Utilities/MyString.h"
#include "./Utilities/MyDate.h"
#include "./Utilities/MyTime.h"
#include "./Utilities/Period.h"

#include "./Test/Test.h"

#include <chrono>
#include <ctime>


#ifndef _WIN32
  const int os = 1;
#else
  const int os = 0;
#endif

enum OS {LINUX = 0, WIN, MAC, ANDROID, IOS};

// using namespace std;

int main(int argc, const char * argv[]) {

  std::cout << "Starting program..."<< std::endl;

//   std::cout << "C++ Version: " << __cplusplus << " OS: " << os << std::endl;
//   if( __cplusplus == 201103L ) std::cout << "C++11\n" ;
//   else if( __cplusplus == 2017701L ) std::cout << "C++17\n" ;
//   else if( __cplusplus == 199711L ) std::cout << "C++98\n" ;
//   else std::cout << "pre-standard C++\n" ;
// //
// //   switch(os)
// //   {
// //     case OS::LINUX : std::cout << "OS: " << "LINUX" << std::endl; break;
// //     case OS::WIN : std::cout << "OS: " << "WIN" << std::endl; break;
// //     case OS::MAC : std::cout << "OS: " << "MAC" << std::endl; break;
// //     case OS::ANDROID : std::cout << "OS: " << "ANDROID" << std::endl; break;
// //     case OS::IOS : std::cout << "OS: " << "IOS" << std::endl; break;
// //   }
// //
  Test testing;

  try{

    if(testing.testMyDate()){
      cout << "\n\t SUCCESS TESTING: " << "MyDate\n"<< endl;
    }else{
      cout << "\n\t FAILED TESTING: " << "MyDate\n" << endl;
    }

    // if(testing.testMyClock()){
    //   cout << "\n\t SUCCESS TESTING: " << "MyClock\n" << endl;
    // }else{
    //   cout << "\n\t FAILED TESTING: " << "MyClock\n" << endl;
    // }

    // if(testing.testMyString()){
    //   cout << "\n\t SUCCESS TESTING: " << "MyString\n" << endl;
    // }else{
    //   cout << "\n\t FAILED TESTING: " << "MyString\n" << endl;
    // }
  }
  catch (MyString e)
  {
    cout << "Error: " << e << endl;
  }

  return (0);
}
