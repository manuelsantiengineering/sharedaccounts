
#include "MyTime.h"

MyTime::MyTime(int seconds, int minutes, int hours, bool isAM){
  this->seconds = seconds;
  this->minutes = minutes;
  this->hours = hours;
  this->isAM = isAM;
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
  this->seconds = s;
  this->minutes = m;
  this->hours = h;
  this->isAM = isAM;
}
void MyTime::setSeconds(int seconds){ this->seconds = seconds;  }
void MyTime::setMinutes(int minutes){ this->minutes = minutes; }
void MyTime::setHours(int hours){ this->hours = hours;  }

int MyTime::getSeconds() const{ return(this->seconds);  }
int MyTime::getMinutes() const{ return(this->minutes);  }
int MyTime::getHours() const{ return(this->hours);  }
bool MyTime::isAm() const{  return(this->isAM); }

bool MyTime::isTimeCorrect(int s, int m, int h){
  return( (s >= 0 && s <= 60) && (m >= 0 && m <= 60) && (h >= 0 && h <= 12)  );
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
