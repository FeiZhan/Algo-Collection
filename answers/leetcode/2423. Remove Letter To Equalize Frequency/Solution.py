class Solution:
    def equalFrequency(self, word: str) -> bool:
        counter = Counter(Counter(word).values())
        if len(counter) == 1:
            return list(counter.keys())[0] == 1 or list(counter.values())[0] == 1
        if len(counter) == 2:
            min_count = min(counter.keys())
            max_count = max(counter.keys())
            return (min_count == 1 and counter[min_count] == 1) or (min_count + 1 == max_count and counter[max_count] == 1)
        return False
