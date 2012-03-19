#ifndef _GRAPH_TEST_
#define _GRAPH_TEST_

#include "gtest/gtest.h"
#include "../graph/graph.h"

TEST(GraphTest, DistToAllVertex)
{
	NsGraph::CGraph graph;
	std::vector<int> num_vec;
	std::vector<std::vector<int> > graph_vec;
	num_vec.clear();
	num_vec.push_back(1);
	num_vec.push_back(4);
	graph_vec.push_back(num_vec);
	num_vec.clear();
	num_vec.push_back(0);
	num_vec.push_back(5);
	graph_vec.push_back(num_vec);
	num_vec.clear();
	num_vec.push_back(3);
	num_vec.push_back(5);
	num_vec.push_back(6);
	graph_vec.push_back(num_vec);
	num_vec.clear();
	num_vec.push_back(2);
	num_vec.push_back(6);
	num_vec.push_back(7);
	graph_vec.push_back(num_vec);
	num_vec.clear();
	num_vec.push_back(0);
	graph_vec.push_back(num_vec);
	num_vec.clear();
	num_vec.push_back(1);
	num_vec.push_back(2);
	num_vec.push_back(6);
	graph_vec.push_back(num_vec);
	num_vec.clear();
	num_vec.push_back(2);
	num_vec.push_back(3);
	num_vec.push_back(5);
	num_vec.push_back(7);
	graph_vec.push_back(num_vec);
	num_vec.clear();
	num_vec.push_back(3);
	num_vec.push_back(6);
	graph_vec.push_back(num_vec);
	graph.CreateGraphTable(graph_vec);

	std::vector<int> ok_vec;
	ok_vec.push_back(1);
	ok_vec.push_back(0);
	ok_vec.push_back(2);
	ok_vec.push_back(3);
	ok_vec.push_back(2);
	ok_vec.push_back(1);
	ok_vec.push_back(2);
	ok_vec.push_back(3);
	EXPECT_EQ(ok_vec, graph.DistToAllVertex(1));
}

TEST(GraphTest, TopoSort)
{
	NsGraph::CGraph graph;
	std::vector<int> num_vec;
	std::vector<std::vector<int> > graph_vec;
	num_vec.clear();
	num_vec.push_back(1);
	num_vec.push_back(2);
	graph_vec.push_back(num_vec);
	num_vec.clear();
	num_vec.push_back(3);
	graph_vec.push_back(num_vec);
	num_vec.clear();
	num_vec.push_back(3);
	graph_vec.push_back(num_vec);
	num_vec.clear();
	graph_vec.push_back(num_vec);
	num_vec.clear();
	graph_vec.push_back(num_vec);
	num_vec.clear();
	num_vec.push_back(6);
	num_vec.push_back(7);
	graph_vec.push_back(num_vec);
	num_vec.clear();
	num_vec.push_back(2);
	num_vec.push_back(7);
	graph_vec.push_back(num_vec);
	num_vec.clear();
	graph_vec.push_back(num_vec);
	num_vec.clear();
	num_vec.push_back(7);
	graph_vec.push_back(num_vec);
	graph.CreateGraphTable(graph_vec);

	std::vector<int> ok_vec;
	ok_vec.push_back(8);
	ok_vec.push_back(5);
	ok_vec.push_back(6);
	ok_vec.push_back(7);
	ok_vec.push_back(4);
	ok_vec.push_back(0);
	ok_vec.push_back(2);
	ok_vec.push_back(1);
	ok_vec.push_back(3);
	EXPECT_EQ(ok_vec, graph.TopoSort());
}

#endif