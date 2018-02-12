//
//  Period.*
//
//  Created by Manuel E Santiago on 2/11/2018.
//  Copyright (c) 2018 Manuel. All rights reserved.
//

#ifndef PERIOD_H
#define PERIOD_H

#include "MyTime.h"
#include "MyDate.h"

class Period
{
private:
  MyDate startDate,
  MyTime startTime;
  MyDate endDate,
  MyTime endTime;

  MyTime timePeriod;
  int yearsPeriod;
  int monthsPeriod;
  int daysPeriod;
  bool isDatePeriod;
  bool isTimePeriod;


public:
  Period();
  // Period(MyDate date);
  // Period(MyTime time);
  // Period(MyDate date, MyTime time);
  Period(const Period &period);
  ~Period();

  bool isPeriodStart() const; /* TRY PASSING EPOCH TIME */
  bool isPeriodEnd() const; /* TRY PASSING EPOCH TIME */

  MyDate getStartDate() const;
  MyDate getEndDate() const;
  MyTime getStartTime() const;
  MyTime getEndTime() const;

  MyDate getPeriodDate() const;
  MyTime getPeriodTime() const;
  int getPeriodYears() const;
  int getPeriodMonths() const;
  int getPeriodDays() const;
  int getPeriodHours() const;
  int getPeriodMinutes() const;

  void setPeriod(int years, int months, int days, int hours, int minutes, int seconds);
  void setPeriod(MyDate date, MyTime time);
  void setPeriodTime(MyTime time);
  void setPeriodDate(MyDate date);
  void setPeriodYears(int y);
  void setPeriodMonths(int m);
  void setPeriodDays(int d);
  void setPeriodHours(int h);
  void setPeriodMinutes(int m);
  void setPeriodSeconds(int s);

  void operator=(const Period &period);
  void operator=(const MyDate &date);
  void operator=(const MyTime &time);

  Period operator+(const Period & period) const;
  Period operator+(const MyDate &date);
  Period operator+(const MyTime &time);

  Period operator-(const Period & period) const;
  Period operator-(const MyDate &date);
  Period operator-(const MyTime &time);

  Period & operator+=(const Period & period);
  Period & operator+=(const MyDate &date);
  Period & operator+=(const MyTime &time);

  Period & operator-=(const Period & period);
  Period & operator-=(const MyDate &date);
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
  bool operator==(const MyDate &date) const;
  bool operator==(const MyTime &time) const;

  bool operator!=(const Period & period) const;
  bool operator!=(const MyDate &date) const;
  bool operator!=(const MyTime &time) const;

  bool operator>(const Period & period) const;
  bool operator>(const MyDate &date) const;
  bool operator>(const MyTime &time) const;
  friend bool operator>(const MyDate &date, const Period & period);
  friend bool operator>(const MyTime &time, const Period & period);

  bool operator>=(const Period & period) const;
  bool operator>=(const MyDate &date) const;
  bool operator>=(const MyTime &time) const;
  friend bool operator>=(const MyDate &date, const Period & period);
  friend bool operator>=(const MyTime &time, const Period & period);

  bool operator<(const Period & period) const;
  bool operator<(const MyDate &date) const;
  bool operator<(const MyTime &time) const;
  friend bool operator<(const MyDate &date, const Period & period);
  friend bool operator<(const MyTime &time, const Period & period);

  bool operator<=(const Period & period) const;
  bool operator<=(const MyDate &date) const;
  bool operator<=(const MyTime &time) const;
  friend bool operator<=(const MyDate &date, const Period & period);
  friend bool operator<=(const MyTime &time, const Period & period);

};

#endif
