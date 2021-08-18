//time: O(2^n) and space: O(n*2*3)
int dp[100003][3][2];
class Solution {
public:
    int solve(vector<int>& prices, int pos, int t, bool bought) {
        if (pos >= prices.size() || t == 0) {
            return 0;
        }
        if (dp[pos][t][bought] != -1) {
            return dp[pos][t][bought];
        }
        int result = solve(prices, pos + 1, t, bought);
        if (bought) {
            result = max(result, prices[pos] + solve(prices, pos + 1, t - 1, false));
        }
        else {
            result = max(result, solve(prices, pos + 1, t, true) - prices[pos]);
        }
        dp[pos][t][bought] = result;
        return result;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 2, false);
    }
};
