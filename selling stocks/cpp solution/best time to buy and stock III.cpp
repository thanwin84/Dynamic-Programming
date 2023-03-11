
///----------------memoization--------------------
int dp[100001][2][2];
class Solution {
public:
    int solve(vector<int> &prices, int currentDay, int trans, bool bought){
        // If no days left or transaction is equal to 2
        // then we can't make any profit
        if (currentDay == prices.size() || trans >= 2){
            return 0;
        }
        if (dp[currentDay][trans][bought] != -1){
            return dp[currentDay][trans][bought];
        }
        // skip the current day
        int skip = solve(prices, currentDay + 1, trans, bought);
        if (bought){
            int buy = -prices[currentDay] + solve(prices, currentDay + 1, trans, false);
            return dp[currentDay][trans][bought] =  max(skip, buy);
        }
        else {
            // when we sell a stock, then we complete a transaction
            // next day we will be at buy state
            int sell = prices[currentDay] + solve(prices, currentDay+ 1, trans + 1, true);
            return dp[currentDay][trans][bought] =  max(skip, sell); 
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 0, true);
    }
};

//// Time: O(n) and space: O(n)

//-----------terative approach----------------------------------

int dp[100002][3][2];
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        for (int currentDay = days; currentDay >= 0; currentDay--){
            for(int tran = 0; tran < 2; tran++){
                for (int bought = 0; bought < 2; bought++){
                    int skip = dp[currentDay + 1][tran][bought];
                    if (currentDay == days){
                        dp[currentDay][tran][bought] = 0;
                    }
                    else if (bought){
                        int buy = -prices[currentDay] + dp[currentDay + 1][tran][false];
                        dp[currentDay][tran][bought] = max(buy, skip);
                    }
                    else {
                        int sell = prices[currentDay] + dp[currentDay + 1][tran + 1][true];
                        dp[currentDay][tran][bought] = max(sell, skip);
                    }
                }
            }
        }
        return dp[0][0][true];
    }
};
///-------------O(1) space---------------------

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> current(3, vector<int>(2, 0)), ahead(3, vector<int>(2, 0));
        int days = prices.size();
        for (int currentDay = days; currentDay >= 0; currentDay--){
            for(int tran = 0; tran < 2; tran++){
                for (int bought = 0; bought < 2; bought++){
                    int skip = ahead[tran][bought];
                    if (currentDay == days){
                        current[tran][bought] = 0;
                    }
                    else if (bought){
                        int buy = -prices[currentDay] + ahead[tran][false];
                        current[tran][bought] = max(buy, skip);
                    }
                    else {
                        int sell = prices[currentDay] + ahead[tran + 1][true];
                        current[tran][bought] = max(sell, skip);
                    }
                }
                ahead = current;
            }
        }
        return current[0][true];
    }
};
