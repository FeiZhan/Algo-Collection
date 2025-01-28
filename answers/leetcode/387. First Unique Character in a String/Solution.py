class Solution:
    def firstUniqChar(self, s: str) -> int:
        index_map = dict()
        count_map = dict()
        for i in range(len(s)):
            if s[i] not in count_map:
                index_map[s[i]] = i
            count_map[s[i]] = count_map.get(s[i], 0) + 1
        result = len(s)
        for char in count_map.keys():
            if count_map[char] == 1:
                result = min(result, index_map[char])
        return result if result < len(s) else -1
