
#include "Test.h"

Test::Test(){
  this->passedTests = 0;
  this->failedTests = 0;
  this->totalPassedTests = 0;
  this->totalFailedTests = 0;
}
Test::~Test(){}

void Test::testAll(){

  if(this->testPerson()){
    std::cout << "\n\t SUCCESS TESTING: " << "Person\n" << std::endl;
  }else{
    std::cout << "\n\t FAILED TESTING: " << "Person" << std::endl;
    std::cout << "\n\t failed tests: " << this->failedTests << std::endl << std::endl;
  }
  this->totalPassedTests+= this->passedTests;
  this->passedTests = 0;
  this->totalFailedTests+= this->failedTests;
  this->failedTests = 0;
  if(this->testMoney()){
    std::cout << "\n\t SUCCESS TESTING: " << "Money\n" << std::endl;
  }else{
    std::cout << "\n\t FAILED TESTING: " << "Money" << std::endl;
    std::cout << "\n\t failed tests: " << this->failedTests << std::endl << std::endl;
  }
  this->totalPassedTests+= this->passedTests;
  this->passedTests = 0;
  this->totalFailedTests+= this->failedTests;
  this->failedTests = 0;
  if(this->testMyDate()){
    std::cout << "\n\t SUCCESS TESTING: " << "MyDate\n" << std::endl;
  }else{
    std::cout << "\n\t FAILED TESTING: " << "MyDate" << std::endl;
    std::cout << "\n\t failed tests: " << this->failedTests << std::endl << std::endl;
  }
  this->totalPassedTests+= this->passedTests;
  this->passedTests = 0;
  this->totalFailedTests+= this->failedTests;
  this->failedTests = 0;
  if(this->testMyTime()){
    std::cout << "\n\t SUCCESS TESTING: " << "MyTime\n" << std::endl;
  }else{
    std::cout << "\n\t FAILED TESTING: " << "MyTime" << std::endl;
    std::cout << "\n\t failed tests: " << this->failedTests << std::endl << std::endl;
  }
  this->totalPassedTests+= this->passedTests;
  this->passedTests = 0;
  this->totalFailedTests+= this->failedTests;
  this->failedTests = 0;
  if(this->testMyClock()){
    std::cout << "\n\t SUCCESS TESTING: " << "MyClock\n" << std::endl;
  }else{
    std::cout << "\n\t FAILED TESTING: " << "MyClock" << std::endl;
    std::cout << "\n\t failed tests: " << this->failedTests << std::endl << std::endl;
  }
  this->totalPassedTests+= this->passedTests;
  this->passedTests = 0;
  this->totalFailedTests+= this->failedTests;
  this->failedTests = 0;
  if(this->testMyString()){
    std::cout << "\n\t SUCCESS TESTING: " << "MyString\n" << std::endl;
  }else{
    std::cout << "\n\t FAILED TESTING: " << "MyString" << std::endl;
    std::cout << "\n\t failed tests: " << this->failedTests << std::endl << std::endl;
  }
  this->totalPassedTests+= this->passedTests;
  this->passedTests = 0;
  this->totalFailedTests+= this->failedTests;
  this->failedTests = 0;
  if(this->testTimeAndDate()){
    std::cout << "\n\t SUCCESS TESTING: " << "TimeAndDate\n" << std::endl;
  }else{
    std::cout << "\n\t FAILED TESTING: " << "TimeAndDate" << std::endl;
    std::cout << "\n\t failed tests: " << this->failedTests << std::endl << std::endl;
  }
  this->totalPassedTests+= this->passedTests;
  this->passedTests = 0;
  this->totalFailedTests+= this->failedTests;
  this->failedTests = 0;
  if(this->testUser()){
    std::cout << "\n\t SUCCESS TESTING: " << "User\n" << std::endl;
  }else{
    std::cout << "\n\t FAILED TESTING: " << "User" << std::endl;
    std::cout << "\n\t failed tests: " << this->failedTests << std::endl << std::endl;
  }
  this->totalPassedTests+= this->passedTests;
  this->passedTests = 0;
  this->totalFailedTests+= this->failedTests;
  this->failedTests = 0;



  std::cout << " Unit Testing Results:\n" << "\tSucceeded: " << this->totalPassedTests
            << "\n\tFailed: " << this->totalFailedTests << std::endl << std::endl;
}

