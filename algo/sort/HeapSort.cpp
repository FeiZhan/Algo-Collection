#include <iostream>
#include <limits.h>
#include "HeapSort.h"

namespace NsHeapSort
{
	int CHeapSort::HeapSize(void)
	{
		return this->m_heap.size();
	}
	std::vector<int> CHeapSort::GetHeap(void)
	{
		return this->m_heap;
	}
	bool CHeapSort::PrintHeap(void)
	{
		std::cout << "HeapSort content:";
		for (int i = 0; i < this->m_heap.size(); ++ i)
		{
			std::cout << " " << this->m_heap.at(i);
		}
		std::cout << std::endl;
		return true;
	}
	int CHeapSort::Parent(const int index)
	{
		return (index - 1) / 2;
	}
	int CHeapSort::Left(const int index)
	{
		return 2 * index + 1;
	}
	int CHeapSort::Right(const int index)
	{
		return 2 * index + 2;
	}
	bool CHeapSort::CreateHeap(const std::vector<int> &num)
	{
		this->m_heap.clear();
		for (std::vector<int>::const_iterator it = num.begin()
			; it != num.end()
			; ++ it)
		{
			this->m_heap.push_back(*it);
		}
		return true;
	}
	bool CHeapSort::MaxHeapify(const int index
		, const int end)
	{
		int left = this->Left(index);
		int right = this->Right(index);
		int max;
		if (left < end && m_heap.at(left) > m_heap.at(index))
		{
			max = left;
		}
		else
		{
			max = index;
		}
		if (right < end && m_heap.at(right) > m_heap.at(max))
		{
			max = right;
		}
		if (max != index)
		{
			std::swap(m_heap[index], m_heap[max]);
			this->MaxHeapify(max, end);
		}
		return true;
	}
	bool CHeapSort::BuildMaxHeap(const std::vector<int> &num)
	{
		this->CreateHeap(num);
		for (int i = num.size() - 1; i >= 0; -- i)
		{
			this->MaxHeapify(i, this->m_heap.size());
		}
		return true;
	}
	std::vector<int> CHeapSort::HeapSort(void)
	{
		for (int i = this->m_heap.size() - 1; i >= 1; -- i)
		{
			std::swap(this->m_heap[0], this->m_heap[i]);
			this->MaxHeapify(0, i);
		}
		std::vector<int> tmp = this->m_heap;
		BuildMaxHeap(this->m_heap);
		return tmp;
	}
	int CHeapSort::HeapMax(void)
	{
		return this->m_heap.at(0);
	}
	bool CHeapSort::ExtractMax(void)
	{
		if (this->m_heap.size() <= 0)
		{
			std::cerr << "heap underflow." << std::endl;
			return false;
		}
		int max = this->m_heap.at(0);
		this->m_heap.at(0) = this->m_heap.at(this->m_heap.size() - 1);
		this->MaxHeapify(0, this->m_heap.size() - 1);
		return true;
	}
	bool CHeapSort::IncreaseKey(const int index, const int key)
	{
		if (key < this->m_heap.at(index))
		{
			std::cerr << "new key is smaller than current key." << std::endl;
			return false;
		}
		this->m_heap[index] = key;
		int i = index;
		while (i > 0
			&& this->m_heap.at(this->Parent(i)) < this->m_heap.at(i))
		{
			std::swap(this->m_heap.at(i)
				, this->m_heap.at(this->Parent(i)));
			i = this->Parent(i);
		}
		return true;
	}
	bool CHeapSort::HeapInsert(const int key)
	{
		this->m_heap.push_back(INT_MIN);
		this->IncreaseKey(this->m_heap.size() - 1, key);
		return true;
	}
}