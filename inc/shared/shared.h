#ifndef _SHARED_H_
#define _SHARED_H_

#include "shared_export.h"

namespace Foo {

class SHARED_EXPORT Shared 
{

public:
  Shared(int rhs);
  ~Shared() = default;
  int getSam() const;
  
protected:
  int sam;

};

}

#endif /* _SHARED_H_ */
