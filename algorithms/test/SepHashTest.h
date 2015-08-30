#ifndef _SEP_HASH_TEST_
#define _SEP_HASH_TEST_

#include "gtest/gtest.h"
#include "../list/SepHash.h"

class CSepHashTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		for (int i = 12; i < 30; ++ i)
			hash.Insert(i);
	}
	NsSepHash::CSepHash hash;
};
TEST_F(CSepHashTest, output)
{
	std::cout << hash << std::endl;
}

#endif