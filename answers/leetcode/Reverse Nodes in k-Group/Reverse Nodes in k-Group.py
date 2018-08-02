# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """

        current = head
        for i in range(k - 1):
            if current:
                current = current.next
        if None == current:
            return head
        dummy = ListNode(-1)
        last = dummy
        current = head
        for i in range(k):
            temp = dummy.next
            dummy.next = current
            current = current.next
            dummy.next.next = temp
            if 0 == i:
                last = dummy.next
        last.next = self.reverseKGroup(current, k)
        return dummy.next
