#include "Period.h"

/*
  Period has the number of seconds on January 1, 1990 at 00:00:00
*/

static const int SECONDS_IN_DAY = 86400;
static const int SECONDS_IN_HOUR = 3600;
static const int MINUTES_IN_DAY = 1440;

Period::Period(){
  this->startTimeInfo = {1,1,1,1,1,1};
  this->endTimeInfo = {1,1,1,1,1,1};
}
Period::Period(MyDate startDate, MyDate endDate){
  this->startTimeInfo = {1,1,1,startDate.getDay(),startDate.getMonth(),startDate.getYear()};
  this->endTimeInfo = {1,1,1,endDate.getDay(),endDate.getMonth(),endDate.getYear()};
}
Period::Period(MyTime startTime, MyTime endTime){
  this->startTimeInfo = {startTime.getSeconds(),startTime.getMinutes(),startTime.getHours(),
    1,1,1};
  this->endTimeInfo = {endTime.getSeconds(),endTime.getMinutes(),endTime.getHours(),
    1,1,1};
}
Period::Period(MyDate startDate, MyDate endDate, MyTime startTime, MyTime endTime){
  this->startTimeInfo = {startTime.getSeconds(),startTime.getMinutes(),startTime.getHours(),
    startDate.getDay(),startDate.getMonth(),startDate.getYear()};
  this->endTimeInfo = {endTime.getSeconds(),endTime.getMinutes(),endTime.getHours(),
    endDate.getDay(),endDate.getMonth(),endDate.getYear()};
}
Period::Period(const Period &period){
  this->startTimeInfo = period.startTimeInfo;
  this->endTimeInfo = period.endTimeInfo;
}
Period::~Period(){}

int Period::getTimeNow_Seconds() const{
  return(0);
}

MyDate Period::getStartDate() const
{  return( MyDate(this->startTimeInfo.tm_mday, this->startTimeInfo.tm_mon, this->startTimeInfo.tm_year) ); }
MyDate Period::getEndDate() const
{  return( MyDate(this->endTimeInfo.tm_mday, this->endTimeInfo.tm_mon, this->endTimeInfo.tm_year) ); }
MyTime Period::getStartTime() const
{  return( MyTime(this->startTimeInfo.tm_hour, this->startTimeInfo.tm_min, this->startTimeInfo.tm_sec) ); }
MyTime Period::getEndTime() const
{  return( MyTime(this->endTimeInfo.tm_hour, this->endTimeInfo.tm_min, this->endTimeInfo.tm_sec) ); }

MyTime Period::getPeriodTime() const{
  return( MyTime(0,0,this->getPeriodInSeconds()) );
}
int Period::getPeriodInSeconds() const{
  int totalSeconds = SECONDS_IN_DAY*this->getDaysBetweenStartDateAndEndDate();
  MyTime startTime(this->getStartTime());
  MyTime endTime(this->getEndTime());
  totalSeconds += endTime.getTimeInSeconds() - startTime.getTimeInSeconds();
  return(totalSeconds);
}
int Period::getDaysBetweenStartDateAndEndDate() const{
  MyDate startDate(this->getStartDate());
  return(startDate.getNumberOfDaysUntilDate(this->getEndDate()) );
}
double Period::getPeriodInMinutes() const{ return( this->getPeriodInSeconds()/60 ); }
double Period::getPeriodInHours() const{  return( this->getPeriodInMinutes()/60 );  }
double Period::getPeriodInDays() const{  return( this->getPeriodInMinutes()/MINUTES_IN_DAY );  }

int Period::getStartDay() const{  return(this->startTimeInfo.tm_mday);  }
int Period::getStartMonth() const{  return(this->startTimeInfo.tm_mon); }
int Period::getStartYear() const{ return(this->startTimeInfo.tm_year);  }
int Period::getStartSecond() const{ return(this->startTimeInfo.tm_sec); }
int Period::getStartMinute() const{ return(this->startTimeInfo.tm_min); }
int Period::getStartHour() const{ return(this->startTimeInfo.tm_hour);  }

int Period::getEndDay() const{  return(this->endTimeInfo.tm_mday);  }
int Period::getEndMonth() const{  return(this->endTimeInfo.tm_mon); }
int Period::getEndYear() const{ return(this->endTimeInfo.tm_year);  }
int Period::getEndSecond() const{ return(this->endTimeInfo.tm_sec); }
int Period::getEndMinute() const{ return(this->endTimeInfo.tm_min); }
int Period::getEndHour() const{ return(this->endTimeInfo.tm_hour);  }

void Period::setPeriod(MyDate startDate, MyDate endDate){
  this->startTimeInfo.tm_mday = startDate.getDay();
  this->startTimeInfo.tm_mon = startDate.getMonth();
  this->startTimeInfo.tm_year = startDate.getYear();
  this->endTimeInfo.tm_mday = endDate.getDay();
  this->endTimeInfo.tm_mon = endDate.getMonth();
  this->endTimeInfo.tm_year = endDate.getYear();
}
void Period::setPeriod(MyTime startTime, MyTime endTime){
  this->startTimeInfo.tm_hour = startTime.getHours();
  this->startTimeInfo.tm_min = startTime.getMinutes();
  this->startTimeInfo.tm_sec = startTime.getSeconds();
  this->endTimeInfo.tm_hour = endTime.getHours();
  this->endTimeInfo.tm_min = endTime.getMinutes();
  this->endTimeInfo.tm_sec = endTime.getSeconds();
}
void Period::setPeriod(MyDate startDate, MyDate endDate, MyTime startTime, MyTime endTime){
  this->startTimeInfo = {startTime.getSeconds(),startTime.getMinutes(),startTime.getHours(),
    startDate.getDay(),startDate.getMonth(),startDate.getYear()};
  this->endTimeInfo = {endTime.getSeconds(),endTime.getMinutes(),endTime.getHours(),
    endDate.getDay(),endDate.getMonth(),endDate.getYear()};
}
// MyDate getDateToday() const{
//
// }
// MyTime getTimeToday() const{
//
// }
void setPeriodDateFromNow(MyDate endDate){

}
void setPeriodTimeFromNow(MyTime endTime){

}
