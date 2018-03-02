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

#include "../Utilities/TimeAndDate.h"

#include "../Model/Money.h"
#include "../Model/User.h"
#include "../Model/Account.h"

#include "./Test/Expected.h"

using namespace std;

class Test{
private:
  int passedTests;
  int failedTests;
  int totalPassedTests;
  int totalFailedTests;

public:
  Test();
  ~Test();

  void testAll();

  bool testMoney();
  bool testMyClock();
  bool testMyDate();
  bool testMyTime();
  bool testMyString();
  bool testPerson();
  bool testUser();
  bool testTimeAndDate();

};

#endif /* defined(__TEST__) */
