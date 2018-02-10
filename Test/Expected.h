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

class Expected{

private:
  MyString className;

public:
    Expected();
    ~MyDate();
  /*
    expect function arguments explanation:
    1) The name of the Class to be tested
    2) The name of the function to be tested
    3) The actual function to be tested
    4) The expected result
  */
  void expect(MyString functionName, int functionResult, int expectedResult);
  void expect(MyString functionName, int functionResult, int expectedResult);
  void expect(MyString functionName, int functionResult, double expectedResult);
  void expect(MyString functionName, int functionResult, MyString expectedResult);
  void expect(MyString functionName, int functionResult, bool expectedResult);
  void expect(MyString functionName, int functionResult, float expectedResult);

  void expect(MyString functionName, double functionResult, double expectedResult);
  void expect(MyString functionName, double functionResult, int expectedResult);
  void expect(MyString functionName, double functionResult, MyString expectedResult);
  void expect(MyString functionName, double functionResult, bool expectedResult);
  void expect(MyString functionName, double functionResult, float expectedResult);

  void expect(MyString functionName, MyString functionResult, MyString expectedResult);
  void expect(MyString functionName, MyString functionResult, int expectedResult);
  void expect(MyString functionName, MyString functionResult, double expectedResult);
  void expect(MyString functionName, MyString functionResult, bool expectedResult);
  void expect(MyString functionName, MyString functionResult, float expectedResult);

  void expect(MyString functionName, bool functionResult, bool expectedResult);
  void expect(MyString functionName, bool functionResult, int expectedResult);
  void expect(MyString functionName, bool functionResult, double expectedResult);
  void expect(MyString functionName, bool functionResult, MyString expectedResult);
  void expect(MyString functionName, bool functionResult, float expectedResult);

  void expect(MyString functionName, float functionResult, float expectedResult);
  void expect(MyString functionName, float functionResult, int expectedResult);
  void expect(MyString functionName, float functionResult, double expectedResult);
  void expect(MyString functionName, float functionResult, MyString expectedResult);
  void expect(MyString functionName, float functionResult, bool expectedResult);

};

#endif /* defined(__Expected__) */
