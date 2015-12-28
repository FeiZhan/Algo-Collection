class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        left = 0
        right = len(nums) - 1
        while left <= right:
            middle = (left + right) / 2
            if nums[middle] == target or ((0 == middle or nums[middle - 1] < target) and nums[middle] > target):
                return middle
            elif nums[middle] < target:
                left = middle + 1
            else:
                right = middle - 1
        return len(nums)
