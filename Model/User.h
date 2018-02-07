
#ifndef USER_H
#define USER_H

#include "../Person.h"
#include "../MyString.h"

using namespace std;

class User
{
private:
  MyString test;

public:
  User();
  User(MyString test);
  ~User();
};

#endif
