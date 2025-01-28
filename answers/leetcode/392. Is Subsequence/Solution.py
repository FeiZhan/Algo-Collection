class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        index: int = 0
        for c in t:
            if index >= len(s):
                break
            if s[index] == c:
                index += 1
        return index == len(s)
