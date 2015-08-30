#ifndef _MAX_SEQ_SUM_TEST_
#define _MAX_SEQ_SUM_TEST_

#include "gtest/gtest.h"
#include "../list/MaxSeqSum.h"

class CMaxSeqSumTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		std::vector<int> vec;
		vec.push_back(4);
		vec.push_back(-3);
		vec.push_back(5);
		vec.push_back(-2);
		vec.push_back(-1);
		vec.push_back(2);
		vec.push_back(6);
		vec.push_back(-2);
		seq << vec;
	}
	NsMaxSeqSum::CMaxSeqSum seq;
};
TEST_F(CMaxSeqSumTest, output)
{
	std::cout << seq << std::endl;
}
TEST_F(CMaxSeqSumTest, addition)
{
	EXPECT_EQ(seq.MaxSeqSumSimple(), seq.MaxSeqSumRec());
}

#endif