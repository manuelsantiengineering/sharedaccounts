
#ifndef USER_H
#define USER_H

#include "../Person.h"
#include "../MyString.h"

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
  ~User();

  void operator=(const User &user);

  bool operator==(const User & user) const;
  friend bool operator==(const User & userA, const User & userB);

  bool operator!=(const User & user) const;
  friend bool operator!=(const User & userA, const User & userB);


};

#endif
