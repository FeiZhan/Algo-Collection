#ifndef _DISJOINT_SET_
#define _DISJOINT_SET_

#include <iostream>
#include <vector>

namespace NsDisjointSet
{
	struct DisjointNode
	{
		int key;
		int root;
	};
	class CDisjointSet
	{
	public:
		CDisjointSet &operator<< (const int key);
		int FindKey(const int key);
		int Find(const int node);
		bool SetUnion(const int node, const int key);
		friend std::ostream &operator<< (std::ostream &os
			, const CDisjointSet &set);
	protected:
	private:
		std::vector<struct DisjointNode> m_set;
	};
}

#endif