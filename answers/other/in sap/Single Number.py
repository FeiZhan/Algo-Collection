class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        total = 0
        for i in nums:
        	total ^= i
        return total