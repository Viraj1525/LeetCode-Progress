class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        n = len(prices)
        max_profit = 0
        buy = prices[0]
        for price in prices:
            if price < buy:
                buy = price
            max_profit = max(price-buy, max_profit)

        return max_profit




        