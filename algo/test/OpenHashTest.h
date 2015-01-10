#ifndef _OPEN_HASH_TEST_
#define _OPEN_HASH_TEST_

#include "gtest/gtest.h"
#include "../list/OpenHash.h"

class COpenHashTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		hash.Init(10);
		hash.Insert(89);
		hash.Insert(18);
		hash.Insert(49);
		hash.Insert(58);
		hash.Insert(69);
	}
	NsOpenHash::COpenHash hash;
};
TEST_F(COpenHashTest, output)
{
	std::cout << hash << std::endl;
}

#endif