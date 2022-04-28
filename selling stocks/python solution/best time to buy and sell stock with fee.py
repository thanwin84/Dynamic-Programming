class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        days = len(prices)
        profit = [[0 for i in range(2)] for j in range(days + 1)]
        for currDay in range(days - 1, -1, -1):
            for bought in range(2):
                skip = profit[currDay + 1][bought]
                if bought:
                    buy = -prices[currDay] + profit[currDay + 1][False]
                    profit[currDay][bought] = max(buy, skip)
                else:
                    sell = prices[currDay] - fee + profit[currDay + 1][True]
                    profit[currDay][bought] = max(sell, skip)
        return profit[0][True]
               
# space optimized solution
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        days = len(prices)
        ahead = [0, 0]
        current = [0, 0]
        for currDay in range(days - 1, -1, -1):
            for bought in range(2):
                skip = ahead[bought]
                if bought:
                    buy = -prices[currDay] + ahead[False]
                    current[bought] = max(buy, skip)
                else:
                    sell = prices[currDay] - fee + ahead[True]
                    current[bought] = max(sell, skip)
            ahead = current
        return current[True]
 # More clean code
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        days = len(prices)
        currentBuy = currentNotBuy = aheadBuy = aheadNotBuy = 0
        for currDay in range(days - 1, -1, -1):
            currentBuy = max(-prices[currDay] + aheadNotBuy, aheadBuy)
            currentNotBuy = max(prices[currDay] - fee + aheadBuy, aheadNotBuy)
            aheadBuy =  currentBuy
            aheadNotBuy = currentNotBuy
        return currentBuy
                    
