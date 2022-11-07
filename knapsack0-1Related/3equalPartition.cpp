//memoization 
class Solution {
public:
    bool solve(vector<int> & nums, int target, int n, vector<vector<int>> &dp){
        // we've got the partition
        if (target == 0){
            return true;
        }
        // no items to choose
        if (n == 0 || target < 0){
            return false;
        }
        if (dp[n][target] != -1) {
            return dp[n][target];
        }
        bool notPick = solve(nums, target, n - 1, dp);
        bool pick = false;
        if (nums[n - 1] <= target){
            pick = solve(nums, target - nums[n - 1], n -1, dp);
        }
        return dp[n][target] = notPick || pick;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (auto value: nums){
            totalSum += value;
        }
        if (totalSum % 2 != 0) {
            return false;
        }
        
        vector<vector<int>> dp(201, vector<int>(10002, -1));
        return solve(nums, totalSum / 2, nums.size(), dp);
    }
};

//top down

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for (auto value: nums){
            totalSum += value;
        }
        
        if (totalSum % 2 != 0) {
            return false;
        }
        int target = totalSum / 2;
        vector<vector<int>> dp(201, vector<int>(10002, -1));
        for (int i = 0; i <=  n; i++) dp[i][0] = true;
        for (int i = 1; i <= target; i++ ) dp[0][i] = false;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= target; j++){
                bool notPick = dp[i - 1][j];
                bool pick = false;
                if (nums[i - 1] <= j) {
                    pick = dp[i - 1][j - nums[i -1]];
                }
                dp[i][j] = pick || notPick;
            }
        }
        return dp[n][target];
    }
};
