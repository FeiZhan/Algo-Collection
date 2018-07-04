class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """

        dp = [[0 for i in range(len(obstacleGrid[0]))] for j in range(len(obstacleGrid))]
        dp[0][0] = not obstacleGrid[0][0]
        for i in range(len(obstacleGrid)):
            for j in range(len(obstacleGrid[i])):
                dp[i][j] += ((dp[i - 1][j] if i > 0 else 0) + (dp[i][j - 1] if j > 0 else 0)) if not obstacleGrid[i][j] else 0
        return dp[-1][-1]
