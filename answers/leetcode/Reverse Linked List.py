# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        if head:
            if head.next:
                head1 = self.reverseList(head.next)
                head.next.next = head
                head.next = None
                head = head1
        return head
