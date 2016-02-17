class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        
        if len(s1) + len(s2) != len(s3):
        	return False
        dp = [[False for i in range(len(s2) + 1)] for j in range(len(s1) + 1)]
        for i in range(len(s1) + 1):
        	for j in range(len(s2) + 1):
        		dp[i][j] = (0 == i and 0 == j) or (i >= 1 and s1[i - 1] == s3[i + j - 1] and dp[i - 1][j]) or (j >= 1 and s2[j - 1] == s3[i + j - 1] and dp[i][j - 1])
        #print "debug", dp
        return dp[-1][-1]