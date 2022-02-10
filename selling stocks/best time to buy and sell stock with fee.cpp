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
