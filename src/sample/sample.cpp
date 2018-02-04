#include "sample/sample.h"

using namespace Foo;

Sample:Sample(int rhs) : sam(10) {
  sam = rhs;
}

int Sample::getSam() const {
  return sam;
}