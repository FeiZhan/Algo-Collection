class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """

        origin = 0
        for i in nums:
            if i != val:
                nums[origin] = i
                origin += 1
        return origin
