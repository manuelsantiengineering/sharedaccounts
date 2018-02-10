//
//  MyTime.*
//
//  Created by Manuel E Santiago on 1/20/15.
//  Copyright (c) 2015 Manuel. All rights reserved.
//

#ifndef __MyTime__
#define __MyTime__

#include <stdio.h>
#include "../MyString.h"

class MyTime{
private:
    int seconds, minutes, hours;
    bool isAM;

public:
    MyTime(int seconds = 1, int minutes = 1, int hours = 1, bool isAM = true);
    MyTime(const MyTime & timeInstance);
    ~MyTime();
    MyTime & operator=(const MyTime & timeInstance);

    void setSeconds(int seconds);
    void setMinutes(int minutes);
    void setHours(int hours);

    int getSeconds() const;
    int getMinutes() const;
    int getHours() const;

    void showSeconds() const;
    void showMinutes() const;
    void showHours() const;
    void showTime() const;

    void askSeconds();
    void askMinutes();
    void askHours();
    void askTime();
    void askAMPM();

    MyString timeToString() const;

    bool operator == (const MyTime & timeInstance) const;
    bool operator != (const MyTime & timeInstance) const;
    bool operator > (const MyTime & timeInstance) const;
    bool operator < (const MyTime & timeInstance) const;

    friend ostream & operator<<(ostream & out, const MyTime & timeInstance);
    friend istream & operator>>(istream & in, MyTime & timeInstance);

};

#endif /* defined(__Lab03_CatalogoLibros__MyTime__) */
