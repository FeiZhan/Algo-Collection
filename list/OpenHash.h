#ifndef _OPEN_HASH_
#define _OPEN_HASH_

#include <iostream>
#include <vector>
#define MIN_TBL_SIZE 3

namespace NsOpenHash
{
	enum HashState
	{
		Legit,
		Empty,
		Deleted
	};
	struct HashNode
	{
		int key;
		enum HashState state;
	};
	class COpenHash
	{
	public:
		COpenHash(const int size = MIN_TBL_SIZE);
		~COpenHash(void);
		bool Init(int size = MIN_TBL_SIZE);
		int Find(const int key);
		bool Insert(const int key);
		friend std::ostream &operator<< (std::ostream &os, const COpenHash &list);
	protected:
		int NextPrime(const int num);
		int Hash(const int key);
	private:
		std::vector<struct HashNode> hash_tbl;
	};
}

#endif