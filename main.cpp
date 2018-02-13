 // Created by Manuel E Santiago on 2/5/2018
 // Copyright (c) 2018 Manuel. All rights reserved.


 #include <stdio.h>
 #include <stdlib.h>
 #include <iostream>
 #include <string.h>
 #include <cstring>

// #include "./Model/Money.h"
// #include "./Model/User.h"
#include "./Utilities/MyString.h"
// #include "./Utilities/MyDate.h"
// #include "./Utilities/MyTime.h"

#include "./Test/Test.h"

#include <chrono>


#ifndef _WIN32
  const int os = 1;
#else
  const int os = 0;
#endif

enum OS {LINUX = 0, WIN, MAC, ANDROID, IOS};

using namespace std::chrono;

// using namespace std;

int main(int argc, const char * argv[]) {

  std::cout << "Starting program..."<< std::endl;

  std::cout << "C++ Version: " << __cplusplus << " OS: " << os << std::endl;
  if( __cplusplus == 201103L ) std::cout << "C++11\n" ;
  else if( __cplusplus == 2017701L ) std::cout << "C++17\n" ;
  else if( __cplusplus == 199711L ) std::cout << "C++98\n" ;
  else std::cout << "pre-standard C++\n" ;

  switch(os)
  {
    case OS::LINUX : std::cout << "OS: " << "LINUX" << std::endl; break;
    case OS::WIN : std::cout << "OS: " << "WIN" << std::endl; break;
    case OS::MAC : std::cout << "OS: " << "MAC" << std::endl; break;
    case OS::ANDROID : std::cout << "OS: " << "ANDROID" << std::endl; break;
    case OS::IOS : std::cout << "OS: " << "IOS" << std::endl; break;
  }

  std::time_t result = std::time(NULL);
  std::gmtime(&result);
  std::cout << std::asctime(std::gmtime(&result)) << result << " (UTC) seconds since the Epoch\n";
  long int t = static_cast<long int> (result);



  MyString timestr(t);
  std::cout << " MyString time: " << timestr << std::endl;

  system_clock::time_point tp = system_clock::now();
  system_clock::duration dtn = tp.time_since_epoch();

  std::cout << "current time since epoch, expressed in:" << std::endl;
  std::cout << "periods: " << dtn.count() << std::endl;
  std::cout << "seconds: " << dtn.count() * system_clock::period::num / system_clock::period::den;
  std::cout << std::endl;


  std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
std::time_t now_c = std::chrono::system_clock::to_time_t(now - std::chrono::hours(24));
std::cout << "24 hours ago, the time was "
          << std::put_time(std::localtime(&now_c), "%F %T") << '\n';

std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
std::cout << "Hello World\n";
std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
std::cout << "Printing took "
          << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
          << "us.\n";



  // Test testing;

  // try{
  //   if(testing.testMoney()){
  //     cout << "\n\t SUCCESS TESTING: " << "Money\n" << endl;
  //   }else{
  //     cout << "\n\t FAILED TESTING: " << "Money\n" << endl;
  //   }
  //
  //   if(testing.testPerson()){
  //     cout << "\n\t SUCCESS TESTING: " << "Person\n" << endl;
  //   }else{
  //     cout << "\n\t FAILED TESTING: " << "Person\n" << endl;
  //   }
  //
  //   if(testing.testMyDate()){
  //     cout << "\n\t SUCCESS TESTING: " << "MyDate\n"<< endl;
  //   }else{
  //     cout << "\n\t FAILED TESTING: " << "MyDate\n" << endl;
  //   }
  //
  //   if(testing.testMyTime()){
  //     cout << "\n\t SUCCESS TESTING: " << "MyTime\n" << endl;
  //   }else{
  //     cout << "\n\t FAILED TESTING: " << "MyTime\n" << endl;
  //   }
  //
  //   if(testing.testMyString()){
  //     cout << "\n\t SUCCESS TESTING: " << "MyString\n" << endl;
  //   }else{
  //     cout << "\n\t FAILED TESTING: " << "MyString\n" << endl;
  //   }
  // }
  // catch (MyString e)
  // {
  //   cout << "Error: " << e << endl;
  // }
  return 0;
}
