
#ifndef PERSON_H
#define PERSON_H

#include <iostream>

#include "MyString.h"

using namespace std;
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
  friend bool operator==(const Person & personA, const Person & personB);

  bool operator!=(const Person & person) const;
  friend bool operator!=(const Person & personA, const Person & personB);

};

#endif
