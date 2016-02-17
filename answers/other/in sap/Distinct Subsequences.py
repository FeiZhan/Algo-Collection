class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        
        dp = [[0 for j in range(len(t) + 1)] for i in range(len(s) + 1)]
        for i in range(len(s) + 1):
        	dp[i][0] = 1
        for i in range(1, len(s) + 1):
        	for j in range(1, len(t) + 1):
        		dp[i][j] = dp[i - 1][j] + (dp[i - 1][j - 1] if s[i - 1] == t[j - 1] else 0)
        return dp[-1][-1]