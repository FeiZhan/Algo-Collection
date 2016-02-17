class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        
        reach = 1
        for i in nums:
            if reach <= 0:
                return False
            else:
                reach = max(reach - 1, i)
        return True