bool Test::testMoney(){

  std::cout << std::endl << "Testing Money object" << std::endl;

  Money money1;
  Money money2(2);
  Money money3(2.0);
  Money money4("EU", 3.0);

  Expected expected("Money");

  if(expected.testConstructor(money1, "USD", 0)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(money2, "USD", 2)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(money3, "USD", 2.0)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(money4, "EU", 3.0)) {this->passedTests++;}else{this->failedTests++;}

  money4.setCurrency("USD");
  money4.setAmount(4);

  if(expected.expect("operator+()", (money2+money1+money3), money4 )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator+()", (money2+2), money4 )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator+()", (money2+2.0), money4 )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect("operator-()", (money2-money3), money1 )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator-()", (money2-2), money1 )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator-()", (money2-2.0), money1 )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect("operator*()", (money2*money3), money4 )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator*()", (money2*2), money4 )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator*()", (money2*2.0), money4 )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect("operator/()", (money4/money3), money2 )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator/()", (money4/2), money2 )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator/()", (money4/2.0), money2 )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect("operator+=()", (money2+=money3), money4 )) {this->passedTests++;}else{this->failedTests++;}
  money2.setAmount(2);
  if(expected.expect("operator+=()", (money2+=2), money4 )) {this->passedTests++;}else{this->failedTests++;}
  money2.setAmount(2);
  if(expected.expect("operator+=()", (money2+=2.0), money4 )) {this->passedTests++;}else{this->failedTests++;}
  money2.setAmount(2);
  if(expected.expect("operator-=()", (money2-=money3), money1 )) {this->passedTests++;}else{this->failedTests++;}
  money2.setAmount(2);
  if(expected.expect("operator-=()", (money2-=2), money1 )) {this->passedTests++;}else{this->failedTests++;}
  money2.setAmount(2);
  if(expected.expect("operator-=()", (money2-=2.0), money1 )) {this->passedTests++;}else{this->failedTests++;}
  money2.setAmount(1);
  money2++;
  if(expected.expect("operator++()", (money2), money3 )) {this->passedTests++;}else{this->failedTests++;}
  money2.setAmount(1);
  ++money2;
  if(expected.expect("operator++()", (money2), money3 )) {this->passedTests++;}else{this->failedTests++;}
  money2.setAmount(3);
  money2--;
  if(expected.expect("operator--()", (money2), money3 )) {this->passedTests++;}else{this->failedTests++;}
  money2.setAmount(3);
  --money2;
  if(expected.expect("operator--()", (money2), money3 )) {this->passedTests++;}else{this->failedTests++;}
  money2.setAmount(2);

  if(expected.expect("operator==()", (money2 == money3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator==()", (money2 == 2), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator==()", (money2 == 2.0), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator==()", (2 == money2), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator==()", (2.0 == money2), true )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect("operator!=()", (money4 != money3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator!=()", (money4 != 3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator!=()", (money4 != 3.0), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator!=()", (3 != money4), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator!=()", (3.0 != money4), true )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect("operator<=()", (money3 <= money4), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator<=()", (money4 <= 5), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator<=()", (money4 <= 5), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator<=()", (3 <= money4), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator<=()", (3.0 <= money4), true )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect("operator<()", (money3 < money4), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator<()", (money4 < 5), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator<()", (money4 < 5), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator<()", (3 < money4), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator<()", (3.0 < money4), true )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect("operator>=()", (money4 >= money3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator>=()", (money4 >= 2), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator>=()", (money4 >= 2), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator>=()", (20 >= money4), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator>=()", (20.0 >= money4), true )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect("operator>()", (money4 > money3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator>()", (money4 > 2), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator>()", (money4 > 2), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator>()", (20 > money4), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("operator>()", (20.0 > money4), true )) {this->passedTests++;}else{this->failedTests++;}

  money1 = 2.34455;
  std::cout << "Money: " << money1 << ", " << money2 << ", " << money3 << ", " << money4 << std::endl;

  std::cout << std::endl;
  return(this->failedTests == 0);
}
bool Test::testMyDate(){

  std::cout << std::endl << "Testing MyDate object" << std::endl;


  MyDate date1;
  MyDate date2(2,2,2020);
  MyDate date3;
  date3.setDate(5,6,1998);
  MyDate date4(date3);

  Expected expected("MyDate");

  MyString empty;
  if(expected.testConstructor(date1, 1, 1, 1990)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(date2, 2, 2, 2020)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(date3, 5, 6, 1998)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(date4, 5, 6, 1998)) {this->passedTests++;}else{this->failedTests++;}
  date2 = date4;
  date3.setDate(3,3,1993);
  if(expected.expect(" operator==() ", (date2 == date4), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator==() ", (date1 == date4), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator!=() ", (date4 != date4), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator!=() ", (date4 != date3), true )) {this->passedTests++;}else{this->failedTests++;}

  date2.setDate(2,2,1992);
  date4.setDate(4,4,1994);

  if(expected.expect(" operator<() ", (date2 < date4), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator<() ", (date4 < date2), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator<() ", (date4 < date4), false )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect(" operator<=() ", (date1 <= date4), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator<=() ", (date4 <= date1), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator<=() ", (date4 <= date4), true )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect(" operator>() ", (date4 > date3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>() ", (date2 > date4), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>() ", (date2 > date2), false )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect(" operator>=() ", (date4 >= date2), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>=() ", (date2 >= date4), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>=() ", (date4 >= date4), true )) {this->passedTests++;}else{this->failedTests++;}

  date2.setDate(1,1,1991);
  date4.setDate(1,2,1991);

  if(expected.expect(" getNumberOfDaysFromStartOfYear() ", (date2.getNumberOfDaysFromStartOfYear() == 0), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" getNumberOfDaysFromStartOfYear() ", (date4.getNumberOfDaysFromStartOfYear() == 31), true )) {this->passedTests++;}else{this->failedTests++;}

  date2.setDate(31,12,1991);
  date4.setDate(1,1,1991);

  if(expected.expect(" getNumberOfDaysUntilEndOfYear() ", (date2.getNumberOfDaysUntilEndOfYear() == 1), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" getNumberOfDaysUntilEndOfYear() ", (date4.getNumberOfDaysUntilEndOfYear() == 365), true )) {this->passedTests++;}else{this->failedTests++;}

  date2.setDate(1,1,1992);
  date3.setDate(1,2,1992);
  date4.setDate(1,1,1992);
  date4.setDateAtNumberOfDaysFromDate(date2, 31);

  if(expected.expect(" setDateAtNumberOfDaysFromDate() ", (date4 == date3), true )) {this->passedTests++;}else{this->failedTests++;}
  date4.setDateAtNumberOfDaysFromDate(date2, 32);
  date3.setDate(2,2,1992);
  if(expected.expect(" setDateAtNumberOfDaysFromDate() ", (date4 == date3), true )) {this->passedTests++;}else{this->failedTests++;}
  date2.setDate(1,1,1993);
  date4.setDateAtNumberOfDaysFromDate(date2, 365);
  date3.setDate(1,1,1994);
  if(expected.expect(" setDateAtNumberOfDaysFromDate() ", (date4 == date3), true )) {this->passedTests++;}else{this->failedTests++;}
  date2.setDate(1,1,1993);
  date4.setDateAtNumberOfDaysFromDate(date2, 366);
  date3.setDate(2,1,1994);
  if(expected.expect(" setDateAtNumberOfDaysFromDate() ", (date4 == date3), true )) {this->passedTests++;}else{this->failedTests++;}
  date2.setDate(1,3,1993);
  date4.setDateAtNumberOfDaysFromDate(date2, 61);
  date3.setDate(1,5,1993);
  if(expected.expect(" setDateAtNumberOfDaysFromDate() ", (date4 == date3), true )) {this->passedTests++;}else{this->failedTests++;}
  date2.setDate(1,3,1993);
  date4.setDateAtNumberOfDaysFromDate(date2, 0);
  std::cout << "Resulting Date must be 1/3/1993, result: " << date2 << " Amount of days: " << 0 << std::endl;
  if(expected.expect(" setDateAtNumberOfDaysFromDate() ", (date4 == date2), true )) {this->passedTests++;}else{this->failedTests++;}

  date2.setDate(1,1,1991);
  date4.setDate(1,1,1991);
  date3.setDate(1,2,1991);
  date4.setDateAtNumberOfDaysFromStartOfYear(31);
  // std::cout << "Date 4 " << date4 << " Date 3 " << date3 << std::endl;
  if(expected.expect(" setDateAtNumberOfDaysFromStartOfYear(int) ", (date4 == date3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date2.getNumberOfDaysUntilDate(date3) == 31), true )) {this->passedTests++;}else{this->failedTests++;}

  date4.setDate(1,1,1991);
  date3.setDate(4,3,1991);
  date4.setDateAtNumberOfDaysFromStartOfYear(62);
  // std::cout << "Date 4 " << date4 << " Date 2 " << date2 << " Difference: " << date2.getNumberOfDaysUntilDate(date4) << std::endl;
  if(expected.expect(" setDateAtNumberOfDaysFromStartOfYear(int) ", (date4 == date3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date2.getNumberOfDaysUntilDate(date4) == 62), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date4.getNumberOfDaysUntilDate(date2) == -62), true )) {this->passedTests++;}else{this->failedTests++;}

  date4.setDate(1,1,1991);
  date3.setDate(3,2,2001);
  date4.setDateAtNumberOfDaysFromStartOfYear(33,2001);
  std::cout << "Date 4 " << date4 << " Date 2 " << date2 << " Difference: " << date2.getNumberOfDaysUntilDate(date4) << std::endl;
  if(expected.expect(" setDateAtNumberOfDaysFromStartOfYear(int, int) ", (date4 == date3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date2.getNumberOfDaysUntilDate(date4) == 3685), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date4.getNumberOfDaysUntilDate(date2) == -3685), true )) {this->passedTests++;}else{this->failedTests++;}

  date4.setDate(1,1,1991);
  date3.setDate(2,1,1992);
  date4.setDateAtNumberOfDaysFromStartOfYear(1,1992);
  std::cout << "Date 4 " << date4 << " Date 2 " << date2 << " Difference: " << date2.getNumberOfDaysUntilDate(date4) << std::endl;
  if(expected.expect(" setDateAtNumberOfDaysFromStartOfYear(int, int) ", (date4 == date3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date2.getNumberOfDaysUntilDate(date4) == 366), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date4.getNumberOfDaysUntilDate(date2) == -366), true )) {this->passedTests++;}else{this->failedTests++;}

  date4.setDate(1,1,1991);
  date3.setDate(1,1,1992);
  date4.setDateAtNumberOfDaysFromStartOfYear(0,1992);
  std::cout << "Date 4 " << date4 << " Date 2 " << date2 << " Difference: " << date2.getNumberOfDaysUntilDate(date4) << std::endl;
  if(expected.expect(" setDateAtNumberOfDaysFromStartOfYear(int, int) ", (date4 == date3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date2.getNumberOfDaysUntilDate(date4) == 365), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date4.getNumberOfDaysUntilDate(date2) == -365), true )) {this->passedTests++;}else{this->failedTests++;}

  date4.setDate(1,1,1991);
  date3.setDate(1,1,1991);
  date4.setDateAtNumberOfDaysFromStartOfYear(0,1991);
  if(expected.expect(" setDateAtNumberOfDaysFromStartOfYear(int, int) ", (date4 == date3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date2.getNumberOfDaysUntilDate(date4) == 0), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date4.getNumberOfDaysUntilDate(date2) == 0), true )) {this->passedTests++;}else{this->failedTests++;}

  date4.setDate(1,1,1991);
  date3.setDate(31,12,1991);
  date4.setDateAtNumberOfDaysFromStartOfYear(364,1991);
  if(expected.expect(" setDateAtNumberOfDaysFromStartOfYear(int, int) ", (date4 == date3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date2.getNumberOfDaysUntilDate(date4) == 364), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date4.getNumberOfDaysUntilDate(date2) == -364), true )) {this->passedTests++;}else{this->failedTests++;}

  date4.setDate(1,1,1970);
  int days = (int) 1514764800/86400;
  date2.setDateAtNumberOfDaysFromDate(date4, days);
  date3.setDate(1,1,2018);
  std::cout << "Resulting Date must be 1/1/2018, result: " << date2 << std::endl;
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date3 == date2), true )) {this->passedTests++;}else{this->failedTests++;}


  date4.setDate(1,1,2018);
  days = (int) -10;
  date2.setDateAtNumberOfDaysFromDate(date4, days);
  date3.setDate(22,12,2017);
  std::cout << "Resulting Date must be 12/12/2017, result: " << date2 << " Amount of days: " << days << std::endl;
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date3 == date2), true )) {this->passedTests++;}else{this->failedTests++;}


  date4.setDate(1,1,2018);
  days = (int) (-1.0)*1514764800/86400;
  date2.setDateAtNumberOfDaysFromDate(date4, days);
  date3.setDate(31,12,1969);
  std::cout << "Resulting Date must be 1/31/1969, result: " << date2 << " Amount of days: " << days << std::endl;
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date3 == date2), true )) {this->passedTests++;}else{this->failedTests++;}

  date4.setDate(1,1,1970);
  days = (int) 928497600/86400;
  date2.setDateAtNumberOfDaysFromDate(date4, days);
  date3.setDate(4,6,1999);
  std::cout << "Resulting Date must be 6/4/1999, result: " << date2 << " Amount of days: " << days << std::endl;
  if(expected.expect(" getNumberOfDaysUntilDate(MyDate) ", (date3 == date2), true )) {this->passedTests++;}else{this->failedTests++;}

  std::cout << std::endl;
  return(this->failedTests == 0);
}


