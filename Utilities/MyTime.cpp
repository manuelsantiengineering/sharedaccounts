//
//  MyTime.cpp
//  Lab03_CatalogoLibros
//
//  Created by Manuel E Santiago on 1/20/15.
//  Copyright (c) 2015 Manuel. All rights reserved.
//

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
void MyTime::setSeconds(int seconds){
    this->seconds = seconds;
}
void MyTime::setMinutes(int minutes){
    this->minutes = minutes;
}
void MyTime::setHours(int hours){
    this->hours = hours;
}

int MyTime::getSeconds() const{
    return(this->seconds);
}
int MyTime::getMinutes() const{
    return(this->minutes);
}
int MyTime::getHours() const{
    return(this->hours);
}
void MyTime::showSeconds() const{
    cout << this->seconds << " seconds ";
}
void MyTime::showMinutes() const{
    cout << this->minutes << " minutes ";
}
void MyTime::showHours() const{
    cout << this->hours << " hours ";
}
void MyTime::showTime() const{
    if(this->hours < 10){
        cout << "0" << this->hours << ":";
    }else{
        cout << this->hours << ":";
    }
    if(this->minutes < 10){
        cout << "0" << this->minutes << ":";
    }else{
        cout << this->minutes << ":";
    }
    if(this->seconds < 10){
        cout << "0" << this->seconds;
    }else{
        cout << this->seconds;
    }
    if(this->isAM == true){
        cout << " AM " ;
    }else{
        cout << " PM " ;
    }
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
void MyTime::askAMPM(){
    MyString AMPM;
    this->isAM = true;
    do{
        cout << "Is it AM or PM: ";
        cin >> AMPM;
        AMPM = AMPM.toUppercase();

        if(AMPM == "PM"){
            this->isAM = false;
        }else if(AMPM != "PM" && AMPM != "AM"){
            cout << "Not a valid input!" << endl;
        }
    }while (AMPM != "PM" && AMPM != "AM");
}
void MyTime::askSeconds(){
    do{
        cout << "Enter the seconds: ";
        cin >> this->seconds;
        if(this->seconds < 0 || this->seconds > 59){
            cout << "Invalid input!" << endl;
        }
    }while(this->seconds < 0 || this->seconds > 59);
}
void MyTime::askMinutes(){
    do{
        cout << "Enter the minutes: ";
        cin >> this->minutes;
        if(this->minutes < 0 || this->minutes > 59){
            cout << "Invalid input!" << endl;
        }
    }while(this->minutes < 0 || this->minutes > 59);
}
void MyTime::askHours(){
    do{
        cout << "Enter the hours: ";
        cin >> this->hours;
        if(this->hours < 0 || this->hours > 12){
            cout << "Invalid input!" << endl;
        }
    }while(this->hours < 0 || this->hours > 12);
}
void MyTime::askTime(){
    this->askHours();
    this->askMinutes();
    this->askSeconds();
    this->askAMPM();
}
bool MyTime::operator == (const MyTime & timeInstance) const{
    return((this->seconds == timeInstance.seconds) && (this->minutes == timeInstance.minutes) && (this->hours == timeInstance.hours) && (this->isAM == timeInstance.isAM));
}
bool MyTime::operator != (const MyTime & timeInstance) const{
    return(!((*this) == timeInstance));
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
bool MyTime::operator < (const MyTime & timeInstance) const{
    return(!((*this) == timeInstance) && !((*this) > timeInstance));
}
ostream & operator<<(ostream & out, const MyTime & timeInstance){
    timeInstance.showTime();
    return(out);
}
istream & operator>>(istream & in, MyTime & timeInstance){
    timeInstance.askTime();
    return(in);
}
