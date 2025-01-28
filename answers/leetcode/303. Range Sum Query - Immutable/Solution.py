class NumArray:

    def __init__(self, nums: List[int]):
        self.sums = [0]
        sum: int = 0
        for number in nums:
            sum += number
            self.sums.append(sum)

    def sumRange(self, left: int, right: int) -> int:
        return self.sums[right + 1] - self.sums[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)