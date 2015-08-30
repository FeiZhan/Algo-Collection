/// from DSAA

#ifndef _SINGLE_LIST_
#define _SINGLE_LIST_

#include <iostream>

namespace NsSingleList
{
	struct SingleListNode
	{
		int key;
		struct SingleListNode *next;
	};
	class CSingleList
	{
	public:
		CSingleList(void);
		~CSingleList(void);
		bool isEmpty(void);
		bool isLast(const struct SingleListNode *node);
		struct SingleListNode *Find(const int key);
		bool Delete(const int key);
		bool PushBack(const int key);
		bool Insert(const int key, struct SingleListNode *pos);
		bool Clear(void);
		friend std::ostream &operator<< (std::ostream &os, CSingleList &list);
	protected:
		struct SingleListNode *FindPrevious(const int key);
	private:
		struct SingleListNode *head;
	};
}

#endif