namespace Foo {

class Sample {
public:
  Sample::Sample(int rhs);
  virtual ~Sample() = default;
  int getSam() const;
  
protected:
  int sam;
};

}