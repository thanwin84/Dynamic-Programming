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
//Max profit with at most two transactions =
  //     MAX {max profit with one transaction and subarray price[0..i] +
    //        max profit with one transaction and subarray price[i+1..n-1]  }
//i varies from 0 to n-1.
//time complexity of this solution is O(n2)
// we can optimize this solution

//time: O(n) and space: O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = 0; //same day transaction is not possible
        right[n -1] = 0;
        int left_min = prices[0];
        int right_max = prices[n -1];
        for(int i = 1; i < n; i++){
            left[i] = max(left[i -1], prices[i] - left_min);
            left_min = min(left_min, prices[i]);
        }
        for(int i = n -2; i >= 0; i--){
            right[i] = max(right[i + 1], right_max - prices[i]);
            right_max = max(right_max, prices[i]);
        }
        int profit = right[0];
        for(int i = 1; i < n; i++){
            profit = max(profit, left[i -1] + right[i]);
        }
        return profit;
    } 
};
