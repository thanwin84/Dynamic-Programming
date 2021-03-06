# time: O(n * 2) and space: O(n * 2)
class Solution:
    def solve(self, prices, current, bought, dp):
        # we can't make any profit here
        if current == len(prices):
            return 0
        
        if dp[current][bought] != -1:
            return dp[current][bought]
        # we can always skip current day 
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
# iterative approach
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        days = len(prices)
        profit = [[0 for i in range(2)] for j in range(days + 1)]
        for curr in range(days -1, -1, -1):
            for buy in range(2):
                skip = profit[curr + 1][buy]
                if buy:
                    profit[curr][buy] = max(-prices[curr] + profit[curr + 1][False], skip)
                else:
                    profit[curr][buy] = max(prices[curr] + profit[curr + 1][True], skip)
        return profit[0][1];
                    
       
# using four variables
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        days = len(prices)
        aheadBuy = aheadNotBuy = 0
        currentBuy = currentNotBuy = 0
        for curr in range(days -1, -1, -1):
            for buy in range(2):
                if buy:
                    currentBuy = max(-prices[curr] + aheadNotBuy, aheadBuy)
                else:
                    currentNotBuy = max(prices[curr] + aheadBuy, aheadNotBuy)
            aheadBuy = currentBuy
            aheadNotBuy = currentNotBuy
        return aheadBuy
    
# using four variable and single pass
#  in the above example, at first we calculated curr[0] and then curr[1]. we can calculate it in one go
#  that means we can omit 2nd loop
# time: O(n) and space: O(1)
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        days = len(prices)
        aheadBuy = aheadNotBuy = 0
        currentBuy = currentNotBuy = 0
        for curr in range(days -1, -1, -1):
            currentNotBuy = max(prices[curr] + aheadBuy, aheadNotBuy)
            currentBuy = max(-prices[curr] + aheadNotBuy, aheadBuy)
            aheadBuy = currentBuy
            aheadNotBuy = currentNotBuy
        return aheadBuy
                    
        
 
