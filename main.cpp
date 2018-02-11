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

using namespace std;

int main(int argc, const char * argv[]) {

  cout << "Starting program..."<< endl;

  Test testing;

  try{
    testing.testMoney();
    // testing.testPerson();
    // testing.testMyDate();
    // testing.testMyTime();
  }
  catch (MyString e)
  {
    cout << "Error: " << e << endl;
  }
  return 0;
}
