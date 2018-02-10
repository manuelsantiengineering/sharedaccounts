//
//  MyString.*
//
//  Created by Manuel E Santiago on 1/15/15.
//  Copyright (c) 2015 Manuel. All rights reserved.
//

#ifndef __MyString__
#define __MyString__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <cmath>

using namespace std;
const int STRING_MAX = 200;

class MyString{
private:
    char str[STRING_MAX + 1];

public:
    MyString(const char *str = ""); //Constructor with a blank default argument
    MyString(char ch);
    MyString(int value);
    ~MyString();
    MyString(const MyString & stringInstance); //Copy constructor

    void setS(const char *str); //Change function
    const char * getS() const; //Obtain value function

    MyString & operator=(const char *str);//Asigns a char array
    MyString & operator=(char ch);//Assigns a single char object
    MyString & operator=(const MyString & stringInstance);//Assigns a MyString object

    MyString operator+(const char *str) const;//Concatenates a char array
    MyString operator+(char ch) const;//Concatenates a single char object
    MyString operator+(const MyString & stringInstance) const;//Concatenates a MyString object

    friend MyString operator+(const char *str, const MyString & stringInstance);
    friend MyString operator+(char ch, const MyString & stringInstance);

    bool operator==(const char *str) const;//Compares if equal to a char array
    bool operator==(const MyString & stringInstance) const;//Compares if equal to a MyString object
    friend bool operator==(const char *str, const MyString & stringInstance); //Compares if a char array if equal to a MyString object using a operator that is not a member of the class

    bool operator!=(const char *str) const;//Compares if not equal to a char array
    bool operator!=(const MyString & stringInstance) const;//Compares if not equal to a MyString object
    friend bool operator!=(const char *str, const MyString & stringInstance); //Compares if a char array if not equal to a MyString object using a operator that is not a member of the class

    bool operator>(const char *str) const;//Compares if greater to a char array
    bool operator>(const MyString & stringInstance) const;//Compares if greater to a MyString object
    friend bool operator>(const char *str, const MyString & stringInstance); //Compares if a char array if greater to a MyString object using a operator that is not a member of the class

    bool operator<(const char *str) const;//Compares if lower to a char array
    bool operator<(const MyString & stringInstance) const;//Compares if lower to a MyString object
    friend bool operator<(const char *str, const MyString & stringInstance); //Compares if a char array if lower to a MyString object using a operator that is not a member of the class

    const char & operator[](int index) const; //gets a character
    char & operator[](int index); //sets a character

    friend istream & operator >>(istream & in, MyString & stringInstance);
    friend ostream & operator <<(ostream & out, const MyString & stringInstance);

    MyString & operator+=(const char *str);
    MyString & operator+=(char ch);
    MyString & operator+=(const MyString & stringInstance);
    MyString & operator ++();
    MyString operator ++(int);
    MyString & operator --();
    MyString operator --(int);

    int len() const;
    int indexOf(char ch) const;
    int indexOfLast(char ch) const;
    int frequency(char ch) const;
    int frequency(const char *str) const;
    int frequency(const MyString & stringInstance) const;
    MyString trimLeadingSpaces() const;
    MyString trimEndingSpaces() const;
    MyString trimAllSpaces() const;
    MyString toUppercase() const;
    MyString toLowercase() const;
    MyString createSubstring(int from, int to) const;
    MyString reverse() const;
    bool isEmpty() const;
    bool include(char ch) const;
    bool representAnUnsignInteger() const;
    bool representAnInteger() const;
    bool representAReal() const;
    int cambiaInt() const;

    //Function for the Class
    static int MaxLen();
};

#endif /* defined(__MyString__) */
