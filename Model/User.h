
#ifndef USER_H
#define USER_H

#include "./Person.h"
// #include "../MyString.h"

using namespace std;

class User : public Person
{
private:
  MyString userId;

public:
  User();
  User(MyString);
  User(MyString, MyString, int);
  User(MyString, MyString, int, MyString);
  User(const User &user);
  ~User();

  void operator=(const User &user);

  bool operator==(const User & user) const;
  bool operator!=(const User & user) const;


};

#endif
