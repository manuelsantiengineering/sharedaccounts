//
//  Period.*
//
//  Created by Manuel E Santiago on 2/11/2018.
//  Copyright (c) 2018 Manuel. All rights reserved.
//

#ifndef PERIOD_H
#define PERIOD_H

#include <ctime>

#include "TimeAndDate.h"

class Period
{
private:
  struct tm startTimeInfo;
  struct tm endTimeInfo;

public:
  Period();
  Period(MyDate startDate, MyDate endDate);
  Period(MyTime startTime, MyTime endTime);
  Period(MyDate startDate, MyDate endDate, MyTime startTime, MyTime endTime);
  Period(TimeAndDate start, TimeAndDate end);
  Period(const Period &period);
  ~Period();

  // bool isPeriodStart() const; /* TRY PASSING EPOCH TIME */
  // bool isPeriodEnd() const; /* TRY PASSING EPOCH TIME */

  TimeAndDate getStartTimeAndDate() const;
  TimeAndDate getEndTimeAndDate() const;
  MyDate getStartDate() const;
  MyDate getEndDate() const;
  MyTime getStartTime() const;
  MyTime getEndTime() const;

  int getStartDay() const;
  int getStartMonth() const;
  int getStartYear() const;
  int getStartSecond() const;
  int getStartMinute() const;
  int getStartHour() const;

  int getEndDay() const;
  int getEndMonth() const;
  int getEndYear() const;
  int getEndSecond() const;
  int getEndMinute() const;
  int getEndHour() const;

  MyTime getPeriodTime() const;
  int getPeriodInSeconds() const;
  int getDaysBetweenStartDateAndEndDate() const;

  double getPeriodInMinutes() const;
  double getPeriodInHours() const;
  double getPeriodInDays() const;

  void setStartDate(MyDate date);
  void setStartDay(int d);
  void setStartMonth(int m);
  void setStartYear(int y);
  void setStartSecond(int s);
  void setStartMinute(int m);
  void setStartHour(int h);

  void setEndDate(MyDate date);
  void setEndDay(int d);
  void setEndMonth(int m);
  void setEndYear(int y);
  void setEndSecond(int s);
  void setEndMinute(int m);
  void setEndHour(int h);

  void setPeriod(MyDate startDate, MyDate endDate);
  void setPeriod(MyTime startTime, MyTime endTime);
  void setPeriod(MyDate startDate, MyDate endDate, MyTime startTime, MyTime endTime);

  void setStartTimeNow_UTC();
  void setStartTimeNow_Local();
  /*
    In the next getters and setters use the current time.
    For the setters, the start date and time will be assumed to be .now().
    The end date and time depends on the input.
  */
  // long int getSecondsSinceEpoch() const;
  TimeAndDate getTimeDateToday_UTC() const;
  TimeAndDate getTimeDateToday_Local() const;

  void setPeriodDateFromNow(MyDate endDate);
  void setPeriodTimeFromNow(MyTime endTime);
  void setPeriodDateAndTimeFromNow(MyDate endDate, MyTime endTime);
  void setPeriodDateAndTimeFromNow(int years, int months, int days, int hours, int minutes, int seconds);
  void setPeriodYearsFromNow(int y);
  void setPeriodMonthsFromNow(int m);
  void setPeriodDaysFromNow(int d);
  void setPeriodHoursFromNow(int h);
  void setPeriodMinutesFromNow(int m);
  void setPeriodSecondsFromNow(int s);

  void operator=(const Period &period);

  Period operator+(const Period & period) const;
  Period operator+(const MyTime &time);

  Period operator-(const Period & period) const;
  Period operator-(const MyTime &time);

  Period & operator+=(const Period & period);
  Period & operator+=(const MyTime &time);

  Period & operator-=(const Period & period);
  Period & operator-=(const MyTime &time);

  Period operator*(const int) const;
  Period operator*(const double) const;

  Period operator/(const int) const;
  Period operator/(const double) const;

  Period operator*=(const int);
  Period operator*=(const double);

  Period operator/=(const int);
  Period operator/=(const double);

  bool operator==(const Period & period) const;
  bool operator!=(const Period & period) const;
  bool operator>(const Period & period) const;
  bool operator>=(const Period & period) const;
  bool operator<(const Period & period) const;
  bool operator<=(const Period & period) const;

};

#endif
