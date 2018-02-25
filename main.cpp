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


using namespace std;

int main(int argc, const char * argv[]) {

  std::cout << "Starting program..."<< std::endl;

//   std::cout << "C++ Version: " << __cplusplus << " OS: " << os << std::endl;
//   if( __cplusplus == 201103L ) std::cout << "C++11\n" ;
//   else if( __cplusplus == 2017701L ) std::cout << "C++17\n" ;
//   else if( __cplusplus == 199711L ) std::cout << "C++98\n" ;
//   else std::cout << "pre-standard C++\n" ;

  Test testing;
  testing.testAll();

  // double x = 2.8;
  // double y = 2.0;
  // std::cout << "Value1 = " << floor(x) << " ValueY = " << floor(x-y) <<std::endl;

  return (0);
}
