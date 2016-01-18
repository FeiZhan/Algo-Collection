//@result Submitted a few seconds ago • Score: 50.00 Status: Accepted Test Case #0: 0s Test Case #1: 0s Test Case #2: 0s Test Case #3: 0s Test Case #4: 0s Test Case #5: 0s Test Case #6: 0s Test Case #7: 0s Test Case #8: 0s Test Case #9: 0s
//@algorithm dfs

#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int dfs(size_t current, vector<unordered_set<int> > &graph_mat, vector<int> &child_list, int &cut_num) {
    if (INT_MAX == child_list[current]) {
        child_list[current] = 1;
        for (unordered_set<int>::iterator it = graph_mat[current].begin(); it != graph_mat[current].end(); ++ it) {
            if (INT_MAX == child_list[*it]) {
                int child_count = dfs(*it, graph_mat, child_list, cut_num);
                if (0 == child_count % 2) {
                    //graph_mat[current].erase(*it);
                    //graph_mat[*it].erase(current);
                    ++ cut_num;
                } else {
                    child_list[current] += child_count;
                }
            }
        }
    }
    return child_list[current];
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int vertex_num = 0;
    int edge_num = 0;
    while (cin >> vertex_num >> edge_num) {
        vector<unordered_set<int> > graph_mat(vertex_num);
        for (int i = 0; i < edge_num; ++ i) {
            int vertex0 = 0;
            int vertex1 = 0;
            cin >> vertex0 >> vertex1;
            graph_mat[vertex0 - 1].insert(vertex1 - 1);
            graph_mat[vertex1 - 1].insert(vertex0 - 1);
        }
        vector<int> child_list(vertex_num, INT_MAX);
        int cut_num = 0;
        dfs(0, graph_mat, child_list, cut_num);
        cout << cut_num << endl;
    }
    return 0;
}
