class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        
        candidates.sort()
        combinations = []
        self.dfs(0, candidates, target, [], combinations)
        return combinations

    def dfs(self, current, candidates, target, combi, combinations):
        if 0 == target:
            combinations.append(combi)
            return
        for i in range(current, len(candidates)):
            if target < candidates[i]:
                break
            self.dfs(i, candidates, target - candidates[i], combi + [candidates[i]], combinations)