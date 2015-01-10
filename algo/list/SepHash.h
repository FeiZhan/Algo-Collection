/// from DSAA

#ifndef _SEP_HASH_
#define _SEP_HASH_

#include <iostream>
#include <vector>
#include "SingleList.h"

#define MIN_TBL_SIZE 3

namespace NsSepHash
{
	typedef struct NsSingleList::SingleListNode ListNode;
	class CSepHash
	{
	public:
		CSepHash(void);
		~CSepHash(void);
		bool Init(int table_size = MIN_TBL_SIZE);
		ListNode *Find(const int key);
		bool Insert(const int key);
		friend std::ostream &operator<< (std::ostream &os, const CSepHash &hash);
	protected:
		int Hash(const int key);
		int NextPrime(const int num);
	private:
		/// \note different from book, not using struct.
		std::vector<ListNode *> list_head;
	};
}
#endif