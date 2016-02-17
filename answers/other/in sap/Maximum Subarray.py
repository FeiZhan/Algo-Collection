class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        sum = 0
        max_sum = -sys.maxint - 1
        for i in nums:
            if sum < 0:
                sum = 0
            sum += i
            max_sum = max(max_sum, sum)
        return max_sum