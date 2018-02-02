#include "sample/sample.h"

Sample::Sample : sam(10) { };
Sample::~Sample() {};
int Sample::getSam() const {
  return sam;
}