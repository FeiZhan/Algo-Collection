class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        
        address_list = []
        self.dfs(0, 0, s, address_list)
        return address_list
    def dfs(self, level, begin, s, address_list):
    	if level >= 4 and begin >= len(s):
    		address_list.append(s[: -1])
    		return
    	elif level >= 4 or begin >= len(s):
    		return
    	for i in range(begin, len(s)):
    		if '0' == s[begin] and i > begin:
    			break
     		num = int(s[begin : i + 1])
    		if num >= 0 and num <= 255:
    			self.dfs(level + 1, i + 2, s[: i + 1] + '.' + s[i + 1 :], address_list)
    		else:
    			break