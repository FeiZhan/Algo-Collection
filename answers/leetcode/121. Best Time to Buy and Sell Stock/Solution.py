class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = sys.maxsize
        result = 0
        for price in prices:
            buy = min(buy, price)
            result = max(result, price - buy)
        return result
