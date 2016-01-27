//@result Submitted a few seconds ago • Score: 50.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0.09s Test Case #7: 0.1s Test Case #8: 0.1s Test Case #9: 0.1s Test Case #10: 0.1s Test Case #11: 0.1s Test Case #12: 0.1s Test Case #13: 0.09s Test Case #14: 0.09s Test Case #15: 0.09s Test Case #16: 0.09s Test Case #17: 0.1s Test Case #18: 0.09s Test Case #19: 0.09s


#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void dfs(size_t current, const vector<int> &node_list, const vector<vector<int> > &edge_list, vector<int> &sum_list) {
    if (INT_MAX == sum_list[current]) {
        sum_list[current] = node_list[current];
        for (size_t i = 0; i < edge_list[current].size(); ++ i) {
            if (INT_MAX == sum_list[edge_list[current][i]]) {
                dfs(edge_list[current][i], node_list, edge_list, sum_list);
                sum_list[current] += sum_list[edge_list[current][i]];
            }
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int node_num = 0;
    while (cin >> node_num) {
        vector<int> node_list;
        for (int i = 0; i < node_num; ++ i) {
            int node = 0;
            cin >> node;
            node_list.push_back(node);
        }
        vector<vector<int> > edge_list(node_list.size());
        for (int i = 0; i < node_num - 1; ++ i) {
            int node0 = 0;
            int node1 = 0;
            cin >> node0 >> node1;
            edge_list[node0 - 1].push_back(node1 - 1);
            edge_list[node1 - 1].push_back(node0 - 1);
        }
        vector<int> sum_list(node_num, INT_MAX);
        dfs(0, node_list, edge_list, sum_list);
        int min_diff = INT_MAX;
        for (size_t i = 1; i < sum_list.size(); ++ i) {
            int diff = abs(sum_list[0] - 2 * sum_list[i]);
            min_diff = min(min_diff, diff);
        }
        cout << min_diff << endl;
    }
    return 0;
}
