
#ifndef PERSON_H
#define PERSON_H

#include <iostream>

#include "MyString.h"

using namespace std;

class Person
{
private:
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

};

#endif
