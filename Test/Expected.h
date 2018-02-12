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
#include "../Utilities/MyTime.h"
#include "../Model/Money.h"
#include "../Model/Person.h"
#include "../Model/User.h"

class Expected{

private:
  MyString className;

public:
  // Expected();
  Expected(MyString name = "");
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
  bool expect(MyString functionName, int functionResult, int expectedResult);
  bool expect(MyString functionName, double functionResult, double expectedResult);
  bool expect(MyString functionName, MyString functionResult, MyString expectedResult);
  bool expect(MyString functionName, bool functionResult, bool expectedResult);
  bool expect(MyString functionName, float functionResult, float expectedResult);
  bool expect(MyString functionName, Person functionResult, Person expectedResult);
  bool expect(MyString functionName, User functionResult, User expectedResult);
  bool expect(MyString functionName, Money functionResult, Money expectedResult);
  bool expect(MyString functionName, MyDate functionResult, MyDate expectedResult);
  bool expect(MyString functionName, MyTime functionResult, MyTime expectedResult);
  /*
    Constructor tests...
    expect function arguments explanation:
    1) The class object
    2...N) The expected attributes
  */
  bool testConstructor(Person person, MyString name, MyString lastName, int age);
  bool testConstructor(User user, MyString name, MyString lastName, int age, MyString userId);
  bool testConstructor(Money money, MyString currency, double amount);
  bool testConstructor(MyDate date, int day, int month, int year);
  bool testConstructor(MyTime time, int h, int m, int s, bool isAM);
  bool testConstructor(MyString str1, const char *str2);

  /*
    Exception tests...
    expect function arguments explanation:
    1) The function name
    2) The function to be called
    3) The expected exception value
  */
  bool testException(MyString functionName, int functionResult, MyString expectedResult);
  bool testException(MyString functionName, double functionResult, MyString expectedResult);
  bool testException(MyString functionName, MyString functionResult, MyString expectedResult);
  bool testException(MyString functionName, bool functionResult, MyString expectedResult);
  bool testException(MyString functionName, float functionResult, MyString expectedResult);
  bool testException(MyString functionName, Person functionResult, MyString expectedResult);
  bool testException(MyString functionName, User functionResult, MyString expectedResult);
  bool testException(MyString functionName, Money functionResult, MyString expectedResult);
  bool testException(MyString functionName, MyDate functionResult, MyString expectedResult);
  bool testException(MyString functionName, MyTime functionResult, MyString expectedResult);

};

#endif /* defined(__Expected__) */
