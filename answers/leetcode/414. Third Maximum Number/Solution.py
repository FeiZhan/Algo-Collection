class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        result = [-inf, -inf, -inf]
        for number in nums:
            if number > result[0]:
                result[2] = result[1]
                result[1] = result[0]
                result[0] = number
            elif number < result[0] and number > result[1]:
                result[2] = result[1]
                result[1] = number
            elif number < result[1] and number > result[2]:
                result[2] = number
        return result[2] if result[2] != -inf else result[0]
