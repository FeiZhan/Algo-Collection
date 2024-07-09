class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        longest = 0
        begin = 0
        char_list = {}
        for i in range(len(s)):
            if s[i] in char_list:
                temp = char_list[s[i]]
                while begin <= temp:
                    del char_list[s[begin]]
                    begin += 1
            if longest < i - begin + 1:
                longest = i - begin + 1
            char_list[s[i]] = i
        return longest
