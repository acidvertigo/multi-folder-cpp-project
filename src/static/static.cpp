#include "static/static.h"

using namespace Foo;

Static::Static(int rhs) : sam(10) {
  sam = rhs;
}

int Static::getSam() const {
  return sam;
}
