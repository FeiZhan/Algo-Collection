class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """

        left = 0
        right = 0
        sum = 0
        min_left = 0
        min_right = len(nums) + 1
        min_sum = sys.maxint
        while right <= len(nums) + 1:
            if sum < s:
                right += 1
                if right <= len(nums):
                    sum += nums[right - 1]
            elif sum >= s:
                if right - left < min_right - min_left:
                    min_sum = sum
                    min_left = left
                    min_right = right
                left += 1
                sum -= nums[left - 1]
        return min_right - min_left if sys.maxint > min_sum else 0
