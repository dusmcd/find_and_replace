#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include"problem3functions.h"

int main() {
  if ( NumDigits(1200) == 4 )
    cout << "Passed NumDigits(1200) test" << endl;
  else
    cout << "Failed NumDigits(1200) test" << endl;

  if ( NumDigits(-31) == 2 )
    cout << "Passed NumDigits(-3) test" << endl;
  else
    cout << "Failed NumDigits(-3) test" << endl;

  if ( NumDigits(0) == 1 )
    cout << "Passed NumDigits(0) test" << endl;
  else
    cout << "Failed NumDigits(0) test" << endl;

  return 0;
}
