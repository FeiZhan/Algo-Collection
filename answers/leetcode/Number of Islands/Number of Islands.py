class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """

        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if '1' == grid[i][j]:
                    self.dfs(i, j, grid)
                    count += 1
        return count

    def dfs(self, x, y, grid):
        if x < 0 or x >= len(grid) or y < 0 or y >= len(grid[x]) or '1' != grid[x][y]:
            return
        grid[x][y] = '2'
        self.dfs(x - 1, y, grid)
        self.dfs(x + 1, y, grid)
        self.dfs(x, y - 1, grid)
        self.dfs(x, y + 1, grid)
