//top-down approach
//time: O(n) since we have to do at most 2 transaction
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
//bottom -up approach
int dp[100002][2][3];
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        for (int day = n -1; day >= 0; day--){
            for (int trans = 0; trans <= 2; trans++){
                if (day == n -1){
                    dp[day][0][trans] = 0;
                    dp[day][1][trans] = (trans >= 1) ? prices[day] : 0;
                }
                else {
                    dp[day][0][trans] = max(-prices[day] + dp[day + 1][1][trans],
                                        dp[day + 1][0][trans]);
                    dp[day][1][trans] =  max((trans >= 1) ? prices[day] + dp[day + 1][0][trans -1] : 0, dp[day + 1][1][trans]);
                }
            }
        }
        return dp[0][0][2];
    }
};
//Divide and conqure
//time: O(n) and space: O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int left_min = prices[0];
        int right_max = prices[n - 1];
        for (int i = 1; i < n; i++){
            left[i] = max(left[i - 1], prices[i] - left_min);
            left_min = min(left_min, prices[i]);
        }
        for (int i = n -2; i >= 0; i--){
            right[i] = max(right[i + 1], right_max - prices[i]);
            right_max = max(right_max, prices[i]);
        }
        int profit = right[0];
        for (int i = 1; i < n; i++){
            profit = max(profit, left[i -1] + right[i]);
        }
        return profit;
        
    }
};
