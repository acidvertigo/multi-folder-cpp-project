#include "gtest/gtest.h"
//#include "gmock/gmock.h"
#include "sample/sample.h"

using namespace ::Foo;
//namespace {

// SampleRate Class test 
TEST(sampleTest, getSam)
{
    Sample sm(11);
    int value = sm.getSam();
    ASSERT_EQ(value, 11);
}
//}