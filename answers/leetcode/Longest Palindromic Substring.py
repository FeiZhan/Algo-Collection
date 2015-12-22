class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """

        longest = ''
        for i in range(len(s)):
            for j in range(2):
                begin = i
                end = i + j
                while begin >= 0 and end < len(s) and s[begin] == s[end]:
                    begin -= 1
                    end += 1
                if len(longest) < end - begin:
                    longest = s[begin + 1 : end]
        return longest