bool Test::testMyTime(){
  std::cout << std::endl << "Testing MyTime object" << std::endl;

  MyTime time0;
  MyTime time1(2,2,2);
  MyTime time2(3,3,3);
  MyTime time3(time1);

  Expected expected("MyTime");

  std::cout << "Time 0: " << time0 << std::endl;
  std::cout << "Time 1: " << time1 << std::endl;
  std::cout << "Time 2: " << time2 << std::endl;
  std::cout << "Time 3: " << time3 << std::endl;

  if(expected.testConstructor(time0, 12,0,0)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(time1, 2,2,2)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(time2, 3,3,3)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(time3, 2,2,2)) {this->passedTests++;}else{this->failedTests++;}
  time0 = time2;
  if(expected.expect(" operator==() ", (time0 == time2), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator==() ", (time0 == time1), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator!=() ", (time0 != time1), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator!=() ", (time0 != time2), false )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect(" operator>=() ", (time0 >= time2), true )) {this->passedTests++;}else{this->failedTests++;}

  time3.setTime(12, 0, 60);
  time0.setTime(12, 1, 0);
  // std::cout << "Time 0 :" << time0 << std::endl;
  // std::cout << "Time 3 :" << time3 << std::endl;
  if(expected.expect(" setToStandardTime() ", (time0 == time3), true )) {this->passedTests++;}else{this->failedTests++;}
  time3.setTime(12, 59, 60);
  time0.setTime(13, 0, 0);
  // std::cout << "Time 0 :" << time0 << std::endl;
  // std::cout << "Time 3 :" << time3 << std::endl;
  if(expected.expect(" setToStandardTime() ", (time0 == time3), true )) {this->passedTests++;}else{this->failedTests++;}
  time3.setTime(12, 59, 125);
  time0.setTime(13, 1, 5);
  // std::cout << "Time 0 :" << time0 << std::endl;
  // std::cout << "Time 3 :" << time3 << std::endl;
  if(expected.expect(" setToStandardTime() ", (time0 == time3), true )) {this->passedTests++;}else{this->failedTests++;}

  time3.setTime(3, 2, 36);
  time0.setTime(12, 0, 0);
  time1.setTime(1, 0, 0);
  if(expected.expect(" operator>=() ", (time2 >= time1), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>=() ", (time1 >= time3), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>() ", (time2 > time1), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>() ", (time1 > time0), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>() ", (time1 > time2), false )) {this->passedTests++;}else{this->failedTests++;}

  time0 = time2;

  if(expected.expect(" operator<=() ", (time0 <= time2), true )) {this->passedTests++;}else{this->failedTests++;}
  time3.setTime(3, 2, 36);
  time0.setTime(12, 0, 0);
  if(expected.expect(" operator<=() ", (time1 <= time2), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator<=() ", (time3 <= time1), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator<() ", (time1 < time2), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator<() ", (time0 > time3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator<() ", (time2 < time1), false )) {this->passedTests++;}else{this->failedTests++;}

  time3.setTime(3, 2, 36);
  if(expected.expect(" timeToString() ", time3.timeToString(), "03:02" )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" timeToString_Seconds() ", time3.timeToString_Seconds(), "03:02:36"  )) {this->passedTests++;}else{this->failedTests++;}

  time3.setTime(12, 30, 30);
  if(expected.expect(" getTimeInSeconds() ", time3.getTimeInSeconds(), 45030 )) {this->passedTests++;}else{this->failedTests++;}

  std::cout << std::endl;

  return(this->failedTests == 0);
}

bool Test::testMyClock(){
  std::cout << std::endl << "Testing MyClock object" << std::endl;

  MyClock time0;
  MyClock time1(2,2,2,true);
  MyClock time2(3,3,3, true);
  MyClock time3(time1);

  Expected expected("MyClock");

  if(expected.testConstructor(time0, 12,0,0, true)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(time1, 2,2,2, true)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(time2, 3,3,3, true)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(time3, 2,2,2, true)) {this->passedTests++;}else{this->failedTests++;}
  time0 = time2;
  if(expected.expect(" operator==() ", (time0 == time2), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator==() ", (time0 == time1), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator!=() ", (time0 != time1), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator!=() ", (time0 != time2), false )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect(" operator>=() ", (time0 >= time2), true )) {this->passedTests++;}else{this->failedTests++;}
  time3.setTime(3, 2, 36, true);
  time0.setTime(12, 0, 0, true);
  time1.setTime(1, 0, 0, true);
  if(expected.expect(" operator>=() ", (time2 >= time1), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>=() ", (time1 >= time3), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>() ", (time2 > time1), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>() ", (time1 > time0), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>() ", (time1 > time2), false )) {this->passedTests++;}else{this->failedTests++;}

  time0 = time2;

  if(expected.expect(" operator<=() ", (time0 <= time2), true )) {this->passedTests++;}else{this->failedTests++;}
  time3.setTime(3, 2, 36, true);
  time0.setTime(12, 0, 0, true);
  if(expected.expect(" operator<=() ", (time1 <= time2), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator<=() ", (time3 <= time1), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator<() ", (time1 < time2), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator<() ", (time0 < time3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator<() ", (time2 < time1), false )) {this->passedTests++;}else{this->failedTests++;}

  time3.setTime(3, 2, 36, false);
  if(expected.expect(" timeToString() ", time3.timeToString(), "03:02PM" )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" timeToString_Seconds() ", time3.timeToString_Seconds(), "03:02:36PM"  )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" timeToStringMilitary() ", time3.timeToStringMilitary(), "15:02" )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" timeToStringMilitary_Seconds() ", time3.timeToStringMilitary_Seconds(), "15:02:36"  )) {this->passedTests++;}else{this->failedTests++;}

  time3.setTime(12, 30, 30, false);
  if(expected.expect(" getTimeInSeconds() ", time3.getTimeInSeconds(), 45030 )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect(" isSecondsCorrect() ", time3.isSecondsCorrect(34), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" isSecondsCorrect() ", time3.isSecondsCorrect(76), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" isMinutesCorrect() ", time3.isMinutesCorrect(33), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" isMinutesCorrect() ", time3.isMinutesCorrect(88), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" isHoursCorrect() ", time3.isHoursCorrect(12), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" isHoursCorrect() ", time3.isHoursCorrect(33), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" isTimeCorrect() ", time3.isTimeCorrect(12,0,0), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" isTimeCorrect() ", time3.isTimeCorrect(24,77,77), false )) {this->passedTests++;}else{this->failedTests++;}

  // std::cout << "UTC: " << time0.getTimeUTC_Epoch_MyString() << " Local: " << time0.getTimeLocaltime_Epoch_MyString()  << std::endl;
  std::cout << std::endl;

  return(this->failedTests == 0);
}

