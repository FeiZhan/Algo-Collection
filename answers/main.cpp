#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int id;
    int parent;
    int value;
    vector<int> children;
    Node(int i) : id(i), value(0) {}
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int vertex_num = 0;
    int edge_num = 0;
    cin >> vertex_num >> edge_num;
    vector<Node> node_list;
    for (int i = 0; i < vertex_num; ++ i) {
        node_list.push_back(Node(i + 1));
    }
    for (int i = 0; i < edge_num; ++ i) {
        
    }
    return 0;
}
