
#include "Person.h"

Person::Person(): name(""), lastName(""), age(18) {}
Person::Person(MyString name, MyString lastName, int age) : name(name), lastName(lastName){
  if(age < MAX_AGE){
    this->age = age;
  }
  else{
    MyString e("Value exceeds the maximum age.");
    throw e;
  }
}
Person::~Person(){}

void Person::setName(MyString name){  this->name = name; }

MyString const Person::getName(){ return this->name; }

void Person::setLastName(MyString lastName){  this->lastName = lastName; }

MyString const Person::getLastName(){ return this->lastName; }

void Person::setAge(int age){
  if(age < MAX_AGE){
    this->age = age;
  }
  else{
    MyString e("Value exceeds the maximum age.");
    throw e;
  }
}

int const Person::getAge(){ return this->age;  }

void Person::operator=(const Person &person){
    this->name = person.name;
    this->lastName = person.lastName;
    this->age = person.age;
}
bool Person::operator==(const Person & person) const{
  return(this->name == person.name && this->lastName == person.lastName && this->age == person.age);
}
bool operator==(const Person & personA, const Person & personB){
  return(personA.name == personB.name && personA.lastName == personB.lastName && personA.age == personB.age);
}
bool Person::operator!=(const Person & person) const{
  return(this->name != person.name || this->lastName != person.lastName || this->age != person.age);
}
bool operator!=(const Person & personA, const Person & personB){
  return(personA.name != personB.name || personA.lastName != personB.lastName || personA.age != personB.age);
}

static int getMaxAge(){ return(MAX_AGE);  }
