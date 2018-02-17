
#include "MyTime.h"

MyTime::MyTime() : seconds(0), minutes(0), hours(12){}

MyTime::MyTime(int hours, int minutes, int seconds){
  this->seconds = seconds;
  this->minutes = minutes;
  this->hours = hours;
  this->setToStandardTime();
}
MyTime::MyTime(const MyTime & timeInstance){
  this->seconds = timeInstance.seconds;
  this->minutes = timeInstance.minutes;
  this->hours = timeInstance.hours;
}
MyTime::~MyTime(){
}
MyTime & MyTime::operator=(const MyTime & timeInstance){
  this->seconds = timeInstance.seconds;
  this->minutes = timeInstance.minutes;
  this->hours = timeInstance.hours;
  return(*this);
}
void MyTime::setToStandardTime(){
  if(this->seconds >= 60 || this->seconds <= 60){
    int divide = this->seconds/60;
    int rd = floor(abs(divide));
    if(this->seconds > 0){
      this->minutes += rd;
      this->seconds = 60*(divide-rd);
    }else{
      this->minutes -= rd;
      this->seconds = 60*(divide+rd);
    }
  }
  if(this->minutes >= 60 || this->minutes <= 60){
    int divide = this->minutes/60;
    int rd = floor(abs(divide));
    if(this->minutes > 0){
      this->hours += rd;
      this->minutes = 60*(divide-rd);
    }else{
      this->hours -= rd;
      this->minutes = 60*(divide+rd);
    }
  }
}
void MyTime::setTime(int h, int m, int s){
  this->seconds = s;
  this->minutes = m;
  this->hours = h;
  this->setToStandardTime();
}
void MyTime::setSeconds(int seconds){ this->seconds = seconds;  }
void MyTime::setMinutes(int minutes){ this->minutes = minutes;  }
void MyTime::setHours(int hours){ this->hours = hours;  }

int MyTime::getSeconds() const{ return(this->seconds);  }
int MyTime::getMinutes() const{ return(this->minutes);  }
int MyTime::getHours() const{ return(this->hours);  }

int MyTime::getTimeInSeconds() const{
  return(this->seconds + (this->minutes*60) + ((this->hours*3600)));
}
double MyTime::getTimeInMinutes() const{
  return((this->seconds/60) + (this->minutes) + ((this->hours*60)));
}
double MyTime::getTimeInHours() const{
  return((this->seconds/3600) + (this->minutes/60) + ((this->hours)));
}

MyString MyTime::timeToString() const{
  MyString tmp ="";

  if(this->hours < 10){
      tmp = tmp + "0" + MyString(this->hours) + ":";
  }else{
      tmp = tmp + MyString(this->hours) + ":";
  }
  if(this->minutes < 10){
      tmp = tmp + "0" + MyString(this->minutes);
  }else{
      tmp = tmp +  MyString(this->minutes);
  }
  return(tmp);
}
MyString MyTime::timeToString_Seconds() const{
  MyString tmp ="";

  if(this->hours < 10){
      tmp = tmp + "0" + MyString(this->hours) + ":";
  }else{
      tmp = tmp + MyString(this->hours) + ":";
  }
  if(this->minutes < 10){
      tmp = tmp + "0" + MyString(this->minutes) + ":";
  }else{
      tmp = tmp +  MyString(this->minutes) + ":";
  }
  if(this->seconds < 10){
      tmp = tmp +  "0"+ MyString(this->seconds);
  }else{
      tmp = tmp +  MyString(this->seconds);
  }
  return(tmp);
}

bool MyTime::operator == (const MyTime & timeInstance) const{
  return((this->seconds == timeInstance.seconds) &&
          (this->minutes == timeInstance.minutes) &&
          (this->hours == timeInstance.hours) );
}
bool MyTime::operator != (const MyTime & timeInstance) const{
  return(!((*this) == timeInstance));
}
bool MyTime::operator >= (const MyTime & timeInstance) const{
  return( ((*this) > timeInstance) || ((*this) == timeInstance) );
}
bool MyTime::operator > (const MyTime & timeInstance) const{
  return( (this->hours > timeInstance.hours) ||
        ((this->hours == timeInstance.hours) && (this->minutes > timeInstance.minutes)) ||
        ((this->hours == timeInstance.hours) && (this->minutes == timeInstance.minutes) &&
          (this->seconds > timeInstance.seconds))  );
}
bool MyTime::operator <= (const MyTime & timeInstance) const{
  return( ((*this) < timeInstance) || ((*this) == timeInstance) );
}
bool MyTime::operator < (const MyTime & timeInstance) const{
  return(!((*this) == timeInstance) && !((*this) > timeInstance));
}
MyTime MyTime::operator+(const MyTime & timeInstance) const{
  int x = this->getTimeInSeconds()+timeInstance.getTimeInSeconds();
  MyTime t(0,0,x);
  return(t);
}
MyTime MyTime::operator-(const MyTime & timeInstance) const{
  int x = this->getTimeInSeconds()-timeInstance.getTimeInSeconds();
  MyTime t(0,0,x);
  return(t);
}
MyTime & MyTime::operator+=(const MyTime & timeInstance){
  int x = this->getTimeInSeconds()+timeInstance.getTimeInSeconds();
  this->setTime(0,0,x);
  return(*this);
}
MyTime & MyTime::operator-=(const MyTime & timeInstance){
  int x = this->getTimeInSeconds()-timeInstance.getTimeInSeconds();
  this->setTime(0,0,x);
  return(*this);
}

ostream & operator<<(ostream & out, const MyTime & timeInstance){
  out << timeInstance.timeToString();
  return(out);
}

// long int MyTime::getTimeUTC_Epoch_Long() const{
//   std::time_t result = std::time(NULL);
//   std::gmtime(&result);
//   std::cout << std::asctime(std::gmtime(&result)) << result << " (UTC) seconds since the Epoch\n";
//   long int t = static_cast<long int> (result);
//   return(t);
// }
// MyString MyTime::getTimeUTC_Epoch_MyString() const{
//   MyString tstr(this->getTimeUTC_Epoch_Long());
//   return(tstr);
// }
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
