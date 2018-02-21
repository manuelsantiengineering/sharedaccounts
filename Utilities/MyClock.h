//
//  MyClock.*
//
//  Created by Manuel E Santiago on 2/17/2018.
//  Copyright (c) 2018 Manuel. All rights reserved.
//

// const
//
// #ifndef _WIN32
//
// #else __linux__
//
// #endif

#ifndef __MYCLOCK__
#define __MYCLOCK__

#include <exception>

#include "MyTime.h"
#include "MyString.h"

class MyClock : public MyTime{
protected:
  bool isAM;

public:
  MyClock();
  MyClock(int hours, int minutes, int seconds);
  MyClock(int hours, int minutes, int seconds, bool isAM);
  MyClock(const MyClock & timeInstance);
  ~MyClock();
  MyClock & operator=(const MyClock & timeInstance);

  void setTime(int h, int m, int s, bool isAM);
  void setSeconds(int seconds);
  void setMinutes(int minutes);
  void setHours(int hours);

  bool isAm() const;

  bool isSecondsCorrect(int s);
  bool isMinutesCorrect(int m);
  bool isHoursCorrect(int h);
  bool isTimeCorrect(int h, int m, int s);

  MyString timeToString() const;
  MyString timeToString_Seconds() const;
  MyString timeToStringMilitary() const;
  MyString timeToStringMilitary_Seconds() const;

  bool operator == (const MyClock & timeInstance) const;
  bool operator != (const MyClock & timeInstance) const;
  bool operator >= (const MyClock & timeInstance) const;
  bool operator > (const MyClock & timeInstance) const;
  bool operator <= (const MyClock & timeInstance) const;
  bool operator < (const MyClock & timeInstance) const;

  friend ostream & operator<<(ostream & out, const MyClock & timeInstance);

};

#endif /* defined(__MyClock__) */
