//
//  MyDate.h
//  Lab03_CatalogoLibros
//
//  Created by Manuel E Santiago on 1/20/15.
//  Copyright (c) 2015 Manuel. All rights reserved.
//

#ifndef __Lab03_CatalogoLibros__MyDate__
#define __Lab03_CatalogoLibros__MyDate__

#include <stdio.h>
#include <iostream>
#include "MyString.h"

using namespace std;

class MyDate{
private:
    int day, month, year;
    //MyString day, month, year;
    
    void askMonth();
    void askDay();
    void askYear();
    void askDate();
    
public:
    MyDate(int day=1, int month=1, int year=2015);
    MyDate(const MyDate & dateInstance);
    ~MyDate();
    MyDate & operator=(const MyDate & dateInstance);
    
    void setDate(int d, int m, int y);
    
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    
    void showDay() const;
    void showMonth() const;
    void showYear() const;
    void showDate() const;
    
    MyString dateToString() const;
    
    bool isLeapYear() const;
    
    bool operator ==(const MyDate & dateInstance) const;
    bool operator !=(const MyDate & dateInstance) const;
    bool operator >(const MyDate & dateInstance) const;
    bool operator <(const MyDate & dateInstance) const;
    
    friend ostream & operator<<(ostream & out, const MyDate dateInstance);
    friend istream & operator>>(istream & in, MyDate dateInstance);
};

#endif /* defined(__Lab03_CatalogoLibros__MyDate__) */
