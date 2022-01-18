//time: O(n) space: O(n)
//top down approach
int dp[1002];
class Solution {
public:
    int solve(vector<int>& cost, int i) {
        if (i < 0) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int left = cost[i] + solve(cost, i - 1);
        int right = cost[i] + solve(cost, i - 2);
        return dp[i] = min(left, right);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        solve(cost, n - 1);
        return min(dp[n-1], dp[n-2]);
    }
};
//iterative approach
int dp[1002];
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2){
            return min(cost[0], cost[1]);
        }
        dp[0] = cost[0];
        dp[1] = cost[1];
        int n = cost.size();
        for(int i = 2; i < n; i++){
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};
