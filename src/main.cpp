#include <iostream>
#include "shared/shared.h"

using namespace std;
using namespace Foo;

int main() {
  Sample sm(44100);
  cout << "Hello World!" << endl;
  cout << "Sample value is: " << sm.getSam() << endl;
  return 0;
}
