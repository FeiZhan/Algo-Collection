class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """

        word_list = []
        left = 0
        for i in range(1, len(s) + 1):
            if i < len(s) and ' ' == s[i - 1] and ' ' != s[i]:
                left = i
            elif ' ' != s[i - 1] and (len(s) <= i or ' ' == s[i]):
                word_list.append(s[left : i])
                left = i
        return " ".join(reversed(word_list))
