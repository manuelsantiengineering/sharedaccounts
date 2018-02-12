
#include "MyTime.h"

MyTime::MyTime(int hours, int minutes, int seconds, bool isAM){
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
void MyTime::setTime(int h, int m, int s, bool isAM){
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
bool MyTime::isTimeCorrect(int h, int m, int s){
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
      temporal = temporal +  "AM" ;
  }else{
      temporal = temporal +  "PM" ;
  }
  return(temporal);
}
MyString MyTime::timeToStringMilitary() const{
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
MyString MyTime::timeToStringMilitary_Seconds() const{
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
  }else if(this->isAM == timeInstance.isAM){
    if( (this->hours != 12 && this->hours > timeInstance.hours) ||
        (timeInstance.hours == 12 && this->hours != timeInstance.hours) ||
        ((this->hours == timeInstance.hours) && (this->minutes > timeInstance.minutes)) ||
        ((this->hours == timeInstance.hours) && (this->minutes == timeInstance.minutes) && (this->seconds > timeInstance.seconds))
    ){  greater = true; }
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

long int MyTime::getTimeUTC_Epoch_Long() const{
  std::time_t result = std::time(NULL);
  std::gmtime(&result);
  std::cout << std::asctime(std::gmtime(&result)) << result << " (UTC) seconds since the Epoch\n";
  long int t = static_cast<long int> (result);
  return(t);
}
MyString MyTime::getTimeUTC_Epoch_MyString() const{
  MyString tstr(this->getTimeUTC_Epoch_Long());
  return(tstr);
}
// long int MyTime::getTimeLocaltime_Epoch_Long() const{
//   std::time_t result = std::time(NULL);
//   std::localtime(&result);
//   std::cout << std::asctime(std::localtime(&result)) << result << " (LOCAL) seconds since the Epoch\n";
//   long int t = static_cast<long int> (result);
//   return(t);
// }
// MyString MyTime::getTimeLocaltime_Epoch_MyString() const{
//   MyString tstr(this->getTimeLocaltime_Epoch_Long());
//   return(tstr);
// }
