class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split(' ')
        if len(pattern) != len(words):
            return False
        letter_map = dict()
        word_map = dict()
        for i in range(len(pattern)):
            if pattern[i] not in letter_map and words[i] not in word_map:
                letter_map[pattern[i]] = words[i]
                word_map[words[i]] = pattern[i]
            elif pattern[i] not in letter_map or words[i] not in word_map or letter_map[pattern[i]] != words[i]:
                return False
        return True
