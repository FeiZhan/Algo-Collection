#include "SepHash.h"

namespace NsSepHash
{
	CSepHash::CSepHash(void)
	{
		this->Init();
	}
	CSepHash::~CSepHash(void)
	{
		ListNode *tmp, *tmp2;
		for (int i = 0; i < this->list_head.size(); ++ i)
		{
			tmp = this->list_head.at(i);
			tmp2 = tmp->next;
			while (tmp && tmp2)
			{
				delete tmp;
				tmp = tmp2;
				tmp2 = tmp2->next;
			}
			if (tmp != NULL)
			{
				delete tmp;
			}
		}
	}
	bool CSepHash::Init(int table_size)
	{
		if (table_size < MIN_TBL_SIZE)
		{
			std::cerr << "table size is too small" << std::endl;
			table_size = MIN_TBL_SIZE;
		}
		this->list_head.resize(this->NextPrime(table_size));
		for (int i = 0; i < this->list_head.size(); ++ i)
		{
			this->list_head[i] = new ListNode;
			if (this->list_head.at(i) == NULL)
			{
				std::cerr << "out of space" << std::endl;
				return false;
			}
			else
				this->list_head.at(i)->next = NULL;
		}
		return true;
	}
	/// \todo next prime
	int CSepHash::NextPrime(const int num)
	{
		return num;
	}
	ListNode *CSepHash::Find(const int key)
	{
		ListNode *node = this->list_head.at(this->Hash(key));
		node = node->next;
		while (node != NULL && node->key != key)
			node = node->next;
		return node;
	}
	int CSepHash::Hash(const int key)
	{
		return key % this->list_head.size();
	}
	bool CSepHash::Insert(const int key)
	{
		ListNode *node = this->Find(key);
		if (node == NULL) /// key is not found, insert
		{
			ListNode *new_node = new ListNode;
			if (new_node == NULL)
			{
				std::cerr << "out of memory" << std::endl;
				return false;
			}
			ListNode *head = this->list_head.at(this->Hash(key));
			new_node->next = head->next;
			new_node->key = key;
			head->next = new_node;
		}
		return true;
	}
	std::ostream &operator<< (std::ostream &os, const CSepHash &hash)
	{
		ListNode *pos;
		os << "SepHash ";
		for (int i = 0; i < hash.list_head.size(); ++ i)
		{
			pos = hash.list_head.at(i);
			os << i << "( ";
			while (pos)
			{
				os << pos->key << " ";
				pos = pos->next;
			}
			os << ") ";
		}
		return os;
	}
}