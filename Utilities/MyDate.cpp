//
//  MyDate.cpp
//
//  Created by Manuel E Santiago on 1/20/2018
//  Copyright (c) 2015 Manuel. All rights reserved.
//

#include "MyDate.h"

static const MyString MONTHS[13] = {"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AGO", "SEP", "OCT", "NOV", "DEC"};

MyDate::MyDate(int day, int month, int year){
  this->day = day;
  this->month = month;
  this->year = year;
  if( !this->isDateCorrect(day, month, year) ){
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
  if(this->isDateCorrect(d, m, y) ){
      this->day = d;
      this->month = m;
      this->year = y;
  }else{
    MyString e("Please verify the date values.");
    throw e;
  }
}
void MyDate::setDay(int d){
  if(this->isDateCorrect(d, this->month, this->year) ){
      this->day = d;
  }else{
    MyString e("Please verify the date values.");
    throw e;
  }
}
void MyDate::setMonth(int m){
  if(this->isDateCorrect(this->day, m, this->year) ){
      this->month = m;
  }else{
    MyString e("Please verify the date values.");
    throw e;
  }
}
void MyDate::setYear(int y){
  if(this->isDateCorrect(this->day, this->month, y) ){
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
int MyDate::getNumberOfDaysFromStartOfYear() const{
  /*
    The amount of days is 1 day before the current day.
    Example: The amount of days that have passed from the years
    on January 2 is 1 day. So, it is assumed that 1 day is 24 hrs and
    the time is 00:00:00.
  */

  int a = (this->isLeapYear()) ? 29 : 28;
  const int days_in_month[13] = {0, 31, a, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int amountOfDays = this->day-1;
  for(int i = 1; i < this->month; i++){ amountOfDays+= days_in_month[i];  }
  return(amountOfDays);
}
int MyDate::getNumberOfDaysUntilEndOfYear() const{
  /*
    The amount of days starts counting 1 day before the current day.
    Example: The amount of days until the end of year on December 31
    is 1 day. So, it is assumed that 1 day is 24 hrs and the time is 00:00:00.
  */
  int a = (this->isLeapYear()) ? 29 : 28;
  const int days_in_month[13] = {0, 31, a, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int amountOfDays = days_in_month[this->month]-this->day+1;
  for(int i = (this->month+1); i < 13; i++){ amountOfDays+= days_in_month[i];  }
  return(amountOfDays);
}
int MyDate::getNumberOfDaysUntilDate(const MyDate & dateInstance) const{
  int amountOfDays = 0;

  if(this->year > dateInstance.year){
    for(int i = (dateInstance.year+1); i < this->year; i++){
      amountOfDays += (this->isLeapYear(dateInstance.year+i)) ? 366 : 365;
    }
    amountOfDays += this->getNumberOfDaysFromStartOfYear();
    amountOfDays += dateInstance.getNumberOfDaysUntilEndOfYear();
    amountOfDays *= -1;
  }else if(this->year < dateInstance.year){
    for(int i = (this->year+1); i < dateInstance.year; i++){
      amountOfDays += (this->isLeapYear(this->year+i)) ? 366 : 365;
    }
    amountOfDays += dateInstance.getNumberOfDaysFromStartOfYear();
    amountOfDays += this->getNumberOfDaysUntilEndOfYear();
  }else {
    int a = (isLeapYear()) ? 29 : 28;
    int days_in_month[13] = {0, 31, a, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(this->month < dateInstance.month){
      for(int i = (this->month+1); i < dateInstance.month; i++){
        amountOfDays += days_in_month[i];
      }

      amountOfDays += dateInstance.day;
      amountOfDays += days_in_month[this->month] - this->day;
    }else if(this->month > dateInstance.month){
      for(int i = (dateInstance.month+1); i < this->month; i++){
        amountOfDays += days_in_month[i];
      }

      amountOfDays += this->day;
      amountOfDays += days_in_month[dateInstance.month] - dateInstance.day;
      amountOfDays *= -1;
    }else{
      amountOfDays += dateInstance.day - this->day;
    }
  }

  return (amountOfDays);
}
void MyDate::setDateAtNumberOfDays(int amountOfDays){
  int a;
  int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int yearsCount = 0;
  int startMonth = this->month;
  int startYear = this->year;
  bool foundDate = false;

  // std::cout << "\t Start: " << amountOfDays << std::endl;

  if(amountOfDays > 0){
    amountOfDays += this->day;
    // std::cout << "\t 02: " << amountOfDays << std::endl;
    while(!foundDate){
      a = (this->isLeapYear(startYear + yearsCount)) ? 29 : 28;
      days_in_month[2] = a;
      for(int i = startMonth; i < 13; i++){
        if(amountOfDays == 0){
          this->day = 1;
          this->month = i;
          this->year = startYear + yearsCount;
          foundDate = true;
          break;
        }else if(amountOfDays >= days_in_month[i]){
          amountOfDays -= days_in_month[i];
        }else{
          this->day = amountOfDays;
          this->month = i;
          this->year = startYear + yearsCount;
          foundDate = true;
          break;
        }
      }
      if(!foundDate){
        yearsCount++;
        startMonth = 1;
      }
    }
  }else if(amountOfDays < 0){
    // bool isFirstIteration = true;
    amountOfDays += this->day-1;
    // std::cout << "\t -00Days: " << amountOfDays << std::endl;
    if(amountOfDays > 0){
      this->day = amountOfDays+1;
    }else if(amountOfDays == 0){
      if(this->month == 1){
        this->month = 12;
        this->year = this->year - 1;
        this->day = days_in_month[this->month];
      }else{
        this->month -= 1;
        this->day = days_in_month[this->month];
      }
    }else {
      startMonth--;
      while(!foundDate){
        a = (this->isLeapYear(startYear + yearsCount)) ? 29 : 28;
        days_in_month[2] = a;
        // std::cout << "\t -01Days: " << amountOfDays << std::endl;
        for(int i = startMonth; i > 0; i--){
          if(amountOfDays == 0){
            this->day = days_in_month[i];
            this->month = i;
            this->year = startYear - yearsCount;
            foundDate = true;
            // std::cout << "\t -03Days: " << amountOfDays << std::endl;
            break;
          }else if(abs(amountOfDays) >= days_in_month[i]){
            amountOfDays += (days_in_month[i]);
            // std::cout << "\t -02Days: " << amountOfDays << std::endl;
          }else{
            this->day = days_in_month[i] + amountOfDays + 1;
            this->month = i;
            this->year = startYear - yearsCount;
            // std::cout << "\t -04Days: " << amountOfDays << std::endl;
            foundDate = true;
            break;
          }
        }
        if(!foundDate){
          yearsCount++;
          startMonth = 12;
        }

      }
    }
  }
}

void MyDate::setDateAtNumberOfDaysFromDate(const MyDate & dateInstance, int amountOfDays){
  int a;
  int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int yearsCount = 0;
  int startMonth = dateInstance.month;
  int startYear = dateInstance.year;
  bool foundDate = false;

  if(amountOfDays > 0){
    amountOfDays += dateInstance.day;
    // std::cout << "\t 02: " << amountOfDays << std::endl;
    while(!foundDate){
      a = (this->isLeapYear(startYear + yearsCount)) ? 29 : 28;
      days_in_month[2] = a;
      for(int i = startMonth; i < 13; i++){
        if(amountOfDays == 0){
          this->day = 1;
          this->month = i;
          this->year = startYear + yearsCount;
          foundDate = true;
          break;
        }else if(amountOfDays >= days_in_month[i]){
          amountOfDays -= days_in_month[i];
        }else{
          this->day = amountOfDays;
          this->month = i;
          this->year = startYear + yearsCount;
          foundDate = true;
          break;
        }
      }
      if(!foundDate){
        yearsCount++;
        startMonth = 1;
      }
    }
  }else if(amountOfDays < 0){
    // bool isFirstIteration = true;
    amountOfDays += dateInstance.day-1;
    // std::cout << "\t -00Days: " << amountOfDays << std::endl;
    if(amountOfDays > 0){
      this->day = amountOfDays+1;
    }else if(amountOfDays == 0){
      if(dateInstance.month == 1){
        this->month = 12;
        this->year = dateInstance.year - 1;
        this->day = days_in_month[this->month];
      }else{
        this->month -= 1;
        this->day = days_in_month[this->month];
      }
    }else {
      startMonth--;
      while(!foundDate){
        a = (this->isLeapYear(startYear + yearsCount)) ? 29 : 28;
        days_in_month[2] = a;
        // std::cout << "\t -01Days: " << amountOfDays << std::endl;
        for(int i = startMonth; i > 0; i--){
          if(amountOfDays == 0){
            this->day = days_in_month[i];
            this->month = i;
            this->year = startYear - yearsCount;
            foundDate = true;
            // std::cout << "\t -03Days: " << amountOfDays << std::endl;
            break;
          }else if(abs(amountOfDays) >= days_in_month[i]){
            amountOfDays += (days_in_month[i]);
            // std::cout << "\t -02Days: " << amountOfDays << std::endl;
          }else{
            this->day = days_in_month[i] + amountOfDays + 1;
            this->month = i;
            this->year = startYear - yearsCount;
            // std::cout << "\t -04Days: " << amountOfDays << std::endl;
            foundDate = true;
            break;
          }
        }
        if(!foundDate){
          yearsCount++;
          startMonth = 12;
        }
      }
    }
  }else if(amountOfDays == 0){
    this->month = dateInstance.month;
    this->year = dateInstance.year;
    this->day = dateInstance.day;
  }
}
void MyDate::setDateAtNumberOfDaysFromDate(const int d, const int m, const int y, int amountOfDays){
  int a;
  int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int yearsCount = 0;
  int startMonth = m;

  if(amountOfDays == 0){
    this->setDate(d,m,y);
  }
  else if(amountOfDays > 0){
    while(amountOfDays != -1){
      a = (this->isLeapYear(y + yearsCount)) ? 29 : 28;
      days_in_month[2] = a;
      for(int i = startMonth; i < 13; i++){
        if(amountOfDays == 0){
          this->day = 1;
          this->month = i;
          this->year = y + yearsCount;
          amountOfDays = -1;
          break;
        }else if(amountOfDays >= days_in_month[i]){
          amountOfDays -= (days_in_month[i]);
        }else{
          this->day = amountOfDays+1;
          this->month = i;
          this->year = y + yearsCount;
          amountOfDays = -1;
          break;
        }
      }
      if(amountOfDays != -1){
        yearsCount++;
        startMonth = 1;
      }
    }
  }else{
    while(amountOfDays != 1){
      a = (this->isLeapYear(y + yearsCount)) ? 29 : 28;
      days_in_month[2] = a;
      for(int i = startMonth; i < 13; i++){
        if(amountOfDays == 0){
          this->day = 1;
          this->month = i;
          this->year = y - yearsCount;
          amountOfDays = 1;
          break;
        }else if(abs(amountOfDays) >= days_in_month[i]){
          amountOfDays += (days_in_month[i]);
        }else{
          if(i == 1){ //? 12 : i;
            this->day = days_in_month[12] + amountOfDays;
            this->month = 12;
            this->year = y - yearsCount - 1;
          }else{
            this->day = days_in_month[12] + amountOfDays;
            this->month = 12;
            this->year = y - yearsCount;
          }
          amountOfDays = 1;
          break;
        }
      }
      if(amountOfDays != 1){
        yearsCount++;
        startMonth = 1;
      }
    }
  }
}
void MyDate::setDateAtNumberOfDaysFromStartOfYear(int amountOfDays){
  int a, maxDays;
  if(this->isLeapYear())
  {
    a = 29;
    maxDays = 365;
  }else{
    a = 28;
    maxDays = 364;
  }
  if( amountOfDays <= maxDays && amountOfDays >= 0 && this->isDateCorrect(1, 1, this->year) ){
    const int days_in_month[13] = {0, 31, a, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i = 1; i < 13; i++){
      if(amountOfDays == 0){
        this->day = 1;
        this->month = i;
        break;
      }else if(amountOfDays >= days_in_month[i]){
        amountOfDays -= (days_in_month[i]);
      }else{
        this->day = amountOfDays+1;
        this->month = i;
        break;
      }
    }
  }else{
    MyString e("Please verify the amount of days from start of year value.");
    throw e;
  }
}
void MyDate::setDateAtNumberOfDaysFromStartOfYear(int amountOfDays, int year){
  this->year = year;
  int a, maxDays;
  if(this->isLeapYear())
  {
    a = 29;
    maxDays = 365;
  }else{
    a = 28;
    maxDays = 364;
  }
  if( amountOfDays <= maxDays && amountOfDays >= 0 && this->isDateCorrect(1, 1, year) ){
    const int days_in_month[13] = {0, 31, a, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i = 1; i < 13; i++){
      if(amountOfDays == 0){
        this->day = 1;
        this->month = i;
        break;
      }else if(amountOfDays >= days_in_month[i]){
        amountOfDays -= (days_in_month[i]);
      }else{
        this->day = amountOfDays+1;
        this->month = i;
        break;
      }
    }
  }else{
    MyString e("Please verify the amount of days from start of year value.");
    throw e;
  }
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
  int a = (isLeapYear()) ? 29 : 28;
  const int days_in_month[13] = {0, 31, a, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  /*
    1) Months are always between 1 and 12, days are always greater than 1, year has to be over 1908.
    2) On leap years, February can have up to 29 days and 28 in non-leap years.
    3) All the odd months before August, and all the even months after July have up to 31 days.
    4) All the even months (but February) before August, and all the odd months after July have up to 30 days.
  */
  if( ( m < 1 || m > 12 || d < 1 || y < 1908) || (d > days_in_month[m]) )
  { isCorrect = false;  }
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
bool MyDate::isLeapYear(int year) const{
  return((year%400 == 0) || (year%100 != 0 && year%4 == 0));
}
bool MyDate::operator ==(const MyDate & dateInstance) const{
  return (this->day == dateInstance.day && this->month == dateInstance.month && this->year == dateInstance.year);
}
bool MyDate::operator !=(const MyDate & dateInstance) const{
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
  return( (*this) < dateInstance || (*this) == dateInstance  );
}
std::ostream & operator<<(std::ostream & out, const MyDate &dateInstance){
  out << dateInstance.month << "/" << dateInstance.day << "/" << dateInstance.year;
  return(out);
}
