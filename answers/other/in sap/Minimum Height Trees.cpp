class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int> > graph(n);
        vector<int> degrees(n, 0);
        for (size_t i = 0; i < edges.size(); ++ i) {
            graph[edges[i].first].push_back(edges[i].second);
            ++ degrees[edges[i].first];
            graph[edges[i].second].push_back(edges[i].first);
            ++ degrees[edges[i].second];
        }
        vector<int> height_list(n, INT_MAX);
        queue<int> node_que;
        for (size_t i = 0; i < degrees.size(); ++ i) {
            if (degrees[i] <= 1) {
                height_list[i] = 0;
                if (1 == degrees[i]) {
                    node_que.push(i);
                }
            }
        }
        while (! node_que.empty()) {
            int current = node_que.front();
            node_que.pop();
            for (size_t i = 0; i < graph[current].size(); ++ i) {
                if (degrees[graph[current][i]] > 0) {
                    -- degrees[graph[current][i]];
                    if (1 == degrees[graph[current][i]]) {
                        height_list[graph[current][i]] = min(height_list[graph[current][i]], height_list[current] + 1);
                        node_que.push(graph[current][i]);
                    }
                }
            }
        }
        vector<int> min_nodes;
        int max_height = 0;
        for (size_t i = 0; i < height_list.size(); ++ i) {
            //cout << "debug " << i << " " << height_list[i] << endl;
            if (max_height < height_list[i]) {
                max_height = height_list[i];
                min_nodes.clear();
            }
            if (max_height == height_list[i]) {
                min_nodes.push_back(i);
            }
        }
        return min_nodes;
    }
};