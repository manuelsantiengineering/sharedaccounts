//
//  Period.*
//
//  Created by Manuel E Santiago on 2/11/2018.
//  Copyright (c) 2018 Manuel. All rights reserved.
//

#ifndef __PERIOD_H__
#define __PERIOD_H__

#include <ctime>

#include "TimeAndDate.h"

struct timeInfo{
  int sec, min, hr;
  bool AM;
  int day, mon, yr;
};

class Period
{
private:
  timeInfo startTimeInfo;
  timeInfo endTimeInfo;

public:
  Period();
  Period(MyDate startDate, MyDate endDate);
  Period(MyClock startTime, MyClock endTime);
  Period(MyDate startDate, MyDate endDate, MyClock startTime, MyClock endTime);
  Period(TimeAndDate start, TimeAndDate end);
  Period(const Period &period);
  ~Period();

  bool periodIsValid() const; //Period must be no more than a year
  bool isPeriodStart() const;
  bool isPeriodEnd() const;

  TimeAndDate getStartTimeAndDate() const;
  TimeAndDate getEndTimeAndDate() const;
  MyDate getStartDate() const;
  MyDate getEndDate() const;
  MyClock getStartTime() const;
  MyClock getEndTime() const;

  int getStartDay() const;
  int getStartMonth() const;
  int getStartYear() const;
  int getStartSecond() const;
  int getStartMinute() const;
  int getStartHour() const;
  bool isStartTimeAM() const;

  int getEndDay() const;
  int getEndMonth() const;
  int getEndYear() const;
  int getEndSecond() const;
  int getEndMinute() const;
  int getEndHour() const;
  bool isEndTimeAM() const;

  MyTime getPeriodTime() const;
  int getDaysBetweenStartDateAndEndDate() const;
  int getPeriodInSeconds() const;
  double getPeriodInMinutes() const;
  double getPeriodInHours() const;
  double getPeriodInDays() const;

  void setStartTimeAndDate(TimeAndDate start);
  void setStartTimeAndDate(MyDate date, MyClock ts);
  void setStartDate(MyDate date);
  void setStartDay(int d);
  void setStartMonth(int m);
  void setStartYear(int y);
  void setStartTime(MyClock ts);
  void setStartSecond(int s);
  void setStartMinute(int m);
  void setStartHour(int h);
  void setStartMeridiem(bool AM);

  void setEndTimeAndDate(TimeAndDate end);
  void setEndTimeAndDate(MyDate date, MyClock ts);
  void setEndDate(MyDate date);
  void setEndDay(int d);
  void setEndMonth(int m);
  void setEndYear(int y);
  void setEndTime(MyClock ts);
  void setEndSecond(int s);
  void setEndMinute(int m);
  void setEndHour(int h);
  void setEndMeridiem(bool AM);

  void setPeriod(MyDate startDate, MyDate endDate);
  void setPeriod(MyClock startTime, MyClock endTime);
  void setPeriod(MyDate startDate, MyDate endDate, MyClock startTime, MyClock endTime);
  void setPeriod(TimeAndDate start, TimeAndDate end);

  /*
    In the next getters and setters use the current time.
    For the setters, the start date and time will be assumed to be .now().
    The end date and time depends on the input.
  */
  void setStartTimeNow_UTC();
  void setStartTimeNow_Local();

  TimeAndDate getTimeDateToday_UTC() const;
  TimeAndDate getTimeDateToday_Local() const;

  void setPeriodDateFromNow_UTC(MyDate endDate);
  void setPeriodTimeFromNow_UTC(MyClock endTime);
  void setPeriodDateAndTimeFromNow_UTC(TimeAndDate end);
  void setPeriodDateAndTimeFromNow_UTC(MyDate endDate, MyClock endTime);
  void setPeriodDateAndTimeFromNow_UTC(int years, int months, int days, int hours, int minutes, int seconds, bool AM);
  void setPeriodDateFromNow_UTC(int d, int m, int y);
  void setPeriodTimeFromNow_UTC(int h, int m, int s, bool AM);


  void operator=(const Period &period);

  // Period operator+(const MyTime &time);
  // Period operator-(const MyTime &time);
  // Period & operator+=(const MyTime &time);
  // Period & operator-=(const MyTime &time);

  // Period operator*(const int) const;
  // Period operator*(const double) const;
  //
  // Period operator/(const int) const;
  // Period operator/(const double) const;
  //
  // Period operator*=(const int);
  // Period operator*=(const double);
  //
  // Period operator/=(const int);
  // Period operator/=(const double);

  bool operator==(const Period & period) const;
  bool operator!=(const Period & period) const;
  bool operator>(const Period & period) const;
  bool operator>=(const Period & period) const;
  bool operator<(const Period & period) const;
  bool operator<=(const Period & period) const;

  friend std::ostream & operator<<(std::ostream & out, const Period &period);
};

#endif
