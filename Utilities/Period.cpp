#include "Period.h"

/*
  struct tm * timeinfo{tm_sec,tm_min,tm_hour,tm_mday,tm_mon,tm_year}
*/

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

MyDate Period::getStartDate() const
{  return( MyDate(this->startTimeInfo.tm_mday, this->startTimeInfo.tm_mon, this->startTimeInfo.tm_year) ); }
MyDate Period::getEndDate() const
{  return( MyDate(this->endTimeInfo.tm_mday, this->endTimeInfo.tm_mon, this->endTimeInfo.tm_year) ); }
MyTime Period::getStartTime() const
{  return( MyTime(this->startTimeInfo.tm_hour, this->startTimeInfo.tm_min, this->startTimeInfo.tm_sec) ); }
MyTime Period::getEndTime() const
{  return( MyTime(this->endTimeInfo.tm_hour, this->endTimeInfo.tm_min, this->endTimeInfo.tm_sec) ); }
