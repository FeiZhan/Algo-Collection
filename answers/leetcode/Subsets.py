class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        nums.sort()
        subset_list = []
        for i in range(1 << len(nums)):
            subset = []
            for j in range(len(nums)):
                if i & (1 << j):
                    subset.append(nums[j])
            subset_list.append(subset)
        return subset_list
