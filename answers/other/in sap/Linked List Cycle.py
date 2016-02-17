# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        
        if None == head:
        	return False
        left = head
        right = head.next
        while right and left != right:
        	left = left.next
        	right = right.next
        	if not right:
        		return False
        	right = right.next
        return None != right