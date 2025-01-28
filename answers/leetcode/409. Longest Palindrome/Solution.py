class Solution:
    def longestPalindrome(self, s: str) -> int:
        count_map = dict()
        for c in s:
            count_map[c] = count_map.get(c, 0) + 1
        have_odd: bool = False
        result: int = 0
        for count in count_map.values():
            if count % 2 == 0:
                result += count
            else:
                result += count - 1
                have_odd = True
        return result + (1 if have_odd else 0)
