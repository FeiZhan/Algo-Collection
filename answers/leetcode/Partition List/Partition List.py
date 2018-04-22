# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """

        dummy = ListNode(-1)
        dummy.next = head
        current = dummy
        dummy0 = ListNode(-1)
        less = dummy0
        dummy1 = ListNode(-1)
        greater = dummy1
        while current.next:
            if current.next.val < x:
                less.next = current.next
                less = less.next
            else:
                greater.next = current.next
                greater = greater.next
            current = current.next
        less.next = dummy1.next
        greater.next = None
        return dummy0.next
