//
//  MyDate.*
//
//  Created by Manuel E Santiago on 1/20/2015.
//  Copyright (c) 2015 Manuel. All rights reserved.
//

#ifndef __MYDATE__
#define __MYDATE__

#include <exception>

#include "MyString.h"

using namespace std;

class MyDate{
protected:
  int day, month, year;

public:
  MyDate(int day=1, int month=1, int year=1990);
  MyDate(const MyDate & dateInstance);
  ~MyDate();
  MyDate & operator=(const MyDate & dateInstance);

  void setDate(int d, int m, int y);
  void setDay(int d);
  void setMonth(int m);
  void setYear(int y);

  int getDay() const;
  int getMonth() const;
  int getYear() const;

  int getNumberOfDaysFromStartOfYear() const;
  int getNumberOfDaysUntilEndOfYear() const;

  int getNumberOfDaysUntilDate(const MyDate & dateInstance) const;

  void setDateAtNumberOfDaysFromDate(const MyDate & dateInstance, int amountOfDays);
  void setDateAtNumberOfDaysFromDate(const int d, const int m, const int y, int amountOfDays);
  void setDateAtNumberOfDaysFromStartOfYear(int amountOfDays);
  void setDateAtNumberOfDaysFromStartOfYear(int amountOfDays, int year);

  MyString dateToMyStringNumbers() const;
  MyString dateToMyString() const;

  bool isDateCorrect(const int, const int, const int) const;
  bool isLeapYear() const;
  bool isLeapYear(int year) const;

  bool operator ==(const MyDate & dateInstance) const;
  bool operator !=(const MyDate & dateInstance) const;
  bool operator >=(const MyDate & dateInstance) const;
  bool operator >(const MyDate & dateInstance) const;
  bool operator <=(const MyDate & dateInstance) const;
  bool operator <(const MyDate & dateInstance) const;

  friend ostream & operator<<(ostream & out, const MyDate dateInstance);
};

#endif /* defined(__MYDATE__) */
