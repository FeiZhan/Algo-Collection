class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        letter_map = dict()
        for letter in magazine:
            letter_map[letter] = letter_map.get(letter, 0) + 1
        for letter in ransomNote:
            if letter in letter_map:
                letter_map[letter] -= 1
            if letter not in letter_map or letter_map[letter] < 0:
                return False
        return True
