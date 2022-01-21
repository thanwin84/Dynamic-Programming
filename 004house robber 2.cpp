int dp[101];
class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        int n = nums.size() - 1;
        int f = solve(nums, 1, n);
        int r = solve(nums, 0, n - 1);
        return max(f, r);

    }
};
