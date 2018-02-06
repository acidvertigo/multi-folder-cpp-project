#ifndef _SHARED_H_
#define _SHARED_H_

#include "shared_export.h"

namespace Foo {

class Shared 
{

public:
  SHARED_EXPORT Shared(int rhs);
  virtual ~Shared() = default;
  int SHARED_EXPORT getSam() const;
  
protected:
  int sam;

};

}

#endif /* _SHARED_H_ */
