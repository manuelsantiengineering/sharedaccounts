
#include "TimeAndDate.h"

TimeAndDate::TimeAndDate() : MyDate(), MyClock()
{}
TimeAndDate::TimeAndDate(int day, int mon, int yr, int hr, int min, int sec) :
    MyDate(day, mon, yr), MyClock(hr, min, sec)
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

void TimeAndDate::operator=(const TimeAndDate &td){
  this->MyDate::operator=(td);
  this->MyClock::operator=(td);
}
bool TimeAndDate::operator==(const TimeAndDate & td) const{
  MyDate date1(td);
  MyDate date2(*this);
  MyClock clock1(td);
  MyClock clock2(*this);
  return(date1 == date2 && clock1 == clock2);
}
bool TimeAndDate::operator!=(const TimeAndDate & td) const{ return( !(*this == td) ); }

bool TimeAndDate::operator >=(const TimeAndDate & td) const{
  MyDate date1(td);
  MyDate date2(*this);
  MyClock clock1(td);
  MyClock clock2(*this);
  return(date1 > date2 || (date1 == date2 && clock1 >= clock2) );
}
bool TimeAndDate::operator >(const TimeAndDate & td) const{
  MyDate date1(td);
  MyDate date2(*this);
  MyClock clock1(td);
  MyClock clock2(*this);
  return(date1 > date2 || (date1 == date2 && clock1 > clock2) );
}
bool TimeAndDate::operator <=(const TimeAndDate & td) const{
  MyDate date1(td);
  MyDate date2(*this);
  MyClock clock1(td);
  MyClock clock2(*this);
  return(date1 < date2 || (date1 == date2 && clock1 <= clock2) );
}
bool TimeAndDate::operator <(const TimeAndDate & td) const{
  MyDate date1(td);
  MyDate date2(*this);
  MyClock clock1(td);
  MyClock clock2(*this);
  return(date1 < date2 || (date1 == date2 && clock1 < clock2) );
}
ostream & operator<<(ostream & out, const TimeAndDate & td){
  MyDate date1(td);
  MyClock clock1(td);
  out << date1.dateToMyString() << " " << clock1.timeToString_Seconds();
  return(out);
}
