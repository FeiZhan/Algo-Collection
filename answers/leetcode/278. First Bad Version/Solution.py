# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        return self.check(1, n)

    def check(self, start: int, end: int) -> int:
        if start > end:
            return -1
        middle: int = (start + end) // 2
        isBad: bool = isBadVersion(middle)
        if isBad:
            if start == middle:
                return start
            else:
                return self.check(start, middle)
        else:
            return self.check(middle + 1, end)
