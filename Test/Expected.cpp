
#include "Expected.h"

// Expected::Expected() {}
Expected::Expected(MyString name) : className(name) {}

void Expected::setClassName(MyString className){  this->className = className;  }

Expected::~Expected(){}

void Expected::expect(MyString functionName, int functionResult, int expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, double functionResult, double expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, MyString functionResult, MyString expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, bool functionResult, bool expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, float functionResult, float expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, Person functionResult, Person expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult.getName() << " == " << expectedResult.getName()  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult.getName() << " != " << expectedResult.getName()  << std::endl;
  }
}
void Expected::expect(MyString functionName, User functionResult, User expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult.getUserId() << " == " << expectedResult.getUserId()  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult.getUserId() << " != " << expectedResult.getUserId()  << std::endl;
  }
}
void Expected::expect(MyString functionName, Money functionResult, Money expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult.getAmount() << " == " << expectedResult.getAmount()  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult.getAmount() << " != " << expectedResult.getAmount()  << std::endl;
  }
}
void Expected::expect(MyString functionName, MyDate functionResult, MyDate expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, MyTime functionResult, MyTime expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}

void Expected::testConstructor(Person person, MyString name, MyString lastName, int age){
  std::cout << "Testing Class: " << this->className << " , Function: Constructor() " << " Results: ";
  if( name == person.getName() && lastName == person.getLastName() && age == person.getAge() ){
    std::cout << "SUCCESS! " << std::endl;
  }else{
    std::cout << "FAILED! " << std::endl;
  }
}
void Expected::testConstructor(User user, MyString name, MyString lastName, int age, MyString userId){
  std::cout << "Testing Class: " << this->className << " , Function: Constructor() " << " Results: ";
  if( name == user.getName() && lastName == user.getLastName() && age == user.getAge() && userId == user.getUserId() ){
    std::cout << "SUCCESS! " << std::endl;
  }else{
    std::cout << "FAILED! " << std::endl;
  }
}
void Expected::testConstructor(Money money, MyString currency, double amount){
  std::cout << "Testing Class: " << this->className << " , Function: Constructor() " << " Results: ";
  if( currency == money.getCurrency() && amount == money.getAmount() ){
    std::cout << "SUCCESS! " << std::endl;
  }else{
    std::cout << "FAILED! " << std::endl;
  }
}
void Expected::testConstructor(MyDate date, int day, int month, int year){
  std::cout << "Testing Class: " << this->className << " , Function: Constructor() " << " Results: ";
  if( day == date.getDay() && month == date.getMonth() && year == date.getYear() ){
    std::cout << "SUCCESS! " << std::endl;
  }else{
    std::cout << "FAILED! " << std::endl;
  }
}
void Expected::testConstructor(MyTime time, int h, int m, int s, bool isAM){
  std::cout << "Testing Class: " << this->className << " , Function: Constructor() " << " Results: ";
  if( s == time.getSeconds() && m == time.getMinutes() && h == time.getHours() && isAM == time.isAm() ){
    std::cout << "SUCCESS! " << std::endl;
  }else{
    std::cout << "FAILED! " << std::endl;
  }
}

void Expected::testException(MyString functionName, int functionResult, MyString expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
}
void Expected::testException(MyString functionName, double functionResult, MyString expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
}
void Expected::testException(MyString functionName, MyString functionResult, MyString expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
}
void Expected::testException(MyString functionName, bool functionResult, MyString expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
}
void Expected::testException(MyString functionName, float functionResult, MyString expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
}
void Expected::testException(MyString functionName, Person functionResult, MyString expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
}
void Expected::testException(MyString functionName, User functionResult, MyString expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
}
void Expected::testException(MyString functionName, Money functionResult, MyString expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
}
void Expected::testException(MyString functionName, MyDate functionResult, MyString expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
}
void Expected::testException(MyString functionName, MyTime functionResult, MyString expectedResult){
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
}
