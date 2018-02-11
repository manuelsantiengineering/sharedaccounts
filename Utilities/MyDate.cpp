//
//  MyDate.cpp
//  Lab03_CatalogoLibros
//
//  Created by Manuel E Santiago on 1/20/15.
//  Copyright (c) 2015 Manuel. All rights reserved.
//

#include "MyDate.h"

const MyString MONTHS[13] = {"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AGO", "SEP", "OCT", "NOV", "DEC"};

MyDate::MyDate(int day, int month, int year){
  if( isDateCorrect(day, month, year) ){
    this->day = day;
    this->month = month;
    this->year = year;
  }else{
    MyString e("Please verify the date values.");
    throw e;
  }
}
MyDate::MyDate(const MyDate & dateInstance){
    this->day = dateInstance.day;
    this->month = dateInstance.month;
    this->year = dateInstance.year;
}
MyDate::~MyDate(){
}
MyDate & MyDate::operator=(const MyDate & dateInstance){
    this->day = dateInstance.day;
    this->month = dateInstance.month;
    this->year = dateInstance.year;
    return(*this);
}

void MyDate::setDate(int d, int m, int y){
  if( isDateCorrect(d, m, y) ){
      this->day = d;
      this->month = m;
      this->year = y;
  }else{
    MyString e("Please verify the date values.");
    throw e;
  }
}
void MyDate::setDay(int d){
  if( isDateCorrect(d, this->month, this->year) ){
      this->day = d;
  }else{
    MyString e("Please verify the date values.");
    throw e;
  }
}
void MyDate::setMonth(int m){
  if( isDateCorrect(this->day, m, this->year) ){
      this->month = m;
  }else{
    MyString e("Please verify the date values.");
    throw e;
  }
}
void MyDate::setYear(int y){
  if( isDateCorrect(this->day, this->month, y) ){
      this->year = y;
  }else{
    MyString e("Please verify the date values.");
    throw e;
  }
}
int MyDate::getDay() const{
    return (this->day);
}
int MyDate::getMonth() const{
    return (this->month);
}
int MyDate::getYear() const{
    return (this->year);
}

MyString MyDate::dateToMyStringNumbers() const{
    MyString temporal = MyString(this->month) + "/" + MyString(this->day) + "/"+ MyString(this->year);
    return (temporal);
}

MyString MyDate::dateToMyString() const{
    MyString temporal = MONTHS[(this->month)] + "/" + MyString(this->day) + "/"+ MyString(this->year);
    return (temporal);
}

bool MyDate::isDateCorrect(const int d, const int m, const int y) const{
    bool isCorrect = true;
    bool isLeapYear = this->isLeapYear();
    /*
      1) Months are always between 1 and 12, days are always greater than 1, year has to be over 1908.
      2) On leap years, February can have up to 29 days and 28 in non-leap years.
      3) All the odd months before August, and all the even months after July have up to 31 days.
      4) All the even months (but February) before August, and all the odd months after July have up to 30 days.
    */

    if( ( m < 1 || m > 12 || d < 1 || y < 1908) ||
        ( m == 2 && ( (isLeapYear && d > 29 ) || (!isLeapYear && d > 28 ) ) ) ||
        ( d > 31 && ( (m%2 != 0 && m < 8) || (m%2 == 0 && m > 7) ) ) ||
        ( d > 30 && ( (m%2 == 0 && m < 8) || (m%2 != 0 && m > 7) ) )
      ){
      isCorrect = false;
    }

    return(isCorrect);
}

bool MyDate::isLeapYear() const{
  /*
    To determine whether a year is a leap year, follow these steps:
      1) If the year is evenly divisible by 4, go to step 2. Otherwise, go to step 5.
      2) If the year is evenly divisible by 100, go to step 3. Otherwise, go to step 4.
      3) If the year is evenly divisible by 400, go to step 4. Otherwise, go to step 5.
      4) The year is a leap year (it has 366 days).
      5) The year is not a leap year (it has 365 days).
  */
    return((this->year%400 == 0) || (this->year%100 != 0 && this->year%4 == 0));
}

bool MyDate::operator ==(const MyDate & dateInstance) const{
    return (this->day == dateInstance.day && this->month == dateInstance.month && this->year == dateInstance.year);
}
bool MyDate::operator !=(const MyDate & dateInstance) const{
    // return(this->day != dateInstance.day || this->month != dateInstance.month || this->year != dateInstance.year);
    return( !((*this) == dateInstance) );
}
bool MyDate::operator >=(const MyDate & dateInstance) const{
  return((this->year >= dateInstance.year) || (this->year == dateInstance.year && this->month > dateInstance.month) ||
  (this->year == dateInstance.year && this->month == dateInstance.month && this->day >= dateInstance.day));
}
bool MyDate::operator >(const MyDate & dateInstance) const{
    return((this->year > dateInstance.year) || (this->year == dateInstance.year && this->month > dateInstance.month) ||
    (this->year == dateInstance.year && this->month == dateInstance.month && this->day > dateInstance.day));
}
bool MyDate::operator <(const MyDate & dateInstance) const{
    return(!((*this) > dateInstance) && (*this) != dateInstance);
}
bool MyDate::operator <=(const MyDate & dateInstance) const{
  // return((this->year <= dateInstance.year) || (this->year == dateInstance.year && this->month < dateInstance.month) ||
  // (this->year == dateInstance.year && this->month == dateInstance.month && this->day <= dateInstance.day));
  return( (*this) < dateInstance || (*this) == dateInstance  );
}
ostream & operator<<(ostream & out, const MyDate dateInstance){
    out << dateInstance.month << "/" << dateInstance.day << "/" << dateInstance.year;
    return(out);
}
