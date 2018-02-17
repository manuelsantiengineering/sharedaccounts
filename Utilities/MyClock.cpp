
#include "MyClock.h"

MyClock::MyClock() : MyTime(12,0,0), isAM(true){}

MyClock::MyClock(int hours, int minutes, int seconds){
  if(this->isSecondsCorrect(seconds) && this->isMinutesCorrect(minutes) && hours < 25){
    if(hours > 12){
      hours-=12;
      this->isAM = false;
    }else{
      this->isAM = true;
    }
    this->seconds = seconds;
    this->minutes = minutes;
    this->hours = hours;
  }else{
    MyString e("Please verify the time values.");
    throw e;
  }
}
MyClock::MyClock(int hours, int minutes, int seconds, bool isAM){
  if(this->isTimeCorrect(hours, minutes, seconds)){
    this->seconds = seconds;
    this->minutes = minutes;
    this->hours = hours;
    this->isAM = isAM;
  }else{
    MyString e("Please verify the time values.");
    throw e;
  }
}
MyClock::MyClock(const MyClock & timeInstance){
  this->seconds = timeInstance.seconds;
  this->minutes = timeInstance.minutes;
  this->hours = timeInstance.hours;
  this->isAM = timeInstance.isAM;
}
MyClock::~MyClock(){
}
MyClock & MyClock::operator=(const MyClock & timeInstance){
  this->seconds = timeInstance.seconds;
  this->minutes = timeInstance.minutes;
  this->hours = timeInstance.hours;
  this->isAM = timeInstance.isAM;
  return(*this);
}
void MyClock::setTime(int h, int m, int s, bool isAM){
  if(this->isTimeCorrect(h, m, s)){
    this->seconds = s;
    this->minutes = m;
    this->hours = h;
    this->isAM = isAM;
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

bool MyClock::isAm() const{  return(this->isAM); }

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
  if(this->isAM == true){
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
  if(this->isAM == true){
      temporal = temporal +  "AM" ;
  }else{
      temporal = temporal +  "PM" ;
  }
  return(temporal);
}
MyString MyClock::timeToStringMilitary() const{
  MyString temporal ="";

  int h = (this->isAM) ? this->hours : (this->hours+12) ;

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

  int h = (this->isAM) ? this->hours : (this->hours+12) ;

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
  return((t1 == t2) && (this->isAM == timeInstance.isAM));
}
bool MyClock::operator != (const MyClock & timeInstance) const{
  return(!((*this) == timeInstance));
}
bool MyClock::operator >= (const MyClock & timeInstance) const{
  return( ((*this) > timeInstance) || ((*this) == timeInstance) );
}
bool MyClock::operator > (const MyClock & timeInstance) const{
  bool greater = false;

  if((this->isAM == false) && timeInstance.isAM == true){
      greater = true;
  }else if(this->isAM == timeInstance.isAM){
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
  out << timeInstance.timeToString();
  return(out);
}
