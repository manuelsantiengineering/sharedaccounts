
#include "Expected.h"

void Expected::setClassName(MyString className){  this->className = className;  }

void Expected::expect(MyString functionName, int functionResult, int expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, double functionResult, double expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, MyString functionResult, MyString expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, bool functionResult, bool expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, float functionResult, float expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, Person functionResult, Person expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult.getName() << " == " << expectedResult.getName()  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult.getName() << " != " << expectedResult.getName()  << std::endl;
  }
}
void Expected::expect(MyString functionName, User functionResult, User expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult.getUserId() << " == " << expectedResult.getUserId()  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult.getUserId() << " != " << expectedResult.getUserId()  << std::endl;
  }
}
void Expected::expect(MyString functionName, Money functionResult, Money expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult.getAmount() << " == " << expectedResult.getAmount()  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult.getAmount() << " != " << expectedResult.getAmount()  << std::endl;
  }
}
void Expected::expect(MyString functionName, MyDate functionResult, MyDate expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\tFAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
