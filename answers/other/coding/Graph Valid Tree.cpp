class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here

        parent_list.resize(n, 0);
        iota(parent_list.begin(), parent_list.end(), 0);
        for (size_t i = 0; i < edges.size(); ++ i) {
            int root0 = find(edges[i][0]);
            int root1 = find(edges[i][1]);
            if (root0 == root1) {
                return false;
            }
            parent_list[root1] = root0;
        }
        int count = 0;
        for (size_t i = 0; i < parent_list.size(); ++ i) {
            if (i == parent_list[i]) {
                ++ count;
            }
            if (count > 1) {
                return false;
            }
        }
        return true;
    }
    int find(int node) {
        return node == parent_list[node] ? node : find(parent_list[node]);
    }
    vector<int> parent_list;
};