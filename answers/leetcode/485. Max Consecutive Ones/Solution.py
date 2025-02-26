class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        left = 0
        result = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                result = max(result, i - left)
                left = i + 1
        return max(result, len(nums) - left)
