#include "Period.h"

static const int SECONDS_IN_DAY = 86400;
static const int MINUTES_IN_DAY = 1440;

Period::Period(){
  this->startTimeInfo = {12,0,0,true,1,1,1990};
  this->endTimeInfo = {12,0,0,true,1,1,1990};
}
Period::Period(MyDate startDate, MyDate endDate){
  this->startTimeInfo = {12,0,0,true,startDate.getDay(),startDate.getMonth(),startDate.getYear()};
  this->endTimeInfo = {12,0,0,true,endDate.getDay(),endDate.getMonth(),endDate.getYear()};
}
Period::Period(MyClock startTime, MyClock endTime){
  this->startTimeInfo = {startTime.getSeconds(),startTime.getMinutes(),startTime.getHours(),
    startTime.isAM(),1,1,1};
  this->endTimeInfo = {endTime.getSeconds(),endTime.getMinutes(),endTime.getHours(),
    endTime.isAM(),1,1,1};
}
Period::Period(MyDate startDate, MyDate endDate, MyClock startTime, MyClock endTime){
  this->startTimeInfo = {startTime.getSeconds(),startTime.getMinutes(),startTime.getHours(),
    startTime.isAM(),startDate.getDay(),startDate.getMonth(),startDate.getYear()};
  this->endTimeInfo = {endTime.getSeconds(),endTime.getMinutes(),endTime.getHours(),
    endTime.isAM(),endDate.getDay(),endDate.getMonth(),endDate.getYear()};
}
Period::Period(TimeAndDate start, TimeAndDate end){
  this->startTimeInfo = {start.getSeconds(),start.getMinutes(),start.getHours(),
    start.isAM(),start.getDay(),start.getMonth(),start.getYear()};
  this->endTimeInfo = {end.getSeconds(),end.getMinutes(),end.getHours(),
    end.isAM(),end.getDay(),end.getMonth(),end.getYear()};
}
Period::Period(const Period &period){
  this->startTimeInfo = {period.startTimeInfo.sec,period.startTimeInfo.hr,
    period.startTimeInfo.AM,period.startTimeInfo.day,period.startTimeInfo.mon,period.startTimeInfo.yr};
  this->endTimeInfo = {period.endTimeInfo.sec,period.endTimeInfo.min,period.endTimeInfo.hr,
    period.endTimeInfo.AM,period.endTimeInfo.day,period.endTimeInfo.mon,period.endTimeInfo.yr};
}
Period::~Period(){}

bool Period::periodIsValid() const{
  MyDate startDate = this->getStartDate();
  const int secondsInPeriod = this->getPeriodInSeconds();
  const int SecondsNonLeapYear = 31536000;

  return( (secondsInPeriod <= SecondsNonLeapYear) ||
          (startDate.isLeapYear() && (secondsInPeriod <= (SecondsNonLeapYear+SECONDS_IN_DAY)))
        );
}
TimeAndDate Period::getStartTimeAndDate() const{
  return( TimeAndDate(this->startTimeInfo.day, this->startTimeInfo.mon, this->startTimeInfo.yr,
            this->startTimeInfo.hr, this->startTimeInfo.min, this->startTimeInfo.sec,
            this->startTimeInfo.AM ) );
}
TimeAndDate Period::getEndTimeAndDate() const{
  return( TimeAndDate(this->endTimeInfo.day, this->endTimeInfo.mon, this->endTimeInfo.yr,
            this->endTimeInfo.hr, this->endTimeInfo.min, this->endTimeInfo.sec,
            this->endTimeInfo.AM ) );
}
MyDate Period::getStartDate() const
{  return( MyDate(this->startTimeInfo.day, this->startTimeInfo.mon, this->startTimeInfo.yr) ); }
MyDate Period::getEndDate() const
{  return( MyDate(this->endTimeInfo.day, this->endTimeInfo.mon, this->endTimeInfo.yr) ); }
MyClock Period::getStartTime() const
{  return( MyClock(this->startTimeInfo.hr, this->startTimeInfo.min,
                  this->startTimeInfo.sec, this->startTimeInfo.AM) ); }
MyClock Period::getEndTime() const
{  return( MyClock(this->endTimeInfo.hr, this->endTimeInfo.min,
                  this->endTimeInfo.sec, this->endTimeInfo.AM) ); }

int Period::getStartDay() const{  return(this->startTimeInfo.day);  }
int Period::getStartMonth() const{  return(this->startTimeInfo.mon); }
int Period::getStartYear() const{ return(this->startTimeInfo.yr);  }
int Period::getStartSecond() const{ return(this->startTimeInfo.sec); }
int Period::getStartMinute() const{ return(this->startTimeInfo.min); }
int Period::getStartHour() const{ return(this->startTimeInfo.hr);  }
bool Period::isStartTimeAM() const{ return(this->startTimeInfo.AM);  }

