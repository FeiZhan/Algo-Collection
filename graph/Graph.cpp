#include <iostream>
#include <limits.h>
#include <queue>
#include "Graph.h"

namespace NsGraph
{
	bool CGraph::CreateGraphMat(const std::vector<std::vector<int> > &mat)
	{
		std::vector<int> tmp;
		for (int i = 0; i < mat.size(); ++ i)
		{
			tmp.clear();
			for (int j = 0; j < mat.at(i).size(); ++ j)
			{
				tmp.push_back(mat.at(i).at(j));
			}
			this->m_mat.push_back(tmp);
		}
		return true;
	}
	bool CGraph::CreateGraphTable(const std::vector<std::vector<int> > &table)
	{
		std::vector<int> tmp;
		for (int i = 0; i < table.size(); ++ i)
		{
			tmp.clear();
			for (int j = 0; j < table.at(i).size(); ++ j)
			{
				tmp.push_back(table.at(i).at(j));
			}
			this->m_table.push_back(tmp);
		}
		return true;
	}
	std::vector<int> CGraph::DistToAllVertex(const int index)
	{
		return Bfs(index);
	}
	std::vector<int> CGraph::Bfs(const int index)
	{
		// based on graph table
		std::vector<enum VertexColor> ver_color;
		ver_color.resize(this->m_table.size());
		std::vector<int> dist;
		dist.resize(this->m_table.size());
		for (int i = 0; i < this->m_table.size(); ++ i)
		{
			ver_color[i] = VertexWhite;
			dist[i] = INT_MAX;
		}
		ver_color[index] = VertexGray;
		dist[index] = 0;
		std::queue<int> ver_queue;
		ver_queue.push(index);
		int now;
		while (! ver_queue.empty())
		{
			now = ver_queue.front();
			ver_queue.pop();
			for (int i = 0; i < this->m_table.at(now).size(); ++ i)
			{
				if (ver_color[this->m_table.at(now).at(i)] == VertexWhite)
				{
					ver_color[this->m_table.at(now).at(i)] = VertexGray;
					dist[this->m_table.at(now).at(i)] = dist[now] + 1;
					ver_queue.push(this->m_table.at(now).at(i));
				}
			}
			ver_color[now] = VertexBlack;
		}
		return dist;
	}
	bool CGraph::Dfs(std::vector<int> &begin, std::vector<int> &end)
	{
		// based on graph table
		std::vector<enum VertexColor> ver_color;
		ver_color.resize(this->m_table.size());
		begin.resize(this->m_table.size());
		end.resize(this->m_table.size());
		int now = 0;
		for (int i = 0; i < this->m_table.size(); ++ i)
		{
			ver_color[i] = VertexWhite;
		}
		for (int i = 0; i < this->m_table.size(); ++ i)
		{
			if (ver_color[i] == VertexWhite)
			{
				DfsVisit(i, ver_color, begin, end, now);
			}
		}
		return true;
	}
	bool CGraph::DfsVisit(const int index
			, std::vector<enum VertexColor> &ver_color, std::vector<int> &begin
			, std::vector<int> &end, int &now)
	{
		ver_color[index] = VertexGray;
		++ now;
		begin[index] = now;
		for (int i = 0; i < this->m_table.at(index).size(); ++ i)
		{
			if (ver_color[this->m_table.at(index).at(i)] == VertexWhite)
			{
				DfsVisit(this->m_table.at(index).at(i), ver_color
					, begin, end, now);
			}
		}
		ver_color[index] = VertexBlack;
		++ now;
		end[index] = now;
		return true;
	}
	std::vector<int> CGraph::TopoSort(void)
	{
		std::vector<int> begin, end, sort;
		Dfs(begin, end);
		int max, max_ptr;
		while (end.size() > 0)
		{
			max = 0, max_ptr = -1;
			for (int j = 0; j < end.size(); ++ j)
			{
				if (end.at(j) > max)
				{
					max = end.at(j);
					max_ptr = j;
				}
			}
			if (max_ptr != -1)
			{
				end[max_ptr] = -1;
				sort.push_back(max_ptr);
			}
		}
		return sort;
	}
	int CGraph::Prim(const std::vector<std::vector<int> > weight, const int index)
	{
		std::vector<int> key;
		for (int i = 0; i < this->m_mat.size(); ++ i)
		{
			key.push_back(INT_MAX);
		}
		key[index] = 0;
		return false;
	}
}