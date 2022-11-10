using namespace std;
class Solution {
public:
    int countSubsets(vector<int> &nums, int sum){
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        for (int ind = 1; ind <= n; ind++){
            for (int target = 0; target <= sum; target++){
                int notTaken = dp[ind - 1][target];
                int taken = 0;
                if (nums[ind - 1] <= target) taken = dp[ind - 1][target - nums[ind - 1]];
                dp[ind][target] = taken + notTaken;
            }
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       int sum = 0;
       for (auto num: nums) {
           sum += num;
       }
       int sum1 = (target + sum) / 2;
       if (sum < target || (target + sum) % 2 != 0){
           return 0;
       }
       if (nums.size() == 1){
           if (nums[0] == abs(target)) return 1;
           if (nums[0] != target) return 0;
       }
       return countSubsets(nums, sum1);
    }
};
