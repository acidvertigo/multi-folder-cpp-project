#include "shared/shared.h"

using namespace Foo;

Shared::Shared(int rhs) : sam(10) {
  sam = rhs;
}

int Shared::getSam() const {
  return sam;
}
