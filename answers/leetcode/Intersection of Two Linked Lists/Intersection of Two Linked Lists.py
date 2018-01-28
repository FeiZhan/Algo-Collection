# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """

        lena = 0
        currenta = headA
        while currenta:
            lena += 1
            currenta = currenta.next
        lenb = 0
        currentb = headB
        while currentb:
            lenb += 1
            currentb = currentb.next

        currenta = headA
        currentb = headB
        for i in range(min(lena, lenb), max(lena, lenb)):
            if lena > lenb:
                currenta = currenta.next
            else:
                currentb = currentb.next
        while currenta and currentb and currenta != currentb:
            currenta = currenta.next
            currentb = currentb.next
        return currenta
