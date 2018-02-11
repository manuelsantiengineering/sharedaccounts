//
//  Account.*
//
//  Created by Manuel E Santiago on 2/11/2018.
//  Copyright (c) 2018 Manuel. All rights reserved.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

#include "Money.h"
#include "../Utilities/MyString.h"

class Account
{
protected:
  MyString accId;
  MyString userId;
  MyString type;
  Money balance;
  double interest;

public:
  Account(MyString accId="XXXXXX", MyString userId="", MyString type="Savings", Money balance=0.0, double interest=0.0);
  Account(const Account &acc);
  ~Account();

  void operator=(const Account & acc);
  bool operator==(const Account & acc) const;
  bool operator!=(const Account & acc) const;

  bool operator>(const double amount) const;
  bool operator>(const int amount) const;
  bool operator>(const Account & acc) const;
  friend bool operator>(const int & accA, const Account & accB);
  friend bool operator>(const double & accA, const Account & accB);
  friend bool operator>(const Money & accA, const Account & accB);

  bool operator>=(const double amount) const;
  bool operator>=(const int amount) const;
  bool operator>=(const Account & acc) const;
  friend bool operator>=(const int & accA, const Account & accB);
  friend bool operator>=(const double & accA, const Account & accB);
  friend bool operator>=(const Money & accA, const Account & accB);

  bool operator<(const double amount) const;
  bool operator<(const int amount) const;
  bool operator<(const Account & acc) const;
  friend bool operator<(const int & accA, const Account & accB);
  friend bool operator<(const double & accA, const Account & accB);
  friend bool operator<(const Money & accA, const Account & accB);

  bool operator<=(const double amount) const;
  bool operator<=(const int amount) const;
  bool operator<=(const Account & acc) const;
  friend bool operator<=(const int & accA, const Account & accB);
  friend bool operator<=(const double & accA, const Account & accB);
  friend bool operator<=(const Money & accA, const Account & accB);

};

#endif
