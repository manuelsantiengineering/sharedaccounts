//
//  User.*
//
//  Created by Manuel E Santiago on 2/1/2018.
//  Copyright (c) 2018 Manuel. All rights reserved.
//

#ifndef USER_H
#define USER_H

#include "./Person.h"

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

  void setUserId(MyString);
  MyString getUserId();
  bool isUserId(MyString);

  void operator=(const User &user);

  bool operator==(const User & user) const;
  bool operator!=(const User & user) const;

};

#endif
