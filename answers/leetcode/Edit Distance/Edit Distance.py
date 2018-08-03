class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """

        length1 = len(word1) + 1
        length2 = len(word2) + 1
        dp = [[1000000 for i in range(length2)] for j in range(length1)]
        for i in range(length1):
            dp[i][0] = i
        for i in range(length2):
            dp[0][i] = i
        for i in range(1, length1):
            for j in range(1, length2):
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + int(word1[i - 1] != word2[j - 1]))
        return dp[-1][-1]
