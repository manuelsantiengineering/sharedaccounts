#include "Account.h"

Account::Account(MyString accId, MyString userId, MyString type, Money balance, double interest) :
    accId(accId), userId(userId), type(type), balance(balance), interest(interest) {}

Account::Account(const Account &acc){
  this->accId = acc.accId;
  this->userId = acc.userId;
  this->type = acc.type;
  this->balance = acc.balance;
  this->interest = acc.interest;
}
Account::~Account(){}
