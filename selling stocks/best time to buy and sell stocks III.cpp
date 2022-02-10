//top-down approach
//time: O(n) 
int dp[100002][2][3];
class Solution {
public:
    int solve(vector<int>& prices, int pos, int k, bool bought) {
        if (pos >= prices.size() || k == 0) {
            return 0;
        }
        if (dp[pos][bought][k] != -1) {
            return dp[pos][bought][k];
        }
        int skip = solve(prices, pos + 1, k, bought);
        if (bought) {
            int buy = -prices[pos] + solve(prices, pos + 1, k, false);
            return dp[pos][bought][k]= max(buy, skip);
        }
        else {
            int sell = prices[pos] + solve(prices, pos + 1, k - 1, true);
            return dp[pos][bought][k] = max(sell, skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 2, true);
    }
};
