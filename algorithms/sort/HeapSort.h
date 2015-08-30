#ifndef _HEAP_SORT_
#define _HEAP_SORT_

#include <vector>

namespace NsHeapSort
{
	class CHeapSort
	{
	public:
		int HeapSize(void);
		std::vector<int> GetHeap(void);
		bool PrintHeap(void);
		bool BuildMaxHeap(const std::vector<int> &num);
		std::vector<int> HeapSort(void);
		int HeapMax(void);
		bool ExtractMax(void);
		bool IncreaseKey(const int index, const int key);
		bool HeapInsert(const int key);
	protected:
		int Parent(const int index);
		int Left(const int index);
		int Right(const int index);
		bool CreateHeap(const std::vector<int> &num);
		bool MaxHeapify(const int index, const int end);
	private:
		std::vector<int> m_heap;
	};
}

#endif