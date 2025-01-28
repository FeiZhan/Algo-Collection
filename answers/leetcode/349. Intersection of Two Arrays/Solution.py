class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        number_set: Set[int] = set()
        for number in nums1:
            number_set.add(number)
        result: Set[int] = set()
        for number in nums2:
            if number in number_set:
                result.add(number)
        return list(result)
