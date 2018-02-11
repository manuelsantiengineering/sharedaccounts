
#include "Test.h"

Test::Test(){}
Test::~Test(){}

void Test::testPerson(){
  cout << endl << "Testing Person object" << endl;
  User person1;
  User person2;
  person2.setName("Persona2");
  person2.setLastName("Dos");
  person2.setAge(22);
  User person3("Persona3","Tres",35);

  Expected expected("Person");

  MyString empty;
  expected.testConstructor(person1, empty, empty, 18);
  expected.testConstructor(person2, "Persona2", "Dos", 22);
  expected.testConstructor(person3, "Persona3", "Tres", 35);
  person1 = person3;
  expected.expect(" operator=() ", (person1 == person3), true );
  expected.expect(" operator=() ", (person1 == person2), false );
  expected.expect(" operator=() ", (person1 != person2), true );

  cout << endl;
}

void Test::testMoney(){

  cout << endl << "Testing Money object" << endl;
  Money money1;
  Money money2(2);
  Money money3(2.0);
  Money money4("EU", 3.0);

  Expected expected("Money");

  expected.testConstructor(money1, "USD", 0);
  expected.testConstructor(money2, "USD", 2);
  expected.testConstructor(money3, "USD", 2.0);
  expected.testConstructor(money4, "EU", 3.0);

  money4.setCurrency("USD");
  money4.setAmount(4);

  expected.expect("operator+()", (money2+money1+money3), money4 );
  expected.expect("operator+()", (money2+2), money4 );
  expected.expect("operator+()", (money2+2.0), money4 );

  expected.expect("operator-()", (money2-money3), money1 );
  expected.expect("operator-()", (money2-2), money1 );
  expected.expect("operator-()", (money2-2.0), money1 );

  expected.expect("operator*()", (money2*money3), money4 );
  expected.expect("operator*()", (money2*2), money4 );
  expected.expect("operator*()", (money2*2.0), money4 );

  expected.expect("operator/()", (money4/money3), money2 );
  expected.expect("operator/()", (money4/2), money2 );
  expected.expect("operator/()", (money4/2.0), money2 );

  expected.expect("operator+=()", (money2+=money3), money4 );
  money2.setAmount(2);
  expected.expect("operator+=()", (money2+=2), money4 );
  money2.setAmount(2);
  expected.expect("operator+=()", (money2+=2.0), money4 );
  money2.setAmount(2);
  expected.expect("operator-=()", (money2-=money3), money1 );
  money2.setAmount(2);
  expected.expect("operator-=()", (money2-=2), money1 );
  money2.setAmount(2);
  expected.expect("operator-=()", (money2-=2.0), money1 );
  money2.setAmount(1);
  money2++;
  expected.expect("operator++()", (money2), money3 );
  money2.setAmount(1);
  ++money2;
  expected.expect("operator++()", (money2), money3 );
  money2.setAmount(3);
  money2--;
  expected.expect("operator--()", (money2), money3 );
  money2.setAmount(3);
  --money2;
  expected.expect("operator--()", (money2), money3 );
  money2.setAmount(2);

  expected.expect("operator==()", (money2 == money3), true );
  expected.expect("operator==()", (money2 == 2), true );
  expected.expect("operator==()", (money2 == 2.0), true );
  expected.expect("operator==()", (2 == money2), true );
  expected.expect("operator==()", (2.0 == money2), true );

  expected.expect("operator!=()", (money4 != money3), true );
  expected.expect("operator!=()", (money4 != 3), true );
  expected.expect("operator!=()", (money4 != 3.0), true );
  expected.expect("operator!=()", (3 != money4), true );
  expected.expect("operator!=()", (3.0 != money4), true );

  expected.expect("operator<=()", (money3 <= money4), true );
  expected.expect("operator<=()", (money4 <= 5), true );
  expected.expect("operator<=()", (money4 <= 5), true );
  expected.expect("operator<=()", (3 <= money4), true );
  expected.expect("operator<=()", (3.0 <= money4), true );

  expected.expect("operator<()", (money3 < money4), true );
  expected.expect("operator<()", (money4 < 5), true );
  expected.expect("operator<()", (money4 < 5), true );
  expected.expect("operator<()", (3 < money4), true );
  expected.expect("operator<()", (3.0 < money4), true );

  expected.expect("operator>=()", (money4 >= money3), true );
  expected.expect("operator>=()", (money4 >= 2), true );
  expected.expect("operator>=()", (money4 >= 2), true );
  expected.expect("operator>=()", (20 >= money4), true );
  expected.expect("operator>=()", (20.0 >= money4), true );

  expected.expect("operator>()", (money4 > money3), true );
  expected.expect("operator>()", (money4 > 2), true );
  expected.expect("operator>()", (money4 > 2), true );
  expected.expect("operator>()", (20 > money4), true );
  expected.expect("operator>()", (20.0 > money4), true );

  cout << endl;
}
void Test::testMyDate(){

  cout << endl << "Testing MyDate object" << endl;

  MyDate date1;
  MyDate date2(2,2,2020);
  MyDate date3;
  date3.setDate(5,6,1998);
  MyDate date4(date3);

  Expected expected("MyDate");

  MyString empty;
  expected.testConstructor(date1, 1, 1, 1990);
  expected.testConstructor(date2, 2, 2, 2020);
  expected.testConstructor(date3, 5, 6, 1998);
  expected.testConstructor(date4, 5, 6, 1998);
  date2 = date4;
  date3.setDate(3,3,1993);
  expected.expect(" operator==() ", (date2 == date4), true );
  expected.expect(" operator==() ", (date1 == date4), false );
  expected.expect(" operator!=() ", (date4 != date4), false );
  expected.expect(" operator!=() ", (date4 != date3), true );

  date2.setDate(2,2,1992);
  date4.setDate(4,4,1994);

  expected.expect(" operator<() ", (date2 < date4), true );
  expected.expect(" operator<() ", (date4 < date2), false );
  expected.expect(" operator<() ", (date4 < date4), false );

  expected.expect(" operator<=() ", (date1 <= date4), true );
  expected.expect(" operator<=() ", (date4 <= date1), false );
  expected.expect(" operator<=() ", (date4 <= date4), true );

  expected.expect(" operator>() ", (date4 > date3), true );
  expected.expect(" operator>() ", (date2 > date4), false );
  expected.expect(" operator>() ", (date2 > date2), false );

  expected.expect(" operator>=() ", (date4 >= date2), true );
  expected.expect(" operator>=() ", (date2 >= date4), false );
  expected.expect(" operator>=() ", (date4 >= date4), true );
}
