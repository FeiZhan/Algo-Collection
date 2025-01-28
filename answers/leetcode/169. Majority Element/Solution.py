class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        result = -1
        for number in nums:
            if count == 0:
                result = number
            count += 1 if number == result else -1

        return result
