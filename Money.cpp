#include "Money.h"

// Money::Money(): currency = "USD", amount = 0.00 {}
Money::Money(){
  this->currency = "USD";
  this->amount = 0.00;
}
Money::Money(double amount){
  this->currency = "USD";
  this->amount = amount;
}
Money::Money(int amount){
  this->currency = "USD";
  this->amount = amount*1.0;
}
Money::Money(MyString currency, double amount){
  this->currency = currency;
  this->amount = amount;
}
Money::Money(MyString currency, int amount){
  this->currency = currency;
  this->amount = amount*1.0;
}
Money::Money(const Money & money){
  (*this) = money;
}
Money::~Money(){}

void Money::setAmount(const double amount){
  this->amount = amount;
}
void Money::setAmount(const int amount){
    this->amount = amount*1.0;
}
double Money::getAmount() const {  return this->amount; }

void Money::setCurrency(const MyString currency){
  this->currency = currency;
}
MyString Money::getCurrency() const  { return this->currency; }


void Money::operator=(const Money &money){
  this->currency = money.currency;
  this->amount = money.amount;
}
void Money::operator=(const double amount){
  this->currency = "USD";
  this->amount = amount;
}
void Money::operator=(const int amount){
  this->currency = "USD";
  this->amount = amount*1.0;
}

Money Money::operator+(const Money & money) const{
  Money tmp(*this);
  if(this->currency == money.currency){
    tmp.amount = this->amount + money.amount;
  }
  else{
    MyString e("Currencies does not match.");
    throw e;
  }
  return(tmp);
}
Money Money::operator+(const int amount) const{
  Money tmp(*this);
  tmp.amount = this->amount + amount*1.0;
  return(tmp);
}
Money Money::operator+(const double amount) const{
  Money tmp(*this);
  tmp.amount = this->amount + amount;
  return(tmp);
}
Money Money::operator-(const Money & money) const{
  Money tmp(*this);
  if(this->currency == money.currency){
    tmp.amount = this->amount - money.amount;
  }
  else{
    MyString e("Currencies does not match.");
    throw e;
  }
  return(tmp);
}
Money Money::operator-(const int amount) const{
  Money tmp(*this);
  tmp.amount = this->amount - amount*1.0;
  return(tmp);
}
Money Money::operator-(const double amount) const{
  Money tmp(*this);
  tmp.amount = this->amount - amount;
  return(tmp);
}
Money & Money::operator+=(const Money & money){
  // Money tmp(*this);
  if(this->currency == money.currency){
    // tmp.amount = this->amount + money.amount;
    this->amount = this->amount + money.amount;
  }
  else{
    MyString e("Currencies does not match.");
    throw e;
  }
  // return(tmp);
  return(*this);
}
Money & Money::operator+=(const int amount){
  // Money tmp(*this);
  // tmp.amount = this->amount + amount;
  // return(tmp);
  this->amount = this->amount + amount;
  return(*this);
}
Money & Money::operator+=(const double amount){
  // Money tmp(*this);
  // tmp.amount = this->amount + amount;
  // return(tmp);
  this->amount = this->amount + amount;
  return(*this);
}
Money & Money::operator-=(const Money & money){
  // Money tmp(*this);
  if(this->currency == money.currency){
    // tmp.amount = this->amount + money.amount;
    this->amount = this->amount - money.amount;
  }
  else{
    MyString e("Currencies does not match.");
    throw e;
  }
  // return(tmp);
  return(*this);
}
Money & Money::operator-=(const int amount){
  // Money tmp(*this);
  // tmp.amount = this->amount - amount;
  // return(tmp);
  this->amount = this->amount - amount;
  return(*this);
}
Money & Money::operator-=(const double amount){
  // Money tmp(*this);
  // tmp.amount = this->amount - amount;
  // return(tmp);
  this->amount = this->amount - amount;
  return(*this);
}
Money & Money::operator ++(){
  this->amount += 1.0;
  return(*this);
}
Money Money::operator ++(int amount){
  Money tmp(*this);
  operator++();
  return(tmp);
}

Money & Money::operator --(){
  this->amount -= 1.0;
  return(*this);
}
Money Money::operator --(int amount){
  Money tmp(*this);
  operator--();
  return(tmp);
}
bool operator==(const double amount) const{
  return(this->amount == amount);
}
bool operator==(const int amount) const{
  return(this->amount == amount*1.0);
}
bool operator==(const Money & money) const{
  return(this->amount == money.amount && this->currency == money.currency);
}
friend bool operator==(const Money & moneyA, const Money & moneyB){
  return(moneyA.amount == moneyB.amount && moneyA.currency == moneyB.currency);
}

// bool operator!=(const double amount) const{
//   return(this->amount != amount);
// }
// bool operator!=(const int amount) const{
//   return(this->amount != amount*1.0);
// }
// bool operator!=(const Money & money) const{
//   return(this->amount != money.amount && this->currency != money.currency);
// }
// friend bool operator!=(const Money & moneyA, const Money & moneyB){
//   return(moneyA.amount != moneyB.amount && moneyA.currency != moneyB.currency);
// }
//
// bool operator>(const double amount) const{
//   return(this->amount > amount);
// }
// bool operator>(const int amount) const{
//   return(this->amount > amount*1.0);
// }
// bool operator>(const Money & money) const{
//   return(this->amount > money.amount && this->currency > money.currency);
// }
// friend bool operator>(const Money & moneyA, const Money & moneyB){
//   return(moneyA.amount > moneyB.amount && moneyA.currency > moneyB.currency);
// }
//
// bool operator>=(const double amount) const{
//   return(this->amount >= amount);
// }
// bool operator>=(const int amount) const{
//   return(this->amount >= amount*1.0);
// }
// bool operator>=(const Money & money) const{
//   return(this->amount >= money.amount && this->currency >= money.currency);
// }
// friend bool operator>=(const Money & moneyA, const Money & moneyB){
//   return(moneyA.amount >= moneyB.amount && moneyA.currency >= moneyB.currency);
// }
//
// bool operator<(const double amount) const{
//   return(this->amount < amount);
// }
// bool operator<(const int amount) const{
//   return(this->amount < amount*1.0);
// }
// bool operator<(const Money & money) const{
//   return(this->amount < money.amount && this->currency < money.currency);
// }
// friend bool operator<(const Money & moneyA, const Money & moneyB){
//   return(moneyA.amount < moneyB.amount && moneyA.currency < moneyB.currency);
// }
//
// bool operator<=(const double amount) const{
//   return(this->amount <= amount);
// }
// bool operator<=(const int amount) const{
//   return(this->amount <= amount*1.0);
// }
// bool operator<=(const Money & money) const{
//   return(this->amount <= money.amount && this->currency <= money.currency);
// }
// friend bool operator<=(const Money & moneyA, const Money & moneyB){
//   return(moneyA.amount <= moneyB.amount && moneyA.currency <= moneyB.currency);
// }
