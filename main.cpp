 // Created by Manuel E Santiago on 2/5/2018
 // Copyright (c) 2018 Manuel. All rights reserved.


 #include <stdio.h>
 #include <stdlib.h>
 #include <iostream>
 #include <string.h>
 #include <cstring>

#include "Money.h"
#include "MyString.h"
#include "Person.h"
// #include "./Model/User.h"

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
    cout << "Testing Person object" << endl;
  Person person1;
  Person person2;
  person2.setName("Persona2");
  person2.setLastName("Dos");
  person2.setAge(22);
  Person person3("Persona3","Tres",35);

  cout << "\t Name: " << person1.getName() << " , Last Name: " << person1.getLastName() << " Age: " << person1.getAge() << endl;
  person1 = person2;
  cout << "\t Name: " << person1.getName() << " , Last Name: " << person1.getLastName() << " Age: " << person1.getAge() << endl;
  cout << "\t Name: " << person3.getName() << " , Last Name: " << person3.getLastName() << " Age: " << person3.getAge() << endl;


  if(person1 == person2){ cout << "\t" << person1.getName() << " == " << person2.getName()  << " Same" << endl; }


  if(person3 == person2){ cout << "\t" << person3.getName() << " == " << person2.getName()  << " Same" << endl; }
  else{ cout << "\t Not the Same" << endl; }


  if(person3 != person2){ cout << "\t" << person3.getName() << " != " << person2.getName()  << " Not the Same" << endl; }
  else{ cout << "\t Same" << endl; }
}

void testMoney(){

  cout << "Testing Money object" << endl;
  Money cash;
  Money pesetas(11);
  Money pesos(30.0);

  cout << "\t Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
  cash.setAmount(20.2);
  cash.setCurrency("EUR");
  cout << "\t Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
  cash = pesetas;
  cout << "\t = Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
  cash = pesetas + pesos;
  cout << "\t +Money Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
  cash = pesetas - 1;
  cout << "\t -1 Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
  cash = pesetas - 10.0;
  cout << "\t -10.0 Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
  // pesetas.setCurrency("EUR");
  // cash = pesetas + pesos;
  // cout << "Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
  cash -= pesetas;
  cout << "\t -=Money Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
  cash += pesetas;
  cout << "\t +=Money Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
  cash += 20;
  cout << "\t +=20 Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
  cash -= 10;
  cout << "\t -=10 Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
  cash--;
  cout << "\t -- Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
  cash++;
  cout << "\t ++ Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;

  cout << "\t" << pesetas.getAmount() << " == " << pesetas.getAmount();
  if(pesetas == pesetas){ cout << " Same" << endl; }

  cout << "\t" << cash.getAmount() << " == " << pesetas.getAmount();
  if(cash == pesetas){ cout << " Same" << endl; }
  else{ cout << " Not the Same" << endl; }

  cout << "\t" << cash.getAmount() << " != " << pesos.getAmount();
  if(cash != pesos){  cout << " Not the Same" << endl; }
  else{ cout << " Same" << endl; }

}
