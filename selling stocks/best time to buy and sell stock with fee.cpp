//************C++ Solution***********************

//memoization
//time: O(n) and space: O(n)
class Solution {
    int dp[50002][2];
public:
    int solve(vector<int> &prices, int fee, int pos, bool bought){
        if (pos == prices.size()){
            return 0;
        }
        if (dp[pos][bought] != -1){
            return dp[pos][bought];
        }
        if (bought){
            int buy = -prices[pos] + solve(prices, fee, pos + 1, false);
            int skip = solve(prices, fee, pos + 1, bought);
            return dp[pos][bought] =max(buy, skip);
        }
        else {
            int sell = (prices[pos] - fee) + solve(prices, fee, pos + 1, true);
            int skip = solve(prices, fee, pos + 1, bought);
            return dp[pos][bought] = max(sell, skip);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, fee, 0, true);
    }
};

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
        
