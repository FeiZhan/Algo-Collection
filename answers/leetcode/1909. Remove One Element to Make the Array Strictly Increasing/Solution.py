class Solution:
    def canBeIncreasing(self, nums: List[int]) -> bool:
        removed = False
        stack = []
        for number in nums:
            if len(stack) >= 1 and number <= stack[-1]:
                if removed:
                    return False
                elif len(stack) == 1 or number > stack[-2]:
                    stack[-1] = number
                removed = True
            else:
                stack.append(number)
        return True
