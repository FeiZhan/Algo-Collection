class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        repetition = -1
        loss = -1
        number_set = set()
        for number in nums:
            if number in number_set:
                repetition = number
            else:
                number_set.add(number)
        for i in range(len(nums)):
            if i + 1 not in number_set:
                loss = i + 1
        return [repetition, loss]
