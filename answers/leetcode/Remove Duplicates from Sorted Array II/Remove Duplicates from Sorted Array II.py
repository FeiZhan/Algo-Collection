class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        prev0 = 0
        prev1 = 1
        for i in range(2, len(nums)):
            if nums[i] != nums[prev0] or nums[i] != nums[prev1]:
                prev0 += 1
                prev1 += 1
                nums[prev1] = nums[i]
        return min(len(nums), prev1 + 1)
