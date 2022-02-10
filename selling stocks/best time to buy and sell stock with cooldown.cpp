//time: O(n)
class Solution {
    int dp[5002][2];
public:
    int solve(vector<int> &prices, int pos, bool bought){
        if (pos >= prices.size()){
            return 0;
        }
        if (dp[pos][bought] != -1){
            return dp[pos][bought];
        }
        int skip = solve(prices, pos + 1, bought);
        if (bought){
            int buy = -prices[pos] + solve(prices, pos + 1, false);
            return dp[pos][bought] = max(buy, skip);
        }
        else {
            int sell = prices[pos] + solve(prices, pos + 2, true);
            return dp[pos][bought] = max(sell, skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, true);
    }
};
