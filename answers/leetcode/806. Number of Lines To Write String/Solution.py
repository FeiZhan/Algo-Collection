class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        result = 0
        size = 0
        for char in s:
            width = widths[ord(char) - ord('a')]
            if width + size > 100:
                result += 1
                size = width
            else:
                size += width
        return [result + 1 if size > 0 else 0, size]
