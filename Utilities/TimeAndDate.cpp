
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
    const int SECONDS_IN_DAY = 86400;
    double daysFraction = abs(seconds/SECONDS_IN_DAY);
    int amountOfDaysToAdd = floor(daysFraction); //Gets the amount of days to add
    daysFraction = (daysFraction - amountOfDaysToAdd)*SECONDS_IN_DAY;
    int amountOfSecondsToAdd = floor(daysFraction); //Gets the amount of seconds that will change the time

    std::cout << " 00 Amount of days: " << amountOfDaysToAdd << std::endl;
    std::cout << " 00 Amount of seconds: " << amountOfSecondsToAdd << std::endl;

    MyClock tdTime = td.getTime();
    std::cout << " Time in Obj: " << tdTime << std::endl;
    int tdSeconds = tdTime.getTimeInSeconds();
    std::cout << " Time in seconds in Obj: " << tdSeconds << std::endl;

    if(seconds < 0){
      amountOfDaysToAdd *= -1;
      // amountOfSecondsToAdd = tdSeconds - amountOfSecondsToAdd;
      amountOfSecondsToAdd += tdSeconds;
      if(amountOfSecondsToAdd < 0){
        amountOfSecondsToAdd += SECONDS_IN_DAY;
        amountOfDaysToAdd -= 1;
      }
    }else if(seconds > 0){
      // amountOfSecondsToAdd = tdSeconds + amountOfSecondsToAdd;
      amountOfSecondsToAdd += tdSeconds;
      std::cout << " 01 Amount of seconds: " << amountOfSecondsToAdd << std::endl;
      if(amountOfSecondsToAdd > SECONDS_IN_DAY){
        amountOfSecondsToAdd -= SECONDS_IN_DAY;
        amountOfDaysToAdd += 1;
      }
      std::cout << " 02 Amount of days: " << amountOfDaysToAdd << std::endl;
      std::cout << " 02 Amount of seconds: " << amountOfSecondsToAdd << std::endl;
    }

    MyTime ts(0,0,amountOfSecondsToAdd);
    MyDate date = td.getDate();
    std::cout << " 03 Time: " << ts << " Date: " << date << std::endl;
    date.setDateAtNumberOfDays(amountOfDaysToAdd);
    std::cout << " 04 Time: " << ts << " Date: " << date << std::endl;
    MyClock tc(ts);
    std::cout << " 05 Clock: " << tc << " Date: " << date << std::endl;
    this->setTime(tc);
    this->setDate(date);
    std::cout << " 06 Final: " << (*this) << std::endl;
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
