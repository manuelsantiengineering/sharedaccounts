//
//  MyString.cpp
//  Lab03_CatalogoLibros
//
//  Created by Manuel E Santiago on 1/15/15.
//  Copyright (c) 2015 Manuel. All rights reserved.
//

#include "MyString.h"

MyString::MyString(const char *str){
    (*this) = str;
}
MyString::MyString(char ch){
    (*this) = ch;
}
MyString::MyString(int value){
    sprintf(this->str, "%d", value);
}
MyString::~MyString(){
}
MyString::MyString(const MyString & stringInstance){
    (*this)= stringInstance;
}
void MyString::setS(const char *str){
    strcpy(this->str, str);
}
const char * MyString::getS() const{
    return(this->str);
}

//Assign Operators
MyString & MyString::operator=(const char *str){
    strcpy(this->str, str);
    return(*this);
}
MyString & MyString::operator=(char ch){
    (*this)="";
    (*this)= (*this) + ch;
    return(*this);
}
MyString & MyString::operator=(const MyString & stringInstance){
    strcpy(this->str,stringInstance.str);
    return(*this);
}

MyString MyString::operator+(const char *str) const{
    MyString r(*this); //Calls the copy constructor
    strcat(r.str, str);
    return(r);
}
MyString MyString::operator+(char ch) const{
    MyString r(*this); //Calls the copy constructor
    if((this->len() +1) <= STRING_MAX){
    //strcat(r.str, str);
        (r.str)[this->len()] = ch;
        (r.str)[this->len()+1] = '\0';
    }
    return(r);
}
MyString MyString::operator+(const MyString & stringInstance) const{
    return((*this)+ stringInstance.str);
}
//Friend operators
MyString operator+(const char *str, const MyString & stringInstance){
    return (MyString(str) + stringInstance);
}
MyString operator+(char ch, const MyString & stringInstance){
    return(MyString(ch) + stringInstance);
}

bool MyString::operator==(const char *str) const{
    return (strcmp(this->str, str) == 0);
}
bool MyString::operator==(const MyString & stringInstance) const{
    return(strcmp(this->str, stringInstance.str) == 0);
}
bool operator==(const char *str, const MyString & stringInstance){ //friend
    return(strcmp(str, stringInstance.str) == 0);
}
bool MyString::operator!=(const char *str) const{
    return (strcmp(this->str, str) != 0);
}
bool MyString::operator!=(const MyString & stringInstance) const{
    return(strcmp(this->str, stringInstance.str) != 0);
}
bool operator!=(const char *str, const MyString & stringInstance){ //friend
    return(strcmp(str, stringInstance.str) != 0);
}

