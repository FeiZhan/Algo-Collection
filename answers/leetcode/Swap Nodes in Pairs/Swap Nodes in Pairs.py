# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        if None == head or None == head.next:
            return head
        temp = self.swapPairs(head.next.next)
        new_head = head.next
        new_head.next = head
        new_head.next.next = temp
        return new_head
