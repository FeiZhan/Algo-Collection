class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """

        title = ""
        while n > 0:
            title = chr((n - 1) % 26 + ord('A')) + title
            n = (n - 1) / 26
        return title
