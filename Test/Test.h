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
#include "../Model/Money.h"
#include "../Model/Person.h"
#include "../Model/User.h"

#include "./Test/Expected.h"

class Test{

public:
  Test();
  ~Test();

  void testMoney();
  void testPerson();

};

#endif /* defined(__Test__) */
