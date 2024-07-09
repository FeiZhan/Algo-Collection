class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        left = 0
        right = len(nums) - 1
        while left <= right:
            middle = (left + right) / 2
            if nums[middle] == target:
                return middle
            elif nums[left] <= nums[middle]:
                if nums[middle] > target and nums[left] <= target:
                    right = middle - 1
                else:
                    left = middle + 1
            else:
                if nums[middle] < target and target <= nums[right]:
                    left = middle + 1
                else:
                    right = middle - 1
        return -1
