class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """

        longest = 0
        stack = []
        begin = -1
        for i in range(len(s)):
            if '(' == s[i]:
                stack.append(i)
            elif ')' == s[i]:
                if 0 == len(stack):
                    begin = i
                else:
                    stack.pop()
                    if 0 == len(stack):
                        length = i - begin
                    else:
                        length = i - stack[-1]
                    longest = max(longest, length)
        return longest
