class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """

        number = 0
        for i in range(len(s)):
            number = number * 26 + ord(s[i]) - ord('A') + 1
        return number
