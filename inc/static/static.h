#ifndef _STATIC_H_
#define _STATIC_H_

namespace Foo {

class Static
{

public:
  Static(int rhs);
  virtual ~Static() = default;
  int getSam() const;
  
protected:
  int sam;

};

}

#endif /* _STATIC_H_ */
