//
//  Person.*
//
//  Created by Manuel E Santiago on 2/1/2018.
//  Copyright (c) 2018 Manuel. All rights reserved.
//

#ifndef PERSON_H
#define PERSON_H

#include <iostream>

#include "../Utilities/MyString.h"

const int MAX_AGE = 110;

class Person
{
protected:
  MyString name;
  MyString lastName;
  int age;

public:
  Person();
  Person(MyString name, MyString lastName, int age);
  ~Person();

  void setName(MyString name);
  MyString const getName();
  void setLastName(MyString lastName);
  MyString const getLastName();
  void setAge(int age);
  int const getAge();

  void operator=(const Person &person);

  bool operator==(const Person & person) const;
  bool operator!=(const Person & person) const;

};

#endif
