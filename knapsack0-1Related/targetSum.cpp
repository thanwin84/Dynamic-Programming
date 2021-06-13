using namespace std;
int dp[1002][1002];
class Solution {
public:
    int countSubset(vector<int>& nums, int target) {
        for (int i = 0; i <= target; i++) dp[0][i] = 0;
        for (int i = 0; i <= nums.size(); i++) dp[i][0] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[nums.size()][target];
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto i : nums) sum += i;
        int sum1 = (target + sum) / 2;
        if (sum < target || (target + sum) % 2 != 0) {
            return 0;
        }
        else {
            return countSubset(nums, sum1);
        }

    }
};
