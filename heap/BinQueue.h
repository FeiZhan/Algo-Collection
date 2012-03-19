#ifndef _BIN_QUEUE_
#define _BIN_QUEUE_

#include <iostream>

namespace NsBinQueue
{
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
	protected:
		struct BinQueueNode *Combine(struct BinQueueNode *node1
			, struct BinQueueNode *node2);
		struct BinQueueNode *Merge(struct BinQueueNode *node1
			, struct BinQueueNode *node2);
	private:
		struct BinQueueNode *head;
	};
}

#endif