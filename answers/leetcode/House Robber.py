class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        dp = [0 for i in range(len(nums))]
        for i in range(len(nums)):
            dp[i] = max((dp[i - 1] if i >= 1 else 0), (dp[i - 2] if i >= 2 else 0) + nums[i])
        return dp[-1] if len(nums) else 0
