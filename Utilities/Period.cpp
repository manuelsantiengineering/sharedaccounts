#include "Period.h"

static const int SECONDS_IN_DAY = 86400;
// static const int SECONDS_IN_HOUR = 3600;
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
Period::Period(TimeAndDate start, TimeAndDate end){
  this->startTimeInfo = {start.getSeconds(),start.getMinutes(),start.getHours(),
    start.getDay(),start.getMonth(),start.getYear()};
  this->endTimeInfo = {end.getSeconds(),end.getMinutes(),end.getHours(),
    end.getDay(),end.getMonth(),end.getYear()};
}
Period::Period(const Period &period){
  this->startTimeInfo = period.startTimeInfo;
  this->endTimeInfo = period.endTimeInfo;
}
Period::~Period(){}

TimeAndDate Period::getStartTimeAndDate() const{
  return( TimeAndDate(this->startTimeInfo.tm_mday, this->startTimeInfo.tm_mon, this->startTimeInfo.tm_year,
            this->startTimeInfo.tm_hour, this->startTimeInfo.tm_min, this->startTimeInfo.tm_sec ) );
}
TimeAndDate Period::getEndTimeAndDate() const{
  return( TimeAndDate(this->endTimeInfo.tm_mday, this->endTimeInfo.tm_mon, this->endTimeInfo.tm_year,
            this->endTimeInfo.tm_hour, this->endTimeInfo.tm_min, this->endTimeInfo.tm_sec ) );
}
MyDate Period::getStartDate() const
{  return( MyDate(this->startTimeInfo.tm_mday, this->startTimeInfo.tm_mon, this->startTimeInfo.tm_year) ); }
MyDate Period::getEndDate() const
{  return( MyDate(this->endTimeInfo.tm_mday, this->endTimeInfo.tm_mon, this->endTimeInfo.tm_year) ); }
MyTime Period::getStartTime() const
{  return( MyTime(this->startTimeInfo.tm_hour, this->startTimeInfo.tm_min, this->startTimeInfo.tm_sec) ); }
MyTime Period::getEndTime() const
{  return( MyTime(this->endTimeInfo.tm_hour, this->endTimeInfo.tm_min, this->endTimeInfo.tm_sec) ); }

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

void Period::setStartDate(MyDate date){
  this->startTimeInfo.tm_mday = date.getDay();
  this->startTimeInfo.tm_mon = date.getMonth();
  this->startTimeInfo.tm_year = date.getYear();
}
void Period::setStartDay(int d){ this->startTimeInfo.tm_mday = d; }
void Period::setStartMonth(int m){ this->startTimeInfo.tm_mon = m;  }
void Period::setStartYear(int y){ this->startTimeInfo.tm_year = y;  }
void Period::setStartSecond(int s){ this->startTimeInfo.tm_sec = s; }
void Period::setStartMinute(int m){ this->startTimeInfo.tm_min = m; }
void Period::setStartHour(int h){ this->startTimeInfo.tm_hour = h;  }

void Period::setEndDate(MyDate date){
  this->endTimeInfo.tm_mday = date.getDay();
  this->endTimeInfo.tm_mon = date.getMonth();
  this->endTimeInfo.tm_year = date.getYear();
}
void Period::setEndDay(int d){ this->endTimeInfo.tm_mday = d; }
void Period::setEndMonth(int m){ this->endTimeInfo.tm_mon = m;  }
void Period::setEndYear(int y){ this->endTimeInfo.tm_year = y;  }
void Period::setEndSecond(int s){ this->endTimeInfo.tm_sec = s; }
void Period::setEndMinute(int m){ this->endTimeInfo.tm_min = m; }
void Period::setEndHour(int h){ this->endTimeInfo.tm_hour = h;  }

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
void Period::setStartTimeNow_UTC(){
  /*
    // const long int SECONDS_2_23_2018_UTC = 1519344000;
    The amount of seconds since 1/1/1970 00:00:00 to
    2/23/2018 00:00:00 in UTC is 1519344000
  */
  std::time_t result = std::time(NULL);
  std::gmtime(&result);
  const long int NOW = static_cast<long int> (result);
  int since20180223 = (int)(1519344000-NOW);
  MyDate date;
  date.setDateAtNumberOfDaysFromDate(23,2,2018,since20180223);
  this->setStartDate(date);
}
void Period::setStartTimeNow_Local(){
  /*
    // const long int SECONDS_2_23_2018_UTC = 1519344000;
    The amount of seconds since 1/1/1970 00:00:00 to
    2/23/2018 00:00:00 in UTC is 1519344000
  */
  std::time_t result = std::time(NULL);
  std::localtime(&result);
  const long int NOW = static_cast<long int> (result);
  int since20180223 = (int)(1519344000-NOW);
  MyDate date;
  date.setDateAtNumberOfDaysFromDate(23,2,2018,since20180223);
  this->setStartDate(date);
}

TimeAndDate Period::getTimeDateToday_UTC() const{
  time_t rawtime;
  struct tm * timeInfo;
  time ( &rawtime );
  timeInfo = gmtime ( &rawtime );
  return( TimeAndDate(timeInfo->tm_mday, timeInfo->tm_mon, timeInfo->tm_year,
            timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec ) );
}
TimeAndDate Period::getTimeDateToday_Local() const{
  time_t rawtime;
  struct tm * timeInfo;
  time ( &rawtime );
  timeInfo = localtime ( &rawtime );
  return( TimeAndDate(timeInfo->tm_mday, timeInfo->tm_mon, timeInfo->tm_year,
            timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec ) );
}
