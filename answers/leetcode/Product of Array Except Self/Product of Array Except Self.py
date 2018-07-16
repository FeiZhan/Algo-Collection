class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        product = 1
        product_list = []
        for i in range(len(nums)):
            product_list.append(product)
            product *= nums[i]
        product = 1
        for i in reversed(range(len(nums))):
            product_list[i] *= product
            product *= nums[i]
        return product_list
