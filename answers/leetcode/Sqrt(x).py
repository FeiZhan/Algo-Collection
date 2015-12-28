class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """

        left = 0
        right = x
        while left <= right:
            middle = (left + right) / 2
            sqrt = middle * middle
            if x == sqrt:
                return middle
            elif x < sqrt:
                right = middle - 1
            else:
                left = middle + 1
        return (left + right) / 2
