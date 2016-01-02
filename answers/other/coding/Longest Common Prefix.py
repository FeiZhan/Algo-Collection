class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        
        if 0 == len(strs):
            return ""
        elif 1 == len(strs):
            return strs[0]
        longest = 0
        for i in range(len(strs[0])):
            flag = True
            for j in strs:
                if len(j) <= i or strs[0][i] != j[i]:
                    flag = False
                    break
            if flag:
                longest = i + 1
            else:
                break
        return strs[0][: longest]

