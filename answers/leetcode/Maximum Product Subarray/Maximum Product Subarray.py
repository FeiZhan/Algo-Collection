class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        max_total = nums[0]
        max_product = nums[0]
        min_product = nums[0]
        for i in range(1, len(nums)):
            temp = max(max_product * nums[i], min_product * nums[i], nums[i])
            min_product = min(max_product * nums[i], min_product * nums[i], nums[i])
            max_product = temp
            max_total = max(max_total, max_product)
        return max_total
