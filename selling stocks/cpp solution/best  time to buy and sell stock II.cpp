// time: O(n*2) and space: O(n*2)
// memoized solution
// algorithm: bought state:we can either buy or skip the current day to sell it next day
// sell state: we can either sell or skip the current day to sell it next day
int dp[30001][2];
class Solution {
public:
    int solve(vector<int> &prices, int currentDay, bool bought){
        // no days left, so no profit
        if (currentDay == prices.size()){
            return 0;
        }
        if (dp[currentDay][bought] != -1){
            return (dp[currentDay][bought]);
        }
        int skip = solve(prices, currentDay + 1, bought);
        if (bought){
            // if we buy now, the next day we will be in sell state
            int buy = -prices[currentDay] + solve(prices, currentDay + 1, false);
            return dp[currentDay][bought] = max(buy, skip);
        }
        else {
            int sell = prices[currentDay] + solve(prices, currentDay + 1, true);
            return dp[currentDay][bought] = max(sell, skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        // initially we are the bought state
        return solve(prices, 0, true);
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
////////enought for the interview. the last doesn't optimize the solution. in the last part, we are just uisng four variables///
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
