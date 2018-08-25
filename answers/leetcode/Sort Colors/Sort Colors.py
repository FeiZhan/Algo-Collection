class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """

        left = 0
        right = len(nums) - 1
        i = 0
        while i <= right:
            if 0 == nums[i]:
                nums[i] = nums[left]
                nums[left] = 0
                left += 1
                i += 1
            elif 2 == nums[i]:
                nums[i] = nums[right]
                nums[right] = 2
                right -= 1
            else:
                i += 1
