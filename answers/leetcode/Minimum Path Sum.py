class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        dp = [[sys.maxint for i in range(len(grid[0]))] for j in range(len(grid))]
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                dp[i][j] = min((dp[i - 1][j] if i else sys.maxint), (dp[i][j - 1] if j else sys.maxint))
                if sys.maxint == dp[i][j]:
                    dp[i][j] = 0
                dp[i][j] += grid[i][j]
        return dp[-1][-1]
