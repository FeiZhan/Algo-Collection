class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """

        stack = []
        for i in s:
            if '(' == i or '[' == i or '{' == i:
                stack.append(i)
            elif ')' == i:
                if 0 == len(stack) or stack.pop() != '(':
                    return False
            elif ']' == i:
                if 0 == len(stack) or stack.pop() != '[':
                    return False
            elif '}' == i:
                if 0 == len(stack) or stack.pop() != '{':
                    return False
        return 0 == len(stack)
