//memoized version
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int ind = 1; ind <= n; ind++){
            for (int target = 1; target <= n; target++){
                int notPick = dp[ind - 1][target];
                int pick = 0;
                if (ind <= target) pick = price[ind- 1] + dp[ind][target - ind];
                dp[ind][target] = max(pick, notPick);
            }
        }
        
        return dp[n][n];
    }
};
//>>>>>> time: O(n * n) and space: O(n * n)
//space optimized solution
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<int> dp(n + 1, 0);
        for (int ind = 1; ind <= n; ind++){
            for (int target = 1; target <= n; target++){
                int notPick = dp[target];
                int pick = 0;
                if (ind <= target) pick = price[ind- 1] + dp[target - ind];
                dp[target] = max(pick, notPick);
            }
        }
        
        return dp[n];
    }
};
