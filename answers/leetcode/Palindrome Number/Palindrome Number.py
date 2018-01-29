class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """

        if x < 0:
            return False
        tens = 1
        while tens * 10 < x:
            tens *= 10
        while x:
            if x / tens != x % 10:
                return False
            x = (x % tens) / 10
            tens /= 100
        return True
