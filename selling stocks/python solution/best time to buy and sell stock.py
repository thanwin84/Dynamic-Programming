#  algorithm: If I wanna sell at ith day, that means I need to buy the chapest stock from 0 to i - 1th day. This will make sure that we get the maximum profit.
# time: O(n) and space: O(1)
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        _min = prices[0]
        ans = 0
        for curr in prices:
            ans = max(ans, curr - _min)
            # update _min if current price is lower
            _min  = min(curr, _min)
        return ans
