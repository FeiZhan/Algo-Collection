#include "Stack.h"

namespace NsStack
{
	CStack::CStack(void)
	{
		this->head = new StackNode;
		if (this->head == NULL)
		{
			std::cerr << "out of space" << std::endl;
			return;
		}
		this->head->key = -1;
		this->head->next = NULL;
	}
	CStack::~CStack(void)
	{
		this->Clear();
		delete this->head;
		this->head = NULL;
	}
	bool CStack::isEmpty(void)
	{
		return this->head->next == NULL;
	}
	bool CStack::Clear(void)
	{
		StackNode *pos = this->head->next;
		while (! this->isEmpty())
		{
			this->Pop();
		}
		return true;
	}
	bool CStack::Push(const int key)
	{
		StackNode *tmp = new StackNode;
		if (tmp == NULL)
		{
			std::cerr << "out of memory" << std::endl;
			return false;
		}
		tmp->key = key;
		tmp->next = this->head->next;
		this->head->next = tmp;
		return true;
	}
	int CStack::Top(void)
	{
		if (this->isEmpty())
		{
			std::cerr << "empty stack" << std::endl;
			return -1;
		}
		return this->head->next->key;
	}
	bool CStack::Pop(void)
	{
		if (this->isEmpty())
		{
			std::cerr << "empty stack" << std::endl;
			return false;
		}
		StackNode *tmp = this->head->next;
		this->head->next = this->head->next->next;
		delete tmp;
		return true;
	}
	std::ostream &operator<< (std::ostream &os, CStack &stack)
	{
		StackNode *tmp = stack.head->next;
		os << "stack ";
		while (tmp)
		{
			os << tmp->key << " ";
			tmp = tmp->next;
		}
		return os;
	}
}