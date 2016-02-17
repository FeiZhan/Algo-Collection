class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        
        total = [i for i in triangle[0]]
        for i in range(1, len(triangle)):
        	prev = sys.maxint
        	for j in range(len(total)):
        		temp = total[j]
        		total[j] = triangle[i][j] + min(prev, total[j])
        		prev = temp
        	total.append(triangle[i][-1] + prev)
        return min(total)