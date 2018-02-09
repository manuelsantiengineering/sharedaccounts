
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
User::User(const User &user){
  this->Person::operator=(user);
  this->userId = user.userId;
}
User::~User(){}

void User::operator=(const User &user){
  this->Person::operator=(user);
  this->userId = user.userId;
}

bool User::operator==(const User & user) const{
  return( this->name == user.name && this->lastName == user.lastName && this->age == user.age && this->userId == user.userId);
}
bool operator==(const User & userA, const User & userB){
  return( userA.name == userB.name && userA.lastName == userB.lastName && userA.age == userB.age && userA.userId == userB.userId);
}
bool User::operator!=(const User & user) const{
  return(this->name != user.name || this->lastName != user.lastName || this->age != user.age || this->userId != user.userId);
  // return( !( user == *this ) );
}
bool operator!=(const User & userA, const User & userB){
  return( userA.name != userB.name || userA.lastName != userB.lastName || userA.age != userB.age || userA.userId != userB.userId);
}
