class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """

        vertical = False
        horizontal = False
        for i in range(len(matrix)):
            if 0 == matrix[i][0]:
                vertical = True
                break
        for i in range(len(matrix[0])):
            if 0 == matrix[0][i]:
                horizontal = True
                break
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if 0 == matrix[i][j]:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[i])):
                if 0 == matrix[i][0] or 0 == matrix[0][j]:
                    matrix[i][j] = 0
        if vertical:
            for i in range(len(matrix)):
                matrix[i][0] = 0
        if horizontal:
            for i in range(len(matrix[0])):
                matrix[0][i] = 0
