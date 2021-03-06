//
//  MyTime.*
//
//  Created by Manuel E Santiago on 1/20/2018.
//  Copyright (c) 2018 Manuel. All rights reserved.


#ifndef __MYTIME__
#define __MYTIME__

#include <exception>
#include <math.h>

#include "MyString.h"

class MyTime{
private:
  void setToStandardTime();

protected:
  int seconds;
  int minutes;
  int hours;

public:
  MyTime();
  MyTime(int hours, int minutes, int seconds);
  MyTime(const MyTime & timeInstance);
  ~MyTime();
  MyTime & operator=(const MyTime & timeInstance);

  void setTime(int h, int m, int s);
  void setSeconds(int seconds);
  void setMinutes(int minutes);
  void setHours(int hours);

  int getSeconds() const;
  int getMinutes() const;
  int getHours() const;

  int getTimeInSeconds() const;

  MyString timeToString() const;
  MyString timeToString_Seconds() const;

  bool operator == (const MyTime & timeInstance) const;
  bool operator != (const MyTime & timeInstance) const;
  bool operator >= (const MyTime & timeInstance) const;
  bool operator > (const MyTime & timeInstance) const;
  bool operator <= (const MyTime & timeInstance) const;
  bool operator < (const MyTime & timeInstance) const;

  MyTime operator-(const MyTime & timeInstance) const;
  MyTime operator+(const MyTime & timeInstance) const;

  MyTime & operator+=(const MyTime & timeInstance);
  MyTime & operator-=(const MyTime & timeInstance);

  friend ostream & operator<<(ostream & out, const MyTime & timeInstance);

};

#endif /* defined(__MYTIME__) */
