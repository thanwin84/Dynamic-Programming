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
