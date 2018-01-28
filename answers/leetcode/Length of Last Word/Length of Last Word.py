class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """

        begin = 0
        end = 0
        for i in reversed(range(len(s) + 1)):
            if i < len(s) and ' ' != s[i] and (0 == i or ' ' == s[i - 1]):
                begin = i
                break
            elif (len(s) == i or ' ' == s[i]) and i > 0 and ' ' != s[i - 1]:
                end = i
        return end - begin
