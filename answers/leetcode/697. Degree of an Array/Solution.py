class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        count_map = {}
        head_map = {}
        tail_map = {}
        for i in range(len(nums)):
            number = nums[i]
            count_map[number] = count_map.get(number, 0) + 1
            tail_map[number] = i
            if number not in head_map:
                head_map[number] = i
        degree = 0
        degree_list = []
        for number in count_map:
            count = count_map[number]
            if count > degree:
                degree = count
                degree_list = [number]
            elif count == degree:
                degree_list.append(number)
        result = float('inf')
        for number in degree_list:
            result = min(result, tail_map[number] - head_map[number] + 1)
        return result
