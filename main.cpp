 // Created by Manuel E Santiago on 2/5/2018
 // Copyright (c) 2018 Manuel. All rights reserved.


 #include <stdio.h>
 #include <stdlib.h>
 #include <iostream>
 #include <string.h>
 #include <cstring>

#include "./Model/Money.h"
#include "./Utilities/MyString.h"
#include "./Model/User.h"

#include "./Test/Expected.h"

using namespace std;

void testMoney();
void testPerson();

int main(int argc, const char * argv[]) {

  cout << "Starting program..."<< endl;

  try{
    testMoney();
    testPerson();
  }
  catch (MyString e)
  {
    cout << "Error: " << e << endl;
  }
  return 0;
}

void testPerson(){
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

void testMoney(){

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

  expected.expect("operator==()", (money4 != money3), true );
  expected.expect("operator==()", (money4 != 3), true );
  expected.expect("operator==()", (money4 != 3.0), true );

  cout << endl;
}
