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

using namespace std;

class Expected{

public:
    Expected();
    ~MyDate();
  /*
    expect function arguments explanation:
    1) Class to be tested
    2) function to be tested
    3)

  */
  void expect(MyString, MyString, int, int);
  void expect(MyString, MyString, int, double);
  void expect(MyString, MyString, int, MyString);
  void expect(MyString, MyString, int, bool);
  void expect(MyString, MyString, int, float);

  void expect(MyString, MyString, double, double);
  void expect(MyString, MyString, double, int);
  void expect(MyString, MyString, double, MyString);
  void expect(MyString, MyString, double, bool);
  void expect(MyString, MyString, double, float);

  void expect(MyString, MyString, MyString, MyString);
  void expect(MyString, MyString, MyString, int);
  void expect(MyString, MyString, MyString, double);
  void expect(MyString, MyString, MyString, bool);
  void expect(MyString, MyString, MyString, float);

  void expect(MyString, MyString, bool, bool);
  void expect(MyString, MyString, bool, int);
  void expect(MyString, MyString, bool, double);
  void expect(MyString, MyString, bool, MyString);
  void expect(MyString, MyString, bool, float);

  void expect(MyString, MyString, float, float);
  void expect(MyString, MyString, float, int);
  void expect(MyString, MyString, float, double);
  void expect(MyString, MyString, float, MyString);
  void expect(MyString, MyString, float, bool);

};

#endif /* defined(__Expected__) */
