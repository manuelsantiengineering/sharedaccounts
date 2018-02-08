
#include "User.h"

User::User() : Person(), userId("XXXX-XXXX") {
  // this->Person::Person();
}
User::User(MyString userId) : Person(), userId(userId) {
  // this->Person::Person();
}
User::User(MyString name, MyString lastName, int age) : Person(name, lastName, age), userId("XXXX-XXXX") {
  // this->Person::Person(name, lastName, age);
}
User::User(MyString name, MyString lastName, int age, MyString userId) : Person(name, lastName, age), userId(userId) {
  // this->Person::Person(name, lastName, age);
}
User::~User(){}

void User::operator=(const User &user){
  this->Person::operator=(user);
  this->userId = user.userId;
  return(*this);
}

bool User::operator==(const User & user) const{
  return(this->Person::operator==(user) && this->userId == user.userId);
}
bool operator==(const User & userA, const User & userB){
  return(this->Person::operator==(userA, userB) && userA.userId == userB.userId);
}

bool User::operator!=(const User & user) const{
  return(this->Person::operator!=(user) || this->userId != user.userId);
}
bool operator!=(const User & userA, const User & userB){
  return(this->Person::operator!=(userA, userB) || userA.userId != userB.userId);
}
