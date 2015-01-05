//
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

#include <vector>

int dfs(int current, int depth, vector<bool> &visit_list, const vector<vector<int> > &edge_list) {
	if (visit_list[current]) {
		return depth - 1;
	}
	visit_list[current] = true;
	int depth_max = depth;
	for (size_t i = 0; i < edge_list[current].size(); ++ i) {
		if (! visit_list[edge_list[current][i]]) {
			int new_depth = dfs(edge_list[current][i], depth + 1, visit_list, edge_list);
			depth_max = std::max(depth_max, new_depth);
		}
	}
	return depth_max;
}

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("output.txt");
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("output.txt", "w", stdout);
#endif
#endif

	int node_num;
	if (cin >> node_num || true) {
		vector<vector<int> > edge_list(node_num);
		int source, target;
		while (cin >> source >> target) {
			-- source;
			-- target;
			edge_list[source].push_back(target);
			edge_list[target].push_back(source);
		}
		vector<int> depth_list(node_num, 0);
		vector<bool> visit_list(node_num, false);
		int component_count = 0;
		for (int i = 0; i < node_num; ++ i) {
			if (0 == component_count) {
				visit_list.assign(node_num, false);
			}
			depth_list[i] = dfs(i, 0, visit_list, edge_list);
			for (size_t j = i + 1; j < visit_list.size(); ++ j) {
				if (! visit_list[j]) {
					++ component_count;
					i = j;
					break;
				}
			}
		}
		if (component_count) {
			// the example is wrong
			cout << "Error: " << component_count + 1 << " components" << endl;
		} else {
			int depth_max = 0;
			vector<size_t> max_list;
			for (size_t i = 0; i < depth_list.size(); ++ i) {
				if (depth_list[i] > depth_max) {
					depth_max = depth_list[i];
					max_list.clear();
					max_list.push_back(i + 1);
				}
				else if (depth_list[i] == depth_max) {
					max_list.push_back(i + 1);
				}
			}
			for (size_t i = 0; i < max_list.size(); ++ i) {
				cout << max_list[i] << endl;
			}
		}
	}

	return 0;
}




