
#include "Test.h"

Test::Test(){}
Test::~Test(){}

bool Test::testPerson(){
  cout << endl << "Testing Person object" << endl;
  bool passedTest = false;

  User person1;
  User person2;
  person2.setName("Persona2");
  person2.setLastName("Dos");
  person2.setAge(22);
  User person3("Persona3","Tres",35);

  Expected expected("Person");

  MyString empty;
  passedTest = expected.testConstructor(person1, empty, empty, 18);
  passedTest = expected.testConstructor(person2, "Persona2", "Dos", 22);
  passedTest = expected.testConstructor(person3, "Persona3", "Tres", 35);
  person1 = person3;
  passedTest = expected.expect(" operator=() ", (person1 == person3), true );
  passedTest = expected.expect(" operator=() ", (person1 == person2), false );
  passedTest = expected.expect(" operator=() ", (person1 != person2), true );

  cout << endl;
  return(passedTest);
}

bool Test::testMoney(){

  cout << endl << "Testing Money object" << endl;
  bool passedTest = false;
  Money money1;
  Money money2(2);
  Money money3(2.0);
  Money money4("EU", 3.0);

  Expected expected("Money");

  passedTest = expected.testConstructor(money1, "USD", 0);
  passedTest = expected.testConstructor(money2, "USD", 2);
  passedTest = expected.testConstructor(money3, "USD", 2.0);
  passedTest = expected.testConstructor(money4, "EU", 3.0);

  money4.setCurrency("USD");
  money4.setAmount(4);

  passedTest = expected.expect("operator+()", (money2+money1+money3), money4 );
  passedTest = expected.expect("operator+()", (money2+2), money4 );
  passedTest = expected.expect("operator+()", (money2+2.0), money4 );

  passedTest = expected.expect("operator-()", (money2-money3), money1 );
  passedTest = expected.expect("operator-()", (money2-2), money1 );
  passedTest = expected.expect("operator-()", (money2-2.0), money1 );

  passedTest = expected.expect("operator*()", (money2*money3), money4 );
  passedTest = expected.expect("operator*()", (money2*2), money4 );
  passedTest = expected.expect("operator*()", (money2*2.0), money4 );

  passedTest = expected.expect("operator/()", (money4/money3), money2 );
  passedTest = expected.expect("operator/()", (money4/2), money2 );
  passedTest = expected.expect("operator/()", (money4/2.0), money2 );

  passedTest = expected.expect("operator+=()", (money2+=money3), money4 );
  money2.setAmount(2);
  passedTest = expected.expect("operator+=()", (money2+=2), money4 );
  money2.setAmount(2);
  passedTest = expected.expect("operator+=()", (money2+=2.0), money4 );
  money2.setAmount(2);
  passedTest = expected.expect("operator-=()", (money2-=money3), money1 );
  money2.setAmount(2);
  passedTest = expected.expect("operator-=()", (money2-=2), money1 );
  money2.setAmount(2);
  passedTest = expected.expect("operator-=()", (money2-=2.0), money1 );
  money2.setAmount(1);
  money2++;
  passedTest = expected.expect("operator++()", (money2), money3 );
  money2.setAmount(1);
  ++money2;
  passedTest = expected.expect("operator++()", (money2), money3 );
  money2.setAmount(3);
  money2--;
  passedTest = expected.expect("operator--()", (money2), money3 );
  money2.setAmount(3);
  --money2;
  passedTest = expected.expect("operator--()", (money2), money3 );
  money2.setAmount(2);

  passedTest = expected.expect("operator==()", (money2 == money3), true );
  passedTest = expected.expect("operator==()", (money2 == 2), true );
  passedTest = expected.expect("operator==()", (money2 == 2.0), true );
  passedTest = expected.expect("operator==()", (2 == money2), true );
  passedTest = expected.expect("operator==()", (2.0 == money2), true );

  passedTest = expected.expect("operator!=()", (money4 != money3), true );
  passedTest = expected.expect("operator!=()", (money4 != 3), true );
  passedTest = expected.expect("operator!=()", (money4 != 3.0), true );
  passedTest = expected.expect("operator!=()", (3 != money4), true );
  passedTest = expected.expect("operator!=()", (3.0 != money4), true );

  passedTest = expected.expect("operator<=()", (money3 <= money4), true );
  passedTest = expected.expect("operator<=()", (money4 <= 5), true );
  passedTest = expected.expect("operator<=()", (money4 <= 5), true );
  passedTest = expected.expect("operator<=()", (3 <= money4), true );
  passedTest = expected.expect("operator<=()", (3.0 <= money4), true );

  passedTest = expected.expect("operator<()", (money3 < money4), true );
  passedTest = expected.expect("operator<()", (money4 < 5), true );
  passedTest = expected.expect("operator<()", (money4 < 5), true );
  passedTest = expected.expect("operator<()", (3 < money4), true );
  passedTest = expected.expect("operator<()", (3.0 < money4), true );

  passedTest = expected.expect("operator>=()", (money4 >= money3), true );
  passedTest = expected.expect("operator>=()", (money4 >= 2), true );
  passedTest = expected.expect("operator>=()", (money4 >= 2), true );
  passedTest = expected.expect("operator>=()", (20 >= money4), true );
  passedTest = expected.expect("operator>=()", (20.0 >= money4), true );

  passedTest = expected.expect("operator>()", (money4 > money3), true );
  passedTest = expected.expect("operator>()", (money4 > 2), true );
  passedTest = expected.expect("operator>()", (money4 > 2), true );
  passedTest = expected.expect("operator>()", (20 > money4), true );
  passedTest = expected.expect("operator>()", (20.0 > money4), true );

  money1 = 2.34455;
  cout << "Money: " << money1 << ", " << money2 << ", " << money3 << ", " << money4 << endl;

  cout << endl;
  return(passedTest);
}
bool Test::testMyDate(){

  cout << endl << "Testing MyDate object" << endl;
  bool passedTest = false;

  MyDate date1;
  MyDate date2(2,2,2020);
  MyDate date3;
  date3.setDate(5,6,1998);
  MyDate date4(date3);

  Expected expected("MyDate");

  MyString empty;
  passedTest = expected.testConstructor(date1, 1, 1, 1990);
  passedTest = expected.testConstructor(date2, 2, 2, 2020);
  passedTest = expected.testConstructor(date3, 5, 6, 1998);
  passedTest = expected.testConstructor(date4, 5, 6, 1998);
  date2 = date4;
  date3.setDate(3,3,1993);
  passedTest = expected.expect(" operator==() ", (date2 == date4), true );
  passedTest = expected.expect(" operator==() ", (date1 == date4), false );
  passedTest = expected.expect(" operator!=() ", (date4 != date4), false );
  passedTest = expected.expect(" operator!=() ", (date4 != date3), true );

  date2.setDate(2,2,1992);
  date4.setDate(4,4,1994);

  passedTest = expected.expect(" operator<() ", (date2 < date4), true );
  passedTest = expected.expect(" operator<() ", (date4 < date2), false );
  passedTest = expected.expect(" operator<() ", (date4 < date4), false );

  passedTest = expected.expect(" operator<=() ", (date1 <= date4), true );
  passedTest = expected.expect(" operator<=() ", (date4 <= date1), false );
  passedTest = expected.expect(" operator<=() ", (date4 <= date4), true );

  passedTest = expected.expect(" operator>() ", (date4 > date3), true );
  passedTest = expected.expect(" operator>() ", (date2 > date4), false );
  passedTest = expected.expect(" operator>() ", (date2 > date2), false );

  passedTest = expected.expect(" operator>=() ", (date4 >= date2), true );
  passedTest = expected.expect(" operator>=() ", (date2 >= date4), false );
  passedTest = expected.expect(" operator>=() ", (date4 >= date4), true );
  cout << endl;
  return(passedTest);
}

