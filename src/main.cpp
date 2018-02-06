#include <iostream>
#include "shared/shared.h"
#include "static/static.h"

using namespace std;
using namespace Foo;

int main() {
  Shared sh(44100);
  Static st(88200);
  cout << "Hello World!" << endl;
  cout << "Shared value is: " << sh.getSam() << endl;
  cout << "Static value is: " << st.getSam() << endl;
  return 0;
}
