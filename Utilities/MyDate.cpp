//
//  MyDate.cpp
//  Lab03_CatalogoLibros
//
//  Created by Manuel E Santiago on 1/20/15.
//  Copyright (c) 2015 Manuel. All rights reserved.
//

#include "MyDate.h"

MyDate::MyDate(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}
MyDate::MyDate(const MyDate & dateInstance){
    this->day = dateInstance.day;
    this->month = dateInstance.month;
    this->year = dateInstance.year;
}
MyDate::~MyDate(){
}
MyDate & MyDate::operator=(const MyDate & dateInstance){
    this->day = dateInstance.day;
    this->month = dateInstance.month;
    this->year = dateInstance.year;
    return(*this);
}
void MyDate::askMonth(){
    do{
        cout << "Enter the month: ";
        cin >> this->month;
        if(this->month < 1 || this->month > 12){
            cout << "Invalid month value." << endl;
        }
    }while(this->month < 1 || this->month > 12);
}
void MyDate::askDay(){
    int maxDays = 0;
    
    do{
        if(this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12){
            maxDays = 31;
        }else if(this->month !=2){
            maxDays = 30;
        }else if(this->month == 2 && this->isLeapYear()){
            maxDays = 29;
        }else{
            maxDays = 28;
        }
        cout << "Enter the day: ";
        cin >> this->day;
    }while(this->day < 1 || this->day > maxDays);
}
void MyDate::askYear(){
    do{
        cout << "Enter the year: ";
        cin >> this->year;
        if(this->year < 1900){
            cout << "Invalid year value." << endl;
        }
    }while(this->year < 1900);
    
}
void MyDate::askDate(){
    this->askMonth();
    this->askDay();
    this->askYear();
}
void MyDate::setDate(int d, int m, int y){
    this->day = d;
    this->month = m;
    this->year = y;
}

int MyDate::getDay() const{
    return (this->day);
}
int MyDate::getMonth() const{
    return (this->month);
}
int MyDate::getYear() const{
    return (this->year);
}
void MyDate::showDay() const{
    cout << this->day;
}
void MyDate::showMonth() const{
    cout << this->month;
}
void MyDate::showYear() const{
    cout << this->year;
}
void MyDate::showDate() const{
    cout << this->month << "/" << this->day << "/" << this->year;
}
MyString MyDate::dateToString() const{
    MyString temporal="";
    temporal = temporal + MyString(this->month) + "/" + MyString(this->day) + "/"+ MyString(this->year);
    return (temporal);
}

bool MyDate::isLeapYear() const{
    return((this->year%400 == 0) || (this->year%100 != 0 && this->year%4 == 0));
}

bool MyDate::operator ==(const MyDate & dateInstance) const{
    return (this->day == dateInstance.day && this->month == dateInstance.month && this->year == dateInstance.year);
}
bool MyDate::operator !=(const MyDate & dateInstance) const{
    return(!(this->day == dateInstance.day && this->month == dateInstance.month && this->year == dateInstance.year));
}
bool MyDate::operator >(const MyDate & dateInstance) const{
    return((this->year > dateInstance.year) || (this->year == dateInstance.year && this->month > dateInstance.month) || (this->year == dateInstance.year && this->month == dateInstance.month && this->day > dateInstance.day));
}
bool MyDate::operator <(const MyDate & dateInstance) const{
    return(!((*this) > dateInstance) || (*this) == dateInstance);
}
ostream & operator<<(ostream & out, const MyDate dateInstance){
    dateInstance.showDate();
    return(out);
}
istream & operator>>(istream & in, MyDate dateInstance){
    dateInstance.askDate();
    return(in);
}
