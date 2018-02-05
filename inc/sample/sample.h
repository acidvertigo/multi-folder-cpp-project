#ifndef _SAMPLE_H_
#define _SAMPLE_H_

#include "sample_export.h"

namespace Foo {

class Sample 
{

public:
  Sample(int rhs);
  virtual ~Sample() = default;
  int getSam() const;
  
protected:
  int sam;

};

}

#endif /* _SAMPLE_H_ */