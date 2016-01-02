class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        
        pascal = [1]
        for i in range(rowIndex):
        	prev = 0
        	for j in range(len(pascal)):
        		temp = pascal[j]
        		pascal[j] += prev
        		prev = temp
        	pascal.append(prev)
        return pascal