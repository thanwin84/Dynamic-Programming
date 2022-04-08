// time: O(n*2) and space: O(n*2)
// memoized solution
class Solution {
public:
    int solve(vector<int> &prices, bool bought, int current, vector<vector<int>>&dp){
        if (current == prices.size()){
            return 0;
        }
        if (dp[bought][current] != -1){
            return dp[bought][current];
        }
        if (bought){
            int buy = -prices[current] + solve(prices, false, current + 1,  dp);
            return dp[bought][current] = max(buy, solve(prices, bought, current + 1, dp));
        }
        else {
            int not_buy = prices[current] + solve(prices, true, current + 1, dp);
            return dp[bought][current] = max(not_buy, solve(prices, bought, current + 1, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(prices.size() + 1, -1));
        return solve(prices, true, 0, dp);
    }
};
// iterative approach
class Solution {
public:  
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        vector<vector<int>> dp(2, vector<int>(days + 1, 0));
        for (int current = days - 1; current >= 0; current--){
            for (int bought = 0; bought < 2; bought++){
                if (bought){
                    int buy = -prices[current] + dp[false][current + 1];
                    dp[bought][current] = max(buy, dp[bought][current + 1]);
                }
                else {
                    int not_buy = prices[current] + dp[true][current + 1];
                    dp[bought][current] = max(not_buy, dp[bought][current + 1]);
                }
            }
        }
        return dp[true][0];
    }
};
// using 1d array
// time: O(n * 2) and space: O(1)
class Solution {
public:  
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        vector<int> ahead(2, 0), current(2, 0);
        for (int curr = days - 1; curr >= 0; curr--){
            for (int bought = 0; bought < 2; bought++){
                if (bought){
                    int buy = -prices[curr] + ahead[false];
                    current[bought] = max(buy, ahead[bought]);
                }
                else {
                    int not_buy = prices[curr] + ahead[true];
                    current[bought] = max(not_buy, ahead[bought]);
                }
                ahead = current;
            }
                                          
        }
        return current[true];
    }
};
// in the above example, first we are calculting curr[0] and then curr[1]. we can calculate it in one go
// that means we can omit 2nd loop
class Solution {
public:  
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        int aheadBuy = 0, aheadNotBuy = 0, currBuy = 0, currNotBuy = 0;
        for (int curr = days - 1; curr >= 0; curr--){
            currNotBuy = max(prices[curr] + aheadBuy, aheadNotBuy);
            currBuy = max(-prices[curr] + aheadNotBuy, aheadBuy);
            aheadNotBuy = currNotBuy;
            aheadBuy = currBuy;
                                          
        }
        return aheadBuy;
    }
};
