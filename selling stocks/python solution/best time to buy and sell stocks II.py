# time: O(n * 2) and space: O(n * 2)
class Solution:
    def solve(self, prices, current, bought, dp):
        # we can't make any profit here
        if current == len(prices):
            return 0
        
        if dp[current][bought] != -1:
            return dp[current][bought]
        # we can always skip to buy or sell in current day
        skip = self.solve(prices, current + 1, bought, dp)
        if not bought:
            sell = prices[current] + self.solve(prices, current + 1, True, dp)
            temp = max(skip, sell)
            dp[current][bought] = temp
            return temp
        else:
            buy = -prices[current] + self.solve(prices, current + 1, False, dp)
            temp = max(skip, buy)
            dp[current][bought] = temp
            return temp
            
            
    def maxProfit(self, prices: List[int]) -> int:
        dp = [[-1 for i in range(2)] for j in range(len(prices) + 1)]
        return self.solve(prices, 0, True, dp)