int Period::getEndDay() const{  return(this->endTimeInfo.day);  }
int Period::getEndMonth() const{  return(this->endTimeInfo.mon); }
int Period::getEndYear() const{ return(this->endTimeInfo.yr);  }
int Period::getEndSecond() const{ return(this->endTimeInfo.sec); }
int Period::getEndMinute() const{ return(this->endTimeInfo.min); }
int Period::getEndHour() const{ return(this->endTimeInfo.hr);  }
bool Period::isEndTimeAM() const{ return(this->endTimeInfo.AM);  }

MyTime Period::getPeriodTime() const{
  return( MyTime(0,0,this->getPeriodInSeconds()) );
}
int Period::getDaysBetweenStartDateAndEndDate() const{
  MyDate startDate(this->getStartDate());
  return(startDate.getNumberOfDaysUntilDate(this->getEndDate()) );
}
int Period::getPeriodInSeconds() const{
  int totalSeconds = SECONDS_IN_DAY*this->getDaysBetweenStartDateAndEndDate();
  MyClock startTime(this->getStartTime());
  MyClock endTime(this->getEndTime());
  totalSeconds += endTime.getTimeInSeconds() - startTime.getTimeInSeconds();
  return(totalSeconds);
}
double Period::getPeriodInMinutes() const{ return( this->getPeriodInSeconds()/60 ); }
double Period::getPeriodInHours() const{  return( this->getPeriodInMinutes()/60 );  }
double Period::getPeriodInDays() const{  return( this->getPeriodInMinutes()/MINUTES_IN_DAY );  }

void Period::setStartTimeAndDate(TimeAndDate start){
  this->startTimeInfo.day = start.getDay();
  this->startTimeInfo.mon = start.getMonth();
  this->startTimeInfo.yr = start.getYear();
  this->startTimeInfo.sec = start.getSeconds();
  this->startTimeInfo.min = start.getMinutes();
  this->startTimeInfo.hr = start.getHours();
  this->startTimeInfo.AM =  start.isAM();
}
void Period::setStartDate(MyDate date){
  this->startTimeInfo.day = date.getDay();
  this->startTimeInfo.mon = date.getMonth();
  this->startTimeInfo.yr = date.getYear();
}
void Period::setStartDay(int d){ this->startTimeInfo.day = d; }
void Period::setStartMonth(int m){ this->startTimeInfo.mon = m;  }
void Period::setStartYear(int y){ this->startTimeInfo.yr = y;  }
void Period::setStartSecond(int s){ this->startTimeInfo.sec = s; }
void Period::setStartMinute(int m){ this->startTimeInfo.min = m; }
void Period::setStartHour(int h){ this->startTimeInfo.hr = h;  }
void Period::setStartMeridiem(bool AM){ this->startTimeInfo.AM = AM;  }

void Period::setEndTimeAndDate(TimeAndDate start){
  this->endTimeInfo.day = start.getDay();
  this->endTimeInfo.mon = start.getMonth();
  this->endTimeInfo.yr = start.getYear();
  this->endTimeInfo.sec = start.getSeconds();
  this->endTimeInfo.min = start.getMinutes();
  this->endTimeInfo.hr = start.getHours();
  this->endTimeInfo.AM =  start.isAM();
}
void Period::setEndDate(MyDate date){
  this->endTimeInfo.day = date.getDay();
  this->endTimeInfo.mon = date.getMonth();
  this->endTimeInfo.yr = date.getYear();
}
void Period::setEndDay(int d){ this->endTimeInfo.day = d; }
void Period::setEndMonth(int m){ this->endTimeInfo.mon = m;  }
void Period::setEndYear(int y){ this->endTimeInfo.yr = y;  }
void Period::setEndSecond(int s){ this->endTimeInfo.sec = s; }
void Period::setEndMinute(int m){ this->endTimeInfo.min = m; }
void Period::setEndHour(int h){ this->endTimeInfo.hr = h;  }
void Period::setEndMeridiem(bool AM){ this->endTimeInfo.AM = AM;  }

