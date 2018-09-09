class Solution(object):
    map = {}
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """

        if n not in self.map:
            if n <= 1:
                self.map[n] = "1"
            else:
                prev = self.countAndSay(n - 1)
                answer = ""
                count = 1
                for i in range(len(prev)):
                    if len(prev) - 1 == i or prev[i] != prev[i + 1]:
                        answer += str(count) + prev[i]
                        count = 1
                    else:
                        count += 1
                self.map[n] = answer
        return self.map[n]
