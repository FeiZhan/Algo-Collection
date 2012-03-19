#include "BinQueue.h"

namespace NsBinQueue
{
	CBinQueue::CBinQueue(void)
	{
		this->head = NULL;
	}
	CBinQueue::~CBinQueue(void)
	{
		/// \todo
	}
	struct BinQueueNode *CBinQueue::Combine(struct BinQueueNode *node1
			, struct BinQueueNode *node2)
	{
		if (node1->key > node2->key)
		{
			return this->Combine(node2, node1);
		}
		node2->sibling = node1->left;
		node1->left = node2;
		return node1;
	}
	struct BinQueueNode *CBinQueue::Merge(struct BinQueueNode *node1
			, struct BinQueueNode *node2)
	{
		/// \todo
		//for (int i = 0, j = 1; j <= node1->)
		return node1;
	}
}