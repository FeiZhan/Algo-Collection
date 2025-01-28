class Solution:
    def reverseVowels(self, s: str) -> str:
        VOWELS = set('AEIOUaeiou')
        sentence = list(s)
        left: int = 0
        right: int = len(s) - 1
        while left < right:
            if sentence[left] in VOWELS and sentence[right] in VOWELS:
                sentence[left],sentence[right] = sentence[right], sentence[left]
                left += 1
                right -= 1
            else:
                if sentence[left] not in VOWELS:
                    left += 1
                if sentence[right] not in VOWELS:
                    right -= 1
        return ''.join(sentence)
