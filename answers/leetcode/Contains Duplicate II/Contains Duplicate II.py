class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """

        num_map = {}
        for i in range(len(nums)):
            if nums[i] not in num_map:
                num_map[nums[i]] = []
            else:
                for j in range(len(num_map[nums[i]])):
                    if abs(i - num_map[nums[i]][j]) <= k:
                        return True
            num_map[nums[i]].append(i)
        return False
