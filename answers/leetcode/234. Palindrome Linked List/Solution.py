# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if head == None:
            return True

        size: int = 0
        previous: Optional[ListNode] = None
        fast: Optional[ListNode] = head
        slow: Optional[ListNode] = head
        while fast != None:
            size += 1
            fast = fast.next
            if fast != None:
                size += 1
                fast = fast.next
            temp: Optional[ListNode] = slow
            slow = slow.next
            temp.next = previous
            previous = temp

        if size % 2 == 1:
            previous = previous.next
        while previous != None and slow != None:
            if previous.val != slow.val:
                return False
            previous = previous.next
            slow = slow.next

        return True
