//Dynamic Approach
int dp[100002][2][2];
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
        return solve(prices, 0, 1, true);
    }
};
//single pass Solution;
//time: O(n) and space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int _min = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            _min = min(_min, prices[i]);
            profit = max(profit, prices[i] - _min);
        }
        return profit;
    }
};
