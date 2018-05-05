# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        if None == l1:
            return l2
        if None == l2:
            return l1
        carry = 0
        dummy = ListNode(-1)
        current = dummy
        while l1 or l2 or carry:
            if l1:
                carry += l1.val
                l1 = l1.next
            if l2:
                carry += l2.val
                l2 = l2.next
            current.next = ListNode(carry % 10)
            carry /= 10
            current = current.next
        return dummy.next
