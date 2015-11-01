//@result TLE

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
		map<int, bool> visit_flag;
		return hasRoute(graph, s, t, visit_flag);
    }
	bool hasRoute(vector<DirectedGraphNode*> graph, DirectedGraphNode* s, DirectedGraphNode* t, map<int, bool> &visit_flag) {
		if (s == t) {
			return true;
		}
		else if (NULL == s || NULL == t || (visit_flag.end() != visit_flag.find(s->label) && visit_flag[s->label])) {
			return false;
		}
		else if (s->label == t->label) {
			return true;
		}
		visit_flag[s->label] = true;
		for (size_t i = 0; i < s->neighbors.size(); ++ i) {
			if (hasRoute(graph, s->neighbors[i], t, visit_flag)) {
				return true;
			}
		}
		visit_flag[s->label] = false;
		return false;
	}
};


