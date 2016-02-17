class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        num_map = dict()
        for i in nums:
            if not(i in num_map):
                num_map[i] = 0
            num_map[i] += 1
        answers = []
        for num0 in num_map:
            for num1 in num_map:
                if num1 < num0 or (num0 == num1 and num_map[num0] < 2):
                    continue
                num2 = - num0 - num1
                if num2 in num_map and (num2 > num1 or (num2 == num0 and num2 == num1 and num_map[num0] >= 3) or (num0 != num1 and num2 == num1 and num_map[num1] >= 2)):
                    answers.append([num0, num1, num2])
        return answers

