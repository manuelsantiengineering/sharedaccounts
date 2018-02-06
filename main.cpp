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

using namespace std;

int main(int argc, const char * argv[]) {

  cout << "Starting program..."<< endl;

  try{

    Money cash;
    Money pesetas(11);
    Money pesos(30.0);

    cout << "Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
    cash.setAmount(20.2);
    cash.setCurrency("EUR");
    cout << "Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
    cash = pesetas;
    cout << "Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
    cash = pesetas + pesos;
    cout << "Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
    cash = pesetas - 1;
    cout << "Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
    cash = pesetas - 10.0;
    cout << "Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
    // pesetas.setCurrency("EUR");
    // cash = pesetas + pesos;
    // cout << "Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
    cash -= pesetas;
    cout << "Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
    cash += pesetas;
    cout << "Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
    cash += 20;
    cout << "+=20 Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
    cash -= 10;
    cout << "-=10 Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
    cash--;
    cout << "-- Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;
    cash++;
    cout << "++ Amount = " << cash.getAmount() << " Currency = " << cash.getCurrency() << endl;

  }
  catch (MyString e)
  {
    cout << "Error: " << e << endl;
  }
  return 0;
}
