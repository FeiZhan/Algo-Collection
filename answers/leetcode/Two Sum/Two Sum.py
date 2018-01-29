class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        dict = {}
        for i in xrange(len(nums)):
            x = nums[i]
            if target - x in dict:
                return (dict[target - x] + 1, i + 1)
            dict[x] = i
