#include "gtest/gtest.h"
#include "shared/shared.h"

using namespace ::Foo;

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
    ASSERT_EQ(sm->getSam(), 11);
}
