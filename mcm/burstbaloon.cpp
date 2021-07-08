int dp[501][501];
class Solution {
public:
    int solve(vector<int>& nums, int i, int j) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = INT_MIN;
        for (int k = i; k <= j; k++) {
            int l, r;
            if (i == 0) l = 1;
            else l = nums[i - 1];
            if (j == nums.size() - 1) r = 1;
            else r = nums[j + 1];
            int left = solve(nums, i, k - 1);
            int right = solve(nums, k + 1, j);
            int temp = left + right + (l * nums[k] * r);
            ans = max(temp, ans);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        memset(dp, -1, sizeof(dp));
        return solve(nums, i, j);

    }
};
