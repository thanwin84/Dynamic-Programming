//best time to buy and sell stocks
//time: O(n^2) and space: O(n * 2 * n/2)
class Solution {
    int dp[1002][2][501];
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int trans_limit = k;
        if (trans_limit >= n) {
            trans_limit = n / 2;
        }
        for (int day = n - 1; day >= 0; day--) {
            for (int tran = 0; tran <= trans_limit; tran++) {
                if (day == n - 1) {
                    dp[day][0][tran] = 0;
                    dp[day][1][tran] = (tran >= 1) ? prices[day] : 0;
                }
                else {
                    dp[day][0][tran] = max(-prices[day] + dp[day + 1][1][tran],
                        dp[day + 1][0][tran]);
                    dp[day][1][tran] = max((tran >= 1) ? prices[day] + dp[day + 1][0][tran - 1] : 0, dp[day + 1][1][tran]);
                }
            }
        }
        return dp[0][0][trans_limit];
    }
};
