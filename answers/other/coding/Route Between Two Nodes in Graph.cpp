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
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        set<int> visit_set;
        return hasRoute(graph, s, t, visit_set);
    }
    bool hasRoute(vector<DirectedGraphNode*> graph, DirectedGraphNode* s, DirectedGraphNode* t, set<int> &visit_set) {
        if (NULL == s || NULL == t) {
            return false;
        }
        if (s == t) {
            return true;
        }
        if (visit_set.end() != visit_set.find(s->label)) {
            return false;
        }
        visit_set.insert(s->label);
        for (size_t i = 0; i < s->neighbors.size(); ++ i) {
            if (hasRoute(graph, s->neighbors[i], t, visit_set)) {
                return true;
            }
        }
        return false;
    }
};

