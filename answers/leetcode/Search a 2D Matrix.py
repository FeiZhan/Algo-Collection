class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """

        row = 0
        column = len(matrix[row]) - 1
        while row >= 0 and row < len(matrix) and column >= 0 and column < len(matrix[row]):
            if matrix[row][column] == target:
                return True
            elif matrix[row][column] < target:
                row += 1
            else:
                column -= 1
        return False