bool MyString::operator>(const char *str) const{
    return(strcmp(this->str, str) > 0);
}
bool MyString::operator>(const MyString & stringInstance) const{
    return(strcmp(this->str, stringInstance.str) > 0);
}
bool operator>(const char *str, const MyString & stringInstance){
    return(strcmp(str, stringInstance.str) > 0);
}
bool MyString::operator<(const char *str) const{
    return(strcmp(this->str, str) < 0);
}
bool MyString::operator<(const MyString & stringInstance) const{
    return(strcmp(this->str, stringInstance.str) < 0);
}
bool operator<(const char *str, const MyString & stringInstance){
    return(strcmp(str, stringInstance.str) < 0);
}
const char & MyString::operator[](int index) const{
    return((this->str)[index]);
}
char & MyString::operator[](int index){
    return((this->str)[index]);
}
istream & operator >>(istream & in, MyString & stringInstance){
    char ch;
    stringInstance = "";

    ch = in.get();
    while (ch == '\n'){
        ch = in.get();
    }
    while (ch != '\n'){
        stringInstance = stringInstance + ch;
        ch = in.get();
    }
    return(in);
}
ostream & operator <<(ostream & out, const MyString & stringInstance){
    out << stringInstance.str;
    return(out);
}
MyString & MyString::operator+=(const char *str){
    return((*this) = (*this) + str);
}
MyString & MyString::operator+=(char ch){
    return((*this) = (*this) + ch);
}
MyString & MyString::operator+=(const MyString & stringInstance){
    return((*this) = (*this) + stringInstance);
}
MyString & MyString::operator ++(){
    return ((*this) = this->toUppercase());
}
MyString MyString::operator ++(int){
    MyString r(*this);
    (*this) = this->toUppercase();
    return (r);
}
MyString & MyString::operator --(){
    return ((*this) = this->toLowercase());
}
MyString MyString::operator --(int){
    MyString r(*this);
    (*this) = this->toLowercase();
    return (r);
}
int MyString::len() const{
    return(round(strlen(this->str)));
}
int MyString::indexOf(char ch) const{
    int index = -1;

    for (int i = 0; (i < this->len()) && (index == -1); i++){
        if((this->str)[i] == ch){
            index = i;
        }
    }
    return (index);
}
int MyString::indexOfLast(char ch) const{
    int index = -1;

    for (int i = this->len(); (i >= 0) && (index == -1); i--){
        if((this->str)[i] == ch){
            index = i;
        }
    }
    return (index);
}
int MyString::frequency(char ch) const{
    int freq = 0;

    for (int i =0; i < this->len(); i++){
        if((this->str)[i] == ch){
            freq++;
        }
    }
    return (freq);
}
int MyString::frequency(const char *str) const{
    int freq = 0;
    int firsti = 0;
    int lasti = 0;
    MyString r;

    for (int i =0; i < this->len(); i++){
        if((this->str)[i] == '\t'|| (this->str)[i] == ' '){
            lasti = i;
            r = this->createSubstring(firsti, lasti-1);
            if(r == str){
                freq++;
            }
        }
        firsti = lasti + 1;
    }
    return (freq);
}
int MyString::frequency(const MyString & stringInstance) const{
    int freq = 0;
    int firsti = 0;
    int lasti = 0;
    MyString r;

    for (int i =0; i < this->len(); i++){
        if((this->str)[i] == '\t'|| (this->str)[i] == ' '){
            lasti = i;
            r = this->createSubstring(firsti, lasti-1);
            if(r == stringInstance){
                freq++;
            }
        }
        firsti = lasti + 1;
    }
    return (freq);
}
MyString MyString::trimLeadingSpaces() const{
    MyString r;
    for (int i = 0; (this->str)[i] == '\t'|| (this->str)[i] == ' '; i++){
        for( ; i < this->len(); i++){
            r = (this->str)[i] + r;
        }
    }
    return (r);
}
MyString MyString::trimEndingSpaces() const{
    MyString r;
    for (int i = this->len(); (this->str)[i] == '\t'|| (this->str)[i] == ' '; i--){
        for( ; i >= 0; i--){
            r = (this->str)[i] + r;
        }
    }
    return (r);
}
MyString MyString::trimAllSpaces() const{
    MyString r;
    for(int i = 0; i < this->len(); i++){
        if ((this->str)[i] != '\t' && (this->str)[i] != ' '){
            r = r + (this->str)[i];
        }
    }
    return (r);
}
MyString MyString::toUppercase() const{
    MyString r(*this);
    for(int i = 0; i < this->len(); i++){
        if((this->str)[i] >= 'a' && (this->str)[i] <= 'z'){
            (r.str)[i] = (this->str)[i] - 32;
        }
    }
    return(r);
}
MyString MyString::toLowercase() const{
    MyString r(*this);
    for(int i = 0; i < this->len(); i++){
        if((this->str)[i] >= 'A' && (this->str)[i] <= 'Z'){
            (r.str)[i] = (this->str)[i] + 32;
        }
    }
    return(r);
}
MyString MyString::createSubstring(int from, int to) const{
    MyString r;
    if(from >= 0 && to < this->len()){
        for(int i = from; i <= to; i++){
            r = r +(this->str)[i];
        }
    }
    return (r);
}
MyString MyString::reverse() const{
    MyString r(*this);
    char ch;
    for(int i = 0, j = this->len()-1; i < j; i++, j--){
        ch = (r.str)[i];
        (r.str)[i] = (r.str)[j];
        (r.str)[j] = ch;
    }
    return (r);
}
bool MyString::isEmpty() const{
    return(this->len() == 0);
}
bool MyString::include(char ch) const{
    bool found = false;

    for(int i = 0; i < this->len() && !found; i++){
        if((this->str)[i] == ch){
            found = true;
        }
    }
    return (found);
}
bool MyString::representAnUnsignInteger() const{
    bool represent = true;
    for(int i =0; i < this->len() && represent; i++){
        if((this->str)[i] < '0' || (this->str)[i] > '9'){
            represent = false;
        }
    }
    return (represent && this->len() > 0);
}
bool MyString::representAnInteger() const{
    MyString r(*this);
    if((this->str)[0] == '+' || (this->str)[0] == '-'){
        r = this->createSubstring(1, this->len()-1);
    }
    return (r.representAnUnsignInteger());
}
bool MyString::representAReal() const{
    int point = this->indexOf('.');
    MyString prefix, sufix;
    bool valid;

    if(point != -1){
        prefix = this->createSubstring(0, point - 1);
        sufix = this->createSubstring(point + 1, this->len() - 1);
        valid = prefix.representAnInteger() && sufix.representAnInteger();
    }else{
        valid = this->representAnInteger();
    }
    return (valid);
}
int MyString::cambiaInt() const{
    int x = atoi(this->str);
    return(x);
}
//Function for the Class
static int MaxLen(){
    return(STRING_MAX);
}
