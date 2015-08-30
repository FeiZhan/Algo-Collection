#include "SingleList.h"

namespace NsSingleList
{
	CSingleList::CSingleList(void)
	{
		this->head = new struct SingleListNode;
		this->head->key = -1;
		this->head->next = NULL;
	}
	CSingleList::~CSingleList(void)
	{
		this->Clear();
		delete this->head;
		this->head = NULL;
	}
	bool CSingleList::isEmpty(void)
	{
		return this->head->next == NULL;
	}
	bool CSingleList::isLast(const struct SingleListNode *node)
	{
		return node->next == NULL;
	}
	struct SingleListNode *CSingleList::Find(const int key)
	{
		struct SingleListNode *tmp = this->head->next;
		while (tmp != NULL && tmp->key != key)
		{
			tmp = tmp->next;
		}
		return tmp;
	}
	struct SingleListNode *CSingleList::FindPrevious(const int key)
	{
		struct SingleListNode *tmp = this->head;
		while (tmp->next != NULL && tmp->next->key != key)
		{
			tmp = tmp->next;
		}
		return tmp;
	}
	bool CSingleList::Delete(const int key)
	{
		struct SingleListNode *previous = this->FindPrevious(key), *tmp;
		if (! this->isLast(previous))
		{
			tmp = previous->next;
			previous->next = tmp->next;
			delete tmp;
			tmp = NULL;
		}
		return true;
	}
	bool CSingleList::Insert(const int key, struct SingleListNode *pos)
	{
		struct SingleListNode *tmp = new struct SingleListNode;
		if (tmp == NULL)
		{
			std::cerr << " out of space" << std::endl;
			return false;
		}
		tmp->key = key;
		tmp->next = pos->next;
		pos->next = tmp;
		return true;
	}
	bool CSingleList::Clear(void)
	{
		struct SingleListNode *pos = head->next, *tmp;
		head->next = NULL;
		while (pos != NULL)
		{
			tmp = pos->next;
			delete pos;
			pos = tmp;
		}
		return true;
	}
	bool CSingleList::PushBack(const int key)
	{
		struct SingleListNode *pos = this->head;
		while (! this->isLast(pos))
		{
			pos = pos->next;
		}
		struct SingleListNode *node = new struct SingleListNode;
		if (node == NULL)
		{
			std::cerr << "out of memory" << std::endl;
		}
		node->key = key;
		node->next = NULL;
		pos->next = node;
		return true;
	}
	std::ostream &operator<< (std::ostream &os, CSingleList &list)
	{
		struct SingleListNode *pos = list.head->next;
		os << "SingleList ";
		while (pos)
		{
			os << pos->key << " ";
			pos = pos->next;
		}
		return os;
	}
}