//time: O(n2)
class Solution {
public:

    long long int solve(vector<int>& nums, int curr, vector<int>& dp)
    {
        if (curr >= nums.size() - 1) {
            return 0;
        }
        if (dp[curr] != -1) return dp[curr];
        long long int tmp = INT_MAX;
        for (int i = 1; i <= nums[curr]; i++)
        {
            tmp = min(tmp, 1 + solve(nums, curr + i,  dp));
        }
        dp[curr] = tmp;
        return tmp;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0,  dp);
    }
};
