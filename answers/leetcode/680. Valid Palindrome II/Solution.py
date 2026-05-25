class Solution:
    def validPalindrome(self, s: str) -> bool:
        deleted = False
        left = 0
        right = len(s) - 1
        while left < right:
            if s[left] != s[right]:
                if deleted:
                    return False
                else:
                    deleted = True
                    return self._check(left + 1, right, s) or self._check(left, right - 1, s)
            left += 1
            right -= 1
        return True
    
    def _check(self, left, right, s):
        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1
        return True
