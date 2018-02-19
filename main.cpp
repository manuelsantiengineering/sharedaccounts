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

#include "./Test/Test.h"

#include <chrono>
#include <ctime>


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



  /*
    FROM HERE STARTS THE PERIOD TESTING
  */

  //   std::time_t result = std::time(NULL);
  //   std::gmtime(&result);
  //   std::cout << std::asctime(std::gmtime(&result)) << result << " (UTC) seconds since the Epoch\n";
  //   long int t = static_cast<long int> (result);
  //
  //
  //
  //   MyString timestr(t);
  //   std::cout << " MyString time: " << timestr << std::endl;
  //
  //   system_clock::time_point tp = system_clock::now();
  //   system_clock::duration dtn = tp.time_since_epoch();
  //
  //   std::cout << "current time since epoch, expressed in:" << std::endl;
  //   std::cout << "periods: " << dtn.count() << std::endl;
  //   std::cout << "seconds: " << dtn.count() * system_clock::period::num / system_clock::period::den;
  //   std::cout << std::endl;
  //
  //
  //   std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
  // std::time_t now_c = std::chrono::system_clock::to_time_t(now - std::chrono::hours(24));
  // std::cout << "24 hours ago, the time was "
  //           << std::put_time(std::localtime(&now_c), "%F %T") << '\n';
  //
  // std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
  // std::cout << "Hello World\n";
  // std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  // std::cout << "Printing took "
  //           << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
  //           << "us.\n";
  //
  // time_t rawtime;
  // struct tm * timeinfo;
  // int year = 2018;
  // int month = 2;
  // int day = 13;
  // const char * weekday[] = { "Sunday", "Monday","Tuesday", "Wednesday","Thursday", "Friday", "Saturday"};
  //
  // time ( &rawtime );
  // timeinfo = localtime ( &rawtime );
  // timeinfo->tm_year = year - 1900;
  // timeinfo->tm_mon = month - 1;
  // timeinfo->tm_mday = day;
  //
  // /* call mktime: timeinfo->tm_wday will be set */
  // mktime ( timeinfo );
  //
  // std::cout << "That day is a " << weekday[timeinfo->tm_wday] << std::endl;
  //
  // struct tm tInfo {1,2,3,4,5,6};//= {.tm_mday=1};
  // struct tm tInfo2 = tInfo;
  // // struct tm tt = {.tm_mday=1};
  // // struct tm my_time = { .tm_year=112, .tm_mon=9, .tm_mday=9, .tm_hour=8, .tm_min=10, .tm_sec=20 };
  // // tInfo = {.tm_year=0,.tm_mon=1,.tm_mday=1,.tm_hour=0,.tm_min=0,.tm_sec=0 };
  //
  // std::cout << "Year: " << tInfo.tm_year << " Month: " << tInfo.tm_mon << " Day: " << tInfo.tm_mday
  //     << " Hour: " << tInfo.tm_hour << " Min: " << tInfo.tm_min << " Sec: " << tInfo.tm_sec << std::endl;
  //
  // std::cout << "Year: " << tInfo2.tm_year << " Month: " << tInfo2.tm_mon << " Day: " << tInfo2.tm_mday
  //     << " Hour: " << tInfo2.tm_hour << " Min: " << tInfo2.tm_min << " Sec: " << tInfo2.tm_sec << std::endl;
  //
  //
  // tInfo2 = {7,8,9,10,11,12};
  // tInfo2.tm_mday = 1;
  // tInfo2.tm_mon = 2;
  // std::cout << "Year: " << tInfo2.tm_year << " Month: " << tInfo2.tm_mon << " Day: " << tInfo2.tm_mday
  //     << " Hour: " << tInfo2.tm_hour << " Min: " << tInfo2.tm_min << " Sec: " << tInfo2.tm_sec << std::endl;


  return 0;
}
