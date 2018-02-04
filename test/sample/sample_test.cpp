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
 
     virtual void SetUp() override
     {      
         sm = new Sample(11);
     }

     virtual void TearDown() override
     {
        delete sm;
     }
};

TEST_F(SampleTest, smTest)
{
    ASSERT_EQ(sm.getSam(), 11);
}

//}