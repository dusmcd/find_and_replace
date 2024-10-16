#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include"problem3functions.h"

int main() {
  int x = 1231231;
  FindAndReplace(x, 3, 7);
  if ( x == 1271271 )
    cout << "Passed first one digit replacement test" << endl;
  else
    cout << "Failed first one digit replacement test" << endl;

  x = 1231231;
  FindAndReplace(x, 1, 0);
  if ( x == 230230 )
    cout << "Passed second one digit replacement test" << endl;
  else
    cout << "Failed second one digit replacement test" << endl;

  x = 1231231;
  FindAndReplace(x, 1, 0);
  if ( x == 230230 )
    cout << "Passed second one digit replacement test" << endl;
  else
    cout << "Failed second one digit replacement test" << endl;

  x = -1785;
  FindAndReplace(x, 78, 96);
  if ( x == -1965 )
    cout << "Passed third two digit replacement test" << endl;
  else
    cout << "Failed third two digit replacement test" << endl;

  x = 11121111;
  FindAndReplace(x, 11, 3);
  if ( x == 10320303 )
    cout << "Passed second two digit replacement test" << endl;
  else
    cout << "Failed second two digit replacement test" << endl;

  x = -401401;
  FindAndReplace(x, 41, 7);
  if ( x == -401401 )
    cout << "Passed third two digit replacement test" << endl;
  else
    cout << "Failed third two digit replacement test" << endl;

  return 0;
}
