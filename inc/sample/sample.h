#ifndef _SAMPLE_H_
#define _SAMPLE_H_

namespace Foo {

class Sample {
public:
  Sample(int rhs);
  virtual ~Sample() = default;
  int getSam() const;
  
protected:
  int sam;
};

}

#endif /* _SAMPLE_H_ */