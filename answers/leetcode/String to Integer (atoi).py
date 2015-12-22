class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """

        if '' == str:
            return 0
        i = 0
        while i < len(str) and str[i].isspace():
            i += 1
        sign = 1
        if i < len(str) and '-' == str[i]:
            sign = -1
        if i < len(str) and ('-' == str[i] or '+' == str[i]):
            i += 1
        INT_MAX = 2147483647
        INT_MIN =  - INT_MAX - 1
        integer = 0
        while i < len(str) and str[i].isdigit():
            digit = int(str[i])
            if integer > INT_MAX / 10 or integer * 10 + digit > INT_MAX:
                return INT_MAX if 1 == sign else INT_MIN
            else:
                integer = integer * 10 + digit;
            i += 1
        return sign * integer
