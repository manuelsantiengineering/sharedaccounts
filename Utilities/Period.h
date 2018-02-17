//
//  Period.*
//
//  Created by Manuel E Santiago on 2/11/2018.
//  Copyright (c) 2018 Manuel. All rights reserved.
//

#ifndef PERIOD_H
#define PERIOD_H

#include <chrono>

#include "MyTime.h"
#include "MyDate.h"

class Period
{
private:
  // MyDate startDate,
  // MyTime startTime;
  // MyDate endDate,
  // MyTime endTime;
  //
  // MyTime timePeriod;
  // int yearsPeriod;
  // int monthsPeriod;
  // int daysPeriod;
  // bool isDatePeriod;
  // bool isTimePeriod;

  struct tm startTimeInfo;
  struct tm endTimeInfo;


public:
  Period();
  Period(MyDate startDate, MyDate endDate);
  Period(MyTime startTime, MyTime endTime);
  Period(MyDate startDate, MyDate endDate, MyTime startTime, MyTime endTime);
  Period(const Period &period);
  ~Period();

  // bool isPeriodStart() const; /* TRY PASSING EPOCH TIME */
  // bool isPeriodEnd() const; /* TRY PASSING EPOCH TIME */

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

  double getPeriodInDays() const;
  double getPeriodInMonths() const;
  double getPeriodInYears() const;
  double getPeriodInSeconds() const;
  double getPeriodInMinutes() const;
  double getPeriodInHours() const;

  void setStartDate(MyDate date);
  void setStartDay(MyString d);
  void setStartMonth(MyString m);
  void setStartYear(MyString y);
  void setStartDay(int d);
  void setStartMonth(int m);
  void setStartYear(int y);
  void setStartSecond(int s);
  void setStartMinute(int m);
  void setStartHour(int h);

  void setEndDate(MyDate date);
  void setEndDay(MyString d);
  void setEndMonth(MyString m);
  void setEndYear(MyString y);
  void setEndDay(int d);
  void setEndMonth(int m);
  void setEndYear(int y);
  void setEndSecond(int s);
  void setEndMinute(int m);
  void setEndHour(int h);

  void setPeriod(MyDate startDate, MyDate endDate);
  void setPeriod(MyTime startTime, MyTime endTime);
  void setPeriod(MyDate startDate, MyDate endDate, MyTime startTime, MyTime endTime);
  /*
    In the next setters the start date and time will be assumed to be .now().
    The end date and time depends on the input.
  */
  void setPeriod(MyDate endDate);
  void setPeriod(MyTime endTime);
  void setPeriod(MyDate endDate, MyTime endTime);
  void setPeriod(int years, int months, int days, int hours, int minutes, int seconds);
  void setPeriodYears(int y);
  void setPeriodMonths(int m);
  void setPeriodDays(int d);
  void setPeriodHours(int h);
  void setPeriodMinutes(int m);
  void setPeriodSeconds(int s);

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
