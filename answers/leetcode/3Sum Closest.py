class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        nums.sort()
        min_diff = sys.maxint
        three_sum = 0
        for i in range(len(nums)):
            left = i + 1
            right = len(nums) - 1
            while left < right:
                sum = nums[i] + nums[left] + nums[right]
                diff = abs(sum - target)
                if min_diff > diff:
                    min_diff = diff
                    three_sum = sum
                if sum > target:
                    right -= 1
                elif sum < target:
                    left += 1
                else:
                    return three_sum
        return three_sum
