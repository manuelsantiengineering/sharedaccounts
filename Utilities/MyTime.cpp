
#include "MyTime.h"

MyTime::MyTime(int seconds, int minutes, int hours, bool isAM){
  if(this->isTimeCorrect(seconds, minutes, hours)){
    this->seconds = seconds;
    this->minutes = minutes;
    this->hours = hours;
    this->isAM = isAM;
  }else{
    MyString e("Please verify the time values.");
    throw e;
  }
}
MyTime::MyTime(const MyTime & timeInstance){
  this->seconds = timeInstance.seconds;
  this->minutes = timeInstance.minutes;
  this->hours = timeInstance.hours;
  this->isAM = timeInstance.isAM;
}
MyTime::~MyTime(){
}
MyTime & MyTime::operator=(const MyTime & timeInstance){
  this->seconds = timeInstance.seconds;
  this->minutes = timeInstance.minutes;
  this->hours = timeInstance.hours;
  this->isAM = timeInstance.isAM;
  return(*this);
}
void MyTime::setTime(int s, int m, int h, int isAM){
  if(this->isTimeCorrect(s, m, h)){
    this->seconds = s;
    this->minutes = m;
    this->hours = h;
    this->isAM = isAM;
  }else{
    MyString e("Please verify the time values.");
    throw e;
  }
}
void MyTime::setSeconds(int seconds){
  if(this->isSecondsCorrect(seconds)){
    this->seconds = seconds;
  }else{
    MyString e("Please verify the seconds values.");
    throw e;
  }
}
void MyTime::setMinutes(int minutes){
  if(this->isMinutesCorrect(minutes)){
    this->minutes = minutes;
  }else{
    MyString e("Please verify the minutes values.");
    throw e;
  }
}
void MyTime::setHours(int hours){
  if(this->isHoursCorrect(hours)){
    this->hours = hours;
  }else{
    MyString e("Please verify the hours values.");
    throw e;
  }
}

int MyTime::getSeconds() const{ return(this->seconds);  }
int MyTime::getMinutes() const{ return(this->minutes);  }
int MyTime::getHours() const{ return(this->hours);  }
bool MyTime::isAm() const{  return(this->isAM); }

bool MyTime::isSecondsCorrect(int s){ return((s >= 0 && s < 60));  }
bool MyTime::isMinutesCorrect(int m){ return((m >= 0 && m < 60));  }
bool MyTime::isHoursCorrect(int h){ return(h > 0 && h <= 12);  }
bool MyTime::isTimeCorrect(int s, int m, int h){
  return( this->isSecondsCorrect(s) && this->isMinutesCorrect(m) && this->isHoursCorrect(h) );
}

MyString MyTime::timeToString() const{
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
  if(this->isAM == true){
      temporal = temporal +  " AM " ;
  }else{
      temporal = temporal +  " PM " ;
  }
  return(temporal);
}
MyString MyTime::timeToString_Seconds() const{
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
      temporal = temporal +  " AM " ;
  }else{
      temporal = temporal +  " PM " ;
  }
  return(temporal);
}

bool MyTime::operator == (const MyTime & timeInstance) const{
  return((this->seconds == timeInstance.seconds) && (this->minutes == timeInstance.minutes) && (this->hours == timeInstance.hours) && (this->isAM == timeInstance.isAM));
}
bool MyTime::operator != (const MyTime & timeInstance) const{
  return(!((*this) == timeInstance));
}
bool MyTime::operator >= (const MyTime & timeInstance) const{
  return( ((*this) > timeInstance) || ((*this) == timeInstance) );
}
bool MyTime::operator > (const MyTime & timeInstance) const{
  bool greater = false;

  if((this->isAM == false) && timeInstance.isAM == true){
      greater = true;
  }else if((this->isAM == timeInstance.isAM)  && (this->hours > timeInstance.hours)){
      greater = true;
  }else if((this->isAM == timeInstance.isAM)  && (this->hours == timeInstance.hours) && (this->minutes > timeInstance.minutes)){
      greater = true;
  }else if((this->isAM == timeInstance.isAM)  && (this->hours == timeInstance.hours) && (this->minutes == timeInstance.minutes) && (this->seconds == timeInstance.seconds)){
      greater = true;
  }
  return(greater);
}

bool MyTime::operator <= (const MyTime & timeInstance) const{
  return( ((*this) < timeInstance) || ((*this) == timeInstance) );
}
bool MyTime::operator < (const MyTime & timeInstance) const{
  return(!((*this) == timeInstance) && !((*this) > timeInstance));
}

ostream & operator<<(ostream & out, const MyTime & timeInstance){
  out << timeInstance.timeToString();
  return(out);
}
