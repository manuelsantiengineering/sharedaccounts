
#include "Person.h"

// Person::Person(): name = "", lastName = "", age = 18 {}
Person::Person(){
  this->name = "";
  this->lastName = "";
  this->age = 18;
}
Person::Person(MyString name, MyString lastName, int age){
  this->name = name;
  this->lastName = lastName;
  this->age = age;
}
Person::~Person(){}

void Person::setName(MyString name){  this->name = name; }

MyString const Person::getName(){ return this->name; }

void Person::setLastName(MyString lastName){  this->lastName = lastName; }

MyString const Person::getLastName(){ return this->lastName; }

void Person::setAge(int age){ this->age = age; }

int const Person::getAge(){ return this->age;  }
