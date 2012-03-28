/// from DSAA

#ifndef _BIN_QUEUE_
#define _BIN_QUEUE_

#include <iostream>
#include <map>
#include <limits.h>

namespace NsBinQueue
{
	typedef std::map<int, struct BinQueueNode *> BinQueType;
	struct BinQueueNode
	{
		int key;
		struct BinQueueNode *left, *sibling;
	};
	class CBinQueue
	{
	public:
		CBinQueue(void);
		~CBinQueue(void);
		int DeleteMin(void);
	protected:
		struct BinQueueNode *Combine(struct BinQueueNode *node1
			, struct BinQueueNode *node2);
		bool Merge(const CBinQueue &queue);
	private:
		BinQueType bin_queue;
	};
}

#endif