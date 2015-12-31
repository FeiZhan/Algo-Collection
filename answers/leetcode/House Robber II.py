class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        dp = [[0 for i in range(len(nums))] for j in range(2)]
        max_rob = 0
        for i in range(2):
            for j in range(len(nums)):
                dp[i][j] = max((dp[i][j - 1] if j >= 1 else 0), (dp[i][j - 2] if j >= 2 else 0) + (nums[j] if not (1 == i and len(nums) == j + 1 and j > 0) and not (0 == i and 0 == j) else 0))
                max_rob = max(max_rob, dp[i][j])
        return max_rob