bool Test::testMyTime(){
  cout << endl << "Testing MyTime object" << endl;
  bool passedTest = false;
  MyTime time0;
  MyTime time1(2,2,2,true);
  MyTime time2(3,3,3, true);
  MyTime time3(time1);

  Expected expected("MyTime");

  passedTest = expected.testConstructor(time0, 12,0,0, true);
  passedTest = expected.testConstructor(time1, 2,2,2, true);
  passedTest = expected.testConstructor(time2, 3,3,3, true);
  passedTest = expected.testConstructor(time3, 2,2,2, true);
  time0 = time2;
  passedTest = expected.expect(" operator==() ", (time0 == time2), true );
  passedTest = expected.expect(" operator==() ", (time0 == time1), false );
  passedTest = expected.expect(" operator!=() ", (time0 != time1), true );
  passedTest = expected.expect(" operator!=() ", (time0 != time2), false );

  passedTest = expected.expect(" operator>=() ", (time0 >= time2), true );
  time3.setTime(3, 2, 36, true);
  time0.setTime(12, 0, 0, true);
  time1.setTime(1, 0, 0, true);
  passedTest = expected.expect(" operator>=() ", (time2 >= time1), true );
  passedTest = expected.expect(" operator>=() ", (time1 >= time3), false );
  passedTest = expected.expect(" operator>() ", (time2 > time1), true );
  passedTest = expected.expect(" operator>() ", (time1 > time0), true );
  passedTest = expected.expect(" operator>() ", (time1 > time2), false );

  time0 = time2;

  passedTest = expected.expect(" operator<=() ", (time0 <= time2), true );
  time3.setTime(3, 2, 36, true);
  time0.setTime(12, 0, 0, true);
  passedTest = expected.expect(" operator<=() ", (time1 <= time2), true );
  passedTest = expected.expect(" operator<=() ", (time3 <= time1), false );
  passedTest = expected.expect(" operator<() ", (time1 < time2), true );
  passedTest = expected.expect(" operator<() ", (time0 < time3), true );
  passedTest = expected.expect(" operator<() ", (time2 < time1), false );

  time3.setTime(3, 2, 36, false);
  passedTest = expected.expect(" timeToStringMilitary() ", time3.timeToStringMilitary(), "15:02" );
  passedTest = expected.expect(" timeToStringMilitary_Seconds() ", time3.timeToStringMilitary_Seconds(), "15:02:36"  );

  time0.setTime(12, 0, 0, true);

  // std::cout << "UTC: " << time0.getTimeUTC_Epoch_MyString() << " Local: " << time0.getTimeLocaltime_Epoch_MyString()  << std::endl;
  cout << endl;

  return(passedTest);
}
bool Test::testMyString(){
  cout << endl << "Testing MyString object" << endl;
  bool passedTest = false;

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

  passedTest = expected.testConstructor(str0, "");
  passedTest = expected.testConstructor(str1, "a");
  passedTest = expected.testConstructor(str2, "123");
  passedTest = expected.testConstructor(str3, "321");
  passedTest = expected.testConstructor(str4, "1234567890");
  passedTest = expected.testConstructor(str5, "0987654321");
  passedTest = expected.testConstructor(str6, "3.456");
  passedTest = expected.testConstructor(str7, "a");

  str7 = str5;
  passedTest = expected.expect(" operator==() ", (str7 == str5), true );
  passedTest = expected.expect(" operator==() ", (str7 == str6), false );
  passedTest = expected.expect(" operator!=() ", (str7 != str6), true );
  passedTest = expected.expect(" operator!=() ", (str7 != str5), false );

  str7 = str1 + str2;
  str7 += 'a';
  str7 = 'b' + str7;
  str7 = "string" + str7;
  passedTest = expected.expect(" operator+() ", (str7 == "a123"), true );
  passedTest = expected.expect(" operator+=() ", (str7 == "a123a"), true );
  passedTest = expected.expect(" friend operator+() ", (str7 == "ba123a"), true );
  passedTest = expected.expect(" friend operator+() ", (str7 == "stringba123a"), true );

  passedTest = expected.expect(" operator>() ", (str7 > "23"), true );
  passedTest = expected.expect(" operator>() ", (str7 > str1), true );
  passedTest = expected.expect(" operator>() ", ("string" > str1), true );
  passedTest = expected.expect(" operator>() ", ("s" > str7), false );
  passedTest = expected.expect(" operator>() ", (str1 > "a123"), false );
  passedTest = expected.expect(" operator>() ", (str1 > "a123"), false );
  passedTest = expected.expect(" operator>() ", (str1 > "a123"), false );

  // passedTest = expected.expect(" operator>=() ", (str1 >= "2"), true );
  // passedTest = expected.expect(" operator>=() ", ("2" >= str1), true );
  // passedTest = expected.expect(" operator>=() ", (str7 >= "23"), true );
  // passedTest = expected.expect(" operator>=() ", (str7 >= str1), true );
  // passedTest = expected.expect(" operator>=() ", ("string" >= str1), true );
  // passedTest = expected.expect(" operator>=() ", ("s" >= str7), false );
  // passedTest = expected.expect(" operator>=() ", (str1 >= "a123"), false );
  // passedTest = expected.expect(" operator>=() ", (str1 >= "a123"), false );
  // passedTest = expected.expect(" operator>=() ", (str1 >= "a123"), false );

  cout << endl;
  return(passedTest);
}