void Period::setPeriod(MyDate startDate, MyDate endDate){
  this->startTimeInfo.day = startDate.getDay();
  this->startTimeInfo.mon = startDate.getMonth();
  this->startTimeInfo.yr = startDate.getYear();
  this->endTimeInfo.day = endDate.getDay();
  this->endTimeInfo.mon = endDate.getMonth();
  this->endTimeInfo.yr = endDate.getYear();
}
void Period::setPeriod(MyClock startTime, MyClock endTime){
  this->startTimeInfo.AM = startTime.isAM();
  this->startTimeInfo.hr = startTime.getHours();
  this->startTimeInfo.min = startTime.getMinutes();
  this->startTimeInfo.sec = startTime.getSeconds();
  this->endTimeInfo.AM = endTime.isAM();
  this->endTimeInfo.hr = endTime.getHours();
  this->endTimeInfo.min = endTime.getMinutes();
  this->endTimeInfo.sec = endTime.getSeconds();
}
void Period::setPeriod(MyDate startDate, MyDate endDate, MyClock startTime, MyClock endTime){
  this->startTimeInfo = {startTime.getSeconds(),startTime.getMinutes(),startTime.getHours(),
    startTime.isAM(),startDate.getDay(),startDate.getMonth(),startDate.getYear()};
  this->endTimeInfo = {endTime.getSeconds(),endTime.getMinutes(),endTime.getHours(),
    endTime.isAM(),endDate.getDay(),endDate.getMonth(),endDate.getYear()};
}
void Period::setPeriod(TimeAndDate start, TimeAndDate end){
  this->startTimeInfo = {start.getSeconds(),start.getMinutes(),start.getHours(),
    start.isAM(),start.getDay(),start.getMonth(),start.getYear()};
  this->endTimeInfo = {end.getSeconds(),end.getMinutes(),end.getHours(),
    end.isAM(),end.getDay(),end.getMonth(),end.getYear()};
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
  timeInfo->tm_year += 1900;
  timeInfo->tm_mon += 1;
  bool tmpIsAm = false;
  if(timeInfo->tm_hour > 12){
    tmpIsAm = true;
    timeInfo->tm_hour -= 12;
  }
  return( TimeAndDate(timeInfo->tm_mday, timeInfo->tm_mon, timeInfo->tm_year,
            timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec, tmpIsAm ) );
}
TimeAndDate Period::getTimeDateToday_Local() const{
  time_t rawtime;
  struct tm * timeInfo;
  time ( &rawtime );
  timeInfo = localtime ( &rawtime );
  timeInfo->tm_year += 1900;
  timeInfo->tm_mon += 1;
  bool tmpIsAm = false;
  if(timeInfo->tm_hour > 12){
    tmpIsAm = true;
    timeInfo->tm_hour -= 12;
  }
  return( TimeAndDate(timeInfo->tm_mday, timeInfo->tm_mon, timeInfo->tm_year,
            timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec, tmpIsAm ) );
}
void Period::setPeriodDateFromNow_UTC(MyDate endDate){
  this->setStartTimeNow_UTC();
  this->setEndDate(endDate);
}
void Period::setPeriodTimeFromNow_UTC(MyClock endTime){
  this->setStartTimeNow_UTC();
  this->endTimeInfo.AM = endTime.isAM();
  this->endTimeInfo.hr = endTime.getHours();
  this->endTimeInfo.min = endTime.getMinutes();
  this->endTimeInfo.sec = endTime.getSeconds();
}
void Period::setPeriodDateAndTimeFromNow_UTC(TimeAndDate end){
  this->setStartTimeNow_UTC();
  this->setEndTimeAndDate(end);
}
void Period::setPeriodDateAndTimeFromNow_UTC(MyDate endDate, MyClock endTime){
  this->setStartTimeNow_UTC();
  this->setEndDate(endDate);
  this->endTimeInfo.AM = endTime.isAM();
  this->endTimeInfo.hr = endTime.getHours();
  this->endTimeInfo.min = endTime.getMinutes();
  this->endTimeInfo.sec = endTime.getSeconds();
}
void Period::setPeriodDateAndTimeFromNow_UTC(int years, int months, int days, int hours, int minutes, int seconds, bool AM){
  this->setStartTimeNow_UTC();
  this->endTimeInfo.day = days;
  this->endTimeInfo.mon = months;
  this->endTimeInfo.yr = years;
  this->endTimeInfo.hr = hours;
  this->endTimeInfo.min = minutes;
  this->endTimeInfo.sec = seconds;
  this->endTimeInfo.AM = AM;
}
void Period::setPeriodDateFromNow_UTC(int d, int m, int y){
  this->setStartTimeNow_UTC();
  this->endTimeInfo.day = d;
  this->endTimeInfo.mon = m;
  this->endTimeInfo.yr = y;
}
void Period::setPeriodTimeFromNow_UTC(int h, int m, int s, bool AM){
  this->setStartTimeNow_UTC();
  this->endTimeInfo.hr = h;
  this->endTimeInfo.min = m;
  this->endTimeInfo.sec = s;
  this->endTimeInfo.AM = AM;
}

void Period::operator=(const Period &period){
  this->startTimeInfo = {period.startTimeInfo.sec,period.startTimeInfo.hr,
    period.startTimeInfo.AM,period.startTimeInfo.day,period.startTimeInfo.mon,period.startTimeInfo.yr};
  this->endTimeInfo = {period.endTimeInfo.sec,period.endTimeInfo.min,period.endTimeInfo.hr,
    period.endTimeInfo.AM,period.endTimeInfo.day,period.endTimeInfo.mon,period.endTimeInfo.yr};
}
