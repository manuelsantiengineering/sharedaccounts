//
//  Expected.*
//
//  Created by Manuel E Santiago on 1/20/15.
//  Copyright (c) 2015 Manuel. All rights reserved.
//

#ifndef __Expected__
#define __Expected__

#include <stdio.h>
#include <iostream>
#include <exception>
#include "../Utilities/MyString.h"
#include "../Utilities/MyDate.h"
#include "../Model/Money.h"
#include "../Model/Person.h"
#include "../Model/User.h"

class Expected{

private:
  MyString className;

public:
  Expected();
  ~Expected();

  void setClassName(MyString className);
  /*
    General tests...
    expect function arguments explanation:
    1) The name of the Class to be tested
    2) The name of the function to be tested
    3) The actual function to be tested
    4) The expected result
  */
  void expect(MyString functionName, int functionResult, int expectedResult);
  void expect(MyString functionName, double functionResult, double expectedResult);
  void expect(MyString functionName, MyString functionResult, MyString expectedResult);
  void expect(MyString functionName, bool functionResult, bool expectedResult);
  void expect(MyString functionName, float functionResult, float expectedResult);
  void expect(MyString functionName, Person functionResult, Person expectedResult);
  void expect(MyString functionName, User functionResult, User expectedResult);
  void expect(MyString functionName, Money functionResult, Money expectedResult);
  void expect(MyString functionName, MyDate functionResult, MyDate expectedResult);
  /*
    Constructor tests...
    expect function arguments explanation:
    1) The class object
    2...N) The expected attributes
  */

  void testConstructor(Person person, MyString name, MyString lastName, int age);
  void testConstructor(Money money, MyString currency, double amount);

};

#endif /* defined(__Expected__) */
