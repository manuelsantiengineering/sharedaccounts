
#include "TimeAndDate.h"

TimeAndDate::TimeAndDate() : MyDate(), MyClock()
{}
TimeAndDate::TimeAndDate(int day, int mon, int yr, int hr, int min, int sec) :
    MyDate(day, mon, yr), MyClock(hr, min, sec)
{}
TimeAndDate::TimeAndDate(int day, int mon, int yr, int hr, int min, int sec, bool isAM) :
    MyDate(day, mon, yr), MyClock(hr, min, sec, isAM)
{}
TimeAndDate::TimeAndDate(MyDate date) : MyDate(date), MyClock()
{}
TimeAndDate::TimeAndDate(MyClock td) : MyDate(), MyClock(td)
{}
TimeAndDate::TimeAndDate(MyDate date, MyClock td) : MyDate(date), MyClock(td)
{}
TimeAndDate::TimeAndDate(const TimeAndDate &td ){
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

void TimeAndDate::setTime(MyClock td){ (*this) = td; }
void TimeAndDate::setDate(MyDate date){ (*this) = date;  }

void TimeAndDate::setTimeAndDateAtNumberOfSecondsFromTimeAndDate(const TimeAndDate & td, int seconds){
  if(seconds != 0){
    const int SECONDS_IN_DAY = 86400;
    double daysFraction = abs(seconds/SECONDS_IN_DAY);
    int amountOfDaysToAdd = floor(daysFraction);

    int amountOfSecondsToAdd = (daysFraction - amountOfDaysToAdd)*SECONDS_IN_DAY;

    MyClock tdTime = td.getTime();
    int tdSeconds = tdTime.getTimeInSeconds();

    if(seconds < 0){
      amountOfDaysToAdd *= -1;
      amountOfSecondsToAdd = tdSeconds - amountOfSecondsToAdd;
      if(amountOfSecondsToAdd < 0){
        amountOfSecondsToAdd += SECONDS_IN_DAY;
        amountOfDaysToAdd -= 1;
      }
    }else if(seconds > 0){
      amountOfSecondsToAdd = tdSeconds + amountOfSecondsToAdd;
      if(amountOfSecondsToAdd > SECONDS_IN_DAY){
        amountOfSecondsToAdd -= SECONDS_IN_DAY;
        amountOfDaysToAdd += 1;
      }
    }

    MyTime ts(0,0,amountOfSecondsToAdd);
    MyDate date = td.getDate();
    date.setDateAtNumberOfDays(amountOfDaysToAdd);
    MyClock tc(ts.getHours(), ts.getMinutes(), ts.getSeconds());
    (*this) = tc;
    (*this) = date;
  }else{
    (*this) = td;
  }
}

void TimeAndDate::operator=(const TimeAndDate &td){
  this->MyDate::operator=(td);
  this->MyClock::operator=(td);
}
bool TimeAndDate::operator==(const TimeAndDate & td) const{
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
ostream & operator<<(ostream & out, const TimeAndDate & td){
  MyDate date1;
  date1 = td.getDate();
  MyClock clock1;
  clock1 = td.getTime();
  out << date1.dateToMyString() << " " << clock1.timeToString_Seconds();
  return(out);
}
