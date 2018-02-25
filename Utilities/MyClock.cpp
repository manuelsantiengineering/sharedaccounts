
#include "MyClock.h"

MyClock::MyClock() : MyTime(12,0,0), AM(true){}

MyClock::MyClock(int hours, int minutes, int seconds){
  if(this->isSecondsCorrect(seconds) && this->isMinutesCorrect(minutes) && hours < 25){
    if(hours > 12){
      hours-=12;
      this->AM = false;
    }else{
      this->AM = true;
    }
    this->seconds = seconds;
    this->minutes = minutes;
    this->hours = hours;
  }else{
    MyString e("Please verify the time values.");
    throw e;
  }
}
MyClock::MyClock(int hours, int minutes, int seconds, bool AM){
  if(this->isTimeCorrect(hours, minutes, seconds)){
    this->seconds = seconds;
    this->minutes = minutes;
    this->hours = hours;
    this->AM = AM;
  }else{
    MyString e("Please verify the time values.");
    throw e;
  }
}
MyClock::MyClock(const MyClock & timeInstance){
  this->seconds = timeInstance.seconds;
  this->minutes = timeInstance.minutes;
  this->hours = timeInstance.hours;
  this->AM = timeInstance.AM;
}
MyClock::~MyClock(){
}
MyClock & MyClock::operator=(const MyClock & timeInstance){
  this->seconds = timeInstance.seconds;
  this->minutes = timeInstance.minutes;
  this->hours = timeInstance.hours;
  this->AM = timeInstance.AM;
  return(*this);
}
void MyClock::setTime(int h, int m, int s, bool AM){
  if(this->isTimeCorrect(h, m, s)){
    this->seconds = s;
    this->minutes = m;
    this->hours = h;
    this->AM = AM;
  }else{
    MyString e("Please verify the time values.");
    throw e;
  }
}
void MyClock::setSeconds(int seconds){
  if(this->isSecondsCorrect(seconds)){
    this->seconds = seconds;
  }else{
    MyString e("Please verify the seconds values.");
    throw e;
  }
}
void MyClock::setMinutes(int minutes){
  if(this->isMinutesCorrect(minutes)){
    this->minutes = minutes;
  }else{
    MyString e("Please verify the minutes values.");
    throw e;
  }
}
void MyClock::setHours(int hours){
  if(this->isHoursCorrect(hours)){
    this->hours = hours;
  }else{
    MyString e("Please verify the hours values.");
    throw e;
  }
}

bool MyClock::isAM() const{  return(this->AM); }

int MyClock::getTimeInSeconds() const{
  int pmSeconds = (this->AM)? 0 : 12*3600;
  return(pmSeconds + this->seconds + (this->minutes*60) + ((this->hours*3600)));
}

bool MyClock::isSecondsCorrect(int s){ return((s >= 0 && s < 60));  }
bool MyClock::isMinutesCorrect(int m){ return((m >= 0 && m < 60));  }
bool MyClock::isHoursCorrect(int h){ return(h > 0 && h <= 12);  }
bool MyClock::isTimeCorrect(int h, int m, int s){
  return( this->isSecondsCorrect(s) && this->isMinutesCorrect(m) && this->isHoursCorrect(h) );
}

MyString MyClock::timeToString() const{
  MyString temporal ="";

  if(this->hours < 10){
      temporal = temporal + "0" + MyString(this->hours) + ":";
  }else{
      temporal = temporal + MyString(this->hours) + ":";
  }
  if(this->minutes < 10){
      temporal = temporal + "0" + MyString(this->minutes);
  }else{
      temporal = temporal +  MyString(this->minutes);
  }
  if(this->AM == true){
      temporal = temporal +  "AM" ;
  }else{
      temporal = temporal +  "PM" ;
  }
  return(temporal);
}
MyString MyClock::timeToString_Seconds() const{
  MyString temporal ="";

  if(this->hours < 10){
      temporal = temporal + "0" + MyString(this->hours) + ":";
  }else{
      temporal = temporal + MyString(this->hours) + ":";
  }
  if(this->minutes < 10){
      temporal = temporal + "0" + MyString(this->minutes) + ":";
  }else{
      temporal = temporal +  MyString(this->minutes) + ":";
  }
  if(this->seconds < 10){
      temporal = temporal +  "0"+ MyString(this->seconds);
  }else{
      temporal = temporal +  MyString(this->seconds);
  }
  if(this->AM == true){
      temporal = temporal +  "AM" ;
  }else{
      temporal = temporal +  "PM" ;
  }
  return(temporal);
}
MyString MyClock::timeToStringMilitary() const{
  MyString temporal ="";

  int h = (this->AM) ? this->hours : (this->hours+12) ;

  if(h < 10){
      temporal = temporal + "0" + MyString(h) + ":";
  }else{
      temporal = temporal + MyString(h) + ":";
  }
  if(this->minutes < 10){
      temporal = temporal + "0" + MyString(this->minutes);
  }else{
      temporal = temporal +  MyString(this->minutes);
  }

  return(temporal);
}
MyString MyClock::timeToStringMilitary_Seconds() const{
  MyString temporal ="";

  int h = (this->AM) ? this->hours : (this->hours+12) ;

  if(h < 10){
      temporal = temporal + "0" + MyString(h) + ":";
  }else{
      temporal = temporal + MyString(h) + ":";
  }
  if(this->minutes < 10){
      temporal = temporal + "0" + MyString(this->minutes) + ":";
  }else{
      temporal = temporal +  MyString(this->minutes) + ":";
  }
  if(this->seconds < 10){
      temporal = temporal +  "0"+ MyString(this->seconds);
  }else{
      temporal = temporal +  MyString(this->seconds);
  }

  return(temporal);
}
bool MyClock::operator == (const MyClock & timeInstance) const{
  MyTime t1(timeInstance);
  MyTime t2(*this);
  return((t1 == t2) && (this->AM == timeInstance.AM));
}
bool MyClock::operator != (const MyClock & timeInstance) const{
  return(!((*this) == timeInstance));
}
bool MyClock::operator >= (const MyClock & timeInstance) const{
  return( ((*this) > timeInstance) || ((*this) == timeInstance) );
}
bool MyClock::operator > (const MyClock & timeInstance) const{
  bool greater = false;

  if((this->AM == false) && timeInstance.AM == true){
      greater = true;
  }else if(this->AM == timeInstance.AM){
    if( (this->hours != 12 && this->hours > timeInstance.hours) ||
        (timeInstance.hours == 12 && this->hours != timeInstance.hours) ||
        ((this->hours == timeInstance.hours) && (this->minutes > timeInstance.minutes)) ||
        ((this->hours == timeInstance.hours) && (this->minutes == timeInstance.minutes) && (this->seconds > timeInstance.seconds))
    ){  greater = true; }
  }
  return(greater);
}
bool MyClock::operator <= (const MyClock & timeInstance) const{
  return( ((*this) < timeInstance) || ((*this) == timeInstance) );
}
bool MyClock::operator < (const MyClock & timeInstance) const{
  return(!((*this) == timeInstance) && !((*this) > timeInstance));
}

ostream & operator<<(ostream & out, const MyClock & timeInstance){
  out << timeInstance.timeToString_Seconds();
  return(out);
}
