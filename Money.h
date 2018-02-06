#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <exception>

#include "MyString.h"

using namespace std;

class Money
{
private:
  MyString currency;
  double amount;

public:
  Money();
  Money(double);
  Money(int);
  Money(MyString, double);
  Money(MyString, int);
  Money(const Money & money);
  ~Money();

  void setAmount(const double);
  void setAmount(const int);
  double getAmount() const;

  void setCurrency(const MyString);
  MyString getCurrency() const;

  void operator=(const Money &money);
  void operator=(const double);
  void operator=(const int);

  Money operator+(const Money & money) const;
  Money operator+(const int) const;
  Money operator+(const double) const;

  Money operator-(const Money & money) const;
  Money operator-(const int) const;
  Money operator-(const double) const;

  Money operator*(const Money & money) const;
  Money operator*(const int) const;
  Money operator*(const double) const;

  Money operator/(const Money & money) const;
  Money operator/(const int) const;
  Money operator/(const double) const;

  Money & operator+=(const Money & money);
  Money & operator+=(const int);
  Money & operator+=(const double);

  Money & operator-=(const Money & money);
  Money & operator-=(const int);
  Money & operator-=(const double);

  Money operator*=(const Money & money);
  Money operator*=(const int);
  Money operator*=(const double);

  Money operator/=(const Money & money);
  Money operator/=(const int);
  Money operator/=(const double);

  Money & operator ++();
  Money operator ++(int);

  Money & operator --();
  Money operator --(int);

  bool operator==(const double amount) const;
  bool operator==(const int amount) const;
  bool operator==(const Money & money) const;
  friend bool operator==(const Money & moneyA, const Money & moneyB);

  bool operator!=(const double amount) const;
  bool operator!=(const int amount) const;
  bool operator!=(const Money & money) const;
  friend bool operator!=(const Money & moneyA, const Money & moneyB);

  bool operator>(const double amount) const;
  bool operator>(const int amount) const;
  bool operator>(const Money & money) const;
  friend bool operator>(const Money & moneyA, const Money & moneyB);

  bool operator>=(const double amount) const;
  bool operator>=(const int amount) const;
  bool operator>=(const Money & money) const;
  friend bool operator>=(const Money & moneyA, const Money & moneyB);

  bool operator<(const double amount) const;
  bool operator<(const int amount) const;
  bool operator<(const Money & money) const;
  friend bool operator<(const Money & moneyA, const Money & moneyB);

  bool operator<=(const double amount) const;
  bool operator<=(const int amount) const;
  bool operator<=(const Money & money) const;
  friend bool operator<=(const Money & moneyA, const Money & moneyB);


};

#endif
