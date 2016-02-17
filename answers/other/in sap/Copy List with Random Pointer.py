# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        
        node_map = {}
        return self.helper(head, node_map)

    def helper(self, head, node_map):
    	if None == head:
    		return head
    	elif head.label not in node_map:
    		node_map[head.label] = RandomListNode(head.label)
    		node_map[head.label].next = self.helper(head.next, node_map)
    		node_map[head.label].random = self.helper(head.random, node_map)
    	return node_map[head.label]