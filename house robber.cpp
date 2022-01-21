int dp[101];
class Solution {
public:
    int solve(vector<int> &nums, int i){
        if (i < 0){
            return 0;
        }
        if (dp[i] != -1){
            return dp[i];
        }
        int including = nums[i] + solve(nums, i - 2);
        int excluding = solve(nums, i - 1);
        return dp[i] = max(including, excluding);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, nums.size() -1);
    }
};
//time: O(n) and space: O(n)
