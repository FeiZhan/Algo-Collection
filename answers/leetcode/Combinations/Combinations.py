class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """

        combinations = []
        self.dfs(1, 0, [], combinations, n, k)
        return combinations

    def dfs(self, begin, count, combi, combinations, n, k):
        if count >= k:
            combinations.append(combi)
            return
        for i in range(begin, n + 1):
            self.dfs(i + 1, count + 1, combi + [i], combinations, n, k)
