class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        convert = {
        	'M': 1000,
        	'D': 500,
        	'C': 100,
        	'L': 50,
        	'X': 10,
        	'V': 5,
        	'I': 1
        }
        integer = 0
        prev = None
        for i in s:
        	if prev and convert[i] > prev:
        		integer -= prev * 2
        	integer += convert[i]
        	prev = convert[i]
        return integer