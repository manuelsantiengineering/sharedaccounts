//
//  Test.*
//
//  Created by Manuel E Santiago on 2/1/2018.
//  Copyright (c) 2018 Manuel. All rights reserved.
//

#ifndef __TEST__
#define __TEST__

#include <stdio.h>
#include <iostream>
#include <exception>
#include "../Utilities/MyString.h"
// #include "../Utilities/MyDate.h"
// #include "../Utilities/MyClock.h"
#include "../Utilities/TimeAndDate.h"
#include "../Model/Money.h"
#include "../Model/Person.h"
#include "../Model/User.h"
#include "../Model/Account.h"

#include "./Test/Expected.h"

using namespace std;

class Test{
private:
  int passedTests;
  int failedTests;

public:
  Test();
  ~Test();

  void testAll();

  bool testPerson();
  bool testMoney();
  bool testMyDate();
  bool testMyTime();
  bool testMyClock();
  bool testMyString();

};

#endif /* defined(__TEST__) */
