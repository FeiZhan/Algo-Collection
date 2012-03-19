#ifndef _BIN_HEAP_
#define _BIN_HEAP_

#include <iostream>
#include <vector>

namespace NsBinHeap
{
	class CBinHeap
	{
	public:
		bool Insert(const int key);
		bool Empty(void);
		int DeleteMin(void);
		friend std::ostream &operator<< (std::ostream &os
			, const CBinHeap &heap);
	protected:
		int LeftChild(const int pos);
	private:
		std::vector<int> heap;
	};
}

#endif