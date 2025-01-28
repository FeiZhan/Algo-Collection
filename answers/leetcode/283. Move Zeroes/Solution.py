class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        index = 0
        for i in range(len(nums)):
            while index < len(nums) and nums[index] != 0:
                index += 1
            if index >= len(nums):
                break
            if i > index and nums[i] != 0:
                nums[i], nums[index] = nums[index], nums[i]
