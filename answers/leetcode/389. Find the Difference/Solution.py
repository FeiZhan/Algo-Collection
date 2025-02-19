class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        s = sorted(s)
        t = sorted(t)
        for i, c in enumerate(s):
            if c != t[i]:
                return t[i]
        return t[-1]
