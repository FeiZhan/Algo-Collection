#ifndef _STACK_
#define _STACK_

#include <iostream>
#include "SingleList.h"

namespace NsStack
{
	typedef struct NsSingleList::SingleListNode StackNode;
	class CStack
	{
	public:
		CStack(void);
		~CStack(void);
		bool isEmpty(void);
		bool Clear(void);
		bool Push(const int key);
		int Top(void);
		bool Pop(void);
		friend std::ostream &operator<< (std::ostream &os, CStack &stack);
	protected:
	private:
		StackNode *head;
	};
}

#endif