class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """

        range_list = []
        for i in range(len(nums)):
            if i > 0 and nums[i - 1] + 1 == nums[i]:
                range_list[-1][1] = nums[i]
            else:
                range_list.append([nums[i], nums[i]])
        str_list = [str(range_list[i][0]) + ("->" + str(range_list[i][1]) if range_list[i][0] != range_list[i][1] else "") for i in range(len(range_list))]
        return str_list
