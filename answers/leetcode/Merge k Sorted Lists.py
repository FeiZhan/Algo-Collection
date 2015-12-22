# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """

        heap = []
        for i in lists:
            if i:
                heap.append((i.val, i))
        heapq.heapify(heap)
        dummy = ListNode(-1)
        current = dummy
        while len(heap):
            pop = heapq.heappop(heap)
            current.next = pop[1]
            if pop[1].next:
                heapq.heappush(heap, (pop[1].next.val, pop[1].next))
            current = current.next
        return dummy.next
