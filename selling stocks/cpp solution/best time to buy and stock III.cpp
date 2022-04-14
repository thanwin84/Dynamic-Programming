// time: O(n * 2 * 2) and space: O(n *2 * 2)
int dp[100001][2][2];
class Solution {
public:
    int solve(vector<int> &prices, int currDay, int trans, bool bought){
        if (currDay == prices.size() || trans >= 2){
            return 0;
        }
        if (dp[currDay][trans][bought] != -1){
            return dp[currDay][trans][bought];
        }
        int skip = solve(prices, currDay + 1, trans, bought);
        if (bought){
            int buy = -prices[currDay] + solve(prices, currDay + 1, trans, false);
            return dp[currDay][trans][bought] =  max(skip, buy);
        }
        else {
            int sell = prices[currDay] + solve(prices, currDay + 1, trans + 1, true);
            return dp[currDay][trans][bought] =  max(skip, sell); 
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 0, true);
    }
};
