//************Python Solution***********************
class Solution:
    def solve(self, prices, fee, pos,bought,  dp):
        if pos == len(prices):
            return 0
        if dp[pos][bought] != -1:
            return dp[pos][bought]
        skip = self.solve(prices, fee, pos + 1, bought, dp)
        if bought:
            buy = - prices[pos] + self.solve(prices, fee, pos + 1, 0, dp);
            dp[pos][bought] = max(buy, skip);
            return dp[pos][bought]
        else:
            sell = (prices[pos] - fee) + self.solve(prices, fee, pos + 1, 1, dp)
            dp[pos][bought] = max(skip, sell);
            return dp[pos][bought]
    def maxProfit(self, prices: List[int], fee: int) -> int:
        dp = [[-1 for i in range(2)]for j in range(len(prices) + 1)]
        return self.solve(prices, fee, 0, 1, dp);
        
