#include "DisjointSet.h"

namespace NsDisjointSet
{
	CDisjointSet &CDisjointSet::operator<< (const int key)
	{
		struct DisjointNode node;
		node.key = key;
		node.root = -1;
		this->m_set.push_back(node);
		return *this;
	}
	int CDisjointSet::FindKey(const int key)
	{
		for (int i = 0; i < this->m_set.size(); ++ i)
		{
			if (this->m_set.at(i).key == key)
				return i;
		}
		return -1;
	}
	int CDisjointSet::Find(const int node)
	{
		if (this->m_set.at(node).root == -1)
			return node;
		else
			return this->Find(this->m_set.at(node).root);
	}
	bool CDisjointSet::SetUnion(const int node, const int key)
	{
		int root = this->m_set.at(node).root;
		if (root == -1)
			root = node;
		this->m_set.at(this->Find(this->FindKey(key))).root = root;
		return true;
	}
	std::ostream &operator<< (std::ostream &os, const CDisjointSet &set)
	{
		os << "DisjointSet";
		for (int i = 0; i < set.m_set.size(); ++ i)
		{
			os << " " << set.m_set.at(i).key << " root " << set.m_set.at(i).root;
		}
		return os;
	}
}