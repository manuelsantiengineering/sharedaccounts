//
//  Account.*
//
//  Created by Manuel E Santiago on 2/11/2018.
//  Copyright (c) 2018 Manuel. All rights reserved.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <exception>

#include "Money.h"
#include "../Utilities/MyString.h"

class Account
{
protected:
  MyString accName;
  MyString bankName;
  MyString accId;
  MyString accUserId;
  MyString accType;
  Money accBalance;
  double interest;

  void setAccName(MyString accName);
  void setAccBankName(MyString bankName);
  void setAccId(MyString accId);
  void setAccUserId(MyString accUserId);
  void setAccType(MyString accType);
  void setAccInterest(double interest);

public:
  Account(MyString accName="", MyString bankName="", MyString accId="XXXXXX", MyString accUserId="", MyString accType="Savings", Money accBalance=0.0, double interest=0.0);
  Account(const Account &acc);
  ~Account();

  MyString getAccName() const;
  MyString getAccBankName() const;
  MyString getAccId() const;
  MyString getAccUserId() const;
  MyString getAccType() const;
  Money getAccBalance() const;
  double getAccInterest() const;

  void deposit(Money &money);
  void deposit(double money);
  void deposit(int money);

  void retire(Money &money);
  void retire(double money);
  void retire(int money);

  void operator=(const Account & acc);
  bool operator==(const Account & acc) const;
  bool operator!=(const Account & acc) const;

};

#endif
