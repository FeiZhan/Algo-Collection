/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    
    private Map<Integer, UndirectedGraphNode> nodeMap = new HashMap<>();
    
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if (null == node) {
            return null;
        } else if (!this.nodeMap.containsKey(node.label)) {
            UndirectedGraphNode cloned = new UndirectedGraphNode(node.label);
            this.nodeMap.put(cloned.label, cloned);
            for (UndirectedGraphNode neighbor : node.neighbors) {
                cloned.neighbors.add(this.cloneGraph(neighbor));
            }
        }
        return this.nodeMap.get(node.label);
    }
}