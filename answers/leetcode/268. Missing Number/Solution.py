class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        for number in nums:
            if number != 0 and number != -100000:
                index: int = abs(number) - 1
                if nums[index] == 0:
                    nums[index] = -100000
                else:
                    nums[index] *= -1
        for i in range(len(nums)):
            if nums[i] >= 0:
                return i + 1
        return 0
