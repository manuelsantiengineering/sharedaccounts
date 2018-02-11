//
//  MyTime.*
//
//  Created by Manuel E Santiago on 1/20/15.
//  Copyright (c) 2015 Manuel. All rights reserved.
//

#ifndef __MyTime__
#define __MyTime__

#include <exception>

#include "MyString.h"

class MyTime{
private:
  int seconds, minutes, hours;
  bool isAM;

public:
  MyTime(int hours = 12, int minutes = 0, int seconds = 0, bool isAM = true);
  MyTime(const MyTime & timeInstance);
  ~MyTime();
  MyTime & operator=(const MyTime & timeInstance);

  void setTime(int h, int m, int s, bool isAM);
  void setSeconds(int seconds);
  void setMinutes(int minutes);
  void setHours(int hours);

  int getSeconds() const;
  int getMinutes() const;
  int getHours() const;
  bool isAm() const;

  bool isSecondsCorrect(int s);
  bool isMinutesCorrect(int m);
  bool isHoursCorrect(int h);
  bool isTimeCorrect(int h, int m, int s);

  MyString timeToString() const;
  MyString timeToString_Seconds() const;

  bool operator == (const MyTime & timeInstance) const;
  bool operator != (const MyTime & timeInstance) const;
  bool operator >= (const MyTime & timeInstance) const;
  bool operator > (const MyTime & timeInstance) const;
  bool operator <= (const MyTime & timeInstance) const;
  bool operator < (const MyTime & timeInstance) const;

  friend ostream & operator<<(ostream & out, const MyTime & timeInstance);

};

#endif /* defined(__MyTime__) */
