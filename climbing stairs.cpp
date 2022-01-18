//time: O(n)
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
        memset(dp, -1, sizeof(dp));
        int first_step = solve(cost, cost.size() - 1);
        memset(dp, -1, sizeof(dp));
        int second_step = solve(cost, cost.size() - 2);
        return min(first_step, second_step);

    }
};
