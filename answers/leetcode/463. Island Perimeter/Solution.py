class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        height = len(grid)
        width = len(grid[0])
        result = 0
        for i in range(0, height):
            row = grid[i]
            for j in range(0, width):
                cell = row[j]
                if cell == 1:
                    if i == 0 or grid[i - 1][j] == 0:
                        result += 1
                    if i + 1 == height or grid[i + 1][j] == 0:
                        result += 1
                    if j == 0 or grid[i][j - 1] == 0:
                        result += 1
                    if j + 1 == width or grid[i][j + 1] == 0:
                        result += 1
        return result

