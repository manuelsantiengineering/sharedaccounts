
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
  // std::cout << "\t\t1 Hr: " << this->hours << " Min: " << this->minutes << " Sec: " << this->seconds << std::endl;
  if( this->seconds < 0 || this->minutes < 0 || this->hours < 0 ){
    MyString e("Time values must be greater or equal to 0.");
    throw e;
  }else{
    // if(this->seconds >= 60 || this->seconds <= 60){
    if(this->seconds >= 60){
      double divide = (this->seconds*1.0)/60.0;
      // std::cout << "\t\t\t2Divide: " << divide << std::endl;
      int rd = floor(divide);
      this->minutes += rd;
      divide = (divide-(rd*1.0))*60.0;
      // std::cout << "\t\t\t2Divide: " << divide << std::endl;
      this->seconds = round(divide);
      // std::cout << "\t\t2 Hr: " << this->hours << " Min: " << this->minutes << " Sec: " << this->seconds << std::endl;
    }
    // if(this->minutes >= 60 || this->minutes <= 60){
    if(this->minutes >= 60){
      double divide = (this->minutes*1.0)/60.0;
      // std::cout << "\t\t\t1Divide: " << divide << std::endl;
      int rd = floor(divide);
      this->hours += rd;
      divide = (divide-(rd*1.0))*60.0;
      // std::cout << "\t\t\t2Divide: " << divide << std::endl;
      this->minutes = round(divide);
      // std::cout << "\t\t3 Hr: " << this->hours << " Min: " << this->minutes << " Sec: " << this->seconds << std::endl;
    }
    // std::cout << "\t\t4 Hr: " << this->hours << " Min: " << this->minutes << " Sec: " << this->seconds << std::endl;
  }
  // std::cout << "\t\t5 Hr: " << this->hours << " Min: " << this->minutes << " Sec: " << this->seconds << std::endl;
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
  return(this->seconds + (this->minutes*60.0) + ((this->hours*3600.0)));
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
  out << timeInstance.timeToString_Seconds();
  return(out);
}
