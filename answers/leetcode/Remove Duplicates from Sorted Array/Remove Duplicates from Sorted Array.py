class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        origin = min(1, len(nums))
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                nums[origin] = nums[i]
                origin += 1
        return origin
