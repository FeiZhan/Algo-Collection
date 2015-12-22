class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """

        reversed = 0
        sign = (x >= 0) * 2 - 1
        x = abs(x)
        while x:
            reversed = reversed * 10 + x % 10
            x /= 10
        reversed *= sign
        if reversed > 2147483647 or reversed < - 2147483648:
            reversed = 0
        return reversed
