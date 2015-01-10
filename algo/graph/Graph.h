#ifndef _GRAPH_
#define _GRAPH_

#include <vector>

namespace NsGraph
{
	enum VertexColor
	{
		VertexWhite,
		VertexGray,
		VertexBlack
	};
	class CGraph
	{
	public:
		bool CreateGraphMat(const std::vector<std::vector<int> > &mat);
		bool CreateGraphTable(const std::vector<std::vector<int> > &table);
		std::vector<int> DistToAllVertex(const int index);
		std::vector<int> TopoSort(void);
		/// \todo undone
		int Prim(const std::vector<std::vector<int> > weight, const int index);
	protected:
		std::vector<int> Bfs(const int index);
		bool Dfs(std::vector<int> &begin, std::vector<int> &end);
		bool DfsVisit(const int index
			, std::vector<enum VertexColor> &ver_color, std::vector<int> &begin
			, std::vector<int> &end, int &now);
	private:
		std::vector<std::vector<int> > m_mat, m_table;
	};
}

#endif