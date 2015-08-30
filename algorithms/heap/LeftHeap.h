/// from DSAA

#ifndef _LEFT_HEAP_
#define _LEFT_HEAP_

#include <iostream>

namespace NsLeftHeap
{
	struct LeftHeapNode
	{
		int key, npl;
		struct LeftHeapNode *left, *right;
		friend std::ostream &operator<< (std::ostream &os
			, const struct LeftHeapNode &node);
	};
	class CLeftHeap
	{
	public:
		CLeftHeap(void);
		~CLeftHeap(void);
		bool Empty(void);
		bool Insert(const int key);
		int DeleteMin(void);
		friend std::ostream &operator<< (std::ostream &os
			, const CLeftHeap &heap);
	protected:
		struct LeftHeapNode *InsertNode(const int key
			, struct LeftHeapNode *node);
		/// \note main operation. O(logN)
		struct LeftHeapNode *Merge(struct LeftHeapNode *node1
			, struct LeftHeapNode *node2);
		struct LeftHeapNode *MergeNode(struct LeftHeapNode *node1
			, struct LeftHeapNode *node2);
		bool SwapChildren(struct LeftHeapNode *node);
	private:
		struct LeftHeapNode *root;
	};
}

#endif