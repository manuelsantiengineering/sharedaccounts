
#include "User.h"

User::User() : Person(), userId("XXXX-XXXX") {}
User::User(MyString userId) : Person(), userId(userId) {}
User::User(MyString name, MyString lastName, int age) : Person(name, lastName, age), userId("XXXX-XXXX") {}
User::User(MyString name, MyString lastName, int age, MyString userId) : Person(name, lastName, age), userId(userId) {}
User::User(const User &user){
  this->Person::operator=(user);
  this->userId = user.userId;
}
User::~User(){}

void User::setUserId(MyString userId){  this->userId = userId;  }

MyString User::getUserId(){ return(this->userId); }

bool User::isUserId(Mystring userId){
  return(this->userId == userId);
}

void User::operator=(const User &user){
  this->Person::operator=(user);
  this->userId = user.userId;
}

bool User::operator==(const User & user) const{
  Person personA(user);
  Person personB(*this);
  return(this->userId == user.userId && personA == personB);
}

bool User::operator!=(const User & user) const{
  return(!(*this == user));
}
