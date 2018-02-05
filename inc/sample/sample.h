#ifndef _SAMPLE_H_
#define _SAMPLE_H_

#include "sample_export.h"

namespace Foo {

class SAMPLE_NO_EXPORT Sample 
{

public:
  Sample(int rhs);
  virtual ~Sample() = default;
  int SAMPLE_EXPORT getSam() const;
  
protected:
  int sam;

};

}

#endif /* _SAMPLE_H_ */