bool Test::testMyString(){
  std::cout << std::endl << "Testing MyString object" << std::endl;


  unsigned int a = 321;
  int b = 123;
  long int lint = 1234567890;
  unsigned long int ulint = 987654321;
  double db = 3.456;
  MyString str0;
  MyString str1('a');
  MyString str2(b);
  MyString str3(a);
  MyString str4(lint);
  MyString str5(ulint);
  MyString str6(db);
  MyString str7(str1);

  Expected expected("MyString");

  if(expected.testConstructor(str0, "")) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(str1, "a")) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(str2, "123")) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(str3, "321")) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(str4, "1234567890")) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(str5, "987654321")) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(str7, "a")) {this->passedTests++;}else{this->failedTests++;}

  str7 = str5;
  if(expected.expect(" operator==() ", (str7 == str5), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator==() ", (str7 == str6), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator!=() ", (str7 != str6), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator!=() ", (str7 != str5), false )) {this->passedTests++;}else{this->failedTests++;}

  str7 = str1 + str2;
  if(expected.expect(" operator+() ", (str7 == "a123"), true )) {this->passedTests++;}else{this->failedTests++;}
  str7 += 'a';
  if(expected.expect(" operator+=() ", (str7 == "a123a"), true )) {this->passedTests++;}else{this->failedTests++;}
  str7 = 'b' + str7;
  if(expected.expect(" friend operator+() ", (str7 == "ba123a"), true )) {this->passedTests++;}else{this->failedTests++;}
  str7 = "string" + str7;
  if(expected.expect(" friend operator+() ", (str7 == "stringba123a"), true )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect(" operator>() ", (str7 > "23"), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>() ", (str7 > str1), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>() ", ("string" > str1), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>() ", ("s" > str7), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>() ", (str1 > "a123"), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>() ", (str1 > "a123"), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>() ", (str1 > "a123"), false )) {this->passedTests++;}else{this->failedTests++;}

  str7++;
  if(expected.expect("operator++() ", (str7 == "STRINGBA123A"), true )) {this->passedTests++;}else{this->failedTests++;}
  str7--;
  if(expected.expect("operator--() ", (str7 == "stringba123a"), true )) {this->passedTests++;}else{this->failedTests++;}
  ++str7;
  if(expected.expect("operator++() ", (str7 == "STRINGBA123A"), true )) {this->passedTests++;}else{this->failedTests++;}
  --str7;
  if(expected.expect("operator--() ", (str7 == "stringba123a"), true )) {this->passedTests++;}else{this->failedTests++;}

  int len = str1.len();
  if(expected.expect("len() ", (len == 1), true )) {this->passedTests++;}else{this->failedTests++;}
  len = str0.len();
  if(expected.expect("len() ", (len == 0), true )) {this->passedTests++;}else{this->failedTests++;}

  int ind = str7.indexOf('a');
  if(expected.expect("indexOf() ", (ind == 7), true )) {this->passedTests++;}else{this->failedTests++;}
  ind = str7.indexOfLast('a');
  if(expected.expect("indexOf() ", (ind == 11), true )) {this->passedTests++;}else{this->failedTests++;}
  ind = str7.frequency('a');
  if(expected.expect("frequency() ", (ind == 2), true )) {this->passedTests++;}else{this->failedTests++;}

  str7 = str7.createSubstring(0,5);
  if(expected.expect("createSubstring() ", (str7 == "string"), true )) {this->passedTests++;}else{this->failedTests++;}
  str7 = str7.reverse();
  if(expected.expect("reverse() ", (str7 == "gnirts"), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("[]() ", (str7[2] == 'i'), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("[]() ", (str7[3] == 'i'), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("getCharAt() ", (str7.getCharAt(2) == "i"), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("getCharAt() ", (str7.getCharAt(3) == "i"), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("isEmpty() ", (str0.isEmpty()), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("isEmpty() ", (str7.isEmpty()), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("representAnInteger() ", (str2.representAnInteger()), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("representAnUnsignInteger() ", (str2.representAnUnsignInteger()), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("representAReal() ", (str6.representAReal()), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("cambiaInt() ", (str2.cambiaInt() == 123), true )) {this->passedTests++;}else{this->failedTests++;}

  std::cout << std::endl;
  return(this->failedTests == 0);
}

bool Test::testPerson(){
  std::cout << std::endl << "Testing Person object" << std::endl;
  Person person1;
  Person person2;
  person2.setName("Persona2");
  person2.setLastName("Dos");
  person2.setAge(22);
  User person3("Persona3","Tres",33);

  Expected expected("Person");

  MyString empty;
  if(expected.testConstructor(person1, empty, empty, 18)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(person2, "Persona2", "Dos", 22)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(person3, "Persona3", "Tres", 33)) {this->passedTests++;}else{this->failedTests++;}
  person1 = person3;
  if(expected.expect(" operator=() ", (person1 == person3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator=() ", (person1 == person2), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator=() ", (person1 != person2), true )) {this->passedTests++;}else{this->failedTests++;}

  std::cout << std::endl;

  return(this->failedTests == 0);
}
bool Test::testUser(){
  std::cout << std::endl << "Testing User object" << std::endl;

  User person1;
  User person2;
  person2.setName("User2");
  person2.setLastName("Dos");
  person2.setAge(22);
  person2.setUserId("2222-2222");
  User person3("User3","Tres",33,"3333-3333");

  Expected expected("User");

  MyString empty;
  if(expected.testConstructor(person1, empty, empty, 18, "XXXX-XXXX")) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(person2, "User2", "Dos", 22, "2222-2222")) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(person3, "User3", "Tres", 33, "3333-3333")) {this->passedTests++;}else{this->failedTests++;}
  person1 = person3;
  if(expected.expect(" operator=() ", (person1 == person3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator=() ", (person1 == person2), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator=() ", (person1 != person2), true )) {this->passedTests++;}else{this->failedTests++;}

  std::cout << std::endl;

  return(this->failedTests == 0);
}
bool Test::testTimeAndDate(){
  std::cout << std::endl << "Testing TimeAndDate object" << std::endl;

  Expected expected("TimeAndDate");

  TimeAndDate td1;
  TimeAndDate td2(1,1,2010,12,0,0);
  TimeAndDate td3(1,1,2010,12,0,0,false);
  TimeAndDate td4(td3);
  MyDate date(1,1,2010);
  MyClock ts(12,0,0);
  TimeAndDate td5(date);
  TimeAndDate td6(ts);
  TimeAndDate td7(date,ts);

  std::cout << "Td2: " << td2 << " Td6: " << td6 << std::endl;

  if(expected.testConstructor(td1, 1, 1, 1990, 12, 0, 0, true)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(td2, 1, 1, 2010, 12, 0, 0, true)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(td3, 1, 1, 2010, 12, 0, 0, false)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(td4, 1, 1, 2010, 12, 0, 0, false)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(td5, 1, 1, 2010, 12, 0, 0, true)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(td6, 1, 1, 1990, 12, 0, 0, true)) {this->passedTests++;}else{this->failedTests++;}
  if(expected.testConstructor(td7, 1, 1, 2010, 12, 0, 0, true)) {this->passedTests++;}else{this->failedTests++;}

  MyDate datecmp;
  MyClock tscmp;
  datecmp = td5.getDate();
  tscmp = td6.getTime();

  if(expected.expect("getDate() ", (datecmp == date), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect("getTime() ", (tscmp == ts), true )) {this->passedTests++;}else{this->failedTests++;}

  td7 = td1;

  if(expected.expect(" operator=() ", (td7 == td1), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator=() ", (td7 == td3), false )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect(" operator==() ", (td4 == td3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator==() ", (td3 == td2), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator!=() ", (td3 != td2), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator!=() ", (td4 != td3), false )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect(" operator>=() ", (td3 >= td2), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>=() ", (td3 >= td4), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>=() ", (td2 >= td3), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>() ", (td3 > td2), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator>() ", (td2 > td3), false )) {this->passedTests++;}else{this->failedTests++;}

  if(expected.expect(" operator<=() ", (td2 <= td3), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator<=() ", (td3 <= td4), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator<=() ", (td3 <= td2), false )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator<() ", (td2 < td4), true )) {this->passedTests++;}else{this->failedTests++;}
  if(expected.expect(" operator<() ", (td4 < td2), false )) {this->passedTests++;}else{this->failedTests++;}

  MyClock clock1(12,0,0,false);
  MyDate dateToSet(1,3,2010);
  td2.setTime(clock1);
  td2.setDate(dateToSet);
  dateToSet.setDate(1,6,2010);
  td6.setDate(dateToSet);
  td6.setTime(clock1);
  td2.setTimeAndDateAtNumberOfSecondsFromTimeAndDate(td2, 7948800); //92 days after
  if(expected.expect(" setTimeAndDateAtNumberOfSecondsFromTimeAndDate(+92days) ", (td6 == td2), true )) {this->passedTests++;}else{this->failedTests++;}

  dateToSet.setDate(31,12,2010);
  td2.setDate(dateToSet);
  dateToSet.setDate(30,9,2010);
  td6.setDate(dateToSet);
  td2.setTimeAndDateAtNumberOfSecondsFromTimeAndDate(td2, -7948800); //92 days before
  if(expected.expect(" setTimeAndDateAtNumberOfSecondsFromTimeAndDate(-92days) ", (td6 == td2), true )) {this->passedTests++;}else{this->failedTests++;}

  dateToSet.setDate(31,12,2010);
  td2.setTime(clock1);
  td2.setDate(dateToSet);
  dateToSet.setDate(30,9,2010);
  td6.setDate(dateToSet);
  clock1.setTime(8,0,0,true);
  td6.setTime(clock1);
  td2.setTimeAndDateAtNumberOfSecondsFromTimeAndDate(td2, -7963200); //92 days and 4 hours before
  if(expected.expect(" setTimeAndDateAtNumberOfSecondsFromTimeAndDate(-92days,4hrs) ", (td6 == td2), true )) {this->passedTests++;}else{this->failedTests++;}

  dateToSet.setDate(31,12,2010);
  clock1.setTime(12,0,0,false);
  td2.setTime(clock1);
  td2.setDate(dateToSet);
  dateToSet.setDate(30,9,2010);
  td6.setDate(dateToSet);
  clock1.setTime(4,0,0,false);
  td6.setTime(clock1);
  td2.setTimeAndDateAtNumberOfSecondsFromTimeAndDate(td2, -7934400); //91 days and 20 hours before
  if(expected.expect(" setTimeAndDateAtNumberOfSecondsFromTimeAndDate(-91days,20hrs) ", (td6 == td2), true )) {this->passedTests++;}else{this->failedTests++;}

  dateToSet.setDate(1,8,2010);
  clock1.setTime(12,0,0,false);
  td2.setTime(clock1);
  td2.setDate(dateToSet);
  dateToSet.setDate(1,11,2010);
  td6.setDate(dateToSet);
  clock1.setTime(8,0,30,true);
  td6.setTime(clock1);
  td2.setTimeAndDateAtNumberOfSecondsFromTimeAndDate(td2, 7934430); //91 days and 20 hours after
  if(expected.expect(" setTimeAndDateAtNumberOfSecondsFromTimeAndDate(+91days,20hrs,30sec) ", (td6 == td2), true )) {this->passedTests++;}else{this->failedTests++;}

  dateToSet.setDate(1,8,2010);
  clock1.setTime(1,0,0,true);
  td2.setTime(clock1);
  td2.setDate(dateToSet);
  dateToSet.setDate(31,7,2010);
  td6.setDate(dateToSet);
  clock1.setTime(11,0,0,false);
  td6.setTime(clock1);
  td2.setTimeAndDateAtNumberOfSecondsFromTimeAndDate(td2, -7200); //2 hours before
  if(expected.expect(" setTimeAndDateAtNumberOfSecondsFromTimeAndDate(-2hrs) ", (td6 == td2), true )) {this->passedTests++;}else{this->failedTests++;}

  dateToSet.setDate(21,8,2010);
  clock1.setTime(11,0,0,false);
  td2.setTime(clock1);
  td2.setDate(dateToSet);
  dateToSet.setDate(22,8,2010);
  td6.setDate(dateToSet);
  clock1.setTime(1,0,0,true);
  td6.setTime(clock1);
  td2.setTimeAndDateAtNumberOfSecondsFromTimeAndDate(td2, 7200); //2 hours after
  if(expected.expect(" setTimeAndDateAtNumberOfSecondsFromTimeAndDate(+2hrs) ", (td6 == td2), true )) {this->passedTests++;}else{this->failedTests++;}

  dateToSet.setDate(1,8,2010);
  clock1.setTime(12,0,0,false);
  td2.setTime(clock1);
  td2.setDate(dateToSet);
  td6.setDate(dateToSet);
  td6.setTime(clock1);
  td2.setTimeAndDateAtNumberOfSecondsFromTimeAndDate(td2, 0); //91 days and 20 hours after
  if(expected.expect(" setTimeAndDateAtNumberOfSecondsFromTimeAndDate(+0days,0hrs,0sec) ", (td6 == td2), true )) {this->passedTests++;}else{this->failedTests++;}

  dateToSet.setDate(31,12,2010);
  clock1.setTime(12,0,0,false);
  td2.setTime(clock1);
  td2.setDate(dateToSet);
  dateToSet.setDate(1,1,2011);
  clock1.setTime(8,30,30,true);
  td6.setDate(dateToSet);
  td6.setTime(clock1);
  td2.setTimeAndDateAtNumberOfSecondsFromTimeAndDate(td2, 73830); //20 hours 30 min 30 sec after
  if(expected.expect(" setTimeAndDateAtNumberOfSecondsFromTimeAndDate(+20hr,30min,30sec) ", (td6 == td2), true )) {this->passedTests++;}else{this->failedTests++;}

  dateToSet.setDate(1,1,2011);
  clock1.setTime(8,30,30,true);
  td2.setTime(clock1);
  td2.setDate(dateToSet);
  dateToSet.setDate(31,12,2010);
  clock1.setTime(12,0,0,false);
  td6.setDate(dateToSet);
  td6.setTime(clock1);
  td2.setTimeAndDateAtNumberOfSecondsFromTimeAndDate(td2, -73830); //20 hours 30 min 30 sec before
  if(expected.expect(" setTimeAndDateAtNumberOfSecondsFromTimeAndDate(-20hr,30min,30sec) ", (td6 == td2), true )) {this->passedTests++;}else{this->failedTests++;}

  std::cout << std::endl;

  return(this->failedTests == 0);
}
