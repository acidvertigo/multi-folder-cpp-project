#include "gtest/gtest.h"
#include "static/static.h"

using namespace ::Foo;

class StaticTest : public ::testing::Test
{
public:
    StaticTest() {}
    virtual ~StaticTest() {}

protected:
     Static * sm;
 
     virtual void SetUp() override
     {      
         sm = new Static(11);
     }

     virtual void TearDown() override
     {
        delete sm;
     }
};

TEST_F(StaticTest, smTest)
{
    ASSERT_EQ(sm->getSam(), 11);
}
