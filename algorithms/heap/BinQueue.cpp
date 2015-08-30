#include "BinQueue.h"

namespace NsBinQueue
{
	CBinQueue::CBinQueue(void)
	{}
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
	bool CBinQueue::Merge(const CBinQueue &queue)
	{
		int carry = 0;
		struct BinQueueNode *carry_node = NULL;
		BinQueType::const_iterator it2 = queue.bin_queue.begin();
		for (BinQueType::iterator it1 = this->bin_queue.begin()
			; it1 != this->bin_queue.end(); ++ it1)
		{
			while (it2 != queue.bin_queue.end() && it2->first <= it1->first)
			{
				/// only carry
				if (carry > 0 && carry < it2->first)
				{
					this->bin_queue.insert(std::make_pair(carry, carry_node));
					carry = 0;
				}
				/// only it2
				else if (carry == 0 && it2->first < it1->first)
				{
					this->bin_queue.insert(*it2);
				}
				/// carry and it2 (maybe it1)
				else if (carry == it2->first)
				{
					carry_node = this->Combine(carry_node, it2->second);
					carry *= 2;
				}
				/// it1 and it2
				else if (carry == 0 && it2->first == it1->first)
				{
					carry_node = this->Combine(it1->second, it2->second);
					carry = it1->first * 2;
					this->bin_queue.erase(it1);
					-- it1;
				}
				++ it2;
			}
		}
		BinQueType::iterator found;
		while (carry > 0)
		{
			found = this->bin_queue.find(carry);
			if (found == this->bin_queue.end())
			{
				this->bin_queue.insert(std::make_pair(carry, carry_node));
				carry = 0;
			}
			else
			{
				carry_node = this->Combine(found->second, carry_node);
				carry *= 2;
				this->bin_queue.erase(found);
			}
		}
		return true;
	}
	int CBinQueue::DeleteMin(void)
	{
		if (this->bin_queue.size() == 0)
		{
			std::cerr << "empty bin queue" << std::endl;
			return 0;
		}
		int min = INT_MAX;
		BinQueType::iterator min_it;
		for (BinQueType::iterator it = this->bin_queue.begin()
			; it != this->bin_queue.end(); ++ it)
		{
			if (it->second->key < min)
			{
				min = it->second->key;
				min_it = it;
			}
		}
		BinQueType tmp;
		BinQueueNode tmp_node;
		if (min_it->second->left)	/// \bug 个数是不确定的
		{
			//tmp = std::make_pair(min_it->first / 2 - 1, min_it->second->left);
		}
		return 0;
	}
}