/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<int> indegree(graph.size(), 0);
        for (size_t i = 0; i < graph.size(); ++ i) {
            for (size_t j = 0; j < graph[i]->neighbors.size(); ++ j) {
                ++ indegree[graph[i]->neighbors[j]->label];
            }
        }
        queue<size_t> node_que;
        for (size_t i = 0; i < indegree.size(); ++ i) {
            if (0 == indegree[i]) {
                node_que.push(i);
            }
        }
        vector<DirectedGraphNode *> sorted;
        while (! node_que.empty()) {
            size_t current = node_que.front();
            node_que.pop();
            sorted.push_back(graph[current]);
            for (size_t i = 0; i < graph[current]->neighbors.size(); ++ i) {
                if (indegree[graph[current]->neighbors[i]->label] > 0) {
                    -- indegree[graph[current]->neighbors[i]->label];
                    if (0 == indegree[graph[current]->neighbors[i]->label]) {
                        node_que.push(graph[current]->neighbors[i]->label);
                    }
                }
            }
        }
        return sorted;
    }
};
