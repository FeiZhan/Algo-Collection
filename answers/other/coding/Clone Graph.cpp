/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        map<UndirectedGraphNode *, UndirectedGraphNode *> node_map;
        cloneGraph(node, node_map);
        return node_map[node];
    }
    void cloneGraph(UndirectedGraphNode *node, map<UndirectedGraphNode *, UndirectedGraphNode *> &node_map) {
        if (NULL == node || node_map.end() != node_map.find(node)) {
            return;
        }
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        node_map.insert(make_pair(node, new_node));
        for (size_t i = 0; i < node->neighbors.size(); ++ i) {
            cloneGraph(node->neighbors[i], node_map);
            new_node->neighbors.push_back(node_map[node->neighbors[i]]);
        }
    }
};