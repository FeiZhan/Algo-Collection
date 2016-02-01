//@result TLE

#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

int find(int node, unordered_map<int, int> &node_map) {
    if (node_map.end() == node_map.find(node)) {
        return -1;
    }
    else if (node_map[node] == node) {
        return node;
    }
    else {
        return find(node_map[node], node_map);
    }
}
void combine(int node0, int node1, unordered_map<int, int> &node_map) {
    if (node_map.end() == node_map.find(node0)) {
        node_map[node0] = node0;
    }
    int root0 = find(node0, node_map);
    if (node_map.end() == node_map.find(node1)) {
        node_map[node1] = node1;
    }
    int root1 = find(node1, node_map);
    if (root0 != root1) {
        node_map[root0] = root1;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int edge_num = 0;
    while (cin >> edge_num) {
        unordered_map<int, int> node_map;
        for (int i = 0; i < edge_num; ++ i) {
            int node0 = 0;
            int node1 = 0;
            cin >> node0 >> node1;
            combine(node0, node1, node_map);
        }
        unordered_map<int, int> root_map;
        for (unordered_map<int, int>::iterator it = node_map.begin(); it != node_map.end(); ++ it) {
            ++ root_map[find(it->first, node_map)];
        }
        int min_count = INT_MAX;
        int max_count = INT_MIN;
        for (unordered_map<int, int>::iterator it = root_map.begin(); it != root_map.end(); ++ it) {
            min_count = min(min_count, it->second);
            max_count = max(max_count, it->second);
        }
        cout << min_count << " " << max_count << endl;
    }
    return 0;
}
