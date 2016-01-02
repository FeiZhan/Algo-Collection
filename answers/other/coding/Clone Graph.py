# Definition for a undirected graph node
# class UndirectedGraphNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution(object):
    def cloneGraph(self, node):
        """
        :type node: UndirectedGraphNode
        :rtype: UndirectedGraphNode
        """
        
        node_map = {}
        return self.helper(node, node_map)

    def helper(self, node, node_map):
    	if None == node:
    		return node
    	elif node.label not in node_map:
    		node_map[node.label] = UndirectedGraphNode(node.label)
    		for i in range(len(node.neighbors)):
    			node_map[node.label].neighbors.append(self.helper(node.neighbors[i], node_map))
    	return node_map[node.label]