class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        range = [-1, -1]
        left = 0
        right = len(nums) - 1
        while left <= right:
            middle = (left + right) / 2
            if nums[middle] == target:
                if 0 == middle or nums[middle - 1] != target:
                    range[0] = middle
                    break
                else:
                    right = middle - 1
            elif nums[middle] < target:
                left = middle + 1
            else:
                right = middle - 1
        left = 0
        right = len(nums) - 1
        while left <= right:
            middle = (left + right) / 2
            if nums[middle] == target:
                if middle + 1 >= len(nums) or nums[middle + 1] != target:
                    range[1] = middle
                    break
                else:
                    left = middle + 1
            elif nums[middle] < target:
                left = middle + 1
            else:
                right = middle - 1
        return range
