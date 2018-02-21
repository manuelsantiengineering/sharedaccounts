//
//  TimeAndDate.*
//
//  Created by Manuel E Santiago on 2/20/2018
//  Copyright (c) 2018 Manuel. All rights reserved.
//

#include "MyDate.h"
#include "MyClock.h"

class TimeAndDate: public MyDate, public MyClock {

public:
  TimeAndDate();
  TimeAndDate(int day, int mon, int yr, int hr, int min, int sec);
  TimeAndDate(MyDate date);
  TimeAndDate(MyClock time);
  TimeAndDate(MyDate date, MyClock time);
  TimeAndDate(const TimeAndDate &td );
  ~TimeAndDate();

  void operator=(const TimeAndDate &td);

  bool operator==(const TimeAndDate &td) const;
  bool operator!=(const TimeAndDate &td) const;

  bool operator >=(const TimeAndDate & td) const;
  bool operator >(const TimeAndDate & td) const;
  bool operator <=(const TimeAndDate & td) const;
  bool operator <(const TimeAndDate & td) const;

  friend ostream & operator<<(ostream & out, const TimeAndDate td);
};
