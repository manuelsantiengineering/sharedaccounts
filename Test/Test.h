//
//  Test.*
//
//  Created by Manuel E Santiago on 2/1/2018.
//  Copyright (c) 2018 Manuel. All rights reserved.
//

#ifndef __Test__
#define __Test__

#include <stdio.h>
#include <iostream>
#include <exception>
#include "../Utilities/MyString.h"
#include "../Utilities/MyDate.h"
#include "../Utilities/MyTime.h"
#include "../Model/Money.h"
#include "../Model/Person.h"
#include "../Model/User.h"
#include "../Model/Account.h"

#include "./Test/Expected.h"

using namespace std;

class Test{

public:
  Test();
  ~Test();

  bool testMoney();
  bool testPerson();
  bool testMyDate();
  bool testMyTime();
  bool testMyString();

};

#endif /* defined(__Test__) */
