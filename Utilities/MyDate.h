//
//  MyDate.*
//
//  Created by Manuel E Santiago on 1/20/15.
//  Copyright (c) 2015 Manuel. All rights reserved.
//

#ifndef __MyDate__
#define __MyDate__

#include <stdio.h>
#include <iostream>
#include <exception>
#include "MyString.h"

using namespace std;

class MyDate{
private:
    int day, month, year;

public:
    MyDate(int day=1, int month=1, int year=1990);
    MyDate(const MyDate & dateInstance);
    ~MyDate();
    MyDate & operator=(const MyDate & dateInstance);

    void setDate(int d, int m, int y);
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    MyString dateToMyStringNumbers() const;
    MyString dateToMyString() const;
    bool dateIsCorrect(const int, const int, const int) const;

    bool isLeapYear() const;

    bool operator ==(const MyDate & dateInstance) const;
    bool operator !=(const MyDate & dateInstance) const;
    bool operator >=(const MyDate & dateInstance) const;
    bool operator >(const MyDate & dateInstance) const;
    bool operator <=(const MyDate & dateInstance) const;
    bool operator <(const MyDate & dateInstance) const;

    friend ostream & operator<<(ostream & out, const MyDate dateInstance);
};

#endif /* defined(__MyDate__) */
