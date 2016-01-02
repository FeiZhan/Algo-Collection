class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        
        pascal = []
        if numRows >= 1:
        	pascal.append([1])
        for i in range(1, numRows):
        	pascal.append([pascal[-1][0]])
        	for j in range(1, len(pascal[-2])):
        		pascal[-1].append(pascal[-2][j - 1] + pascal[-2][j])
        	pascal[-1].append(pascal[-2][-1])
        return pascal