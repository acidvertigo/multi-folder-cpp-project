#include "gtest/gtest.h"
//#include "gmock/gmock.h"
#include "sample/sample.h"

using namespace ::Foo;
//namespace {

class SampleTest : public ::testing::Test
{
public:
    SampleTest() {}
    virtual ~SampleTest() {}

protected:
     Sample * sm;
 
     virtual void SetUp()
     {      
         sm = new Sample(11);
     }

     virtual void TearDown()
     {
        delete sm;
     }
};

TEST_F(sampleTest, smTest)
{
    ASSERT_EQ(*sm.getSam(), 11);
}

//}