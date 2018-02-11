#include "Money.h"

Money::Money() : currency("USD"), amount(0.00) {}

Money::Money(double amount) : currency("USD"), amount(amount) {}

Money::Money(int amount){
  this->currency = "USD";
  this->amount = amount*1.0;
}

Money::Money(MyString currency, double amount) : currency(currency), amount(amount) {}

Money::Money(MyString currency, int amount){
  this->currency = currency;
  this->amount = amount*1.0;
}
Money::Money(const Money & money){
  this->currency = money.currency;
  this->amount = money.amount;
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
    MyString e("Can't add. Currencies does not match.");
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
    MyString e("Can't subtract. Currencies does not match.");
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
Money Money::operator*(const Money & money) const{
  Money tmp(*this);
  if(this->currency == money.currency){
    tmp.amount = this->amount * money.amount;
  }
  else{
    MyString e("Can't multiply. Currencies does not match.");
    throw e;
  }
  return(tmp);
}
Money Money::operator*(const int amount) const{
  Money tmp(*this);
  tmp.amount = this->amount * amount*1.0;
  return(tmp);
}
Money Money::operator*(const double amount) const{
  Money tmp(*this);
  tmp.amount = this->amount * amount;
  return(tmp);
}

Money Money::operator/(const Money & money) const{
  Money tmp(*this);
  if(this->currency == money.currency){
    tmp.amount = this->amount / money.amount;
  }
  else{
    MyString e("Can't divide. Currencies does not match.");
    throw e;
  }
  return(tmp);
}
Money Money::operator/(const int amount) const{
  Money tmp(*this);
  tmp.amount = this->amount/(amount*1.0);
  return(tmp);
}
Money Money::operator/(const double amount) const{
  Money tmp(*this);
  tmp.amount = this->amount/amount;
  return(tmp);
}

Money & Money::operator+=(const Money & money){
  if(this->currency == money.currency){
    this->amount = this->amount + money.amount;
  }
  else{
    MyString e("Can't add. Currencies does not match.");
    throw e;
  }
  return(*this);
}
Money & Money::operator+=(const int amount){
  this->amount = this->amount + amount;
  return(*this);
}
Money & Money::operator+=(const double amount){
  this->amount = this->amount + amount;
  return(*this);
}
Money & Money::operator-=(const Money & money){
  if(this->currency == money.currency){
    this->amount = this->amount - money.amount;
  }
  else{
    MyString e("Can't subtract. Currencies does not match.");
    throw e;
  }
  return(*this);
}
Money & Money::operator-=(const int amount){
  this->amount = this->amount - amount;
  return(*this);
}
Money & Money::operator-=(const double amount){
  this->amount = this->amount - amount;
  return(*this);
}


Money Money::operator*=(const Money & money){
  if(this->currency == money.currency){
    this->amount = this->amount * money.amount;
  }
  else{
    MyString e("Can't multiply. Currencies does not match.");
    throw e;
  }
  return(*this);
}
Money Money::operator*=(const int amount){
  this->amount = this->amount * amount;
  return(*this);
}
Money Money::operator*=(const double amount){
  this->amount = this->amount * amount;
  return(*this);
}

Money Money::operator/=(const Money & money){
  if(this->currency == money.currency){
    this->amount = this->amount / money.amount;
  }
  else{
    MyString e("Can't divide. Currencies does not match.");
    throw e;
  }
  return(*this);
}
Money Money::operator/=(const int amount){
  this->amount = this->amount / amount;
  return(*this);
}
Money Money::operator/=(const double amount){
  this->amount = this->amount / amount;
  return(*this);
}

Money & Money::operator++(){
  this->amount += 1.0;
  return(*this);
}
Money Money::operator++(int amount){
  Money tmp(*this);
  operator++();
  return(tmp);
}

Money & Money::operator--(){
  this->amount -= 1.0;
  return(*this);
}
Money Money::operator--(int amount){
  Money tmp(*this);
  operator--();
  return(tmp);
}
bool  Money::operator==(const double amount) const{
  return(this->amount == amount);
}
bool  Money::operator==(const int amount) const{
  return(this->amount == amount*1.0);
}
bool  Money::operator==(const Money & money) const{
  return(this->amount == money.amount && this->currency == money.currency);
}
bool operator==(const int & moneyA, const Money & moneyB){
  return(moneyA == moneyB.amount);
}
bool operator==(const double & moneyA, const Money & moneyB){
  return(moneyA == moneyB.amount);
}

bool Money::operator!=(const double amount) const{
  return(this->amount != amount);
}
bool Money::operator!=(const int amount) const{
  return(this->amount != amount*1.0);
}
bool Money::operator!=(const Money & money) const{
  return(this->amount != money.amount || this->currency != money.currency);
}
bool operator!=(const int & moneyA, const Money & moneyB){
  return(moneyA != moneyB.amount);
}
bool operator!=(const double & moneyA, const Money & moneyB){
  return(moneyA != moneyB.amount);
}

bool Money::operator>(const double amount) const{
  return(this->amount > amount);
}
bool Money::operator>(const int amount) const{
  return(this->amount > amount*1.0);
}
bool Money::operator>(const Money & money) const{
  return(this->amount > money.amount);
}
bool operator>(const int & moneyA, const Money & moneyB){
  return(moneyA > moneyB.amount);
}
bool operator>(const double & moneyA, const Money & moneyB){
  return(moneyA > moneyB.amount);
}

bool Money::operator>=(const double amount) const{
  return(this->amount >= amount);
}
bool Money::operator>=(const int amount) const{
  return(this->amount >= amount*1.0);
}
bool Money::operator>=(const Money & money) const{
  return(this->amount >= money.amount);
}
bool operator>=(const int & moneyA, const Money & moneyB){
  return(moneyA >= moneyB.amount);
}
bool operator>=(const double & moneyA, const Money & moneyB){
  return(moneyA >= moneyB.amount);
}

bool Money::operator<(const double amount) const{
  return(this->amount < amount);
}
bool Money::operator<(const int amount) const{
  return(this->amount < amount*1.0);
}
bool Money::operator<(const Money & money) const{
  return(this->amount < money.amount);
}
bool operator<(const int & moneyA, const Money & moneyB){
  return(moneyA < moneyB.amount);
}
bool operator<(const double & moneyA, const Money & moneyB){
  return(moneyA < moneyB.amount);
}

bool Money::operator<=(const double amount) const{
  return(this->amount <= amount);
}
bool Money::operator<=(const int amount) const{
  return(this->amount <= amount*1.0);
}
bool Money::operator<=(const Money & money) const{
  return(this->amount <= money.amount);
}
bool operator<=(const int & moneyA, const Money & moneyB){
  return(moneyA <= moneyB.amount);
}
bool operator<=(const double & moneyA, const Money & moneyB){
  return(moneyA <= moneyB.amount);
}
std::ostream & operator <<(std::ostream & out, const Money & money){
  out << "$" << std::fixed << std::setprecision(2) << money.getAmount();
  return(out);
}
