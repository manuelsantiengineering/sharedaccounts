//
//  TimeAndDate.*
//
//  Created by Manuel E Santiago on 2/20/2018
//  Copyright (c) 2018 Manuel. All rights reserved.
//

#ifndef __TIMEANDDATE__
#define __TIMEANDDATE__

#include "MyDate.h"
#include "MyClock.h"

class TimeAndDate: public MyDate, public MyClock {

public:
  TimeAndDate();
  TimeAndDate(int day, int mon, int yr, int hr, int min, int sec);
  TimeAndDate(int day, int mon, int yr, int hr, int min, int sec, bool AM);
  TimeAndDate(MyDate date);
  TimeAndDate(MyClock time);
  TimeAndDate(MyDate date, MyClock td);
  TimeAndDate(const TimeAndDate &td );
  ~TimeAndDate();

  MyClock getTime() const;
  MyDate getDate() const;

  void setTime(MyClock td);
  void setDate(MyDate date);

  void setTimeAndDateAtNumberOfSecondsFromTimeAndDate(const TimeAndDate & td, int seconds);

  void operator=(const TimeAndDate &td);

  bool operator==(const TimeAndDate &td) const;
  bool operator!=(const TimeAndDate &td) const;

  bool operator >=(const TimeAndDate & td) const;
  bool operator >(const TimeAndDate & td) const;
  bool operator <=(const TimeAndDate & td) const;
  bool operator <(const TimeAndDate & td) const;

  friend std::ostream & operator<<(std::ostream & out, const TimeAndDate &td);
};

#endif /* defined(__TIMEANDDATE__) */
