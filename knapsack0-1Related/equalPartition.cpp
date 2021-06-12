//memoization 
int const D = 10000;
int dp[201][200001];
class Solution {
public:
    bool solve(vector<int>& nums, int n, int target) {

        if (target < 0 || n == 0) return false;
        if (target == 0) return true;
        if (dp[n][target] != -10) return dp[n][target];
        return dp[n][target] = solve(nums, n - 1, target - nums[n - 1]) or solve(nums, n - 1, target);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums) {
            sum += i;
        }
        for (int i = 0; i <= nums.size(); i++) {
            for (int j = 0; j <= sum / 2; j++) {
                dp[i][j] = -10;
            }
        }
        if (sum % 2 != 0) {
            return false;
        }
        else {
            return solve( nums, nums.size(), sum / 2);
        }

    }
};

//top down
int const D = 10000;
bool dp[D][D];
class Solution {
public:
    bool subsetSum(int N, vector<int> arr, int sum) {
        for (int i = 0; i <= N; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= sum; i++) {
            dp[0][i] = false;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[N][sum];
    };
    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return 0;
        }
        return subsetSum(N, nums, sum / 2);
        
        
    }
};
