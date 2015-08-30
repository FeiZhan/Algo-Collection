//
#include <cstdio>
#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

void buildTree(int root, int &index, const vector<int> &num_list, vector<int> &node_list) {
	if (root >= num_list.size()) {
		return;
	}
	buildTree(root * 2 + 1, index, num_list, node_list);
	node_list[root] = num_list[index];
	++ index;
	buildTree(root * 2 + 2, index, num_list, node_list);
}
int main (int argc, char *argv[])
{
	int num_num(0);
	while (cin >> num_num) {
		vector<int> num_list;
		for (int i = 0; i < num_num; ++ i) {
			int num(0);
			cin >> num;
			num_list.push_back(num);
		}
		sort(num_list.begin(), num_list.end());
		vector<int> node_list(num_list.size(), 0);
		int index(0);
		buildTree(0, index, num_list, node_list);
		cout << node_list[0];
		for (size_t i = 1; i < node_list.size(); ++ i) {
			cout << " " << node_list[i];
		}
		cout << endl;
	}

	return 0;
}