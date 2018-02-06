#include "gtest/gtest.h"
#include "shared/shared.h"

using namespace ::Foo;

class SharedTest : public ::testing::Test
{
public:
    SharedTest() {}
    virtual ~SharedTest() {}

protected:
     Shared * sm;
 
     virtual void SetUp() override
     {      
         sm = new Shared(11);
     }

     virtual void TearDown() override
     {
        delete sm;
     }
};

TEST_F(SharedTest, smTest)
{
    ASSERT_EQ(sm->getSam(), 11);
}
