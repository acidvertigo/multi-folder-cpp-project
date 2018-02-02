#include "sample/sample.h"

Sample::Sample() : sam(10) { };
Sample::~Sample() = default;
int Sample::getSam() const {
  return sam;
}