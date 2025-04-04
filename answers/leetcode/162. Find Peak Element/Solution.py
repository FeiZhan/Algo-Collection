class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        left = 0
        right = len(nums) - 1
        while left < right:
            middle = (left + right) / 2
            if (0 == middle or nums[middle - 1] < nums[middle]) and (len(nums) - 1 == middle or nums[middle] > nums[middle + 1]):
                break
            elif middle > 0 and nums[middle - 1] > nums[middle] and (len(nums) - 1 == middle or nums[middle] > nums[middle + 1]):
                right = middle - 1
            elif (0 == middle or nums[middle - 1] < nums[middle]) and middle < len(nums) - 1 and nums[middle] < nums[middle + 1]:
                left = middle + 1
            else:
                left += 1
        return (left + right) / 2
