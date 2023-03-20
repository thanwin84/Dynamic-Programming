int dp[301][301];
class Solution {
public:
    int solve(vector<int> &nums, int start, int end){
        if (start > end) return 0;
        if (dp[start][end] != -1) return dp[start][end];
        int ans = 0;
        for (int partitionIndex = start; partitionIndex <= end; partitionIndex++){
            int left_ind = (start - 1 < 0) ? 1: nums[start - 1];
            int right_ind = (end + 1 >= nums.size()) ? 1: nums[end + 1];
            int cost = left_ind * nums[partitionIndex] * right_ind;
            int left = solve(nums, start, partitionIndex - 1);
            int right = solve(nums, partitionIndex + 1, end);
            ans = max(ans, cost + left + right);
        }
        return dp[start][end] = ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, nums.size() - 1);
    }
};
