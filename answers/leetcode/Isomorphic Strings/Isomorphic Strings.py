class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        if len(s) != len(t):
            return False
        char_map = {}
        count_map = {}
        for i in range(len(s)):
            if s[i] not in char_map:
                char_map[s[i]] = t[i]
                if t[i] not in count_map:
                    count_map[t[i]] = 1
                else:
                    return False
            elif char_map[s[i]] != t[i]:
                return False
        return True
