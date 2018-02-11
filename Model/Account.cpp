#include "Account.h"

Account::Account(MyString accName, MyString bankName, MyString accId, MyString accUserId, MyString accType, Money accBalance, double interest) :
    accName(accName), bankName(bankName), accId(accId), accUserId(accUserId), accType(accType), accBalance(accBalance), interest(interest) {}

Account::Account(const Account &acc){
  this->accName = acc.accName;
  this->bankName = acc.bankName;
  this->accId = acc.accId;
  this->accUserId = acc.accUserId;
  this->accType = acc.accType;
  this->accBalance = acc.accBalance;
  this->interest = acc.interest;
}
Account::~Account(){}

void Account::setAccName(MyString accName){ this->accName = accName;  }
void Account::setAccBankName(MyString bankName){ this->bankName = bankName;  }
void Account::setAccId(MyString accId){ this->accId = accId;  }
void Account::setAccUserId(MyString accUserId){  this->accUserId = accUserId;  }
void Account::setAccType(MyString accType){  this->accType = accType;  }
void Account::setAccInterest(double interest){  this->interest = interest;  }

MyString Account::getAccName() const{ return(this->accName); }
MyString Account::getAccBankName() const{ return(this->bankName); }
MyString Account::getAccId() const  { return(this->accId); }
MyString Account::getAccUserId() const  { return(this->accUserId); }
MyString Account::getAccType() const  { return(this->accType); }
Money Account::getAccBalance() const  { return(this->accBalance); }
double Account::getAccInterest() const  { return(this->interest); }

void Account::deposit(Money money){ this->accBalance += money; }
void Account::deposit(double money){  this->accBalance += money; }
void Account::deposit(int money){ this->accBalance += money; }

void Account::retire(Money money){
  if( (this->accBalance - money) >= 0.0 ){
    this->accBalance -= money;
  }else{
    MyString e("Not enough balance in account: ");
    e += this->accId;
    throw e;
  }
}
void Account::retire(double money){
  if( (this->accBalance - money) >= 0.0 ){
    this->accBalance -= money;
  }else{
    MyString e("Not enough balance in account: ");
    e += this->accId;
    throw e;
  }
}
void Account::retire(int money){
  if( (this->accBalance - money) >= 0.0 ){
    this->accBalance -= money;
  }else{
    MyString e("Not enough balance in account: ");
    e += this->accId;
    throw e;
  }
}

void Account::operator=(const Account & acc){
  this->accName = acc.accName;
  this->bankName = acc.bankName;
  this->accId = acc.accId;
  this->accUserId = acc.accUserId;
  this->accType = acc.accType;
  this->accBalance = acc.accBalance;
  this->interest = acc.interest;
}
bool Account::operator==(const Account & acc) const{
  return( this->bankName == acc.bankName && this->accId == acc.accId &&
    this->accUserId == acc.accUserId && this->accType == acc.accType );
}
bool Account::operator!=(const Account & acc) const{
  return( !((*this) == acc) );
}
