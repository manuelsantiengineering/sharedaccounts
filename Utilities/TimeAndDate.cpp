
#include "TimeAndDate.h"

TimeAndDate::TimeAndDate() : MyDate(), MyClock()
{}
TimeAndDate::TimeAndDate(int day, int mon, int yr, int hr, int min, int sec) :
    MyDate(day, mon, yr), MyClock(hr, min, sec)
{}
TimeAndDate::TimeAndDate(int day, int mon, int yr, int hr, int min, int sec, bool isAM) :
    MyDate(day, mon, yr), MyClock(hr, min, sec, isAM)
{}
TimeAndDate::TimeAndDate(MyDate &date) : MyDate(date), MyClock()
{}
TimeAndDate::TimeAndDate(MyClock &ts) : MyDate(), MyClock(ts)
{}
TimeAndDate::TimeAndDate(MyDate &date, MyClock &ts) : MyDate(date), MyClock(ts)
{}
TimeAndDate::TimeAndDate(const TimeAndDate &td){
  this->MyDate::operator=(td);
  this->MyClock::operator=(td);
}
TimeAndDate::~TimeAndDate(){}

MyClock TimeAndDate::getTime() const{
  MyClock td(*this);
  return(td);
}
MyDate TimeAndDate::getDate() const{
  MyDate date(*this);
  return(date);
}

void TimeAndDate::setTime(MyClock &ts){ this->MyClock::operator=(ts); }
void TimeAndDate::setDate(MyDate &date){ this->MyDate::operator=(date);  }

void TimeAndDate::setTimeAndDateAtNumberOfSecondsFromTimeAndDate(const TimeAndDate &td, int seconds){
  if(seconds != 0){
    int sec = abs(seconds);
    // std::cout << " 00 Seconds: " << seconds << " sec: " << sec << std::endl;
    const double SECONDS_IN_DAY = 86400;
    double daysFraction = (sec/(SECONDS_IN_DAY));
    // std::cout << " 00 daysFraction: " << (sec/SECONDS_IN_DAY) << std::endl;
    int amountOfDaysToAdd = floor(daysFraction); //Gets the amount of days to add
    // std::cout << " 00 daysFraction: " << daysFraction << " amountOfDaysToAdd: " << amountOfDaysToAdd << std::endl;
    daysFraction = (daysFraction - amountOfDaysToAdd)*SECONDS_IN_DAY;
    // std::cout << " 00 daysFraction: " << daysFraction << std::endl;
    int amountOfSecondsToAdd = round(daysFraction); //Gets the amount of seconds that will change the time
    // std::cout << " 00 Amount of days: " << amountOfDaysToAdd << std::endl;
    // std::cout << " 00 Amount of seconds: " << amountOfSecondsToAdd << std::endl;

    MyClock tdTime = td.getTime();

    if(seconds < 0){
      std::cout << " -01 Amount of seconds: " << amountOfSecondsToAdd << std::endl;
      amountOfSecondsToAdd = tdTime.getTimeInSeconds()-amountOfSecondsToAdd;
      std::cout << " -02 Amount of seconds: " << amountOfSecondsToAdd << std::endl;
      if(amountOfSecondsToAdd < 0){
        amountOfSecondsToAdd = floor(SECONDS_IN_DAY + amountOfSecondsToAdd);
        amountOfDaysToAdd = (-1)-amountOfDaysToAdd;
      }else{
        amountOfDaysToAdd = -1*amountOfDaysToAdd;
      }
      std::cout << " -03 Amount of days: " << amountOfDaysToAdd << std::endl;
      std::cout << " -03 Amount of seconds: " << amountOfSecondsToAdd << std::endl;
    }else if(seconds > 0){
      amountOfSecondsToAdd = tdTime.getTimeInSeconds()+amountOfSecondsToAdd;
      if(amountOfSecondsToAdd > SECONDS_IN_DAY){
        amountOfSecondsToAdd = floor(amountOfSecondsToAdd - SECONDS_IN_DAY);
        amountOfDaysToAdd += 1;
      }
      std::cout << " +03 Amount of days: " << amountOfDaysToAdd << std::endl;
      std::cout << " +03 Amount of seconds: " << amountOfSecondsToAdd << std::endl;
    }
    MyTime ts(0,0,amountOfSecondsToAdd);
    // std::cout << " 03 Time: " << ts << std::endl;
    MyDate date = td.getDate();
    std::cout << " 03 Time: " << ts << " Date: " << date << std::endl;
    date.setDateAtNumberOfDays(amountOfDaysToAdd);
    // date.setDateAtNumberOfDaysFromDate(date, amountOfDaysToAdd);
    std::cout << " 04 Time: " << ts << " Date: " << date << std::endl;
    MyClock tc(ts);
    // std::cout << " 05 Clock: " << tc << " Date: " << date << std::endl;
    this->setTime(tc);
    this->setDate(date);
    // std::cout << " 06 Final: " << (*this) << std::endl;
  }else{
    (*this) = td;
  }
}

void TimeAndDate::operator=(const TimeAndDate &td){
  this->MyDate::operator=(td);
  this->MyClock::operator=(td);
}
bool TimeAndDate::operator==(const TimeAndDate &td) const{
  MyDate date1(*this);
  MyDate date2(td);
  MyClock clock1(*this);
  MyClock clock2(td);
  return(date1 == date2 && clock1 == clock2);
}
bool TimeAndDate::operator!=(const TimeAndDate & td) const{ return( !(*this == td) ); }

bool TimeAndDate::operator >=(const TimeAndDate & td) const{
  MyDate date1(*this);
  MyDate date2(td);
  MyClock clock1(*this);
  MyClock clock2(td);
  return(date1 > date2 || (date1 == date2 && clock1 >= clock2) );
}
bool TimeAndDate::operator >(const TimeAndDate & td) const{
  MyDate date1(*this);
  MyDate date2(td);
  MyClock clock1(*this);
  MyClock clock2(td);
  return(date1 > date2 || (date1 == date2 && clock1 > clock2) );
}
bool TimeAndDate::operator <=(const TimeAndDate & td) const{
  MyDate date1(*this);
  MyDate date2(td);
  MyClock clock1(*this);
  MyClock clock2(td);
  return(date1 < date2 || (date1 == date2 && clock1 <= clock2) );
}
bool TimeAndDate::operator <(const TimeAndDate & td) const{
  MyDate date1(*this);
  MyDate date2(td);
  MyClock clock1(*this);
  MyClock clock2(td);
  return(date1 < date2 || (date1 == date2 && clock1 < clock2) );
}
std::ostream & operator<<(std::ostream & out, const TimeAndDate &td){
  MyDate date1;
  date1 = td.getDate();
  MyClock clock1;
  clock1 = td.getTime();
  out << date1 << " " << clock1;
  // out << "MANUEL";
  // out << date1.dateToMyString() << " " << clock1.timeToString_Seconds();
  return(out);
}
