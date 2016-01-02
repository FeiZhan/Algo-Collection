class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        
        for i in range(len(matrix) / 2):
            for j in range(i, len(matrix[i]) - i - 1):
                temp = matrix[i][j]
                matrix[i][j] = matrix[- j - 1][i]
                matrix[- j - 1][i] = matrix[- i - 1][- j - 1]
                matrix[- i - 1][- j - 1] = matrix[j][- i - 1]
                matrix[j][- i - 1] = temp
