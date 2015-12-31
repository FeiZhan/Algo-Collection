class Solution(object):
    def __init__(self):

        self.num_map = {}

    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """

        if n not in self.num_map:
            self.num_map[n] = False
            temp = n
            sum = 0
            while temp:
                sum += (temp % 10) * (temp % 10)
                temp /= 10
            self.num_map[n] = 1 == n or self.isHappy(sum)
        return self.num_map[n]
