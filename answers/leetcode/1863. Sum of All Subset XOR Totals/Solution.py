class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        result = 0
        for i in range(len(nums)):
            result += self._getXor(i, 0, nums)
        return result
    
    def _getXor(self, index, xor, nums):
        if index >= len(nums):
            return 0
        xor ^= nums[index]
        result = xor
        for i in range(index, len(nums)):
            result += self._getXor(i + 1, xor, nums)
        return result
