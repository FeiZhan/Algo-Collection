class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """

        dp = [0 for i in range(n + 1)]
        dp[0] = 1
        for i in range(n):
            if i + 1 < len(dp):
                dp[i + 1] += dp[i]
            if i + 2 < len(dp):
                dp[i + 2] += dp[i]
        return dp[-1]
