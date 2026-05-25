class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        number_sum = sum(nums[0 : k])
        max_sum = number_sum
        for i in range(len(nums) - k):
            number_sum += nums[i + k] - nums[i]
            max_sum = max(max_sum, number_sum)
        return max_sum / k
