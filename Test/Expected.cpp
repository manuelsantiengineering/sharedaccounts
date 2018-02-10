
#include "Expected.h"

void Expected::expect(MyString functionName, int functionResult, int expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, int functionResult, int expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, int functionResult, double expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, int functionResult, MyString expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, int functionResult, bool expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, int functionResult, float expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}

void Expected::expect(MyString functionName, double functionResult, double expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, double functionResult, int expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, double functionResult, MyString expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, double functionResult, bool expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, double functionResult, float expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, MyString functionResult, MyString expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, MyString functionResult, int expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, MyString functionResult, double expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, MyString functionResult, bool expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, MyString functionResult, float expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, bool functionResult, bool expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, bool functionResult, int expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, bool functionResult, double expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, bool functionResult, MyString expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, bool functionResult, float expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, float functionResult, float expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, float functionResult, int expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, float functionResult, double expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, float functionResult, MyString expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
void Expected::expect(MyString functionName, float functionResult, bool expectedResult){
  std::cout << "Testing function: " << functionName << " in class: " << this->className << std::endl;
  if(functionResult == expectedResult){
    std::cout << "\tSUCCESS: " << functionResult << " == " << expectedResult  << std::endl;
  }else{
    std::cout << "\FAILED: " << functionResult << " != " << expectedResult  << std::endl;
  }
}
