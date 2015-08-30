#ifndef _BIG_INTEGER_TEST_
#define _BIG_INTEGER_TEST_

#include "gtest/gtest.h"
#include "../math/BigInteger.h"

class CBigIntegerTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		n = NsBigInteger::CBigInteger(123456);
	}
	NsBigInteger::CBigInteger n;
};
TEST_F(CBigIntegerTest, output)
{
	std::cout << n << std::endl;
}
TEST_F(CBigIntegerTest, addition)
{
	EXPECT_EQ(NsBigInteger::CBigInteger(123461)
		, n + NsBigInteger::CBigInteger(5));
}
TEST_F(CBigIntegerTest, stringinput)
{
	EXPECT_EQ(NsBigInteger::CBigInteger(123456)
		, NsBigInteger::CBigInteger("123456"));
}

#endif