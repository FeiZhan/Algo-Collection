#ifndef _COMPLEX_TEST_
#define _COMPLEX_TEST_

#include "gtest/gtest.h"
#include "../math/Complex.h"

class CComplexTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		c = NsComplex::CComplex(3, 4);
	}
	NsComplex::CComplex c;
};
TEST_F(CComplexTest, output)
{
	std::cout << c << std::endl;
	EXPECT_EQ(5, c.Mod());
	EXPECT_EQ(NsComplex::CComplex(3, -4), c.Conjugate());
}
TEST_F(CComplexTest, addition)
{
	EXPECT_EQ(NsComplex::CComplex(4, 5), c + NsComplex::CComplex(1, 1));
	EXPECT_EQ(NsComplex::CComplex(4, 4), c + 1);
	EXPECT_EQ(NsComplex::CComplex(4, 4), 1 + c);
}

#endif