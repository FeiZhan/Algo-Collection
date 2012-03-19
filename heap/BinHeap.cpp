#include "BinHeap.h"

namespace NsBinHeap
{
	bool CBinHeap::Insert(const int key)
	{
		if (this->heap.size() == 0)
		{
			this->heap.push_back(key);
			return true;
		}
		this->heap.resize(this->heap.size() + 1);
		int i;
		for (i = this->heap.size() - 1; this->heap.at(i / 2) > key && i > 0
			; i /= 2)
		{
			this->heap[i] = this->heap.at(i / 2);
		}
		this->heap[i] = key;
		return true;
	}
	bool CBinHeap::Empty(void)
	{
		return this->heap.empty();
	}
	int CBinHeap::LeftChild(const int pos)
	{
		return pos * 2 + 1;
	}
	int CBinHeap::DeleteMin(void)
	{
		if (this->Empty())
		{
			std::cerr << "heap is empty" << std::endl;
			return -1;
		}
		int min = this->heap.at(0)
			, last = this->heap.at(this->heap.size() - 1), child, i;
		for (i = 0; this->LeftChild(i) < this->heap.size(); i = child)
		{
			child = this->LeftChild(i);
			if (child + 1 < this->heap.size()
				&& this->heap.at(child + 1) < this->heap.at(child))
			{
				child ++;
			}
			if (last > this->heap.at(child))
			{
				this->heap[i] = this->heap.at(child);
			}
			else
			{
				break;
			}
		}
		this->heap[i] = last;
		this->heap.erase(this->heap.begin() + this->heap.size() - 1);
		return min;
	}
	std::ostream &operator<< (std::ostream &os, const CBinHeap &heap)
	{
		os << "BinHeap";
		for (int i = 0; i < heap.heap.size(); ++ i)
		{
			os << " " << heap.heap.at(i);
		}
		return os;
	}
}