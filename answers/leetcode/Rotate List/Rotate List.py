# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """

        if 0 == k or None == head:
            return head
        dummy = ListNode(-1)
        dummy.next = head
        current = dummy
        count = 0
        while current.next:
            current = current.next
            count += 1
        current.next = dummy.next
        for i in range(count - k % count):
            current = current.next
        head = current.next
        current.next = None
        return head
