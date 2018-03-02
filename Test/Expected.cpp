
#include "Expected.h"

// Expected::Expected() {}
Expected::Expected(MyString name) : className(name) {}

void Expected::setClassName(MyString className){  this->className = className;  }

Expected::~Expected(){}

bool Expected::expect(MyString functionName, int functionResult, int expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    passedTest = true;
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
  return(passedTest);
}
bool Expected::expect(MyString functionName, double functionResult, double expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    passedTest = true;
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
  return(passedTest);
}
bool Expected::expect(MyString functionName, MyString functionResult, MyString expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    passedTest = true;
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
  return(passedTest);
}
bool Expected::expect(MyString functionName, bool functionResult, bool expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    passedTest = true;
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
  return(passedTest);
}
bool Expected::expect(MyString functionName, float functionResult, float expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    passedTest = true;
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
  return(passedTest);
}
bool Expected::expect(MyString functionName, Person functionResult, Person expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    passedTest = true;
    std::cout << "\tSUCCESS: " << functionResult.getName() << " == " << expectedResult.getName()  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult.getName() << " != " << expectedResult.getName()  << std::endl;
  }
  return(passedTest);
}
bool Expected::expect(MyString functionName, User functionResult, User expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    passedTest = true;
    std::cout << "\tSUCCESS: " << functionResult.getUserId() << " == " << expectedResult.getUserId()  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult.getUserId() << " != " << expectedResult.getUserId()  << std::endl;
  }
  return(passedTest);
}
bool Expected::expect(MyString functionName, Money functionResult, Money expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    passedTest = true;
    std::cout << "\tSUCCESS: " << functionResult.getAmount() << " == " << expectedResult.getAmount()  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult.getAmount() << " != " << expectedResult.getAmount()  << std::endl;
  }
  return(passedTest);
}
bool Expected::expect(MyString functionName, MyDate functionResult, MyDate expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    passedTest = true;
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
  return(passedTest);
}
bool Expected::expect(MyString functionName, MyClock functionResult, MyClock expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  if(functionResult == expectedResult){
    passedTest = true;
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
  return(passedTest);
}

bool Expected::testConstructor(Person person, MyString name, MyString lastName, int age){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: Constructor() " << " Results: ";
  if( name == person.getName() && lastName == person.getLastName() && age == person.getAge() ){
    passedTest = true;
    std::cout << "SUCCESS! " << std::endl;
  }else{
    std::cout << "FAILED! " << std::endl;
  }
  return(passedTest);
}
bool Expected::testConstructor(User user, MyString name, MyString lastName, int age, MyString userId){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: Constructor() " << " Results: ";
  if( name == user.getName() && lastName == user.getLastName() && age == user.getAge() && userId == user.getUserId() ){
    passedTest = true;
    std::cout << "SUCCESS! " << std::endl;
  }else{
    std::cout << "FAILED! " << std::endl;
  }
  return(passedTest);
}
bool Expected::testConstructor(Money money, MyString currency, double amount){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: Constructor() " << " Results: ";
  if( currency == money.getCurrency() && amount == money.getAmount() ){
    passedTest = true;
    std::cout << "SUCCESS! " << std::endl;
  }else{
    std::cout << "FAILED! " << std::endl;
  }
  return(passedTest);
}
bool Expected::testConstructor(MyDate date, int day, int month, int year){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: Constructor() " << " Results: ";
  if( day == date.getDay() && month == date.getMonth() && year == date.getYear() ){
    passedTest = true;
    std::cout << "SUCCESS! " << std::endl;
  }else{
    std::cout << "FAILED! " << std::endl;
  }
  return(passedTest);
}
bool Expected::testConstructor(MyTime time, int h, int m, int s){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: Constructor() " << " Results: ";
  if( s == time.getSeconds() && m == time.getMinutes() && h == time.getHours() ){
    passedTest = true;
    std::cout << "SUCCESS! " << std::endl;
  }else{
    std::cout << "FAILED! " << std::endl;
  }
  return(passedTest);
}
bool Expected::testConstructor(MyClock time, int h, int m, int s, bool AM){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: Constructor() " << " Results: ";
  if( s == time.getSeconds() && m == time.getMinutes() && h == time.getHours() && AM == time.isAM() ){
    passedTest = true;
    std::cout << "SUCCESS! " << std::endl;
  }else{
    std::cout << "FAILED! " << std::endl;
  }
  return(passedTest);
}
bool Expected::testConstructor(MyString str1, const char *str2){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: Constructor() " << " Results: ";
  if( str2 == str1 ){
    passedTest = true;
    std::cout << "SUCCESS! " << std::endl;
  }else{
    std::cout << "FAILED! " << std::endl;
  }
  return(passedTest);
}
bool Expected::testConstructor(TimeAndDate td, int day, int mon, int yr, int h, int m, int s, bool AM){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: Constructor() " << " Results: ";
  if( td.getDay() == day && td.getMonth() == mon && td.getYear() == yr &&
      td.getHours() == h && td.getMinutes() == m && td.getSeconds() == s &&
      td.isAM() == AM){
    passedTest = true;
    std::cout << "SUCCESS! " << std::endl;
  }else{
    std::cout << "FAILED! " << std::endl;
  }
  return(passedTest);
}
bool Expected::testConstructor(Period td, MyDate startDate, MyDate endDate, MyClock startTime, MyClock endTime){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: Constructor() " << " Results: ";
  if( td.getStartDate() == startDate && td.getStartTime() == startTime &&
      td.getEndDate() == endDate && td.getEndTime() == endTime 
    ){
    passedTest = true;
    std::cout << "SUCCESS! " << std::endl;
  }else{
    std::cout << "FAILED! " << std::endl;
  }
  return(passedTest);
}
bool Expected::testException(MyString functionName, int functionResult, MyString expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      passedTest = true;
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
  return(passedTest);
}
bool Expected::testException(MyString functionName, double functionResult, MyString expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      passedTest = true;
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
  return(passedTest);
}
bool Expected::testException(MyString functionName, MyString functionResult, MyString expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      passedTest = true;
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
  return(passedTest);
}
bool Expected::testException(MyString functionName, bool functionResult, MyString expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      passedTest = true;
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
  return(passedTest);
}
bool Expected::testException(MyString functionName, float functionResult, MyString expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      passedTest = true;
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
  return(passedTest);
}
bool Expected::testException(MyString functionName, Person functionResult, MyString expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      passedTest = true;
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
  return(passedTest);
}
bool Expected::testException(MyString functionName, User functionResult, MyString expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      passedTest = true;
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
  return(passedTest);
}
bool Expected::testException(MyString functionName, Money functionResult, MyString expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      passedTest = true;
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
  return(passedTest);
}
bool Expected::testException(MyString functionName, MyDate functionResult, MyString expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      passedTest = true;
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
  return(passedTest);
}
bool Expected::testException(MyString functionName, MyClock functionResult, MyString expectedResult){
  bool passedTest = false;
  std::cout << "Testing Class: " << this->className << " , Function: " << functionName << " Results: ";
  try{
    std::cout << "FAILED: " << " Did not catched the exception." << std::endl;
  }catch(MyString e){
    if(e == expectedResult)
    {
      passedTest = true;
      std::cout << "SUCCESS: " << e << std::endl;
    }else{
      std::cout << "FAILED: " << e << std::endl;
    }
  }
  return(passedTest);
}
